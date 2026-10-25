#include "Main/Effect/Effect.h"

extern "C" {

void func_02064b40(Effect3D *e) {
    e->unk_14 = 1;
    e->unk_c4 = 0;
}

static inline void Effect_SetProjection(const void *mtx) {
    MIi_CpuCopyFast(mtx, data_02092800, 0x40);
    NNS_G3dGlb.flags &= ~0x50;
}


// Scales all three components; the caller then overwrites z, which keeps
// the target's store order for y and z.
static inline void Effect_VecScale(EffectVec *d, const EffectVec *s, s32 k) {
    d->x = Effect_FxMul(s->x, k);
    d->y = Effect_FxMul(s->y, k);
    d->z = Effect_FxMul(s->z, k);
}
void func_02064b54(Effect3D *e) {
    u8 proj[0x40];
    u8 cam[0x30];
    EffectVec trans;
    EffectVec scale;
    u8 ortho[0x40];
    u8 rot[0x24];
    u8 *glbProj = data_02092800;
    u8 *glbCam = data_02092844;
    MI_Copy64B(glbProj, proj);
    MI_Copy48B(glbCam, cam);
    MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, ortho);
    Effect_SetProjection(ortho);
    MTX_Identity43_(glbCam);
    *(s32 *)(glbCam + 0x2c) = 0x200;
    trans.x = Effect_FxMul(e->offset.x, e->scale.x);
    trans.y = Effect_FxMul(e->offset.y, e->scale.y);
    trans.z = Effect_FxMul(e->offset.z, e->scale.z);
    if (e->posPtr != NULL) {
        VEC_Add(&trans, e->posPtr, &trans);
    } else {
        VEC_Add(&trans, &e->pos, &trans);
    }
    NNS_G3dGlbSetBaseTrans(&trans);
    MTX_Identity33_(rot);
    MI_Copy36B(rot, data_020928b4);
    NNS_G3dGlb.flags &= ~0xa4;
    Effect_VecScale(&scale, &e->scale, 0x64000);
    scale.z = 0x1000;
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbFlushP();
    NNS_G3dDraw(&e->renderObj);
    Effect_SetProjection(proj);
    MI_Copy48B(cam, glbCam);
}

}
