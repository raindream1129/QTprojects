#ifndef WIDGET_H
#define WIDGET_H

#include "common.h"
#include "cjt188_fio.h"
#include "cjt188_general.h"
#include "writeLog.h"
#include <QWidget>
#include <QGridLayout>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMenu>
#include <QAction>
#include <QStringListModel>
#include "readhstdt.h"
#include "reportperiod.h"
#include "netconfig.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void fillPortsInfo();
    void loadComSettings();
    void meterComOpen();
    void meterComClose();
    void meterComSend();
    void logHandler(QString);
    void BuiltLogFileExe();
    void CmdExecution();
    void meterCmdResponseHandler();
    void readReportST();

    QSerialPort     *meterCom;
    SerialInfo      meterComInfo;
    QTimer          *meterRecvTimer;
    QTimer          *meterPollTimer;
    QByteArray      meterRecvArr;
    unsigned char   meterRecvBuff[UART_BUFFER_MAX];
    unsigned char   meterSendBuff[UART_BUFFER_MAX];
    int             meterRecvBuffLen;
    int             meterSendBuffLen;
    Routine         meterRoutine;
    bool            isMeterPulseOn;

    CJT188Obj       cjt188obj;
    Log      WriteLog;
    QString  logFile;

    ReadHstDt *readHistory;
    ReportPeriod *RepPd;

    NetConfig *NetCnf;





private slots:

        void on_BtnConn_clicked();

        void meterRecvData();

        void on_BtnRDAddr_clicked();

        void on_SetLDN_clicked();

        void on_BtnOpenV_clicked();

        void on_BtnClsV_clicked();

        void on_BtnSetT_clicked();

        void on_pushButton_clicked();

        void ReadHistoryData(CJT188Obj);

        void on_RdReportPeriodBtn_clicked();

        //void Reportpd(QString);

        void RepTimeSet(CJT188Obj);

        void on_BtnVth_clicked();

        void TTimeout();

        void TTimeout_A();

        void TTimeout_B();

        void TTimeout_C();

        void TTimeout_D();

        void Ctime_out();

        void on_pushButton_2_clicked();

        void on_ModleBTN_clicked();

        void on_MaxFlowBTN_clicked();

        void on_MinFlow_BTN_clicked();

        void on_IdleT_BTN_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_APPSevIPBTN_clicked();

        void on_BACKSevIPBTN_clicked();

        void on_BandWidthBTN_clicked();

        void on_PLMN_BTN_clicked();

        void on_AvoidPeakClouseBTN_clicked();

        void on_AvoidPeakOpenBTN_clicked();

        void on_Clear_NormalBTN_clicked();

        void on_Balance_BTN_clicked();

        void on_AlarmFlow_BTN_clicked();

        void on_RD_MTRLGC_DATA_BTN_clicked();

        void on_RD_EXTERNAL_V_clicked();

        void on_RD_RUNNIN_TIME_BTN_clicked();

        void on_RD_FIRMWARE_VERSION_BTN_clicked();

        void on_RD_TEMP_BTN_clicked();

        void on_RD_OFFLINE_TIME_BTN_clicked();

        void on_RD_OVERDRAFT_BTN_clicked();

        void on_FIRMWARE_VERSION_BTN_clicked();

        void on_RD_MODEL_BTN_clicked();

        void on_RD_THRESHOLD_BTN_clicked();

        void on_RD_MAX_FLOW_BTN_clicked();

        void on_RD_MIN_FLOW_BTN_clicked();

        void on_RD_IDLE_TIME_BTN_clicked();

        void on_RD_ILDE_OVERTIME_BTN_clicked();

        void on_RD_BALANCE_BTN_clicked();

        void on_RD_REMAINGAS_BTN_clicked();

        void on_RD_ALARM_BALANCE_BTN_clicked();

        void on_SYS_STATUS_BTN_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

        void on_Report_ST_BTN_clicked();

        void on_pushButton_9_clicked();

        void on_pushButton_5_clicked();

signals:
        void ReadData(QString);

        void ReadHstDtR(CJT188Obj);

        void ReadreportPeriod(quint32,QString);



private:
    Ui::Widget *ui;

    QTimer     *Timer;
    QTimer     *Timer_A;
    QTimer     *Timer_B;
    QTimer     *Timer_C;
    QTimer     *Timer_D;
    QTimer     *Ctime;
    int i;
    int NumOfHst;



};

#endif // WIDGET_H
