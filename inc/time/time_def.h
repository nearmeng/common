#ifndef _TIME_DEF_H_
#define _TIME_DEF_H_

#include "linked_list/linked_list.h"

#define TVN_BITS 6
#define TVR_BITS 8
#define TVN_SIZE (1 << TVN_BITS)
#define TVR_SIZE (1 << TVR_BITS)
#define TVN_MASK (TVN_SIZE - 1)
#define TVR_MASK (TVR_SIZE - 1)

#define TV1_MAX TVR_SIZE
#define TV2_MAX (1 << (TVR_BITS + 1 * TVN_BITS))
#define TV3_MAX (1 << (TVR_BITS + 2 * TVN_BITS))
#define TV4_MAX (1 << (TVR_BITS + 3 * TVN_BITS))
#define TV5_MAX (1 << (TVR_BITS + 4 * TVN_BITS))

#define TV1_IDX(tick) ((tick)&TVR_MASK)
#define TV2_IDX(tick) (((tick) >> TVR_BITS) & TVN_MASK)
#define TV3_IDX(tick) (((tick) >> (TVR_BITS + 1 * TVN_BITS)) & TVN_MASK)
#define TV4_IDX(tick) (((tick) >> (TVR_BITS + 2 * TVN_BITS)) & TVN_MASK)
#define TV5_IDX(tick) (((tick) >> (TVR_BITS + 3 * TVN_BITS)) & TVN_MASK)

#define TICK_PER_SECOND (1000)
#define MS_PER_TICK (1000 / TICK_PER_SECOND)

#define SEC2MS(s) ((s)*1000)
#define SEC2TICK(s) ((s)*TICK_PER_SECOND)
#define MS2TICK(ms) ((int64_t)(ms) / MS_PER_TICK)
#define TICK2MS(tick) ((int64_t(tick)) * MS_PER_TICK)

#define MAX_TIMER_TYPE_COUNT (512)
#define MAX_TIMER_CB_DATA_LEN (64)
#define MAX_TIMER_TYPE_COUNT (512)

typedef void (*TIMEOUT_FUNC)(uint64_t qwTimerID, void *pCbData, int32_t nCbDataLen);

struct TIMER_HANDLER : LINK_NODE
{
    int64_t llExpires;                  // ��ʱtick
    int64_t llListOffset;               // ��������ƫ��
    int32_t nInterval;                  // ִ�м��
    int32_t nRepeatTimes;               // ִ�д���
    BOOL bRunning;                      // ��ǰrun״̬
    uint16_t wTimerType;                // ��ʱ����
    uint16_t wDataLen;                  // �ص����ݳ���
    char byData[MAX_TIMER_CB_DATA_LEN]; // �ص�����
};

struct TIMER_VECTOR
{
    LINK_HEAD stVec[TVN_SIZE];
};

struct TIMER_VECTOR_ROOT
{
    LINK_HEAD stVec[TVR_SIZE];
};

struct TIME_MGR_DATA
{
    int32_t nStartTimeSec;
    int32_t nCurrTimeSec;
    int64_t llCurrTimeUSec;

    int32_t nOffSet;
    int64_t llCurTick;

    TIMER_VECTOR_ROOT tv1;
    TIMER_VECTOR tv2;
    TIMER_VECTOR tv3;
    TIMER_VECTOR tv4;
    TIMER_VECTOR tv5;

    TIMEOUT_FUNC pTimeoutFunc[MAX_TIMER_TYPE_COUNT];
};

#endif