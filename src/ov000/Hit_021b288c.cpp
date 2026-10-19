#include "nitro/fx.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad[0x68];
    s32 height;
    u8 pad6c[4];
    VecFx32 pos;
    u8 pad7c[0x1c];
    u16 rot;
    u8 pad9a[6];
    s32 vy;
    u8 pada4[0xac4];
    u16 flags;
    u16 flags2;
} Obj021b288c;

typedef struct {
    u8 pad[0x2c];
    u32 keys;
} Data02fe0f14;

extern "C" {

extern Data02fe0f14 data_02fe0f14;
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);

s32 func_ov000_021b288c(Obj021b288c *self) {
    s32 ret = 1;
    VecFx32 a;
    VecFx32 b;
    if (self->flags2 & 2) {
        return -1;
    }
    a = self->pos;
    b = self->pos;
    a.y += self->height;
    b.y -= 0x19a;
    if (func_01ffbd6c(&a, &b, 0x20000000, 0, 0, -1) != -0x1000) {
        if ((self->flags & 0x80) || (data_02fe0f14.keys & 0x400)) {
            return -1;
        }
    }
    if (self->flags & 0x40) {
        s32 s;
        s32 c;
        ret = 0;
        a = self->pos;
        a.y += self->height >> 2;
        b.x = a.x;
        b.z = a.z;
        b.y = a.y;
        s = FX_MUL(FX_SinCosTable_[(self->rot >> 4) * 2], 0x1800);
        c = FX_MUL(FX_SinCosTable_[(self->rot >> 4) * 2 + 1], 0x1800);
        a.x -= s >> 3;
        a.z -= c >> 3;
        b.x += s;
        b.z += c;
        if (func_01ffbd6c(&a, &b, 0x40000000, 0, 0, -1) == -0x1000) {
            a.y += 0x333;
            b.y += 0x333;
            if (func_01ffbd6c(&a, &b, 0x40000000, 0, 0, -1) != -0x1000) {
                ret = 1;
            }
        } else {
            ret = 1;
        }
    }
    if (ret) {
        if (self->flags & 0x40) {
            self->vy += (0xcd - self->vy) >> 2;
        } else if (self->flags & 0x80) {
            self->vy += (-0xcd - self->vy) >> 2;
        } else {
            self->vy = 0;
        }
        self->pos.y += self->vy;
    }
    return ret;
}

}
