#include "types.h"
#include "ov003/Shot.h"

// The effect object the effect functions return (Main EffectObj; only the members used here).
class Ov003SlFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void SetScale(VecFx32 *s);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void AddPos(VecFx32 *p);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(ActorRot *r);

    u8 unk_04[0x20];
    void *id; // handle
    u8 active;
    u8 unk_29[0x2f];
    VecFx32 pos;
    u8 unk_64[0x18];
    s32 alpha;
    u8 unk_80[0x48];
    s32 unk_c8;
};

extern "C" {

extern void *data_0214a420;
extern Ov003SlFx *Effect3D_Create(void *arc, void *mdl, s32 c, VecFx32 *pos);
extern Ov003SlFx *func_02065f88(s32 id, VecFx32 *pos);
extern Ov003SlFx *func_020657b0(void *mgr, void *handle);
extern void func_01ffc9fc(VecFx32 *out, VecFx32 *in, u16 ang);

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

static inline Ov003SlFx *Ov003Sl_GetFx(Ov003Beam *self, s32 i) {
    return func_020657b0(data_0214a420, self->layers[i]);
}

void func_ov003_021dc3fc(Ov003Beam *self, s32 i, s32 mode) {
    Ov003SlFx *fx;
    Ov003BeamDef *def;
    VecFx32 a;
    VecFx32 b;
    s32 y;
    s32 z;
    Ov003SlFx *nfx;
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
            nfx = func_02065f88(ent->fx, &self->pos);
        }
        if (nfx != NULL) {
            a.x = self->unk_84.x;
            a.y = self->unk_84.y;
            a.z = self->unk_84.z;
            Ov003Sl_RotX(&a, &a, self->rot_x);
            func_01ffc9fc(&a, &a, self->rot_y);
            nfx->AddPos(&a);
            al = ent->alpha;
            if (al > 0x1f) {
                al = 0x1f;
            }
            nfx->alpha = FX_Div((u8)al << 12, 0x1f000);
            nfx->unk_c8 = -1;
            nfx->active = 0;
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
    func_01ffc9fc(&b, &b, self->rot_y);
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
