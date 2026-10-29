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

extern void OS_Terminate(void);
extern void func_02224c1c(void);  /* TWL only */

static inline u32 GfxReg_GetObjCharShift(u32 addr) {
    int mode = (int)(REG32(addr) & 0x300010);
    return (mode >> 20) & 3;
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

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
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
        if ((ch == 0 || ch == 3) && data_02097d44.fadeState[3] != 0) {
            data_02097d44.fadeState[3] = 1;
            data_02097d44.fadeTimer[3] = 0;
            data_02097d44.fadeDuration[3] = duration;
            data_02097d44.fadeStart[3] = 0;
            data_02097d44.fadeEnd[3] = 0;
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
            data_02097d44.fadeState[3] = 3;
            data_02097d44.fadeTimer[3] = 0;
            data_02097d44.fadeDuration[3] = duration;
            data_02097d44.fadeStart[3] = 0;
            data_02097d44.fadeEnd[3] = 0;
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
