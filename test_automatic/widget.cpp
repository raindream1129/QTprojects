#include "widget.h"
#include "writeLog.h"
#include "common.h"
#include <QTextCursor>
#include <QTimer>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <windows.h>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>


void Widget::Ctime_out()
{
    QDateTime Current_date_time =QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(Current_date_time);
}

/****************
 * 读取串口号
 * **************/
void Widget::fillPortsInfo()
{
    ui->CBComMeter->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName();
        ui->CBComMeter->addItem(list.first(), list);
    }
}

/*************************
 * 获取串口设置
 * *************************/
void Widget::loadComSettings()
{
    if(!ui->CBComMeter->currentText().isEmpty())
    {
        meterComInfo.ComPortName  = ui->CBComMeter->currentText();
        meterComInfo.ComBaudStr   = ui->CBBaudMeter->currentText();
        meterComInfo.ComBaud      = Common::GetBaudrate(meterComInfo.ComBaudStr);
        meterComInfo.ComParityStr = ui->CBParityMeter->currentText();
        meterComInfo.ComParity    = Common::GetParity(meterComInfo.ComParityStr);
        meterComInfo.ComDataBitsStr = ui->CBDataMeter->currentText();
        meterComInfo.ComDataBits  = Common::GetDataBits(meterComInfo.ComDataBitsStr);
        meterComInfo.ComStopBits  = Common::GetStopBits(ui->CBStopMeter->currentIndex() + 1);
//        meterComInfo.ComTimeout   = ui->LetTimeoutMeter->text().toInt();
//        meterComInfo.ComPoll      = ui->LetPollMeter->text().toInt();
    }
}

/*************************
 * 打开串口
 * *************************/
void Widget::meterComOpen()
{
    if(meterCom->isOpen())
        meterCom->close();
    meterComInfo.clear();
    loadComSettings();
    if(!meterComInfo.isEmpty())
    {
        meterCom->setPortName(meterComInfo.ComPortName);
        if(meterCom->open(QIODevice::ReadWrite))
        {
            meterCom->setBaudRate(meterComInfo.ComBaud);
            meterCom->setDataBits(meterComInfo.ComDataBits);
            meterCom->setParity(meterComInfo.ComParity);
            meterCom->setStopBits(meterComInfo.ComStopBits);
            logHandler("串口已打开");
        }
        else
        {
            logHandler("读串口: "+ meterCom->errorString());
            QMessageBox::warning(this,"提示","串口打开失败");

            return;
        }
    }
}

/*******************************
 * 关闭串口
 * *****************************/
void Widget::meterComClose()
{
//    meterRecvTimer->stop();
//    meterPollTimer->stop();
    if(meterCom->isOpen())
        meterCom->close();

    meterRecvBuffLen = 0;
    meterSendBuffLen = 0;
    meterComInfo.clear();
    meterRoutine.clear();
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    memset(meterSendBuff, 0, sizeof(meterSendBuff));

    logHandler("串口已关闭");
}

/************************************
 * 连接串口
 * *********************************/
void Widget::on_BtnConn_clicked()
{
    if(meterCom->isOpen())
    {
        meterComClose();
        if(!meterCom->isOpen())
            ui->BtnConn->setText(tr("连接"));
    }
    else
    {
        meterComOpen();
        if(meterCom->isOpen())
            ui->BtnConn->setText(tr("断开"));
    }

    meterRecvArr.clear();
    memset(meterSendBuff,0,sizeof(meterSendBuff));
    memset(meterRecvBuff,0,sizeof(meterRecvBuff));

}

/*******************************************
 * 串口接收数据
 * *****************************************/
void Widget::meterRecvData()
{
    //meterPollTimer->stop();
    if(meterCom->bytesAvailable())
    {
        meterRecvArr += meterCom->readAll();
        Sleep(200);
        if( meterRecvArr.startsWith(0x68) && meterRecvArr.endsWith(0x16))
        {
            meterRecvBuffLen = meterRecvArr.length();
            memcpy(meterRecvBuff, meterRecvArr, meterRecvBuffLen);
            meterCmdResponseHandler();
        }
    }
}

/******************************
 * 串口发送数据
 * ***************************/
void Widget::meterComSend()
{

    meterRoutine.rsp = METER_RSP_NONE;
    meterRecvArr.clear();
    if(meterCom->isOpen())
    {
        meterCom->write((char *)meterSendBuff, meterSendBuffLen);
    }
}

/*******************************
 *建立日志文件、命令执行
 * *****************************/
void Widget::BuiltLogFileExe()
{
    /*QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm-ss");
    QString logStr = ".\\logs\\";
    logFile = logStr + "test_log_" + current_date + ".txt";
    WriteLog.LogFileName = logFile;
    QFile logtxt(logFile);
    if(logtxt.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        //logHandler("打开日志文件");
    }
    else
    {
        logHandler("打开日志文件失败");
    }
    logtxt.close();*/
    CmdExecution();
}

/******************************
 * 日志实时打印
 * *****************************/
void Widget::logHandler(QString logString)
{
    QTextCursor cursor(ui->txtLog->document());
    cursor.insertText(tr("%1 %2\n")
                      .arg(QTime::currentTime().toString("HH:mm:ss.zzz"))
                      .arg(logString));
}

/******************************
 * 执行命令发送数据
 * ***************************/
void Widget::CmdExecution()
{
    quint8 len = 0;
    quint16 cs16 = 0;
    meterSendBuffLen = 0;
    meterRoutine.errCount = 0;
    memset(meterSendBuff, 0, sizeof(meterSendBuff));
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    WriteLog.TRFlag = Log_WRITE_DIRECTION;
    /*0xFE*/
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_PREFIX;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_PREFIX;
   /*0x68*/
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_HEADER;
    /*0x30*/
    meterSendBuff[meterSendBuffLen++] = CJT188_METER_GAS;
    /*0xAA*/
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_BROADCAST_ADDR;
    /*控制码*/
    meterSendBuff[meterSendBuffLen++] = cjt188obj.ctrlId;
    /*长度预留*/
    meterSendBuffLen++;
    /*数据标识*/
    meterSendBuff[meterSendBuffLen++] = (cjt188obj.dataId >> 8) & 0xFF;
    meterSendBuff[meterSendBuffLen++] = cjt188obj.dataId & 0xFF;
    /*序列*/
    meterSendBuff[meterSendBuffLen++] = CJT188_OBJ_DATA_SER_NON;
    /*具体数据*/
    len = cjt188obj.value.length()/2;
    char Str2Bit[3];
    memset(Str2Bit,0,sizeof(Str2Bit));
    bool *ok = 0;
    QByteArray Barray = cjt188obj.value.toLatin1();
    char *strValue = Barray.data();
    char StrArray[128];
    strcpy(StrArray,strValue);
    while(*strValue && *strValue>='0' && *strValue<='9') strValue++;


    unsigned char meterSendBuff_Value[UART_BUFFER_MAX];
    memset(meterSendBuff_Value,0,sizeof(meterSendBuff_Value));
    int Len_tmp = 0;
    for(int i = 0;i<cjt188obj.value.length();)
    {
        memcpy(Str2Bit,&StrArray[i],2);
        QString str = "0x" + QString(QLatin1String(Str2Bit));
        quint16 Hex_t = str.toUInt(ok,0);
        meterSendBuff_Value[Len_tmp++] = Hex_t;
        i +=2;
    }
    if(cjt188obj.dataId != CJT188_FIO_OBJ_ID_APP_ADDR
            && cjt188obj.dataId != CJT188_FIO_OBJ_ID_BACKUP_ADDR
            && cjt188obj.dataId != CJT188_FIO_OBJ_ID_NET_PUSH
            && cjt188obj.dataId != CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA
            && cjt188obj.dataId != CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA
            && cjt188obj.dataId != CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA)
    {
        for(int i = Len_tmp-1;i >= 0;i--)
        {
            meterSendBuff[meterSendBuffLen++] = meterSendBuff_Value[i];
        }
    }else{
        for(int i = 0;i<Len_tmp;i++)
        {
            meterSendBuff[meterSendBuffLen++] = meterSendBuff_Value[i];
        }
    }
    //补写帧长
    meterSendBuff[12] = (len+3) & 0xFF;
    cs16 = Common::pGetCS16(meterSendBuff + 2, meterSendBuffLen - 2);
    //校验及尾部
    meterSendBuff[meterSendBuffLen++] = cs16 & 0xFF;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_TAIL;

    //打印待发送的原始数据
    WriteLog.Tx_APDU.clear();
    for(int i=0;i<meterSendBuffLen;i++)
    {
        QString ssPeriod = QString("%1").arg(meterSendBuff[i],2,16,QLatin1Char('0'));
        //k += (QString::number(meterSendBuff[i],16) + " ");
        WriteLog.Tx_APDU += (ssPeriod + " ");
    }
    for(int i=0;i<WriteLog.Tx_APDU.length();i++)
    {

        if(WriteLog.Tx_APDU.at(i) >= 'a' && WriteLog.Tx_APDU.at(i) <= 'z')
        {
            QString y = WriteLog.Tx_APDU.at(i).toUpper();
            WriteLog.Tx_APDU.replace(i, 1, y);
        }
    }
    //将待发送数据存档
    WriteLog.LogFileName = logFile;
    logPrint(WriteLog);
    //下发数据
    if(!meterCom->isOpen())
        meterComOpen();
    meterComSend();
}

/*******************************
 * 接收数据处理
 * ****************************/
void Widget::meterCmdResponseHandler()
{
    WriteLog.clear();
    //接收数据长度初验
    if(meterRecvBuffLen < 4)
    {
        logHandler("接收长度错误");
    }
    //CS校验
    quint16 cs16;
    cs16 = Common::pGetCS16(meterRecvBuff, meterRecvBuffLen - 2);
    if (((cs16 & 0xFF) != meterRecvBuff[meterRecvBuffLen - 2]) &&
        (0x16 == meterRecvBuff[meterRecvBuffLen - 1]))
    {
        logHandler("CS校验错误");
        meterRecvBuffLen = 0;
        return;
    }

    CJT188Obj cjt188Recv;
    cjt188Recv.clear();
    quint8 rxIdx = 0;
    QString p = meterRecvArr.toHex();
    rxIdx = 2;
    //地址
    cjt188Recv.address = p.mid(4,14);
    rxIdx += 7;
    //控制码
    cjt188Recv.ctrlId = meterRecvBuff[rxIdx++];
    //长度
    quint8 Len = meterRecvBuff[rxIdx++];
    //数据标识
    cjt188Recv.dataId = meterRecvBuff[rxIdx++]<<8;
    cjt188Recv.dataId |= meterRecvBuff[rxIdx++];
    //数据序号
    quint8 ser = meterRecvBuff[rxIdx++];
    //数据内容
    if(Len == 3)
    {
        cjt188Recv.value = "";
    }
    else {
        cjt188Recv.value = p.mid(rxIdx*2,(Len-3)*2);
    }
//    QString value_Back = cjt188Recv.value;
//    int Len_Value = cjt188Recv.value.length();
//    for(int i = Len_Value-1;i>=0;i-=2)
//    {

//        cjt188Recv.value = cjt188Recv.value + value_Back.at(i-1) + value_Back.at(i);
//    }

    /***********************
     * 数据解析
     * *******************/
    switch(meterRoutine.task)
    {
    //读地址
    case  TASK_READ_LDN:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == 0x83)
        {
           WriteLog.Result = "success";
           logHandler(tr("[成功]读取编号%1成功")
                      .arg(cjt188Recv.address));
        }
        else{
            WriteLog.Result = "fail";
            logHandler(tr("[失败]读取编号%1失败")
                       .arg(cjt188Recv.address));
            //return;
        }
        ui->LetSn->setText(cjt188Recv.address);
//        logHandler(tr("[成功]读取编号%1成功")
//                   .arg(cjt188Recv.address));
        break;
    }
    //读计量数据
    case TASK_READ_METROLOGICAL_DATA:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if((cjt188Recv.ctrlId == CJT188_CTRL_ID_RD_DATA_RETURN_SUCCESS))
        {
            WriteLog.Result = "success";

            /*ReadJLdata *readDilog = new ReadJLdata();
            readDilog->show();
            connect(this,SIGNAL(ReadData(QString)),readDilog,SLOT(PrintData(QString)));
            emit ReadData(cjt188Recv.value);*/

            QString Time_T;
            BigToLittle(cjt188Recv.value.mid(0,8),&Time_T);
            QString Tot;
            BigToLittle(cjt188Recv.value.mid(8,8),&Tot);
            QString Tmp;
            BigToLittle(cjt188Recv.value.mid(24,4),&Tmp);
            Time_T = "0x" + Time_T;
            bool ok;

            QDateTime time = QDateTime::fromTime_t(Time_T.toInt(&ok,0)-8*60*60);

            QString Time_Now = time.toString("yyyy-MM-dd HH:mm");
            QString Totol_flow = QString::number(Tot.toDouble()/100) + "m3";

//            QString ST_Meter = SystemState(ST.toInt());
            QString Tmpr = QString::number(Tmp.toDouble()/10);

            ui->Device_timeLE->setText(Time_Now);
            ui->AllFlowLE->setText(Totol_flow);
//            ui->SYSState->setText(ST_Meter);
            ui->Temp_LE->setText(Tmpr + "   ℃");

            logHandler("[成功]读取计量数据成功...");
        }
        else
        {
            WriteLog.Result = "fail";
            logHandler("[失败]读取计量数据失败...");
            return;
        }

        break;
    }
    //写表号
    case TASK_WRITE_LDN:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == 0x95 && cjt188Recv.address == ui->LetSn->text())
        {
            WriteLog.Result = "success";
            logHandler(tr("[成功]LDN编号%1设置成功")
                       .arg(cjt188Recv.address));
        }
        else
        {
            WriteLog.Result = "fail";
            logHandler(tr("[失败]LDN编号%1设置失败")
                       .arg(cjt188Recv.address));
        }

        break;
    }
    //写时间
    case TASK_WRITE_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS ||cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("写时间成功");
        }
        else
        {
            WriteLog.Result = "fail";
            logHandler("写时间失败");
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //开阀
    case TASK_WRITE_OPEN_VALVE:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS ||cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("开阀成功");
        }
        else
        {
            WriteLog.Result = "fail";
            logHandler("开阀失败");
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //关阀
    case TASK_WRITE_CLOSE_VALVE:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS ||cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("关阀成功");

        }
        else
        {
            WriteLog.Result = "fail";
            logHandler("关阀失败");
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }

    //读历史数据
    case TASK_READ_HISTORY_DATA:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            logHandler("读历史数据成功");
            WriteLog.Result = "success";
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读历史数据失败");
            return;
        }
        meterRoutine.rsp = METER_RSP_OK;
        emit(ReadHstDtR(cjt188Recv));
        break;
    }
    //读网络上报参数
    case TASK_READ_REPORT_PERIOD_NET:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            logHandler("读取网络上报参数成功");
            WriteLog.Result = "success";
        }
        else{
            logHandler("读取网络上报参数失败");
            WriteLog.Result = "fail";
        }
        meterRoutine.rsp = METER_RSP_OK;
        emit ReadreportPeriod(cjt188Recv.dataId,cjt188Recv.value);

        break;
    }
    //读累加器采样参数
    case TASK_READ_ACCUMULATOR_PARAM:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            logHandler("读累加器采样参数成功");
            WriteLog.Result = "success";
        }
        else{
            logHandler("读取累加器采样参数失败");
            WriteLog.Result = "fail";
        }
        meterRoutine.rsp = METER_RSP_OK;
        emit ReadreportPeriod(cjt188Recv.dataId,cjt188Recv.value);

        break;
    }
    //读温度采样时间
    case TASK_READ_TEMP_SAMP_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            logHandler("读取温度采样周期成功");
            WriteLog.Result = "success";
        }
        else{
            logHandler("读取温度采样周期失败");
            WriteLog.Result = "fail";
        }
        meterRoutine.rsp = METER_RSP_OK;
        emit ReadreportPeriod(cjt188Recv.dataId,cjt188Recv.value);

        break;
    }
    //设置网络上报参数
    case TASK_WRITE_REPORT_PERIOD:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            logHandler("设置上报周期成功");
            WriteLog.Result = "success";
            QMessageBox::about(RepPd,"提示","设置上报周期成功");
        }
        else{
            logHandler("设置上报周期失败");
            WriteLog.Result = "fail";
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //设置累加器采样参数
    case TASK_WRITE_ACC_SAMP_PARA:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            logHandler("设置累加器参数成功");
            WriteLog.Result = "success";
            QMessageBox::about(RepPd,"提示","设置累加器采样参数成功");
        }
        else{
            logHandler("设置累加器采样参数失败");
            WriteLog.Result = "fail";
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //设置温度采样时间
    case TASK_WRITE_TEMP_SAMP_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            logHandler("设置温度采样参数成功");
            WriteLog.Result = "success";
            QMessageBox::about(RepPd,"提示","设置温度采样参数成功");
        }
        else
        {
            logHandler("设置累加器采样参数失败");
            WriteLog.Result = "fail";
            QMessageBox::about(RepPd,"提示","设置温度采样参数失败");
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //设置电压阈值
    case TASK_WRITE_VOLTAGE_TH:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_BATT_THRESHOLD)
        {
            WriteLog.Result = "success";
            logHandler("写电压阈值成功");
        }else{
            WriteLog.Result = "fail";
            logHandler("写电压阈值失败");
        }
        break;
    }
    //读外部电压值
    case TASK_READ_EXTERNAL_VOL:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("读外部电压值成功");
            bool ok;
            QString sStr = "0x" + cjt188Recv.value;
            int iStr = sStr.toInt(&ok,0);
            sStr = QString::number((double)iStr/10);
            ui->lineEV->setText(sStr+"V");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读外部电压值失败");
        }
        break;
    }
    //读电压阈值
    case TASK_READ_VOLTAGE_TH:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("读电压阈值成功");
            QString sStr;
            BigToLittle_Int(cjt188Recv.value,&sStr);

            double Vol = sStr.toDouble();
            ui->lineEVTh->setText(QString::number(Vol));
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读电压阈值失败");
        }
        break;
    }
    //读仪表工作状态
        /*
    case TASK_READ_DEVICE_STATE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("读仪表工作状态成功");
            QString sState;
            sState.clear();
            if(cjt188Recv.value ==  "00")
            {
                sState = "闲置状态";
            }
            else if(cjt188Recv.value ==  "01")
            {
                sState = "正常工作状态";
            }
            else if(cjt188Recv.value ==  "02")
            {
                sState = "超大流量";
            }
            else if(cjt188Recv.value ==  "03")
            {
                sState = "超小流量";
            }
            else if(cjt188Recv.value ==  "04")
            {
                sState = "故障状态";
            }
            else if(cjt188Recv.value ==  "05")
            {
                sState = "报废状态";
            }
            else if(cjt188Recv.value ==  "06")
            {
                sState = "无休眠状态";
            }
            else
            {
               sState = "未知状态" ;
            }

            ui->LEWKSTATE->setText(sState);
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读仪表工作状态失败");
        }
        break;
    }
    */
    //读工作模式
    case TASK_READ_MODLE_CHANGE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("读模式成功");
            if(cjt188Recv.value.mid(1,1) == "0")
            {
                ui->ModleChgCBB->setCurrentIndex(0);
            }
            else if(cjt188Recv.value.mid(1,1) == "1"){
                ui->ModleChgCBB->setCurrentIndex(1);
            }
            else if(cjt188Recv.value.mid(1,1) == "2")
            {
                ui->ModleChgCBB->setCurrentIndex(2);
            }
            else{
                logHandler("未知模式");
                ui->ModleChgCBB->setCurrentText("未知模式");
            }
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读模式失败");
        }
        break;
    }
    //设置工作模式
    case TASK_WRITE_MODLE_CHANGE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置模式成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置模式失败");
        }
        break;
    }
    //读系统状态
    case TASK_READ_SYSTEM_STATE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sV;
            BigToLittle(cjt188Recv.value,&sV);
            ui->SYS_ST_LE->setText(SystemState(("0x"+sV).toInt(NULL,0)));
            WriteLog.Result = "success";
            logHandler("读系统状态成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读系统状态失败");
        }
        break;
    }
    //读设备运行时间
    case TASK_READ_WORKING_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sWorkingT;
            BigToLittle_Int(cjt188Recv.value,&sWorkingT);

            ui->WorkingT_LE->setText(sWorkingT+"小时");
            WriteLog.Result = "success";
            logHandler("读设备运行时间成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读设备运行时间失败");
        }
        break;
    }
    //读余额
    case TASK_READ_BALANCE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sVin = cjt188Recv.value;
            QString sVout;
            BigToLittle(sVin,&sVout);
            bool ok;
            long bal = ("0x"+sVout).toLongLong(&ok,0);
            qDebug()<<bal;
            //BigToLittle_Int(sVin,&sVout);
            ui->Alarm_Bal_LE->setText(QString::number(bal));
            WriteLog.Result = "success";
            logHandler("读余额控制成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读余额控制失败");
        }

        break;
    }
    //读剩余用气量
    case TASK_READ_REMAIN_GAS:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sStr = cjt188Recv.value;
            QString sVout;
            BigToLittle(sStr,&sVout);
            sVout = QString::number(sVout.toInt());
            ui->Alarm_Gas_LE->setText(sVout);
            WriteLog.Result = "success";
            logHandler("读余量控制成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读余量控制失败");
        }
        break;
    }
    //读版本号
    case TASK_READ_DEVICENET_VERSION:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            ui->SEV_Version_LE->setText(QString::number(cjt188Recv.value.toInt()));
            WriteLog.Result = "success";
            logHandler("读版本信息成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读版本信息失败");
        }

        break;
    }
    //读温度
    case TASK_READ_ENVIRONMENT_TEMPERATURE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            ui->Temp_LE->setText(QString::number(cjt188Recv.value.toDouble()/10.0) + "  ℃");
            WriteLog.Result = "success";
            logHandler("读温度信息成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读温度息失败");
        }
        break;
    }
    //读最大流量
    case TASK_READ_MAX_FLOW:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sVin = cjt188Recv.value;
            QString sVout;
            BigToLittle_Int(sVin,&sVout);
            ui->MAX_FLOW_LE->setText(QString::number(sVout.toDouble()*0.01));
            WriteLog.Result = "success";
            logHandler("读最大流量成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读最大流量失败");
        }
        break;
    }
    //读最小流量
    case TASK_READ_MIN_FLOW:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {

            QString sVin = cjt188Recv.value;
            QString sVout;
            BigToLittle_Int(sVin,&sVout);
            ui->Min_Flow_LE->setText(QString::number(sVout.toDouble()*0.01));
            WriteLog.Result = "success";
            logHandler("读最小流量成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读最小流量失败");
        }

        break;
    }
    //读闲置时间闲置超时关阀
    case TASK_READ_IDLE_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sStr;
            BigToLittle_Int(cjt188Recv.value,&sStr);

            ui->IdleT_LE->setText(sStr);
            WriteLog.Result = "success";
            logHandler("读闲置时间成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读闲置时间失败");
        }
        break;
    }
    //读连续不通讯时间
    case TASK_READ_DROP_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sTime;
            BigToLittle_Int(cjt188Recv.value,&sTime);
            ui->DropTimeLE->setText(sTime + "天");
            WriteLog.Result = "success";
            logHandler("读掉线时间成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读掉线时间失败");
        }
        break;
    }
    //已闲置时长
    case TASK_READ_IDLED_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sTime;
            BigToLittle_Int(cjt188Recv.value,&sTime);
            ui->IdledTs_LE->setText(sTime);
            WriteLog.Result = "success";
            logHandler("读已闲置时间成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读已闲置时间失败");
        }
        break;
    }
    //手动上报
    case TASK_WRITE_HANDLE_REPORT:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("手动上报成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("手动上报失败");
        }
        break;
    }
    //读模组信息
    case TASK_READ_MODLE_INFORMATION:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString ssICCID;
            ssICCID.clear();
            QString sICCID = cjt188Recv.value.mid(0,40);
//            QString sVersion = cjt188Recv.value.mid(20,12);
//            QString sICCID = cjt188Recv.value.mid(32,40);
            for(int i =0;i<sICCID.length();i+=2)
            {
                bool ok;
                int iIccic = ("0x"+sICCID.mid(i,2)).toInt(&ok,0);
                qDebug()<<iIccic;
                QString s = (QChar)iIccic;
                ssICCID += s;
            }
            //QString ssICCID = QString::number(sICCID.toInt());

            ui->ModleInf->setText(tr("模组信息：\n厂商：0；"
                                    "\n版本：0；"
                                    "\nICCID：%1；").arg(ssICCID));

            WriteLog.Result = "success";
            logHandler("读模组信息成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读模组信息失败");
        }
        break;
    }
    //读应用服务器
    case TASK_READ_APPLICATION_SERVER:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString IP_sStr_In = cjt188Recv.value.mid(0,8);
            QString IP;
            IP = IP_sStr_In;
            //BigToLittle(IP_sStr_In,&IP);
            bool ok;

            QString PORT;
            BigToLittle_Int(cjt188Recv.value.mid(8,4),&PORT);

            QString sIP = QString::number(("0x"+IP.mid(0,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(2,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(4,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(6,2)).toInt(&ok,0));
            ui->AppSevIPLE->setText(sIP);
            ui->AppSevPortLE->setText(PORT);
            WriteLog.Result = "success";
            logHandler("读应用服务器成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读应用服务器失败");
        }
        break;
    }
    //读备份服务器
    case TASK_READ_BACKUP_SERVER:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            bool ok;
            QString IP = cjt188Recv.value.mid(0,8);
            QString sIP = QString::number(("0x"+IP.mid(0,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(2,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(4,2)).toInt(&ok,0)) + "."
                    + QString::number(("0x"+IP.mid(6,2)).toInt(&ok,0));

            QString PORT;
            BigToLittle_Int(cjt188Recv.value.mid(8,4),&PORT);
            ui->BackUpIPLE->setText(sIP);
            ui->BackUpSevPortLE->setText(PORT);
            WriteLog.Result = "success";
            logHandler("读备份服务器成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读备份服务器失败");
        }
        break;
    }
    //读频宽
    case TASK_READ_BAND_WIDTH:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            ui->BandWidthLE->setText(QString::number(cjt188Recv.value.toInt()));
            WriteLog.Result = "success";
            logHandler("读频宽成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读频宽失败");
        }
        break;
    }
    //读PLMN
    case TASK_READ_NBIOT_PLMN:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sPLMN;
            BigToLittle_Int(cjt188Recv.value,&sPLMN);
            ui->PLMN_LE->setText(sPLMN);
            WriteLog.Result = "success";
            logHandler("读PLMN成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读PLMN失败");
        }
        break;
    }
    //读错峰
    case TASK_READ_NBIOT_AVOID_PEAK:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            bool ok;
            int sAble = ("0x" + cjt188Recv.value.mid(0,2)).toInt(&ok,0);
            if(sAble == 0)
            {
                ui->AvoidPeakAbleST->setText("使能关闭");
            }else{
                ui->AvoidPeakAbleST->setText("使能打开");
            }
            QString sAvoid;
            BigToLittle_Int(cjt188Recv.value.mid(2,4),&sAvoid);
            //QString sAvoidPeakT =QString::number(cjt188Recv.value.mid(2,4).toInt());
            ui->AvoidPeakTimeLE->setText(sAvoid +"  分钟");
            WriteLog.Result = "success";
            logHandler("读错峰信息成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读错峰信息失败");
        }
        break;
    }
    //设置最大流量
    case TASK_WRITE_MAX_FLOW:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置最大流量成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置最大流量失败");
        }
        break;
    }
    //设置最小流量
    case TASK_WRITE_MIN_FLOW:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置最小流量成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置最小流量失败");
        }
        break;
    }
    //设置闲置时长
    case TASK_WRITE_IDLE_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置闲置时长成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置闲置时长失败");
        }
        break;
    }
    //设置应用服务器
    case TASK_WRITE_APPLICATION_SERVER:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置应用服务器成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置应用服务器失败");
        }
        break;
    }
    //设置备份服务器
    case TASK_WRITE_BACKUP_SERVER:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置备份服务器成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置备份服务器失败");
        }
        break;
    }
    //设置频宽
    case TASK_WRITE_BAND_WIDTH:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置频宽成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置频宽失败");
        }
        break;
    }
    //设置PLMN
    case TASK_WRITE_PLMN:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置PLMN成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置PLMN失败");
        }
        break;

    }
    //关闭避峰使能
    case TASK_WRITE_AVOID_PEAK_ENABLE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置使能避峰关闭成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置使能避峰关闭失败");
        }
        break;

    }
    //避峰使能
    case TASK_WRITE_AVOID_PEAK_ABLE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("设置使能避峰打开成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("设置使能避峰打开失败");
        }
        break;

    }
    //查看异常
    case TASK_READ_CHECK_NORMAL_STATION:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sForceOpenT = cjt188Recv.value.mid(0,8);
            QDateTime ForceOpenT_time = QDateTime::fromTime_t(sForceOpenT.toInt());
            QString ssForceOpenT = ForceOpenT_time.toString("yyyyMMddHHmmss");
            QString sForceOpenTs = cjt188Recv.value.mid(8,2);

            QString sLostElect = cjt188Recv.value.mid(10,8);
            QDateTime LostElect_time = QDateTime::fromTime_t(sLostElect.toInt());
            QString ssLostElect = LostElect_time.toString("yyyyMMddHHmmss");
            QString sLostElectTs = cjt188Recv.value.mid(18,2);

            QString sFlowSmaller = cjt188Recv.value.mid(20,8);
            QDateTime FlowSmaller_time = QDateTime::fromTime_t(sFlowSmaller.toInt());
            QString ssFlowSmaller = FlowSmaller_time.toString("yyyyMMddHHmmss");
            QString sFlowSmallerTs = cjt188Recv.value.mid(28,2);

            QString sValveFault = cjt188Recv.value.mid(30,8);
            QDateTime ValveFault_time = QDateTime::fromTime_t(sValveFault.toInt());
            QString ssValveFault = ValveFault_time.toString("yyyyMMddHHmmss");
            QString sValveFaultTs = cjt188Recv.value.mid(38,2);

            QString sStrongElecInterFerence = cjt188Recv.value.mid(40,8);
            QDateTime StrongElecInterFerence_time = QDateTime::fromTime_t(sStrongElecInterFerence.toInt());
            QString ssStrongElecInterFerence = StrongElecInterFerence_time.toString("yyyyMMddHHmmss");
            QString sStrongElecInterFerenceTs = cjt188Recv.value.mid(48,2);

            ui->AbnormalST->setText(tr("破拆:  发生时间:%1 发生次数:%2"
                                       "\n掉电:   发生时间:%3 发生次数:%4"
                                       "\n读数回退: 发生时间:%5 发生次数:%6"
                                       "    阀门故障: 发生时间:%7 发生次数:%8"
                                       "\n强磁干扰: 发生时间:%9 发生次数:").arg(ssForceOpenT,sForceOpenTs,ssLostElect,sLostElectTs,ssFlowSmaller,sFlowSmallerTs,ssValveFault,sValveFaultTs,ssStrongElecInterFerence) + sStrongElecInterFerenceTs);


            WriteLog.Result = "success";
            logHandler("查看异常成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("查看异常失败");
        }
        break;
    }
    //清除异常
    case TASK_READ_CLEAR_NORMAL_STATION:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("清除异常成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("清除异常失败");
        }
        break;
    }
    //余额设置
    case TASK_WRITE_ALARM_BALANCE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("余额成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("余额失败");
        }
        break;

    }
    //余量设置
    case TASK_WRITE_ALARM_FLOW:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("报警余量成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("报警余量失败");
        }
        break;
    }
    //读设备启用时间--自动唤醒时间
    case TASK_READ_DEVICE_WAKEUP_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString V_In = cjt188Recv.value;
            QString V_Out;
            BigToLittle_Int(V_In,&V_Out);
            ui->Wakeup_time_LE->setDateTime(QDateTime::fromTime_t(V_Out.toInt()));
            WriteLog.Result = "success";
            logHandler("读设备启用时间成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读设备启用时间失败");
        }
        break;

    }
    //设置唤醒时间
    case TASK_WRITE_WAKEUP_TIME:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            WriteLog.Result = "success";
            logHandler("唤醒时间设置成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("唤醒时间设置失败");
        }
        break;
    }
    //读警示余额
    case TASK_READ_ALARM_BANLANCE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sVin = cjt188Recv.value;
            QString sVout;
            BigToLittle(sVin,&sVout);
            bool ok;
            long bal = ("0x"+sVout).toLongLong(&ok,0);
            qDebug()<<bal;
            //BigToLittle_Int(sVin,&sVout);
            ui->lineEdit->setText(QString::number(bal));
            WriteLog.Result = "success";
            logHandler("读警示余额成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读警示余额失败");
        }
        break;
    }
    case TASK_READ_OVERDRAFT:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {
            QString sVin = cjt188Recv.value;
            QString sVout;
            BigToLittle(sVin,&sVout);
            bool ok;
            long bal = ("0x"+sVout).toLongLong(&ok,0);
            qDebug()<<bal;
            //BigToLittle_Int(sVin,&sVout);
            ui->lineEdit_2->setText(QString::number(bal));
            WriteLog.Result = "success";
            logHandler("读透支余额成功");
        }
        else{
            WriteLog.Result = "fail";
            logHandler("读透支余额失败");
        }
        break;

    }
    default:
        break;
    }

    WriteLog.TRFlag = Log_READ_DIRECTION;
    //打印接收的原始数据
    WriteLog.Rx_APDU.clear();
    for(int i=0;i<meterRecvBuffLen;i++)
    {
        QString ssPeriod = QString("%1").arg(meterRecvBuff[i],2,16,QLatin1Char('0'));
        //k += (QString::number(meterSendBuff[i],16) + " ");
        WriteLog.Rx_APDU += (ssPeriod + " ");
    }
    for(int i=0;i<WriteLog.Rx_APDU.length();i++)
    {

        if(WriteLog.Rx_APDU.at(i) >= 'a' && WriteLog.Rx_APDU.at(i) <= 'z')
        {
            QString y = WriteLog.Rx_APDU.at(i).toUpper();
            WriteLog.Rx_APDU.replace(i, 1, y);
        }
    }
    WriteLog.LogFileName = logFile;
    logPrint(WriteLog);
}

/*******************************
 * 读地址表号
 * ****************************/
void Widget::on_BtnRDAddr_clicked()
{
    ui->LetSn->clear();
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_LDN;
    cjt188obj.ctrlId = CJT188_CTRL_ID_RD_ADDR;
    cjt188obj.dataId = CJT188_OBJ_ID_RD_MET_ARRD;
    cjt188obj.value = ui->LetSn->text();
    WriteLog.desc = "get gas meter's LDN";
    BuiltLogFileExe();
}

/****************************
 * 读计量数据
 * *************************/
/*void Widget::on_RdMtDt_Btn_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_METROLOGICAL_DATA;
    cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
    cjt188obj.dataId = CJT188_OBJ_ID_RD_METROLOGICAL_DATA;
    WriteLog.desc = "get gas meter's metrological data";
    BuiltLogFileExe();
}
*/
/******************************
 *设置表号
 * ***************************/
void Widget::on_SetLDN_clicked()
{
    meterRoutine.errCount = 0;
    WriteLog.clear();
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_LDN;
    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_ADDR;
    cjt188obj.dataId = CJT188_OBJ_ID_WR_ADDR;
    QString No = ui->LetSn->text();
    if(No.length() != 14)
    {
        logHandler("表号长度错误");
        QMessageBox::warning(this,"提示","LDN长度错误");
        return;
    }
    for(int i=No.length()-1;i>=0;)
    {
        cjt188obj.value = cjt188obj.value + No.mid(i-1,2);
        i -= 2;
    }

    WriteLog.desc = "set gas meter's LDN";

    BuiltLogFileExe();
}

/*************************************
 * 开阀
 * ***********************************/
void Widget::on_BtnOpenV_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_OPEN_VALVE;
    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_OBJ_ID_WR_VALVE_CTROL;
    cjt188obj.value = "00";
    WriteLog.desc = "open the gas meter's valve";

    BuiltLogFileExe();
}

/*******************************
 * 关阀
 * ****************************/
void Widget::on_BtnClsV_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_CLOSE_VALVE;
    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_OBJ_ID_WR_VALVE_CTROL;
    cjt188obj.value = "01";
    WriteLog.desc = "close the gas meter's valve";

    BuiltLogFileExe();
}

/************************************
 * 设置时间
 * *********************************/
void Widget::on_BtnSetT_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_TIME;
    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_OBJ_ID_WR_TIME;
    //ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QDateTime dt = ui->dateTimeEdit->dateTime();
    //QString strTmp = dt.toString("yyyyMMddhhmmss");
    QString strTmp = QString("%1").arg(dt.toTime_t(),8,16,QLatin1Char('0'));
    cjt188obj.value = strTmp;
    WriteLog.desc = "set the gas meter's time";

    BuiltLogFileExe();
}

/*************************************
 * 读历史数据
 * **********************************/
void Widget::on_pushButton_clicked()
{
    WriteLog.clear();
    readHistory = new ReadHstDt();
    readHistory->show();
    connect(readHistory,SIGNAL(ReadHistDt(CJT188Obj)),this,SLOT(ReadHistoryData(CJT188Obj)));
    connect(this,SIGNAL(ReadHstDtR(CJT188Obj)),readHistory,SLOT(ReadHstDtResponse(CJT188Obj)));
    WriteLog.desc = "read history data";
}
void Widget::ReadHistoryData(CJT188Obj cjt188Tmp)
{
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_HISTORY_DATA;
    //cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_CMD_RD_DATA;
    //cjt188obj.dataId = CJT188_FIO_OBJ_ID_HISTORY_DATA;
    WriteLog.desc = cjt188Tmp.desc;
    cjt188obj = cjt188Tmp;
    BuiltLogFileExe();
}

/*********************************
 * 网络上报参数设置(读)
 * ******************************/
void Widget::on_RdReportPeriodBtn_clicked()
{
    RepPd = new ReportPeriod();
    RepPd->show();
    //connect(RepPd,SIGNAL(RepPd(QString)),this,SLOT(Reportpd(QString)));
    connect(this,SIGNAL(ReadreportPeriod(quint32,QString)),RepPd,SLOT(ReadRPPd(quint32,QString)));
    connect(RepPd,SIGNAL(RepTimeSet(CJT188Obj)),this,SLOT(RepTimeSet(CJT188Obj)));
    Timer->start(MAX_TIMEOUT_READ);
}

void Widget::TTimeout()
{
    WriteLog.clear();
    cjt188obj.clear();
    switch (i)
    {
    case 0:
    {
        //读网络上报
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_REPORT_PERIOD_NET;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NET_PUSH;
        WriteLog.desc = "read report period data by net";
        BuiltLogFileExe();
       break;
    }
    case 1:
    {
        //读累加器采样
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_ACCUMULATOR_PARAM;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_CUMULATIVE_SAMP;
        WriteLog.desc = "read accumulator parameter";
        BuiltLogFileExe();
        break;
    }
    case 2:
    {
        //温度采样时间
        ////WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_TEMP_SAMP_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_TEMP_SAMP;
        WriteLog.desc = "read Temprature sampling time";
        BuiltLogFileExe();
        break;
    }
    default:
    {
        Timer->stop();
        i = 0;
        return;
    }
    }

   i++;
}

/*************************************************
 * 网络上报与累加器温度参数设置(写)
 * **********************************************/
void Widget::RepTimeSet(CJT188Obj cjt188obj_tmp)
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    //meterRoutine.task = TASK_WRITE_REPORT_PERIOD;
    switch(cjt188obj_tmp.dataId)
    {
    case CJT188_FIO_OBJ_ID_NET_PUSH:
    {
        meterRoutine.task = TASK_WRITE_REPORT_PERIOD;//写网络上报参数
        break;
    }
    case CJT188_FIO_OBJ_ID_CUMULATIVE_SAMP:
    {
        meterRoutine.task = TASK_WRITE_ACC_SAMP_PARA;//累加器采样
        break;
    }
    case CJT188_FIO_OBJ_ID_TEMP_SAMP:
    {
        meterRoutine.task = TASK_WRITE_TEMP_SAMP_TIME;//温度采样
        break;
    }
    default :
    {
        logHandler("dateid错误");
        WriteLog.Result = "fail";
        QMessageBox::about(RepPd,"提示","dateid错误");
        break;
    }
    }

    WriteLog.desc = cjt188obj.desc;
    cjt188obj = cjt188obj_tmp;
    BuiltLogFileExe();
}

/***************************************************
 * 电压阈值设置
 * ************************************************/
void Widget::on_BtnVth_clicked()
{
    WriteLog.clear();
    QString VValue = ui->lineEVTh->text();
    //VValue = VValue.remove(".");
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_VOLTAGE_TH;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_BATT_THRESHOLD;
    QString ssReTs = QString("%1").arg(VValue.toInt(),2,16,QLatin1Char('0'));
    cjt188obj.value = ssReTs;
    WriteLog.desc = "set the gas meter's voltage threshold";

    BuiltLogFileExe();
}

/**********************************************************
 * 网络参数
 * *******************************************************/
/*void Widget::on_NetSetBtn_clicked()
{
        NetCnf = new NetConfig();
    NetCnf->show();
    connect(NetCnf,SIGNAL(NetCfgSet(CJT188Obj)),this,SLOT(NetCon(CJT188Obj)));
}
void Widget::NetCon(CJT188Obj cjt188obj_tmp)
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_NETCONFIG;

    switch (cjt188obj_tmp.dataId) {
    case CJT188_FIO_OBJ_ID_APP_ADDR:
    {
        WriteLog.desc = "set the gas meter's application IP";
        break;
    }
    case CJT188_FIO_OBJ_ID_BACKUP_ADDR:
    {
        WriteLog.desc = "set the gas meter's backup IP";
        break;
    }
    case CJT188_FIO_OBJ_ID_UPGRADE_ADDR:
    {
        WriteLog.desc = "set the gas meter's upgrade IP";
        break;
    }
    case CJT188_FIO_OBJ_ID_PLATFORM_ADDR:
    {
        WriteLog.desc = "set the gas meter's platform IP";
        break;
    }
    default:
        break;
    }

    cjt188obj.desc = WriteLog.desc;
    cjt188obj = cjt188obj_tmp;
    BuiltLogFileExe();

}
*/
/*******************************************
 * 读仪表各项配置参数
 * ****************************************/
void Widget::on_pushButton_2_clicked()
{
    ui->Device_timeLE->clear();
    ui->AllFlowLE->clear();
    ui->SYS_ST_LE->clear();
    ui->WorkingT_LE->clear();
    ui->Alarm_Bal_LE->clear();
    ui->Alarm_Gas_LE->clear();
    ui->SEV_Version_LE->clear();
    ui->DropTimeLE->clear();
    ui->Temp_LE->clear();
    ui->lineEV->clear();
    ui->lineEVTh->clear();
    ui->MAX_FLOW_LE->clear();
    ui->Min_Flow_LE->clear();
    ui->IdledTs_LE->clear();
    ui->IdleT_LE->clear();
    ui->lineEdit->clear();
    i = 0;
    Timer_A->start(MAX_TIMEOUT_READ);
}
void Widget::TTimeout_A()
{
    WriteLog.clear();
    cjt188obj.value = "";
    switch (i)
    {
    case 0:
    {
        /*
        //仪表工作状态
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_DEVICE_STATE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_METER_WORKING_STATE;
        WriteLog.desc = "get the gas meter's working state";
        BuiltLogFileExe();
        */
        //读计量数据
        WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_METROLOGICAL_DATA;
        cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_OBJ_ID_RD_METROLOGICAL_DATA;
        WriteLog.desc = "get gas meter's metrological data";
        BuiltLogFileExe();
       break;
    }
    case 1:
    {
        //系统状态
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_SYSTEM_STATE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_SYSTEM_STATE;
        WriteLog.desc = "get the gas meter's system state";
        BuiltLogFileExe();

        break;
    }
    case 2:
    {
        //设备运行时间
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_WORKING_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_WORKING_TIME;
        WriteLog.desc = "get the gas meter's meter working times";
        BuiltLogFileExe();
        break;
    }
    case 3:
    {
        //余额
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_BALANCE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_BALANCE_SET;
        WriteLog.desc = "get the gas meter's balance";
        BuiltLogFileExe();
        break;
    }
    case 4:
    {
        //剩余用气量
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_REMAIN_GAS;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_ALLOWANCE_SET;
        WriteLog.desc = "get the gas meter's remaining gas";
        BuiltLogFileExe();
        break;
    }
    case 5:
    {
        //版本号
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_DEVICENET_VERSION;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_CONFIG_VERSION;
        WriteLog.desc = "get the gas meter's config versions";
        BuiltLogFileExe();

        break;
    }
    case 6:
    {
        //温度
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_ENVIRONMENT_TEMPERATURE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_GET_TEMERATURE;
        WriteLog.desc = "get the gas meter's temerature";
        BuiltLogFileExe();
        break;
    }
    case 7:
    {
        //模式切换
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_MODLE_CHANGE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_MODLE_CHANGE;
        WriteLog.desc = "get the gas meter's working modle";
        BuiltLogFileExe();
        break;
    }
    case 8:
    {
        //外电电压
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_EXTERNAL_VOL;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_VOL_OUT;
        WriteLog.desc = "read gas meter's external voltage";
        BuiltLogFileExe();
        break;
    }
    case 9:
    {
        //电压阈值
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_VOLTAGE_TH;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_BATT_THRESHOLD;
        WriteLog.desc = "get the gas meter's voltage threshold";
        BuiltLogFileExe();
        break;
    }
    case 10:
    {
        //最大流量
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_MAX_FLOW;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_MAX_FLOW;
        WriteLog.desc = "get the gas meter's max flow";
        BuiltLogFileExe();

        break;
    }
    case 11:
    {
        //最小流量
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_MIN_FLOW;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_MIN_FLOW;
        WriteLog.desc = "get the gas meter's min flow";
        BuiltLogFileExe();

        break;
    }
    case 12:
    {
        //闲置时间
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_IDLE_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_CONTINUE_IDLE_TIME;
        WriteLog.desc = "get the gas meter's ilde time";
        BuiltLogFileExe();

        break;
    }
    case 13:
    {
        //连续不通讯时间
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_DROP_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_DROP_TIME;
        WriteLog.desc = "get the gas meter's drop time";
        BuiltLogFileExe();
        break;
    }
    case 14:
    {
        //已闲置时长
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_IDLED_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_IDLED_TIME;
        WriteLog.desc = "get the gas meter's idled time";
        BuiltLogFileExe();
        break;
    }
    case 15:
    {
        //警示额度
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_ALARM_BANLANCE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_ALARM_BANLANCE;
        WriteLog.desc = "get the gas meter's alarm banlace";
        BuiltLogFileExe();
        break;
    }
    case 16:
    {
        //唤醒时间--设备启用
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_DEVICE_WAKEUP_TIME;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_WAKEUP_TIME;
        WriteLog.desc = "get the gas meter's wakeup time on the factory modle";
        BuiltLogFileExe();
        break;
    }
    case 17:
    {
        //透支额度
        //WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_OVERDRAFT;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_OVERDRAFT;
        WriteLog.desc = "get the gas meter's over draft";
        BuiltLogFileExe();
        break;
    }
    default:
    {
        Timer_A->stop();
        i = 0;
        return;
    }
    }

   i++;
}

//设置模式
void Widget::on_ModleBTN_clicked()
{
    WriteLog.clear();
    QString VValue = ui->ModleChgCBB->currentText();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_MODLE_CHANGE;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_MODLE_CHANGE;
    if(VValue == "工厂模式(0)")
    {
        cjt188obj.value = "00";
    }
    else if(VValue == "出厂模式(1)"){
        cjt188obj.value = "01";
    }else if(VValue == "用户模式(2)")
    {
        cjt188obj.value = "02";
    }
    else{
        QMessageBox::about(this,"提示","未知模式");
        return;
    }
    WriteLog.desc = "set the gas meter's model";

    BuiltLogFileExe();
}

/**********************************
 * 最大流量设置
 * *******************************/
void Widget::on_MaxFlowBTN_clicked()
{
    QString sValue = ui->MAX_FLOW_LE->text();
    sValue.remove(".");
    sValue = sValue+"0000";
    int iValue = sValue.left(3).toInt();
    QString ssValue = QString("%1").arg(iValue,8,16,QLatin1Char('0'));

    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_MAX_FLOW;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_MAX_FLOW;
    WriteLog.desc = "set the gas meter's max flow";
    cjt188obj.value = ssValue;

    BuiltLogFileExe();
}

/**********************************
 * 最小流量设置
 * *******************************/
void Widget::on_MinFlow_BTN_clicked()
{
    QString sValue = ui->Min_Flow_LE->text();
    sValue.remove(".");
    sValue = sValue+"0000";
    int iValue = sValue.left(3).toInt();
    QString ssValue = QString("%1").arg(iValue,8,16,QLatin1Char('0'));

    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_MIN_FLOW;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_MIN_FLOW;
    WriteLog.desc = "set the gas meter's min flow";
    cjt188obj.value = ssValue;

    BuiltLogFileExe();
}

/**********************************
 * 闲置时间
 * *******************************/
void Widget::on_IdleT_BTN_clicked()
{
    QString sDate = ui->IdleT_LE->text();
    int iDate = sDate.toInt();
    QString ssDate = QString("%1").arg(iDate,8,16,QLatin1Char('0'));
    QString sStr_out;
    BigToLittle(ssDate,&sStr_out);
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_IDLE_TIME;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CONTINUE_IDLE_TIME;
    WriteLog.desc = "set the gas meter's idle time";
    cjt188obj.value = ssDate;

    BuiltLogFileExe();


}

/************************************
 *手动上报
 * *********************************/
void Widget::on_pushButton_3_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_HANDLE_REPORT;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_GAS_CONTINUE_TIME;
    WriteLog.desc = "set the gas meter's handle report to server";
    cjt188obj.value = "";

    BuiltLogFileExe();
}

/************************************
 * 读网络配置信息
 * *********************************/
void Widget::on_pushButton_4_clicked()
{
    ui->AppSevIPLE->clear();
    ui->AppSevPortLE->clear();
    ui->BackUpIPLE->clear();
    ui->BackUpSevPortLE->clear();
    ui->BandWidthLE->clear();
    ui->PLMN_LE->clear();
    ui->AvoidPeakAbleST->clear();
    ui->AvoidPeakTimeLE->clear();
    i = 0;
    Timer_B->start(MAX_TIMEOUT_READ);
}

void Widget::TTimeout_B()
{
    WriteLog.clear();
    cjt188obj.value="";
    switch(i)
    {
    //模组信息
    case 0:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_MODLE_INFORMATION;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_INFORMATION;
        WriteLog.desc = "get the gas meter's NB-iot modle information";
        BuiltLogFileExe();
        break;
    }
    //应用服务器
    case 1:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_APPLICATION_SERVER;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_APP_ADDR;
        WriteLog.desc = "get the gas meter's application server";
        BuiltLogFileExe();
        break;
    }
    //备份服务器
    case 2:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_BACKUP_SERVER;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_BACKUP_ADDR;
        WriteLog.desc = "get the gas meter's backup server";
        BuiltLogFileExe();
        break;
    }
    //频宽
    case 3:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_BAND_WIDTH;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_BAND;
        WriteLog.desc = "get the gas meter's NB-iot band width";
        BuiltLogFileExe();
        break;
    }
    //PLMN
    case 4:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_NBIOT_PLMN;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_PLMN;
        WriteLog.desc = "get the gas meter's NB-iot PLMN";
        BuiltLogFileExe();
        break;
    }
    //错峰
    case 5:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_NBIOT_AVOID_PEAK;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_AVOID_PEAK;
        WriteLog.desc = "get the gas meter's avoid peak config";
        BuiltLogFileExe();
        break;
    }
    default:
    {
        Timer_B->stop();
        i=0;
        return;
    }
    }
i++;
}

/***********************************
 * 设置应用服务器
 * ********************************/
void Widget::on_APPSevIPBTN_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_APPLICATION_SERVER;
    QString IPAddrApp = ui->AppSevIPLE->text();

    QString PortApp = ui->AppSevPortLE->text();
    QString IPAddrApp_out;
    QString PortApp_out;
    if(FAIL == IPtoString(IPAddrApp,&IPAddrApp_out))
    {
        QMessageBox::about(this,"提示","IP地址不正确");
        return;
    }
    if(FAIL == PORTtostring(PortApp,&PortApp_out))
    {
        QMessageBox::about(this,"提示","端口不正确");
        return;
    }
    QString ValueApp = IPAddrApp_out + PortApp_out;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_APP_ADDR;
    cjt188obj.value = ValueApp;
    WriteLog.desc = "set the gas meter's application address";
    BuiltLogFileExe();
}

/****************************************
 *设置备份服务器
 * *************************************/
void Widget::on_BACKSevIPBTN_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_BACKUP_SERVER;
    QString IPAddrApp = ui->BackUpIPLE->text();
    QString PortApp = ui->BackUpSevPortLE->text();
    QString IPAddrApp_out;
    QString PortApp_out;
    if(FAIL == IPtoString(IPAddrApp,&IPAddrApp_out))
    {
        QMessageBox::about(this,"提示","IP地址不正确");
        return;
    }
    if(FAIL == PORTtostring(PortApp,&PortApp_out))
    {
        QMessageBox::about(this,"提示","端口不正确");
        return;
    }
    QString ValueApp = IPAddrApp_out + PortApp_out;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_BACKUP_ADDR;
    cjt188obj.value = ValueApp;
    WriteLog.desc = "set the gas meter's backup address";
    BuiltLogFileExe();
}

/*************************************
 * 设置频宽
 * ***********************************/
void Widget::on_BandWidthBTN_clicked()
{
    WriteLog.clear();
    QString VValue = ui->BandWidthLE->text();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_BAND_WIDTH;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_BAND;
    QString ssReTs = QString("%1").arg(VValue.toInt(),2,16,QLatin1Char('0'));
    cjt188obj.value = ssReTs;
    WriteLog.desc = "set the gas meter's band width";

    BuiltLogFileExe();
}

void Widget::on_PLMN_BTN_clicked()
{
    WriteLog.clear();
    QString VValue = ui->PLMN_LE->text();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_PLMN;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_PLMN;
    QString ssReTs = QString("%1").arg(VValue.toInt(),8,16,QLatin1Char('0'));
    cjt188obj.value = ssReTs;
    WriteLog.desc = "set the gas meter's PLMN";

    BuiltLogFileExe();
}

/*****************************************
 * 使能关闭
 * ***************************************/
void Widget::on_AvoidPeakClouseBTN_clicked()
{
    WriteLog.clear();
    QString VValue = ui->AvoidPeakTimeLE->text();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_AVOID_PEAK_ENABLE;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_AVOID_PEAK;
    QString ssReTs = QString("%1").arg(VValue.toInt(),8,16,QLatin1Char('0'));
    cjt188obj.value = "00" + ssReTs;
    WriteLog.desc = "set the gas meter's avoid peak enable";

    BuiltLogFileExe();
}

/**********************************************
 * 使能打开
 * *******************************************/
void Widget::on_AvoidPeakOpenBTN_clicked()
{

    WriteLog.clear();
    QString VValue = ui->AvoidPeakTimeLE->text();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_AVOID_PEAK_ABLE;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_AVOID_PEAK;
    QString ssReTs = QString("%1").arg(VValue.toInt(),8,16,QLatin1Char('0'));
    cjt188obj.value = "01" + ssReTs;
    WriteLog.desc = "set the gas meter's avoid peak able";

    BuiltLogFileExe();
}

/*****************************************
 * 查看异常
 * **************************************/
void Widget::on_Check_Normal_BTN_clicked()
{

    WriteLog.clear();
    ui->AbnormalST->clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_CHECK_NORMAL_STATION;

    cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_ABNORMAL_STATION;
    cjt188obj.value = "";
    WriteLog.desc = "check the gas meter's abnormal station";
    BuiltLogFileExe();


}

/**************************************
 * 清除异常
 * ***********************************/
void Widget::on_Clear_NormalBTN_clicked()
{
    WriteLog.clear();
    ui->AbnormalST->clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_CLEAR_NORMAL_STATION;

    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CLEAR_ABNORMAL_STATION;
    cjt188obj.value = "";
    WriteLog.desc = "clear the gas meter's abnormal station";
    BuiltLogFileExe();
}

/**************************************
 * 余量设置
 * ***********************************/
void Widget::on_Balance_BTN_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_ALARM_FLOW;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_ALLOWANCE_SET;

    QString Value = ui->Alarm_Gas_LE->text();
    int LEN = Value.length();
    if(LEN!=8)
    {
        for(int i =0;i<8-LEN;i++)
        {
            Value.insert(0,"0");
        }
    }
    qDebug()<<Value;
    cjt188obj.value = Value;
    WriteLog.desc = "clear the gas meter's alarm allowance";
    BuiltLogFileExe();
}

/******************************************
 * 余额设置
 * **************************************/
void Widget::on_AlarmFlow_BTN_clicked()
{
    WriteLog.clear();
    cjt188obj.value.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_ALARM_BALANCE;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_BALANCE_SET;

    QString V_In =ui->Alarm_Bal_LE->text();
    //QString sV_In = QString("%1").arg(V_In.toLong(NULL,16));
    QString sV_In = QString("%1").arg(V_In.toInt(),8,16,QLatin1Char('0'));
    cjt188obj.value = sV_In.right(8);
    WriteLog.desc = "clear the gas meter's alarm balance";
    BuiltLogFileExe();
}

void Widget::on_pushButton_5_clicked()
{
    WriteLog.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_WRITE_WAKEUP_TIME;

    cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_WAKEUP_TIME;

    int Time_t = ui->Wakeup_time_LE->dateTime().toTime_t();
    QString V_In = QString("%1").arg(Time_t,8,16,QLatin1Char('0'));
    QString V_Out;
    BigToLittle(V_In,&V_Out);
    cjt188obj.value = V_Out;
    WriteLog.desc = "set the gas meter's wakeup time on factory modle";
    BuiltLogFileExe();
}




