#ifndef MAIN_SND_SNDMGR_H
#define MAIN_SND_SNDMGR_H

#include "types.h"
#include "nnsys/snd/heap.h"
#include "nnsys/snd/sndarc.h"
#include "nnsys/snd/sndarc_stream.h"

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

typedef struct SndQueueNode {
    /* 0x0 */ u16 value;
    /* 0x4 */ struct SndQueueNode *next;
    /* 0x8 */ struct SndQueueNode *prev;
} SndQueueNode; // size 0xc

#define SND_QUEUE_NODES 8

typedef struct SndQueue {
    /* 0x00 */ u16 flag0 : 1;
    /* 0x00 */ u16 flag1 : 1;
    /* 0x00 */ u16 flag2 : 1;
    /* 0x00 */ u16 flag3 : 1;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0c */ SndQueueNode nodes[SND_QUEUE_NODES];
    /* 0x6c */ SndQueueNode *cur;
    /* 0x70 */ u16 unk_70;
    /* 0x72 */ u16 unk_72;
    /* 0x74 */ u16 unk_74;
    /* 0x78 */ s32 unk_78;
    /* 0x7c */ u16 unk_7c;
    /* 0x7e */ u16 unk_7e;
    /* 0x80 */ u16 unk_80;
} SndQueue; // size 0x84

typedef struct SndGlobal {
    /* 0x00 */ SndQueue *queue;
    /* 0x04 */ SndMgr *mgr;
} SndGlobal;

// The sound TU defines these as two globals (queue, mgr); other TUs see them as one struct.
#ifndef SND_DEFINE_GLOBALS
extern SndGlobal data_02097e48;
#endif
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

static inline void SndMgr_PlayBgm(SndMgr *mgr, s32 seq) {
    mgr->curBgm = -1;
    if (mgr->noAutoPlay) {
        mgr->playAfterLoad = FALSE;
    } else {
        mgr->playAfterLoad = TRUE;
    }
    SndMgr_RequestLoad(mgr, 1, seq, -1);
}

static inline void SndMgr_StopSlot(SndMgr *mgr, s32 idx) {
    if (idx < 0 || idx >= 5) {
        return;
    }
    func_0202eb80(&mgr->seqArc[idx], 0);
}

static inline void SndMgr_StopStrm(SndMgr *mgr) {
    func_0203192c((StrmHandle *)&mgr->strm, 10);
    mgr->unk_48 = -1;
}

static inline void SndMgr_SetStrmVolume(SndMgr *mgr, s32 volume, s32 frames) {
    if (volume < 0) {
        volume = 0;
    }
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    func_0203195c((StrmHandle *)&mgr->strm, volume, frames);
}

void func_0204a20c(SndMgr *mgr, s32 strmNo);

#ifdef __cplusplus
}
#endif

#endif
