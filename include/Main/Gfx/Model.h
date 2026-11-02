#ifndef MAIN_GFX_MODEL_H
#define MAIN_GFX_MODEL_H

#include "types.h"
#include "Main/Gfx/PlttRes.h"
#include "nitro/fx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ModelRes {
    /* 0x0 */ u8 unk_0[4];
    /* 0x4 */ void *texRes;
    /* 0x8 */ u8 unk_8[4];
    /* 0xc */ void *mdlRes;
} ModelRes;

typedef struct ModelPartRes {
    /* 0x00 */ u8 unk_00[0x30];
    /* 0x30 */ void *tex;
} ModelPartRes;

typedef struct ModelPart {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ ModelPartRes *res;
    /* 0x08 */ u8 unk_08[0x20];
} ModelPart; // size 0x28

typedef struct ModelPos {
    s32 x;
    s32 y;
} ModelPos;

// 3D model instance (built by func_02041440, torn down by func_02041558).
typedef struct Model {
    /* 0x000 */ u8 unk_000[0x28];
    /* 0x028 */ ModelRes *res;
    /* 0x02c */ char name[0x20];
    /* 0x04c */ char unk_04c[0x20]; // file name (the name argument of func_02041440)
    /* 0x06c */ u32 flags;
    /* 0x070 */ u8 unk_070[8];
    /* 0x078 */ ModelPart *parts;
    /* 0x07c */ s32 unk_07c;
    /* 0x080 */ s32 numParts;
    /* 0x084 */ u8 unk_084;
    /* 0x085 */ u8 unk_085;
    /* 0x086 */ u8 unk_086[2];
    /* 0x088 */ PlttRes pltt;
    /* 0x0ec */ PlttRes *extPltt;
    /* 0x0f0 */ u8 unk_0f0[0xc];
    /* 0x0fc */ union {
        struct {
            s32 x;
            s32 y;
        };
        ModelPos pos[1];
    };
    /* 0x104 */ u8 unk_104[8];
    /* 0x10c */ s32 unk_10c;
    /* 0x110 */ s32 unk_110;
    /* 0x114 */ MtxFx22 mtx[3]; // identity after func_02041440
    /* 0x144 */ s32 unk_144;
    /* 0x148 */ s32 unk_148;
    /* 0x14c */ s32 unk_14c;
    /* 0x150 */ s32 unk_150;
    /* 0x154 */ u16 color;
    /* 0x156 */ u8 unk_156[2];
    /* 0x158 */ void *unk_158;
    /* 0x15c */ u8 unk_15c[4];
} Model; // size 0x160

extern void func_02041440(Model *model, const char *name, int a);
extern void func_02041558(Model *model);
extern void func_020417e0(Model *model, void *res);
extern void func_02041d9c(Model *model, int a, int b);
extern void func_02042628(Model *model, void *tex, ModelPart *part, u8 a);
// Game-side views of two nnsys/g2d/g2d_Load.h functions. The SDK takes a u16 index and typed banks;
// these callers pass the index at full width, and declaring it u16 adds a truncation to nine functions
// (SlidePanel, TextWin, seven ov000 TUs). So this header and g2d_Load.h cannot be included together.
extern void *NNS_G2dGetAnimSequenceByIdx(void *res, int idx);
extern void *NNS_G2dGetCellDataByIdx(void *res, u16 idx);

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

#ifdef __cplusplus
}
#endif

#endif
