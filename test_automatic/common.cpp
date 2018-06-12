#include "common.h"
#include <QTextStream>
#include <QDebug>
/* CRC High byte */
const static quint8 auchCRCHi[ 256 ] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

/* CRC Low byte */
const static quint8 auchCRCLo[ 256 ] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};


qint16 cmdToint16(quint8 *rsp)
{
    qint16 v;

    v  = (qint16)(rsp[0]) << 8;
    v |= (qint16)(rsp[1]);

    return v;
}

quint16 cmdTouint16(quint8 *rsp)
{
    quint16 v;

    v  = (quint16)(rsp[0]) << 8;
    v |= (quint16)(rsp[1]);

    return v;
}

void uint16ToRsp(quint8 *rsp, quint16 val)
{
    rsp[0] = val >> 8;
    rsp[1] = val;
}

quint32 cmdTouint32(quint8 *rsp)
{
    quint32 v;

    v  = (quint32)(rsp[0]) << 24;
    v |= (quint32)(rsp[1]) << 16;
    v |= (quint32)(rsp[2]) <<  8;
    v |= (quint32)(rsp[3]);

    return v;
}

qint32 cmdToint32(quint8 *rsp)
{
    qint32 v;

    v  = (qint32)(rsp[0]) << 24;
    v |= (qint32)(rsp[1]) << 16;
    v |= (qint32)(rsp[2]) <<  8;
    v |= (qint32)(rsp[3]);

    return v;
}

float cmdTofloat(quint8 *rsp, quint8 len)
{
    quint8 i;
    qint64 t64 = 0;
    qint32 t32 = 0;
    qint32 temp;

    double retFloat;

    for(i = 0; i < len; i++) {
        t64 |= rsp[i];
        if(i < 3) {
            t64 <<= 8;
        }
    }

    if(8 == len) {
        temp = 1000000000;
    }else{
        temp = 100000;
    }

    if(4 == len){
        t32 = (qint32)t64;
        retFloat = (double)t32 / (double)temp;
    } else {
        retFloat = (double)t64 / (double)temp;
    }

    return retFloat;
}



void uint32ToRsp(quint8 *rsp, quint32 val)
{
    rsp[0] = val >> 24;
    rsp[1] = val >> 16;
    rsp[2] = val >> 8;
    rsp[3] = val;
}

quint16 GetCRC16( const quint8 *puchMsg, quint8 usDataLen )
{
    quint8 uchCRCHi = 0xFF;
    quint8 uchCRCLo = 0xFF;
    quint8 uIndex = 0;

    while (usDataLen--)
    {
        uIndex = uchCRCHi ^ *puchMsg++;
        uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
        uchCRCLo = auchCRCLo[uIndex];
    }

    return (quint16)((quint16)uchCRCHi << 8 | uchCRCLo);
}

quint16 GetCS16( const quint8 *puchMsg, quint8 usDataLen )
{
    quint16 cs16 = 0;

    for(int i = 0; i < usDataLen; i++)
    {
        cs16 += *puchMsg++;
    }

    return cs16;
}

unsigned char GetNum(unsigned char c)
{
    if(c > 90){
        return 0;
    }

    return (c >= 65) ? (c - 65 + 10) : (c - 48);
}

unsigned char GetHex(unsigned char c)
{
    unsigned char base  = 1;
    unsigned char tmp   = 0;
    while(c){
        tmp += c % 16;
        c /= base;
        base = 16;
    }

    return tmp;
}

QSerialPort::BaudRate Common::GetBaudrate(QString str)
{
    int val = str.toInt();
    switch (val) {
    case 1200:
        return QSerialPort::Baud1200;
    case 2400:
        return QSerialPort::Baud2400;
    case 4800:
        return QSerialPort::Baud4800;
    case 9600:
        return QSerialPort::Baud9600;
    case 19200:
        return QSerialPort::Baud19200;
    case 38400:
        return QSerialPort::Baud38400;
    case 57600:
        return QSerialPort::Baud57600;
    case 115200:
        return QSerialPort::Baud115200;
    default:
        return QSerialPort::UnknownBaud;
    }
}

QSerialPort::Parity Common::GetParity(QString str)
{
    if(str.contains("NONE"))
        return QSerialPort::NoParity;
    else if(str.contains("EVEN"))
        return QSerialPort::EvenParity;
    else if(str.contains("ODD"))
        return QSerialPort::OddParity;
    else if(str.contains("SPACE"))
        return QSerialPort::SpaceParity;
    else if(str.contains("MARK"))
        return QSerialPort::MarkParity;
    else
        return QSerialPort::UnknownParity;
}

QSerialPort::DataBits  Common::GetDataBits(QString str)
{
    int val = str.toInt();
    switch (val) {
    case 5:
        return QSerialPort::Data5;
    case 6:
        return QSerialPort::Data6;
    case 7:
        return QSerialPort::Data7;
    case 8:
        return QSerialPort::Data8;
    default:
        return QSerialPort::UnknownDataBits;
    }
}

QSerialPort::StopBits Common::GetStopBits(int stopInt)
{
    switch (stopInt) {
    case 1:
        return QSerialPort::OneStop;
    case 2:
        return QSerialPort::TwoStop;
    case 3:
        return QSerialPort::OneAndHalfStop;
    default:
        return QSerialPort::UnknownStopBits;
    }
}

void Common::log(QString logStr)
{
    QString logPath = QDir::currentPath() + "/Log/" + QDate::currentDate().toString("yyyy-MM-dd") + ".txt";
    QFile logFile(logPath);
    if(logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QTextStream in(&logFile);
        in << logStr << "\r\n";

        logFile.close();
    }

}

QString    Common::DBPath;
QString    Common::CONFPath;
QString    Common::DATAPath;
CMD2INT16  Common::pcmdToint16  = cmdToint16;
CMD2UINT16 Common::pcmdTouint16 = cmdTouint16;
CMD2UINT32 Common::pcmdTouint32 = cmdTouint32;
CMD2INT32  Common::pcmdToint32 = cmdToint32;
CMD2FLOAT  Common::pcmdTofloat  = cmdTofloat;
UINT162RSP Common::puint16ToRsp = uint16ToRsp;
UINT322RSP Common::puint32ToRsp = uint32ToRsp;
GETCRC16   Common::pGetCRC16    = GetCRC16;
GETCS16    Common::pGetCS16     = GetCS16;
GETNUM     Common::pGetNum      = GetNum;
GETHEX     Common::pGetHex      = GetHex;

#if 0
QSerialPort  *Common::comMeter  = new QSerialPort();
SerialInfo   senorComInfo;
QSerialPort  *Common::comSensor = new QSerialPort();
SerialInfo   meterComInfo;
int        Common::curMeterType;
#endif
int ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
     return ch-'0';
    else if((ch >= 'A') && (ch <= 'F'))
     return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
     return ch-'a'+10;
    else return (-1);
}

QByteArray QString2Hex(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();   //字符型
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}
/****系统状态*****/
QString SystemState(int ST)
{
    int systerSt = ST;
    STATE StateAll;
    StateAll.state0 = systerSt & 0x01;
    StateAll.state1 = systerSt & 0x02;
    StateAll.state2 = systerSt & 0x04;
    StateAll.state3 = systerSt & 0x08;
    StateAll.state4 = systerSt & 0x10;
    StateAll.state5 = systerSt & 0x20;
    StateAll.state6 = systerSt & 0x40;
    StateAll.state7 = systerSt & 0x80;
    StateAll.state8 = (systerSt >> 8) & 0x01;
    StateAll.state9 = (systerSt >> 8) & 0x02;
    StateAll.state10 = (systerSt >> 8) & 0x04;
    StateAll.state11 = (systerSt >> 8) & 0x08;
    StateAll.state12 = (systerSt >> 8) & 0x10;
    StateAll.state13 = (systerSt >> 8) & 0x20;
    StateAll.state14 = (systerSt >> 8) & 0x40;
    StateAll.state15 = (systerSt >> 8) & 0x80;
    StateAll.state16 = (systerSt >> 16) & 0x01;
    StateAll.state17 = (systerSt >> 16) & 0x02;
    StateAll.state18 = (systerSt >> 16) & 0x04;
    StateAll.state19 = (systerSt >> 16) & 0x08;
    StateAll.state20 = (systerSt >> 16) & 0x10;
    StateAll.state21 = (systerSt >> 16) & 0x20;
    StateAll.state22 = (systerSt >> 16) & 0x40;
    StateAll.state23 = (systerSt >> 16) & 0x80;
    StateAll.state24 = (systerSt >> 24) & 0x01;
    StateAll.state25 = (systerSt >> 24) & 0x02;
    StateAll.state26 = (systerSt >> 24) & 0x04;
    StateAll.state27 = (systerSt >> 24) & 0x08;
    StateAll.state28 = (systerSt >> 24) & 0x10;
    StateAll.state29 = (systerSt >> 24) & 0x20;
    StateAll.state30 = (systerSt >> 24) & 0x40;
    StateAll.state31 = (systerSt >> 24) & 0x80;

    QString stateStr;
    stateStr.clear();
    if(StateAll.state0 != 0)
    {
        stateStr = stateStr + "同步异常 ";
    }
    if(StateAll.state1 !=0)
    {
        stateStr = stateStr + "日志存满 ";
    }
    if(StateAll.state2 !=0)
    {
        stateStr = stateStr + "日志存储空间不足 ";
    }
    if(StateAll.state3 !=0)
    {
        stateStr = stateStr + "计量错误 ";
    }
    if(StateAll.state4 !=0)
    {
        stateStr = stateStr + "设备故障 ";
    }
    if(StateAll.state5 !=0)
    {
        stateStr = stateStr + "欠费 ";
    }
    if(StateAll.state6 !=0)
    {
        stateStr = stateStr + "内存错误 ";
    }
    if(StateAll.state7 !=0)
    {
        stateStr = stateStr + "设备状态错误 ";
    }
    if(StateAll.state8 !=0)
    {
        stateStr = stateStr + "内电低电压 ";
    }if(StateAll.state9 !=0)
    {
        stateStr = stateStr + "内电电压严重不足 ";
    }if(StateAll.state10 !=0)
    {
        stateStr = stateStr + "开盖报警 ";
    }if(StateAll.state11 !=0)
    {
        stateStr = stateStr + "DST开启 ";
    }
    if(StateAll.state12 !=0)
    {
        stateStr = stateStr + "阀门故障 ";
    }
    if(StateAll.state13 !=0)
    {
        stateStr = stateStr + "时钟同步进行中 ";
    }
    if(StateAll.state14 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state15 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state16 !=0)
    {
        stateStr = stateStr + "外电低电压 ";
    }
    if(StateAll.state17 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state18 !=0)
    {
        stateStr = stateStr + "外电掉电 ";
    }
    if(StateAll.state19 !=0)
    {
        stateStr = stateStr + "余额不足 ";
    }
    if(StateAll.state20 !=0)
    {
        stateStr = stateStr + "流量异常 ";
    }
    if(StateAll.state21 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state22 !=0)
    {
        stateStr = stateStr + "强磁干扰 ";
    }
    if(StateAll.state23 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state24 !=0)
    {
        stateStr = stateStr + "阀门关闭 ";
    }
    else{
        stateStr = stateStr + "阀门打开 ";
    }
    if(StateAll.state25 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state26 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state27 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state28 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state29 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state30 !=0)
    {
        stateStr = stateStr + "";
    }
    if(StateAll.state31 !=0)
    {
        stateStr = stateStr + "";
    }
    return stateStr;
}

//IP地址转换为字符串
int IPtoString(QString IPAddress,QString *str)
{
    QString IPAddr[4];
    int IPAdd[4];
    int IPFalg = 0;
    IPAdd[0] = IPAddress.section(".",0,0).toInt();
    IPAdd[1] = IPAddress.section(".",1,1).toInt();
    IPAdd[2] = IPAddress.section(".",2,2).toInt();
    IPAdd[3] = IPAddress.section(".",3,3).toInt();

    if(IPAdd[0] > 255 || IPAdd[1] > 255 || IPAdd[2] >255 || IPAdd[3] > 255)
        IPFalg = 1;


    IPAddr[0] = QString("%1").arg(IPAdd[0],2,16,QLatin1Char('0'));
    IPAddr[1] = QString("%1").arg(IPAdd[1],2,16,QLatin1Char('0'));
    IPAddr[2] = QString("%1").arg(IPAdd[2],2,16,QLatin1Char('0'));
    IPAddr[3] = QString("%1").arg(IPAdd[3],2,16,QLatin1Char('0'));

    *str =  IPAddr[0]+IPAddr[1]+IPAddr[2]+IPAddr[3];
    return IPFalg;
}
//端口转换成16进制 高低位互换
int PORTtostring(QString PORTAddress,QString *str)
{
    int PORTAdd = PORTAddress.toInt();
    int PortFlag = 0;
    if(PORTAdd > 65535)
        PortFlag = 1;

    QString Portid = QString("%1").arg(PORTAdd,4,16,QLatin1Char('0'));
    *str =  Portid.mid(2,2) + Portid.mid(0,2);
    return PortFlag;
}


int BigToLittle(QString str_in,QString *str_out)
{
    QString sStr_In = str_in;
    QString sStr_Out;
    sStr_Out.clear();

    for(int i = sStr_In.length()-1;i>=0;)
    {
        sStr_Out = sStr_Out + sStr_In.mid(i-1,2);
        i -= 2;
    }
    *str_out = sStr_Out;
    return SUCCESS;
}


int BigToLittle_Int(QString str_in,QString *str_out)
{
    QString sStr_In = str_in;
    QString sStr_Out;
    sStr_Out.clear();

    for(int i = sStr_In.length()-1;i>=0;)
    {
        sStr_Out = sStr_Out + sStr_In.mid(i-1,2);
        i -= 2;
    }
    sStr_Out = "0x" + sStr_Out;
    bool ok;
    *str_out = QString::number(sStr_Out.toInt(&ok,0));
    return SUCCESS;
}
