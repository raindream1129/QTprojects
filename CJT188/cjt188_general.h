#ifndef CJT188_GENERAL_H
#define CJT188_GENERAL_H

#include <QString>

#define CJT188_HDLC_PREFIX                  0xFE
#define CJT188_HDLC_HEADER                  0x68
#define CJT188_METER_GAS                    0x30
#define CJT188_HDLC_BROADCAST_ADDR          0xAA

#define CJT188_HDLC_TAIL                    0x16

/*
 * CJT188 control code   控制码
*/
//General
#define CJT188_CTRL_ID_NONE                     0x00
#define CJT188_DATAID_ID_NONE                   0x00
//rd
#define CJT188_CTRL_ID_RD_DATA                  0x01
#define CJT188_CTRL_ID_RD_ADDR                  0x03
#define CJT188_CTRL_ID_RD_VERSION               0x09
//rd_return
#define CJT188_CTRL_ID_RD_DATA_RETURN_SUCCESS   0x81
#define CJT188_CTRL_ID_RD_DATA_RETURN_FAULSE    0xC1
#define CJT188_CTRL_ID_RD_VERSION_RETURN_SUCCESS 0x89
#define CJT188_CTRL_ID_RD_VERSION_RETURN_FAULSE 0xC9
#define CJT188_CTRL_ID_RD_ADDR_RETURN_SUCCESS   0x83
#define CJT188_CTRL_ID_RD_ADDR_RETURN_FAULSE    0xC3
//wr
#define CJT188_CTRL_ID_WR_DATA                  0x04
#define CJT188_CTRL_ID_WR_ADDR                  0x15
#define CJT188_CTRL_ID_WR_MOTOR                 0x16
//wr_return
#define CJT188_CTRL_ID_WR_DATA_RETURN_SUCCESS   0x84
#define CJT188_CTRL_ID_WR_DATA_RETURN_FAULSE    0xC4
#define CJT188_CTRL_ID_WR_ADDR_RETURN_SUCCESS   0x95
#define CJT188_CTRL_ID_WR_ADDR_RETURN_FAULSE    0xD5
#define CJT188_CTRL_ID_WR_MOTOR_RETURN_SUCCESS  0x96
#define CJT188_CTRL_ID_WR_MOTOR_RETURN_FAULSE   0xD6

/* CJT188 object id */
#define CJT188_OBJ_ID_NONE                  (0x0000)
//rd
#define CJT188_OBJ_ID_RD_METROLOGICAL_DATA  (0x901F)    //读计量数据
#define CJT188_OBJ_ID_RD_HISTORY_1          (0xD120)    //历史数据1
#define CJT188_OBJ_ID_RD_HISTORY_2          (0xD121)    //历史数据2
#define CJT188_OBJ_ID_RD_HISTORY_3          (0xD122)    //历史数据3
#define CJT188_OBJ_ID_RD_HISTORY_4          (0xD123)    //历史数据4
#define CJT188_OBJ_ID_RD_HISTORY_5          (0xD124)    //历史数据5
#define CJT188_OBJ_ID_RD_HISTORY_6          (0xD125)    //历史数据6
#define CJT188_OBJ_ID_RD_HISTORY_7          (0xD126)    //历史数据7
#define CJT188_OBJ_ID_RD_HISTORY_8          (0xD127)    //历史数据8
#define CJT188_OBJ_ID_RD_HISTORY_9          (0xD128)    //历史数据9
#define CJT188_OBJ_ID_RD_HISTORY_10         (0xD129)    //历史数据10
#define CJT188_OBJ_ID_RD_HISTORY_11         (0xD12A)    //历史数据11
#define CJT188_OBJ_ID_RD_HISTORY_12         (0xD128)    //历史数据12
#define CJT188_OBJ_ID_RD_PRICE_LIST         (0xD102)    //读价目表
#define CJT188_OBJ_ID_RD_BALANCE_DATA       (0x8103)    //读结算日
#define CJT188_OBJ_ID_RD_DATE               (0x8104)    //读抄表日期
#define CJT188_OBJ_ID_RD_PURCHASE_AMOUNT    (0x8105)    //读购入金额
#define CJT188_OBJ_ID_RD_DATE_KEY_VERSION   (0x8106)    //读密钥版本号
#define CJT188_OBJ_ID_RD_MET_ARRD           (0x810A)    //读地址

//wr
#define CJT188_OBJ_ID_WR_PRICE_LIST         (0xA010)    //写价目表
#define CJT188_OBJ_ID_WR_BALANCE_DATA       (0xA011)    //写结算日
#define CJT188_OBJ_ID_WR_DATA               (0xA012)    //写抄表日
#define CJT188_OBJ_ID_WR_PURCHASE_AMOUNT    (0xA013)    //写购入金额
#define CJT188_OBJ_ID_WR_KEY                (0xA014)    //写密钥
#define CJT188_OBJ_ID_WR_TIME               (0xA015)    //写标准时间
#define CJT188_OBJ_ID_WR_VALVE_CTROL        (0x6036)    //写阀门控制
#define CJT188_OBJ_ID_WR_FACTORY_ENABLE     (0xA019)    //出厂启用
#define CJT188_OBJ_ID_WR_ADDR               (0xA018)    //写地址
#define CJT188_OBJ_ID_WR_ELECTR_SYNC_DATA   (0xA016)    //写机电同步数据


#define CJT188_OBJ_DATA_SER_NON             0x00;

class Cjt188Object
{
public:
    QString     desc;           //当前操作的描述
    QString     address;        //表号
    quint16     ctrlId;         //控制码
    quint32     flagId;         //数据标识
    QString     value;          //数据
    int         requestType;
    QString     allcmd;
    quint8      Seriers;
    QString     resultFlag;

    Cjt188Object(){}
    ~Cjt188Object(){}

    void clear()
    {
        desc.clear();
        address.clear();
        value.clear();

        ctrlId  = CJT188_CTRL_ID_NONE;
        flagId = CJT188_DATAID_ID_NONE;
        requestType = 0;
        Seriers = 0;
    }
};
















#endif // CJT188_GENERAL_H
