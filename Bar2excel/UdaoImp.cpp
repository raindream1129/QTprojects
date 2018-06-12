#include "UdaoImp.h"
#include "DBHelper.h"
#include <QSqlQuery>
#include<QVariant>
#include <vector>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "dbstr_inf.h"
#include "common.h"
using namespace std;

UdaoImp::UdaoImp()
{

}

/*********************************************
 * 添加一台表
 *insert into
 *
 * ******************************************/
bool UdaoImp::inserterMt(const dbstr_inf& stdbstr_inf)
{
        QSqlQuery query;
        query.prepare("insert into bstr_inf(mt_num,cst_num,cst_nm,opn_num,opn_dt,mnt_num,mnt_dt,rcd_st,"
                      "tms,abstract,rsv_fld1,rsv_fld2,rsv_fld3,rsv_fld4)"
                      "values(:mt_num,:cst_num,:cst_nm,:opn_num,:opn_dt,:mnt_num,:mnt_dt,:rcd_st,"
                      ":tms,:abstract,:rsv_fld1,:rsv_fld2,:rsv_fld3,:rsv_fld4);");
        query.bindValue(":mt_num",  stdbstr_inf.getMT_NUM());
        query.bindValue(":cst_num", stdbstr_inf.getCST_NUM());
        query.bindValue(":cst_nm",  stdbstr_inf.getCST_NM());
        query.bindValue(":opn_num", stdbstr_inf.getOPN_NUM());
        query.bindValue(":opn_dt",  stdbstr_inf.getOPN_DT());
        query.bindValue(":mnt_num", stdbstr_inf.getMNT_NUM());
        query.bindValue(":mnt_dt",  stdbstr_inf.getMNT_DT());
        query.bindValue(":rcd_st",  stdbstr_inf.getRCD_ST());
        query.bindValue(":tms",     stdbstr_inf.getTMS());
        query.bindValue(":abstract",stdbstr_inf.getABSTRACT());
        query.bindValue(":rsv_fld1",stdbstr_inf.getRSV_FLD1());
        query.bindValue(":rsv_fld2",stdbstr_inf.getRSV_FLD2());
        query.bindValue(":rsv_fld3",stdbstr_inf.getRSV_FLD3());
        query.bindValue(":rsv_fld4",stdbstr_inf.getRSV_FLD4());
        if(!query.exec())
        {
           qDebug()<< query.lastError();
           return FAIL;
        }
        return SUCCESS;
    //    helper->destoryConn();
}

//删除一台表
void UdaoImp::deleteMt(const QString sLDN)
{
    QSqlQuery query;
    query.prepare("delete form bstr_inf where mt_num=:mt_num);");

    query.bindValue(":mt_num",sLDN);
    query.exec();
}
//维护表数据
void UdaoImp::maintainMt(const dbstr_inf& stdbstr_inf)
{
    QSqlQuery query;
    query.prepare("update bstr_inf set cst_num=:cst_num,cst_nm=:cst_nm,opn_num=:opn_num,opn_dt=:opn_dt,mnt_num=:mnt_num,mnt_dt=:mnt_dt,"
                  "tms=:tms,abstract=:abstract,rsv_fld1=:rsv_fld1,rsv_fld2=:rsv_fld2,rsv_fld3=:rsv_fld3,rsv_fld4=:rsv_fld3 "
                  "where mt_num=:mt_num and rcd_st=:rcd_st);");
    query.bindValue(":mt_num",  stdbstr_inf.getMT_NUM());
    query.bindValue(":cst_num", stdbstr_inf.getCST_NUM());
    query.bindValue(":cst_nm",  stdbstr_inf.getCST_NM());
    query.bindValue(":opn_num", stdbstr_inf.getOPN_NUM());
    query.bindValue(":opn_dt",  stdbstr_inf.getOPN_DT());
    query.bindValue(":mnt_num", stdbstr_inf.getMNT_NUM());
    query.bindValue(":mnt_dt",  stdbstr_inf.getMNT_DT());
    query.bindValue(":rcd_st",  stdbstr_inf.getRCD_ST());
    query.bindValue(":tms",     stdbstr_inf.getTMS());
    query.bindValue(":abstract",stdbstr_inf.getABSTRACT());
    query.bindValue(":rsv_fld1",stdbstr_inf.getRSV_FLD1());
    query.bindValue(":rsv_fld2",stdbstr_inf.getRSV_FLD2());
    query.bindValue(":rsv_fld3",stdbstr_inf.getRSV_FLD3());
    query.bindValue(":rsv_fld4",stdbstr_inf.getRSV_FLD4());
    query.exec();
}

//查询表数据
dbstr_inf UdaoImp::selectMt(const dbstr_inf& stdbstr_inf)
{
    QSqlQuery query;
    query.prepare("select * from bstr_inf where mt_num=:mt_num and rcd_st=:rcd_st");
    query.bindValue(":mt_num",  stdbstr_inf.getMT_NUM());
    query.bindValue(":rcd_st",  stdbstr_inf.getRCD_ST());
    query.exec();
    QString sMT_NUM     = query.value(0).toString();     //仪表编号
    QString sCST_NUM    = query.value(1).toString();     //客户号
    QString sCST_NM     = query.value(2).toString();     //客户名
    QString sOPN_NUM    = query.value(3).toString();     //操作员号
    QString sOPN_DT     = query.value(4).toString();     //操作日期
    QString sMNT_NUM    = query.value(5).toString();     //维护人员编号
    QString sMNT_DT     = query.value(6).toString();     //维护日期
    QString sRCD_ST     = query.value(7).toString();     //记录状态
    int iTMS            = query.value(8).toInt();        //时间戳
    QString sABSTRACT   = query.value(9).toString();    //摘要
    QString sRSV_FLD1   = query.value(10).toString();   //备用字段1
    QString sRSV_FLD2   = query.value(11).toString();   //备用字段2
    QString sRSV_FLD3   = query.value(12).toString();   //备用字段3
    QString sRSV_FLD4   = query.value(13).toString();   //备用字段4
    dbstr_inf(sMT_NUM  ,
               sCST_NUM ,
               sCST_NM  ,
               sOPN_NUM ,
               sOPN_DT  ,
               sMNT_NUM ,
               sMNT_DT  ,
               sRCD_ST  ,
               sABSTRACT,
               sRSV_FLD1,
               sRSV_FLD2,
               sRSV_FLD3,
               sRSV_FLD4,
               iTMS
            );

}

/*

//select rjbbnh from BBnbxx group by rjbbnh;
//选择所有版本号
QList<QString> UdaoImp::selectAllVersion()
{
    DBHelper *helper = DBHelper::getInstance();
    QList<QString> Versions;
    helper->createConn();
    QSqlQuery query;
    query.exec("select rjbbnh from BBNBXX where jiluzt = '0' group by rjbbnh;");
    while(query.next())
    {
        QString version = query.value(0).toString();
        Versions.append(version);
    }
    helper->destoryConn();
    return Versions;
}
//选择某版本的所有数据
//select * from BBnbxx where rjbbnh=rjbbnh;
vector<TBL_BBNBXX> UdaoImp::selectAllDateOfSmVersion(const TBL_BBNBXX& stBBNBXX)
{
    DBHelper *helper = DBHelper::getInstance();
    vector<TBL_BBNBXX>vcBBNBXXs;
    helper->createConn();
    QSqlQuery query;
    query.exec("BEGIN");
    query.prepare("select * from BBnbxx where jiluzt = '0' and rjbbnh = :rjbbnh");
    query.bindValue(":rjbbnh",stBBNBXX.getRJBBNH());
    query.exec();
    while(query.next())
    {
        QString sRJBBNH = query.value(0).toString();
        QString sSHUJCD = query.value(1).toString();
        QString sDIZHIH = query.value(2).toString();
        QString sSHJUNR = query.value(3).toString();
        QString sJIAOYM = query.value(4).toString();
        QString sJILUZT = query.value(5).toString();
        quint16 iXUHAOO = query.value(6).toInt();
        QString sBANBRQ = query.value(7).toString();
        unsigned int iSHIJCH = query.value(8).toInt();
        QString sZHAIYY = query.value(9).toString();
        QString sBEIZD1 = query.value(10).toString();
        QString sBEIZD2 = query.value(11).toString();
        QString sBEIZD3 = query.value(12).toString();
        QString sBEIZD4 = query.value(13).toString();
        TBL_BBNBXX stBBNBXX_tmp(sRJBBNH,sSHUJCD,sDIZHIH,sSHJUNR,sJIAOYM,sJILUZT,sBANBRQ,sZHAIYY,sBEIZD1,sBEIZD2,sBEIZD3,sBEIZD4,iXUHAOO,iSHIJCH);
        vcBBNBXXs.push_back(stBBNBXX_tmp);
    }

    query.exec("COMMIT");
    helper->destoryConn();

    return vcBBNBXXs;
}
//选择版本条目数(判断是否已经加入版本库)
//select rjbbnh,beizd1 from BBnbxx group by rjbbnh,beizd1;
int UdaoImp::selectCountVersion(const TBL_BBNBXX& stBBNBXX)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("select count(*) from BBnbxx where jiluzt = '0' and rjbbnh = :rjbbnh and beizd1 = :beizd1");
    query.bindValue(":rjbbnh",stBBNBXX.getRJBBNH());
    query.bindValue(":beizd1",stBBNBXX.getBEIZD1());
    query.exec();
    query.next();
    int Num = query.value(0).toInt();
    return Num;
}
//版本入库
//insert
void UdaoImp::inserterVersion(const TBL_BBNBXX& stBBNBXX)
{
//    DBHelper *helper = DBHelper::getInstance();
//    helper->createConn();
    QSqlQuery query;
    query.prepare("insert into BBNBXX(rjbbnh,shujcd,dizhih,shjunr,jiaoym,jiluzt,xuhaoo,banbrq,"
                  "shijch,zhaiyy,beizd1,beizd2,beizd3,beizd4)"
                  "values(:rjbbnh,:shujcd,:dizhih,:shjunr,:jiaoym,:jiluzt,"
                  ":xuhaoo,:banbrq,:shijch,:zhaiyy,:beizd1,:beizd2,:beizd3,:beizd4);");
    query.bindValue(":rjbbnh",stBBNBXX.getRJBBNH());
    query.bindValue(":shujcd",stBBNBXX.getSHUJCD());
    query.bindValue(":dizhih",stBBNBXX.getDIZHIH());
    query.bindValue(":shjunr",stBBNBXX.getSHJUNR());
    query.bindValue(":jiaoym",stBBNBXX.getJIAOYM());
    query.bindValue(":jiluzt",stBBNBXX.getJILUZT());
    query.bindValue(":xuhaoo",stBBNBXX.getXUHAOO());
    query.bindValue(":banbrq",stBBNBXX.getBANBRQ());
    query.bindValue(":shijch",stBBNBXX.getSHIJCH());
    query.bindValue(":zhaiyy",stBBNBXX.getZHAIYY());
    query.bindValue(":beizd1",stBBNBXX.getBEIZD1());
    query.bindValue(":beizd2",stBBNBXX.getBEIZD2());
    query.bindValue(":beizd3",stBBNBXX.getBEIZD3());
    query.bindValue(":beizd4",stBBNBXX.getBEIZD4());

    query.exec();
//    helper->destoryConn();
}

//插入一条仪表数据
void UdaoImp::InsertDevice(const TBL_BBSJIXX& stBBSJIXX)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("insert into BSJIXX(yibobh,rjbbnh,shjijd,sjksdz,weihrq,shijch,"
                                      "shjizt,jiluzt,beizd1,beizd2,beizd3,beizd4)"
                               "values(:yibobh,:rjbbnh,:shjijd,:sjksdz,:weihrq,:shijch,"
                                      ":shjizt,:jiluzt,:beizd1,:beizd2,:beizd3,:beizd4);");

    query.bindValue(":yibobh",stBBSJIXX.getYIBOBH());
    query.bindValue(":rjbbnh",stBBSJIXX.getRJBBNH());
    query.bindValue(":shjijd",stBBSJIXX.getSHJIJD());
    query.bindValue(":sjksdz",stBBSJIXX.getSJKSDZ());
    query.bindValue(":weihrq",stBBSJIXX.getWEIHRQ());
    query.bindValue(":shijch",stBBSJIXX.getSHIJCH());
    query.bindValue(":shjizt",stBBSJIXX.getSHJIZT());
    query.bindValue(":jiluzt",stBBSJIXX.getJILUZT());
    query.bindValue(":beizd1",stBBSJIXX.getBEIZD1());
    query.bindValue(":beizd2",stBBSJIXX.getBEIZD2());
    query.bindValue(":beizd3",stBBSJIXX.getBEIZD3());
    query.bindValue(":beizd4",stBBSJIXX.getBEIZD4());

    query.exec();
    helper->destoryConn();
}

//更新一条数据
void UdaoImp::UpdateDevice(const TBL_BBSJIXX& stBBSJIXX)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("update BSJIXX set shjijd=:shjijd,sjksdz=:sjksdz,weihrq=:weihrq,"
                  "shijch=:shijch where yibobh=:yibobh and jiluzt='0';");
    query.bindValue(":shjijd",stBBSJIXX.getSHJIJD());
    query.bindValue(":sjksdz",stBBSJIXX.getSJKSDZ());
    query.bindValue(":weihrq",stBBSJIXX.getWEIHRQ());
    query.bindValue(":shijch",stBBSJIXX.getSHIJCH());
    query.bindValue(":yibobh",stBBSJIXX.getYIBOBH());

    query.exec();
    helper->destoryConn();
}

//查询仪表升级信息
TBL_BBSJIXX UdaoImp::SelectDevice(const TBL_BBSJIXX& stBBSJIXX)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("select * from BBNBXX where yibobh=:yibobh;");
    query.bindValue(":yibobh",stBBSJIXX.getYIBOBH());
    query.exec();
    QString 	 	sYIBOBH;
    QString		 	sRJBBNH;
    unsigned int 	sSHJIJD;
    QString		 	sSJKSDZ;
    QString		 	sWEIHRQ;
    unsigned int 	sSHIJCH;
    QString		 	sSHJIZT;
    QString		 	sJILUZT;
    QString		 	sBEIZD1;
    QString		 	sBEIZD2;
    QString		 	sBEIZD3;
    QString		 	sBEIZD4;
    while(query.next())
    {
        sYIBOBH = query.value(0).toString();
        sRJBBNH = query.value(1).toString();
        sSHJIJD = query.value(2).toInt();
        sSJKSDZ = query.value(3).toString();
        sWEIHRQ = query.value(4).toString();
        sSHIJCH = query.value(5).toInt();
        sSHJIZT = query.value(6).toString();
        sJILUZT = query.value(7).toString();
        sBEIZD1 = query.value(8).toString();
        sBEIZD2 = query.value(9).toString();
        sBEIZD3 = query.value(10).toString();
        sBEIZD4 = query.value(11).toString();

    }
    TBL_BBSJIXX stBBSJIXX_tmp(sYIBOBH,sRJBBNH,sSJKSDZ,sWEIHRQ,sSHJIZT,sJILUZT,sBEIZD1,sBEIZD2,sBEIZD3,sBEIZD4,sSHJIJD,sSHIJCH);
    return stBBSJIXX_tmp;
    helper->destoryConn();
}

*/
