#ifndef FSM_H
#define FSM_H
#include "stdint.h"
typedef struct FsmNode_t FsmNode;
typedef struct FsmState_t FsmState;
typedef struct FsmSimpleNode_t FsmSimpleNode;
typedef struct FsmCompositeNode_t FsmCompositeNode;
//转换类型
typedef enum
{
    TRANS_RESET,
    TRANS_RECORD,
}TRANS_TYPE;

typedef void (*entryHandle)(FsmState *fsm);
typedef void (*exitHandle)(FsmState *fsm,uint8_t transType);
typedef void (*workHandle)(FsmState *fsm);
typedef void (*eventHandle)(FsmState *fsm, uint32_t event, uint32_t param);

//抽象状态
typedef struct FsmNode_t
{
    uint8_t isComposite; // 是否为复合状态
    eventHandle event;   // 事件回调
    FsmNode *backState;  // 历史状态
} FsmNode;
//简单状态
typedef struct FsmSimpleNode_t
{
    FsmNode node;        // 抽象状态
    FsmNode *super;      // 所属的父节点
    entryHandle entry;   // 进入活动
    exitHandle exit;     // 退出活动
    workHandle work;     // 轮询活动
} FsmSimpleNode;
//复合状态
typedef struct FsmCompositeNode_t
{
    FsmNode node;        // 抽象状态
    uint8_t num;         // 包含的子状态个数
    uint8_t initState;   // 初始状态
    uint8_t activeState; // 活动状态
    FsmNode ** nodeList;
} FsmCompositeNode;
//状态机
typedef struct FsmState_t
{
    uint8_t activeState; // 活动状态  
    uint8_t num;         // 状态数量
    FsmNode **node;      // 状态机列表
    eventHandle event;   // 事件回调
    void *param;         // 参数指针
} FsmState;

#endif