#include "types.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern void Vec_RotateY(VecFx32 *out, VecFx32 *in, u16 ang);

static inline void Ov003Sl_RotX(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline EffectObj *Ov003Sl_GetFx(Ov003Beam *self, s32 i) {
    return Effect_Find_020657b0(gEffectMgr, self->layers[i]);
}

void Ov003Beam_UpdateLayer(Ov003Beam *self, s32 i, s32 mode) {
    EffectObj *fx;
    Ov003BeamDef *def;
    VecFx32 a;
    VecFx32 b;
    s32 y;
    s32 z;
    EffectObj *nfx;
    u32 al;
    Ov003BeamLayer *ent;
    def = self->def;
    ent = &def->layers[i];
    if (ent == NULL) {
        return;
    }
    if (self->layers[i] == NULL) {
        if (def->arc != NULL && ent->mdl != NULL) {
            nfx = Effect3D_Create(def->arc, ent->mdl, 0, &self->pos);
        } else if (ent->fx != -1) {
            nfx = Effect_SpawnId(ent->fx, &self->pos);
        }
        if (nfx != NULL) {
            a.x = self->unk_84.x;
            a.y = self->unk_84.y;
            a.z = self->unk_84.z;
            Ov003Sl_RotX(&a, &a, self->rot_x);
            Vec_RotateY(&a, &a, self->rot_y);
            nfx->AddPos(&a);
            al = ent->alpha;
            if (al > 0x1f) {
                al = 0x1f;
            }
            nfx->alpha = FX_Div((u8)al << 12, 0x1f000);
            nfx->loopCount = -1;
            nfx->unk_28 = 0;
            self->layers[i] = nfx->id;
        }
    }
    fx = Ov003Sl_GetFx(self, i);
    if (fx == NULL) {
        return;
    }
    y = self->unk_84.y;
    z = self->unk_84.z;
    b.x = self->unk_84.x;
    b.y = y;
    b.z = z;
    Ov003Sl_RotX(&b, &b, self->rot_x);
    Vec_RotateY(&b, &b, self->rot_y);
    VEC_Add(&b, &self->pos, &b);
    a.x = fx->pos.x;
    a.y = fx->pos.y;
    a.z = fx->pos.z;
    b.x = b.x - a.x;
    b.y = b.y - a.y;
    b.z = b.z - a.z;
    fx->AddPos(&b);
    fx->SetRot(&self->rot);
    switch (mode) {
    case 0:
        if (self->scales[i].x < ent->maxX << 4) {
            self->scales[i].x += ent->incX << 4;
            if (self->scales[i].x > ent->maxX << 4) {
                self->scales[i].x = ent->maxX << 4;
            }
            self->scales[i].y = self->scales[i].x;
        }
        if (self->scales[i].z < ent->maxZ << 4) {
            self->scales[i].z += ent->incZ << 4;
            if (self->scales[i].z > ent->maxZ << 4) {
                self->scales[i].z = ent->maxZ << 4;
            }
        }
        break;
    case 1:
        if (self->scales[i].x > 0) {
            self->scales[i].x -= ent->decX << 4;
            if (self->scales[i].x < 0) {
                self->scales[i].x = 0;
            }
            self->scales[i].y = self->scales[i].x;
        }
        if (self->scales[i].z > 0) {
            self->scales[i].z -= ent->decZ << 4;
            if (self->scales[i].z < 0) {
                self->scales[i].z = 0;
            }
        }
        break;
    }
    fx->SetScale(&self->scales[i]);
}

}
