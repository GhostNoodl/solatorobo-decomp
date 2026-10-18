#include "ov000/Vec.h"

typedef struct {
    u8 pad[8];
    s32 state;
    u8 pad0c[0x1c];
    s32 unk_28;
} Obj021bc6c0;

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef021bc6c0;

extern "C" {
extern u8 *data_02097d48;
extern DLRef021bc6c0 data_0208b3d0;
extern DLRef021bc6c0 data_020828f8;
void func_02043d20(void *obj, int a);
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
void func_ov000_021bc86c(Obj021bc6c0 *self);
void func_ov000_021bcd08(Obj021bc6c0 *self);

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

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

void func_ov000_021bc6c0(Obj021bc6c0 *self) {
    if (self->state == 0) {
        return;
    }
    switch (self->state) {
    case 1: {
        int v1b[3];
        int v1c[3];
        u32 c12;
        u32 c20;
        u32 c2a;
        u32 c29;
        u8 *g = data_02097d48;
        s32 alpha = LO_FX_MUL(FX_SinCosTable_[((self->unk_28 << 14) >> 16) * 2], 0xf000) >> 12;
        if (alpha == 0) {
            return;
        }
        func_02043d20(g + 0x8b0, 0);
        c29 = (func_02043d48(g + 0x8b0) << 24) | 0xd0 | (alpha << 16);
        NNS_G3dGeBufferOP_N(0x29, &c29, 1);
        c2a = 0x20000000;
        NNS_G3dGeBufferOP_N(0x2a, &c2a, 1);
        c20 = 0x4b1d;
        NNS_G3dGeBufferOP_N(0x20, &c20, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        v1c[0] = 0;
        v1c[1] = 0;
        v1c[2] = -0xc4d;
        NNS_G3dGeBufferOP_N(0x1c, v1c, 3);
        v1b[0] = 0x100000;
        v1b[1] = 0xc0000;
        v1b[2] = 0x1000;
        NNS_G3dGeBufferOP_N(0x1b, v1b, 3);
        NNS_G3dGeSendDL(data_0208b3d0.unk_04, (u32)data_020828f8.unk_04);
        c12 = 1;
        NNS_G3dGeBufferOP_N(0x12, &c12, 1);
        break;
    }
    case 2:
        func_ov000_021bc86c(self);
        break;
    case 3:
        func_ov000_021bcd08(self);
        break;
    }
}

}
