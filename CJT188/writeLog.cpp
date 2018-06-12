#include <QFile>
#include "writeLog.h"
/*
logPrint(Log WrtLog)
{

    QString fileH= "***";
    QString fileE= "*********************************************************";
    QString fEnd = "*******************************************************************************";
    QFile logtxt(logFile);
    //recvObjectqDebug()<<cjt188obj.allcmd;
    if(logtxt.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream in(&logtxt);
        in<<fileH+cjt188obj.desc+fileE<<endl;
        if(flag == 1)
        {
            in<<"Tx APDU:"<<endl;
            in<<cjt188obj.allcmd<<endl;
        }else{
            in<<"Rx APDU:"<<endl;
            in<<cjt188obj.allcmd<<endl;
            in<<fileH<<"Result "<<fileE<<endl;
            in<<cjt188obj.resultFlag<<endl;
            in<<fEnd<<endl;
            in<<endl;

        }


    }
    else
    {
        logtxt.close();
        qDebug()<<"打开日志文件错误";
        return;
    }
    logtxt.close();
}
*/
