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

extern s32 VEC_Distance(SndVec *vec);
extern int func_0204061c(s32 *out, const SndVec *pos);
extern void NNS_SndPlayerPause(SndHandle *handle, int pause);
extern s32 OS_GetThreadPriority(void *thread);
extern BOOL OS_SetThreadPriority(void *thread, s32 prio);

s32 func_02049bdc(SndMgr *mgr, s32 id, s32 pan) {
    s32 seqArc;
    s32 index;
    SndHandle *handle;
    if (id < 0) {
        return -1;
    }
    if (pan < -0x200 || pan > 0x1ff) {
        return -1;
    }
    handle = func_02049984(mgr, id, &seqArc, &index);
    if (handle == NULL) {
        return -1;
    }
    if (!NNS_SndArcPlayerStartSeqArc(handle, seqArc, index)) {
        return -1;
    }
    NNS_SndPlayerSetTrackPitch(handle, 1, pan << 6);
    NNS_SndPlayerSetPlayerPriority(handle, 0x40);
    return 1;
}

s32 func_02049c80(SndMgr *mgr, s32 id, s32 volume, s32 pan, s32 pitch, s32 useSlot, u32 slot);

#ifdef NONMATCHING
// 60 raw / 12 aligned-masked (round bgW; was 85 / 24). The ROM tests useSlot once, with the slot check
// inside the useSlot arm after the zero (round svA). Written that way with a plain `if (slot >= 5)
// return -1;` the slot return is derived from the zero (`sub r0, r5, #1`), the -1 group is only four
// and is not hoisted into r4. In the ROM the slot return is a fresh `mvn` and the result < 0 return is
// zero - 1, so the slot-fail block must lie outside the zero's extended block. A slot-load inline
// whose early return joins its result (SndMgr_LoadSlot) gives the -1 group of five and the hoisted r4
// (cmp r8, r4 / sub r0, r4, #0x7f), but the join then breaks the extended block for the result < 0
// return instead (fresh `mvnlt`), and result shares the zero's register (6 saved registers, ROM 8).
// Tried (bgW): a BOOL slot-valid inline (87 / 18, the join survives as movlo + cmp), the inline with
// `r = -1` and an if (59 / 13), the result < 0 test inside the inline (84 / 17), `return result` for
// it (82 / 25), the two-test form with the arms swapped or nested (84 / 49); honest_search from this
// draft (916 compiles): nothing.
static inline s32 SndMgr_LoadSlot(SndMgr *mgr, s32 id, u32 slot) {
    s32 r;
    if (slot >= 5) {
        return -1;
    }
    r = func_02049afc(mgr, id);
    mgr->seqArcSlots[slot] = r;
    return r;
}

s32 func_02049c80(SndMgr *mgr, s32 id, s32 volume, s32 pitch, s32 pan, s32 useSlot, u32 slot) {
    SndHandle *handle;
    s32 seqArc;
    s32 index;
    s32 result;
    if (id < 0) {
        return -1;
    }
    result = 0;
    if (!useSlot) {
        handle = func_02049984(mgr, id, &seqArc, &index);
        if (handle == NULL) {
            return -1;
        }
        if (!NNS_SndArcPlayerStartSeqArc(handle, seqArc, index)) {
            return -1;
        }
    } else {
        result = SndMgr_LoadSlot(mgr, id, slot);
        if (result < 0) {
            return -1;
        }
        if (++mgr->seqArcNext >= 5) {
            mgr->seqArcNext = 0;
        }
        handle = mgr->seqArcHandles[result];
    }
    if (pitch != -1) {
        s32 v = pitch - 0x40;
        if (v < -0x80) {
            v = -0x80;
        }
        if (v > 0x7f) {
            v = 0x7f;
        }
        NNS_SndPlayerSetTrackPitch(handle, 1, v);
    }
    if (pan != -1) {
        s32 v = (pan - 0x40) * 2;
        if (v < -0x80) {
            v = -0x80;
        }
        if (v > 0x7f) {
            v = 0x7f;
        }
        NNS_SndPlayerSetTrackPan(handle, 1, v);
    }
    if (volume != -1) {
        if (volume < 0) {
            volume = 0;
        }
        if (volume > 0x7f) {
            volume = 0x7f;
        }
        NNS_SndPlayerMoveVolume(handle, volume, 0);
    }
    NNS_SndPlayerSetPlayerPriority(handle, 0x40);
    return result;
}
#endif

static inline void SndMgr_StopSe(SndMgr *mgr, s32 id) {
    s32 seqArc;
    s32 index;
    if (func_02049984(mgr, id, &seqArc, &index) == NULL) {
        return;
    }
    NNS_SndPlayerStopSeqBySeqArcIdx(seqArc, index, 0);
}

void func_02049de8(SndMgr *mgr, s32 id);

static inline BOOL SndMgr_IsArea(SndListener *listener, u8 a, u8 b, u8 c) {
    return (listener->a == a && listener->b == b && listener->c == c) ? TRUE : FALSE;
}

s32 func_02049e20(SndMgr *mgr, const SndVec *pos);

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
