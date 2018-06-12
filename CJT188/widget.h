#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "common.h"
#include <QtXml>
#include <QFile>
#include "cjt188_general.h"
#include "cjt188_fio.h"
#include "writeLog.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void loadComSettings(SerialInfo*);
    void loadExternalConfig(QList<Cjt188Object> *);

private slots:
    void meterRecvData();
    void meterRecvTimeout();

    //void on_BtnWrLdn_clicked();

    //void on_BtnSync_clicked();
    void autoCmdExecution(void);


private:
    Ui::Widget *ui;

    void logPrint(Cjt188Object,int);

    void meterComOpen();
    void meterComClose();
    void meterComSend();

    void meterCmdListHandler();
    void meterCmdResponseHandler();
    void save_meterCmdResponse(Cjt188Object recvObject);
    void preActive(Cjt188Object currentObj,Log Logprint);

    QSerialPort     *meterCom;
    SerialInfo      meterComInfo;
    QTimer          *meterRecvTimer;
    QTimer          *testTimer;
    QByteArray      meterRecvArr;
    unsigned char   meterRecvBuff[UART_BUFFER_MAX];
    unsigned char   meterSendBuff[UART_BUFFER_MAX];
    int             meterRecvBuffLen;
    int             meterSendBuffLen;
    Routine         meterRoutine;
    QDomDocument meterCmdResponseMsg;
    QDomElement RootNode;

    int i;
    int m_nTimerID;

    quint8 series;

public:
    QList<Cjt188Object>   cjt188_cmds_list;
    void autoExe(void);

    QByteArray QString2Hex(QString str);
    int ConvertHexChar(char ch);
    QString ResFileNm;
    QString  logFile;
    Log      WriteLog;
};

#endif // WIDGET_H
