#ifndef MAIN_GFX_MODEL_H
#define MAIN_GFX_MODEL_H

#include "types.h"

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

typedef struct ModelExtPltt {
    /* 0x00 */ u8 unk_00[0x60];
    /* 0x60 */ void *transfer;
} ModelExtPltt;

// 3D model instance (built by func_02041440, torn down by func_02041558).
typedef struct Model {
    /* 0x000 */ u8 unk_000[0x28];
    /* 0x028 */ ModelRes *res;
    /* 0x02c */ char name[0x20];
    /* 0x04c */ u8 unk_04c[0x20];
    /* 0x06c */ u32 flags;
    /* 0x070 */ u8 unk_070[8];
    /* 0x078 */ ModelPart *parts;
    /* 0x07c */ s32 unk_07c;
    /* 0x080 */ s32 numParts;
    /* 0x084 */ u8 unk_084[4];
    /* 0x088 */ u8 pltt[0x60];
    /* 0x0e8 */ void *plttTransfer;
    /* 0x0ec */ struct ModelExtPltt *extPltt;
    /* 0x0f0 */ u8 unk_0f0[0xc];
    /* 0x0fc */ union {
        struct {
            s32 x;
            s32 y;
        };
        ModelPos pos[1];
    };
    /* 0x104 */ u8 unk_104[0x4c];
    /* 0x150 */ s32 unk_150;
    /* 0x154 */ u16 color;
    /* 0x156 */ u8 unk_156[0xa];
} Model; // size 0x160

extern void func_02041218(void *pltt);
extern void func_02041278(void *pltt);
extern void func_02041440(Model *model, const char *name, int a);
extern void func_02041558(Model *model);
extern void func_020417e0(Model *model, void *res);
extern void func_02041d9c(Model *model, int a, int b);
extern void func_02042628(Model *model, void *tex, ModelPart *part, u8 a);
extern void *NNS_G2dGetAnimSequenceByIdx(void *res, int idx);
extern void *NNS_G2dGetCellDataByIdx(void *res, u16 idx);

#ifdef __cplusplus
}
#endif

#endif
