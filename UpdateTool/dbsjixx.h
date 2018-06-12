#ifndef DBSJIXX_H
#define DBSJIXX_H
#include <qwidget.h>

class TBL_BBSJIXX
{
private:
    QString 			sYIBOBH;//仪表编号
    QString				sRJBBNH;//软件版本号
    unsigned int		sSHJIJD;//升级进度
    QString				sSJKSDZ;//升级开始地址
    QString				sWEIHRQ;//维护日期
    unsigned int		sSHIJCH;//时间戳
    QString				sSHJIZT;//升级状态
    QString				sJILUZT;//记录状态
    QString				sBEIZD1;//备用字段1
    QString				sBEIZD2;//备用字段2
    QString				sBEIZD3;//备用字段3
    QString				sBEIZD4;//备用字段4


public:
    TBL_BBSJIXX();
    QString         getYIBOBH()const;
    QString		    getRJBBNH()const;
    unsigned int    getSHJIJD()const;
    QString		    getSJKSDZ()const;
    QString		    getWEIHRQ()const;
    unsigned int    getSHIJCH()const;
    QString		    getSHJIZT()const;
    QString		    getJILUZT()const;
    QString		    getBEIZD1()const;
    QString		    getBEIZD2()const;
    QString		    getBEIZD3()const;
    QString		    getBEIZD4()const;

    void    setYIBOBH(const QString);
    void    setRJBBNH(const QString);
    void    setSHJIJD(const unsigned int);
    void    setSJKSDZ(const QString);
    void    setWEIHRQ(const QString);
    void    setSHIJCH(const unsigned int);
    void    setSHJIZT(const QString);
    void    setJILUZT(const QString);
    void    setBEIZD1(const QString);
    void    setBEIZD2(const QString);
    void    setBEIZD3(const QString);
    void    setBEIZD4(const QString);

    TBL_BBSJIXX(QString sYIBOBH,QString	sRJBBNH,QString	sSJKSDZ,QString	sWEIHRQ,QString	sSHJIZT,QString	sJILUZT,QString	sBEIZD1,QString	sBEIZD2,QString	sBEIZD3,QString	sBEIZD4,unsigned int sSHJIJD=0,unsigned int sSHIJCH=0);
    void clear()

    {
        sYIBOBH.clear();
        sRJBBNH.clear();
        sSHJIJD = 0;
        sSJKSDZ.clear();
        sWEIHRQ.clear();
        sSHIJCH = 0;
        sSHJIZT.clear();
        sJILUZT.clear();
        sBEIZD1.clear();
        sBEIZD2.clear();
        sBEIZD3.clear();
        sBEIZD4.clear();
    }



};

#endif // DBSJIXX_H
