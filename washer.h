#ifndef WASHER_H
#define WASHER_H
#include "washer_status/washer_status.h"
//模块初始化
void mod_washer_init(void);
//模块自轮询
void mod_washer_work(void);
//模块事件处理
void mod_washer_event(uint32_t event,uint32_t param);
#endif