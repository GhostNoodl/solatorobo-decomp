#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"
#include "Main/Res/ResLoader.h"

extern "C" {

typedef struct GfxFadeCtx {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ int state;
    /* 0x08 */ int timer;
    /* 0x0c */ int duration;
    /* 0x10 */ int start;
    /* 0x14 */ int end;
} GfxFadeCtx;

typedef int (*GfxFadeFunc)(GfxFadeCtx *ctx);

extern u32 gFadeFuncArg;
extern GfxFadeFunc gFadeFunc;
extern int gFadeEnd[5];
extern int gFadeTimer[5];
extern int gFadeState[5];
extern int gFadeDuration[5];
extern int gFadeStart[5];
extern int gFadePlanes[5];
extern void *Heap_Alloc(u32 size);
extern void Gfx3DState_Init(void *obj);
void GfxSys_Init(GfxSys *sys);

}

extern "C" {

extern u8 gGeBuffer[];
extern void G3X_Init(void);
extern void DC_FlushAll(void);
extern void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void NNS_G3dInit(void);
extern void NNS_G2dInitOamManagerModule(void);
extern BOOL NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(void *obj, int a, int b, int c);
extern void *NNS_GfdGetLnkTexVramManagerWorkSize(int n);
extern void *NNS_GfdGetLnkPlttVramManagerWorkSize(int n);
extern void GfxSys_SetMode(GfxSys *sys, int state);
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
extern void Gfx3DState_Reset(void *obj);
extern void Gfx3D_SendDL(void *obj, int a);
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

}

extern "C" {

}

extern "C" {

extern void GX_SetBankForTex(int a);
extern void GX_SetBankForTexPltt(int a);
extern void NNS_GfdInitLnkTexVramManager(u32 a, u32 b, void *c, void *d, BOOL e);
extern void NNS_GfdInitLnkPlttVramManager(u32 a, void *b, void *c, BOOL d);
extern void GfxSys_SetupVram(GfxSys *sys);
extern void GfxSys_SetupVramTwl(GfxSys *sys);
extern void Sys_ResetVram(void);
extern void GXS_SetGraphicsMode(int a);
extern void GX_SetBankForLCDC(int a);
extern void GX_SetBankForBG(int a);
extern void GX_SetBankForSubBG(int a);
extern void GX_SetBankForSubOBJ(int a);
extern void GfxMgr_FreeAll(GfxMgr *mgr, int state);
extern u32 Vram_AllocTex(u32 size, int is4x4, int opt);
extern int Vram_FreeTex(u32 key);
extern u32 Vram_AllocPltt(u32 size, int is4pltt, int opt);
extern int Vram_FreePltt(u32 key);
extern void *NNS_GfdDefaultFuncAllocTexVram;
extern void *NNS_GfdDefaultFuncFreeTexVram;
extern void *NNS_GfdDefaultFuncAllocPlttVram;
extern void *NNS_GfdDefaultFuncFreePlttVram;

static inline void GfxSys_InitTexVram(GfxSys *sys, u32 size) {
    if (sys->unk_018 == 0) {
        sys->unk_018 = (u32)Heap_AllocLo((u32)sys->unk_014, 4);
    } else {
        MI_CpuFill8((void *)sys->unk_018, 0, (u32)sys->unk_014);
    }
    NNS_GfdInitLnkTexVramManager(size, 0, (void *)sys->unk_018, sys->unk_014, TRUE);
}

static inline void GfxSys_InitPlttVram(GfxSys *sys, u32 size) {
    if (sys->unk_020 == 0) {
        sys->unk_020 = (u32)Heap_AllocLo((u32)sys->unk_01c, 4);
    } else {
        MI_CpuFill8((void *)sys->unk_020, 0, (u32)sys->unk_01c);
    }
    NNS_GfdInitLnkPlttVramManager(size, (void *)sys->unk_020, sys->unk_01c, TRUE);
}

static inline void GfxSys_SetVramFuncs(void) {
    NNS_GfdDefaultFuncAllocTexVram = (void *)Vram_AllocTex;
    NNS_GfdDefaultFuncFreeTexVram = (void *)Vram_FreeTex;
    NNS_GfdDefaultFuncAllocPlttVram = (void *)Vram_AllocPltt;
    NNS_GfdDefaultFuncFreePlttVram = (void *)Vram_FreePltt;
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

extern void GX_SetBankForOBJ(int a);
extern void GX_SetBankForSubOBJExtPltt(int a);
extern void Gfx3DState_SetDefaults(void *obj);

// NitroSDK-style register inlines (GX_SetVisiblePlane, G2_SetBGnPriority, ...).
// With the same writes spelled out as plain REG expressions, GfxSys_SetupVram
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

}

extern "C" {

extern void GX_SetBankForOBJ(int a);
extern void GX_SetBankForSubOBJExtPltt(int a);
extern void Gfx3DState_SetDefaults(void *obj);

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

extern void OS_Terminate(void);
extern void func_02224c1c(void);  /* TWL only */

static inline u32 GfxReg_GetObjCharShift(u32 addr) {
    int mode = (int)(REG32(addr) & 0x300010);
    return (mode >> 20) & 3;
}

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

}

extern "C" {

extern void GfxSys_DrawFadeQuad(int v);
extern u8 Gfx3DState_NextPolyId(void *obj);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void Gfx3D_DrawPrimScaled(int a, int b, int c, u32 d);

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
}

}

extern "C" {

// The fade channels (indexed by screen) are this TU's own .bss objects, addressed through one
// pool literal (0x02097d44) plus offsets. GfxSys_Create already reads gGfxSys that way, so
// the first two objects are defined before it. The rest are defined after it, which keeps
// definition order: nine definitions before the first function come out in MWCC's own order
// (d4c d48 d44, then the arrays from d8c). As TU objects in one pool their accesses stay in
// source order against the context copy in GfxSys_RunFadeFunc, which is why that function needs no
// volatile.
u32 gFadeFuncArg;
GfxSys *gGfxSys;

void GfxSys_Create(void) {
    GfxSys *sys;
    if (gGfxSys != NULL) {
        return;
    }
    gSysState->cur = gSysState->heapLo;
    sys = (GfxSys *)Heap_Alloc(sizeof(GfxSys));
    if (sys != NULL) {
        Gfx3DState_Init(sys->unk_8b0);
        GfxSys_Init(sys);
    }
    gGfxSys = sys;
    gSysState->cur = gSysState->heapHi;
}

GfxFadeFunc gFadeFunc;
int gFadeEnd[5];
int gFadeTimer[5];
int gFadeState[5];
int gFadeDuration[5];
int gFadeStart[5];
int gFadePlanes[5];

void GfxSys_Init(GfxSys *sys) {
    int i;
    GfxOam *oam;
    G3X_Init();
    sys->unk_008 = 0;
    DC_FlushAll();
    GX_LoadBGPltt(&sys->unk_008, 0, 2);
    sys->unk_00a = 0;
    DC_FlushAll();
    GXS_LoadBGPltt(&sys->unk_00a, 0, 2);
    NNS_G3dInit();
    NNS_G2dInitOamManagerModule();
    NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(sys->unk_02c, 0, 0x80, 0);
    NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(sys->unk_048, 0, 0x80, 1);
    sys->unk_014 = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    sys->unk_018 = 0;
    sys->unk_01c = NNS_GfdGetLnkPlttVramManagerWorkSize(0x20);
    sys->unk_020 = 0;
    sys->unk_024 = 0;
    sys->unk_028 = 0;
    sys->nextState = 1;
    GfxSys_SetMode(sys, 1);
    for (i = 0; i < 5; i++) {
        gFadePlanes[i] = 0;
        gFadeState[i] = 0;
        gFadeTimer[i] = 0;
        gFadeDuration[i] = 0;
        gFadeStart[i] = 0;
        gFadeEnd[i] = 0;
    }
    gFadeFunc = 0;
    gFadeFuncArg = 0;
    oam = sys->oams;
    for (i = 0; i < 12; i++) {
        // y is declared after the first store; declared above it, the zero and the clear-loop
        // addresses take other registers.
        int x = (u32)(i << 30) >> 24;
        oam->attr23 = 0;
        int y = (i >> 2) << 6;
        oam->attr01 = 0xc0000c00 | (y & 0xff) | (x << 16);
        oam->attr2 = (((y >> 3) << 5) + (x >> 3)) | 0xf000;
        oam++;
    }
    NNS_G3dGeSetBuffer(gGeBuffer);
    NNS_G3dGeUseFastDma(1);
    sys->unk_a30_0 = 1;
    sys->unk_a30_1 = 0;
    REG16(0x400004a) = (REG16(0x400004a) & ~0x3f) | 0;
    REG16(0x4000048) = (REG16(0x4000048) & ~0x3f) | 0x3f;
    if (!OS_IsRunOnTwl()) {
        REG16(0x4000040) = 0x1ff;
        REG16(0x4000044) = 0xbf;
    } else {
        REG32(0x4004008) |= 8;
        REG16(0x4000040) = 0x1ff;
        REG16(0x4000044) = 0x1bf;
    }
}

void GfxSys_SetBackdrop(GfxSys *sys, u16 color) {
    sys->unk_008 = color;
    DC_FlushAll();
    GX_LoadBGPltt(&sys->unk_008, 0, 2);
}

void GfxSys_SetBackdropSub(GfxSys *sys, u16 color) {
    sys->unk_00a = color;
    DC_FlushAll();
    GXS_LoadBGPltt(&sys->unk_00a, 0, 2);
}

void GfxSys_EndFrame(GfxSys *sys) {
    GfxSys *g;
    {
        // The target loads state before nextState; only a volatile read keeps that order.
        // Kept (round auA honesty audit): junk with no honest form found (jkK, auA). GfxSys.cpp has
        // .bss and this function is mid-file, so it can't be cut out to a dsd gap.
        int s = *(volatile int *)&sys->state;
        int n = sys->nextState;
        if (s != n) {
            GfxSys_SetMode(sys, n);
        }
    }
    if (sys->state == 2) {
        func_0203c880(sys);
    } else if (sys->state == 3 && sys->unk_a30_2) {
        if (!sys->unk_a30_3) {
            GX_SetGraphicsMode(6, 0, 0);
            sys->unk_a30_3 = 1;
        } else {
            GX_SetGraphicsMode(2, 0, 0);
            sys->unk_a30_3 = 0;
        }
    }
    NNS_G2dApplyAndResetOamManagerBuffer(sys->unk_02c);
    NNS_G2dApplyAndResetOamManagerBuffer(sys->unk_048);
    G3X_Reset();
    Gfx3DState_Reset(sys->unk_8b0);
    g = gGfxSys;
    if (g->unk_8b0_5) {
        REG32(0x4000000) = (REG32(0x4000000) & ~0xe000) | 0x2000;
        if (OS_IsRunOnTwl()) {
            return;
        }
        Gfx3D_SendDL(g->unk_8b0, 0);
        NNS_G3dGeSendDL(data_02fe00a0, 0x44);
    } else {
        REG32(0x4000000) &= ~0xe000;
    }
}

void GfxSys_SwapBuffers(GfxSys *sys) {
    NNS_G3dGeFlushBuffer();
    REG32(0x4000540) = (sys->unk_00c << 1) | sys->unk_010;
}

void GfxSys_FlipTextBg(GfxSys *sys) {
    u32 v;
    void *p;
    u32 size;
    u32 bits;
    if (!sys->unk_a30_0) {
        return;
    }
    v = (REG32(0x4001000) & 0x1f00) >> 8;
    if (sys->state != 2) {
        if (!sys->unk_a30_1) {
            sys->unk_a30_1 = 1;
            bits = (v & ~1) | 2;
            p = G2S_GetBG0CharPtr();
        } else {
            sys->unk_a30_1 = 0;
            bits = (v & ~2) | 1;
            p = G2S_GetBG1CharPtr();
        }
        REG32(0x4001000) = (REG32(0x4001000) & ~0x1f00) | (bits << 8);
        size = 0x3720;
    } else {
        if (sys->unk_a30_4 == 1) {
            p = G2_GetBG1CharPtr();
        } else {
            p = G2_GetBG2CharPtr();
        }
        size = 0x6020;
    }
    MIi_CpuClearFast(0, p, size);
}

void *GfxSys_GetTextBgPtr(GfxSys *sys, BOOL main) {
    if (sys->state != 2) {
        if (main) {
            return !sys->unk_a30_1 ? G2S_GetBG1ScrPtr() : G2S_GetBG0ScrPtr();
        }
        return !sys->unk_a30_1 ? G2S_GetBG1CharPtr() : G2S_GetBG0CharPtr();
    }
    if (main) {
        if (sys->unk_a30_4 == 1) {
            return G2_GetBG1ScrPtr();
        }
        return G2_GetBG2ScrPtr();
    }
    if (sys->unk_a30_4 == 1) {
        return G2_GetBG1CharPtr();
    }
    return G2_GetBG2CharPtr();
}

void *GfxSys_GetOamMgr(GfxSys *sys, int which) {
    void *ret = NULL;
    switch (which) {
    case 0:
        ret = sys->unk_02c;
        break;
    case 1:
        ret = sys->unk_048;
        break;
    }
    return ret;
}

// Allocates `size` bytes from the main (sub == FALSE) or sub VRAM range heap and returns the
// offset: first after the last node, otherwise in the first gap between two nodes that fits.
// `cur` and `node` are locals; declaring them as parameters gives the target's registers.
// Kept (round auA honesty audit): fake parameters with no honest form found. GfxSys.cpp has .bss and
// this function is mid-file, so it can't be cut out to a dsd gap.
u32 GfxSys_AllocVram(GfxSys *sys, u32 size, BOOL sub, GfxVramNode *cur, GfxVramNode *node) {
    GfxVramHeap *heap = &sys->heaps[0];
    GfxVramNode *tail;
    GfxVramNode *next;
    u32 offset;
    int i;
    if (sub) {
        heap = &sys->heaps[1];
    }
    tail = heap->tail;
    offset = tail->offset + tail->size;
    if (heap->size - offset >= size) {
        node = NULL;
        for (i = 0; i < 64; i++) {
            if (heap->nodes[i].size == 0) {
                node = &heap->nodes[i];
                break;
            }
        }
        if (node == NULL) {
            return -1;
        }
        node->offset = offset;
        node->size = size;
        node->prev = tail;
        tail->next = node;
        heap->tail = node;
        return node->offset;
    }
    for (cur = &heap->head; cur != NULL; cur = next) {
        next = cur->next;
        if (next != NULL) {
            offset = cur->offset + cur->size;
            if (next->offset - offset >= size) {
                node = NULL;
                for (i = 0; i < 64; i++) {
                    if (heap->nodes[i].size == 0) {
                        node = &heap->nodes[i];
                        break;
                    }
                }
                if (node == NULL) {
                    return 0;
                }
                node->offset = offset;
                node->size = size;
                node->prev = cur;
                node->next = next;
                cur->next = node;
                next->prev = node;
                return node->offset;
            }
        }
    }
    return -1;
}

void GfxSys_FreeVram(GfxSys *sys, u32 offset, BOOL sub) {
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

u16 GfxSys_AllocSlots(GfxSys *sys, int count, int idx) {
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

void GfxSys_FreeSlots(GfxSys *sys, int shift, int count, int idx) {
    u16 mask = 0;
    int i;
    for (i = 0; i < count; i++) {
        mask |= (u16)(1 << i);
    }
    mask = ~(u16)(mask << shift);
    sys->slotMasks[idx] &= mask;
}

void GfxSys_SetMode(GfxSys *sys, int state) {
    int i;
    switch (state) {
    default:
        if (sys->state != 3) {
            GfxSys_SetupVram(sys);
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
        Sys_ResetVram();
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
        if (gGfxMgr != NULL) {
            GfxMgr *mgr;
            GfxMgr_FreeAll(gGfxMgr, state);
            mgr = gGfxMgr;
            mgr->unk_678 = 0x20;
            mgr->unk_67a = 0x18;
        }
        break;
    case 3:
        if (sys->state != 1) {
            GfxSys_SetupVram(sys);
        }
        sys->unk_a30_3 = 0;
        sys->unk_a30_2 = 1;
        GX_SetGraphicsMode(2, 0, 0);
        GX_SetBankForLCDC(3);
        break;
    case 4:
        GfxSys_SetupVramTwl(sys);
        break;
    }
    sys->state = state;
}

void GfxSys_SetupVram(GfxSys *sys) {
    int i;
    REG16(0x4000304) = (u16)(REG16(0x4000304) & ~0x8000);
    Sys_ResetVram();
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
    Gfx3DState_SetDefaults(sys->unk_8b0);
    sys->unk_00c = 0;
    sys->unk_010 = 1;
    GfxVramHeap_Init(&sys->heaps[0], 0x8000 << ((GX_GetOBJVRamModeChar() >> 20) & 3));
    GfxVramHeap_Init(&sys->heaps[1], 0x8000 << ((GXS_GetOBJVRamModeChar() >> 20) & 3));
    for (i = 0; i < 6; i++) {
        sys->slotMasks[i] = 0;
    }
    if (gGfxMgr != NULL) {
        GfxMgr *mgr;
        GfxMgr_FreeAll(gGfxMgr, 1);
        mgr = gGfxMgr;
        mgr->unk_678 = 0x14;
        mgr->unk_67a = 0x16;
    }
}

void GfxSys_SetupVramTwl(GfxSys *sys) {
    int i;

    if (!OS_IsRunOnTwl()) {
        OS_Terminate();
    }
    func_02224c1c();
    sys->unk_a30_0 = 1;
    sys->unk_a30_1 = 0;
    sys->unk_00c = 0;
    sys->unk_010 = 1;
    GfxSys_InitTexVram(sys, 0x40000);
    GfxSys_InitPlttVram(sys, 0x8000);
    GfxSys_SetVramFuncs();
    GfxVramHeap_Init(&sys->heaps[0], 0x8000 << GfxReg_GetObjCharShift(0x4000000));
    GfxVramHeap_Init(&sys->heaps[1], 0x8000 << GfxReg_GetObjCharShift(0x4001000));
    for (i = 0; i < 6; i++) {
        sys->slotMasks[i] = 0;
    }
    if (gGfxMgr != NULL) {
        GfxMgr *mgr;
        GfxMgr_FreeAll(gGfxMgr, 1);
        mgr = gGfxMgr;
        mgr->unk_678 = 0x14;
        mgr->unk_67a = 0x16;
    }
}

void func_0203c880(GfxSys *sys) {
    if (!sys->unk_a30_4) {
        REG16(0x4000304) = (u16)(REG16(0x4000304) & ~0x8000);
        GfxReg_SetVisiblePlane(0x4001000, (GfxReg_GetVisiblePlane(0x4001000) & ~0x10) | 4);
        GfxReg_SetVisiblePlane(0x4000000, (GfxReg_GetVisiblePlane(0x4000000) & ~2) | 4);
        GX_ResetBankForSubOBJ();
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        REG32(0x4000064) = 0x80330010;
        GX_SetGraphicsMode(0xe, 0, 1);
        sys->unk_a30_4 = 1;
    } else {
        REG16(0x4000304) = (u16)(REG16(0x4000304) | 0x8000);
        GfxReg_SetVisiblePlane(0x4001000, (GfxReg_GetVisiblePlane(0x4001000) & ~4) | 0x10);
        GfxReg_SetVisiblePlane(0x4000000, (GfxReg_GetVisiblePlane(0x4000000) & ~4) | 2);
        GX_ResetBankForSubBG();
        GX_SetBankForSubOBJ(8);
        GX_SetBankForLCDC(4);
        REG32(0x4000064) = 0x80320010;
        GX_SetGraphicsMode(0xa, 0, 1);
        NNS_G2dEntryOamManagerOam(sys->unk_048, sys->oams, 12);
        sys->unk_a30_4 = 0;
    }
}

void GfxSys_SetFadePlanes(int value, int ch) {
    int end;
    if (ch != -1) {
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        if (ch == 1) {
            value &= ~3;
        }
        gFadePlanes[ch] = value;
    }
}

void GfxSys_SetFadeRange(int start, int end_, int ch) {
    int end;
    if (ch != -1) {
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        if (start != -1) {
            gFadeStart[ch] = start;
        }
        if (end_ != -1) {
            gFadeEnd[ch] = end_;
        }
    }
}

int GfxSys_GetFadeTimer(int ch) {
    return gFadeTimer[ch];
}

int GfxSys_GetFadeLevel(int ch) {
    int t;
    int start;
    if (gFadeDuration[ch] == 0) {
        t = 0x1000;
    } else {
        t = FX_Div(gFadeTimer[ch], gFadeDuration[ch]);
        if (t >= 0x1000) {
            t = 0x1000;
        }
    }
    start = gFadeStart[ch];
    return start + (FX_Mul((gFadeEnd[ch] - start) << 12, t) >> 12);
}

void GfxSys_StopFade(int ch) {
    int end;
    if (ch != -1) {
        end = ch + 1;
    } else {
        ch = 0;
        end = 5;
    }
    for (; ch < end; ch++) {
        gFadeState[ch] = 0;
        if (ch == 0) {
            G2x_SetBlendBrightness_((volatile void *)0x4000050, gFadePlanes[ch], 0);
        } else if (ch == 1) {
            G2x_SetBlendBrightness_((volatile void *)0x4001050, gFadePlanes[ch], 0);
        }
    }
}

void GfxSys_StartFadeIn(int duration, int mode, int ch) {
    int end;
    if (ch != -1) {
        if ((ch == 0 || ch == 3) && gFadeState[3] != 0) {
            gFadeState[3] = 1;
            gFadeTimer[3] = 0;
            gFadeDuration[3] = duration;
            gFadeStart[3] = 0;
            gFadeEnd[3] = 0;
            return;
        }
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        gFadeState[ch] = 1;
        gFadeTimer[ch] = 0;
        gFadeDuration[ch] = duration;
        if (mode == 1) {
            gFadeStart[ch] = 16;
        } else if (mode == 2) {
            gFadeStart[ch] = -16;
        } else {
            gFadeStart[ch] = gFadeEnd[ch];
        }
        gFadeEnd[ch] = 0;
    }
}

void GfxSys_StartFadeOut(int duration, int mode, int ch) {
    int end;
    if (ch != -1) {
        if (ch == 3) {
            gFadeState[3] = 3;
            gFadeTimer[3] = 0;
            gFadeDuration[3] = duration;
            gFadeStart[3] = 0;
            gFadeEnd[3] = 0;
            return;
        }
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        gFadeState[ch] = 3;
        gFadeTimer[ch] = 0;
        gFadeDuration[ch] = duration;
        if (mode == 1) {
            gFadeStart[ch] = 0;
            gFadeEnd[ch] = 16;
        } else {
            gFadeStart[ch] = 0;
            gFadeEnd[ch] = -16;
        }
    }
}

void GfxSys_UpdateFade(void) {
    int i;
    if ((*(volatile u16 *)0x2ffffa8 & 0x8000) >> 15) {
        return;
    }
    for (i = 0; i < 4; i++) {
        int state = gFadeState[i];
        if (state != 0 && state != 2 && state != 4) {
            gFadeTimer[i] += 0x1000;
            if (gFadeTimer[i] >= gFadeDuration[i]) {
                gFadeTimer[i] = gFadeDuration[i];
            }
        }
    }
}

void GfxSys_ApplyFade3D(void) {
    int t;
    int v;
    if (gFadeState[2] == 2 || gFadeState[2] == 4) {
        GfxSys_DrawFadeQuad(gFadeEnd[2]);
        return;
    }
    if (gFadeDuration[2] == 0) {
        t = 0x1000;
    } else {
        t = FX_Div(gFadeTimer[2], gFadeDuration[2]);
        if (t >= 0x1000) {
            t = 0x1000;
        }
    }
    v = gFadeStart[2] + (FX_Mul((gFadeEnd[2] - gFadeStart[2]) << 12, t) >> 12);
    if (v == 0) {
        if (gFadeState[2] == 1) {
            gFadeState[2] = 0;
        }
    } else if (v == gFadeEnd[2]) {
        if (gFadeState[2] == 1) {
            gFadeState[2] = 2;
        } else {
            gFadeState[2] = 4;
        }
    }
    GfxSys_DrawFadeQuad(v);
}

// The context is copied out and back one word at a time.
void GfxSys_RunFadeFunc(void) {
    GfxFadeCtx ctx;
    GfxFadeFunc func = gFadeFunc;
    if (func == NULL) {
        gFadeState[3] = 0;
        return;
    }
    ctx.unk_00 = gFadeFuncArg;
    ctx.state = gFadeState[3];
    ctx.timer = gFadeTimer[3];
    ctx.duration = gFadeDuration[3];
    ctx.start = gFadeStart[3];
    ctx.end = gFadeEnd[3];
    gFadeState[3] = func(&ctx);
    gFadeFuncArg = ctx.unk_00;
    gFadeState[3] = ctx.state;
    gFadeTimer[3] = ctx.timer;
    gFadeDuration[3] = ctx.duration;
    gFadeStart[3] = ctx.start;
    gFadeEnd[3] = ctx.end;
}

void GfxSys_ApplyFade(int mode) {
    int ch;
    int t;
    int v;
    if (mode != -1) {
        if (gFadeState[2] != 0) {
            GfxSys_ApplyFade3D();
        }
        if (gFadeState[3] != 0) {
            GfxSys_RunFadeFunc();
        }
        return;
    }
    if (gFadeState[4] != 0) {
        G2x_SetBlendBrightness_((volatile void *)0x4000050, gFadePlanes[4], gFadeStart[4]);
    }
    for (ch = 0; ch < 2; ch++) {
        int state = gFadeState[ch];
        if (state != 0 && state != 2 && state != 4) {
            if (gFadeDuration[ch] == 0) {
                t = 0x1000;
            } else {
                t = FX_Div(gFadeTimer[ch], gFadeDuration[ch]);
                if (t >= 0x1000) {
                    t = 0x1000;
                }
            }
            v = gFadeStart[ch] + (FX_Mul((gFadeEnd[ch] - gFadeStart[ch]) << 12, t) >> 12);
            if (v == 0) {
                if (gFadeState[ch] == 1) {
                    gFadeState[ch] = 0;
                }
            } else if (v == gFadeEnd[ch]) {
                if (gFadeState[ch] == 1) {
                    gFadeState[ch] = 2;
                } else {
                    gFadeState[ch] = 4;
                }
            }
            if (ch == 0) {
                G2x_SetBlendBrightness_((volatile void *)0x4000050, gFadePlanes[ch], v);
            } else if (ch == 1) {
                G2x_SetBlendBrightness_((volatile void *)0x4001050, gFadePlanes[ch], v);
            }
        }
    }
}

void GfxSys_DrawFadeQuad(int v) {
    GfxSys *sys;
    int t;
    u32 polyAttr;
    u32 texParam;
    int trans[3];
    if (v == 0) {
        return;
    }
    sys = gGfxSys;
    t = FX_Div((v < 0 ? -v : v) << 12, 16 << 12);
    Gfx3D_SendDL(gGfxSys->unk_8b0, 0);
    polyAttr = G3_PackPolygonAttr(0, 1, 3, Gfx3DState_NextPolyId(sys->unk_8b0), FX_Mul(t, 0x1f000) >> 12, 0);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    texParam = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    trans[0] = 0;
    trans[1] = 0;
    trans[2] = -0x666;
    NNS_G3dGeBufferOP_N(0x1c, trans, 3);
    Gfx3D_DrawPrimScaled(1, 0x100000, 0xc0000, v > 0 ? 0x7fff : 0);
}

// Blends two RGB555 colors; t is fx32 in [0, 0x1000].
u16 GfxSys_BlendColor(int c0, int c1, int t) {
    int r0 = c0 & 0x1f;
    int r1 = c1 & 0x1f;
    int g0 = (c0 >> 5) & 0x1f;
    int g1 = (c1 >> 5) & 0x1f;
    int b0 = (c0 >> 10) & 0x1f;
    int b1 = (c1 >> 10) & 0x1f;
    r0 = ((r1 - r0) * t + (r0 << 12)) >> 12;
    b0 = ((b1 - b0) * t + (b0 << 12)) >> 12;
    g0 = ((g1 - g0) * t + (g0 << 12)) >> 12;
    return r0 | (g0 << 5) | (b0 << 10);
}

}
