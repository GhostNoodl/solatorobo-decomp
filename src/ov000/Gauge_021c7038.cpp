#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

class Gauge021c7038 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1c();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2c();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3c();
    virtual void vfunc_40(s32 x, s32 y, s32 z, s32 h, s32 idx);
    virtual void vfunc_44(s32 x, s32 y, s32 z, s32 w, s32 h, s32 idx);
    virtual void vfunc_48(s32 x, s32 y, s32 z, s32 w, s32 h, s32 idx);

    u8 pad_04[0x8];
    u32 unk_0c;
    u8 pad_10[0x38];
    s32 unk_48;
    u8 pad_4c[0x4];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 pad_64[0x4];
    s32 unk_68;
};

typedef struct {
    u32 pad_00 : 4;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 pad_06 : 2;
    u32 b8 : 1;
    u32 pad_09 : 23;
} Flags021c7038;

extern "C" {

extern u8 *data_02097d48;
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
s32 func_02043d84(void *p);
s32 FX_Div(s32 n, s32 d);

static inline void G3_Cmd1_021c7038(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline s32 Ratio021c7038(s32 n, s32 d) {
    s32 r = FX_Div(n, d);
    if (r >= 0x1000) {
        r = 0x1000;
    } else if (r < 0) {
        r = 0;
    }
    return r;
}

// The gauge size, loop counter, step and alpha live in parameters: that gives
// the target register assignment (see docs/MATCHING.md, round ovhimid6).
#define FLAGS(g) (*(Flags021c7038 *)&(g)->unk_0c)

void func_ov000_021c7038(Gauge021c7038 *self, s32 a, VecFx32 *pos, s32 h, s32 scale, s32 w, s32 i, s32 step) {
    u8 *g = data_02097d48;
    u32 attr;
    s32 z;

    s32 id = func_02043d84(g + 0x8b0);
    G3_Cmd1_021c7038(0x2a, 0x20000000);
    attr = 0x1f08d0 | (id << 24);
    G3_Cmd1_021c7038(0x29, attr);
    w = self->unk_50 << 12;
    h = self->unk_54 << 12;
    z = pos->z;
    self->vfunc_44(pos->x, pos->y, z, w, h, 1);
    self->vfunc_44(pos->x - 0x1000, pos->y - 0x1000, z, w + 0x2000, h + 0x2000, 0);
    if (FLAGS(self).b5) {
        self->vfunc_40(pos->x - 0x2000, pos->y, z, h, 0);
        self->vfunc_40(pos->x + w + 0x1000, pos->y, z, h, 0);
    }
    z = pos->z;
    if (FLAGS(self).b8 && self->unk_5c < self->unk_68) {
        G3_Cmd1_021c7038(0x29, (func_02043d84(g + 0x8b0) << 24) | 0x8d0 | ((LO_FX_MUL(scale, 0x14000) >> 12) << 16));
        self->vfunc_44(pos->x, pos->y, z + 0x20, (LO_FX_MUL(w, Ratio021c7038(self->unk_68, self->unk_60)) + 0x800) & 0x7ffff000, h, 3);
    }
    z = pos->z;
    if (self->unk_5c > 0) {
        G3_Cmd1_021c7038(0x29, attr);
        self->vfunc_48(pos->x, pos->y, z + 0x30, (LO_FX_MUL(w, Ratio021c7038(self->unk_5c, self->unk_60)) + 0x800) & 0x7ffff000, h, 2);
    }
    z = pos->z;
    if (self->unk_58 > 1) {
        G3_Cmd1_021c7038(0x29, attr);
        step = FX_Div(w, self->unk_58 << 12);
        for (i = 1; i < self->unk_58; i++) {
            self->vfunc_40(pos->x + step * i, pos->y, z + 0x40, h, 0);
        }
    }
    z = pos->z;
    if (FLAGS(self).b4) {
        a = LO_FX_MUL(LO_FX_MUL(self->unk_48, scale), 0x10000) >> 12;
        if (a != 0) {
            G3_Cmd1_021c7038(0x29, (func_02043d84(g + 0x8b0) << 24) | 0x8d0 | (a << 16));
            self->vfunc_44(pos->x, pos->y, z + 0x50, w, h, 4);
        }
    }
}

}
