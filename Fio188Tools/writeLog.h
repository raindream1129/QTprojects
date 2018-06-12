#ifndef WRITE_LOG_H
#define WRITE_LOG_H

#include <QString>

#define Log_READ_DIRECTION  0
#define Log_WRITE_DIRECTION 1

class Log
{
public:
    int     TRFlag;     //标识
    QString desc;       //描述
    quint8  ClientID;   //操作员号
    QString Tx_APDU;    //发送的命令
    QString Rx_APDU;    //接收的数据
    QString Result;     //结果
    QString LogFileName;//文件名
    QString ErrMsg;     //错误信息
    Log(){}
    ~Log(){}
    void clear()
    {
        TRFlag = -1;
        desc.clear();
        ClientID = 0;
        Tx_APDU.clear();
        Rx_APDU.clear();
        Result.clear();
        LogFileName.clear();
        ErrMsg.clear();
    }
};

int logPrint(Log WrtLog);
















#endif
