#include "dbbnbxx.h"

TBL_BBNBXX::TBL_BBNBXX()
{

}

QString TBL_BBNBXX::getRJBBNH()const
{
    return sRJBBNH;
}
QString TBL_BBNBXX::getSHUJCD()const
{
    return sSHUJCD;
}
QString  TBL_BBNBXX::getDIZHIH()const
{
    return sDIZHIH;

}
QString  TBL_BBNBXX::getSHJUNR()const
{
    return sSHJUNR;
}
QString  TBL_BBNBXX::getJIAOYM()const
{
    return sJIAOYM;
}
QString  TBL_BBNBXX::getJILUZT()const
{
    return sJILUZT;
}
quint16 TBL_BBNBXX::getXUHAOO()const
{
    return iXUHAOO;
}
QString  TBL_BBNBXX::getBANBRQ()const
{
    return sBANBRQ;
}
unsigned int TBL_BBNBXX::getSHIJCH()const
{
    return iSHIJCH;
}
QString  TBL_BBNBXX::getZHAIYY()const
{
    return sZHAIYY;
}
QString  TBL_BBNBXX::getBEIZD1()const
{
    return sBEIZD1;
}
QString  TBL_BBNBXX::getBEIZD2()const
{
    return sBEIZD2;

}
QString  TBL_BBNBXX::getBEIZD3()const
{
    return sBEIZD3;

}
QString  TBL_BBNBXX::getBEIZD4()const
{
    return sBEIZD4;
}

void TBL_BBNBXX::setRJBBNH(const QString sRJBBNH)
{
    this->sRJBBNH = sRJBBNH;
}

void TBL_BBNBXX::setSHUJCD(const QString sSHUJCD)
{
    this->sSHUJCD = sSHUJCD;
}

void TBL_BBNBXX::setDIZHIH(const QString sDIZHIH)
{
    this->sDIZHIH = sDIZHIH;
}

void TBL_BBNBXX::setSHJUNR(const QString sSHJUNR)
{
    this->sSHJUNR = sSHJUNR;
}

void TBL_BBNBXX::setJIAOYM(const QString sJIAOYM)
{
    this->sJIAOYM = sJIAOYM;
}

void TBL_BBNBXX::setJILUZT(const QString sJILUZT)
{
    this->sJILUZT = sJILUZT;
}

void TBL_BBNBXX::setXUHAOO(const quint16 iXUHAOO)
{
    this->iXUHAOO = iXUHAOO;
}

void TBL_BBNBXX::setBANBRQ(const QString sBANBRQ)
{
    this->sBANBRQ = sBANBRQ;
}

void TBL_BBNBXX::setSHIJCH(const unsigned int iSHIJCH)
{
    this->iSHIJCH = iSHIJCH;
}

void TBL_BBNBXX::setZHAIYY(const QString sZHAIYY)
{
    this->sZHAIYY = sZHAIYY;
}

void TBL_BBNBXX::setBEIZD1(const QString sBEIZD1)
{
    this->sBEIZD1 = sBEIZD1;
}

void TBL_BBNBXX::setBEIZD2(const QString sBEIZD2)
{
    this->sBEIZD2 = sBEIZD2;
}

void TBL_BBNBXX::setBEIZD3(const QString sBEIZD3)
{
    this->sBEIZD3 = sBEIZD3;
}

void TBL_BBNBXX::setBEIZD4(const QString sBEIZD4)
{
    this->sBEIZD4 = sBEIZD4;
}




TBL_BBNBXX::TBL_BBNBXX(QString sRJBBNH,QString sSHUJCD,QString sDIZHIH,QString sSHJUNR,QString sJIAOYM,QString sJILUZT,QString sBANBRQ,QString sZHAIYY,QString sBEIZD1,QString sBEIZD2,QString sBEIZD3,QString sBEIZD4,quint16 iXUHAOO,unsigned int iSHIJCH)
    :sRJBBNH(sRJBBNH),sSHUJCD(sSHUJCD),sDIZHIH(sDIZHIH),sSHJUNR(sSHJUNR),sJIAOYM(sJIAOYM),sJILUZT(sJILUZT),sBANBRQ(sBANBRQ),sZHAIYY(sZHAIYY),sBEIZD1(sBEIZD1),sBEIZD2(sBEIZD2),sBEIZD3(sBEIZD3),sBEIZD4(sBEIZD4),iXUHAOO(iXUHAOO),iSHIJCH(iSHIJCH)
{

}

