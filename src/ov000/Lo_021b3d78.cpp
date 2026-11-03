#include "types.h"
#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u8 pad[0x70];
    VecFx32 pos;
    u8 pad7c[0xb90 - 0x7c];
    VecFx32 target;
    s32 rate;
} Mgr021b3d78;

extern "C" {

#define FXM(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov000_021b3d78(Mgr021b3d78 *self) {
    FieldState *p = gSceneCmd;
    s32 dist;
    s32 v;
    s32 half;
    if (p->cam.unk_d9 != 0) {
        return;
    }
    p->cam.unk_bc.x = self->pos.x;
    p->cam.unk_bc.y = self->pos.y;
    p->cam.unk_bc.z = self->pos.z;
    if (self->rate == 0) {
        return;
    }
    {
        VecFx32 d;
        d.x = FX_Mul(self->target.x - self->pos.x, self->rate);
        d.y = FX_Mul(self->target.y - self->pos.y, self->rate);
        d.z = FX_Mul(self->target.z - self->pos.z, self->rate);
        p->cam.unk_dc = d;
    }
    p->cam.unk_da_0 = 1;
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
        p->cam.unk_f4 = v;
        p->cam.unk_da_2 = 2;
    }
    self->rate = 0;
}

}
