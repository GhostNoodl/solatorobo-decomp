#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003SlVec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003SlRot;

class Ov003SlFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void SetScale(Ov003SlVec *s);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(Ov003SlVec *p);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003SlRot *r);

    u8 unk_04[0x20];
    void *handle;
    u8 active;
    u8 unk_29[0x2f];
    Ov003SlVec pos;
    u8 unk_64[0x18];
    s32 alpha;
    u8 unk_80[0x48];
    s32 unk_c8;
};

typedef struct {
    void *mdl;
    s16 id;
    u8 alpha;
    u8 unk_07;
    s16 maxX;
    s16 maxZ;
    s16 incX;
    s16 incZ;
    s16 decX;
    s16 decZ;
} Ov003SlEnt;

typedef struct {
    void *arc;
    u8 unk_04[0x14];
    Ov003SlEnt ents[2];
} Ov003SlDef;

typedef struct {
    u8 unk_00[0x70];
    Ov003SlVec pos;
    Ov003SlRot rot;
    u8 unk_82[2];
    Ov003SlVec offset;
    u8 unk_90[0x40];
    Ov003SlDef *def;
    void *handles[2];
    Ov003SlVec vecs[2];
} Ov003Slot;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern void *data_0214a420;
extern Ov003SlFx *func_02066774(void *arc, void *mdl, s32 c, Ov003SlVec *pos);
extern Ov003SlFx *func_02065f88(s32 id, Ov003SlVec *pos);
extern Ov003SlFx *func_020657b0(void *mgr, void *handle);
extern void func_01ffc9fc(Ov003SlVec *out, Ov003SlVec *in, u16 ang);
extern s32 FX_Div(s32 a, s32 b);
extern void VEC_Add(const Ov003SlVec *a, const Ov003SlVec *b, Ov003SlVec *out);

static inline void Ov003Sl_RotX(Ov003SlVec *out, const Ov003SlVec *in, u16 ang) {
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

static inline Ov003SlFx *Ov003Sl_GetFx(Ov003Slot *self, s32 i) {
    return func_020657b0(data_0214a420, self->handles[i]);
}

void func_ov003_021dc3fc(Ov003Slot *self, s32 i, s32 mode) {
    Ov003SlFx *fx;
    Ov003SlDef *def;
    Ov003SlVec a;
    Ov003SlVec b;
    s32 y;
    s32 z;
    Ov003SlFx *nfx;
    u32 al;
    Ov003SlEnt *ent;
    def = self->def;
    ent = &def->ents[i];
    if (ent == NULL) {
        return;
    }
    if (self->handles[i] == NULL) {
        if (def->arc != NULL && ent->mdl != NULL) {
            nfx = func_02066774(def->arc, ent->mdl, 0, &self->pos);
        } else if (ent->id != -1) {
            nfx = func_02065f88(ent->id, &self->pos);
        }
        if (nfx != NULL) {
            a.x = self->offset.x;
            a.y = self->offset.y;
            a.z = self->offset.z;
            Ov003Sl_RotX(&a, &a, self->rot.x);
            func_01ffc9fc(&a, &a, self->rot.y);
            nfx->SetPos(&a);
            al = ent->alpha;
            if (al > 0x1f) {
                al = 0x1f;
            }
            nfx->alpha = FX_Div((u8)al << 12, 0x1f000);
            nfx->unk_c8 = -1;
            nfx->active = 0;
            self->handles[i] = nfx->handle;
        }
    }
    fx = Ov003Sl_GetFx(self, i);
    if (fx == NULL) {
        return;
    }
    y = self->offset.y;
    z = self->offset.z;
    b.x = self->offset.x;
    b.y = y;
    b.z = z;
    Ov003Sl_RotX(&b, &b, self->rot.x);
    func_01ffc9fc(&b, &b, self->rot.y);
    VEC_Add(&b, &self->pos, &b);
    a.x = fx->pos.x;
    a.y = fx->pos.y;
    a.z = fx->pos.z;
    b.x = b.x - a.x;
    b.y = b.y - a.y;
    b.z = b.z - a.z;
    fx->SetPos(&b);
    fx->SetRot(&self->rot);
    switch (mode) {
    case 0:
        if (self->vecs[i].x < ent->maxX << 4) {
            self->vecs[i].x += ent->incX << 4;
            if (self->vecs[i].x > ent->maxX << 4) {
                self->vecs[i].x = ent->maxX << 4;
            }
            self->vecs[i].y = self->vecs[i].x;
        }
        if (self->vecs[i].z < ent->maxZ << 4) {
            self->vecs[i].z += ent->incZ << 4;
            if (self->vecs[i].z > ent->maxZ << 4) {
                self->vecs[i].z = ent->maxZ << 4;
            }
        }
        break;
    case 1:
        if (self->vecs[i].x > 0) {
            self->vecs[i].x -= ent->decX << 4;
            if (self->vecs[i].x < 0) {
                self->vecs[i].x = 0;
            }
            self->vecs[i].y = self->vecs[i].x;
        }
        if (self->vecs[i].z > 0) {
            self->vecs[i].z -= ent->decZ << 4;
            if (self->vecs[i].z < 0) {
                self->vecs[i].z = 0;
            }
        }
        break;
    }
    fx->SetScale(&self->vecs[i]);
}

}
