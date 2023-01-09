#ifndef CUTE_FSM_H
#define CUTE_FSM_H
#include "stdint.h"
#define NULL ((void *)0)
typedef struct FsmSimpleNode_t FsmSimpleNode;
typedef struct FsmObj_t FsmObj;
// 转换类型
typedef enum
{
    TRANS_RESET,
    TRANS_RECORD,
} TRANS_TYPE;

typedef void (*entryHandle)(void);
typedef void (*exitHandle)(void);
typedef void (*workHandle)(void);
typedef void (*eventHandle)(uint32_t event, uint32_t param);

// 状态机类型
typedef struct FsmObj_t
{
    uint8_t super;       // 所属的父节点
    uint8_t active;      // 复合状态时为活动状态，简单状态时为历史状态
    entryHandle entry;   // 进入活动
    exitHandle exit;     // 退出活动
    workHandle work;     // 轮询活动
    eventHandle event;   // 事件回调
    FsmObj **node;       // 子状态列表
} FsmObj;

#endif