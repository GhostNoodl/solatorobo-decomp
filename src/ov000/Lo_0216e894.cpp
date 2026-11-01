#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;

struct Obj0216e894 {
    u8 unk_00[0x4];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    u8 unk_20[0x8];
    s32 unk_28;
    u8 unk_2c[0x8];
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
};

void func_ov000_0216e894(Obj0216e894 *self) {
    if (LBIT(self, 0).b13 == 1) {
        return;
    }
    LBIT(self, 0).b13 = 1;
    if (LBIT(self, 0).b14 == 1) {
        self->unk_0c = 1;
    } else if (LBIT(self, 0).b10 == 1) {
        self->unk_0c = 2;
    } else {
        self->unk_0c = 3;
    }
    if (LBIT(self, 0).b6 != 1) {
        return;
    }
    func_ov000_0219bf90();
    if (!func_ov000_021b4738()) {
        s32 v = self->unk_1c;
        u8 *g;
        if (v > 0xffff) {
            v = 0xffff;
        }
        func_020627fc(self->unk_0c);
        func_0206280c(v);
        g = data_ov000_021ccd54;
        g[0xac] = 1;
        func_ov000_02182590(g + 0xac);
    }
    self->unk_04 = 9;
}

static inline void Bounce(Obj0216e894 *self) {
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b8 = 0;
    LBIT(self, 0).b10 = 1;
    self->unk_34 = 0x2000;
    self->unk_38 = 0x2000;
    self->unk_3c = 0;
}

void func_ov000_0216e968(Obj0216e894 *self) {
    s32 t;
    if (!LBIT(self, 0).b16) {
        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        LBIT(self, 0).b16 = 1;
    }
    self->unk_38 += 0x1000;
    t = FX_Div(self->unk_38, 0x14000);
    if (t >= 0x1000) {
        t = 0x1000;
        if (self->unk_38 >= 0x3c000) {
            if (LBIT(self, 0).b9 == 1) {
                if (self->unk_38 >= 0x64000) {
                    if (self->unk_08 == 2) {
                        if (LBIT(self, 0).b17 == 1 && !LBIT(self, 0).b14 && self->unk_28 != 0 && self->unk_28 < self->unk_1c) {
                            Bounce(self);
                        } else {
                            func_ov000_0216e894(self);
                        }
                    } else {
                        if (LBIT(self, 0).b17 == 1 && !LBIT(self, 0).b14 && self->unk_28 != 0 && self->unk_28 > self->unk_1c) {
                            Bounce(self);
                        } else {
                            func_ov000_0216e894(self);
                        }
                    }
                    self->unk_38 = 0;
                    LBIT(self, 0).b8 = 0;
                }
            } else {
                LBIT(self, 0).b5 = 0;
                self->unk_38 = 0;
                LBIT(self, 0).b8 = 0;
            }
        }
    }
    self->unk_3c = (s32)(((s64)FX_SinCosTable_[((s32)(t << 15) >> 16) * 2] * (s64)0x1800 + 0x800) >> 12);
}

}
