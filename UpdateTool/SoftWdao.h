#ifndef SOFTWDAO_H
#define SOFTWDAO_H
//#include "Struct.h"
#include <vector>
#include "dbbnbxx.h"
#include "dbsjixx.h"
using namespace std;

class SoftWdao
{
public:
    /****************************************************
     * 版本库管理
     * *************************************************/

    //插入版本数据
    virtual void inserterVersion(const TBL_BBNBXX&)=0;
    //某版本下所有数据
    virtual vector<TBL_BBNBXX> selectAllDateOfSmVersion(const TBL_BBNBXX& stBBNBXX)=0;
    //选择所有版本号
    virtual QList<QString> selectAllVersion()=0;
    //版本条目数(判断是否已经加入版本库)
    virtual int selectCountVersion(const TBL_BBNBXX& stBBNBXX)=0;

    /****************************************************
     * 仪表版本升级管理
     * *************************************************/

    //插入一条数据
    virtual void InsertDevice(const TBL_BBSJIXX&)=0;
    //更新一条数据
    virtual void UpdateDevice(const TBL_BBSJIXX&)=0;
    //查询仪表升级信息
    virtual TBL_BBSJIXX SelectDevice(const TBL_BBSJIXX&)=0;

    SoftWdao();
    virtual ~SoftWdao();
};

#endif // USERDAO_H
