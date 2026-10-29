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

void func_0203b6a0(void) {
    GfxSys *sys;
    if (data_02097d44.sys != NULL) {
        return;
    }
    data_02097dd0->cur = data_02097dd0->unk_04;
    sys = (GfxSys *)func_0203dd9c(sizeof(GfxSys));
    if (sys != NULL) {
        func_02043858(sys->unk_8b0);
        func_0203b70c(sys);
    }
    data_02097d44.sys = sys;
    data_02097dd0->cur = data_02097dd0->unk_08;
}

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
    data_02097d44.unk_8 = 0;
    data_02097d44.unk_0 = 0;
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
