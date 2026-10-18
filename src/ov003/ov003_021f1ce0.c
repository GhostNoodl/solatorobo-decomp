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
    s16 angle;
    u8 unk_02[2];
    u8 kind;
    u8 unk_05[7];
    s16 unk_0c;
    u8 unk_0e[2];
    Ov003Vec offset;
    u8 unk_1c[0x10];
} Ov003FlickerEntry;

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 1;
    u16 rotate : 1;
} Ov003FlickerInfo;

typedef struct {
    u8 unk_00[2];
    u16 timer;
} Ov003FlickerTask;

typedef struct {
    u8 unk_00[0xe];
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
    u8 unk_44[0x2c];
    Ov003Vec pos;
    u8 unk_7c[8];
    Ov003Vec origin;
    u8 unk_90[0x20];
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
extern void func_02012be8(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);

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
    func_02012be8(&self->pos, &e->offset, &self->pos);
    self->unk_b2 = e->unk_0c;
}
