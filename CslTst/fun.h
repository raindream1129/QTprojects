#ifndef FUN_H
#define FUN_H

#include "common.h"


#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringListModel>

enum MeterRsp
{
    METER_RSP_NONE = 0,
    METER_RSP_OK
};

//void fillPortsInfo();
void loadComSettings();
void meterComOpen();
void meterComClose();
void logHandler(QString);
void meterRecvData();
void meterRecvTimeout();
void meterPollTimeout();
void meterSend();
void meterTaskHandler();
QByteArray QString2Hex(QString str);
int ConvertHexChar(char ch);


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

quint32         zeusSn;
quint32         zeusSta;
quint32         deviceMode;
quint32         deviceCnt;
quint32         deviceType;
quint32         deviceBaud;
quint32         deviceId;
quint32         deviceIdx;
quint32         deviceWorks;
quint32         herculesSn;
quint16         herculesIndex;
quint32         tickRead;
quint32         tickCheck;
QByteArray      syncTime;
quint32         ip;
qint32          port;
quint32         addrCur, addrTx;
QString         apnString;
char            SnNum[60];
quint32          SnNm[20];
QStringList     idList;

QString         MTCOMM;
QString         METERLDN;



#endif // FUN_H
