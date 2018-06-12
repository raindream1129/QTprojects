#include "rdxml.h"
//#include <QDomDocument>
#include <writeLog.h>
#include <QFile>
#include <QDebug>
#include "common.h"
#include <QStringRef>
#include "cjt188_general.h"
#include "cjt188_fio.h"

RdXML::RdXML(QWidget *parent) : QWidget(parent)
{

}

void RdXML::read_xml(QList<Cjt188Object> *cmdsToBeReady,QString XmlFilename)
{
    Cjt188Object cjt188Obj;

    QFile xmlfile(XmlFilename);
    if(xmlfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        reader.setDevice(&xmlfile);
        while (!reader.atEnd())
        {
            cjt188Obj.clear();
            if (reader.isStartElement())
            {
                if (reader.name() == "root")
                {
                    readindexElement(&cjt188Obj,cmdsToBeReady);
                    reader.readNext();
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
        qDebug()<<"打开XML配置文件失败";
        xmlfile.close();
        exit(1);
    }
    xmlfile.close();
}

void RdXML::readindexElement(Cjt188Object* cjt188Obj,QList<Cjt188Object> *cmdsToBeReady)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "root");
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "Address")
            {
                readAddressElement(cjt188Obj);
                reader.readNext();
            }
            else if(reader.name() == "GetRequest")
            {
                readGetRequest(cjt188Obj,cmdsToBeReady);
                reader.readNext();
            }
            else if(reader.name() == "SetRequest")
            {
                readSetRequest(cjt188Obj,cmdsToBeReady);
                reader.readNext();
            }
            else{
                //skipUnknownElement();
                reader.readNext();
            }
        } else {
            reader.readNext();
        }
    }
}

void RdXML::readAddressElement(Cjt188Object* cjt188Obj)
{
    cjt188Obj->address = reader.attributes().value("Value").toString();
    //qDebug()<<reader.attributes().value("Value").toString();
    reader.readNext();

}

void RdXML::readGetRequest(Cjt188Object* cjt188Obj,QList<Cjt188Object> *cmdsToBeReady)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "GetRequest");
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }
        if (reader.isStartElement())
        {
            if (reader.name() == "AttributeDescriptor")
            {
                readDesc(cjt188Obj);
                reader.readNext();
            }
            else if(reader.name() == "Value")
            {
                ReadValue(cjt188Obj);

                reader.readNext();

            }
            else{
                reader.readNext();
            }
        }
        else{
            reader.readNext();
        }
    }
    cmdsToBeReady->append(*cjt188Obj);
    cjt188Obj->clear();

}
void RdXML::readSetRequest(Cjt188Object* cjt188Obj,QList<Cjt188Object> *cmdsToBeReady)
{
    //qDebug()<<"Read_set";
    Q_ASSERT(reader.isStartElement() && reader.name() == "SetRequest");
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "AttributeDescriptor")
            {
                readDesc(cjt188Obj);
                reader.readNext();
            }
            else if(reader.name() == "Value")
            {
                ReadValue(cjt188Obj);


                reader.readNext();

            }
            else{
                reader.readNext();
            }

        }
        else{
            reader.readNext();
        }

    }
    cmdsToBeReady->append(*cjt188Obj);
    cjt188Obj->clear();
}


void RdXML::readDesc(Cjt188Object *cjt188Obj)
{
    cjt188Obj->desc = reader.attributes().value("Descr").toString();

    //qDebug()<<reader.attributes().value("Descr").toString();
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
             if(reader.name() == "ctrlId")
             {
                readctrlId(cjt188Obj);
                reader.readNext();
             }
             else if(reader.name() == "flagId")
             {
                 readflagId(cjt188Obj);
             }
             else{
                 reader.readNext();
             }
        }
        else{
            reader.readNext();
        }

    }
    reader.readNext();
}

void RdXML::readctrlId(Cjt188Object*cjt188Obj)
{
    bool *ok=0;
    cjt188Obj->ctrlId = reader.attributes().value("Value").toUInt(ok,0);
   // qDebug()<<reader.attributes().value("Value").toInt();
    reader.readNext();

}

void RdXML::readflagId(Cjt188Object*cjt188Obj)
{
    bool *ok=0;
    cjt188Obj->flagId = reader.attributes().value("Value").toUInt(ok,0);
    //qDebug()<<reader.attributes().value("Value").toUInt(ok,0);
    reader.readNext();
}

void RdXML::ReadValue(Cjt188Object*cjt188Obj)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "Value");
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            qDebug()<<reader.name();
            if (reader.name() == "BCD" || reader.name() == "U8" || reader.name() == "U16"
                    || reader.name() == "U32")
            {
                cjt188Obj->value = reader.attributes().value("Value").toString();
                reader.readNext();
            }
            else{
                reader.readNext();
            }

        }
        else{
            reader.readNext();
        }

    }

    reader.readNext();
}

