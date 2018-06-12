#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "common.h"
#include <qwidget.h>
#include "dbbnbxx.h"
#include <QSqlQuery>
#include "UdaoImp.h"
#include "cjt188_fio.h"
#include "cjt188_general.h"
#include <QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:

    void fillPortsInfo();//端口号
    void loadComSettings();
    void meterComOpen();
    void meterComClose();
    void meterComSend();
    void CmdExecution();
    void meterCmdResponseHandler();
    void logHandler(QString);
    void fillVersionInfo();//版本号
    int JudgeReptation();//判断是否重复加载
    quint8 AddCheckCode(quint16 ChenckBuff[256],int );//校验码
    void AddToBBBNBXX(vector<TBL_BBNBXX> stTBLs);
    void SendUpdatePackage();
    void ChangeVersion();
    void InsertUpgrade(CJT188Obj stCJT188obj);
    void upBSHIXX(TBL_BBSJIXX);
    void SaveCMD(QStringList);
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

    void meterRecvData();

    void on_BtnConn_clicked();

    void on_CBBaudMeter_currentTextChanged(const QString &arg1);

    void on_ChooseFlBtn_clicked();

    void on_LoadBtn_clicked();

    void on_UpdatingBtn_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_VersionComb_currentTextChanged(const QString &arg1);

    void on_VerCheckBTN_clicked();

    void on_RunNewVerBTN_clicked();

    void ResvTimeOut();

    void ReadyUpgrade();

private:

    QSerialPort     *meterCom;
    SerialInfo      meterComInfo;
    QTimer          *meterRecvTimer;
    QTimer          *meterPollTimer;
    QByteArray      meterRecvArr;
    unsigned char   meterRecvBuff[UART_BUFFER_MAX];
    unsigned char   meterSendBuff[UART_BUFFER_MAX];
    int             meterRecvBuffLen;
    int             meterSendBuffLen;
    Routine         meterRoutine;
    bool            isMeterPulseOn;

    bool            IfGoOnUpdate;

    QString Version;    //待入库的版本号
    QString versionDEV; //仪表升级的版本
    QString Filename;   //文件名
    quint16 iXUHAOO;    //表序号自增
    quint16 iSer;       //
    QString dir;

    QString AddrBegin;//开始地址，更新升级进度表
    int iSeriosUpAll; //版本库条目数(计算升级进度时(序号+1)/总条目数)

    CJT188Obj cjt188obj;
    vector<TBL_BBNBXX> vBBNBXXs;
    vector<TBL_BBNBXX>::iterator it;
    Ui::Widget *ui;
};

#endif // WIDGET_H
