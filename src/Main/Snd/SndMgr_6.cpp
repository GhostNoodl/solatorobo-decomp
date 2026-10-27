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

void func_02049de8(SndMgr *mgr, s32 id);

static inline BOOL SndMgr_IsArea(SndListener *listener, u8 a, u8 b, u8 c) {
    return (listener->a == a && listener->b == b && listener->c == c) ? TRUE : FALSE;
}

s32 func_02049e20(SndMgr *mgr, const SndVec *pos);

SndHandle *func_02049f44(SndMgr *mgr, s32 id, const SndVec *vec, s32 pitch) {
    s32 seqArc;
    s32 index;
    s32 vol;
    s32 out[2];
    s32 p;
    SndHandle *handle;
    if (id < 0) {
        return NULL;
    }
    vol = func_02049e20(mgr, vec);
    if (vol <= 0) {
        return NULL;
    }
    func_0204061c(out, vec);
    p = out[0] - 0x80;
    if (p > 0x7f) {
        p = 0x7f;
    }
    if (p < -0x80) {
        p = -0x80;
    }
    handle = func_02049984(mgr, id, &seqArc, &index);
    if (handle == NULL) {
        return NULL;
    }
    if (!NNS_SndArcPlayerStartSeqArc(handle, seqArc, index)) {
        return NULL;
    }
    NNS_SndPlayerSetTrackPitch(handle, 1, pitch);
    NNS_SndPlayerSetTrackPan(handle, 1, p);
    NNS_SndPlayerSetVolume(handle, vol);
    return handle;
}

SndHandle *func_0204a028(SndMgr *mgr, s32 id, const SndVec *vec, s32 pitch) {
    if (pitch < -0x200 || pitch > 0x1ff) {
        return NULL;
    }
    return func_02049f44(mgr, id, vec, pitch << 6);
}

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

void func_0204a058(SndMgr *mgr, u32 slot, s32 volume, s32 frames) {
    SndMgr_SetSlotVolume(mgr, slot, volume, frames);
}

void func_0204a094(SndMgr *mgr, u32 slot, s32 pan) {
    SndHandle *handle;
    if (pan < -0x8000 || pan > 0x7fff) {
        return;
    }
    handle = SndMgr_GetSlotHandle(mgr, slot);
    if (handle == NULL) {
        return;
    }
    NNS_SndPlayerSetTrackPitch(handle, 1, pan);
}

void func_0204a0d4(SndMgr *mgr, u32 slot, s32 pan) {
    SndHandle *handle;
    if (pan < -0x200 || pan > 0x1ff) {
        return;
    }
    handle = SndMgr_GetSlotHandle(mgr, slot);
    if (handle == NULL) {
        return;
    }
    NNS_SndPlayerSetTrackPitch(handle, 1, pan << 6);
}

BOOL func_0204a118(SndMgr *mgr, s32 id) {
    s32 i;
    BOOL ret;
    for (i = 0; i < data_0208b704; i++) {
        ret = FALSE;
        if (id == data_0208b744[i]) {
            return TRUE;
        }
    }
    return ret;
}

void func_0204a160(SndMgr *mgr) {
    s32 i;
    SndHandle *handle;
    for (i = 0; i < 5; i++) {
        handle = &mgr->seqArc[i];
        if ((handle->player != NULL ? TRUE : FALSE)) {
            NNS_SndPlayerPause(handle, TRUE);
            mgr->unk_70[i] = 1;
        } else {
            mgr->unk_70[i] = 0;
        }
    }
}

void func_0204a1c4(SndMgr *mgr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (mgr->unk_70[i] != 0) {
            NNS_SndPlayerPause(&mgr->seqArc[i], FALSE);
            mgr->unk_70[i] = 0;
        }
    }
}

void func_0204a20c(SndMgr *mgr, s32 strmNo) {
    void *thread;
    s32 prio;
    if (func_02031904((StrmHandle *)&mgr->strm, strmNo, 0)) {
        mgr->unk_48 = strmNo;
        func_02031948((StrmHandle *)&mgr->strm, 0x7f);
        thread = func_02031ac0();
        prio = 0xf;
        if (mgr->unk_5b) {
            prio = 0x11;
        }
        if (prio != OS_GetThreadPriority(thread)) {
            OS_SetThreadPriority(thread, prio);
        }
    } else {
        mgr->unk_48 = -1;
    }
}

void func_0204a284(SndMgr *mgr) {
    SndMgr_StopStrm(mgr);
}

void func_0204a2a8(SndMgr *mgr, s32 volume, s32 frames) {
    SndMgr_SetStrmVolume(mgr, volume, frames);
}

s32 func_0204a2c8(SndMgr *mgr, s32 seq) {
    return SndMgr_GetSeqVolume(seq);
}

void func_0204a2e0(SndMgr *mgr, int fadeFrames) {
    NNS_SndPlayerStopSeqAll(fadeFrames);
}

void func_0204a2f0(SndMgr *mgr, s32 id) {
    SndMgr_RequestLoad(data_02097e48.mgr, 1, id, -1);
    mgr->loadedSeqEx[0] = id;
    SndMgr_RequestLoad(data_02097e48.mgr, 5, 0x26, 1);
    SndMgr_RequestLoad(data_02097e48.mgr, 5, 0x24, 2);
}

void func_0204a360(void) {
    SndMgr *mgr = data_02097e48.mgr;
    if (mgr->heapLevels[1] >= 1) {
        NNS_SndHeapLoadState(mgr->heaps[1], 1);
        mgr->heapLevels[1] = 1;
    }
    SndMgr_RequestLoad(data_02097e48.mgr, 4, 2, -1);
}

typedef struct SndCmd {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 args[6];
} SndCmd;

void func_0204a3b8(SndMgr *mgr, SndCmd *cmd) {
    switch (cmd->type) {
    case 0:
        mgr->playAfterLoad = TRUE;
        SndMgr_RequestLoad(mgr, 1, cmd->args[0], cmd->args[2]);
        break;
    case 1:
        NNS_SndPlayerStopSeqBySeqNo(cmd->args[0], 10);
        break;
    case 3:
        NNS_SndPlayerStopSeqBySeqNo(cmd->args[0], cmd->args[2]);
        break;
    case 6:
        func_02049c80(mgr, cmd->args[0], cmd->args[1], cmd->args[2], cmd->args[3], cmd->args[4], cmd->args[5]);
        break;
    case 7:
        if (cmd->args[2] == 1) {
            SndMgr_StopSlot(mgr, mgr->seqArcSlots[cmd->args[5]]);
            mgr->seqArcNext--;
        } else {
            SndMgr_StopSe(mgr, cmd->args[0]);
        }
        break;
    case 12:
        if (cmd->args[4] == 1) {
            SndMgr_SetSlotVolume(mgr, mgr->seqArcSlots[cmd->args[5]], cmd->args[2], cmd->args[3]);
        }
        break;
    case 9:
        func_0204a20c(mgr, cmd->args[1]);
        break;
    case 10:
        SndMgr_StopStrm(mgr);
        break;
    }
}

typedef struct SndFile {
    u8 data[0x48];
} SndFile;

extern u32 FS_GetFileLength(void *file);
extern void DC_StoreRange(const void *startAddr, u32 nBytes);
extern void OS_Terminate(void);
extern void OS_Sleep(u32 msec);
extern BOOL OS_IsRunOnTwl(void);
extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern char data_0208b6e0[];
/* TWL only */
extern void func_0228ee0c(u32 a, u32 b);
extern void func_0228f2c4(u32 a, u32 b);
extern void func_0221defc(SndFile *file);
extern BOOL func_0221df38(SndFile *file, u32 a, u32 b);
extern s32 func_0221d814(u32 *out);
extern void func_0221dfa0(void);
extern void func_02219778(void *buf, s32 len);
extern s32 func_022198cc(void);

// Nothing in the NDS build calls the TWL-only functions below.
#pragma force_active on

static inline void SndMgr_TwlOpen(void) {
    SndFile file;

    func_0228ee0c(1, 0);
    func_0228f2c4(1, 0);
    func_0228ee0c(2, 0);
    func_0228f2c4(2, 0);
    FS_InitFile(&file);
    if (OS_IsRunOnTwl()) {
        func_0221defc(&file);
    }
    if (!(OS_IsRunOnTwl() ? func_0221df38(&file, 1, 1) : FALSE)) {
        OS_Terminate();
    }
    FS_CloseFile(&file);
}

BOOL func_0204a598(SndMgr *mgr) {
    SndFile file;
    u32 status;
    s32 result;
    s32 len;

    if (mgr->unk_a0 != 0) {
        return FALSE;
    }
    SndMgr_TwlOpen();
    mgr->unk_a0 = (s32)func_0203de84(0x10000, 4);
    result = 4;
    if (OS_IsRunOnTwl() == TRUE) {
        result = func_0221d814(&status);
    }
    if (result != 0) {
        OS_Terminate();
        return FALSE;
    }
    if (status != 0) {
        OS_Terminate();
        return FALSE;
    }
    if (!FS_OpenFileEx(&file, (void *)data_0208b6e0, 1)) {
        OS_Terminate();
        return FALSE;
    }
    len = FS_GetFileLength(&file);
    mgr->unk_a4 = len;
    if (FS_ReadFile(&file, (void *)mgr->unk_a0, len) == -1) {
        OS_Terminate();
        return FALSE;
    }
    FS_CloseFile(&file);
    DC_StoreRange((void *)mgr->unk_a0, mgr->unk_a4);
    return TRUE;
}

void func_0204a734(SndMgr *mgr) {
    if (OS_IsRunOnTwl()) {
        func_0221dfa0();
    }
    if (mgr->unk_a0 != 0) {
        func_0203df0c((void *)mgr->unk_a0);
        mgr->unk_a0 = 0;
    }
}

static inline s32 SndMgr_TwlIsBusy(void) {
    s32 busy = 0;
    if (OS_IsRunOnTwl()) {
        busy = func_022198cc();
    }
    return busy;
}

void func_0204a768(SndMgr *mgr) {
    void *buf = (void *)mgr->unk_a0;
    s32 len;

    if (buf == NULL) {
        return;
    }
    len = mgr->unk_a4;
    if (OS_IsRunOnTwl()) {
        func_02219778(buf, len);
    }
    while (SndMgr_TwlIsBusy()) {
        OS_Sleep(100);
    }
    if (OS_IsRunOnTwl()) {
        func_0221dfa0();
    }
}

void func_0204a7dc(void) {
    SndMgr_TwlOpen();
}

#pragma force_active reset

}
