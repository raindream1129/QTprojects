//#include <QCoreApplication>
#include <QApplication>
#include <fun.h>
#include <rdcfg.h>
#include<rdxml.h>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    RdCFG Read_file;
    Read_file.RdCom();
    RdXML RdXml;
    RdXml.read_xml();


    return a.exec();
}
