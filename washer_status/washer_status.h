#ifndef WASHER_STATUS_H
#define WASHER_STATUS_H
#include "../cutefsm.h"

//��Ϣ
typedef enum
{
    WASHER_MSG_POWERON, //����
    WASHER_MSG_POWEROFF,//�ػ�
    WASHER_MSG_START,   //��ʼ����
    WASHER_MSG_PAUSE,   //��ͣ
    WASHER_MSG_CONTINUE,//����
}WASHER_MSG;

//���ϲ�״̬
typedef enum
{
    WASHER_TOP_STATE,     // ����״̬
    WASHER_READY_STATE,   // ׼��״̬
    WASHER_WORK_STATE,    // ����״̬
    WASHER_WATER_STATE,   // ��ˮ״̬
    WASHER_CLEAN_STATE,   // ��ϴ״̬
    WASHER_SPINDRY_STATE, // ˦��״̬
    WASHER_PAUSE_STATE,   // ��ͣ״̬
    WASHER_BUTT_STATE,    //
} WASHER_STATUS;

extern FsmObj TopState;
extern FsmObj ReadyState;
extern FsmObj WorkState;
extern FsmObj WaterState;
extern FsmObj CleanState;
extern FsmObj SpinDryState;
extern FsmObj PauseState;

#endif