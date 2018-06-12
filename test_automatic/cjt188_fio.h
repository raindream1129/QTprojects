#ifndef CJT188_FIO_H
#define CJT188_FIO_H

/* CJT188 request type: GET/SET */


/* *************
 * CJT188 control code
*****************/
//General
#define CJT188_FIO_CTRL_ID_NONE                  0x00
/***master***/
//rd
#define CJT188_FIO_CTRL_ID_RD_DATA               0x01
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA           0x01
//wr
#define CJT188_FIO_CTRL_ID_WR_DATA               0x04
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA           0x04
//相应主动上报
#define CJT188_FIO_CTRL_ID_RESPONSE              0x20
/****slave****/
//answer
//rd
#define CJT188_FIO_CTRL_ID_RD_DATA_SUCCESS       0x81
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA_SUCCESS   0x81
#define CJT188_FIO_CTRL_ID_CMD_RD_DATA_FAULSE    0xA2
//wr
#define CJT188_FIO_CTRL_ID_WR_DATA_SUCCESS       0x84
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA_SUCCESS   0x84
#define CJT188_FIO_CTRL_ID_CMD_WR_DATA_FAULSE    0xA1
//report
#define CJT188_FIO_CTRL_ID_REPORT_DATA           0xA0



/* CJT188 object id */
#define CJT188_FIO_OBJ_ID_NONE                  (0x0000)
#define CJT188_FIO_OBJ_ID_REGISTER              (0x9066)//注册
#define CJT188_FIO_OBJ_ID_INITIAVE_REPORT       (0x6044)//主动上报
#define CJT188_FIO_OBJ_ID_HISTORY_DATE_DATA     (0xD120)//历史数据(日)
#define CJT188_FIO_OBJ_ID_HISTORY_TIME_DATA     (0xD121)//历史数据(时)
#define CJT188_FIO_OBJ_ID_HISTORY_MONTH_DATA    (0xD122)//历史数据(月)

#define CJT188_FIO_OBJ_ID_NET_PUSH              (0x6030)//网络上报
#define CJT188_FIO_OBJ_ID_SYSTEM_STATE          (0x6031)//系统状态
#define CJT188_FIO_OBJ_ID_CUMULATIVE_SAMP       (0x6032)//累加器采样
#define CJT188_FIO_OBJ_ID_TEMP_SAMP             (0x6033)//温度采样

#define CJT188_FIO_OBJ_ID_APP_ADDR              (0x6040)//应用服务器地址
#define CJT188_FIO_OBJ_ID_BACKUP_ADDR           (0x6041)//备份服务器地址
#define CJT188_FIO_OBJ_ID_UPGRADE_ADDR          (0x6042)//升级服务器地址
#define CJT188_FIO_OBJ_ID_PLATFORM_ADDR         (0x6043)//平台服务器地址

#define CJT188_FIO_OBJ_ID_WORKING_TIME          (0x6049)//设备运行时间


#define CJT188_FIO_OBJ_ID_ALLOWANCE_SET         (0x6034)//余量设置
#define CJT188_FIO_OBJ_ID_BALANCE_SET           (0x6035)//余额设置
#define CJT188_FIO_OBJ_ID_VALVE_CONTROL         (0x6036)//阀门控制
#define CJT188_FIO_OBJ_ID_METER_WORKING_STATE   (0x6037)//表具工作状态
#define CJT188_FIO_OBJ_ID_MODLE_CHANGE          (0x6038)//模式切换
#define CJT188_FIO_OBJ_ID_VOL_OUT               (0x6039)//外电电压
#define CJT188_FIO_OBJ_ID_BATT_THRESHOLD        (0x603A)//电压阈值
#define CJT188_FIO_OBJ_ID_CONFIG_VERSION        (0x603B)//配置版本号
#define CJT188_FIO_OBJ_ID_MAX_FLOW              (0x603C)//最大流量
#define CJT188_FIO_OBJ_ID_MIN_FLOW              (0x603D)//最小流量
#define CJT188_FIO_OBJ_ID_CONTINUE_IDLE_TIME    (0x603E)//连续闲置时间
#define CJT188_FIO_OBJ_ID_GAS_CONTINUE_TIME     (0x603F)//命令上报
#define CJT188_FIO_OBJ_ID_REPORT_STATE          (0x6055)//上报状态

#define CJT188_FIO_OBJ_ID_DROP_TIME             (0x604A)//连续不通讯时间
#define CJT188_FIO_OBJ_ID_IDLED_TIME            (0x604B)//已闲置时长
#define CJT188_FIO_OBJ_ID_ALARM_BANLANCE        (0x60AC)//警示额度
#define CJT188_FIO_OBJ_ID_OVERDRAFT             (0x60A2)//透支额度





//NB_IOT
#define CJT188_FIO_OBJ_ID_NB_IOT_INFORMATION    (0x6050)//厂商\版本\ICCID
#define CJT188_FIO_OBJ_ID_NB_IOT_VERSION        (0x6051)//
#define CJT188_FIO_OBJ_ID_NB_IOT_ICCID          (0x6052)//
#define CJT188_FIO_OBJ_ID_NB_IOT_BAND           (0x6053)//BAND
#define CJT188_FIO_OBJ_ID_NB_IOT_PLMN           (0x6054)//PLMN
#define CJT188_FIO_OBJ_ID_NB_IOT_SIGNLE         (0x6055)//RSRP/SNR/PCI
#define CJT188_FIO_OBJ_ID_NB_IOT_APN            (0x6056)//APN
#define CJT188_FIO_OBJ_ID_NB_IOT_AVOID_PEAK     (0x6058)//避峰
#define CJT188_FIO_OBJ_ID_GET_TEMERATURE        (0x6059)//温度
#define CJT188_FIO_OBJ_ID_WAKEUP_TIME           (0x605A)//唤醒时间
#define CJT188_FIO_OBJ_ID_BALANCE               (0x60A0)//余额
#define CJT188_FIO_OBJ_ID_CHARGE                (0x60A1)//充值
#define CJT188_FIO_OBJ_ID_OVER_DRAFT            (0x60A2)//透支
#define CJT188_FIO_OBJ_ID_PAY                   (0x60A3)//付费类型
#define CJT188_FIO_OBJ_ID_UPDATE_NEW_VERSION    (0x6070)//升级-新版本
#define CJT188_FIO_OBJ_ID_UPDATING_PAG          (0x6071)//升级包
#define CJT188_FIO_OBJ_ID_CHANGE_TO_NEW_VERSION (0x6072)//切换新版本
#define CJT188_FIO_OBJ_ID_ASK_CHANGE            (0x6073)//请求切换
#define CJT188_FIO_OBJ_ID_AMOUNT_LIST           (0x60AA)//价格表
#define CJT188_FIO_OBJ_ID_ALLOWANCE_PROMPT      (0x60AB)//余量提示
#define CJT188_FIO_OBJ_ID_BALANCE_PROMPT        (0x60AC)//余额提示
#define CJT188_FIO_OBJ_ID_FREEZEN_DATE          (0x60AD)//冻结日

#define CJT188_FIO_OBJ_ID_ABNORMAL_STATION       (0x6080)//异常事件
#define CJT188_FIO_OBJ_ID_CLEAR_ABNORMAL_STATION (0x6081)//清除异常

#define CJT188_FIO_OBJ_ID_IDLE_TIME             (0x603E)//闲置时间





#define CJT188_FIO_OBJ_ID_WR_VALVE              (0xA017)//写阀门控制


/* CJT188 data id */
#define CJT188_FIO_OBJ_DATA_ID_BATT             101
#define CJT188_FIO_OBJ_DATA_ID_TOT              102
#define CJT188_FIO_OBJ_DATA_ID_WORK_TIME        103
#define CJT188_FIO_OBJ_DATA_ID_VAVLE_OPEN       104
#define CJT188_FIO_OBJ_DATA_ID_VAVLE_CLOSE      105


#endif // CJT188_FIO_H
