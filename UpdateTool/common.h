#ifndef COMMON_H
#define COMMON_H

#include <qDebug>
#include <stdint.h>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QDir>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDataStream>

#include <QMutex>
#include <QMutexLocker>

#define UART_BUFFER_MAX 512

#define SEND_DATA           0x01
#define QUICK_SET           0x02
#define ROUTINE_CMD         0x04

#define METER_RSP_NONE          0
#define METER_RSP_OK            1

#define METER_RSP_GOONUPDATE    0
#define METER_RSP_NOTGOONUPDATE 1


#define SUCCESS     0
#define FAIL        1



struct SerialInfo
{
    QString               ComPortName;
    QSerialPort::BaudRate ComBaud;
    QString               ComBaudStr;
    QSerialPort::Parity   ComParity;
    QString               ComParityStr;
    QSerialPort::DataBits ComDataBits;
    QString               ComDataBitsStr;
    QSerialPort::StopBits ComStopBits;
//    int                   ComTimeout;
//    int                   ComPoll;

    void clear()
    {
        ComPortName.clear();
    }

    bool isEmpty()
    {
        return ComPortName.isEmpty();
    }
};

enum taskEnum{
    TASK_CMD_SERVTODEV_VERSION_NUM,
    TASK_CMD_SERVTODEV_READY_UPGRADE,
    TASK_CMD_SERVTODEV_DATA_PACK,
    TASK_CMD_SERVTODEV_CHANGE_VERSION,
    TASK_CMD_SERVTODEV_HANDLE_UPGRADE,
    TASK_CMD_SERVTODEV_READ_VERSION,

};

struct Routine
{
    int     task;
    int     id;
    int     rsp;
    int     errCount;
    bool    ispolling;

    void clear()
    {
        task     = 0;
        id       = 0;
        rsp      = 0;
        errCount = 0;
        ispolling = false;
    }
};

class Record
{
public:
    quint32     sn;
    time_t      ts;
    quint32     pos;
    quint32     neg;
    qint32      flow;
    qint16      bat;

    Record(){}
    ~Record(){}

    void clear()
    {
        sn   = 0;
        ts   = 0;
        pos  = 0;
        neg  = 0;
        flow = 0;
        bat  = 0;
    }

//    friend QDataStream & operator << (QDataStream &dso, const Record &mp)
//    {
//        dso << mp.sn << mp.ts << mp.pos << mp.neg << mp.flow << mp.bat;

//        return dso;
//    }

//    friend QDataStream & operator >> (QDataStream &dsi, Record &mp)
//    {
//        dsi >> mp.sn >> mp.ts >> mp.pos >> mp.neg >> mp.flow >> mp.bat;

//        return dsi;
//    }
};
Q_DECLARE_METATYPE(Record);

typedef qint16  (*CMD2INT16)(quint8 *rsp);
typedef quint16 (*CMD2UINT16)(quint8 *rsp);
typedef qint32  (*CMD2INT32)(quint8 *rsp);
typedef quint32 (*CMD2UINT32)(quint8 *rsp);
typedef float   (*CMD2FLOAT)(quint8 *rsp, quint8 len);

typedef void    (*UINT162RSP)(quint8 *rsp, quint16 val);
typedef void    (*UINT322RSP)(quint8 *rsp, quint32 val);
typedef quint16 (*GETCRC16)( const quint8 *puchMsg, quint8 usDataLen);
typedef quint16 (*GETCS16)( const quint8 *puchMsg, quint8 usDataLen);

typedef unsigned char (*GETNUM)(unsigned char c);
typedef unsigned char (*GETHEX)(unsigned char c);

class Common
{
public:
    static QString      DBPath;
    static QString      CONFPath;
    static QString      DATAPath;
    static CMD2INT16    pcmdToint16;
    static CMD2UINT16   pcmdTouint16;
    static CMD2UINT32   pcmdTouint32;
    static CMD2INT32    pcmdToint32;
    static CMD2FLOAT    pcmdTofloat;
    static UINT162RSP   puint16ToRsp;
    static UINT322RSP   puint32ToRsp;
    static GETCRC16     pGetCRC16;
    static GETCS16      pGetCS16;
    static GETNUM       pGetNum;
    static GETHEX       pGetHex;
    static void log(QString logStr);

    static QSerialPort::BaudRate GetBaudrate(QString str);
    static QSerialPort::Parity   GetParity(QString str);
    static QSerialPort::DataBits GetDataBits(QString str);
    static QSerialPort::StopBits GetStopBits(int);
};
int BigToLittle(QString,QString *str_out);
int BigToLittle_Int(QString str_in,QString *str_out);


#endif // COMMON_H
