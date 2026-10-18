#include "ov006/ov006.h"
#include <nitro/fx.h>

typedef struct ov006_Proj021dccc8 {
    u8 unk0[8];
    VecFx32 unk8;
    VecFx32 unk14;
} ov006_Proj021dccc8;

static inline void ov006_SetVec021dccc8(VecFx32 *v, fx32 x, fx32 y, fx32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

extern "C" void func_ov006_021dccc8(ov006_Proj021dccc8 *out, const VecFx32 *pos, const MtxFx43 *cam, const MtxFx44 *proj, u8 flag) {
    VecFx32 v;
    MtxFx43 m;
    fx32 w;

    MTX_MultVec43(pos, cam, &v);
    w = FX_Mul(v.z, -FX32_ONE);
    MTX_Copy44To43(proj, &m);
    MTX_MultVec43(&v, &m, &v);
    v.x = FX_Div(v.x, w);
    v.y = FX_Div(v.y, w);
    v.z = FX_Div(v.z, w);
    ov006_SetVec021dccc8(&out->unk8, (FX_Whole(FX_Mul(v.x, 0x80000) + 0x80000) - 0x80) << 12, (FX_Whole(0x60000 - FX_Mul(v.y, 0x60000)) - 0x60) << 12, 0);
    if (flag) {
        out->unk14.x = out->unk8.x;
        out->unk14.y = out->unk8.y;
        out->unk14.z = out->unk8.z;
    }
}
