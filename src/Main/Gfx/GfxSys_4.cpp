#include "Main/Gfx/GfxMgr.h"

extern "C" {

// Brightness fade channels, indexed by screen.
typedef struct GfxSysHolder {
    /* 0x00 */ u32 unk_0;
    /* 0x04 */ GfxSys *sys;
    /* 0x08 */ u32 unk_8;
    /* 0x0c */ int fadeEnd[5];
    /* 0x20 */ int fadeTimer[5];
    /* 0x34 */ int fadeState[5];
    /* 0x48 */ int fadeDuration[5];
    /* 0x5c */ int fadeStart[5];
    /* 0x70 */ int fadeBase[5];
} GfxSysHolder;

extern GfxSysHolder data_02097d44;
extern int data_02097d50[5];
extern int data_02097d64[5];
extern int data_02097d78[5];
extern int data_02097d8c[5];
extern int data_02097da0[5];
extern int data_02097db4[5];
extern void *func_0203dd9c(u32 size);
extern void func_02043858(void *obj);
void func_0203b70c(GfxSys *sys);

}

extern "C" {


extern u8 data_02fe01e8[];
extern void G3X_Init(void);
extern void DC_FlushAll(void);
extern void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void NNS_G3dInit(void);
extern void NNS_G2dInitOamManagerModule(void);
extern BOOL NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(void *obj, int a, int b, int c);
extern void *NNS_GfdGetLnkTexVramManagerWorkSize(int n);
extern void *NNS_GfdGetLnkPlttVramManagerWorkSize(int n);
extern void func_0203beac(GfxSys *sys, int state);
extern void NNS_G3dGeSetBuffer(void *arg);
extern void NNS_G3dGeUseFastDma(int arg);
extern BOOL OS_IsRunOnTwl(void);

#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile u32 *)(a))

}

extern "C" {

extern u8 data_02fe00a0[];
extern void func_0203c880(GfxSys *sys);
extern void GX_SetGraphicsMode(int a, int b, int c);
extern void NNS_G2dApplyAndResetOamManagerBuffer(void *obj);
extern void G3X_Reset(void);
extern void func_020438e8(void *obj);
extern void func_02043d20(void *obj, int a);
extern void NNS_G3dGeSendDL(void *a, int b);
extern void NNS_G3dGeFlushBuffer(void);
extern void *G2S_GetBG0CharPtr(void);
extern void *G2S_GetBG1CharPtr(void);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG2CharPtr(void);
extern void *G2S_GetBG1ScrPtr(void);
extern void *G2S_GetBG0ScrPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);

void func_0203bd40(GfxSys *sys, u32 offset, BOOL sub) {
    GfxVramHeap *heap = &sys->heaps[0];
    if (sub) {
        heap = &sys->heaps[1];
    }
    GfxVramNode *node;
    for (node = heap->head.next; node != NULL; node = node->next) {
        if (node->offset == offset) {
            if (node->next != NULL) {
                node->next->prev = node->prev;
            } else {
                heap->tail = node->prev;
            }
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
            node->prev = NULL;
            node->next = NULL;
            node->size = 0;
            return;
        }
    }
}

}

extern "C" {

u16 func_0203bdb0(GfxSys *sys, int count, int idx) {
    u16 mask = 0;
    int i;
    int n;
    u16 ret;
    int j;
    for (i = 0; i < count; i++) {
        mask |= (u16)(1 << i);
    }
    ret = 0xffff;
    n = 16 - count;
    if (n < 0) {
        n = 0;
    }
    for (j = 0; j <= n; j++) {
        if (!(mask & sys->slotMasks[idx])) {
            sys->slotMasks[idx] |= mask;
            ret = j;
            break;
        }
        mask <<= 1;
    }
    return ret;
}

void func_0203be50(GfxSys *sys, int shift, int count, int idx) {
    u16 mask = 0;
    int i;
    for (i = 0; i < count; i++) {
        mask |= (u16)(1 << i);
    }
    mask = ~(u16)(mask << shift);
    sys->slotMasks[idx] &= mask;
}

}

extern "C" {

extern void *func_0203dec8(u32 size, int align);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void GX_SetBankForTex(int a);
extern void GX_SetBankForTexPltt(int a);
extern void NNS_GfdInitLnkTexVramManager(u32 a, u32 b, void *c, void *d, BOOL e);
extern void NNS_GfdInitLnkPlttVramManager(u32 a, void *b, void *c, BOOL d);
extern void func_0203c2bc(GfxSys *sys);
extern void func_0203c638(GfxSys *sys);
extern void func_0203d770(void);
extern void GXS_SetGraphicsMode(int a);
extern void GX_SetBankForLCDC(int a);
extern void GX_SetBankForBG(int a);
extern void GX_SetBankForSubBG(int a);
extern void GX_SetBankForSubOBJ(int a);
extern void func_02039c54(GfxMgr *mgr, int state);
extern u32 func_0203e8e0(void);
extern int func_0203ea00(void);
extern u32 func_0203ea6c(void);
extern int func_0203eb8c(void);
extern void *NNS_GfdDefaultFuncAllocTexVram;
extern void *NNS_GfdDefaultFuncFreeTexVram;
extern void *NNS_GfdDefaultFuncAllocPlttVram;
extern void *NNS_GfdDefaultFuncFreePlttVram;

static inline void GfxSys_InitTexVram(GfxSys *sys, u32 size) {
    if (sys->unk_018 == 0) {
        sys->unk_018 = (u32)func_0203dec8((u32)sys->unk_014, 4);
    } else {
        MI_CpuFill8((void *)sys->unk_018, 0, (u32)sys->unk_014);
    }
    NNS_GfdInitLnkTexVramManager(size, 0, (void *)sys->unk_018, sys->unk_014, TRUE);
}

static inline void GfxSys_InitPlttVram(GfxSys *sys, u32 size) {
    if (sys->unk_020 == 0) {
        sys->unk_020 = (u32)func_0203dec8((u32)sys->unk_01c, 4);
    } else {
        MI_CpuFill8((void *)sys->unk_020, 0, (u32)sys->unk_01c);
    }
    NNS_GfdInitLnkPlttVramManager(size, (void *)sys->unk_020, sys->unk_01c, TRUE);
}

static inline void GfxSys_SetVramFuncs(void) {
    NNS_GfdDefaultFuncAllocTexVram = (void *)func_0203e8e0;
    NNS_GfdDefaultFuncFreeTexVram = (void *)func_0203ea00;
    NNS_GfdDefaultFuncAllocPlttVram = (void *)func_0203ea6c;
    NNS_GfdDefaultFuncFreePlttVram = (void *)func_0203eb8c;
}

static inline void GfxVramHeap_Init(GfxVramHeap *heap, u32 size) {
    int i;
    heap->unk_00 = 0;
    heap->unk_04 = size;
    heap->size = size;
    heap->tail = &heap->head;
    heap->head.prev = NULL;
    heap->head.next = NULL;
    heap->head.size = 0;
    heap->head.offset = 0;
    for (i = 0; i < 64; i++) {
        heap->nodes[i].prev = NULL;
        heap->nodes[i].next = NULL;
        heap->nodes[i].size = 0;
    }
}

void func_0203beac(GfxSys *sys, int state) {
    int i;
    switch (state) {
    default:
        if (sys->state != 3) {
            func_0203c2bc(sys);
        } else {
            GX_SetGraphicsMode(1, 5, 1);
            GX_SetBankForTex(7);
            GX_SetBankForTexPltt(0x60);
            GfxSys_InitTexVram(sys, 0x60000);
            GfxSys_InitPlttVram(sys, 0x8000);
            GfxSys_SetVramFuncs();
        }
        break;
    case 2:
        sys->unk_a30_4 = 0;
        sys->unk_a30_0 = 1;
        sys->unk_a30_1 = 0;
        func_0203d770();
        GX_SetGraphicsMode(1, 3, 1);
        GXS_SetGraphicsMode(5);
        GX_SetBankForLCDC(0x1ff);
        GX_SetBankForTex(3);
        GX_SetBankForTexPltt(0x60);
        GfxSys_InitTexVram(sys, 0x40000);
        GfxSys_InitPlttVram(sys, 0x8000);
        GfxSys_SetVramFuncs();
        GX_SetBankForBG(0x10);
        GX_SetBankForSubBG(4);
        GX_SetBankForSubOBJ(8);
        REG16(0x400100c) = (u16)((REG16(0x400100c) & 0x43) | 0x84 | 0x4000);
        REG32(0x4001000) = (REG32(0x4001000) & ~0x60) | 0x20;
        REG16(0x400000a) = (u16)((REG16(0x400000a) & 0x43) | 0xe00);
        REG16(0x400000c) = (u16)((REG16(0x400000c) & 0x43) | 0xf08);
        REG32(0x4000000) = (REG32(0x4000000) & ~0x1f00) | 0x100;
        REG32(0x4001000) &= ~0x1f00;
        GfxVramHeap_Init(&sys->heaps[0], 0);
        GfxVramHeap_Init(&sys->heaps[1], 0);
        for (i = 0; i < 6; i++) {
            sys->slotMasks[i] = 0;
        }
        if (data_02097ce0 != NULL) {
            GfxMgr *mgr;
            func_02039c54(data_02097ce0, state);
            mgr = data_02097ce0;
            mgr->unk_678 = 0x20;
            mgr->unk_67a = 0x18;
        }
        break;
    case 3:
        if (sys->state != 1) {
            func_0203c2bc(sys);
        }
        sys->unk_a30_3 = 0;
        sys->unk_a30_2 = 1;
        GX_SetGraphicsMode(2, 0, 0);
        GX_SetBankForLCDC(3);
        break;
    case 4:
        func_0203c638(sys);
        break;
    }
    sys->state = state;
}

extern void GX_SetBankForOBJ(int a);
extern void GX_SetBankForSubOBJExtPltt(int a);
extern void func_02043904(void *obj);

// NitroSDK-style register inlines (GX_SetVisiblePlane, G2_SetBGnPriority, ...).
// With the same writes spelled out as plain REG expressions, func_0203c2bc
// keeps sys in sb instead of r4.
static inline void GX_SetVisiblePlane(int plane) {
    REG32(0x4000000) = (u32)((REG32(0x4000000) & ~0x1f00) | (plane << 8));
}
static inline void GXS_SetVisiblePlane(int plane) {
    REG32(0x4001000) = (u32)((REG32(0x4001000) & ~0x1f00) | (plane << 8));
}
static inline void G2_SetBG0Priority(int p) { REG16(0x4000008) = (u16)((REG16(0x4000008) & ~3) | (p << 0)); }
static inline void G2_SetBG1Priority(int p) { REG16(0x400000a) = (u16)((REG16(0x400000a) & ~3) | (p << 0)); }
static inline void G2_SetBG2Priority(int p) { REG16(0x400000c) = (u16)((REG16(0x400000c) & ~3) | (p << 0)); }
static inline void G2S_SetBG0Priority(int p) { REG16(0x4001008) = (u16)((REG16(0x4001008) & ~3) | (p << 0)); }
static inline void G2S_SetBG1Priority(int p) { REG16(0x400100a) = (u16)((REG16(0x400100a) & ~3) | (p << 0)); }
static inline void GX_SetOBJVRamModeChar(int mode) { REG32(0x4000000) = (u32)(REG32(0x4000000) & ~(0x300000 | 0x10) | mode); }
static inline void GXS_SetOBJVRamModeChar(int mode) { REG32(0x4001000) = (u32)(REG32(0x4001000) & ~(0x300000 | 0x10) | mode); }
static inline int GX_GetOBJVRamModeChar(void) { return (int)(REG32(0x4000000) & (0x300000 | 0x10)); }
static inline int GXS_GetOBJVRamModeChar(void) { return (int)(REG32(0x4001000) & (0x300000 | 0x10)); }
static inline void G2S_SetBG0Control(int screenSize, int colorMode, int screenBase, int charBase, int bgExtPltt) {
    REG16(0x4001008) = (u16)((REG16(0x4001008) & (3 | 0x40)) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG1Control(int screenSize, int colorMode, int screenBase, int charBase, int bgExtPltt) {
    REG16(0x400100a) = (u16)((REG16(0x400100a) & (3 | 0x40)) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_BlendNone(void) { REG16(0x4000050) = 0; }

void func_0203c2bc(GfxSys *sys) {
    int i;
    REG16(0x4000304) = (u16)(REG16(0x4000304) & ~0x8000);
    func_0203d770();
    GX_SetGraphicsMode(1, 5, 1);
    GXS_SetGraphicsMode(5);
    GX_SetBankForLCDC(0x1ff);
    GX_SetBankForTex(7);
    GX_SetBankForTexPltt(0x60);
    GfxSys_InitTexVram(sys, 0x60000);
    GfxSys_InitPlttVram(sys, 0x8000);
    GfxSys_SetVramFuncs();
    GX_SetBankForOBJ(0x10);
    GX_SetBankForSubBG(0x80);
    GX_SetBankForSubOBJ(8);
    GX_SetBankForSubOBJExtPltt(0x100);
    GX_SetVisiblePlane(0x11);
    GXS_SetVisiblePlane(0x10);
    G2_SetBG0Priority(3);
    G2_SetBG1Priority(0);
    G2_SetBG2Priority(0);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(0);
    GX_SetOBJVRamModeChar(0x100010);
    GXS_SetOBJVRamModeChar(0x200010);
    G2S_SetBG0Control(0, 0, 0xf, 1, 0);
    G2S_SetBG1Control(0, 0, 7, 0, 0);
    sys->unk_a30_0 = 1;
    sys->unk_a30_1 = 0;
    G2_BlendNone();
    func_02043904(sys->unk_8b0);
    sys->unk_00c = 0;
    sys->unk_010 = 1;
    GfxVramHeap_Init(&sys->heaps[0], 0x8000 << ((GX_GetOBJVRamModeChar() >> 20) & 3));
    GfxVramHeap_Init(&sys->heaps[1], 0x8000 << ((GXS_GetOBJVRamModeChar() >> 20) & 3));
    for (i = 0; i < 6; i++) {
        sys->slotMasks[i] = 0;
    }
    if (data_02097ce0 != NULL) {
        GfxMgr *mgr;
        func_02039c54(data_02097ce0, 1);
        mgr = data_02097ce0;
        mgr->unk_678 = 0x14;
        mgr->unk_67a = 0x16;
    }
}

}

extern "C" {

extern void GX_SetBankForOBJ(int a);
extern void GX_SetBankForSubOBJExtPltt(int a);
extern void func_02043904(void *obj);

}

extern "C" {

extern s32 GX_ResetBankForSubOBJ(void);
extern s32 GX_ResetBankForSubBG(void);
extern BOOL NNS_G2dEntryOamManagerOam(void *obj, void *src, int count);
extern int FX_Div(int a, int b);
extern void G2x_SetBlendBrightness_(volatile void *reg, int a, int b);

static inline u32 GfxReg_GetVisiblePlane(u32 addr) {
    return (REG32(addr) & 0x1f00) >> 8;
}

static inline void GfxReg_SetVisiblePlane(u32 addr, u32 plane) {
    REG32(addr) = (REG32(addr) & ~0x1f00) | (plane << 8);
}

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

}

extern "C" {

extern void func_0203d040(int v);
extern int func_02043d48(void *obj);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void func_02043db4(int a, int b, int c, int d);

typedef struct GfxFadeCtx {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ int state;
    /* 0x08 */ int timer;
    /* 0x0c */ int duration;
    /* 0x10 */ int start;
    /* 0x14 */ int end;
} GfxFadeCtx;

typedef int (*GfxFadeFunc)(GfxFadeCtx *ctx);

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
}

}
