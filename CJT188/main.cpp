#include "widget.h"
#include <writeLog.h>
#include <rdxml.h>
#include "common.h"
#include "QApplication"
#include "cjt188_general.h"
#include "cjt188_fio.h"

extern int TimeOut;
extern int TimeNum;
/*配置串口参数*/
SerialInfo loadLocalConfiguration()
{
    SerialInfo sinfo;
    sinfo.clear();
    TimeOut = 0;
    TimeNum = 0;
    QFile file("config.conf");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream Rdfl(&file);
        while (!Rdfl.atEnd())
        {
            QString OneLine = Rdfl.readLine();
            if("[COM]" == OneLine)
            {
                sinfo.ComPortName = Rdfl.readLine().section('=',1,1);
                sinfo.ComBaud = QSerialPort::Baud9600;
                sinfo.ComBaudStr = "9600";
                sinfo.ComDataBits = QSerialPort::Data8;
                sinfo.ComDataBitsStr = "1";
                sinfo.ComParity = QSerialPort::NoParity;
                sinfo.ComParityStr = "NONE";
                sinfo.ComStopBits = QSerialPort::OneStop;
                sinfo.ComTimeout = 10000;
//                sinfo.ComPoll
                qDebug()<<"COM:"<< sinfo.ComPortName;
                //file.close();
                //break;
            }
            else if("[TIMEOUT]" == OneLine)
            {
                TimeOut = Rdfl.readLine().section('=',1,1).toInt();
                qDebug()<<"超时时间[毫秒]:"<<TimeOut;
            }
            else if("[TIME]" == OneLine)
            {
                QString tmp = Rdfl.readLine();
                TimeNum = tmp.right(1).toInt();
                qDebug()<<"超时次数:"<<TimeNum;
                break;
            }
            //sinfo.ComBaudStr = "9600";
            //sinfo.ComBaud = 9600;

        }
    }
    else
    {
        qDebug()<<"Open local configuration failed.";
        file.close();
    }

    return sinfo;
}

void xmlsToCmdList(QList<Cjt188Object> *cmdsToBeReady,QString XmlFilename)
{

    RdXML RdXml;
    RdXml.read_xml(cmdsToBeReady,XmlFilename);

}

/*清空文件*/
void ClearFile(QString RESFilename)
{
        QFile Savexmlfile(RESFilename);
        Savexmlfile.open(QIODevice::ReadOnly);
        QTextStream io(&Savexmlfile);
        int b;
        io>>b;
       // qDebug("%d",b);
        Savexmlfile.close();
        Savexmlfile.open(QIODevice::Truncate);
        Savexmlfile.close();
        Savexmlfile.open(QIODevice::WriteOnly);
        io<<1;
        Savexmlfile.close();
}

/* 命令行执行

用法：
    程序名  命令序列文件  结果保存文件
例如：
    cjt188_lib.exe ./get_ldn.xml ./reuslt_get_ldn.xml
*/


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    if(argc <3)
    {
        qDebug()<<"Usage:.exe ./config.xml ./reuslt.xml";
        exit(1);
    }
    QString CMDFilename = "xml\\" + QString(QLatin1String(argv[1]));
    QString RESFilename = "result\\" + QString(QLatin1String(argv[2]));
    /* 加载本地配置 */
    SerialInfo serialInfo;
    serialInfo = loadLocalConfiguration();
    if (serialInfo.isEmpty())
    {
        qDebug() << "Load local configuration failed.";
    }

    /* 加载命令集 */
    QList<Cjt188Object> cmdsToBeReady;
    xmlsToCmdList(&cmdsToBeReady,CMDFilename);
    if (!cmdsToBeReady.length())
    {
        qDebug() << "No command found!";
        return 0;
    }
/*
    //写低电压检测阈值

    // 判断传入参数是否为.xml
    //是，调用解析函数处理文本，讲提取的有效信息共享至list
    //否，无操作
    Cjt188Object cjt188Obj;
    cjt188Obj.desc = "Set low voltage";
    cjt188Obj.address = "AAAAAAAAAAAAAA";
    cjt188Obj.ctrlId = CJT188_CTRL_ID_WR_DATA;
    cjt188Obj.flagId = CJT188_FIO_OBJ_ID_BATT_THRESHOLD;
    cjt188Obj.dataId = CJT188_FIO_OBJ_DATA_ID_BATT;
    cjt188Obj.value = "21";
    cmdsToBeReady.append(cjt188Obj);

*/


    Widget w;
    ClearFile(RESFilename);
    w.loadComSettings(&serialInfo);
    w.loadExternalConfig(&cmdsToBeReady);
    w.cjt188_cmds_list = cmdsToBeReady;
    w.ResFileNm = RESFilename;
    if(cmdsToBeReady.count())
    {
        w.autoExe();
    }


    return a.exec();
}

