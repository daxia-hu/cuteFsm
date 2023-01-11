#ifndef WASHER_STATUS_H
#define WASHER_STATUS_H
#include "../cutefsm.h"

//消息
typedef enum
{
    WASHER_MSG_POWERON, //开机
    WASHER_MSG_POWEROFF,//关机
    WASHER_MSG_START,   //开始工作
    WASHER_MSG_PAUSE,   //暂停
    WASHER_MSG_CONTINUE,//继续
}WASHER_MSG;

//最上层状态
typedef enum
{
    WASHER_TOP_STATE,     // 顶层状态
    WASHER_READY_STATE,   // 准备状态
    WASHER_WORK_STATE,    // 工作状态
    WASHER_WATER_STATE,   // 放水状态
    WASHER_CLEAN_STATE,   // 清洗状态
    WASHER_SPINDRY_STATE, // 甩干状态
    WASHER_PAUSE_STATE,   // 暂停状态
    WASHER_BUTT_STATE,    //
} WASHER_STATUS;

extern FsmObj TopState;
extern FsmObj ReadyState;
extern FsmObj WorkState;
extern FsmObj WaterState;
extern FsmObj CleanState;
extern FsmObj SpinDryState;
extern FsmObj PauseState;

#endif