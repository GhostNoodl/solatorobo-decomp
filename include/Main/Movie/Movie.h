#ifndef MAIN_MOVIE_MOVIE_H
#define MAIN_MOVIE_MOVIE_H

#include "types.h"
#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

// Sleep callback, registered with the power manager.
typedef struct MovieSleepCb {
    /* 0x0 */ void (*func)(void);
    /* 0x4 */ void *arg;
    /* 0x8 */ u32 unk_8[2];
} MovieSleepCb;

// Mobiclip movie player.
typedef struct Movie {
    /* 0x000 */ u8 decoder[0xc0];
    /* 0x0c0 */ void *buf;
    /* 0x0c4 */ char name[0x20];
    /* 0x0e4 */ const char **names;
    /* 0x0e8 */ u16 unk_0e8;
    /* 0x0ec */ u32 file[0x12];
    /* 0x134 */ void *audio;
    /* 0x138 */ u32 unk_138;
    /* 0x13c */ u32 unk_13c;
    /* 0x140 */ u32 unk_140;
    /* 0x144 */ u32 sampleRate;
    /* 0x148 */ u8 channels;
    /* 0x149 */ u8 state;
    /* 0x14a */ u8 loop : 1;
    /* 0x14a */ u8 paused : 1;
    /* 0x14a */ u8 mode : 2;
    /* 0x14a */ u8 unk_14a_4 : 4;
    /* 0x14b */ u8 opened : 1;
    /* 0x14b */ u8 playing : 1;
    /* 0x14b */ u8 soundOn : 1;
    /* 0x14b */ u8 unk_14b_3 : 5;
    /* 0x14c */ u32 numQueued;
    /* 0x150 */ u32 writePos;
    /* 0x154 */ u32 numBlocks;
    /* 0x158 */ u32 blockCount;
    /* 0x15c */ u32 bufSize;
    /* 0x160 */ s16 *bufL;
    /* 0x164 */ s16 *bufR;
    /* 0x168 */ MovieSleepCb preSleep;
    /* 0x178 */ MovieSleepCb postSleep;
} Movie; // size 0x188

extern Movie *data_02097e3c;

#ifdef __cplusplus
}
#endif

#endif
