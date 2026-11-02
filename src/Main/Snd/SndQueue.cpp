#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResMgr.h"
#include "nitro/fx.h"

extern "C" {

// The sound TU's two .bss objects. Every function of the TU reaches them through the 0x02097e48
// pool literal plus an offset (func_0204a2f0 and func_0204a360 read data_02097e4c that way), so
// they are defined before the first function.
SndQueue *data_02097e48;
SndMgr *data_02097e4c;

typedef struct SndCmd {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 type;
    /* 0x4 */ s16 args[6];
} SndCmd;

void func_0204a3b8(SndMgr *mgr, SndCmd *cmd);

}

// ---- merged from SndMgr_5.cpp
namespace m_02049de8 {
extern "C" {

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
    /* 0xf8 */ VecFx32 pos;
} SndListener;

extern s32 data_0208b700;
extern SndListener *data_ov000_021ccd54;
extern SndAreaEntry data_0208b7c8[];
extern s32 data_0208b704;
extern s32 data_0208b744[];

extern int func_0204061c(s32 *out, const VecFx32 *pos);
extern void NNS_SndPlayerPause(SndHandle *handle, int pause);
extern s32 OS_GetThreadPriority(void *thread);
extern BOOL OS_SetThreadPriority(void *thread, s32 prio);

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

s32 func_02049e20(SndMgr *mgr, const VecFx32 *pos) {
    SndListener *listener = data_ov000_021ccd54;
    s32 *range = NULL;
    s32 i;
    VecFx32 vec;
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

SndHandle *func_02049f44(SndMgr *mgr, s32 id, const VecFx32 *pos, s32 pitch);

SndHandle *func_0204a028(SndMgr *mgr, s32 id, const VecFx32 *pos, s32 pitch);

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

void SndMgr_PauseAll(SndMgr *mgr);

void SndMgr_ResumeAll(SndMgr *mgr);

void func_0204a20c(SndMgr *mgr, s32 strmNo);

void func_0204a284(SndMgr *mgr, s32 arg);

void func_0204a2a8(SndMgr *mgr, s32 volume, s32 frames);

s32 func_0204a2c8(SndMgr *mgr, s32 seq);

void func_0204a2e0(SndMgr *mgr, int fadeFrames);

void func_0204a2f0(SndMgr *mgr, s32 id);

void func_0204a360(SndMgr *self, s32 arg);



}
// @exclude func_0204a3b8
}  // namespace m_02049de8

// ---- merged from SndMgr_6.cpp
namespace m_02049f44 {
extern "C" {

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

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
    /* 0xf8 */ VecFx32 pos;
} SndListener;

extern s32 data_0208b700;
extern SndListener *data_ov000_021ccd54;
extern SndAreaEntry data_0208b7c8[];
extern s32 data_0208b704;
extern s32 data_0208b744[];

extern int func_0204061c(s32 *out, const VecFx32 *pos);
extern void NNS_SndPlayerPause(SndHandle *handle, int pause);
extern s32 OS_GetThreadPriority(void *thread);
extern BOOL OS_SetThreadPriority(void *thread, s32 prio);

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

s32 func_02049e20(SndMgr *mgr, const VecFx32 *pos);

SndHandle *func_02049f44(SndMgr *mgr, s32 id, const VecFx32 *vec, s32 pitch) {
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

SndHandle *func_0204a028(SndMgr *mgr, s32 id, const VecFx32 *vec, s32 pitch) {
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

void SndMgr_PauseAll(SndMgr *mgr) {
    s32 i;
    SndHandle *handle;
    for (i = 0; i < 5; i++) {
        handle = &mgr->seqArc[i];
        if ((handle->player != NULL ? TRUE : FALSE)) {
            NNS_SndPlayerPause(handle, TRUE);
            mgr->seqArcPaused[i] = 1;
        } else {
            mgr->seqArcPaused[i] = 0;
        }
    }
}

void SndMgr_ResumeAll(SndMgr *mgr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (mgr->seqArcPaused[i] != 0) {
            NNS_SndPlayerPause(&mgr->seqArc[i], FALSE);
            mgr->seqArcPaused[i] = 0;
        }
    }
}

void func_0204a20c(SndMgr *mgr, s32 strmNo) {
    void *thread;
    s32 prio;
    if (func_02031904((StrmHandle *)&mgr->strm, strmNo, 0)) {
        mgr->curStrm = strmNo;
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
        mgr->curStrm = -1;
    }
}

void func_0204a284(SndMgr *mgr, s32 arg) {
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
    SndMgr_RequestLoad(data_02097e4c, 1, id, -1);
    mgr->loadedSeqEx[0] = id;
    SndMgr_RequestLoad(data_02097e4c, 5, 0x26, 1);
    SndMgr_RequestLoad(data_02097e4c, 5, 0x24, 2);
}

void func_0204a360(SndMgr *self, s32 arg) {
    SndMgr *mgr = data_02097e4c;
    if (mgr->heapLevels[1] >= 1) {
        NNS_SndHeapLoadState(mgr->heaps[1], 1);
        mgr->heapLevels[1] = 1;
    }
    SndMgr_RequestLoad(data_02097e4c, 4, 2, -1);
}


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
extern void *Heap_AllocHi(u32 size, u32 align);
extern void Heap_FreeHi(void *ptr);
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

    if (mgr->fileBuf != 0) {
        return FALSE;
    }
    SndMgr_TwlOpen();
    mgr->fileBuf = (s32)Heap_AllocHi(0x10000, 4);
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
    mgr->fileSize = len;
    if (FS_ReadFile(&file, (void *)mgr->fileBuf, len) == -1) {
        OS_Terminate();
        return FALSE;
    }
    FS_CloseFile(&file);
    DC_StoreRange((void *)mgr->fileBuf, mgr->fileSize);
    return TRUE;
}

void SndMgr_FreeFileBuf(SndMgr *mgr) {
    if (OS_IsRunOnTwl()) {
        func_0221dfa0();
    }
    if (mgr->fileBuf != 0) {
        Heap_FreeHi((void *)mgr->fileBuf);
        mgr->fileBuf = 0;
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
    void *buf = (void *)mgr->fileBuf;
    s32 len;

    if (buf == NULL) {
        return;
    }
    len = mgr->fileSize;
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
}  // namespace m_02049f44

// ---- SndQueue.cpp
extern "C" {

#define SND_QUEUE data_02097e48
#define SND_MGR data_02097e4c

extern void *Heap_Alloc(u32 size);
extern void *Heap_AllocLo(u32 size, int align);
extern SndMgr *func_020492e0(SndMgr *mgr);
extern void func_02049344(SndMgr *mgr);
void func_0204a924(SndQueue *queue);


void func_0204a87c(void) {
    if (SND_MGR == NULL) {
        SndMgr *mgr;
        data_02097dd0->cur = data_02097dd0->heapLo;
        mgr = (SndMgr *)Heap_Alloc(sizeof(SndMgr));
        if (mgr != NULL) {
            mgr = func_020492e0(mgr);
        }
        SND_MGR = mgr;
        data_02097dd0->cur = data_02097dd0->heapHi;
        func_02049344(SND_MGR);
    }
    if (SND_QUEUE == NULL) {
        SND_QUEUE = (SndQueue *)Heap_AllocLo(sizeof(SndQueue), 4);
        func_0204a924(SND_QUEUE);
    }
}

void func_0204a904(void) {
    NNS_SndPlayerStopSeqAll(0);
    func_0204a924(SND_QUEUE);
}

static inline void SndQueue_Reset(SndQueue *queue) {
    s32 i;
    queue->nodes[0].prev = &queue->nodes[1];
    queue->nodes[0].value = 0xffff;
    queue->nodes[0].next = &queue->nodes[SND_QUEUE_NODES - 1];
    for (i = 1; i < SND_QUEUE_NODES - 1; i++) {
        queue->nodes[i].value = 0xffff;
        queue->nodes[i].next = &queue->nodes[i - 1];
        queue->nodes[i].prev = &queue->nodes[i + 1];
    }
    queue->nodes[i].value = 0xffff;
    queue->nodes[i].next = &queue->nodes[i - 1];
    queue->nodes[i].prev = &queue->nodes[0];
    queue->cur = &queue->nodes[0];
}

void func_0204a924(SndQueue *queue);

void func_0204aa10(SndQueue *queue);

void SndQueue_Pop(SndQueue *queue);

void func_0204aab0(SndQueue *queue, u16 value);

u16 SndQueue_Peek(SndQueue *queue);

void func_0204aad0(SndQueue *queue);

void func_0204aaec(SndQueue *queue, SndCmd *cmd);

void SndQueue_StopSeqArcs(SndQueue *queue);

}

extern "C" {

extern void NNS_SndMain(void);

static inline void SndQueue_Push(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

void func_0204ab8c(SndQueue *queue);

}

// ---- merged from SndQueue_2.cpp
namespace m_0204a924 {
extern "C" {


extern void *Heap_Alloc(u32 size);
extern void *Heap_AllocLo(u32 size, int align);
extern void *func_020492e0(SndMgr *mgr);
extern void func_02049344(SndMgr *mgr);


void func_0204a87c(void);

void func_0204a904(void);

// The neighbour links are byte offsets from the node array: the target computes i * 12 once
// and adds -12 and +12 to it.
static inline void SndQueue_ResetNodes(SndQueue *queue) {
    int i;
    queue->nodes[0].value = 0xffff;
    queue->nodes[0].next = &queue->nodes[SND_QUEUE_NODES - 1];
    queue->nodes[0].prev = &queue->nodes[1];
    for (i = 1; i < SND_QUEUE_NODES - 1; i++) {
        u32 off = i * sizeof(SndQueueNode);
        queue->nodes[i].value = 0xffff;
        queue->nodes[i].next = (SndQueueNode *)((u8 *)queue->nodes + (off - sizeof(SndQueueNode)));
        queue->nodes[i].prev = (SndQueueNode *)((u8 *)queue->nodes + (off + sizeof(SndQueueNode)));
    }
    queue->nodes[i].value = 0xffff;
    queue->nodes[i].next = &queue->nodes[i - 1];
    queue->nodes[i].prev = &queue->nodes[0];
    queue->cur = &queue->nodes[0];
}

void func_0204a924(SndQueue *queue) {
    queue->flag0 = 1;
    queue->flag1 = 0;
    queue->flag2 = 0;
    queue->flag3 = 1;
    queue->unk_02 = 0;
    queue->unk_04 = 0xffff;
    queue->unk_06 = 0xffff;
    queue->unk_08 = 10;
    queue->unk_70 = 0;
    queue->unk_7c = 0;
    queue->unk_72 = 0xffff;
    queue->unk_74 = 0xffff;
    queue->unk_78 = -1;
    queue->unk_7e = 0xffff;
    queue->unk_80 = 0xffff;
    SndQueue_ResetNodes(queue);
}

void func_0204aa10(SndQueue *queue) {
    SndQueue_ResetNodes(queue);
}

void SndQueue_Pop(SndQueue *queue) {
    queue->cur->value = 0xffff;
    queue->cur = queue->cur->next;
}

void func_0204aab0(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

u16 SndQueue_Peek(SndQueue *queue) {
    return queue->cur->value;
}

void func_0204aad0(SndQueue *queue) {
    SndMgr *mgr = SND_MGR;
    mgr->seqArcNext = 0;
    mgr->unk_9c = 0;
}

void func_0204aaec(SndQueue *queue, SndCmd *cmd) {
    switch (cmd->type) {
        case 0:
            if (!queue->flag0) {
                return;
            }
            queue->unk_04 = cmd->args[0];
            break;
        case 1:
        case 3:
            if (!queue->flag3) {
                return;
            }
            queue->unk_04 = 0xffff;
            break;
    }
    func_0204a3b8(SND_MGR, cmd);
}

void SndQueue_StopSeqArcs(SndQueue *queue) {
    s32 i;
    SndMgr *mgr = SND_MGR;
    for (i = 0; i < 5; i++) {
        NNS_SndPlayerStopSeq(&mgr->seqArc[i], 0);
    }
}

}

extern "C" {

extern void NNS_SndMain(void);

static inline void SndQueue_Push(SndQueue *queue, u16 value) {
    queue->cur = queue->cur->prev;
    queue->cur->value = value;
}

void func_0204ab8c(SndQueue *queue) {
    NNS_SndMain();
    if (queue->unk_06 != 0xffff) {
        switch (queue->unk_02) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_04 = queue->unk_06;
                queue->unk_06 = 0xffff;
                SndMgr_PlayBgm(SND_MGR, queue->unk_04);
                break;
            case 0:
                if (queue->unk_04 != 0xffff) {
                    NNS_SndPlayerStopSeqBySeqNo(queue->unk_04, queue->unk_08);
                    SndQueue_Push(queue, queue->unk_04);
                    queue->unk_04 = 0xffff;
                    queue->unk_02 = queue->unk_02 + 1;
                } else {
                    SndQueue_Push(queue, 0xffff);
                    queue->unk_02 = 10;
                }
                if (queue->unk_06 == 0x8000) {
                    queue->unk_06 = 0xffff;
                    queue->unk_02 = 0;
                }
                break;
            default:
                queue->unk_02++;
                break;
        }
    }
    if (queue->unk_74 != 0xffff) {
        switch (queue->unk_70) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_72 = queue->unk_74;
                queue->unk_74 = 0xffff;
                queue->unk_78 = func_02049afc(SND_MGR, queue->unk_72);
                break;
            case 0:
                if (queue->unk_72 != 0xffff) {
                    SndMgr_StopSlot(SND_MGR, queue->unk_78);
                    queue->unk_72 = 0xffff;
                    queue->unk_78 = -1;
                    queue->unk_70 = queue->unk_70 + 1;
                } else {
                    queue->unk_70 = 10;
                }
                if (queue->unk_74 == 0x8000) {
                    queue->unk_74 = 0xffff;
                    queue->unk_78 = -1;
                    queue->unk_70 = 0;
                }
                break;
            default:
                queue->unk_70++;
                break;
        }
    }
    if (queue->unk_80 != 0xffff) {
        switch (queue->unk_7c) {
            case 10:
                if (queue->flag1 == 1) {
                    break;
                }
                queue->unk_7e = queue->unk_80;
                queue->unk_80 = 0xffff;
                func_0204a20c(SND_MGR, queue->unk_7e);
                SndMgr_SetStrmVolume(SND_MGR, 0x32, 0);
                break;
            case 0:
                if (queue->unk_7e != 0xffff) {
                    SndMgr_StopStrm(SND_MGR);
                    queue->unk_7e = 0xffff;
                    queue->unk_7c = queue->unk_7c + 1;
                } else {
                    queue->unk_7c = 10;
                }
                if (queue->unk_80 == 0x8000) {
                    queue->unk_80 = 0xffff;
                    queue->unk_7c = 0;
                }
                break;
            default:
                queue->unk_7c++;
                break;
        }
    }
}

}
}  // namespace m_0204a924
