#include "Main/Snd/SndMgr.h"

extern "C" {

typedef struct SndVec {
    s32 x;
    s32 y;
    s32 z;
} SndVec;

typedef struct SndAreaEntry {
    /* 0x0 */ u8 a;
    /* 0x1 */ u8 b;
    /* 0x2 */ u8 c;
    /* 0x4 */ s32 *range;
} SndAreaEntry;

typedef struct SndListener {
    /* 0x00 */ u8 unk_00[0xca];
    /* 0xca */ u8 a;
    /* 0xcb */ u8 b;
    /* 0xcc */ u8 c;
    /* 0xcd */ u8 unk_cd[0xf8 - 0xcd];
    /* 0xf8 */ SndVec pos;
} SndListener;

extern s32 data_0208b700;
extern SndListener *data_ov000_021ccd54;
extern SndAreaEntry data_0208b7c8[];
extern s32 data_0208b704;
extern s32 data_0208b744[];

extern s32 VEC_Distance(const SndVec *a, const SndVec *b);
extern u32 _fflt(s32 v);
extern u32 _fsub(u32 a, u32 b);
extern u32 _fdiv(u32 a, u32 b);
extern u32 _fmul(u32 a, u32 b);
extern s32 _ffix(u32 a);
extern void func_0204061c(s32 *out, const SndVec *pos);
extern void NNS_SndPlayerPause(SndHandle *handle, int pause);
extern s32 OS_GetThreadPriority(void *thread);
extern void OS_SetThreadPriority(void *thread, s32 prio);

s32 func_02049bdc(SndMgr *mgr, s32 id, s32 pan);

s32 func_02049c80(SndMgr *mgr, s32 id, s32 volume, s32 pan, s32 pitch, s32 useSlot, u32 slot);

static inline void SndMgr_StopSe(SndMgr *mgr, s32 id) {
    s32 seqArc;
    s32 index;
    if (func_02049984(mgr, id, &seqArc, &index) == NULL) {
        return;
    }
    NNS_SndPlayerStopSeqBySeqArcIdx(seqArc, index, 0);
}

void func_02049de8(SndMgr *mgr, s32 id) {
    s32 seqArc;
    s32 index;
    if (func_02049984(mgr, id, &seqArc, &index) == NULL) {
        return;
    }
    NNS_SndPlayerStopSeqBySeqArcIdx(seqArc, index, 0);
}

static inline BOOL SndMgr_IsArea(SndListener *listener, u8 a, u8 b, u8 c) {
    return (listener->a == a && listener->b == b && listener->c == c) ? TRUE : FALSE;
}

// The listener bytes are compared through a pointer taken from the global inside the loop,
// so the first one is loaded in every iteration, as in the target.
static inline BOOL SndMgr_IsAreaAt(const u8 *p, u8 a, u8 b, u8 c) {
    BOOL r = FALSE;
    if (p[0] == a && p[1] == b && p[2] == c) {
        r = TRUE;
    }
    return r;
}

s32 func_02049e20(SndMgr *mgr, const SndVec *pos) {
    SndListener *listener = data_ov000_021ccd54;
    s32 *range = NULL;
    s32 i;
    SndVec vec;
    s32 dist;
    s32 vol;
    for (i = 0; i < data_0208b700; i++) {
        SndAreaEntry *e = &data_0208b7c8[i];
        u8 a = e->a;
        u8 b = e->b;
        u8 c = e->c;
        range = e->range;
        if (SndMgr_IsAreaAt(&data_ov000_021ccd54->a, a, b, c)) {
            break;
        }
    }
    if (range == NULL) {
        return 0;
    }
    vec = listener->pos;
    dist = VEC_Distance(&vec, pos);
    vol = (s32)(((float)(range[1] + range[0]) - (float)dist) / (float)range[1] * 127.0f);
    if (vol < 0) {
        vol = 0;
    }
    if (vol > 0x7f) {
        vol = 0x7f;
    }
    return vol;
}

SndHandle *func_02049f44(SndMgr *mgr, s32 id, const SndVec *pos, s32 pitch);

SndHandle *func_0204a028(SndMgr *mgr, s32 id, const SndVec *pos, s32 pitch);

static inline SndHandle *SndMgr_GetSlotHandle(SndMgr *mgr, u32 slot) {
    return slot >= 5 ? NULL : mgr->seqArcHandles[slot];
}

static inline void SndMgr_SetSlotVolume(SndMgr *mgr, u32 slot, s32 volume, s32 frames) {
    SndHandle *handle = SndMgr_GetSlotHandle(mgr, slot);
    if (handle == NULL) {
        return;
    }
    if (volume < 0) {
        volume = 0;
    }
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    NNS_SndPlayerMoveVolume(handle, volume, frames);
}

void func_0204a058(SndMgr *mgr, u32 slot, s32 volume, s32 frames);

void func_0204a094(SndMgr *mgr, u32 slot, s32 pan);

void func_0204a0d4(SndMgr *mgr, u32 slot, s32 pan);

BOOL func_0204a118(SndMgr *mgr, s32 id);

void func_0204a160(SndMgr *mgr);

void func_0204a1c4(SndMgr *mgr);

void func_0204a20c(SndMgr *mgr, s32 strmNo);

void func_0204a284(SndMgr *mgr);

void func_0204a2a8(SndMgr *mgr, s32 volume, s32 frames);

s32 func_0204a2c8(SndMgr *mgr, s32 seq);

void func_0204a2e0(SndMgr *mgr, int fadeFrames);

void func_0204a2f0(SndMgr *mgr, s32 id);

void func_0204a360(void);

typedef struct SndCmd {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 args[6];
} SndCmd;

void func_0204a3b8(SndMgr *mgr, SndCmd *cmd);

}
// @exclude func_0204a3b8
