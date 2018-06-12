#include "rdcfg.h"

#include "QFileDialog"
#include <QtCore/QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>

#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "fun.h"

RdCFG::RdCFG(QWidget *parent) : QWidget(parent)
{

}

int RdCFG::RdCom()
{
    QFile file("config.conf");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream Rdfl(&file);
        while (!Rdfl.atEnd())
        {
            if("[COM]" == Rdfl.readLine())
            {
                MTCOMM = Rdfl.readLine().section('=',1,1);
                qDebug()<<"端口:"<<MTCOMM;
                file.close();
                break;
            }
        }
    }
    else
    {
        qDebug()<<"端口配置文件打开失败";
        file.close();
        return 1;
    }
return 0;
}

