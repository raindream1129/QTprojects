#include "widget.h"
#include <windows.h>
#include <QTimer>
#include <QtXml>
#include <QFile>
#include "common.h"
int TimeOut;
int TimeNum;

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    meterCom = new QSerialPort();
    connect(meterCom, SIGNAL(readyRead()), this, SLOT(meterRecvData()));

    meterRecvTimer = new QTimer();
    connect(meterRecvTimer, SIGNAL(timeout()), this, SLOT(meterRecvTimeout()));

    //QTimer::singleShot(2000, this, SLOT(autoCmdExecution()));
    testTimer = new QTimer(this);
    connect( testTimer,SIGNAL(timeout()), this, SLOT(autoCmdExecution()));
    testTimer->start(TimeOut);

    i = 0;
    series = 0x00;
}

Widget::~Widget()
{
    delete meterCom;
    delete meterRecvTimer;
}

void Widget::loadComSettings(SerialInfo* sinfo)
{
    meterComInfo = *sinfo;
}

void Widget::loadExternalConfig(QList<Cjt188Object> *cmds)
{
    QList<Cjt188Object>  cmdslist;
    Cjt188Object cjt188Obj;
    cmdslist = *cmds;
    cmds->clear();
    QList<Cjt188Object>::Iterator iter;
    iter = cmdslist.begin();
    while(iter != cmdslist.end())
    {
        cjt188Obj = *iter;
        /*
        CJT188_CTRL_ID_NONE
        CJT188_CTRL_ID_WR_DATA
        CJT188_CTRL_ID_WR_ADDR
        CJT188_CTRL_ID_WR_MOTOR

        CJT188_CTRL_ID_RD_DATA
        CJT188_CTRL_ID_RD_ADDR
        CJT188_CTRL_ID_RD_VERSION
        */
        switch(cjt188Obj.ctrlId)
        {
        case CJT188_CTRL_ID_WR_DATA:
        {//写数据
            cjt188Obj.requestType = CJT188_REQUEST_SET_DATA;
            break;
        }
        case CJT188_CTRL_ID_WR_ADDR:
        {//写地址
            cjt188Obj.requestType = CJT188_REQUEST_SET_ADDR;
            break;
        }
        case CJT188_CTRL_ID_WR_MOTOR:
        {//写电机数据
            cjt188Obj.requestType = CJT188_REQUEST_SET_MOTOR_DATA;
            break;
        }
        case CJT188_CTRL_ID_RD_DATA:
        {//读数据
            cjt188Obj.requestType =CJT188_REQUEST_GET_DATA;
            break;
        }
        case CJT188_CTRL_ID_RD_ADDR:
        {//读地址
            cjt188Obj.requestType = CJT188_REQUEST_GET_ADDR;
            break;
        }
        case CJT188_CTRL_ID_RD_VERSION:
        {//读版本号
            cjt188Obj.requestType = CJT188_REQUEST_GET_VERSION;
            break;
        }
        }
        cmds->append(cjt188Obj);
        iter++;
    }

}
void Widget::preActive(Cjt188Object currentObj,Log Logprint)
{

}

void Widget::logPrint(Cjt188Object cjt188obj,int flag)
{

    QString fileH= "***";
    QString fileE= "*********************************************************";
    QString fEnd = "*******************************************************************************";
    QFile logtxt(logFile);
    //recvObjectqDebug()<<cjt188obj.allcmd;
    if(logtxt.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream in(&logtxt);
        in<<fileH+cjt188obj.desc+fileE<<endl;
        if(flag == 1)
        {
            in<<"Tx APDU:"<<endl;
            in<<cjt188obj.allcmd<<endl;
        }else{
            in<<"Rx APDU:"<<endl;
            in<<cjt188obj.allcmd<<endl;
            in<<fileH<<"Result "<<fileE<<endl;
            in<<cjt188obj.resultFlag<<endl;
            in<<fEnd<<endl;
            in<<endl;

        }
    }
    else
    {
        logtxt.close();
        qDebug()<<"打开日志文件错误";
        return;
    }
    logtxt.close();


    //ui->textEditLog->append(logStr);
}

void Widget::meterComOpen()
{
    if(meterCom->isOpen())
        meterCom->close();

    if(!meterComInfo.isEmpty())
    {
        meterCom->setPortName(meterComInfo.ComPortName);
        if(meterCom->open(QIODevice::ReadWrite))
        {
            meterCom->setBaudRate(meterComInfo.ComBaud);
            meterCom->setDataBits(meterComInfo.ComDataBits);
            meterCom->setParity(meterComInfo.ComParity);
            meterCom->setStopBits(meterComInfo.ComStopBits);
            //qDebug()<<"{通知}串口已打开";
        }
        else
        {
            qDebug()<<"{通知}串口错误";
        }
    }
}

void Widget::meterComClose()
{
    meterRecvTimer->stop();
    testTimer->stop();
    if(meterCom->isOpen())
        meterCom->close();

    meterRecvBuffLen = 0;
    meterSendBuffLen = 0;
    meterComInfo.clear();
    meterRoutine.clear();
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    memset(meterSendBuff, 0, sizeof(meterSendBuff));

   // qDebug()<<"{通知}串口已关闭";
}

void Widget::meterComSend()
{

    meterRoutine.rsp = METER_RSP_NONE;
    meterRecvArr.clear();
    if(meterCom->isOpen())
    {
        meterCom->write((char *)meterSendBuff, meterSendBuffLen);
    }
}

void Widget::meterRecvData()
{
    if(meterCom->bytesAvailable())
    {
        //稍作延时100ms
        Sleep(100);

        //数据全部读出
        meterRecvArr += meterCom->readAll();

        if( meterRecvArr.startsWith(0x68) && meterRecvArr.endsWith(0x16))
        {
            meterRecvBuffLen = meterRecvArr.length();
            memcpy(meterRecvBuff, meterRecvArr, meterRecvBuffLen);
            meterCmdResponseHandler();
        }

        //meterRecvTimer->start(meterComInfo.ComTimeout);
        meterRecvTimer->setInterval(meterComInfo.ComTimeout);
        meterRecvTimer->start();       

    }
}

void Widget::meterRecvTimeout()
{
    //出错，打开结果保存的文件，将错误码写入
    qDebug()<<"接收数据超时";

    meterComClose();
}
/*执行命令集*/

void Widget::autoExe()
{
    QString strHeader( "version=\"1.0\" encoding=\"UTF-8\"" );
    meterCmdResponseMsg.appendChild(meterCmdResponseMsg.createProcessingInstruction("xml",strHeader));
    RootNode = meterCmdResponseMsg.createElement("Root");
    meterCmdResponseMsg.appendChild(RootNode);

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm-ss");
    QString logStr = ".\\logs\\";
    logFile = logStr + "test_log_" + current_date + ".txt";
    WriteLog.LogFileName = logFile;
    QFile logtxt(logFile);
    if(!logtxt.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug()<<"打开日志文件失败";
    }
    logtxt.close();
    autoCmdExecution();
}

void Widget::autoCmdExecution(void)
{

    if(cjt188_cmds_list.first().Seriers <series)
    {
        Cjt188Object recvObject;
        recvObject.clear();
        recvObject.allcmd = "NoResponse";
        recvObject.desc = cjt188_cmds_list.first().desc;
        recvObject.value = "";
        recvObject.resultFlag = "fail";
        recvObject.requestType = cjt188_cmds_list.first().requestType;
        logPrint(recvObject,2);
        if(i>=TimeNum-1)
        {
            qDebug()<<"无响应";

            save_meterCmdResponse(recvObject);
            Sleep(1000);
            cjt188_cmds_list.removeFirst();
            if(cjt188_cmds_list.length() == 0)
            {
                QFile Savexmlfile(ResFileNm);
                if(Savexmlfile.open(QIODevice::WriteOnly | QIODevice::Append))
                {
                   QTextStream stream(&Savexmlfile);
                   meterCmdResponseMsg.save(stream,2);
                }
                else
                {
                    Savexmlfile.close();
                    qDebug()<<"打开结果文件错误";
                    return;
                }
                Savexmlfile.close();
                testTimer->stop();
                meterRecvTimer->stop();
                meterComClose();
                this->close();
            }
            series = 0x00 - 1;
            i = 0;
        }
        i++;
    }
    series++;

    QString strToPrint;
    if (cjt188_cmds_list.count())
    {
        strToPrint = "解析到命令数：" + QString::number(cjt188_cmds_list.count());
    }
    else
    {
        strToPrint = "命令集发送完成";
        meterComClose();
        this->close();
        return;
    }
    //打开串口
    meterComOpen();
    if(meterCom->isOpen())
    {
        //启动命令集管理器
        meterCmdListHandler();
    }
}
/**************************************
 * 发送数据处理
 *************************************/
void Widget::meterCmdListHandler()
{
    //判断cjt188_cmds_list有无命令
    if (!cjt188_cmds_list.count())
    {
        qDebug() << "没有命令";
        meterComClose();
        return;
    }

    //组包
    quint8 len = 0;
    quint16 cs16 = 0;
    Cjt188Object curObj = cjt188_cmds_list.first();
    //清空meterSendBuff
    meterSendBuffLen = 0;
    meterRecvBuffLen = 0;
    memset(meterSendBuff, 0, sizeof(meterSendBuff));
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));

    //协议打包
    quint8 curIndx = 0;
    meterSendBuff[curIndx++] = CJT188_HDLC_PREFIX;          //FE
    meterSendBuff[curIndx++] = CJT188_HDLC_PREFIX;          //FE
    meterSendBuff[curIndx++] = CJT188_HDLC_HEADER;          //68
    meterSendBuff[curIndx++] = CJT188_METER_GAS;            //30
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = CJT188_HDLC_BROADCAST_ADDR;  //AA
    meterSendBuff[curIndx++] = curObj.ctrlId;
    //meterSendBuff[curIndx++] = len;
    //offset = 11
    curIndx++;
    meterSendBuff[curIndx++] = (curObj.flagId >> 8) & 0xFF;
    meterSendBuff[curIndx++] = curObj.flagId & 0xFF;
    meterSendBuff[curIndx++] = CJT188_OBJ_DATA_SER_NON;
    curObj.Seriers = meterSendBuff[curIndx-1];
    //curObj.value --->meterSendBuff
    bool *ok =0;
    QString Str_in = curObj.value;
    if(
            curObj.flagId != CJT188_OBJ_ID_WR_ADDR
            && curObj.flagId != CJT188_FIO_OBJ_ID_APP_ADDR
            && curObj.flagId != CJT188_FIO_OBJ_ID_BACKUP_ADDR
            && curObj.flagId != CJT188_FIO_OBJ_ID_NET_PUSH
            && curObj.flagId != CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA
            && curObj.flagId != CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA
            && curObj.flagId != CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA)
    {//需要倒置
        Str_in.replace(QString("0x"), QString(""));
        for(int i = Str_in.length()-1;i>=0;)
        {
           meterSendBuff[curIndx++] = ("0x"+Str_in.mid(i-1,2)).toUInt(ok,0);

            i -= 2;
        }
    }
    else if(curObj.flagId == CJT188_FIO_OBJ_ID_APP_ADDR
            || curObj.flagId == CJT188_FIO_OBJ_ID_BACKUP_ADDR)
    {//部分倒置、设置IP
        QString sIP = Str_in.mid(0,8);
        QString sPort = Str_in.mid(8,4);
        QString sStr_Out_Port;
        BigToLittle(sPort,&sStr_Out_Port);

        QString sStr_meter = sIP + sStr_Out_Port;
        for(int i=0;i<sStr_meter.length();)
        {
           meterSendBuff[curIndx++] = ("0x"+sStr_meter.mid(i,2)).toUInt(ok,0);
            i += 2;
        }
    }
    else if(curObj.flagId == CJT188_FIO_OBJ_ID_NET_PUSH)
    {//网络上报参数
        QString sTime = Str_in.mid(0,8);
        QString sStr_Out_Time;
        BigToLittle(sTime,&sStr_Out_Time);

        QString sCYC = Str_in.mid(8,4);
        QString sStr_Out_CYC;
        BigToLittle(sCYC,&sStr_Out_CYC);

        QString sTimeout_In = Str_in.mid(12,4);
        QString sTimeout_Out;
        BigToLittle(sTimeout_In,&sTimeout_Out);
        QString sStr_meter = sStr_Out_Time + sStr_Out_CYC + sTimeout_Out + Str_in.right(2);
        for(int i=0;i<Str_in.length();)
        {
           meterSendBuff[curIndx++] = ("0x"+sStr_meter.mid(i,2)).toUInt(ok,0);
            i += 2;
        }
    }
    else
    {
        Str_in.replace(QString("0x"), QString(""));
        for(int i = 0;i<Str_in.length();)
        {
           meterSendBuff[curIndx++] = ("0x"+Str_in.mid(i,2)).toUInt(ok,0);

            i += 2;
        }
    }

    len = Str_in.length()/2;
    /*char tmp[3];
    memset(tmp,0,sizeof(tmp));
    bool *ok = 0;
    QByteArray ba = curObj.value.toLatin1();
    char *s = ba.data();
    char ss[128];
    memset(ss,0,sizeof(ss));
    strcpy(ss,s);
    while(*s && *s>='0' && *s<='9') s++;

    unsigned char meterSendBuff_Value[UART_BUFFER_MAX];
    memset(meterSendBuff_Value,0,sizeof(meterSendBuff_Value));
    int Len_tmp = 0;
    for(int i = 0;i<curObj.value.length();)
    {
        qDebug()<<"ss"<<ss[i]+" "+ss[i+1];
        memcpy(tmp,&ss[i],2);
        QString str = "0x" + QString(QLatin1String(tmp));
        quint8 Hex_t = str.toUInt(ok,0);
        meterSendBuff_Value[Len_tmp++] = Hex_t;
        i +=2;
    }
for(int i = 0;i<Len_tmp;i++)
{
            qDebug()<<tr("meterSendBuff_Value[%1]=").arg(i)<<meterSendBuff_Value[i];;

}

    for(int i = Len_tmp-1;i >= 0;i--)
    {

        meterSendBuff[curIndx++] = meterSendBuff_Value[i];
    }
*/
    //补写帧长
    meterSendBuff[12] = (len+3) & 0xFF;
    cs16 = Common::pGetCS16(meterSendBuff + 2, curIndx - 2);
    //校验及尾部
    meterSendBuff[curIndx++] = cs16 & 0xFF;
    meterSendBuff[curIndx++] = CJT188_HDLC_TAIL;
    meterSendBuffLen = curIndx;
    //打印待发送的原始数据
    QString k;

    for(int i=0;i<meterSendBuffLen;i++)
    {
        QString ssPeriod = QString("%1").arg(meterSendBuff[i],2,16,QLatin1Char('0'));
        //k += (QString::number(meterSendBuff[i],16) + " ");
        k += (ssPeriod + " ");
    }
    for(int i=0;i<k.length();i++)
    {

        if(k.at(i) >= 'a' && k.at(i) <= 'z')
        {
            QString y = k.at(i).toUpper();
            k.replace(i, 1, y);
        }
    }
    curObj.allcmd = k;
    qDebug()<<k;
    //存档前处理
    preActive(curObj,WriteLog);
    //将待发送数据存档
    logPrint(curObj,1);
    //下发数据
    meterComSend();
    //设置超时
    meterRecvTimer->setInterval(meterComInfo.ComTimeout);
    meterRecvTimer->start();
}


/********************************************************************
接收数据
*********************************************************************/
void Widget::meterCmdResponseHandler()
{
    series = 0x00;
    if(meterRecvBuffLen < 4)
    {
        qDebug()<<"接收长度错误";
    }
    quint16 cs16;
    cs16 = Common::pGetCS16(meterRecvBuff, meterRecvBuffLen - 2);
    if (((cs16 & 0xFF) != meterRecvBuff[meterRecvBuffLen - 2]) &&
        (0x16 == meterRecvBuff[meterRecvBuffLen - 1]))
    {
        meterRecvBuffLen = 0;
        qDebug("<错误>CS16校验不通过...");
        return;
    }
    //协议解析
    Cjt188Object recvObject;
    quint8 rxIdx = 0;
    QString p = meterRecvArr.toHex();
    recvObject.allcmd = p;
    //地址
    rxIdx = 2;
    recvObject.address = p.mid(4,14);
    rxIdx += 7;
    //控制码
    recvObject.ctrlId = meterRecvBuff[rxIdx++];
    //长度
    quint8 Len = meterRecvBuff[rxIdx++];
    //数据标识
    recvObject.flagId = meterRecvBuff[rxIdx++]<<8 & 0xFF;
    recvObject.flagId = meterRecvBuff[rxIdx++];
    //数据序号
    quint8 ser = meterRecvBuff[rxIdx++];
    //数据内容
    if(Len == 3)
    {
        recvObject.value = "";
    }
    else {
        recvObject.value = p.mid(rxIdx*2,(Len-3)*2);
    }
/*
CJT188_REQUEST_NONE
CJT188_REQUEST_GET_DATA
CJT188_REQUEST_GET_VERSION
CJT188_REQUEST_GET_ADDR

CJT188_REQUEST_SET_DATA
CJT188_REQUEST_SET_ADDR
CJT188_REQUEST_SET_MOTOR_DATA
*/
    recvObject.desc = cjt188_cmds_list.constFirst().desc;
    recvObject.requestType = cjt188_cmds_list.constFirst().requestType;
    qDebug()<<recvObject.desc;
    switch(cjt188_cmds_list.constFirst().requestType)
    {

    case CJT188_REQUEST_GET_ADDR:
    {//读地址
        //qDebug()<<"读地址完成";
        recvObject.value = recvObject.address;
        if(recvObject.ctrlId == 0x83)
        {
            recvObject.resultFlag = "success";
        }
        else{
            recvObject.resultFlag = "fail";
        }
        break;
    }
    case CJT188_REQUEST_GET_VERSION:
    {//读版本号
        //qDebug()<<"读版本号完成";
        if(recvObject.ctrlId == 0x89)
        {
            recvObject.resultFlag = "success";
        }
        else
        {
            recvObject.resultFlag = "fail";
        }
        break;
    }
    case CJT188_REQUEST_GET_DATA:
    {//读数据
        //qDebug()<<"读数据完成";
        if(recvObject.ctrlId == CJT188_CTRL_ID_RD_DATA_RETURN_SUCCESS || recvObject.ctrlId == CJT188_FIO_CTRL_ID_CMD_RD_DATA_SUCCESS)
        {
            recvObject.resultFlag = "success";
        }
        else
        {
            recvObject.resultFlag = "fail";
        }
        break;
    }
    case CJT188_REQUEST_SET_DATA:
    {//写数据
        //qDebug()<<"写数据完成";
        if(recvObject.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS)
        {
            recvObject.resultFlag = "success";
        }
        else
        {
            recvObject.resultFlag = "fail";
        }
        break;
    }
    case CJT188_REQUEST_SET_ADDR:
    {//写地址
        //qDebug()<<"写地址完成";
        if(recvObject.ctrlId == 0x95)
        {
            recvObject.resultFlag = "success";
        }
        else
        {
            recvObject.resultFlag = "fail";
        }
        break;
    }
    case CJT188_REQUEST_SET_MOTOR_DATA:
    {//写电机
        //qDebug()<<"写电机数据完成";
        if(recvObject.ctrlId == 0x96)
        {
            recvObject.resultFlag = "success";
        }
        else
        {
            recvObject.resultFlag = "fail";
        }
        break;
    }

    default:
    {
        if(recvObject.ctrlId == CJT188_FIO_CTRL_ID_REPORT_DATA)
        {
            recvObject.resultFlag = "Take the initiative to report";
        }

        break;
    }
    }

/*
    QString FlagID = p.mid(22,4);
    if( FlagID == "810a")
    {
        QString sn = p.mid(4,14);
        recvObject.desc = "get gas meter's LDN";
        ui->lineEdit->setText(sn);
    }
*/

    //删除cjt188_cmds_list第一个元素
    cjt188_cmds_list.removeFirst();
    if(cjt188_cmds_list.length() != 0)
        cjt188_cmds_list.first().Seriers = CJT188_OBJ_DATA_SER;
    //存档
    save_meterCmdResponse(recvObject);
    //打印接收到的原始数据HEX HEX
    QString k;

    for(int i=0;i<meterRecvBuffLen;i++)
    {
        QString ssPeriod = QString("%1").arg(meterRecvBuff[i],2,16,QLatin1Char('0'));
        k += (ssPeriod + " ");
        //k += (QString::number(meterRecvBuff[i],16) + " ");
    }

    for(int i=0;i<k.length();i++)
    {

        if(k.at(i) >= 'a' && k.at(i) <= 'z')
        {
            QString y = k.at(i).toUpper();
            k.replace(i, 1, y);
        }
    }
    recvObject.allcmd = k;
    logPrint(recvObject,2);
    //清空meterRecvBuff
    meterRecvBuffLen = 0;
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    QFile Savexmlfile(ResFileNm);
    if(cjt188_cmds_list.length() == 0)
    {

        if(Savexmlfile.open(QIODevice::WriteOnly | QIODevice::Append))
        {
           QTextStream stream(&Savexmlfile);
           meterCmdResponseMsg.save(stream,2);
           qDebug()<<"write ok!!!";

        }
        else
        {
            Savexmlfile.close();
            qDebug()<<"打开结果文件错误";
            return;
        }
        Savexmlfile.close();
        testTimer->stop();
        meterRecvTimer->stop();
        meterComClose();
        this->close();
    }
    else
    {
//        Savexmlfile.close();
//        testTimer->stop();
//        meterRecvTimer->stop();
        //meterComClose();
            testTimer->start(TimeOut);
            autoCmdExecution();
    }
    i = 0;
}

/* UI Related */
/*
void Widget::on_BtnWrLdn_clicked()
{
    Cjt188Object setObj;

    cjt188_cmds_list.append(setObj);
    autoCmdExecution();
}

void Widget::on_BtnSync_clicked()
{
    Cjt188Object setObj;

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QDateTime dt = ui->dateTimeEdit->dateTime();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_TIME;
    QString strTmp = dt.toString("yyyyMMddhhmmss");
//    syncTime = QString2Hex(strTmp);

    cjt188_cmds_list.append(setObj);
    autoCmdExecution();
}
*/
void Widget::save_meterCmdResponse(Cjt188Object recvObject)
{
    /*
        CJT188_REQUEST_NONE
        CJT188_REQUEST_GET_DATA
        CJT188_REQUEST_GET_VERSION
        CJT188_REQUEST_GET_ADDR

    */
    if(recvObject.requestType == CJT188_REQUEST_GET_DATA
            || recvObject.requestType == CJT188_REQUEST_GET_VERSION
            || recvObject.requestType == CJT188_REQUEST_GET_ADDR)
    {
        QDomElement GetRespons = meterCmdResponseMsg.createElement("GetResponse");
        RootNode.appendChild(GetRespons);

        QDomElement GetResult = meterCmdResponseMsg.createElement("Result");
        GetRespons.appendChild(GetResult);

        QDomElement GetData = meterCmdResponseMsg.createElement("Data");
        GetResult.appendChild(GetData);
        GetData.setAttribute("Descr",recvObject.desc);

        QDomElement GetValue = meterCmdResponseMsg.createElement("ResValue");
        GetValue.setAttribute("Value",recvObject.value);
        GetData.appendChild(GetValue);
        QDomElement DataAResult = meterCmdResponseMsg.createElement("DataAccessResult");
        DataAResult.setAttribute("Value","0");
        DataAResult.setAttribute("Result",recvObject.resultFlag);
        GetResult.appendChild(DataAResult);

    }
    /*
        CJT188_REQUEST_SET_DATA
        CJT188_REQUEST_SET_ADDR
        CJT188_REQUEST_SET_MOTOR_DATA
    */
    else if(recvObject.requestType == CJT188_REQUEST_SET_DATA
            || recvObject.requestType == CJT188_REQUEST_SET_ADDR
            || recvObject.requestType == CJT188_REQUEST_SET_MOTOR_DATA)
    {
        QDomElement SetRespons = meterCmdResponseMsg.createElement("SetResponse");
        RootNode.appendChild(SetRespons);
        QDomElement SetResult = meterCmdResponseMsg.createElement("Result");
        SetRespons.appendChild(SetResult);
        QDomElement SetData = meterCmdResponseMsg.createElement("Data");
        SetData.setAttribute("Descr",recvObject.desc);
        SetResult.appendChild(SetData);
        QDomElement SetValue = meterCmdResponseMsg.createElement("ResValue");
        SetValue.setAttribute("Value",recvObject.value);
        SetData.appendChild(SetValue);
        QDomElement SetDataAResult = meterCmdResponseMsg.createElement("DataAccessResult");
        SetDataAResult.setAttribute("Value","0");
        SetDataAResult.setAttribute("Result",recvObject.resultFlag);
        SetResult.appendChild(SetDataAResult);
    }
    else{
        QDomElement SetRespons = meterCmdResponseMsg.createElement("UnKnownCommand");
        RootNode.appendChild(SetRespons);
        QDomElement SetResult = meterCmdResponseMsg.createElement("Result");
        SetRespons.appendChild(SetResult);
        QDomElement SetData = meterCmdResponseMsg.createElement("Data");
        SetData.setAttribute("Descr","UnKnown command");
        SetResult.appendChild(SetData);
        QDomElement SetValue = meterCmdResponseMsg.createElement("ResValue");
        SetValue.setAttribute("Value","0");
        SetData.appendChild(SetValue);
        QDomElement SetDataAResult = meterCmdResponseMsg.createElement("DataAccessResult");
        SetDataAResult.setAttribute("Value","0");
        SetDataAResult.setAttribute("Result","fail");
        SetResult.appendChild(SetDataAResult);
    }
}


QByteArray Widget::QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();   //字符型
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

int Widget::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
     return ch-'0';
    else if((ch >= 'A') && (ch <= 'F'))
     return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
     return ch-'a'+10;
    else return (-1);
}


