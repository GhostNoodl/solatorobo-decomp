#ifndef NITRO_PM_H
#define NITRO_PM_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*PMSleepCallback)(void *arg);

typedef struct PMSleepCallbackInfo {
    /* 0x0 */ PMSleepCallback callback;
    /* 0x4 */ void *arg;
    /* 0x8 */ int priority;
    /* 0xc */ struct PMSleepCallbackInfo *next;
} PMSleepCallbackInfo; // size 0x10

static inline void PM_SetSleepCallbackInfo(PMSleepCallbackInfo *info, PMSleepCallback callback, void *arg) {
    info->callback = callback;
    info->arg = arg;
}

void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info);
void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info);
void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info);
void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info);

#ifdef __cplusplus
}
#endif

#endif
