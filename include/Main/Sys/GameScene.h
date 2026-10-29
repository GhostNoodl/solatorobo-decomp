#ifndef MAIN_SYS_GAMESCENE_H
#define MAIN_SYS_GAMESCENE_H

#include "types.h"
#include "Main/Gfx/Model.h"
#include "Main/Gfx/GfxMgr.h"

// Game scene with HUD state (the class of func_020534dc). The vtable stays in asm.
struct GameScene {
    /* 0x000 */ // vtable
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void unk_vf0c();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void unk_vf24();
    virtual void unk_vf28();
    virtual void unk_vf2c();
    virtual void unk_vf30();
    virtual void unk_vf34();
    virtual void unk_vf38();
    virtual void unk_vf3c();
    virtual void unk_vf40();
    virtual void unk_vf44();
    virtual void unk_vf48();
    virtual void unk_vf4c();
    virtual void unk_vf50();
    virtual void unk_vf54();
    virtual void unk_vf58();
    virtual void unk_vf5c();
    virtual void unk_vf60();
    virtual void unk_vf64();
    virtual void unk_vf68();
    virtual void unk_vf6c();
    virtual void unk_vf70();
    virtual void unk_vf74();
    virtual void unk_vf78();
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void unk_vf90();
    virtual void unk_vf94();
    virtual void Update98();
    virtual void unk_vf9c();
    virtual void unk_vfa0();
    virtual void unk_vfa4();
    virtual void unk_vfa8();
    virtual void UpdateAc();
    virtual void unk_vfb0(int a, int b);
    virtual void UpdateB4(void *p);
    /* 0x004 */ u32 flag0 : 1;
    /* 0x004 */ u32 unk_04_1 : 1;
    /* 0x004 */ u32 flag2 : 1;
    /* 0x004 */ u32 unk_04_3 : 22;
    /* 0x004 */ u32 flag25 : 1;
    /* 0x004 */ u32 unk_04_26 : 1;
    /* 0x004 */ u32 flag27 : 1;
    /* 0x004 */ u32 unk_04_28 : 4;
    /* 0x008 */ u8 unk_008[0xc];
    /* 0x014 */ Model *model;
    /* 0x018 */ s16 unk_018;
    /* 0x01a */ u8 unk_01a[0x6a];
    /* 0x084 */ s32 shakeType;
    /* 0x088 */ u8 unk_088[0x30];
    /* 0x0b8 */ u32 unk_b8_0 : 4;
    /* 0x0b8 */ u32 flag4 : 1;
    /* 0x0b8 */ u32 unk_b8_5 : 6;
    /* 0x0b8 */ u32 flag11 : 1;
    /* 0x0b8 */ u32 lock : 2;
    /* 0x0b8 */ u32 fadeReq : 1;
    /* 0x0b8 */ u32 unk_b8_15 : 1;
    /* 0x0b8 */ u32 fadeType : 8;
    /* 0x0b8 */ u32 fadeFrames : 8;
    /* 0x0bc */ u32 shake : 2;
    /* 0x0bc */ u32 effect : 4;
    /* 0x0bc */ u32 unk_bc_6 : 26;
    /* 0x0c0 */ u32 unk_c0_0 : 1;
    /* 0x0c0 */ u32 flag1 : 1;
    /* 0x0c0 */ u32 unk_c0_2 : 4;
    /* 0x0c0 */ u32 count : 8;
    /* 0x0c0 */ u32 unk_c0_14 : 18;
    /* 0x0c4 */ u8 unk_0c4[0xc];
    /* 0x0d0 */ u8 unk_0d0[0xa6c];
    /* 0xb3c */ s32 shakeX;
    /* 0xb40 */ s32 shakeY;
    /* 0xb44 */ s32 shakeZ;
    /* 0xb48 */ s32 shakeTime;
    /* 0xb4c */ s32 shakePeriod;
    /* 0xb50 */ s32 shakeAmp;
    /* 0xb54 */ s32 shakePhase;
    /* 0xb58 */ s32 shakeLimit;
    /* 0xb5c */ s32 unk_b5c;
    /* 0xb60 */ s32 unk_b60;
    /* 0xb64 */ s32 unk_b64;
};

extern "C" {

typedef struct ShakeEntry {
    s32 unk_0;
    s32 value;
} ShakeEntry;

typedef struct ShakeTable {
    ShakeEntry entries[8];
} ShakeTable;

extern const ShakeTable data_020829d0;
extern s32 data_02097d78[5];
extern const s16 FX_SinCosTable_[];

extern void func_0203c9e8(int a, int b);
extern void func_0203cc58(int a, int b, int c);
extern s32 FX_Div(s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_02043d20(void *obj, int a);
extern s32 func_02043d84(void *obj);
extern void func_02052fcc(GameScene *scene);
extern s32 func_020572f8(GameScene *scene, void *p);
extern void *func_0203972c(void *blocks, u32 count);
extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

// Buffered vertex commands, for files that do not include the SDK G3 header.
#ifndef NITRO_GX_H
static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}
#endif

// Points the model at frame 0 of animation `idx`: the part's own texture, or the first cell of
// the sequence when the part has none.
static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

static inline s32 GameScene_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

}

#endif
