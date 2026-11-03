#include "nitro/fx.h"
#include "ov000/ActorMgr.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"


extern "C" {
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Vec_RotateY(VecFx32 *out, const VecFx32 *in, u16 angle);

static inline void VecSet_021b4130(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline Actor *FindActor_021b4130(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void func_ov000_021b4130(Robo021ca458 *self, BOOL flag) {
    VecFx32 v;
    MtxFx43 m;
    Actor *a;
    ActorSub4c *o;
    a = FindActor_021b4130(self->unk_b1c);
    if (a == NULL) {
        return;
    }
    o = a->targetObj;
    switch (self->unk_b24_7) {
    default:
        MTX_Identity43_(&m);
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa50, &m);
            VEC_Add(&self->unk_a74, &self->unk_aa4, &v);
            v.x = FX_Mul(v.x, 0x800);
            v.y = FX_Mul(v.y, 0x800);
            v.z = FX_Mul(v.z, 0x800);
            if (o != NULL) {
                o->unk_18_0 = 0;
            }
            if (self->unk_b22_3) {
                v.y -= (FX_SinCosTable_[((u16)(gActorMgr->frame << 9) >> 4) * 2] + 0x1400) >> 2;
                v.x += FX_SinCosTable_[(self->rot_y >> 4) * 2] >> 1;
                v.z += FX_SinCosTable_[(self->rot_y >> 4) * 2 + 1] >> 1;
            } else if (self->unk_b2c_1) {
                VecFx32 t;
                t.x = a->radius >> 1;
                t.y = 0;
                t.z = 0;
                MTX_MultVec33(&t, (MtxFx33 *)&m, &t);
                VEC_Add(&v, &t, &v);
                v.y -= 0x1800;
                if (o != NULL) {
                    o->unk_18_0 = 1;
                }
            } else if (self->unk_b2c_0) {
                u16 r = self->rot_y;
                s32 sn = FX_SinCosTable_[(r >> 4) * 2];
                s32 cs = FX_SinCosTable_[(r >> 4) * 2 + 1];
                s32 d = a->radius;
                sn = FX_Mul(d, sn);
                cs = FX_Mul(d, cs);
                v.x += sn;
                v.z += cs;
                v.y -= 0x800;
            } else if (self->unk_b2c_2) {
                VecFx32 t;
                t.x = a->radius;
                t.y = -0xc00;
                t.z = 0;
                MTX_MultVec33(&t, (MtxFx33 *)&m, &t);
                VEC_Add(&v, &t, &v);
                if (o != NULL) {
                    o->unk_18_0 = 1;
                }
            }
        } else {
            VecSet_021b4130(&v, self->unk_75c.x, self->unk_75c.y + self->height, self->unk_75c.z);
        }
        m.m[3][0] = v.x;
        m.m[3][1] = v.y;
        m.m[3][2] = v.z;
        MI_Copy48B(&m, (u8 *)o + 0x20);
        return;
    case 0:
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa50, (u8 *)o + 0x20);
            return;
        }
        VecSet_021b4130(&v, -0xccd, self->height >> 1, 0xccd);
        Vec_RotateY(&v, &v, self->rot_y);
        VEC_Add(&v, &self->unk_75c, &v);
        o->dest = v;
        return;
    case 1:
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa80, (u8 *)o + 0x20);
            return;
        }
        VecSet_021b4130(&v, 0xccd, self->height >> 1, 0xccd);
        Vec_RotateY(&v, &v, self->rot_y);
        VEC_Add(&v, &self->unk_75c, &v);
        o->dest = v;
        return;
    }
}

}
