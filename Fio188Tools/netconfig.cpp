#include "netconfig.h"
#include "ui_netconfig.h"
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include "cjt188_fio.h"
#include "cjt188_general.h"
#include <windows.h>

//IP地址转换为字符串
QString NetConfig::IPtoString(QString IPAddress)
{
    QString IPAddr[4];
    int IPAdd[4];
    IPAdd[0] = IPAddress.section(".",0,0).toInt();
    IPAdd[1] = IPAddress.section(".",1,1).toInt();
    IPAdd[2] = IPAddress.section(".",2,2).toInt();
    IPAdd[3] = IPAddress.section(".",3,3).toInt();

    if(IPAdd[0] != 0 || IPAdd[1] != 0 || IPAdd[2] != 0 || IPAdd[3] != 0)
        IPChanged = 1;
    if(IPAdd[0] > 255 || IPAdd[1] > 255 || IPAdd[2] >255 || IPAdd[3] > 255)
        IPFalg = 1;


    IPAddr[0] = QString("%1").arg(IPAdd[0],2,16,QLatin1Char('0'));
    IPAddr[1] = QString("%1").arg(IPAdd[1],2,16,QLatin1Char('0'));
    IPAddr[2] = QString("%1").arg(IPAdd[2],2,16,QLatin1Char('0'));
    IPAddr[3] = QString("%1").arg(IPAdd[3],2,16,QLatin1Char('0'));

    return IPAddr[0]+IPAddr[1]+IPAddr[2]+IPAddr[3];
}
//端口转换成16进制 高低位互换
QString NetConfig::PORTtostring(QString PORTAddress)
{
    int PORTAdd = PORTAddress.toInt();
    if(PORTAdd != 0)
        portChanged = 1;
    if(PORTAdd > 65535)
        PortFlag = 1;

    QString Portid = QString("%1").arg(PORTAdd,4,16,QLatin1Char('0'));
    return Portid.mid(2,2) + Portid.mid(0,2);
}


NetConfig::NetConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetConfig)
{
    ui->setupUi(this);

    IPFalg = 0;
    PortFlag = 0;
    IPChanged = 0;
    portChanged = 0;
    QRegExp ipRegExp = QRegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){4}");
    QRegExpValidator *ipRegExpValidator = new QRegExpValidator(ipRegExp, this);
    ui->LEIP1->setValidator(ipRegExpValidator);
    ui->LEIP1->setInputMask("000.000.000.000; ");

    ui->LEIP2->setValidator(ipRegExpValidator);
    ui->LEIP2->setInputMask("000.000.000.000; ");

    ui->LEIP3->setValidator(ipRegExpValidator);
    ui->LEIP3->setInputMask("000.000.000.000; ");

    ui->LEIP4->setValidator(ipRegExpValidator);
    ui->LEIP4->setInputMask("000.000.000.000; ");

    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()),
            this, SLOT(TTimeout()));
    i = 0;
}

NetConfig::~NetConfig()
{
    delete ui;
}

//确定按钮发送信号
void NetConfig::on_NETBTN_clicked()
{
    Timer->start(300);

}

void NetConfig::TTimeout()
{
    QString IPAddrApp = ui->LEIP1->text();
    QString PortApp = ui->LEPT1->text();
    QString IPAddrBackup = ui->LEIP2->text();
    QString PortBackup = ui->LEPT1->text();
    QString IPAddrUpgrade = ui->LEIP3->text();
    QString PortUpgrade = ui->LEPT1->text();
    QString IPAddrPlatform = ui->LEIP4->text();
    QString PortPlatform = ui->LEPT1->text();
    switch(i)
    {
    case 0:
    {
        QString ValueApp = IPtoString(IPAddrApp) + PORTtostring(PortApp);
        if(IPChanged)
        {
            cjt188ob_tmp.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
            cjt188ob_tmp.dataId = CJT188_FIO_OBJ_ID_APP_ADDR;
            cjt188ob_tmp.value = ValueApp;
            IPChanged = 0;
            portChanged = 0;
            emit NetCfgSet(cjt188ob_tmp);
            cjt188ob_tmp.clear();
        }
        break;
    }
    case 1:
    {
        QString ValueBackup = IPtoString(IPAddrBackup) + PORTtostring(PortBackup);
        if(IPChanged)
        {
            cjt188ob_tmp.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
            cjt188ob_tmp.dataId = CJT188_FIO_OBJ_ID_BACKUP_ADDR;
            cjt188ob_tmp.value = ValueBackup;
            IPChanged = 0;
            portChanged = 0;
            emit NetCfgSet(cjt188ob_tmp);
            cjt188ob_tmp.clear();
        }
        break;
    }
//    case 2:
//    {
//        QString ValueUpgrade = IPtoString(IPAddrUpgrade) + PORTtostring(PortUpgrade);
//        if(IPChanged)
//        {
//            cjt188ob_tmp.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
//            cjt188ob_tmp.dataId = CJT188_FIO_OBJ_ID_UPGRADE_ADDR;
//            cjt188ob_tmp.value = ValueUpgrade;
//            IPChanged = 0;
//            portChanged = 0;
//            emit NetCfgSet(cjt188ob_tmp);
//            cjt188ob_tmp.clear();
//        }
//        break;
//    }
//    case 3:
//    {
//        QString ValuePlatform = IPtoString(IPAddrPlatform) + PORTtostring(PortPlatform);
//        if(IPChanged)
//        {
//            cjt188ob_tmp.ctrlId = CJT188_FIO_CTRL_ID_CMD_WR_DATA;
//            cjt188ob_tmp.dataId = CJT188_FIO_OBJ_ID_PLATFORM_ADDR;
//            cjt188ob_tmp.value = ValuePlatform;
//            IPChanged = 0;
//            portChanged = 0;
//            emit NetCfgSet(cjt188ob_tmp);
//            cjt188ob_tmp.clear();
//        }
//        break;
//    }
    default:
    {
        Timer->stop();
        i = 0;
        break;
    }
    }
    i++;
}
