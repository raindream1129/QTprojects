#include "dbsjixx.h"

TBL_BBSJIXX::TBL_BBSJIXX()
{

}


QString TBL_BBSJIXX::getYIBOBH()const
{
    return sYIBOBH;
}
QString TBL_BBSJIXX::getRJBBNH()const
{
    return sRJBBNH;
}
unsigned int    TBL_BBSJIXX::getSHJIJD()const
{
    return sSHJIJD;
}
QString TBL_BBSJIXX::getSJKSDZ()const
{
    return sSJKSDZ;
}
QString TBL_BBSJIXX::getWEIHRQ()const
{
    return sWEIHRQ;
}
unsigned int    TBL_BBSJIXX::getSHIJCH()const
{
    return sSHIJCH;
}
QString TBL_BBSJIXX::getSHJIZT()const
{
    return sSHJIZT;
}
QString TBL_BBSJIXX::getJILUZT()const
{
    return sJILUZT;
}
QString TBL_BBSJIXX::getBEIZD1()const
{
    return sBEIZD1;
}
QString TBL_BBSJIXX::getBEIZD2()const
{
    return sBEIZD2;
}
QString TBL_BBSJIXX::getBEIZD3()const
{
    return sBEIZD3;
}
QString TBL_BBSJIXX::getBEIZD4()const
{
    return sBEIZD4;
}

void TBL_BBSJIXX::setYIBOBH(const QString sYIBOBH)
{
    this->sYIBOBH = sYIBOBH;

}

void TBL_BBSJIXX::setRJBBNH(const QString sRJBBNH)
{
    this->sRJBBNH = sRJBBNH;
}

void TBL_BBSJIXX::setSHJIJD(const unsigned int sSHJIJD)
{
    this->sSHJIJD = sSHJIJD;
}

void TBL_BBSJIXX::setSJKSDZ(const QString sSJKSDZ)
{
    this->sSJKSDZ = sSJKSDZ;
}

void TBL_BBSJIXX::setWEIHRQ(const QString sWEIHRQ)
{
    this->sWEIHRQ = sWEIHRQ;
}

void TBL_BBSJIXX::setSHIJCH(const unsigned int sSHIJCH)
{
    this->sSHIJCH = sSHIJCH;
}

void TBL_BBSJIXX::setSHJIZT(const QString sSHJIZT)
{
    this->sSHJIZT = sSHJIZT;
}

void TBL_BBSJIXX::setJILUZT(const QString sJILUZT)
{
    this->sJILUZT = sJILUZT;
}

void TBL_BBSJIXX::setBEIZD1(const QString sBEIZD1)
{
    this->sBEIZD1 = sBEIZD1;
}

void TBL_BBSJIXX::setBEIZD2(const QString sBEIZD2)
{
    this->sBEIZD2 = sBEIZD2;
}

void TBL_BBSJIXX::setBEIZD3(const QString sBEIZD3)
{
    this->sBEIZD3 = sBEIZD3;
}

void TBL_BBSJIXX::setBEIZD4(const QString sBEIZD4)
{
    this->sBEIZD4 = sBEIZD4;
}

TBL_BBSJIXX::TBL_BBSJIXX(QString sYIBOBH,QString	sRJBBNH,QString	sSJKSDZ,QString	sWEIHRQ,QString	sSHJIZT,QString	sJILUZT,QString	sBEIZD1,QString	sBEIZD2,QString	sBEIZD3,QString	sBEIZD4,unsigned int sSHJIJD,unsigned int sSHIJCH)
    :sYIBOBH(sYIBOBH),sRJBBNH(sRJBBNH),sSJKSDZ(sSJKSDZ),sWEIHRQ(sWEIHRQ),sSHJIZT(sSHJIZT),sJILUZT(sJILUZT),sBEIZD1(sBEIZD1),sBEIZD2(sBEIZD2),sBEIZD3(sBEIZD3),sBEIZD4(sBEIZD4),sSHJIJD(sSHJIJD),sSHIJCH(sSHIJCH)
{

}

