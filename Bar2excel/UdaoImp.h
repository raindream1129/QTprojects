#ifndef UDAOIMP_H
#define UDAOIMP_H
#include "dbstr_inf.h"
#include "StrIdao.h"
#include <vector>

class UdaoImp : public StrIdao
{
public:
    //添加一台表
    bool inserterMt(const dbstr_inf&);
    //删除一台表
    void deleteMt(const QString);
    //维护表数据
    void maintainMt(const dbstr_inf&);
    //查询表数据
    dbstr_inf selectMt(const dbstr_inf&);
    UdaoImp();
};

#endif // UDAOIMP_H
