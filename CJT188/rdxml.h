#ifndef RDXML_H
#define RDXML_H


#include "cjt188_general.h"
#include "cjt188_fio.h"
#include <QWidget>
#include <QXmlStreamReader>
class RdXML : public QWidget
{
    Q_OBJECT
public:
    explicit RdXML(QWidget *parent = 0);

    void read_xml(QList<Cjt188Object> *,QString);

private:
    QXmlStreamReader reader;

    void readindexElement(Cjt188Object*,QList<Cjt188Object> *v);

    void readAddressElement(Cjt188Object*);

    void readGetRequest(Cjt188Object*,QList<Cjt188Object> *);

    void readSetRequest(Cjt188Object*,QList<Cjt188Object> *);

    void readDesc(Cjt188Object*);

    void readctrlId(Cjt188Object*);

    void readflagId(Cjt188Object*);

    void ReadValue(Cjt188Object*cjt188Obj);

    void InsertObj(Cjt188Object*);





signals:

public slots:
};

#endif // RDXML_H
