#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include "common.h"
#include "cjt188_fio.h"
#include "cjt188_general.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    int iTimesReport;




    void fillPortsInfo();
    void loadComSettings();
    void meterComOpen();
    void meterComClose();
    void meterComSend();
    void CMDSend();
    void meterCmdResponseHandler();
    int Support();
    void logHandler(QString);

    void Rest();

    void StopAll();
    void StartAll();

private slots:
    void on_Open_Port_clicked();

    void meterRecvData();

    void on_Close_Port_clicked();

    void on_pushButton_clicked();

    void TTimeout();

    void TATimeout();
    void TBTimeout();
    void TCTimeout();
    void TDTimeout();

    void on_pushButton_2_clicked();

    void on_LDN_LE_returnPressed();

private:
    Ui::MainWindow *ui;

    bool TotalizerIsOk;
    QTimer     *Timer;
    QTimer      *TimerA;//1秒
    QTimer      *TimerB;//45秒
    QTimer      *TimerC;//15秒
    QTimer      *TimerD;//30秒
    int i;
    int j;
};

#endif // MAINWINDOW_H
