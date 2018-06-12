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

#define UART_BUFFER_MAX 128

#define SEND_DATA           0x01
#define QUICK_SET           0x02
#define ROUTINE_CMD         0x04

enum CMD_Enum
{
    OP_MREAD,
    OP_SYNC,
    OP_STA,
    OP_SN,
    OP_RST,
    OP_SMSC,
    OP_APN,
    OP_USER,
    OP_PASSWD,
    OP_MODE,
    OP_HEARTBEAT,
    OP_METER_TICK,
    OP_UPLOAD_TICK,
    OP_CHECK_TICK,
    OP_IP,
    OP_DOMAIN,
    OP_PORT,
    OP_MBAUD,
    OP_MID,
    OP_MCNT,
    OP_METERCNT,
    OP_MTYPE,
    OP_MADD,
    OP_MDEL,
    OP_CE,
    OP_CHECK_NUM,
    OP_CHECK_STATUS,
    OP_REC_CNT,
    OP_UPLOAD,
    OP_INIT,
    OP_FIRM_VERSION,
    OP_TASK,
    OP_PCF,
    OP_DTU_ON,
    OP_DTU_CONNECT,
    OP_DTU_WRITE,
    OP_DTU_CLOSE,
    OP_DTU_OFF,
    OP_DTU_CONNECTION,
    OP_DTU_HW_CHECK,
    OP_DTU_SERVICE_CHECK,
};

enum TASK_Enum
{
    TASK_NONE,

    TASK_READ_SN,
    TASK_READ_APN,
    TASK_READ_MODE,
    TASK_READ_TYPE,
    TASK_READ_BAUD,
    TASK_READ_NUM,
    TASK_READ_TIME,
    TASK_READ_HEARTBEAT,
    TASK_READ_READ_TICK,
    TASK_READ_UPLOAD_TICK,
    TASK_READ_PCF,
    TASK_READ_CHECK_TICK,
    TASK_READ_IP,
    TASK_READ_PORT,
    TASK_READ_DEVICE_SN,
    TASK_READ_DEVICE,
    TASK_READ_DEVICE_WORKING_NUM,
    TASK_READ_DEVICE_STATUS,
    TASK_READ_FLASH_RECS,
    TASK_READ_DOMAIN,
    READ_METROLOGICAL_DATA,

    TASK_WRITE_SN,
    TASK_WRITE_STA,
    TASK_WRITE_APN,
    TASK_WRITE_MODE,
    TASK_WRITE_TYPE,
    TASK_WRITE_BAUD,
    TASK_WRITE_NUM,
    TASK_WRITE_TIME,
    TASK_WRITE_HEARTBEAT,
    TASK_WRITE_READ_TICK,
    TASK_WRITE_UPLOAD_TICK,
    TASK_WRITE_PCF,
    TASK_WRITE_CHECK_TICK,
    TASK_WRITE_IP,
    TASK_WRITE_PORT,
    TASK_WRITE_DOMAIN,

    TASK_ADD_HERCULES_NUM,
    TASK_ADD_HERCULES,
    TASK_ADD_DEVICES,
    TASK_DEL_DEVICES,
    TASK_DEL_METERS,

    TASK_SCAN_HERCULES,
    TASK_SCAN_METERS,
    TASK_UPLOAD,
    TASK_INIT,
    TASK_RESET,
    TASK_VERSION,

    TASK_REQ_DTU_ON,
    TASK_REQ_DTU_CONNECT,
    TASK_REQ_DTU_WRITE,
    TASK_REQ_DTU_CLOSE,
    TASK_REQ_DTU_OFF,
    TASK_REQ_DTU_CONNECTION,
    TASK_REQ_DTU_HW_CHECK,
    TASK_REQ_DTU_SERVICE_CHECK,
    TASK_REQ_DTU_STATUS,

    TASK_CLEAN_FALSH,
    TASK_FAILED,

    TASK_OPEN_VALVE,
    TASK_CLOSE_VALVE
};

typedef enum
{
    STATE_HW_OFF		= 0x00000000,
    STATE_HW_ON			= 0x00000001,
    STATE_HW_COMDATA	= 0x00000002,

    STATE_SIM			= 0x00000010,
    STATE_GSM			= 0x00000020,
    STATE_GPRS			= 0x00000040,

    STATE_SMS			= 0x00000100,

    STATE_SOCKET		= 0x00001000,
    STATE_SOCKET_CONNECTED		= 0x00002000,
    STATE_SOCKET_ACK	= 0x00004000,
} DtuStateEnum_Type;

#define DTU_TASK_ON  				(0x0000000000000001)
#define DTU_TASK_ON_BUSY			(0x0000000000000002)
#define DTU_TASK_ON_DONE			(0x0000000000000008)

#define DTU_TASK_HW_CHECK			(0x0000000000000010)
#define DTU_TASK_HW_CHECK_BUSY		(0x0000000000000020)
#define DTU_TASK_HW_CHECK_DONE		(0x0000000000000080)

#define DTU_TASK_NETWORK_CHECK		(0x0000000000000100)
#define DTU_TASK_NETWORK_CHECK_BUSY	(0x0000000000000200)
#define DTU_TASK_NETWORK_CHECK_DONE	(0x0000000000000800)

#define DTU_TASK_CONNECT			(0x0000000000001000)
#define DTU_TASK_CONNECT_BUSY		(0x0000000000002000)
#define DTU_TASK_CONNECT_DONE		(0x0000000000008000)

#define DTU_TASK_CONNECTION			(0x0000000000010000)
#define DTU_TASK_CONNECTION_BUSY	(0x0000000000020000)
#define DTU_TASK_CONNECTION_DONE	(0x0000000000080000)

#define DTU_TASK_WRITE				(0x0000000000100000)
#define DTU_TASK_WRITE_BUSY			(0x0000000000200000)
#define DTU_TASK_WRITE_DONE			(0x0000000000800000)

#define DTU_TASK_CLOSE				(0x0000000001000000)
#define DTU_TASK_CLOSE_BUSY			(0x0000000002000000)
#define DTU_TASK_CLOSE_DONE			(0x0000000008000000)

#define DTU_TASK_OFF				(0x0000000010000000)
#define DTU_TASK_OFF_BUSY			(0x0000000020000000)
#define DTU_TASK_OFF_DONE			(0x0000000080000000)

#define DTU_TASK_SMS_DEL			(0x0000000100000000)
#define DTU_TASK_SMS_DEL_BUSY		(0x0000000200000000)
#define DTU_TASK_SMS_DEL_DONE		(0x0000000800000000)

#define DTU_TASK_SMS_WR				(0x0000001000000000)
#define DTU_TASK_SMS_WR_BUSY		(0x0000002000000000)
#define DTU_TASK_SMS_WR_DONE		(0x0000008000000000)

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
    int                   ComTimeout;
    int                   ComPoll;

    void clear()
    {
        ComPortName.clear();
    }

    bool isEmpty()
    {
        return ComPortName.isEmpty();
    }
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
#if 0
    static int          curMeterType;

    static QSerialPort  *comMeter;
    static SerialInfo   comMeterInfo;
    static QSerialPort  *comSensor;
    static SerialInfo   comSensorInfo;
#endif
    static QSerialPort::BaudRate GetBaudrate(QString str);
    static QSerialPort::Parity   GetParity(QString str);
    static QSerialPort::DataBits GetDataBits(QString str);
    static QSerialPort::StopBits GetStopBits(int);
};



#endif // COMMON_H
