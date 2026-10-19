#include "ov000/Actor.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
} Bits021b7b50;

typedef struct {
    u8 pad_00[0x2c];
    u8 unk_2c[0x20];
    void *unk_4c;
    void *unk_50[1];
    u8 unk_54[0x54];
    VecFx32 pos;
    u8 pad_b4[0x32];
    u8 unk_e6;
    u8 unk_e7;
    u8 unk_e8;
    Bits021b7b50 unk_e9;
    u8 pad_ea[2];
    void *unk_ec;
    u8 pad_f0[5];
    u8 unk_f5;
    Bits021b7b50 unk_f6;
    u8 pad_f7;
    s32 unk_f8;
    VecFx32 unk_fc;
    VecFx32 unk_108;
} Obj021b7b50;

extern "C" {

BOOL func_ov000_021b7f0c(Obj021b7b50 *self);
void func_0203f8d8(void *p);
void func_0203f920(void *p);
BOOL func_01ffc23c(VecFx32 *v, VecFx32 *min, VecFx32 *max);
s32 VEC_Mag(const VecFx32 *v);
s32 FX_Div(s32 a, s32 b);
void func_ov000_021b7838(void *p, s32 a);

static inline void *Obj021b7b50_GetModel(Obj021b7b50 *self, u8 n) {
    if (n == 0) {
        return self->unk_54;
    }
    return self->unk_50[n - 1];
}

static inline void Obj021b7b50_SetModel(Obj021b7b50 *self, u8 n) {
    void *p;
    self->unk_e7 = n;
    p = Obj021b7b50_GetModel(self, n);
    if (p != NULL) {
        self->unk_4c = p;
    }
}

s32 func_ov000_021b7b50(Obj021b7b50 *self) {
    VecFx32 d;
    s32 mag;
    switch (self->unk_f5) {
    case 0:
        if (!func_ov000_021b7f0c(self)) {
            break;
        }
        self->unk_f6.b2 = 1;
        self->unk_e9.b0 = 1;
        if (!self->unk_f6.b0 && !self->unk_f6.b1) {
            if (self->unk_ec != NULL) {
                func_0203f8d8(self->unk_ec);
            }
            self->unk_f5 = 10;
            break;
        }
        self->unk_f5++;
    case 1:
        if (self->unk_f6.b3 && self->unk_ec != NULL) {
            func_0203f8d8(self->unk_ec);
        }
        {
            VecFx32 *g = &data_ov000_021ccd54->unk_f4.pos;
            s32 gx = g->x, gy = g->y, gz = g->z;
            d.x = self->pos.x;
            d.y = self->pos.y;
            d.z = self->pos.z;
            d.x -= gx;
            d.y -= gy;
            d.z -= gz;
        }
        if (!func_01ffc23c(&d, &self->unk_fc, &self->unk_108)) {
            self->unk_f6.b2 = 0;
            if (self->unk_ec != NULL && !self->unk_f6.b3) {
                func_0203f920(self->unk_ec);
            }
            break;
        }
        mag = VEC_Mag(&d);
        if (self->unk_f8 != 0 && self->unk_f8 != 0x1000) {
            mag = FX_Div(mag, self->unk_f8);
        }
        self->unk_e8 = 0x1f;
        if (self->unk_f6.b0) {
            if (mag > 0xc3000) {
                self->unk_f6.b2 = 0;
                if (self->unk_ec != NULL && !self->unk_f6.b3) {
                    func_0203f920(self->unk_ec);
                }
                break;
            }
            if (!self->unk_f6.b2) {
                self->unk_e8 = 1;
                self->unk_f6.b2 = 1;
            } else if (mag > 0x9b000) {
                self->unk_e8 = 0x1f - (u8)((s64)(mag - 0x9b000) * 0x1c / 0x28000);
            }
            if (self->unk_ec != NULL && !self->unk_f6.b3) {
                if (mag < 0x3c000) {
                    func_0203f8d8(self->unk_ec);
                } else {
                    func_0203f920(self->unk_ec);
                }
            }
        }
        if (self->unk_f6.b1 && self->unk_f6.b2) {
            if (mag > 0x9b000) {
                u8 n = 1;
                if (self->unk_e6 < n) {
                    n = self->unk_e6;
                }
                if (n != self->unk_e7) {
                    Obj021b7b50_SetModel(self, n);
                }
            } else if (self->unk_e7 != 0) {
                Obj021b7b50_SetModel(self, 0);
            }
        }
        if (mag < 0xaf000) {
            func_ov000_021b7838(self->unk_2c, 0x1000);
        }
        break;
    case 10:
        func_ov000_021b7838(self->unk_2c, 0x1000);
        self->unk_f6.b2 = 1;
        break;
    }
    return 0;
}

}
