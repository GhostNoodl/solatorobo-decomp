#include "Main/Gfx/GfxMgr.h"

extern "C" {

void func_0203cd84(void);
void func_0203ce3c(void);

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

typedef struct GfxFadeCtx {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ int state;
    /* 0x08 */ int timer;
    /* 0x0c */ int duration;
    /* 0x10 */ int start;
    /* 0x14 */ int end;
} GfxFadeCtx;

typedef int (*GfxFadeFunc)(GfxFadeCtx *ctx);

void func_0203ced8(int mode) {
    int ch;
    int t;
    int v;
    if (mode != -1) {
        if (data_02097d44.fadeState[2] != 0) {
            func_0203cd84();
        }
        if (data_02097d44.fadeState[3] != 0) {
            func_0203ce3c();
        }
        return;
    }
    if (data_02097d44.fadeState[4] != 0) {
        G2x_SetBlendBrightness_((volatile void *)0x4000050, data_02097d44.fadeBase[4], data_02097d44.fadeStart[4]);
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

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
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
    sys = data_02097d44.sys;
    t = FX_Div((v < 0 ? -v : v) << 12, 16 << 12);
    func_02043d20(data_02097d44.sys->unk_8b0, 0);
    polyAttr = G3_PackPolygonAttr(0, 1, 3, func_02043d48(sys->unk_8b0), FX_Mul(t, 0x1f000) >> 12, 0);
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
