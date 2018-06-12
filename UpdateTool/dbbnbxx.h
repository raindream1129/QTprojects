#ifndef DBBNBXX_H
#define DBBNBXX_H
#include <qwidget.h>

class TBL_BBNBXX
{
private:
    QString      sRJBBNH;
    QString      sSHUJCD;
    QString      sDIZHIH;
    QString      sSHJUNR;
    QString      sJIAOYM;
    QString      sJILUZT;
    quint16      iXUHAOO;
    QString      sBANBRQ;
    unsigned int iSHIJCH;
    QString      sZHAIYY;
    QString      sBEIZD1;
    QString      sBEIZD2;
    QString      sBEIZD3;
    QString      sBEIZD4;

public:
    TBL_BBNBXX();
    QString      getRJBBNH()const;//软件版本号
    QString      getSHUJCD()const;//数据长度
    QString      getDIZHIH()const;//地址
    QString      getSHJUNR()const;//数据内容
    QString      getJIAOYM()const;//校验码
    QString      getJILUZT()const;//记录状态
    quint16      getXUHAOO()const;//序号
    QString      getBANBRQ()const;//版本登记日期
    unsigned int getSHIJCH()const;//时间戳
    QString      getZHAIYY()const;//摘要信息
    QString      getBEIZD1()const;//备用字段
    QString      getBEIZD2()const;
    QString      getBEIZD3()const;
    QString      getBEIZD4()const;

    void setRJBBNH(const QString );
    void setSHUJCD(const QString );
    void setDIZHIH(const QString );
    void setSHJUNR(const QString );
    void setJIAOYM(const QString );
    void setJILUZT(const QString );
    void setXUHAOO(const quint16 );
    void setBANBRQ(const QString );
    void setSHIJCH(const unsigned int );
    void setZHAIYY(const QString );
    void setBEIZD1(const QString );
    void setBEIZD2(const QString );
    void setBEIZD3(const QString );
    void setBEIZD4(const QString );
    TBL_BBNBXX(QString sRJBBNH,QString sSHUJCD,QString sDIZHIH,QString sSHJUNR,QString sJIAOYM,QString sJILUZT,QString sBANBRQ,QString sZHAIYY,QString sBEIZD1,QString sBEIZD2,QString sBEIZD3,QString sBEIZD4,quint16 iXUHAOO=0,unsigned int iSHIJCH=0);

};

#endif // DBBNBXX_H
