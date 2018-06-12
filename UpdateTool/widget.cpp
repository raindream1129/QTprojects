#include <widget.h>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <vector>
#include <QSqlQuery>
#include "DBHelper.h"
#include "ui_widget.h"
#include <QTextCursor>
#include <windows.h>
#include "dbsjixx.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    iXUHAOO = 1;
    iSer = 0;
    fillPortsInfo();
    fillVersionInfo();
    meterCom = new QSerialPort(this);
    connect(meterCom, SIGNAL(readyRead()),
            this, SLOT(meterRecvData()));
    meterPollTimer = new QTimer();
    connect(meterPollTimer,SIGNAL(timeout()),this,SLOT(ResvTimeOut()));

}

Widget::~Widget()
{
    delete ui;
}

/***********************************
 * 打印操作日志
 * *********************************/
void Widget::logHandler(QString logString)
{
    QTextCursor cursor(ui->textLog->document());
    cursor.insertText(tr("%1  %2\n")
                      .arg(QTime::currentTime().toString("HH:mm:ss"))
                      .arg(logString));
}

/****************************************
 * CRC校验
 * *************************************/
quint8 Widget::AddCheckCode(quint16 *CRCBuff,int length)
{
    quint8 CRCData =0;
    for(int i =0;i<length;i++)
    {
        CRCData += *(CRCBuff+i);
    }
    CRCData = ~CRCData +1;
    return CRCData;
}

/*******************************
 * 版本号显示
 * *****************************/
void Widget::fillVersionInfo()
{
    QStringList list;
    QList<QString> Versions;
    UdaoImp *SoftVersions = new UdaoImp();
    Versions = SoftVersions->selectAllVersion();
    QList<QString>::Iterator iter;
    iter = Versions.begin();
    for(;iter!=Versions.end();iter++)
    {
        list<<*iter;
    }
    ui->VersionComb->addItems(list);
}

/**********************************
 * 判断重复加载
 * ********************************/
int Widget::JudgeReptation()
{
    TBL_BBNBXX stBBNXX_tmp;
    stBBNXX_tmp.setRJBBNH(Version);
    stBBNXX_tmp.setBEIZD1(Filename);
    UdaoImp *SoftVersions = new UdaoImp();
    int Num = SoftVersions->selectCountVersion(stBBNXX_tmp);
    if(Num>0)
    {
        QMessageBox::critical(this,"warning","此版本的文件已存在");
        logHandler("加载文件失败");
        return FAIL;
    }
    return SUCCESS;
}

/****************************************
 *  加载hex文件到数据库
 * *************************************/
void Widget::AddToBBBNBXX(vector<TBL_BBNBXX> stTBLs)
{
    UdaoImp *AddVersionData = new UdaoImp();
    vector<TBL_BBNBXX>::iterator it;
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("BEGIN");
    for(it=stTBLs.begin();it!=stTBLs.end();it++)
    {
        AddVersionData->inserterVersion(*it);
    }
    query.exec("COMMIT");
    helper->destoryConn();
}

/***********************************************
 * 登记升级进度表
 * ********************************************/
void Widget::InsertUpgrade(CJT188Obj stCJT188obj)
{
    TBL_BBSJIXX stBSJIXX;
    stBSJIXX.setYIBOBH(stCJT188obj.address);    //仪表编号
    stBSJIXX.setRJBBNH(versionDEV);             //版本号
    stBSJIXX.setSHJIJD(0);;                     //升级进度
    stBSJIXX.setSJKSDZ("0");                    //开始地址
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMdd");
    int timeT = current_date_time.toTime_t();   //将当前时间转为时间戳
    stBSJIXX.setSHIJCH(timeT);                  //时间戳
    stBSJIXX.setWEIHRQ(current_date);           //维护日期
    stBSJIXX.setSHJIZT("0");                    //升级状态
    stBSJIXX.setJILUZT("0");                    //记录状态
    stBSJIXX.setBEIZD1("");
    stBSJIXX.setBEIZD2("");
    stBSJIXX.setBEIZD3("");
    stBSJIXX.setBEIZD4("");

    UdaoImp *insertDEVUp = new UdaoImp();
    insertDEVUp->InsertDevice(stBSJIXX);
}

/**********************************************
 * 更新升级进度表
 * ********************************************/
void Widget::upBSHIXX(TBL_BBSJIXX stBSJIXX)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMdd");
    int timeT = current_date_time.toTime_t();   //将当前时间转为时间戳
    stBSJIXX.setSHIJCH(timeT);                  //时间戳
    stBSJIXX.setWEIHRQ(current_date);           //维护日期

    UdaoImp *UpBsjixx = new UdaoImp();
    UpBsjixx->UpdateDevice(stBSJIXX);
}

/****************************
 * 端口号
 * **************************/
void Widget::fillPortsInfo()
{
    ui->CBComMeter->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName();
        ui->CBComMeter->addItem(list.first(), list);
    }
}

/******************************
 * 读取串口设置
 * ****************************/
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

/*****************
    打开串口
******************/
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
            logHandler("读表串口已打开");
        }
        else
        {
            logHandler("读表串口: "+ meterCom->errorString());
        }
    }
}

/*****************************
 * 关闭串口
 * ***************************/
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

    logHandler("读表串口已关闭");
}

/**********************************
 * 串口连接按钮
 * ********************************/
void Widget::on_BtnConn_clicked()
{
    if(meterCom->isOpen())
    {
        meterComClose();
        ui->BtnConn->setText(tr("Connect"));
    }
    else
    {
        meterComOpen();
        ui->BtnConn->setText(tr("disconnect"));
    }

    meterRecvArr.clear();
    memset(meterSendBuff,0,sizeof(meterSendBuff));
    memset(meterRecvBuff,0,sizeof(meterRecvBuff));
}

/***********************************
 * 自定义波特率
 * *********************************/
void Widget::on_CBBaudMeter_currentTextChanged(const QString &arg1)
{
    if(ui->CBBaudMeter->currentText() == "custom")
    {
        ui->CBBaudMeter->setEditable(true);
        ui->CBBaudMeter->clearEditText();
    }
}

/*****************************************
 * 文件路径选择
 * **************************************/
void Widget::on_ChooseFlBtn_clicked()
{
    QString directory;
    directory.clear();
    if(dir.isEmpty())
        directory = QFileDialog::getOpenFileName(this, tr("Find Files"), QDir::currentPath());
    else
        directory = QFileDialog::getOpenFileName(this, tr("Find Files"),dir);
    dir = directory;
    if (!directory.isEmpty()) {
        ui->lineEFilePth->setText(directory);
        QStringList sections = directory.split(QRegExp("/"));
        Version =  sections.at(sections.size()-2);
        Filename = sections.at(sections.size()-1);
    }
}

/******************************************
 * 生成命令文本
 * ***************************************/
void Widget::SaveCMD(QStringList sStrList)
{
    QFile FileN("VerData.txt");
    if(FileN.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Truncate))
    {
        QTextStream in(&FileN);
        for(int i=0;i<sStrList.length();i++)
        {
            in<<sStrList.at(i)<<endl;
            qDebug()<<sStrList.at(i);
        }
    }
}


/***************************************
 * 加载hex文件到数据库
 * ************************************/
void Widget::on_LoadBtn_clicked()
{
    //判断加载的版本是否已经入库
    if(FAIL == JudgeReptation())
    {
        return;
    }
    iXUHAOO = 1;
    TBL_BBNBXX stBbnbxx;
    stBbnbxx.setRJBBNH(Version);//版本号
    QStringList ListOfCTAddr;
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMdd");
    int timeT = current_date_time.toTime_t();   //将当前时间转为时间戳
    stBbnbxx.setBANBRQ(current_date);//版本登记日期
    stBbnbxx.setBEIZD1(Filename);//文件名称
    stBbnbxx.setBEIZD2("");//备用字段
    stBbnbxx.setBEIZD3("");
    stBbnbxx.setBEIZD4("");
    stBbnbxx.setJILUZT("0");//记录状态
    stBbnbxx.setSHIJCH(timeT);//时间戳
    stBbnbxx.setZHAIYY("测试");
    QString Dir = ui->lineEFilePth->text();
    if(!Dir.endsWith("hex"))
    {
         QMessageBox::critical(this,"warning","加载的文件不是hex文件！");
         logHandler("加载的文件不是hex文件！");
         return;
    }
    QFile FileN(Dir);
    if(FileN.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString sDataBuff;
        sDataBuff.clear();
        QTextStream TextStm(&FileN);
        QStringList LineList;
        QString ValueOfContinuousAddr;
        ValueOfContinuousAddr.clear();
        QString sAddressOfSomeLineValue;
        QString LastLineValue;
        LastLineValue.clear();
        QString NextLineValue;
        NextLineValue.clear();
        QString sDataOfNextLine;
        sDataOfNextLine.clear();
        int iifContinuous = 0;
        int iifFirtLine = 1;
        LineList.clear();
        /*****************************
         ** 放入Qstringlist缓存中
         *****************************/
        QString Addr = "0000";
        while(!TextStm.atEnd())
        {
            QString sLineData = TextStm.readLine();

            bool ok;
            int32_t iTypeOfSomeLineValue = sLineData.mid(7,2).toInt(&ok,16) & 0xFF;
            if(iTypeOfSomeLineValue == 0x04)
            {
                Addr = sLineData.mid(9,4);
            }
            if(!iTypeOfSomeLineValue)
            {
                sLineData.insert(3,Addr);
                LineList.append(sLineData);
            }
        }

        /*****************************
         * 将连续地址的值归集
         * ***************************/
        for(int i=0;i<LineList.count()-1;i++)
        {
            QString sDataOfSomeLine;
            sDataOfSomeLine.clear();
            sAddressOfSomeLineValue.clear();
            LastLineValue.clear();
            NextLineValue.clear();

            sDataOfSomeLine = LineList.at(i);
            bool ok;
            int32_t iLengthOfSomeLineValue = sDataOfSomeLine.mid(1,2).toInt(&ok,16);//第一行数据长度
            sAddressOfSomeLineValue = sDataOfSomeLine.mid(3,8);                     //第一行开始地址
            int32_t iAddressOfSomeLine = sAddressOfSomeLineValue .toInt(&ok,16);    //第一行开始地址
            LastLineValue = sDataOfSomeLine.mid(13,iLengthOfSomeLineValue*2);       //第一行有效值
            //下一行
            sDataOfNextLine.clear();
            sDataOfNextLine = LineList.at(i+1);
            int32_t iLengthOfNextLineValue = sDataOfNextLine.mid(1,2).toInt(&ok,16);//下一行数据长度
            QString sAddressOfNextLineValue = sDataOfNextLine.mid(3,8);             //下一行开始地址
            int32_t iAddressOfNextLine = sAddressOfNextLineValue .toInt(&ok,16);    //地址
            NextLineValue = sDataOfNextLine.mid(13,iLengthOfNextLineValue*2);        //下一行数据
            if(iifFirtLine)
            {
                ValueOfContinuousAddr.append(sAddressOfSomeLineValue);
            }
            ValueOfContinuousAddr.append(LastLineValue);
            if(iAddressOfNextLine == iAddressOfSomeLine+iLengthOfSomeLineValue)
            {//地址连续
                //ValueOfContinuousAddr.append(LastLineValue);
                iifContinuous = 1;
                iifFirtLine = 0;
            }
            else{
                iifContinuous = 0;
                ListOfCTAddr.append(ValueOfContinuousAddr);
                ValueOfContinuousAddr.clear();
                iifFirtLine = 1;
            }
        }
        if(iifFirtLine)
        {
            ValueOfContinuousAddr.append(sAddressOfSomeLineValue);
        }
        ValueOfContinuousAddr.append(NextLineValue);
        ListOfCTAddr.append(ValueOfContinuousAddr);
    }else
    {
        QMessageBox::critical(this,"warning","加载文件失败");
        logHandler("加载文件失败");
    }

    /****************************
     *字节按128字节对齐
     * *************************/
    QString EffectValue;
    QStringList EffectiveValues;
    EffectValue.clear();
    EffectiveValues.clear();
    for(int i = 0;i<ListOfCTAddr.count();i++)
    {
        int32_t StartAddr = 0;
        QString LineData = ListOfCTAddr.at(i);
        QString AddrBegin = LineData.mid(0,8);
        bool ok;
        int32_t Addr = AddrBegin .toInt(&ok,16);
        QString DataBegin = LineData.mid(8,LineData.length()-8);
        if(Addr%128 != 0)
        {
            StartAddr = Addr/128*128;
            QString AddTmp = QString::number(StartAddr,16);
            if(AddTmp.length()<8)
            {
                for(int j = 0;j<8-AddTmp.length();j++)
                    AddTmp.insert(0,"0");
            }
            EffectValue.append(AddTmp);
            int m=0;
            for(m = 0;m<(Addr%128)*2;m++)
            {
                EffectValue.append("0");
            }
            EffectValue.append(DataBegin);
            EffectiveValues.append(EffectValue);
            EffectValue.clear();
        }
        else{
            QString Str;
            Str.clear();
            Str.append(AddrBegin);
            Str.append(DataBegin);
            EffectiveValues.append(Str);
        }
    }
    /******************************************
     * 每128字节存放一条记录
     * **************************************/
    QString OneRecord;
    OneRecord.clear();
    QStringList EffectiveDataList;
    EffectiveDataList.clear();
    for(int i = 0;i<EffectiveValues.count();i++)
    {
        OneRecord = EffectiveValues.at(i);
        QString AddressOne = OneRecord.mid(0,8);
        bool ok;
        int32_t Addr = AddressOne .toInt(&ok,16);
        int k = 8;
        do{
            QString Str;
            Str.clear();
            Str.append(AddressOne);
            Str.append(OneRecord.mid(k,256));
            EffectiveDataList.append(Str);
            Addr += 128;
            QString AddrAdd = QString::number(Addr,16);
            QString AddTemp;
            AddTemp.clear();
            if(AddrAdd.length()<8)
            {
                for(int j = 0;j<8-AddrAdd.length();j++)
                    AddTemp.append("0");
            }
            AddTemp.append(AddrAdd);
            AddressOne = AddTemp;
            k += 256;
        }while(k<OneRecord.length());
    }
    /*************************************
     * 登记版本信息表
     * ***********************************/
    vector<TBL_BBNBXX>stTBLs;
    for(int i =0;i<EffectiveDataList.count();i++)
    {
        QString DataBuff = EffectiveDataList.at(i);
        stBbnbxx.setDIZHIH(DataBuff.mid(0,8));
        stBbnbxx.setXUHAOO(iXUHAOO);
        QString LEN = QString::number(((DataBuff.length()-8)/2)+6,16);
        QString LEN_Tmp;
        LEN_Tmp.clear();
        if(LEN.length()<4)
        {
            for(int j = 0;j<4-LEN.length();j++)
                LEN_Tmp.append("0");
        }
        LEN_Tmp.append(LEN);
        stBbnbxx.setSHUJCD(LEN_Tmp);
        stBbnbxx.setSHJUNR(DataBuff.mid(8,DataBuff.length()-8));
        //追加校验码
        quint16 CheckBuff[256];
        bool ok;
        for(int k=0;k<DataBuff.length();k += 2)
        {
            quint16 CRCByte = DataBuff.mid(k,2).toInt(&ok,16);
            CheckBuff[k/2] = CRCByte;
        }
        quint8 CRCResult;
        CRCResult = AddCheckCode(CheckBuff,DataBuff.length()/2);
        //QString CRCR = QString::number(CRCResult,16);
        QString CRCR = "0000";
        stBbnbxx.setJIAOYM(CRCR);
        //装到vector
        stTBLs.push_back(stBbnbxx);
        iXUHAOO++;
    }
    //写入数据库
    AddToBBBNBXX(stTBLs);
    QMessageBox::about(this,tr("提示信息"),tr("文件加载成功"));
    logHandler("文件加载成功！");
    return;

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
    meterPollTimer->start(3000);
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
    char StrArray[512];
    memset(StrArray,0,sizeof(StrArray));
    strcpy(StrArray,strValue);
    while(*strValue && *strValue>='0' && *strValue<='9') strValue++;
    for(int i = 0;i<cjt188obj.value.length();)
    {
        memcpy(Str2Bit,&StrArray[i],2);
        QString str = "0x" + QString(QLatin1String(Str2Bit));
        quint16 Hex_t = str.toUInt(ok,0);
        meterSendBuff[meterSendBuffLen++] = Hex_t;
        i +=2;
    }
    //补写帧长
    meterSendBuff[12] = (len+3) & 0xFF;
    cs16 = Common::pGetCS16(meterSendBuff + 2, meterSendBuffLen - 2);
    //校验及尾部
    meterSendBuff[meterSendBuffLen++] = cs16 & 0xFF;
    meterSendBuff[meterSendBuffLen++] = CJT188_HDLC_TAIL;
    QString sCMD;
    sCMD.clear();
    for(int i =0;i<meterSendBuffLen;i++)
    {

        QString ssPeriod = QString("%1").arg(meterSendBuff[i],2,16,QLatin1Char('0'));
        sCMD += (ssPeriod + " ");
    }
    for(int i=0;i<sCMD.length();i++)
    {

        if(sCMD.at(i) >= 'a' && sCMD.at(i) <= 'z')
        {
            QString y = sCMD.at(i).toUpper();
            sCMD.replace(i, 1, y);
        }
    }
    logHandler("命令:"+sCMD);
    //下发数据
    meterComSend();
}

/******************************************
 * 数据接收超时
 * ****************************************/
void Widget::ResvTimeOut()
{
    meterPollTimer->stop();
    logHandler("数据接收超时!!!");
}

/*******************************************
 * 串口接收数据
 * *****************************************/
void Widget::meterRecvData()
{
    meterPollTimer->stop();
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

/*******************************
 * 接收数据处理
 * ****************************/
void Widget::meterCmdResponseHandler()
{
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
        meterRecvBuffLen = 0;
        logHandler("CS校验失败");
        return;
    }
    CJT188Obj cjt188Recv;
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
    cjt188Recv.dataId = meterRecvBuff[rxIdx++]<<8 & 0xFFFFFFFF;
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

    TBL_BBSJIXX stBSJIXX;//仪表版本升级进度
    stBSJIXX.clear();
    stBSJIXX.setSJKSDZ(AddrBegin);//升级开始地址

    UPData upgradeRecv;
    upgradeRecv.clear();
    upgradeRecv.Serios = cjt188Recv.value.mid(0,4);
    int addbegin = upgradeRecv.Serios.toInt();
    int Progre = (addbegin+1)*100/iSeriosUpAll;
    stBSJIXX.setSHJIJD(Progre);//升级进度
    stBSJIXX.setYIBOBH(cjt188Recv.address);//仪表编号

    bool ok;
    int len = cjt188Recv.value.mid(14,4).toInt(&ok,16)*2;
    upgradeRecv.Data = cjt188Recv.value.mid(18,len);
    switch(meterRoutine.task)
    {
    case TASK_CMD_SERVTODEV_VERSION_NUM:
    {//是否要升级
        meterRoutine.rsp = METER_RSP_OK;
//        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS
//                && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_CHECK_VERSION
//                && upgradeRecv.Data == "00")
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS
                    && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_CHECK_VERSION)
        {
            QString sVersion = versionDEV;
            bool ok;
            QString sVersion_Out = cjt188Recv.value;
            BigToLittle(cjt188Recv.value,&sVersion_Out);
            QString sVer = QString::number(sVersion_Out.mid(0,2).toInt())+"."+QString::number(sVersion_Out.mid(2,2).toInt());
            if(sVer ==  sVersion)
            {
                logHandler("固件为最新版本，无需升级");
                QMessageBox::about(this,tr("提示信息"),tr("固件为最新版本，无需升级"));
                return;
            }
            logHandler("固件版本不是最新,准备升级");
            IfGoOnUpdate = METER_RSP_GOONUPDATE;
            //登记仪表升级进度表
            InsertUpgrade(cjt188Recv);
            //发送升级数据包
            //SendUpdatePackage();
            ReadyUpgrade();
        }
        else{
            QMessageBox::warning(this,tr("警告"),tr("固件不允许升级,升级失败"));
            logHandler("升级失败");
            return;
        }
        break;
    }
    case TASK_CMD_SERVTODEV_READY_UPGRADE:
    {
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS)
        {
            logHandler("升级总包数成功,准备发送数据包");
            SendUpdatePackage();

        }else
        {
            QMessageBox::warning(this,tr("警告"),tr("固件不允许升级,升级失败(发送总包数失败)"));
            logHandler("升级失败");
            return;
        }
        break;
    }
    case TASK_CMD_SERVTODEV_DATA_PACK:
    {//升级数据
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS
                && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_UPDATING_PAG)
        {//允许升级
            IfGoOnUpdate = METER_RSP_GOONUPDATE;
            //更新一台设备升级进度表
            upBSHIXX(stBSJIXX);

            SendUpdatePackage();
        }
        else{
            IfGoOnUpdate = METER_RSP_NOTGOONUPDATE;
            logHandler("升级中断,请检查");
            //不允许升级
        }
        break;
    }
    case TASK_CMD_SERVTODEV_CHANGE_VERSION:
    {//切换版本后主动上报
        meterRoutine.rsp = METER_RSP_OK;
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS
                && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_REGISTER)
        {
            if(Version == cjt188Recv.value.right(6).left(2))
            {
                //升级成功
                QMessageBox::about(this,tr("提示信息"),tr("升级成功"));
                logHandler("升级成功");

            }
        }
        else{
            QMessageBox::warning(this,tr("警告"),tr("升级失败"));
            logHandler("升级失败");
            //注册失败
        }
        break;
    }
    case TASK_CMD_SERVTODEV_HANDLE_UPGRADE:
    {//手动发送某一行数据
        if(cjt188Recv.ctrlId == CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS && cjt188Recv.dataId == CJT188_FIO_OBJ_ID_UPDATING_PAG)
        {
            logHandler("单行数据写入成功");
        }
        break;
    }
    case TASK_CMD_SERVTODEV_READ_VERSION:
    {//校验版本
        bool ok;
        QString Ver = QString::number(("0x"+cjt188Recv.value.mid(2,2)).toInt(&ok,0)) + "." + QString::number(("0x"+cjt188Recv.value.mid(0,2)).toInt(&ok,0));
        ui->LNEVer->setText(Ver);
        if(Ver == ui->VersionComb->currentText())
        {
            QMessageBox::about(this,"提示","固件版本为最新版本,无需升级");
        }
        else
        {
            QMessageBox::about(this,"提示","固件版本有更新");
        }
        break;
    }
    default:
        break;
    }
}

/******************************************
 *开始升级--版本校验
 * ***************************************/
void Widget::on_UpdatingBtn_clicked()
{
    cjt188obj.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_CMD_SERVTODEV_VERSION_NUM;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CHECK_VERSION;//先校验版本
    versionDEV = ui->VersionComb->currentText();
    QString vers = versionDEV;
    //cjt188obj.value = vers.remove(".").insert(0,"0");
    cjt188obj.value = "";
    TBL_BBNBXX stBBNBXX;
    stBBNBXX.setRJBBNH(versionDEV);
    versionDEV = vers;
    UdaoImp *SelVersionData = new UdaoImp();
    vBBNBXXs = SelVersionData->selectAllDateOfSmVersion(stBBNBXX);
    iSeriosUpAll = vBBNBXXs.size();
    it = vBBNBXXs.begin();
    logHandler("版本校验");
    CmdExecution();
}

/******************************
 * 升级准备
 * ***************************/
void Widget::ReadyUpgrade()
{
    cjt188obj.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_CMD_SERVTODEV_READY_UPGRADE;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_UPDATING_READY;//准备升级
    int iNumOfSer = iSeriosUpAll;
    QString sNum = QString("%1").arg(iNumOfSer,4,16,QLatin1Char('0'));
    QString sNum_Out;
    BigToLittle(sNum,&sNum_Out);
    cjt188obj.value = sNum_Out;
    logHandler("准备升级");
    CmdExecution();
}

/******************************
 * 允许升级后发送数据包
 * ****************************/
void Widget::SendUpdatePackage()
{
    cjt188obj.clear();
    if(meterRoutine.rsp == METER_RSP_OK && IfGoOnUpdate == METER_RSP_GOONUPDATE)
    {
        meterRoutine.errCount = 0;
        meterRoutine.rsp = METER_RSP_NONE;
        meterRoutine.task = TASK_CMD_SERVTODEV_DATA_PACK;
        //cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RESPONSE;
        cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
        cjt188obj.dataId = CJT188_FIO_OBJ_ID_UPDATING_PAG;
        QString Values;
        Values.clear();

        UPData DataPack;
        DataPack.clear();
        //序号
        if(it != vBBNBXXs.end())
        {
            QString SER = QString::number(it->getXUHAOO(),16);
            int lengofSER = SER.length();
            if(lengofSER<4)
            {
                for(int i = 0;i<4-lengofSER;i++)
                {
                    SER.insert(0,"0");
                }
            }
            DataPack.Serios = SER;
            DataPack.Type = UPGRADE_MCU_IN;
            DataPack.Address = it->getDIZHIH();
            AddrBegin = DataPack.Address;//更新升级进度表
            DataPack.Length = it->getSHUJCD();
            DataPack.Data = it->getSHJUNR();
            DataPack.CRCheck = it->getJIAOYM();
            Values = DataPack.Values();
            cjt188obj.value = Values;
            //校验(暂不考虑)
            //cjt188obj.value.append("0000");
        }
        else{
            //发送切换指令
            ChangeVersion();
            return;
        }
        it++;
    }
    CmdExecution();
}

/**************************************
 * 发送切换版本指令
 * ************************************/
void Widget::ChangeVersion()
{
    cjt188obj.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_CMD_SERVTODEV_CHANGE_VERSION;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RESPONSE;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CHANGE_TO_NEW_VERSION;
    cjt188obj.value = "01";
    CmdExecution();
}
//双击某一行,手动发送
void Widget::on_listWidget_doubleClicked(const QModelIndex &index)
{
    cjt188obj.clear();
    meterRoutine.task = TASK_CMD_SERVTODEV_HANDLE_UPGRADE;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_UPDATING_PAG;
    QString sValue = ui->listWidget->item(index.row())->text();
    QString sSer;
    BigToLittle(sValue.mid(0,4),&sSer);
    QString sLen;
    BigToLittle(sValue.mid(4,4),&sLen);
    cjt188obj.value = sSer + sLen + sValue.mid(8,sValue.length()-8);


    logHandler(tr("第%1行数据已下发,数据包序号:[%2]").arg(QString::number(index.row() + 1))
                                                 .arg(ui->listWidget->item(index.row())->text().mid(0,4)));
    CmdExecution();

}

void Widget::on_VersionComb_currentTextChanged(const QString &arg1)
{
    QString CurrentVer = ui->VersionComb->currentText();
    TBL_BBNBXX stBBNBXX;
    stBBNBXX.setRJBBNH(CurrentVer);
    UdaoImp *SelVersionData = new UdaoImp();
    vector<TBL_BBNBXX> vBBNBXXsTmp;
    vBBNBXXsTmp = SelVersionData->selectAllDateOfSmVersion(stBBNBXX);
    vector<TBL_BBNBXX>::iterator itTmp;
    itTmp = vBBNBXXsTmp.begin();
    QStringList sString;
    sString.clear();
    for(;itTmp!=vBBNBXXsTmp.end();itTmp++)
    {
        QStringList strList;
        QString ser = QString("%1").arg(itTmp->getXUHAOO(),4,16,QLatin1Char('0'));
        //strList<<ser + itTmp->getDIZHIH() + itTmp->getSHUJCD() + itTmp->getSHJUNR() + itTmp->getJIAOYM();
        bool ok;
        int iLEN = ("0x" + itTmp->getSHUJCD()).toInt(&ok,0);
        QString sLEN = QString("%1").arg(iLEN,4,16,QLatin1Char('0'));

        QString sStr = ser + sLEN + itTmp->getDIZHIH() + itTmp->getSHJUNR() + itTmp->getJIAOYM();
        for(int i=0;i<sStr.length();i++)
        {
            if(sStr.at(i)>='a' && sStr.at(i)<='z')
            {
                QString ss = QString(sStr.at(i).toUpper());
                sStr.replace(i,1,ss);
            }
        }

        strList<<sStr;
        ui->listWidget->addItems(strList);
        sString.append(strList);
    }
    SaveCMD(sString);


}

//版本比较
void Widget::on_VerCheckBTN_clicked()
{
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_CMD_SERVTODEV_READ_VERSION;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CHECK_VERSION;
    cjt188obj.value = "";

    CmdExecution();
}

//运行新固件
void Widget::on_RunNewVerBTN_clicked()
{
    cjt188obj.clear();
    meterRoutine.errCount = 0;
    meterRoutine.rsp = METER_RSP_NONE;
    meterRoutine.task = TASK_CMD_SERVTODEV_CHANGE_VERSION;
    cjt188obj.ctrlId = CJT188_FIO_CTRL_ID_RESPONSE;
    cjt188obj.dataId = CJT188_FIO_OBJ_ID_CHANGE_TO_NEW_VERSION;
    cjt188obj.value = "01";
    CmdExecution();
}
