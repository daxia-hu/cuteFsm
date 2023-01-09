#include "washer_status.h"
void readyEntry(void)
{

}
void readyEvent(uint32_t event,uint32_t param)
{

}
void readyExit(void)
{

}
void readyWork(void)
{

}

FsmObj ReadyState = 
{
    .activeState = NULL,
    .entry = readyEntry,
    .event = readyEvent,
    .exit = readyExit,
    .node = NULL,
    .super = &TopState,
    .work = readyWork,
};
