#include "rdxml.h"
#include <QDomDocument>
#include <rdcfg.h>
#include <QFile>
#include <QDebug>
#include "fun.h"




RdXML::RdXML(QWidget *parent) : QWidget(parent)
{

}

void RdXML::read_xml()
{
    QFile xmlfile("config.xml");
    if(xmlfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        reader.setDevice(&xmlfile);
        while (!reader.atEnd())
        {
                if (reader.isStartElement())
                {
                    if (reader.name() == "root") {
                        readindexElement();
                        qDebug()<<"read ok";
                    } else {
                        reader.raiseError(tr("Not a root file"));
                    }
                } else {
                    reader.readNext();
                }
        }
    }
    else
    {
        qDebug()<<"打开配置文件失败";
        xmlfile.close();
        exit(1);
    }
}

void RdXML::readindexElement()
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "root");
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "Address") {
                readAddressElement();
            } else {
                //skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }
}

void RdXML::readAddressElement()
{
    qDebug()<<reader.attributes().value("Value").toString();
/*
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            if (reader.name() == "entry") {
                readEntryElement(item);
            } else if (reader.name() == "page") {
                readPageElement(item);
            } else {
                skipUnknownElement();
            }
        } else {
            reader.readNext();
        }
    }*/
}




