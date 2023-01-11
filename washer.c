#include "washer.h"
static FsmObj *washerObj;
void mod_washer_init(void)
{
    FSM_init(washerObj,&TopState);
}
void mod_washer_work(void)
{
    while(1)
    {
        if(washerObj->event)
        {
            // washerObj->event(event,param);//执行事件处理函数
        }
        if(washerObj->work)
        {
            washerObj->work();
        }
    }
}
//模块事件处理
void mod_washer_event(uint32_t event,uint32_t param)
{

}