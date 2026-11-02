#ifndef MAIN_SAVE_PLAYTIME_H
#define MAIN_SAVE_PLAYTIME_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Elapsed play time; hours saturate at 999.
typedef struct PlayTime {
    /* 0x00 */ u16 hours;
    /* 0x02 */ u16 minutes;
    /* 0x04 */ u16 seconds;
    /* 0x06 */ u16 millis;
} PlayTime;

void PlayTime_Clear(PlayTime *t);
void func_02048bfc(PlayTime *t, BOOL toMinutes);
void PlayTime_Clamp(PlayTime *t, u16 hours, u16 minutes, u16 seconds, u16 millis);
void PlayTime_Add(PlayTime *dst, const PlayTime *a, const PlayTime *b);
void func_02048e74(PlayTime *dst, const PlayTime *a, const PlayTime *b);
void PlayTime_FromFrames(PlayTime *t, u32 frames);

#ifdef __cplusplus
}
#endif

#endif
