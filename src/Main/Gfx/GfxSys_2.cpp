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
extern void func_02019228(void);
extern void func_02014304(const void *src, u32 offset, u32 size);
extern void func_0201439c(const void *src, u32 offset, u32 size);
extern void NNS_G3dInit(void);
extern void func_02023a70(void);
extern void func_02023b44(void *obj, int a, int b, int c);
extern void *NNS_GfdGetLnkTexVramManagerWorkSize(int n);
extern void *NNS_GfdGetLnkPlttVramManagerWorkSize(int n);
extern void func_0203beac(GfxSys *sys, int state);
extern void NNS_G3dGeSetBuffer(void *arg);
extern void NNS_G3dGeUseFastDma(int arg);
extern BOOL func_02018d58(void);

#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile u32 *)(a))

}

extern "C" {

extern u8 data_02fe00a0[];
extern void func_0203c880(GfxSys *sys);
extern void func_0201369c(int a, int b, int c);
extern void func_02024160(void *obj);
extern void func_02013c04(void);
extern void func_020438e8(void *obj);
extern void func_02043d20(void *obj, int a);
extern void NNS_G3dGeSendDL(void *a, int b);
extern void NNS_G3dGeFlushBuffer(void);
extern void *func_02014240(void);
extern void *func_02014294(void);
extern void *func_02014260(void);
extern void *func_020142b4(void);
extern void *func_02014128(void);
extern void *func_020140d4(void);
extern void *func_020140f4(void);
extern void *func_02014148(void);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);

void func_0203b924(GfxSys *sys, u16 color) {
    sys->unk_008 = color;
    func_02019228();
    func_02014304(&sys->unk_008, 0, 2);
}

void func_0203b948(GfxSys *sys, u16 color) {
    sys->unk_00a = color;
    func_02019228();
    func_0201439c(&sys->unk_00a, 0, 2);
}

}

extern "C" {

}

extern "C" {

extern void *func_0203dec8(u32 size, int align);
extern void func_02016e28(void *dst, u32 value, u32 size);
extern void func_02015298(int a);
extern void func_02015410(int a);
extern void NNS_GfdInitLnkTexVramManager(u32 a, u32 b, void *c, void *d, BOOL e);
extern void NNS_GfdInitLnkPlttVramManager(u32 a, void *b, void *c, BOOL d);
extern void func_0203c2bc(GfxSys *sys);
extern void func_0203c638(GfxSys *sys);
extern void func_0203d770(void);
extern void func_02013704(int a);
extern void func_020154ec(int a);
extern void func_02014ec8(int a);
extern void func_02015510(int a);
extern void func_020155ac(int a);
extern void func_02039c54(GfxMgr *mgr, int state);
extern void func_0203e8e0(void);
extern void func_0203ea00(void);
extern void func_0203ea6c(void);
extern void func_0203eb8c(void);
extern void *NNS_GfdDefaultFuncAllocTexVram;
extern void *NNS_GfdDefaultFuncFreeTexVram;
extern void *NNS_GfdDefaultFuncAllocPlttVram;
extern void *NNS_GfdDefaultFuncFreePlttVram;

static inline void GfxSys_InitTexVram(GfxSys *sys, u32 size) {
    if (sys->unk_018 == 0) {
        sys->unk_018 = (u32)func_0203dec8((u32)sys->unk_014, 4);
    } else {
        func_02016e28((void *)sys->unk_018, 0, (u32)sys->unk_014);
    }
    NNS_GfdInitLnkTexVramManager(size, 0, (void *)sys->unk_018, sys->unk_014, TRUE);
}

static inline void GfxSys_InitPlttVram(GfxSys *sys, u32 size) {
    if (sys->unk_020 == 0) {
        sys->unk_020 = (u32)func_0203dec8((u32)sys->unk_01c, 4);
    } else {
        func_02016e28((void *)sys->unk_020, 0, (u32)sys->unk_01c);
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

extern void func_020150cc(int a);
extern void func_0201561c(int a);
extern void func_02043904(void *obj);

}

extern "C" {

extern void func_02015780(void);
extern void func_0201576c(void);
extern void func_02023c9c(void *obj, void *src, int count);
extern int FX_Div(int a, int b);
extern void func_020137a8(volatile void *reg, int a, int b);

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
