#ifndef COMMON_H
#define COMMON_H

//#include <qDebug>
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

#define FAIL 1
#define SUCCESS 0

#define MAX_MONTH_RECORDS   12
#define MAX_DATE_RECORDS    31
#define MAX_TIME_RECORDS    24

#define MAX_TIMEOUT_READ    800

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

    TASK_READ_LDN,
    TASK_READ_METROLOGICAL_DATA,
    TASK_WRITE_LDN,
    TASK_WRITE_TIME,
    TASK_WRITE_OPEN_VALVE,
    TASK_WRITE_CLOSE_VALVE,

    TASK_READ_HISTORY_DATA_NUMBER,
    TASK_READ_HISTORY_DATA,

    TASK_READ_REPORT_PERIOD_NET,
    TASK_READ_ACCUMULATOR_PARAM,
    TASK_READ_WORK_TIME,
    TASK_READ_START_READDEV_AND_REPORT_TIME,
    TASK_READ_TEMP_SAMP_TIME,
    TASK_READ_EXTERNAL_VOL,
    TASK_READ_VOLTAGE_TH,
    TASK_READ_DEVICE_STATE,
    TASK_READ_REMAIN_GAS,
    TASK_READ_BALANCE,
    TASK_READ_MODLE_CHANGE,
    TASK_READ_SYSTEM_STATE,
    TASK_READ_WORKING_TIME,
    TASK_READ_DEVICENET_VERSION,
    TASK_READ_ENVIRONMENT_TEMPERATURE,
    TASK_READ_MAX_FLOW,
    TASK_READ_MIN_FLOW,
    TASK_READ_IDLE_TIME,
    TASK_READ_DROP_TIME,
    TASK_READ_IDLED_TIME,
    TASK_READ_ALARM_BANLANCE,
    TASK_READ_OVERDRAFT,
    TASK_READ_FIRMWARE_VERSION,
    TASK_READ_DEVICE_WAKEUP_TIME,
    TASK_READ_TOTALIZER_STYLE,

    TASK_READ_MODLE_INFORMATION,
    TASK_READ_APPLICATION_SERVER,
    TASK_READ_BACKUP_SERVER,
    TASK_READ_BAND_WIDTH,
    TASK_READ_NBIOT_PLMN,
    TASK_READ_NBIOT_AVOID_PEAK,
    TASK_READ_NBIOT_REPORT_STATUS,

    TASK_READ_CHECK_NORMAL_STATION,
    TASK_READ_CLEAR_NORMAL_STATION,
    TASK_READ_NBIOT_ALLOWANCE_PROMPT,

    TASK_WRITE_REPORT_PERIOD,
    TASK_WRITE_ACC_SAMP_PARA,
    TASK_WRITE_TEMP_SAMP_TIME,

    TASK_WRITE_VOLTAGE_TH,
    TASK_WRITE_MODLE_CHANGE,
    TASK_WRITE_MAX_FLOW,
    TASK_WRITE_MIN_FLOW,
    TASK_WRITE_NETCONFIG,
    TASK_WRITE_IDLE_TIME,
    TASK_WRITE_HANDLE_REPORT,
    TASK_WRITE_APPLICATION_SERVER,
    TASK_WRITE_BACKUP_SERVER,
    TASK_WRITE_BAND_WIDTH,
    TASK_WRITE_PLMN,
    TASK_WRITE_AVOID_PEAK_ABLE,
    TASK_WRITE_AVOID_PEAK_ENABLE,
    TASK_WRITE_CHARGE,
    TASK_WRITE_ALARM_BALANCE,
    TASK_WRITE_ALARM_FLOW,
    TASK_WRITE_WAKEUP_TIME,
    TASK_WRITE_TOTALIZER_STYLE,
    TASK_WRITE_ALLOWANCE_PROMPT,



    TASK_CLEAN_FALSH,
    TASK_FAILED
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




#define METER_RSP_NONE  0
#define METER_RSP_OK    1

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
QString SystemState(int ST);
int IPtoString(QString,QString*);
int PORTtostring(QString,QString*);
int BigToLittle(QString,QString *str_out);
int BigToLittle_Int(QString str_in,QString *str_out);
struct STATE
{
    quint8 state0;      //同步
    quint8 state1;      //日志存满
    quint8 state2;      //日志存储空间不足
    quint8 state3;      //计量错误
    quint8 state4;      //设备故障
    quint8 state5;      //欠费
    quint8 state6;      //内存错误
    quint8 state7;      //设备状态错误
    quint8 state8;      //内电低电压
    quint8 state9;      //内电严重不足
    quint8 state10;     //开盖报警
    quint8 state11;     //DST开启
    quint8 state12;     //阀门故障
    quint8 state13;     //时钟同步进行中
    quint8 state14;     //
    quint8 state15;     //
    quint8 state16;     //外电低电压
    quint8 state17;     //
    quint8 state18;     //外电掉电
    quint8 state19;     //余额不足
    quint8 state20;     //流量异常
    quint8 state21;     //
    quint8 state22;     //强磁干扰
    quint8 state23;     //
    quint8 state24;     //阀门状态
    quint8 state25;
    quint8 state26;
    quint8 state27;
    quint8 state28;
    quint8 state29;
    quint8 state30;
    quint8 state31;




};





#endif // COMMON_H
