#include "dbstr_inf.h"

dbstr_inf::dbstr_inf()
{

}

QString      dbstr_inf::getMT_NUM()const       //仪表编号
{
    return sMT_NUM;
}
QString      dbstr_inf::getCST_NUM()const      //客户号
{
    return sCST_NUM;
}
QString      dbstr_inf::getCST_NM()const       //客户名
{
    return sCST_NM;
}
QString      dbstr_inf::getOPN_NUM()const      //操作员号
{
    return sOPN_NUM;
}
QString      dbstr_inf::getOPN_DT()const       //操作日期
{
    return sOPN_DT;
}
QString      dbstr_inf::getMNT_NUM()const      //维护人员编号
{
    return sMNT_NUM;
}
QString      dbstr_inf::getMNT_DT()const       //维护日期
{
    return sMNT_DT;
}
QString      dbstr_inf::getRCD_ST()const       //记录状态
{
    return sRCD_ST;
}
unsigned int dbstr_inf::getTMS()const          //时间戳
{
    return iTMS;
}
QString      dbstr_inf::getABSTRACT()const     //摘要
{
    return sABSTRACT;
}
QString      dbstr_inf::getRSV_FLD1()const     //备用字段1
{
    return sRSV_FLD1;
}
QString      dbstr_inf::getRSV_FLD2()const     //备用字段2
{
    return sRSV_FLD2;
}
QString      dbstr_inf::getRSV_FLD3()const     //备用字段3
{
    return sRSV_FLD3;
}
QString      dbstr_inf::getRSV_FLD4()const     //备用字段4
{
    return sRSV_FLD4;
}

void dbstr_inf::setMT_NUM(const QString   sMT_NUM  ){
    this->sMT_NUM = sMT_NUM;
}
void dbstr_inf::setCST_NUM(const QString  sCST_NUM ){
    this->sCST_NUM = sCST_NUM;
}
void dbstr_inf::setCST_NM(const QString   sCST_NM  ){
    this->sCST_NM = sCST_NM;
}
void dbstr_inf::setOPN_NUM(const QString  sOPN_NUM ){
    this->sOPN_NUM = sOPN_NUM;
}
void dbstr_inf::setOPN_DT(const QString   sOPN_DT  ){
    this->sOPN_DT = sOPN_DT;
}
void dbstr_inf::setMNT_NUM(const QString  sMNT_NUM ){
    this->sMNT_NUM = sMNT_NUM;
}
void dbstr_inf::setMNT_DT(const QString   sMNT_DT  ){
    this->sMNT_DT = sMNT_DT;
}
void dbstr_inf::setRCD_ST(const QString   sRCD_ST  ){
    this->sRCD_ST = sRCD_ST;
}
void dbstr_inf::setTMS(const unsigned int iTMS     ){
    this->iTMS = iTMS;
}
void dbstr_inf::setABSTRACT(const QString sABSTRACT){
    this->sABSTRACT = sABSTRACT;
}
void dbstr_inf::setRSV_FLD1(const QString sRSV_FLD1){
    this->sRSV_FLD1 = sRSV_FLD1;
}
void dbstr_inf::setRSV_FLD2(const QString sRSV_FLD2){
    this->sRSV_FLD2 = sRSV_FLD2;
}
void dbstr_inf::setRSV_FLD3(const QString sRSV_FLD3){
    this->sRSV_FLD3 = sRSV_FLD3;
}
void dbstr_inf::setRSV_FLD4(const QString sRSV_FLD4){
    this->sRSV_FLD4 = sRSV_FLD4;
}
dbstr_inf::dbstr_inf(QString      sMT_NUM  ,
           QString      sCST_NUM ,
           QString      sCST_NM  ,
           QString      sOPN_NUM ,
           QString      sOPN_DT  ,
           QString      sMNT_NUM ,
           QString      sMNT_DT  ,
           QString      sRCD_ST  ,
           QString      sABSTRACT,
           QString      sRSV_FLD1,
           QString      sRSV_FLD2,
           QString      sRSV_FLD3,
           QString      sRSV_FLD4,
           unsigned int iTMS
        )
    :sMT_NUM  (sMT_NUM  ),
     sCST_NUM (sCST_NUM ),
     sCST_NM  (sCST_NM  ),
     sOPN_NUM (sOPN_NUM ),
     sOPN_DT  (sOPN_DT  ),
     sMNT_NUM (sMNT_NUM ),
     sMNT_DT  (sMNT_DT  ),
     sRCD_ST  (sRCD_ST  ),
     sABSTRACT(sABSTRACT),
     sRSV_FLD1(sRSV_FLD1),
     sRSV_FLD2(sRSV_FLD2),
     sRSV_FLD3(sRSV_FLD3),
     sRSV_FLD4(sRSV_FLD4),
     iTMS(iTMS)
{

}
