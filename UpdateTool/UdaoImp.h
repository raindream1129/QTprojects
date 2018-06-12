#ifndef UDAOIMP_H
#define UDAOIMP_H
#include "dbbnbxx.h"
#include "SoftWdao.h"
#include <vector>

class UdaoImp : public SoftWdao
{
public:
    //插入版本数据
    void inserterVersion(const TBL_BBNBXX&);
    //某版本下所有数据
    vector<TBL_BBNBXX> selectAllDateOfSmVersion(const TBL_BBNBXX& stBBNBXX);
    //选择所有版本号
    QList<QString> selectAllVersion();
    //版本条目数(判断是否已经加入版本库)
    int selectCountVersion(const TBL_BBNBXX& stBBNBXX);

    //插入一条仪表数据
    void InsertDevice(const TBL_BBSJIXX&);
    //更新一条数据
    void UpdateDevice(const TBL_BBSJIXX&);
    //查询仪表升级信息
    TBL_BBSJIXX SelectDevice(const TBL_BBSJIXX&stBBSJIXX);

    UdaoImp();
};

#endif // UDAOIMP_H
