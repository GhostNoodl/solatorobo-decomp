#include "Main/Gfx/GfxMgr.h"

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

extern u32 data_02097d44;
extern GfxSys *data_02097d48;
extern GfxFadeFunc data_02097d4c;
extern int data_02097d50[5];
extern int data_02097d64[5];
extern int data_02097d78[5];
extern int data_02097d8c[5];
extern int data_02097da0[5];
extern int data_02097db4[5];
extern void *Heap_Alloc(u32 size);
extern void Gfx3DState_Init(void *obj);
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
extern void Gfx3DState_Reset(void *obj);
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

}

extern "C" {

}

extern "C" {

extern void *Heap_AllocLo(u32 size, int align);
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
extern u32 func_0203e8e0(u32 size, int is4x4, int opt);
extern int func_0203ea00(u32 key);
extern u32 func_0203ea6c(u32 size, int is4pltt, int opt);
extern int func_0203eb8c(u32 key);
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

extern void func_0203d040(int v);
extern u8 Gfx3DState_NextPolyId(void *obj);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void func_02043db4(int a, int b, int c, int d);

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
}

}

extern "C" {

// The fade channels (indexed by screen) are this TU's own .bss objects, addressed through one
// pool literal (0x02097d44) plus offsets. GfxSys_Create already reads data_02097d48 that way, so
// the first two objects are defined before it. The rest are defined after it, which keeps
// definition order: nine definitions before the first function come out in MWCC's own order
// (d4c d48 d44, then the arrays from d8c). As TU objects in one pool their accesses stay in
// source order against the context copy in func_0203ce3c, which is why that function needs no
// volatile.
u32 data_02097d44;
GfxSys *data_02097d48;

void GfxSys_Create(void) {
    GfxSys *sys;
    if (data_02097d48 != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->heapLo;
    sys = (GfxSys *)Heap_Alloc(sizeof(GfxSys));
    if (sys != NULL) {
        Gfx3DState_Init(sys->unk_8b0);
        func_0203b70c(sys);
    }
    data_02097d48 = sys;
    data_02097dd0->cur = data_02097dd0->heapHi;
}

GfxFadeFunc data_02097d4c;
int data_02097d50[5];
int data_02097d64[5];
int data_02097d78[5];
int data_02097d8c[5];
int data_02097da0[5];
int data_02097db4[5];

void func_0203b70c(GfxSys *sys) {
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
    func_0203beac(sys, 1);
    for (i = 0; i < 5; i++) {
        data_02097db4[i] = 0;
        data_02097d78[i] = 0;
        data_02097d64[i] = 0;
        data_02097d8c[i] = 0;
        data_02097da0[i] = 0;
        data_02097d50[i] = 0;
    }
    data_02097d4c = 0;
    data_02097d44 = 0;
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
    NNS_G3dGeSetBuffer(data_02fe01e8);
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

void func_0203b96c(GfxSys *sys) {
    GfxSys *g;
    {
        // The target loads state before nextState; only a volatile read keeps that order.
        int s = *(volatile int *)&sys->state;
        int n = sys->nextState;
        if (s != n) {
            func_0203beac(sys, n);
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
    g = data_02097d48;
    if (g->unk_8b0_5) {
        REG32(0x4000000) = (REG32(0x4000000) & ~0xe000) | 0x2000;
        if (OS_IsRunOnTwl()) {
            return;
        }
        func_02043d20(g->unk_8b0, 0);
        NNS_G3dGeSendDL(data_02fe00a0, 0x44);
    } else {
        REG32(0x4000000) &= ~0xe000;
    }
}

void func_0203ba7c(GfxSys *sys) {
    NNS_G3dGeFlushBuffer();
    REG32(0x4000540) = (sys->unk_00c << 1) | sys->unk_010;
}

void func_0203baa4(GfxSys *sys) {
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

void *func_0203bb68(GfxSys *sys, BOOL main) {
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

void *func_0203bbfc(GfxSys *sys, int which) {
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
u32 func_0203bc20(GfxSys *sys, u32 size, BOOL sub, GfxVramNode *cur, GfxVramNode *node) {
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

void GfxSys_FreeSlots(GfxSys *sys, int shift, int count, int idx) {
    u16 mask = 0;
    int i;
    for (i = 0; i < count; i++) {
        mask |= (u16)(1 << i);
    }
    mask = ~(u16)(mask << shift);
    sys->slotMasks[idx] &= mask;
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

void func_0203c638(GfxSys *sys) {
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
    if (data_02097ce0 != NULL) {
        GfxMgr *mgr;
        func_02039c54(data_02097ce0, 1);
        mgr = data_02097ce0;
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

void func_0203c9e8(int value, int ch) {
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
        data_02097db4[ch] = value;
    }
}

void func_0203ca24(int start, int end_, int ch) {
    int end;
    if (ch != -1) {
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        if (start != -1) {
            data_02097da0[ch] = start;
        }
        if (end_ != -1) {
            data_02097d50[ch] = end_;
        }
    }
}

int func_0203ca74(int ch) {
    return data_02097d64[ch];
}

int func_0203ca84(int ch) {
    int t;
    int start;
    if (data_02097d8c[ch] == 0) {
        t = 0x1000;
    } else {
        t = FX_Div(data_02097d64[ch], data_02097d8c[ch]);
        if (t >= 0x1000) {
            t = 0x1000;
        }
    }
    start = data_02097da0[ch];
    return start + (FX_Mul((data_02097d50[ch] - start) << 12, t) >> 12);
}

void func_0203caf8(int ch) {
    int end;
    if (ch != -1) {
        end = ch + 1;
    } else {
        ch = 0;
        end = 5;
    }
    for (; ch < end; ch++) {
        data_02097d78[ch] = 0;
        if (ch == 0) {
            G2x_SetBlendBrightness_((volatile void *)0x4000050, data_02097db4[ch], 0);
        } else if (ch == 1) {
            G2x_SetBlendBrightness_((volatile void *)0x4001050, data_02097db4[ch], 0);
        }
    }
}

void func_0203cb78(int duration, int mode, int ch) {
    int end;
    if (ch != -1) {
        if ((ch == 0 || ch == 3) && data_02097d78[3] != 0) {
            data_02097d78[3] = 1;
            data_02097d64[3] = 0;
            data_02097d8c[3] = duration;
            data_02097da0[3] = 0;
            data_02097d50[3] = 0;
            return;
        }
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        data_02097d78[ch] = 1;
        data_02097d64[ch] = 0;
        data_02097d8c[ch] = duration;
        if (mode == 1) {
            data_02097da0[ch] = 16;
        } else if (mode == 2) {
            data_02097da0[ch] = -16;
        } else {
            data_02097da0[ch] = data_02097d50[ch];
        }
        data_02097d50[ch] = 0;
    }
}

void func_0203cc58(int duration, int mode, int ch) {
    int end;
    if (ch != -1) {
        if (ch == 3) {
            data_02097d78[3] = 3;
            data_02097d64[3] = 0;
            data_02097d8c[3] = duration;
            data_02097da0[3] = 0;
            data_02097d50[3] = 0;
            return;
        }
        end = ch + 1;
    } else {
        ch = 0;
        end = 2;
    }
    for (; ch < end; ch++) {
        data_02097d78[ch] = 3;
        data_02097d64[ch] = 0;
        data_02097d8c[ch] = duration;
        if (mode == 1) {
            data_02097da0[ch] = 0;
            data_02097d50[ch] = 16;
        } else {
            data_02097da0[ch] = 0;
            data_02097d50[ch] = -16;
        }
    }
}

void func_0203cd10(void) {
    int i;
    if ((*(volatile u16 *)0x2ffffa8 & 0x8000) >> 15) {
        return;
    }
    for (i = 0; i < 4; i++) {
        int state = data_02097d78[i];
        if (state != 0 && state != 2 && state != 4) {
            data_02097d64[i] += 0x1000;
            if (data_02097d64[i] >= data_02097d8c[i]) {
                data_02097d64[i] = data_02097d8c[i];
            }
        }
    }
}

void func_0203cd84(void) {
    int t;
    int v;
    if (data_02097d78[2] == 2 || data_02097d78[2] == 4) {
        func_0203d040(data_02097d50[2]);
        return;
    }
    if (data_02097d8c[2] == 0) {
        t = 0x1000;
    } else {
        t = FX_Div(data_02097d64[2], data_02097d8c[2]);
        if (t >= 0x1000) {
            t = 0x1000;
        }
    }
    v = data_02097da0[2] + (FX_Mul((data_02097d50[2] - data_02097da0[2]) << 12, t) >> 12);
    if (v == 0) {
        if (data_02097d78[2] == 1) {
            data_02097d78[2] = 0;
        }
    } else if (v == data_02097d50[2]) {
        if (data_02097d78[2] == 1) {
            data_02097d78[2] = 2;
        } else {
            data_02097d78[2] = 4;
        }
    }
    func_0203d040(v);
}

// The context is copied out and back one word at a time.
void func_0203ce3c(void) {
    GfxFadeCtx ctx;
    GfxFadeFunc func = data_02097d4c;
    if (func == NULL) {
        data_02097d78[3] = 0;
        return;
    }
    ctx.unk_00 = data_02097d44;
    ctx.state = data_02097d78[3];
    ctx.timer = data_02097d64[3];
    ctx.duration = data_02097d8c[3];
    ctx.start = data_02097da0[3];
    ctx.end = data_02097d50[3];
    data_02097d78[3] = func(&ctx);
    data_02097d44 = ctx.unk_00;
    data_02097d78[3] = ctx.state;
    data_02097d64[3] = ctx.timer;
    data_02097d8c[3] = ctx.duration;
    data_02097da0[3] = ctx.start;
    data_02097d50[3] = ctx.end;
}

void func_0203ced8(int mode) {
    int ch;
    int t;
    int v;
    if (mode != -1) {
        if (data_02097d78[2] != 0) {
            func_0203cd84();
        }
        if (data_02097d78[3] != 0) {
            func_0203ce3c();
        }
        return;
    }
    if (data_02097d78[4] != 0) {
        G2x_SetBlendBrightness_((volatile void *)0x4000050, data_02097db4[4], data_02097da0[4]);
    }
    for (ch = 0; ch < 2; ch++) {
        int state = data_02097d78[ch];
        if (state != 0 && state != 2 && state != 4) {
            if (data_02097d8c[ch] == 0) {
                t = 0x1000;
            } else {
                t = FX_Div(data_02097d64[ch], data_02097d8c[ch]);
                if (t >= 0x1000) {
                    t = 0x1000;
                }
            }
            v = data_02097da0[ch] + (FX_Mul((data_02097d50[ch] - data_02097da0[ch]) << 12, t) >> 12);
            if (v == 0) {
                if (data_02097d78[ch] == 1) {
                    data_02097d78[ch] = 0;
                }
            } else if (v == data_02097d50[ch]) {
                if (data_02097d78[ch] == 1) {
                    data_02097d78[ch] = 2;
                } else {
                    data_02097d78[ch] = 4;
                }
            }
            if (ch == 0) {
                G2x_SetBlendBrightness_((volatile void *)0x4000050, data_02097db4[ch], v);
            } else if (ch == 1) {
                G2x_SetBlendBrightness_((volatile void *)0x4001050, data_02097db4[ch], v);
            }
        }
    }
}

void func_0203d040(int v) {
    GfxSys *sys;
    int t;
    u32 polyAttr;
    u32 texParam;
    int trans[3];
    if (v == 0) {
        return;
    }
    sys = data_02097d48;
    t = FX_Div((v < 0 ? -v : v) << 12, 16 << 12);
    func_02043d20(data_02097d48->unk_8b0, 0);
    polyAttr = G3_PackPolygonAttr(0, 1, 3, Gfx3DState_NextPolyId(sys->unk_8b0), FX_Mul(t, 0x1f000) >> 12, 0);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    texParam = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    trans[0] = 0;
    trans[1] = 0;
    trans[2] = -0x666;
    NNS_G3dGeBufferOP_N(0x1c, trans, 3);
    func_02043db4(1, 0x100000, 0xc0000, v > 0 ? 0x7fff : 0);
}

// Blends two RGB555 colors; t is fx32 in [0, 0x1000].
u16 func_0203d144(int c0, int c1, int t) {
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
