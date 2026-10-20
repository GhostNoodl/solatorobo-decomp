#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 4;
    u16 visible : 1;
} Ov003FlickerModel;

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
    Ov003Vec offset[2];
    Ov003FlickerBox *box;
} Ov003FlickerEntry;

typedef struct {
    s32 m[9];
    Ov003Vec t;
} Ov003FlickerMtx;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    Ov003Vec ofs;
    s32 unk_30;
} Ov003FlickerHit;

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 1;
    u16 rotate : 1;
} Ov003FlickerInfo;

typedef struct {
    u16 state;
    u16 timer;
} Ov003FlickerTask;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 id;
    u8 unk_10[8];
    s16 range;
    s16 lo;
    s16 hi;
    s16 period;
    u8 unk_20[0x18];
    Ov003FlickerModel *model;
    u8 unk_3c[4];
    Ov003FlickerTask *task;
    u8 unk_44[0x14];
    void *obj;
    u8 unk_5c[8];
    s32 unk_64;
    u8 unk_68[8];
    Ov003Vec pos;
    u16 rot[3];
    u8 unk_82[2];
    Ov003Vec origin;
    u8 unk_90[0xc];
    Ov003Vec vel;
    u8 unk_a8[8];
    u16 timer;
    s16 unk_b2;
} Ov003Flicker;

extern const Ov003FlickerEntry data_ov003_021f7560[];

extern void func_ov000_021b4c60(void *self);
extern BOOL func_ov000_02191120(void *model);
extern s32 func_02040498(s32 max);
extern void func_ov000_02190e98(void *model, s32 a, s32 b, s32 c);
extern void func_ov000_02191618(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern Ov003FlickerInfo *func_0206fef8(u16 id);
extern void *func_0203dd9c(u32 size);
extern void *func_ov000_02198328(void *p);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void VEC_Normalize(const Ov003Vec *a, Ov003Vec *out);
extern BOOL func_01ffc198(Ov003Vec *a, Ov003Vec *b, s32 r);
extern const s16 FX_SinCosTable_[];
extern void MTX_Identity43_(Ov003FlickerMtx *m);
extern void MTX_RotX43_(Ov003FlickerMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003FlickerMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003FlickerMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003FlickerMtx *a, Ov003FlickerMtx *b, Ov003FlickerMtx *out);
extern void func_0203f9dc(void *obj, Ov003FlickerMtx *m);
extern s32 func_ov000_0219b808(u16 id, void *pos, Ov003FlickerHit *entry, u16 *ids, s32 max);

#define OV003FL_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003FL_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021f1d6c(Ov003Flicker *self);

void func_ov003_021f1ce0(Ov003Flicker *self) {
}

void func_ov003_021f1ce4(Ov003Flicker *self) {
}

void func_ov003_021f1ce8(Ov003Flicker *self) {
    func_ov000_021b4c60(self);
    func_ov003_021f1d6c(self);
    self->model->visible = 0;
    self->timer = 0;
}

void func_ov003_021f1d18(Ov003Flicker *self) {
    s32 period;
    u16 t;
    if (!func_ov000_02191120(self->model)) {
        return;
    }
    period = self->period;
    if (period < 0) {
        period = 0;
    }
    t = self->timer;
    self->timer = t + 1;
    if (t > (u16)period) {
        self->timer = func_02040498(0x3c);
        func_ov003_021f1d6c(self);
    }
}

void func_ov003_021f1d6c(Ov003Flicker *self) {
    s32 r = self->range;
    u8 a = r & 0xff;
    u8 b = (r >> 8) & 0xff;
    s16 lo;
    s16 hi;
    if (a != b) {
        if (a < b) {
            a = a + (u8)func_02040498(b - a);
        } else {
            a = b + func_02040498(a - b);
        }
    }
    func_ov000_02190e98(self->model, a, 0x1000, 1);
    func_ov000_02191618(self->model);
    lo = self->lo;
    if (lo < 0) {
        lo = 0;
    } else if (lo > 0x4000) {
        lo = 0x4000;
    }
    hi = self->hi;
    if (hi < 0) {
        hi = 0;
    } else if (hi > 0x4000) {
        hi = 0x4000;
    }
    if (lo != hi) {
        if (lo < hi) {
            lo = lo + (s16)func_02040498(hi - lo);
        } else {
            lo = hi + func_02040498(lo - hi);
        }
    }
    func_ov000_021911c8(self->model, lo);
}

void func_ov003_021f1e44(Ov003Flicker *self) {
    const Ov003FlickerEntry *e;
    void *p;
    func_ov000_021b4c60(self);
    e = &data_ov003_021f7560[self->range];
    if (func_0206fef8(self->id)->rotate) {
        func_ov000_021911c8(self->model, e->angle);
        if (e->kind != 1) {
            func_ov000_02191618(self->model);
        }
    }
    p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_ov000_02198328(p);
    }
    self->task = p;
    self->task->timer = func_02040498(0x28);
    self->timer = 1;
    self->origin.x = self->pos.x;
    self->origin.y = self->pos.y;
    self->origin.z = self->pos.z;
    VEC_Add(&self->pos, &e->offset[0], &self->pos);
    self->unk_b2 = e->unk_0c;
}

static inline void Ov003Fl_Scale(Ov003Vec *v, s32 k) {
    v->x = (s32)(((s64)v->x * k + 0x800) >> 12);
    v->y = (s32)(((s64)v->y * k + 0x800) >> 12);
    v->z = (s32)(((s64)v->z * k + 0x800) >> 12);
}

void func_ov003_021f1f00(Ov003Flicker *self) {
    Ov003Vec tgt;
    Ov003FlickerHit hit;
    const Ov003FlickerEntry *e = &data_ov003_021f7560[self->range];
    Ov003FlickerTask *task;
    void *obj;
    Ov003FlickerBox *box;
    VEC_Add(&self->origin, &e->offset[self->timer], &tgt);
    task = self->task;
    switch (task->state) {
    case 0:
        if (task->timer != 0) {
            task->timer--;
        }
        if (task->timer == 0) {
            if (func_01ffc198(&self->pos, &tgt, e->radius + self->unk_64)) {
                self->task->state = 10;
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
            self->task->timer = 0;
            self->task->state = 0;
            self->timer++;
            if (self->timer >= e->count) {
                self->timer = 0;
            }
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0;
            if (e->kind == 2) {
                func_ov000_02190e98(self->model, 0, 0x1000, 1);
            } else if (e->kind == 3) {
                func_ov000_02190e98(self->model, self->timer & 1, 0x1000, 1);
            }
        }
        break;
    }
    }
    VEC_Add(&self->pos, &self->vel, &self->pos);
    obj = self->obj;
    if (obj != NULL) {
        Ov003FlickerMtx t;
        Ov003FlickerMtx m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        rz = self->rot[2];
        ry = self->rot[1];
        rx = self->rot[0];
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
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        func_0203f9dc(obj, &m);
    }
    box = e->box;
    if (box != NULL) {
        hit.box[0] = box->box[0];
        hit.box[1] = box->box[1];
        hit.box[2] = box->box[2];
        hit.box[3] = box->box[3];
        hit.box[4] = box->box[4];
        hit.box[5] = box->box[5];
        hit.rot[0] = self->rot[0];
        hit.rot[1] = self->rot[1];
        hit.rot[2] = self->rot[2];
        hit.kind = 0x32;
        hit.unk_20 = 0x20040000;
        hit.ofs.x = self->vel.x;
        hit.ofs.y = self->vel.y;
        hit.ofs.z = self->vel.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->unk_0c, &self->pos, &hit, NULL, 0);
    }
}
