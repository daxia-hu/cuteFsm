#include "washer_status.h"

void topWork(void)
{
    TopState.node[TopState.active]->work();
}
void topEntry(void)
{
    TopState.node[TopState.active]->entry();
}
void topEvent(uint32_t event,uint32_t param)
{
    switch (event)
    {
    case WASHER_MSG_POWERON:
        break; // 开机
    case WASHER_MSG_POWEROFF:
        break; // 关机
    default:
        break;
    };
    if(TopState.super)
    {
        if(TopState.super->event)
        {
            TopState.super->event(event,param);
        }
    }
}

FsmObj * StateTable[] = 
{
    &ReadyState,
    &WorkState,
    &PauseState,
};
FsmObj TopState = 
{
    .active = WASHER_READY_STATE,
    .super = NULL,
    .node = StateTable,
    .entry = topEntry,
    .work = topWork,
    .exit = NULL,
    .event = topEvent,
};
