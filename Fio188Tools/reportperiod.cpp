#include "reportperiod.h"
#include "ui_reportperiod.h"
#include <QDebug>
#include "cjt188_fio.h"
#include "cjt188_general.h"
#include <QMessageBox>
#include <QTimer>
#include <windows.h>
#include "common.h"

ReportPeriod::ReportPeriod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportPeriod)
{
    ui->setupUi(this);

    Timer = new QTimer(this);

    i = 0;
}

ReportPeriod::~ReportPeriod()
{
    delete ui;
}

//读取上报周期对应参数
void ReportPeriod::ReadRPPd(quint32 dataID,QString value)
{
    switch(dataID)
    {
    //读网络上报参数
    case CJT188_FIO_OBJ_ID_NET_PUSH:
    {
        QDateTime time;
        QString sStartT;
        BigToLittle(value.mid(0,8),&sStartT);
        sStartT = "0x" + sStartT;
        bool ok;
        int StartT = sStartT.toInt(&ok,0)-8*60*60;

        time = QDateTime::fromTime_t(StartT);
        //ui->StartRpTime->setDateTime(time);//开始时间

        QString UploadCycle;//上传周期
        BigToLittle(value.mid(8,4),&UploadCycle);
        UploadCycle = "0x" + UploadCycle;
        UploadCycle = QString::number(UploadCycle.toInt(&ok,0));
        //ui->lineEPushCyc->setText(QString::number(UploadCycle.toInt()));

        QString Uploadtimeout;//上传超时
        BigToLittle(value.mid(12,4),&Uploadtimeout);
        Uploadtimeout = "0x" + Uploadtimeout;
        Uploadtimeout = QString::number(Uploadtimeout.toInt(&ok,0));
        //ui->lineEUploadTout->setText(QString::number(Uploadtimeout.toInt()));

        QString ReTimes;//重传次数
        ReTimes = QString::number(("0x" + value.mid(16,2)).toInt(&ok,0));
        //ui->lineReT->setText(QString::number(ReTimes.toInt()));

        if(value.length() > 0)
        {
            ui->StartRpTime->setDateTime(time);//开始时间
            ui->lineEPushCyc->setText(UploadCycle);
            ui->lineEUploadTout->setText(Uploadtimeout);
            ui->lineReT->setText(ReTimes);
        }else{
            ui->lineEPushCyc->setText("0");
            ui->lineEUploadTout->setText("0");
            ui->lineReT->setText("0");
        }
        break;
    }
    //读累加器采样参数
    case CJT188_FIO_OBJ_ID_CUMULATIVE_SAMP:
    {
        QString UploadCycle;//上传周期
        BigToLittle_Int(value.mid(0,4),&UploadCycle);
        ui->lineERdCycle->setText(UploadCycle);
//        QString Uploadtimeout;//上传超时
//        Uploadtimeout = value.mid(4,4);
//        ui->lineERdTOut->setText(QString::number(Uploadtimeout.toInt()));
//        QString ReTimes;//重传次数
//        ReTimes = value.mid(8,2);
//        ui->lineReT_ACC->setText(QString::number(ReTimes.toInt()));
        break;
    }
    //读温度采样参数
//    case CJT188_FIO_OBJ_ID_TEMP_SAMP:
//    {
//        QString UploadCycle;//上传周期
//        BigToLittle_Int(value.mid(0,4),&UploadCycle);
//        //ui->lineETmpSmplF->setText(UploadCycle);
//        break;
//    }
    default:
        break;
    }
}

//网络上报参数设置
void ReportPeriod::on_PushByNetBTN_clicked()
{
    bool ok = 0;
    int iStartT = ui->StartRpTime->dateTime().toTime_t()+8*60*60;

    QString sTime;

    //QString sEndRpT = ui->EndRpT->dateTime().toString("HHmmss");
    QString sPeriod = ui->lineEPushCyc->text();//上报周期
    int iPeriod = sPeriod.toInt();
    QString sTimeOut = ui->lineEUploadTout->text();//超时
    int iTimeOut = sTimeOut.toInt();
    QString sReT = ui->lineReT->text();//重传
    int iReT = sReT.toInt();

    if(iPeriod < 1 || (24%iPeriod !=0 && iPeriod%24!=0))
    {
        QMessageBox::critical(this,"warning","上报周期错误");
        return;
    }
    if(iTimeOut <360 || iTimeOut%60!=0)
    {
        //QMessageBox::critical(this,"warning","上报超时时间错误[1-60]");
        //return;
    }
    if(iReT < 1 || iReT > 3)
    {
        QMessageBox::critical(this,"warning","上报重传错误次数[1-3]");
        return;
    }

    QString sStartT_HEX = QString("%1").arg(iStartT,8,16,QLatin1Char('0'));
    BigToLittle(sStartT_HEX,&sTime);
    QString ssPeriod = QString("%1").arg(iPeriod,4,16,QLatin1Char('0'));
    QString sV_Out;
    BigToLittle(ssPeriod,&sV_Out);
    QString ssTimeOut = QString("%1").arg(iTimeOut,4,16,QLatin1Char('0'));
    QString sV_Out_T;
    BigToLittle(ssTimeOut,&sV_Out_T);
    QString ssReT = QString("%1").arg(iReT,2,16,QLatin1Char('0'));

    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
    QString Value;
    Value.clear();
    cjt188objtx.dataId = CJT188_FIO_OBJ_ID_NET_PUSH;
    cjt188objtx.value = sTime + sV_Out + sV_Out_T + ssReT;
    cjt188objtx.desc = "写网络上报参数";
    emit RepTimeSet(cjt188objtx);

}

//累加器参数设置
void ReportPeriod::on_ACC_SAMP_BTN_clicked()
{
    QString sUploadC     = ui->lineERdCycle->text(); //采样周期
//    QString sUploadTout  = ui->lineERdTOut->text();  //采样超时
//    QString sReTs        = ui->lineReT_ACC->text();  //重传次数
    int iUploadC = sUploadC.toInt();
//    int iUploadTout = sUploadTout.toInt();
//    int iReTs = sReTs.toInt();
    QString ssUploadC = QString("%1").arg(iUploadC,4,16,QLatin1Char('0'));
//    QString ssUploadTout = QString("%1").arg(iUploadTout,4,16,QLatin1Char('0'));
//    QString ssReTs = QString("%1").arg(iReTs,2,16,QLatin1Char('0'));
    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
    cjt188objtx.dataId = CJT188_FIO_OBJ_ID_CUMULATIVE_SAMP;
    //cjt188objtx.value = ssUploadC + ssUploadTout + ssReTs;
    /***********************************************
     * delete by luch -20180302
     * 取消采样超时、重传次数
     * *******************************************/
    cjt188objtx.value = ssUploadC;
    cjt188objtx.desc = "累加器参数设置";
    emit RepTimeSet(cjt188objtx);
}

//温度采样参数设置
//void ReportPeriod::on_TMP_SAMP_BTN_clicked()
//{

//   QString sTmp_samp = ui->lineETmpSmplF->text();
//   int iTmp_samp = sTmp_samp.toInt();
//   QString ssTmp_samp = QString("%1").arg(iTmp_samp,4,16,QLatin1Char('0'));
//   CJT188Obj cjt188objtx;
//   cjt188objtx.clear();
//   cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_WR_DATA;
//   cjt188objtx.dataId = CJT188_FIO_OBJ_ID_TEMP_SAMP;
//   cjt188objtx.value = ssTmp_samp;
//   cjt188objtx.desc = "温度采样参数设置";
//   emit RepTimeSet(cjt188objtx);
//}



#if 0
void ReportPeriod::on_pushButton_clicked()
{
    QString sRdCycle     = ui->lineERdCycle->text();     //抄表间隔
    QString sTmpSmplF    = ui->lineETmpSmplF->text();    //温度采样频率
    QString sUploadC     = ui->lineEUploadC->text();     //上传周期
    QString sUploadTout  = ui->lineEUploadTout->text();  //上传超时
    QString sReTs        = ui->lineReT->text();          //重传次数

    int iRdCycle    = sRdCycle.toInt();
    int iTmpSmplF   = sTmpSmplF.toInt();
    int iUploadC    = sUploadC.toInt();
    int iUploadTout = sUploadTout.toInt();
    int iReTs       = sReTs.toInt();

    //转16进制补0
    QString ssRdCycle     = QString("%1").arg(iRdCycle   ,4,16,QLatin1Char('0'));
    QString ssTmpSmplF    = QString("%1").arg(iTmpSmplF  ,4,16,QLatin1Char('0'));
    QString ssUploadC     = QString("%1").arg(iUploadC   ,4,16,QLatin1Char('0'));
    QString ssUploadTout  = QString("%1").arg(iUploadTout,2,16,QLatin1Char('0'));
    QString ssReTs        = QString("%1").arg(iReTs      ,2,16,QLatin1Char('0'));

    QString value = ssRdCycle+ssTmpSmplF+ssUploadC+ssUploadTout+ssReTs+"0016010001000A0100010001";
    qDebug()<<value;
    emit RepPd(value);
}

//设置上报时间
void ReportPeriod::on_SetTimeBtn_clicked()
{
    Timer->start(1000);
}

void ReportPeriod::TTimeout()
{
    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
    QString Value;
    Value.clear();
    //当前时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyMMddHHmmss");
    //开始闲置时间
    QString sIdleStartT = ui->IdleStartT->dateTime().toString("yyMMddHHmmss");
    //闲置时间
    QString sIdleLength = ui->IdleLength->text();
    int iIdleLength = sIdleLength.toInt();
    QString ssIdleLength = QString("%1").arg(iIdleLength,2,16,QLatin1Char('0'));

    //开始工作时间
    QString sWorkStT = ui->WorkStT->dateTime().toString("yyMMddHHmmss");
    //工作时长
    QString sWorkTLen = ui->WorkTLen->text();
    int iWorkTLen = sWorkTLen.toInt();
    QString ssWorkTLen = QString("%1").arg(iWorkTLen,2,16,QLatin1Char('0'));
    //开始抄表时间
    QString sStartRdT = ui->StartRdT->dateTime().toString("yyMMddHHmmss");
    //开始上报时间
    QString sStartRpT = ui->StartRpT->dateTime().toString("yyMMddHHmmss");
    //温度采样时间
    QString sTempRdT = ui->TempRdT->dateTime().toString("yyMMddHHmmss");

    switch(i)
    {
    case 0:
    {
        //闲置时间
        if(sIdleStartT < current_date)
        {
            QMessageBox::critical(this,"warning","开始闲置时间不得早于当前时间");
            Timer->stop();
            i=0;

            return;
        }
        else if(sIdleStartT >current_date)
        {
            Value.clear();
            Value = sIdleStartT + ssIdleLength;
            cjt188objtx.dataId = CJT188_FIO_OBJ_ID_IDLE_TIME;
            cjt188objtx.value = Value;
            cjt188objtx.desc = "写开始闲置时间闲置时长";
            emit RepTimeSet(cjt188objtx);
        }
        break;
    }
    case 1:
    {
        //工作时间
        if(sWorkStT < current_date)
        {
            QMessageBox::critical(this,"warning","开始工作时间不得早于当前时间");
            Timer->stop();
            i=0;
            return;
        }
        else if(sWorkStT > current_date)
        {
            Value.clear();
            Value = sWorkStT + ssWorkTLen;
            cjt188objtx.dataId = CJT188_FIO_OBJ_ID_WORK_TIME;
            cjt188objtx.value = Value;
            cjt188objtx.desc = "写开始工作时间工作时长";
            emit RepTimeSet(cjt188objtx);
        }
        break;
    }
    case 2:
    {
        //抄表时间
        //上报时间
        if(sStartRdT < current_date || sStartRpT < current_date)
        {
            QMessageBox::critical(this,"warning","开始抄表、上报时间不得早于当前时间");
            Timer->stop();
            i=0;
            return;
        }
        else if(sStartRdT > current_date && sStartRpT > current_date)
        {
            Value.clear();
            Value = sStartRdT + sStartRpT;
            cjt188objtx.dataId = CJT188_FIO_OBJ_ID_START_REPROT_TIME;
            cjt188objtx.value = Value;
            cjt188objtx.desc = "写开始抄表时间开始上报时间";
            emit RepTimeSet(cjt188objtx);
        }
        break;
    }
    case 3:
    {
        //温度采样时间
        if(sTempRdT < current_date)
        {
            QMessageBox::critical(this,"warning","温度采样时间不得早于当前时间");
            Timer->stop();
            i=0;
            return;
        }
        else if(sTempRdT > current_date)
        {
            Value.clear();
            Value = sTempRdT;
            cjt188objtx.dataId = CJT188_FIO_OBJ_ID_SAMPLING_TIME;
            cjt188objtx.value = Value;
            cjt188objtx.desc = "写温度采样时间";
            emit RepTimeSet(cjt188objtx);
        }
        break;
    }
    default:
    {
        Timer->stop();
        i=0;
        break;
    }
    }
   i++;
}
#endif


