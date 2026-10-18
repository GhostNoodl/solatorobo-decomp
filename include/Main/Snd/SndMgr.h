#ifndef MAIN_SND_SNDMGR_H
#define MAIN_SND_SNDMGR_H

#include "types.h"
#include "nnsys/snd/heap.h"
#include "nnsys/snd/sndarc.h"

#ifdef __cplusplus
extern "C" {
#endif

// Game sound manager: BGM / SE / voice playback on top of the NitroSystem sound archive player.

typedef struct SndHandle {
    void *player;
} SndHandle;

typedef struct SndMgr {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0c */ s32 unk_0c;
    /* 0x10 */ NNSSndHeap *heaps[2];
    /* 0x18 */ SndHandle bgm;
    /* 0x1c */ SndHandle se;
    /* 0x20 */ SndHandle strm;
    /* 0x24 */ SndHandle voice;
    /* 0x28 */ SndHandle seqArc[5];
    /* 0x3c */ s32 curBgm;
    /* 0x40 */ s32 heapLevels[2];
    /* 0x48 */ s32 unk_48;
    /* 0x4c */ s32 loadType;
    /* 0x50 */ s32 loadId;
    /* 0x54 */ s32 loadArg;
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ u8 playAfterLoad;
    /* 0x5a */ u8 noAutoPlay;
    /* 0x5b */ u8 unk_5b;
    /* 0x5c */ SndHandle *seqArcHandles[5];
    /* 0x70 */ s32 unk_70[5];
    /* 0x84 */ s32 seqArcSlots[5];
    /* 0x98 */ s32 seqArcNext;
    /* 0x9c */ s32 unk_9c;
    /* 0xa0 */ s32 unk_a0;
    /* 0xa4 */ s32 unk_a4;
    /* 0xa8 */ s32 loadedSeq;
    /* 0xac */ s32 loadedSeqEx[3];
    /* 0xb8 */ s32 unk_b8[6];
} SndMgr; // size 0xd0

typedef struct SndGlobal {
    /* 0x00 */ void *queue;
    /* 0x04 */ SndMgr *mgr;
} SndGlobal;

extern SndGlobal data_02097e48;
extern const s8 data_0208b778[];
extern const s32 data_0208b688[];

extern void func_0202eb80(SndHandle *handle, int fadeFrames);
extern void func_0202eb90(int playerNo, int fadeFrames);
extern void func_0202ebe8(int a, int b, int fadeFrames);
extern void func_0202ec4c(int fadeFrames);
extern void func_0202ec9c(SndHandle *handle);
extern void func_0202ecc4(SndHandle *handle, int value);
extern void func_0202ecec(SndHandle *handle, int volume, int frames);
extern void func_0202ed18(SndHandle *handle, int volume);
extern void func_0202ed54(SndHandle *handle, int trackMask, int value);
extern void func_0202ed74(SndHandle *handle, int trackMask, int value);

void func_02049690(SndMgr *mgr);
SndHandle *func_02049984(SndMgr *mgr, s32 id, s32 *outSeqArc, s32 *outIndex);
s32 func_02049afc(SndMgr *mgr, s32 id);

static inline s32 SndMgr_GetSeqVolume(s32 seq) {
    return (u32)seq >= 0x4f ? 0 : data_0208b778[seq];
}

static inline void SndMgr_RequestLoad(SndMgr *mgr, s32 type, s32 id, s32 arg) {
    mgr->loadType = type;
    mgr->loadId = id;
    mgr->loadArg = arg;
    func_02049690(mgr);
}

#ifdef __cplusplus
}
#endif

#endif
