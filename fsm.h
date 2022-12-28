#ifndef FSM_H
#define FSM_H
#include "stdint.h"
typedef struct FsmNode_t FsmNode;
typedef struct FsmState_t FsmState;
typedef struct FsmSimpleNode_t FsmSimpleNode;
typedef struct FsmCompositeNode_t FsmCompositeNode;
//ת������
typedef enum
{
    TRANS_RESET,
    TRANS_RECORD,
}TRANS_TYPE;

typedef void (*entryHandle)(FsmState *fsm);
typedef void (*exitHandle)(FsmState *fsm,uint8_t transType);
typedef void (*workHandle)(FsmState *fsm);
typedef void (*eventHandle)(FsmState *fsm, uint32_t event, uint32_t param);

//����״̬
typedef struct FsmNode_t
{
    uint8_t isComposite; // �Ƿ�Ϊ����״̬
    eventHandle event;   // �¼��ص�
    FsmNode *backState;  // ��ʷ״̬
} FsmNode;
//��״̬
typedef struct FsmSimpleNode_t
{
    FsmNode node;        // ����״̬
    FsmNode *super;      // �����ĸ��ڵ�
    entryHandle entry;   // ����
    exitHandle exit;     // �˳��
    workHandle work;     // ��ѯ�
} FsmSimpleNode;
//����״̬
typedef struct FsmCompositeNode_t
{
    FsmNode node;        // ����״̬
    uint8_t num;         // ��������״̬����
    uint8_t initState;   // ��ʼ״̬
    uint8_t activeState; // �״̬
    FsmNode ** nodeList;
} FsmCompositeNode;
//״̬��
typedef struct FsmState_t
{
    uint8_t activeState; // �״̬  
    uint8_t num;         // ״̬����
    FsmNode **node;      // ״̬���б�
    eventHandle event;   // �¼��ص�
    void *param;         // ����ָ��
} FsmState;

#endif