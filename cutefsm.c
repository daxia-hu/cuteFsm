
#include "cutefsm.h"

// 状态机状态切换
void FSM_transState(FsmObj *workObj,FsmObj *targetObj)
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
            workObj->entry();
        }
    }
}

// 状态机初始化
void FSM_init(FsmObj *workObj,FsmObj *initObj)
{
    workObj = initObj;
    if(workObj->entry)
    {
        workObj->entry();
    }
}
