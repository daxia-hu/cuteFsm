#ifndef CUTE_FSM_H
#define CUTE_FSM_H
#include "stdint.h"
#define NULL ((void *)0)
#define DEBUG //
#define ASSERT(x) do{if(!(x)){DEBUG("<ERROR> file:%s,line:%d\r\n", __FILE__, __LINE__);}}while(0);
typedef struct FsmSimpleNode_t FsmSimpleNode;
typedef struct FsmObj_t FsmObj;
// 转换类型
typedef enum
{
    TRANS_RESET,
    TRANS_RECORD,
} TRANS_TYPE;

typedef void (*entryHandle)(TRANS_TYPE transType);
typedef void (*exitHandle)(void);
typedef void (*workHandle)(void);
typedef void (*eventHandle)(uint32_t event, uint32_t param);

// 状态机类型
typedef struct FsmObj_t
{
    uint8_t active;      // 复合状态时为活动状态，简单状态时为历史状态
    FsmObj* super;       // 所属的父节点
    entryHandle entry;   // 进入活动
    exitHandle exit;     // 退出活动
    workHandle work;     // 轮询活动
    eventHandle event;   // 事件回调
    FsmObj **node;       // 子状态列表
} FsmObj;
/**
 * @brief 状态机初始化
 * @param workObj 最终活动状态
 * @param targetObj 初始状态
 */
void FSM_init(FsmObj *workObj,FsmObj *initObj);
/**
 * @brief 状态机状态切换 参数重置
 * @param workObj 当前状态
 * @param workObj 目标状态
 */
void FSM_transState(FsmObj *workObj,FsmObj *targetObj);
/**
 * @brief 状态机状态返回 参数不重置
 * @param workObj 当前状态
 * @param workObj 目标状态
 */
void FSM_backState(FsmObj *workObj,FsmObj *targetObj);
/**
 * @brief 状态机事件执行函数
 * @param workObj 当前状态
 * @param event 事件ID
 * @param param 参数ID
 */
void FSM_eventHandle(FsmObj *workObj,uint32_t event,uint32_t param);
#endif