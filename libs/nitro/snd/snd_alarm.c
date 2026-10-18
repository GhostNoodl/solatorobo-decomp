#include "nitro/snd.h"

typedef struct AlarmCallbackInfo {
    SNDAlarmHandler handler; // 0x0
    void *arg;               // 0x4
    u8 id;                   // 0x8
    u8 padding[3];
} AlarmCallbackInfo; // size 0xc

static AlarmCallbackInfo sCallbackTable[SND_ALARM_COUNT];

void SND_AlarmInit(void) {
    s32 i;
    for (i = 0; i < SND_ALARM_COUNT; i++) {
        sCallbackTable[i].handler = NULL;
        sCallbackTable[i].arg = NULL;
        sCallbackTable[i].id = 0;
    }
}

void SNDi_IncAlarmId(u32 id) {
    AlarmCallbackInfo *info = &sCallbackTable[id];
    info->id++;
}

u8 SNDi_SetAlarmHandler(u32 id, SNDAlarmHandler handler, void *arg) {
    AlarmCallbackInfo *info = &sCallbackTable[id];
    info->handler = handler;
    info->arg = arg;
    info->id++;
    return info->id;
}

void SNDi_CallAlarmHandler(s32 id) {
    AlarmCallbackInfo *info = &sCallbackTable[id & 0xff];
    if (((id >> 8) & 0xff) != info->id) {
        return;
    }
    if (info->handler == NULL) {
        return;
    }
    info->handler(info->arg);
}
