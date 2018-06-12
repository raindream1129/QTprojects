#include <QFile>
#include "writeLog.h"
#include "widget.h"
#include <QTextStream>
#include <QDebug>
int logPrint(Log WrtLog)
{
    QString Filename = WrtLog.LogFileName;
    QString fileH= "***";
    QString fileE= "*********************************************************";
    QString fEnd = "*******************************************************************************";
    QFile logtxt(Filename);
    if(logtxt.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream in(&logtxt);
        in<<WrtLog.desc<<endl;
        in<<fileE<<endl;
        if(WrtLog.TRFlag == Log_WRITE_DIRECTION)
        {
            in<<"Tx APDU:"<<endl;
            in<<WrtLog.Tx_APDU;
            qDebug()<<"Tx:"<<WrtLog.Tx_APDU;
        }else{
            in<<"Rx APDU:"<<endl;
            in<<WrtLog.Rx_APDU<<endl;
            in<<fileH<<"Result "<<fileE<<endl;
            in<<WrtLog.Result<<endl;
            qDebug()<<"RX:"<<WrtLog.Rx_APDU;
            in<<fEnd<<endl;
            in<<endl;
        }
    }
    else
    {
        logtxt.close();
        return 1;
    }
    logtxt.close();
    return 0;
}

