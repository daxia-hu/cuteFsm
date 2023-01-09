#include "washer_status.h"

void topWork(void)
{
    TopState.node[TopState.activeState]->work();
}
void topEntry(void)
{
    TopState.node[TopState.activeState]->entry();
}
void topEvent(uint32_t event,uint32_t param)
{
    switch (event)
    {
    case WASHER_MSG_POWERON:
        break; // ����
    case WASHER_MSG_POWEROFF:
        break; // �ػ�
    default:
        break;
    };
    if(TopState.node[TopState.activeState]->event)
    {
        TopState.node[TopState.activeState]->event(event,param);
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
