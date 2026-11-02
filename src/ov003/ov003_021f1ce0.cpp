#include "types.h"
#include "ov003/Prop.h"

extern "C" {

typedef struct {
    s32 box[6];
} Ov003FlickerBox;

typedef struct {
    s16 angle;
    u8 unk_02[2];
    u8 kind;
    u8 count;
    u16 duration;
    s16 radius;
    s16 speed;
    s16 unk_0c;
    s16 rate;
    VecFx32 offset[2];
    Ov003FlickerBox *box;
} Ov003FlickerEntry;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    VecFx32 ofs;
    s32 unk_30;
} Ov003FlickerHit;

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 1;
    u16 rotate : 1;
} Ov003FlickerInfo;

extern const Ov003FlickerEntry data_ov003_021f7560[];

extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern u32 Rand_UpTo(u32 max);
extern void Model0218fe1c_SetAnimByIndex(void *model, s32 a, s32 b, s32 c);
extern void Model0218fe1c_ClearLoop(void *model);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 v);
extern Ov003FlickerInfo *Tbl_FindEntry_0206fef8(u16 id);
extern void *Heap_Alloc(u32 size);
extern ActorSub40 *History_Init(void *p);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern const s16 FX_SinCosTable_[];
extern void HitMesh_SetMtx(void *obj, MtxFx43 *m);
extern s32 func_ov000_0219b808(u16 id, void *pos, Ov003FlickerHit *entry, u16 *ids, s32 max);

#define OV003FL_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003FL_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void Ov003PropFlicker_Randomize(Ov003PropFlicker *self);

void Ov003PropFlicker_SelectState(Ov003PropFlicker *self) {
}

void Ov003PropFlicker_Update(Ov003PropFlicker *self) {
}

void Ov003ActVt_021fa4f0_Start(Ov003PropFlicker *self) {
    Ov000ActVt_021cc7cc_Start(self);
    Ov003PropFlicker_Randomize(self);
    self->model->boxTest = 0;
    self->timer = 0;
}

void Ov003ActVt_021fa4f0_RunState(Ov003PropFlicker *self) {
    s32 period;
    u16 t;
    if (!Model0218fe1c_IsAnimDone(self->model)) {
        return;
    }
    period = self->unk_1e;
    if (period < 0) {
        period = 0;
    }
    t = self->timer;
    self->timer = t + 1;
    if (t > (u16)period) {
        self->timer = Rand_UpTo(0x3c);
        Ov003PropFlicker_Randomize(self);
    }
}

void Ov003PropFlicker_Randomize(Ov003PropFlicker *self) {
    s32 r = self->unk_18;
    u8 a = r & 0xff;
    u8 b = (r >> 8) & 0xff;
    s16 lo;
    s16 hi;
    if (a != b) {
        if (a < b) {
            a = a + (u8)Rand_UpTo(b - a);
        } else {
            a = b + Rand_UpTo(a - b);
        }
    }
    Model0218fe1c_SetAnimByIndex(self->model, a, 0x1000, 1);
    Model0218fe1c_ClearLoop(self->model);
    lo = self->unk_1a;
    if (lo < 0) {
        lo = 0;
    } else if (lo > 0x4000) {
        lo = 0x4000;
    }
    hi = self->unk_1c;
    if (hi < 0) {
        hi = 0;
    } else if (hi > 0x4000) {
        hi = 0x4000;
    }
    if (lo != hi) {
        if (lo < hi) {
            lo = lo + (s16)Rand_UpTo(hi - lo);
        } else {
            lo = hi + Rand_UpTo(lo - hi);
        }
    }
    Model0218fe1c_SetAnimSpeed(self->model, lo);
}

void Ov003ActVt_021fa498_Start(Ov003PropFlicker *self) {
    const Ov003FlickerEntry *e;
    ActorSub40 *p;
    Ov000ActVt_021cc7cc_Start(self);
    e = &data_ov003_021f7560[self->unk_18];
    if (Tbl_FindEntry_0206fef8(self->kind)->rotate) {
        Model0218fe1c_SetAnimSpeed(self->model, e->angle);
        if (e->kind != 1) {
            Model0218fe1c_ClearLoop(self->model);
        }
    }
    p = (ActorSub40 *)Heap_Alloc(0x14);
    if (p != NULL) {
        p = History_Init(p);
    }
    self->fsm = p;
    self->fsm->timer = Rand_UpTo(0x28);
    self->timer = 1;
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    VEC_Add(&self->pos, &e->offset[0], &self->pos);
    self->unk_b2 = e->unk_0c;
}

static inline void Ov003Fl_Scale(VecFx32 *v, s32 k) {
    v->x = (s32)(((s64)v->x * k + 0x800) >> 12);
    v->y = (s32)(((s64)v->y * k + 0x800) >> 12);
    v->z = (s32)(((s64)v->z * k + 0x800) >> 12);
}

void Ov003ActVt_021fa498_RunState(Ov003PropFlicker *self) {
    VecFx32 tgt;
    Ov003FlickerHit hit;
    const Ov003FlickerEntry *e = &data_ov003_021f7560[self->unk_18];
    ActorSub40 *task;
    void *obj;
    Ov003FlickerBox *box;
    VEC_Add(&self->unk_84, &e->offset[self->timer], &tgt);
    task = self->fsm;
    switch (task->st) {
    case 0:
        if (task->timer != 0) {
            task->timer--;
        }
        if (task->timer == 0) {
            if (Hit_DiffInSphere(&self->pos, &tgt, e->radius + self->radius)) {
                self->fsm->st = 10;
            }
            self->vel.x = tgt.x - self->pos.x;
            self->vel.y = tgt.y - self->pos.y;
            self->vel.z = tgt.z - self->pos.z;
            VEC_Normalize(&self->vel, &self->vel);
            self->unk_b2 += (s16)(((s64)e->rate * (e->unk_0c - self->unk_b2) + 0x800) >> 12);
            Ov003Fl_Scale(&self->vel, self->unk_b2);
        }
        break;
    case 10: {
        s32 spd;
        self->vel.x = tgt.x - self->pos.x;
        self->vel.y = tgt.y - self->pos.y;
        self->vel.z = tgt.z - self->pos.z;
        spd = e->speed;
        self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
        self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
        self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        task->timer++;
        if (task->timer > e->duration) {
            self->fsm->timer = 0;
            self->fsm->st = 0;
            self->timer++;
            if (self->timer >= e->count) {
                self->timer = 0;
            }
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0;
            if (e->kind == 2) {
                Model0218fe1c_SetAnimByIndex(self->model, 0, 0x1000, 1);
            } else if (e->kind == 3) {
                Model0218fe1c_SetAnimByIndex(self->model, self->timer & 1, 0x1000, 1);
            }
        }
        break;
    }
    }
    VEC_Add(&self->pos, &self->vel, &self->pos);
    obj = self->hitMesh;
    if (obj != NULL) {
        MtxFx43 t;
        MtxFx43 m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003FL_SIN(rz), OV003FL_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003FL_SIN(ry), OV003FL_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003FL_SIN(ry), OV003FL_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003FL_SIN(rx), OV003FL_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003FL_SIN(rx), OV003FL_COS(rx));
                set = TRUE;
            }
        }
        m._30 = self->pos.x;
        m._31 = self->pos.y;
        m._32 = self->pos.z;
        HitMesh_SetMtx(obj, &m);
    }
    box = e->box;
    if (box != NULL) {
        hit.box[0] = box->box[0];
        hit.box[1] = box->box[1];
        hit.box[2] = box->box[2];
        hit.box[3] = box->box[3];
        hit.box[4] = box->box[4];
        hit.box[5] = box->box[5];
        hit.rot[0] = self->rot_x;
        hit.rot[1] = self->rot_y;
        hit.rot[2] = self->rot_z;
        hit.kind = 0x32;
        hit.unk_20 = 0x20040000;
        hit.ofs.x = self->vel.x;
        hit.ofs.y = self->vel.y;
        hit.ofs.z = self->vel.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->id, &self->pos, &hit, NULL, 0);
    }
}

} // extern "C"
