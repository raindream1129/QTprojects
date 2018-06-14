#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "dialog.h"
#include "totalizer.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->hide();
    ui->pushButton_2->hide();
    fillPortsInfo();

    meterRecvBuffLen = 0;
    meterSendBuffLen = 0;
    meterComInfo.clear();
    meterRoutine.clear();
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    memset(meterSendBuff, 0, sizeof(meterSendBuff));

    meterCom = new QSerialPort(this);
    connect(meterCom, SIGNAL(readyRead()),
            this, SLOT(meterRecvData()));

    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),
            this, SLOT(TTimeout()));
    TimerA = new QTimer(this);
    connect(TimerA, SIGNAL(timeout()),
            this, SLOT(TATimeout()));
    TimerB = new QTimer(this);
    connect(TimerB, SIGNAL(timeout()),
            this, SLOT(TBTimeout()));
    TimerC = new QTimer(this);
    connect(TimerC, SIGNAL(timeout()),
            this, SLOT(TCTimeout()));
    TimerD = new QTimer(this);
    connect(TimerD, SIGNAL(timeout()),
            this, SLOT(TCTimeout()));

    i = 0;
    j=0;
    iTimesReport = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::logHandler(QString logString)
{
    QTextCursor cursor(ui->txtLog->document());
    cursor.insertText(tr("%1 %2\n")
                      .arg(QTime::currentTime().toString("HH:mm:ss.zzz"))
                      .arg(logString));
}
void MainWindow::TATimeout()
{
    TimerA->stop();
    TimerC->start(10000);
    //Timer->start(MAX_TIMEOUT_READ);
}
void MainWindow::TBTimeout()
{
    switch(j)
    {
    case 0:
    {
        //电压阈值
        cjt188obj.value.clear();
        QString VValue = "4800";
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_VOLTAGE_TH;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_BATT_THRESHOLD;
        QString ssReTs = QString("%1").arg(VValue.toInt(),2,16,QLatin1Char('0'));
        BigToLittle(ssReTs,&cjt188obj.value);
        CMDSend();
        break;
    }
    case 1:
    {
        //余量
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_ALARM_FLOW;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_ALLOWANCE_SET;

        QString Value = "0";
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
        CMDSend();
        break;
    }
    case 2:
    {
        //报警余额
        cjt188obj.value.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_ALARM_BALANCE;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_ALARM_BANLANCE;

        QString V_In = "0";
        //QString sV_In = QString("%1").arg(V_In.toLong(NULL,16));
        QString sV_In = QString("%1").arg(V_In.toInt(),8,16,QLatin1Char('0'));
        cjt188obj.value = sV_In.right(8);
        CMDSend();
    }
    default:
    {
        logHandler("已恢复出厂参数");
        j=0;
        TimerB->stop();
        Timer->start(MAX_TIMEOUT_READ);
    }

    }
    j++;
}
void MainWindow::TCTimeout()
{
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_READ_PORT_STATE;

    cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_REPORT_STATE;
    ////WriteLog.desc = "get the gas meter's handle report state to server";
    cjt188obj.value = "";
    CMDSend();
}
void MainWindow::TDTimeout()
{
    QMessageBox::warning(this,"提示","上报失败");
    StopAll();
}
int MainWindow::Support()
{
    return ui->SupportCB->currentIndex();
}

void MainWindow::Rest()
{
    TimerB->start(1000);
}

/****************
 * 自动获取串口号
 * **************/
void MainWindow::fillPortsInfo()
{
    ui->Port_box->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName();
        ui->Port_box->addItem(list.first(), list);
    }
}

/*************************
 * 获取串口设置
 * *************************/
void MainWindow::loadComSettings()
{
    if(!ui->Port_box->currentText().isEmpty())
    {
        meterComInfo.ComPortName  = ui->Port_box->currentText();
        meterComInfo.ComBaudStr   = "9600";
        meterComInfo.ComBaud      = Common::GetBaudrate(meterComInfo.ComBaudStr);
        meterComInfo.ComParityStr = "8";
        meterComInfo.ComParity    = Common::GetParity(meterComInfo.ComParityStr);
        meterComInfo.ComDataBitsStr = "NONE";
        meterComInfo.ComDataBits  = Common::GetDataBits(meterComInfo.ComDataBitsStr);
        meterComInfo.ComStopBits  = Common::GetStopBits(1);
    }
}

/*************************
 * 打开串口
 * *************************/
void MainWindow::meterComOpen()
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
            //logHandler("串口已打开");
        }
        else
        {
            //logHandler("读串口: "+ meterCom->errorString());
            QMessageBox::warning(this,"提示","串口打开失败");
            return;
        }
    }
}

/*******************************
 * 关闭串口
 * *****************************/
void MainWindow::meterComClose()
{
    if(meterCom->isOpen())
        meterCom->close();

    meterRecvBuffLen = 0;
    meterSendBuffLen = 0;
    meterComInfo.clear();
    meterRoutine.clear();
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    memset(meterSendBuff, 0, sizeof(meterSendBuff));

    //logHandler("串口已关闭");
}

/************************************
 * 连接串口
 * *********************************/
void MainWindow::on_Open_Port_clicked()
{
    meterComOpen();
    if(meterCom->isOpen())
    {
        ui->Open_Port->setEnabled(false);
        ui->Close_Port->setEnabled(true);
    }
    meterRecvArr.clear();
    memset(meterSendBuff,0,sizeof(meterSendBuff));
    memset(meterRecvBuff,0,sizeof(meterRecvBuff));

}

/************************************
 * 关闭串口
 * *********************************/
void MainWindow::on_Close_Port_clicked()
{
    meterComClose();
    if(!meterCom->isOpen())
    {
        ui->Close_Port->setEnabled(false);
        ui->Open_Port->setEnabled(true);
    }
    meterRecvArr.clear();
    memset(meterSendBuff,0,sizeof(meterSendBuff));
    memset(meterRecvBuff,0,sizeof(meterRecvBuff));

}
/******************************
 * 串口发送数据
 * ***************************/
void MainWindow::meterComSend()
{

    meterRoutine.rsp = METER_RSP_NONE;
    meterRecvArr.clear();
    if(meterCom->isOpen())
    {
        meterCom->write((char *)meterSendBuff, meterSendBuffLen);
    }
}

/*******************************************
 * 串口接收数据
 * *****************************************/
void MainWindow::meterRecvData()
{
    //meterPollTimer->stop();
    if(meterCom->bytesAvailable())
    {
        meterRecvArr += meterCom->readAll();
        if( meterRecvArr.startsWith(0x68) && meterRecvArr.endsWith(0x16))
        {
            meterRecvBuffLen = meterRecvArr.length();
            memcpy(meterRecvBuff, meterRecvArr, meterRecvBuffLen);
            meterCmdResponseHandler();
        }
    }
}

void MainWindow::CMDSend()
{
    quint8 len = 0;
    quint16 cs16 = 0;
    meterSendBuffLen = 0;
    meterRoutine.errCount = 0;
    memset(meterSendBuff, 0, sizeof(meterSendBuff));
    memset(meterRecvBuff, 0, sizeof(meterRecvBuff));
    ////WriteLog.TRFlag = Log_WRITE_DIRECTION;
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

    for(int i=0;i<cjt188obj.value.length();i+=2)
    {
        QString Str1Bit = cjt188obj.value.mid(i,2);
        int str_out = ("0x" + Str1Bit).toInt(NULL,0);
        meterSendBuff[meterSendBuffLen++] = str_out;
//        QString ssTimeOut = QString("%1").arg(iTimeOut,4,16,QLatin1Char('0'));
    }
    meterSendBuff[12] = (len+3) & 0xFF;
    cs16 = Common::pGetCS16(meterSendBuff + 2, meterSendBuffLen - 2);
    //校验及尾部
    meterSendBuff[meterSendBuffLen++] = cs16 & 0xFF;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_TAIL;
    //下发数据
    if(!meterCom->isOpen())
        meterComOpen();
    meterComSend();

}

void MainWindow::meterCmdResponseHandler()
{
    ////WriteLog.clear();
    //接收数据长度初验
    if(meterRecvBuffLen < 4)
    {
        //logHandler("接收长度错误");
    }
    //CS校验
    quint16 cs16;
    cs16 = Common::pGetCS16(meterRecvBuff, meterRecvBuffLen - 2);
    if (((cs16 & 0xFF) != meterRecvBuff[meterRecvBuffLen - 2]) &&
        (0x16 == meterRecvBuff[meterRecvBuffLen - 1]))
    {
        //logHandler("CS校验错误");
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
    //读计量数据
    case TASK_READ_METROLOGICAL_DATA:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if((cjt188Recv.ctrlId == CJT188_CTRL_ID_RD_DATA_RETURN_SUCCESS))
        {
            ////WriteLog.Result = "success";

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

//            ui->Device_timeLE->setText(Time_Now);
            ui->AllFlowLE->setText("累积量" + Totol_flow);
            logHandler("[成功]读取计量数据成功...");

            totalizer *total = new totalizer();
            if(total->exec() == QDialog::Accepted)
            {
                i = 0;
                Timer->start(MAX_TIMEOUT_READ);
            }
            else{
                TotalizerIsOk = false;
                return;
            }

        }
        else
        {
            ////WriteLog.Result = "fail";
            logHandler("[失败]读取计量数据失败...");
            StopAll();
            QMessageBox::warning(this,"提示","读取计量数据失败");
            return;
        }

        break;
    }
    //写表号
    case TASK_WRITE_LDN:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == 0x95)// && cjt188Recv.address == ui->LetSn->text())
        {
            qDebug()<<"写表号成功";
//            //WriteLog.Result = "success";
            logHandler(tr("[成功]LDN编号%1设置成功")
                       .arg(cjt188Recv.address));
        }
        else
        {
//            //WriteLog.Result = "fail";
            logHandler(tr("[失败]LDN编号%1设置失败")
                      .arg(cjt188Recv.address));
            StopAll();
            QMessageBox::warning(this,"提示","LDN编号设置失败");
            return;
        }

        break;
    }
    //开阀
    case TASK_WRITE_OPEN_VALVE:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS ||cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("开阀成功");
        }
        else
        {
//            //WriteLog.Result = "fail";
            logHandler("开阀失败");
            StopAll();
            QMessageBox::warning(this,"提示","开阀失败");
            return;
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //关阀
    case TASK_WRITE_CLOSE_VALVE:
    {
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS ||cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("关阀成功");

        }
        else
        {
//            //WriteLog.Result = "fail";
            logHandler("关阀失败");
            StopAll();
            QMessageBox::warning(this,"提示","关阀失败");
            return;
        }
        meterRoutine.rsp = METER_RSP_OK;
        break;
    }
    //手动上报
    case TASK_WRITE_HANDLE_REPORT:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("手动上报命令成功");
            //Rest();
            TimerD->start(90000);
            TimerA->start(20000);
        }
        else{
//            //WriteLog.Result = "fail";
            logHandler("手动上报命令失败");
            StopAll();
            QMessageBox::warning(this,"提示","手动上报命令失败");
            return;
        }
        break;
    }
    //读上报状态
    case TASK_READ_PORT_STATE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS)
        {

            if(cjt188Recv.value == "01")
            {
                iTimesReport = 0;
                TimerC->stop();
                TimerD->stop();
                i++;
                Rest();
                //Timer->start(MAX_TIMEOUT_READ);
                logHandler("上报成功");
            }
            else if(cjt188Recv.value == "00")
            {

                logHandler("正在上报");
//                if(iTimesReport == 0)
//                    Sleep(15000);
//                else if(iTimesReport == 1)
//                    Sleep(30000);
//                else{
//                    iTimesReport = 0;
//                    StopAll();
//                    QMessageBox::warning(this,"提示","上报失败");
//                    return;
//                }
//                i--;
//                iTimesReport++;
            }
            else{
                logHandler("上报失败");
                StopAll();
                QMessageBox::warning(this,"提示","上报失败");
                return;
            }
//            //WriteLog.Result = "success";
//            logHandler("设置应用服务器成功");
        }
        else{
//            //WriteLog.Result = "fail";
//            logHandler("上报状态读取失败");
        }


        break;
    }
    //设置应用服务器
    case TASK_WRITE_APPLICATION_SERVER:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("设置应用服务器成功");
        }
        else{
//            //WriteLog.Result = "fail";
            logHandler("设置应用服务器失败");
            StopAll();
            QMessageBox::warning(this,"提示","设置应用服务器失败");
            return;
        }
        break;
    }
    //设置备份服务器
    case TASK_WRITE_BACKUP_SERVER:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
//            logHandler("设置备份服务器成功");
        }
        else{
//            //WriteLog.Result = "fail";
//            logHandler("设置备份服务器失败");
        }
        break;
    }
    //设置频宽
    case TASK_WRITE_BAND_WIDTH:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("设置频宽成功");
        }
        else{
//            //WriteLog.Result = "fail";
           logHandler("设置频宽失败");
           StopAll();
           QMessageBox::warning(this,"提示","设置频宽失败");
           return;
        }
        break;
    }
    //设置PLMN
    case TASK_WRITE_PLMN:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
       {
//            //WriteLog.Result = "success";
            logHandler("设置PLMN成功");

        }
        else{
//            //WriteLog.Result = "fail";
            logHandler("设置PLMN失败");
            StopAll();
            QMessageBox::warning(this,"提示","设置PLMN失败");
            return;

        }
        break;

    }

//清除异常
    case TASK_READ_CLEAR_NORMAL_STATION:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
//            //WriteLog.Result = "success";
            logHandler("清除异常成功");

        }
        else{
//            //WriteLog.Result = "fail";
            logHandler("清除异常失败");
            StopAll();
            QMessageBox::warning(this,"提示","清除异常失败");
            return;

        }
        break;
    }
    case TASK_WRITE_VOLTAGE_TH:
    {
        qDebug()<<cjt188Recv.ctrlId;
        if(cjt188Recv.ctrlId == CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS)
        {
            //logHandler("写电压阈值成功");
        }else{
            //logHandler("写电压阈值失败");
        }
        break;
    }
    case TASK_WRITE_CHARGE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            //WriteLog.Result = "success";
            //logHandler("设置余额成功");
        }
        else{
            //WriteLog.Result = "fail";
            //logHandler("设置余额失败");
        }
        break;
    }
    case TASK_WRITE_ALARM_FLOW:
    {

        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            //WriteLog.Result = "success";
            //logHandler("报警余量成功");
        }
        else{
            //WriteLog.Result = "fail";
            //logHandler("报警余量失败");
        }
        break;
    }
    case TASK_WRITE_ALARM_BALANCE:
    {
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            //WriteLog.Result = "success";
            //logHandler("设置警示额度成功");
        }
        else{
            //WriteLog.Result = "fail";
            //logHandler("设置警示额度失败");
        }
        break;
    }
    default:
        break;
    }


}




/*******************************************
 * 一键测试
 * *****************************************/
void MainWindow::on_pushButton_clicked()
{
    StartAll();
}

void MainWindow::StartAll(){

    ui->txtLog->clear();
    if(ui->LDN_LE->text().length() != 14)
    {
        QMessageBox::warning(this,"提示","仪表编号不正确");
        return;
    }
    Dialog *Display = new Dialog();
    Display->show();

    if(Display->exec() == Dialog::Accepted)
    {
        ////WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_METROLOGICAL_DATA;
        cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_OBJ_ID_RD_METROLOGICAL_DATA;
        ////WriteLog.desc = "get gas meter's metrological data";
        CMDSend();
    }
    else{
        qDebug()<<"display wrong!";
        return;
    }
}

void MainWindow::TTimeout()
{
    qDebug()<<i;
    switch (i)
    {
    case 0:
    {
        //开阀
       meterRoutine.errCount = 0;
       meterRoutine.rsp = METER_RSP_NONE;
       meterRoutine.task = TASK_WRITE_OPEN_VALVE;
       cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
       cjt188obj.dataId = CJT188_OBJ_ID_WR_VALVE_CTROL;
       cjt188obj.value = "00";
       ////WriteLog.desc = "open the gas meter's valve";

       CMDSend();
       break;
    }
    case 1:
    {
        //关阀
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_CLOSE_VALVE;
        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_OBJ_ID_WR_VALVE_CTROL;
        cjt188obj.value = "01";
        ////WriteLog.desc = "close the gas meter's valve";

        CMDSend();
        break;
    }
    case 2:
    {
        //开阀
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_OPEN_VALVE;
        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_OBJ_ID_WR_VALVE_CTROL;
        cjt188obj.value = "00";
        ////WriteLog.desc = "open the gas meter's valve";

        CMDSend();
        break;
    }
    case 3:
    {
        //写IP
        ////WriteLog.clear();
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_APPLICATION_SERVER;
        QString IPAddrApp = ui->Test_IP->text();

        QString PortApp = ui->Test_Port->text();
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
        ////WriteLog.desc = "set the gas meter's application address";

        CMDSend();
        break;
    }
    case 4:
    {
        //写band
        ////WriteLog.clear();
        QString VValue;
        VValue.clear();
        int Supp = Support();
        if(0 == Supp || 1 == Supp)
        {
            VValue = "8";
        }
        else if(2 == Supp)
        {
            VValue = "5";
        }
        else{
            QMessageBox::about(this,"提示","band");
            return;
        }
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_BAND_WIDTH;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_BAND;
        QString ssReTs = QString("%1").arg(VValue.toInt(),2,16,QLatin1Char('0'));
        cjt188obj.value = ssReTs;
        ////WriteLog.desc = "set the gas meter's band width";

        CMDSend();
        break;
    }
    case 5:
    {
        //写PLMN
        ////WriteLog.clear();
        QString VValue;
        VValue.clear();
        int Supp = Support();
        if(0 == Supp)
        {
            VValue = "46000";
        }
        else if(1 == Supp)
        {
            VValue = "46001";
        }
        else if(2 == Supp)
        {
            VValue = "46011";
        }else
        {
            QMessageBox::about(this,"提示","PLMN");
            return;
        }

        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_PLMN;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_NB_IOT_PLMN;
        QString ssReTs = QString("%1").arg(VValue.toInt(),8,16,QLatin1Char('0'));
        BigToLittle(ssReTs,&cjt188obj.value);
        CMDSend();
        break;
    }
    case 6:
    {
        //上报
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_HANDLE_REPORT;

        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_GAS_CONTINUE_TIME;
        ////WriteLog.desc = "set the gas meter's handle report to server";
        cjt188obj.value = "";
        CMDSend();
        Timer->stop();
        break;
    }
    case 7:
    {
        //上报状态
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_PORT_STATE;

        cjt188obj.ctrlId = CJT188_CTRL_ID_RD_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_REPORT_STATE;
        ////WriteLog.desc = "get the gas meter's handle report state to server";
        cjt188obj.value = "";
        CMDSend();
        break;
    }
    case 8:
    {
        //配置表号
        meterRoutine.errCount = 0;
        ////WriteLog.clear();
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_LDN;
        cjt188obj.ctrlId = CJT188_CTRL_ID_WR_ADDR;
        cjt188obj.dataId = CJT188_OBJ_ID_WR_ADDR;
        QString No = ui->LDN_LE->text();
        if(No.length() != 14)
        {
            //logHandler("表号长度错误");
            QMessageBox::warning(this,"提示","LDN长度错误");
            return;
        }
        cjt188obj.value = No;
//        for(int i=No.length()-1;i>=0;)
//        {
//            cjt188obj.value = cjt188obj.value + No.mid(i-1,2);
//            i -= 2;
//        }

        ////WriteLog.desc = "set gas meter's LDN";
        CMDSend();
        break;
    }
    case 9:
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_WRITE_APPLICATION_SERVER;
        QString IPAddrApp = ui->APP_IP->text();

        QString PortApp = ui->APP_Port->text();
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
        ////WriteLog.desc = "set the gas meter's application address";

        CMDSend();
        break;
    }
    case 10:
    {
        ////WriteLog.clear();

        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_READ_CLEAR_NORMAL_STATION;

        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_CLEAR_ABNORMAL_STATION;
        cjt188obj.value = "";
        ////WriteLog.desc = "clear the gas meter's abnormal station";
        CMDSend();
        break;
    }
    default:
    {

       StopAll();
        QMessageBox::about(this,"提示","测试完成");
        return;
    }
    }

   i++;
}

void MainWindow::on_pushButton_2_clicked()
{
    StopAll();
}
void MainWindow::StopAll()
{
    Timer->stop();
    TimerC->stop();
    i = 0;
    j=0;
    TotalizerIsOk=0;
    ui->LDN_LE->clear();
    ui->LDN_LE->setFocus();
    ui->AllFlowLE->setText("累积量");
}

void MainWindow::on_LDN_LE_returnPressed()
{
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    StartAll();
}
