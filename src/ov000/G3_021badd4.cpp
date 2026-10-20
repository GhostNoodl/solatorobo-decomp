#include "ov000/LoCommon.h"

typedef struct {
    u32 lo : 8;
    u32 alpha : 5;
    u32 id : 8;
    u32 hi : 11;
} Attr021badd4;

typedef struct {
    s32 unk_00;
    s32 state;
    u8 pad_08[8];
    VObj *obj;
    u8 pad_14[8];
    s32 t0;
    s32 t1;
    u8 pad_24[4];
    s32 t2;
} Self021badd4;

extern "C" {
extern u8 *data_02097d48;
extern void *data_0208b3d0;
extern void *data_020828f8;
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);

static inline s32 FxMulL021badd4(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

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

void func_ov000_021badd4(Self021badd4 *self) {
    u8 *g = data_02097d48;
    s32 a;
    s32 b;
    s32 x;
    VObj *obj;
    s32 c;
    s32 y;
    s32 t;
    s32 base;
    t = self->t0;
    if (self->state != 13) {
        a = FxMulL021badd4(t, 0x16000) >> 12;
        b = FxMulL021badd4(0x1000 - t, 0x8000);
    } else {
        a = LO_FX_MUL(0x1000 - t, 0x16000) >> 12;
        b = 0;
    }
    if (a != 0) {
        G3_Cmd1(0x29, (func_02043d48(g + 0x8b0) << 24) | 0xd0 | (a << 16));
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3_Vec(0x1c, 0x80000, 0x60000 - b, -0x91a);
        G3_Cmd1(0x20, 0x87);
        G3_Cmd1(0x2a, 0x20000000);
        G3_Vec(0x1b, 0x100000, 0x18000, 0x1000);
        NNS_G3dGeSendDL(data_0208b3d0, (u32)data_020828f8);
        G3_Cmd1(0x12, 1);
    }
    t = self->t1;
    if (self->state != 13) {
        a = FxMulL021badd4(t, 0x16000) >> 12;
        b = FxMulL021badd4(0x1000 - t, 0x10000);
    } else {
        a = LO_FX_MUL(0x1000 - t, 0x16000) >> 12;
        b = 0;
    }
    if (a != 0) {
        G3_Cmd1(0x29, (func_02043d48(g + 0x8b0) << 24) | 0xd0 | (a << 16));
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3_Vec(0x1c, 0x80000, b + 0x63000, -0x91a);
        G3_Cmd1(0x20, 0x7b);
        G3_Cmd1(0x2a, 0x20000000);
        G3_Vec(0x1b, 0x100000, 0xe000, 0x1000);
        NNS_G3dGeSendDL(data_0208b3d0, (u32)data_020828f8);
        G3_Cmd1(0x12, 1);
    }
    obj = self->obj;
    x = 0x100 - (LFLD(s32, obj, 0x44) + 0x10);
    t = self->t2;
    if (self->state != 13) {
        y = 0x68;
        c = FxMulL021badd4(t, 0x2e000) >> 12;
        x += FxMulL021badd4(0x1000 - t, 0x20000) >> 12;
    } else {
        y = 0x68;
        c = FxMulL021badd4(0x1000 - t, 0x1f000) >> 12;
        x -= FxMulL021badd4(t, 0x20000) >> 12;
    }
    if (c == 0) {
        return;
    }
    if (c > 30) {
        c = 30;
    }
    LFLD(s32, obj, 0x70) = -0x81a;
    LFLD(Attr021badd4, self->obj, 4).alpha = (u8)c;
    LFLD(Attr021badd4, self->obj, 4).id = func_02043d48(g + 0x8b0);
    self->obj->vfunc_20(x, y - 0xb);
    self->obj->vfunc_90();
}
}
