
#include "cutefsm.h"
/**
 * @brief 状态机初始化
 * @param workObj 最终活动状态
 * @param targetObj 初始状态
 **/
void FSM_init(FsmObj *workObj,FsmObj *initObj)
{
    ASSERT(NULL != workObj);
    ASSERT(NULL != initObj);
    workObj = initObj;
    if(workObj->entry)
    {
        workObj->entry(TRANS_RESET);
    }
}
static void func_FsmTrans(FsmObj *workObj,FsmObj *targetObj,TRANS_TYPE type)
{
    if((NULL != workObj) && (NULL != targetObj))
    {
        if(workObj->exit)
        {
            workObj->exit();
        }
        memcpy(workObj,targetObj,sizeof(targetObj));
        if(workObj->entry)
        {
            workObj->entry(type);
        }
    }
}
/**
 * @brief 状态机状态切换 参数重置
 * @param workObj 当前状态
 * @param workObj 目标状态
 */
void FSM_transState(FsmObj *workObj,FsmObj *targetObj)
{
    func_FsmTrans(workObj,targetObj,TRANS_RESET);
}
/**
 * @brief 状态机状态返回 参数不重置
 * @param workObj 当前状态
 * @param workObj 目标状态
 */
void FSM_backState(FsmObj *workObj,FsmObj *targetObj)
{
    ASSERT(NULL != workObj);
    ASSERT(NULL != targetObj);
    func_FsmTrans(workObj,targetObj,TRANS_RECORD);
}
/**
 * @brief 状态机事件执行函数
 * @param workObj 当前状态
 * @param event 事件ID
 * @param param 参数ID
 */
void FSM_eventHandle(FsmObj *workObj,uint32_t event,uint32_t param)
{
    ASSERT(NULL != workObj);
    if(workObj->event)
    {
        workObj->event(event,param);
    }
    FsmObj *workSuper = workObj->super;
    while(NULL != workSuper)
    {
        if(workSuper->event)
        {
            workSuper->event(event,param);
        }
        workSuper = workSuper->super;
    }
}