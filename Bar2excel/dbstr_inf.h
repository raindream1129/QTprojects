#ifndef DBSTR_INF_H
#define DBSTR_INF_H

#include <QWidget>

class dbstr_inf
{
private:
    QString      sMT_NUM  ;  //仪表编号
    QString      sCST_NUM ;  //客户号
    QString      sCST_NM  ;  //客户名
    QString      sOPN_NUM ;  //操作员号
    QString      sOPN_DT  ;  //操作日期
    QString      sMNT_NUM ;  //维护人员编号
    QString      sMNT_DT  ;  //维护日期
    QString      sRCD_ST  ;  //记录状态
    unsigned int iTMS     ;  //时间戳
    QString      sABSTRACT; //摘要
    QString      sRSV_FLD1; //备用字段1
    QString      sRSV_FLD2; //备用字段2
    QString      sRSV_FLD3; //备用字段3
    QString      sRSV_FLD4; //备用字段4

public:
    dbstr_inf();

    QString      getMT_NUM()const;       //仪表编号
    QString      getCST_NUM()const;      //客户号
    QString      getCST_NM()const;       //客户名
    QString      getOPN_NUM()const;      //操作员号
    QString      getOPN_DT()const;       //操作日期
    QString      getMNT_NUM()const;      //维护人员编号
    QString      getMNT_DT()const;       //维护日期
    QString      getRCD_ST()const;       //记录状态
    unsigned int getTMS()const;          //时间戳
    QString      getABSTRACT()const;     //摘要
    QString      getRSV_FLD1()const;     //备用字段1
    QString      getRSV_FLD2()const;     //备用字段2
    QString      getRSV_FLD3()const;     //备用字段3
    QString      getRSV_FLD4()const;     //备用字段4

    void setMT_NUM(const QString );    //仪表编号
    void setCST_NUM(const QString );   //客户号
    void setCST_NM(const QString );    //客户名
    void setOPN_NUM(const QString );   //操作员号
    void setOPN_DT(const QString );    //操作日期
    void setMNT_NUM(const QString );   //维护人员编号
    void setMNT_DT(const QString );    //维护日期
    void setRCD_ST(const QString );    //记录状态
    void setTMS(const unsigned int );  //时间戳
    void setABSTRACT(const QString );  //摘要
    void setRSV_FLD1(const QString );  //备用字段1
    void setRSV_FLD2(const QString );  //备用字段2
    void setRSV_FLD3(const QString );  //备用字段3
    void setRSV_FLD4(const QString );  //备用字段4
    dbstr_inf(QString      sMT_NUM  ,
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
               unsigned int iTMS=0
            );
    void clear()
    {
        sMT_NUM.clear();
        sCST_NUM.clear();
        sCST_NM.clear();
        sOPN_NUM.clear();
        sOPN_DT.clear();
        sMNT_NUM.clear();
        sMNT_DT.clear();
        sRCD_ST.clear();
        iTMS = 0;
        sABSTRACT.clear();
        sRSV_FLD1.clear();
        sRSV_FLD2.clear();
        sRSV_FLD3.clear();
        sRSV_FLD4.clear();
    }

};

#endif // DBSTR_INF_H
