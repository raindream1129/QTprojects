#include "readhstdt.h"
#include "ui_readhstdt.h"
#include <QMessageBox>
#include <QDebug>
#include "common.h"
#include "cjt188_fio.h"
#include "cjt188_general.h"

ReadHstDt::ReadHstDt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadHstDt)
{
    ui->setupUi(this);

    i=0;


}

ReadHstDt::~ReadHstDt()
{
    delete ui;
}


/***************************************
 * 接收数据
 * ************************************/
void ReadHstDt::ReadHstDtResponse(CJT188Obj cjt188obj_t)
{
    int YMDFlag = 0;
    /*CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA   日
    CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA     时
    CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA    月
    */
    if(cjt188obj_t.dataId == CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA)
    {
        YMDFlag = 1;//日
    }
    else if(cjt188obj_t.dataId == CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA)
    {
        YMDFlag = 2;//时
    }
    else if(cjt188obj_t.dataId == CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA)
    {
        YMDFlag = 3;//月
    }
    QString Value = cjt188obj_t.value;
    int RecordNum = Value.mid(0,2).toInt();//记录数
    ui->labelRecordNumMon->setText(tr("记录数:%1").arg(RecordNum));
    QString sRecAll[RecordNum];
    QString ssRecAll = Value.mid(2,Value.length()-2);

    for(int i=0,k=0;i<RecordNum;i++)
    {
       sRecAll[i] .clear();
       /**************************************************
        * delete by luch--20180319-16.34
        * 返回数据与协议不符，临时改动
        * ***********************************************/
//       sRecAll[i] = ssRecAll.mid(k,k+28);
//       k +=28;
       sRecAll[i] = ssRecAll.mid(k,k+32);
       k +=32;
    }
    for(int i = 0;i<RecordNum;i++)
    {
        //时间
        QString Time_OneRec_T = sRecAll[i].mid(0,8);
        QString s_Out;
        BigToLittle_Int(Time_OneRec_T,&s_Out);
        QDateTime time = QDateTime::fromTime_t(s_Out.toInt()-30*60);//往前推30分钟能保证为前一时间段
        QString sTime_One;
        sTime_One.clear();
        if(YMDFlag == 1)
            sTime_One = time.toString("MM月dd日");
        else if(YMDFlag == 2)
            sTime_One = time.toString("dd日HH时");
        else if(YMDFlag == 3)
            sTime_One = time.toString("yy年MM月");
        //总量
        QString Total_Tot = sRecAll[i].mid(8,8);
        QString sTotal_Tot_Out;
        BigToLittle(Total_Tot,&sTotal_Tot_Out);
        bool ok;
        int iTotal_Tot = ("0x"+sTotal_Tot_Out).toInt(&ok,0);
        /**************************************************
         * delete by luch--20180319-16.34
         * 返回数据与协议不符，临时改动
         * ***********************************************/
        //Total_Tot = QString::number(((float)iTotal_Tot)/10.0) + "m3";
        Total_Tot = QString::number(((float)iTotal_Tot)/1000.0) + "m3";
        QString ST = sRecAll[i].mid(16,8);
        QString SystemSt = SystemState(ST.toInt());
        QString sTemp = sRecAll[i].mid(24,4);
        QString ssTemp;
        BigToLittle_Int(sTemp,&ssTemp);
        float iTemp = ssTemp.toFloat()/10.0;
        ssTemp = QString::number(iTemp);
        if(YMDFlag == 3)
        {//月
            ui->TBHistMonth->setRowCount(i+1);//总行数增加1
            ui->TBHistMonth->setItem(i,0,new QTableWidgetItem(sTime_One));
            ui->TBHistMonth->setItem(i,1,new QTableWidgetItem(Total_Tot));
            ui->TBHistMonth->setItem(i,2,new QTableWidgetItem(SystemSt));
            ui->TBHistMonth->setItem(i,3,new QTableWidgetItem(ssTemp));
        }
        else if(YMDFlag == 1)
        {//日
            ui->TBHistDate->setRowCount(i+1);//总行数增加1
            ui->TBHistDate->setItem(i,0,new QTableWidgetItem(sTime_One));
            ui->TBHistDate->setItem(i,1,new QTableWidgetItem(Total_Tot));
            ui->TBHistDate->setItem(i,2,new QTableWidgetItem(SystemSt));
            ui->TBHistDate->setItem(i,3,new QTableWidgetItem(ssTemp));
        }
        else if(YMDFlag == 2)
        {//时
            ui->TBHistTime->setRowCount(i+1);//总行数增加1
            ui->TBHistTime->setItem(i,0,new QTableWidgetItem(sTime_One));
            ui->TBHistTime->setItem(i,1,new QTableWidgetItem(Total_Tot));
            ui->TBHistTime->setItem(i,2,new QTableWidgetItem(SystemSt));
            ui->TBHistTime->setItem(i,3,new QTableWidgetItem(ssTemp));
        }
    }

}

/**************************************
 * 读取月历史记录(发送命令)
 * ***********************************/
void ReadHstDt::on_MonthBtn_clicked()
{
    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
    cjt188objtx.dataId = CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA;//月记录
    cjt188objtx.desc = "读月历史记录";

    int DateLength = 0;
    //当前时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    int current_date_time_T = current_date_time.toTime_t();//当前时间时间戳
    int LastDatetimeYear = current_date_time.date().year();
    if((LastDatetimeYear % 4 ==0 || LastDatetimeYear % 400 ==0) && (LastDatetimeYear % 100 !=0))
    {
        DateLength = 366;
    }else
    {
        DateLength = 365;
    }

    QString current_date =current_date_time.toString("yyMM");
    QString TimeStart = ui->DTEMonthStart->dateTime().toString("MM");
    QString ssTimeStart = QString("%1").arg(TimeStart.toInt(),2,16,QLatin1Char('0'));
    int TimeStart_T = ui->DTEMonthStart->dateTime().toTime_t();//开始时间戳
    QString TimeEnd = ui->DTEMonthEnd->dateTime().toString("MM");
    QString ssTimeEnd = QString("%1").arg(TimeEnd.toInt(),2,16,QLatin1Char('0'));
    int TimeEnd_T = ui->DTEMonthEnd->dateTime().toTime_t();//结束时间戳
    if((TimeStart_T + DateLength*24*3600) <  current_date_time_T || TimeEnd_T > current_date_time_T)
    {
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(TimeEnd_T < TimeStart_T)
    {
        QMessageBox::critical(this,"warning","结束时间不得小于开始时间");
        return ;
    }
    cjt188objtx.value = ssTimeStart + ssTimeEnd;

    emit ReadHistDt(cjt188objtx);
}

/*****************************************
 * 读日历史记录(发送数据)
 * **************************************/
void ReadHstDt::on_DateBtn_clicked()
{
    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
    cjt188objtx.dataId = CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA;//日记录
    cjt188objtx.desc = "读日历史记录";
    //当前时间
    QDateTime Current_date_time =QDateTime::currentDateTime();
    int iCurrent_date_time_T = Current_date_time.toTime_t();//当前时间时间戳
    int LastDatetimeYear = Current_date_time.date().year();
//    if((LastDatetimeYear % 4 ==0 || LastDatetimeYear % 400 ==0) && (LastDatetimeYear % 100 !=0))
//    {
//        isLeapY = 1;
//    }

    int iCurrent_date_Year = Current_date_time.date().year();//当前时间--年
    int iCurrent_date_Month =Current_date_time.date().month();//当前时间--月
    int iCurrent_date_Date =Current_date_time.date().day();//当前时间--日
    int iLastMonth = iCurrent_date_Month-1;//上个月份
    if( iLastMonth <= 0)
    {
        iLastMonth = 12;
    }


    QString sTimeStart = ui->DTEDateStart->dateTime().toString("dd");//开始时间--月、日
    QString ssTimeStart = QString("%1").arg(sTimeStart.toInt(),2,16,QLatin1Char('0'));
    int iTimeStart_Month = ui->DTEDateStart->dateTime().date().month();//开始时间--月
    QString sTimeEnd = ui->DTEDateEnd->dateTime().toString("dd");//结束时间--月、日
    QString ssTimeEnd = QString("%1").arg(sTimeEnd.toInt(),2,16,QLatin1Char('0'));

    int iTimeEnd_Month = ui->DTEDateEnd->dateTime().date().month();//结束时间--月
    int iTimeStart_T = ui->DTEDateStart->dateTime().toTime_t();//开始时间戳
    int iTimeEnd_T = ui->DTEDateEnd->dateTime().toTime_t();//结束时间戳

    if(iTimeEnd_T > iCurrent_date_time_T || iTimeStart_T > iCurrent_date_time_T)
    {//结束时间大于当前时间或开始时间大于当前时间
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(iLastMonth != 12 && (iCurrent_date_Month - iTimeStart_Month) > 1)
    {//本月非1月,上月非12月且当前月份减开始时间的月份大于1
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(iLastMonth == 12 && (iTimeStart_Month != 12 && iTimeStart_Month != 1))
    {//本月为1月，上月是12月，且开始时间不是12月也不是1月
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(iTimeEnd_T < iTimeStart_T)
    {
        QMessageBox::critical(this,"warning","结束时间不得小于开始时间");
        return ;
    }

    cjt188objtx.value = ssTimeStart + ssTimeEnd;

    emit ReadHistDt(cjt188objtx);
}

/*******************************************
 * 读历史记录--时
 * ****************************************/
void ReadHstDt::on_TimeBtn_clicked()
{
    CJT188Obj cjt188objtx;
    cjt188objtx.clear();
    cjt188objtx.ctrlId = CJT188_FIO_CTRL_ID_RD_DATA;
    cjt188objtx.dataId = CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA;//时记录
    cjt188objtx.desc = "读时历史记录";

    //当前时间
    QDateTime Current_date_time =QDateTime::currentDateTime();
    int iCurrent_date_time_T = Current_date_time.toTime_t();//当前时间时间戳
    QString sTimeStart = ui->DTETimeStart->dateTime().toString("hh");//开始时间--日、时
    QString ssTimeStart = QString("%1").arg(sTimeStart.toInt(),2,16,QLatin1Char('0'));

    int iTimeStart_Month = ui->DTETimeStart->dateTime().date().month();//开始时间--月
    QString sTimeEnd = ui->DTETimeEnd->dateTime().toString("hh");//结束时间--日、时
    QString ssTimeEnd = QString("%1").arg(sTimeEnd.toInt(),2,16,QLatin1Char('0'));


    int iTimeEnd_Month = ui->DTETimeEnd->dateTime().date().month();//结束时间--月
    int iTimeStart_T = ui->DTETimeStart->dateTime().toTime_t();//开始时间戳
    int iTimeEnd_T = ui->DTETimeEnd->dateTime().toTime_t();//结束时间戳
    QString strBuffer  = Current_date_time.toString("yyyyMMddhh") + "0000";
    QDateTime Current_date_time_MMss = QDateTime::fromString(strBuffer,"yyyyMMddhhmmss");
    int elapsed = ui->DTETimeStart->time().secsTo(Current_date_time_MMss.time());//开始时间到当前时间(分/秒=00)的秒数
    if(elapsed > 24*3600)
    {
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(iCurrent_date_time_T < iTimeStart_T || iCurrent_date_time_T < iTimeEnd_T)
    {
        QMessageBox::critical(this,"warning","查询时间超限");
        return ;
    }
    if(iTimeStart_T >= iTimeEnd_T)
    {
        QMessageBox::critical(this,"warning","结束时间不得小于等于开始时间");
        return ;
    }

    cjt188objtx.value =ssTimeStart + ssTimeEnd;
    emit ReadHistDt(cjt188objtx);
}


