#ifndef RDXML_H
#define RDXML_H

#include <QWidget>
#include <QXmlStreamReader>
class RdXML : public QWidget
{
    Q_OBJECT
public:
    explicit RdXML(QWidget *parent = 0);

    void read_xml();

private:
    QXmlStreamReader reader;

    void readindexElement();

    void readAddressElement();



signals:

public slots:
};

#endif // RDXML_H
