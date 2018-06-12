#ifndef CJT188_FIO_H
#define CJT188_FIO_H
#include <QString>
#include "common.h"
/* CJT188 request type: GET/SET */


/* *************
 * CJT188 control code
*****************/
//General
#define CJT188_FIO_CTRL_ID_NONE                  0x00
/***master***/
//rd
#define CJT188_FIO_CTRL_ID_RD_DATA               0x01
//#define CJT188_FIO_CTRL_ID_CMD_RD_DATA           0x52
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA           0x01
//wr
#define CJT188_FIO_CTRL_ID_WR_DATA               0x04
//#define CJT188_FIO_CTRL_ID_CMD_WR_DATA           0x57
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA           0x04
//相应主动上报
#define CJT188_FIO_CTRL_ID_RESPONSE              0x20
/****slave****/
//answer
//rd
#define CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS       0x81
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA_SUCCESS   0xD2
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA_FAULSE    0xA2
//wr
#define CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS       0x84
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS   0xD7
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA_FAULSE    0xA1
//report
#define CJT188_FIO_CTRL_ID_REPORT_DATA           0xA0



/* CJT188 object id */
#define CJT188_FIO_OBJ_ID_NONE                  (0x0000)
#define CJT188_FIO_OBJ_ID_REGISTER              (0x9066)//注册
#define CJT188_FIO_OBJ_ID_INITIAVE_REPORT       (0x6044)//主动上报
#define CJT188_FIO_OBJ_ID_HISTORY_DATA          (0xD120)//历史数据
#define CJT188_FIO_OBJ_ID_REPORT_CYCLE          (0x6031)//上报周期
#define CJT188_FIO_OBJ_ID_NET_DATA              (0x6032)//网络参数
#define CJT188_FIO_OBJ_ID_ALLOWANCE_SET         (0x6034)//余量设置
#define CJT188_FIO_OBJ_ID_VALVE_CONTROL         (0x6036)//阀门控制
#define CJT188_FIO_OBJ_ID_MODLE_CHANGE          (0x6038)//模式切换
#define CJT188_FIO_OBJ_ID_BATT_THRESHOLD        (0x603A)//电压阈值
#define CJT188_FIO_OBJ_ID_CONFIG_VERSION        (0x603B)//配置版本号
#define CJT188_FIO_OBJ_ID_MAX_FLOW              (0x603C)//最大流量
#define CJT188_FIO_OBJ_ID_MIN_FLOW              (0x603D)//最小流量
#define CJT188_FIO_OBJ_ID_CONTINUE_IDLE_TIME    (0x603E)//连续闲置时间
#define CJT188_FIO_OBJ_ID_GAS_CONTINUE_TIME     (0x603F)//连续用气时间
#define CJT188_FIO_OBJ_ID_METER_WORKING_STATE   (0x6040)//表具工作状态
//NB_IOT
#define CJT188_FIO_OBJ_ID_NB_IOT_FACTORY        (0x6050)//厂商
#define CJT188_FIO_OBJ_ID_NB_IOT_VERSION        (0x6051)//版本
#define CJT188_FIO_OBJ_ID_NB_IOT_ICCID          (0x6052)//ICCID
#define CJT188_FIO_OBJ_ID_NB_IOT_BAND           (0x6053)//BAND
#define CJT188_FIO_OBJ_ID_NB_IOT_PLMN           (0x6054)//PLMN
#define CJT188_FIO_OBJ_ID_NB_IOT_SIGNLE         (0x6055)//RSRP/SNR/PCI
#define CJT188_FIO_OBJ_ID_NB_IOT_APN            (0x6056)//APN
#define CJT188_FIO_OBJ_ID_NB_IOT_AVOID_PEAK     (0x6057)//避峰
#define CJT188_FIO_OBJ_ID_BALANCE               (0x60A0)//余额
#define CJT188_FIO_OBJ_ID_CHARGE                (0x60A1)//充值
#define CJT188_FIO_OBJ_ID_OVER_DRAFT            (0x60A2)//透支
#define CJT188_FIO_OBJ_ID_PAY                   (0x60A3)//付费类型
#define CJT188_FIO_OBJ_ID_CHECK_VERSION         (0x6070)//版本校验
#define CJT188_FIO_OBJ_ID_UPDATING_READY        (0x6071)//准备升级
#define CJT188_FIO_OBJ_ID_UPDATING_PAG          (0x6072)//数据包
#define CJT188_FIO_OBJ_ID_CHANGE_TO_NEW_VERSION (0x6073)//请求切换
#define CJT188_FIO_OBJ_ID_AMOUNT_LIST           (0x60AA)//价格表
#define CJT188_FIO_OBJ_ID_ALLOWANCE_PROMPT      (0x60AB)//余量提示
#define CJT188_FIO_OBJ_ID_BALANCE_PROMPT        (0x60AC)//余额提示
#define CJT188_FIO_OBJ_ID_FREEZEN_DATE          (0x60AD)//冻结日
#define CJT188_FIO_OBJ_ID_METER_LIMIT_PARAMETER (0x6080)//表具极限特性参数


#define CJT188_FIO_OBJ_ID_WR_VALVE              (0xA017)//写阀门控制


/* CJT188 data id */
#define CJT188_FIO_OBJ_DATA_ID_BATT             101
#define CJT188_FIO_OBJ_DATA_ID_TOT              102
#define CJT188_FIO_OBJ_DATA_ID_WORK_TIME        103
#define CJT188_FIO_OBJ_DATA_ID_VAVLE_OPEN       104
#define CJT188_FIO_OBJ_DATA_ID_VAVLE_CLOSE      105


#define UPGRADE_CONF_INF  "00"
#define UPGRADE_MCU_IN    "FF"
#define UPGRADE_MCU_OUT   "01"

/*升级数据包协议*/
class UPData
{
public:
    QString Serios;
    QString Type;
    QString Address;
    QString Length;
    QString Data;
    QString CRCheck;

    UPData(){}
    ~UPData(){}
    void clear()
    {
        Serios.clear();
        Type.clear();
        Address.clear();
        Length.clear();
        Data.clear();
        CRCheck.clear();
    }
    QString Values(){
        //return Serios+Type+Address+Length+Data+CRCheck;
        QString sSerios_Out;
        QString sLength_Out;
        BigToLittle(Serios,&sSerios_Out);
        BigToLittle(Length,&sLength_Out);
        return sSerios_Out+sLength_Out+Address+Data+CRCheck;
    }
};



#endif // CJT188_FIO_H
