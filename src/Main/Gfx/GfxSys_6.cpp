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

}

extern "C" {

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
extern u8 func_02043d48(void *obj);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void func_02043db4(int a, int b, int c, int d);


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

// The fade channels (indexed by screen) are this TU's own .bss objects, addressed through one
// pool literal. They are defined after the first function so that they keep definition order
// (a size-sorted run otherwise puts the arrays first). As TU objects in one pool their accesses
// stay in source order against the context copy in func_0203ce3c, which is why that function
// needs no volatile.
u32 data_02097d44;
GfxSys *data_02097d48;
GfxFadeFunc data_02097d4c;
int data_02097d50[5];
int data_02097d64[5];
int data_02097d78[5];
int data_02097d8c[5];
int data_02097da0[5];
int data_02097db4[5];

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

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
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

}
