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

void func_02048be4(PlayTime *t);
void func_02048bfc(PlayTime *t, BOOL toMinutes);
void func_02048cf0(PlayTime *t, u16 hours, u16 minutes, u16 seconds, u16 millis);
void func_02048d58(PlayTime *dst, const PlayTime *a, const PlayTime *b);
void func_02048e74(PlayTime *dst, const PlayTime *a, const PlayTime *b);
void func_02049088(PlayTime *t, u32 frames);

#ifdef __cplusplus
}
#endif

#endif
