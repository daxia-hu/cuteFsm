#ifndef WASHER_H
#define WASHER_H
#include "washer_status/washer_status.h"
//ģ���ʼ��
void mod_washer_init(void);
//ģ������ѯ
void mod_washer_work(void);
//ģ���¼�����
void mod_washer_event(uint32_t event,uint32_t param);
#endif