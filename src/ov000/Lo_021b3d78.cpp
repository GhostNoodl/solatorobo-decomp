#include "types.h"
#include "nitro/fx.h"

typedef struct {
    u8 pad[0x1b0];
    VecFx32 pos;
    u8 pad1bc[0x11];
    u8 unk_1cd;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 4;
    u8 pad1cf;
    VecFx32 vel;
    u8 pad1dc[0xc];
    s32 unk_1e8;
} Player021b3d78;

typedef struct {
    u8 pad[0x70];
    VecFx32 pos;
    u8 pad7c[0xb90 - 0x7c];
    VecFx32 target;
    s32 rate;
} Mgr021b3d78;

extern "C" {

extern Player021b3d78 *data_ov000_021ccd54;

#define FXM(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov000_021b3d78(Mgr021b3d78 *self) {
    Player021b3d78 *p = data_ov000_021ccd54;
    s32 dist;
    s32 v;
    s32 half;
    if (p->unk_1cd != 0) {
        return;
    }
    p->pos.x = self->pos.x;
    p->pos.y = self->pos.y;
    p->pos.z = self->pos.z;
    if (self->rate == 0) {
        return;
    }
    {
        VecFx32 d;
        d.x = FX_Mul(self->target.x - self->pos.x, self->rate);
        d.y = FX_Mul(self->target.y - self->pos.y, self->rate);
        d.z = FX_Mul(self->target.z - self->pos.z, self->rate);
        p->vel = d;
    }
    p->b0 = 1;
    half = 0x800;
    dist = VEC_Distance(&self->target, &self->pos);
    if (dist < 0x5800) {
        dist -= 0x5800;
        v = dist + (dist >> 2);
    } else if (dist > 0x9800) {
        v = dist - 0x9800;
    } else {
        v = half - 0x1800;
    }
    if (v != -0x1000) {
        p->unk_1e8 = v;
        p->b2 = 2;
    }
    self->rate = 0;
}

}
