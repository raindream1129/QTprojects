#ifndef STRIDAO_H
#define STRIDAO_H
#include "dbstr_inf.h"

class StrIdao
{
public:
    StrIdao();
    //添加一台表
    virtual bool inserterMt(const dbstr_inf&)=0;
    //删除一台表
    virtual void deleteMt(const QString)=0;
    //维护表数据
    virtual void maintainMt(const dbstr_inf&)=0;
    //查询表数据
    virtual dbstr_inf selectMt(const dbstr_inf&)=0;



};

#endif // STRIDAO_H
