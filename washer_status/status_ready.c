#include "washer_status.h"
void readyEntry(void)
{
}
void readyEvent(uint32_t event, uint32_t param)
{
    switch (event)
    {
    case WASHER_MSG_START:
        break; // ÔÝÍ£
    default:
        break;
    };
}
void readyExit(void)
{

}
void readyWork(void)
{

}

FsmObj ReadyState = 
{
    .active = NULL,
    .entry = readyEntry,
    .event = readyEvent,
    .exit = readyExit,
    .node = NULL,
    .super = WASHER_TOP_STATE,
    .work = readyWork,
};
