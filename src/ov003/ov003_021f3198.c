#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec pos;
    u8 unk_84[0x24];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u8 unk_b4[0xa];
    u8 alpha;
    u8 unk_bf[3];
    u16 visible : 1;
    u16 unk_c2_1 : 2;
    u16 flip : 1;
    u16 shadow : 1;
} Ov003BlinkModel;

typedef struct {
    u8 unk_00[0x10];
    s16 scale;
    u16 unk_12_0 : 11;
    u16 flip : 1;
} Ov003BlinkInfo;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    u16 pattern;
    u16 angleA;
    u16 angleB;
    s16 unk_1e;
    u8 unk_20[0x18];
    Ov003BlinkModel *model;
    u8 unk_3c[0x34];
    Ov003Vec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[0x30];
    union {
        struct {
            Ov003Vec offset;
            s32 phase;
        } drift;
        struct {
            s32 radius;
            u16 phase;
        } blink;
    } u;
} Ov003Blink;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec pos;
} Ov003BlinkTarget;

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *func_ov000_0219bf90(void);
extern BOOL func_ov000_02191120(void *model);
extern char data_ov003_021fa2d2[];

extern void func_ov000_021b4c60(void *self);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern s32 func_02040528(s32 max);
extern void func_02012fb8(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern void func_02012be8(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern Ov003BlinkInfo *func_0206fef8(u16 id);
extern BOOL func_ov000_0218cea4(void *self);
extern void func_ov000_021903b4(void *model);

static inline s32 Ov003_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov003_021f3198(Ov003Blink *self) {
    u16 v = self->pattern >> ((3 - self->u.blink.phase) * 4);
    u32 n = v & 0xf;
    u16 a;
    if (n == 0) {
        self->model->visible = 0;
        return;
    }
    self->model->visible = 1;
    if (n >= 2) {
        func_ov000_02190cb0(self->model, data_ov003_021f738c[self->u.blink.phase], 0x19a, 0);
        if (n >= 3) {
            func_ov000_021915a0(self->model);
        }
    }
    a = 0x40;
    switch (self->u.blink.phase) {
    case 0:
        a = self->angleA >> 8;
        break;
    case 1:
        a = self->angleA;
        break;
    case 2:
        a = self->angleB >> 8;
        break;
    case 3:
        a = self->angleB;
        break;
    }
    func_ov000_021911c8(self->model, (s16)((u8)a << 6));
}

void func_ov003_021f3280(Ov003Blink *self) {
    func_ov000_021b4c60(self);
    self->u.drift.offset.x = 0;
    self->u.drift.offset.y = 0;
    self->u.drift.offset.z = 0;
    self->u.drift.phase = 0;
    func_ov000_02190cb0(self->model, data_ov003_021fa2d2, 0x1000, 0);
    func_ov000_021915a0(self->model);
}

void func_ov003_021f32c0(Ov003Blink *self) {
    Ov003Vec v;
    s32 z;
    self->u.drift.phase += func_02040528(0xe1) + 0x9a;
    if (self->u.drift.phase > 0x1000) {
        self->u.drift.phase = 0;
    }
    z = func_02040528(0x400);
    v.x = func_02040528(0x400) - self->u.drift.offset.x;
    v.y = -self->u.drift.offset.y;
    v.z = z - self->u.drift.offset.z;
    func_02012fb8(0x400, &v, &self->u.drift.offset, &self->u.drift.offset);
}

BOOL func_ov003_021f3348(Ov003Blink *self) {
    s32 s = func_0206fef8(self->id)->scale;
    BOOL r;
    Ov003Vec v;
    Ov003BlinkModel *model;
    model = self->model;
    model->scaleX = s;
    model->scaleY = s;
    model->scaleZ = s;
    self->model->alpha = 0x1f;
    model = self->model;
    model->pos.x = self->pos.x;
    model->pos.y = self->pos.y;
    model->pos.z = self->pos.z;
    r = func_ov000_0218cea4(self);
    if (r) {
        s32 d = s + Ov003_FxMul(self->u.drift.phase, 0x59a);
        model = self->model;
        model->scaleX = d + 0x333;
        model->scaleY = d;
        model->scaleZ = d + 0x333;
        self->model->alpha = 0x12 - (self->u.drift.phase >> 8);
        func_02012be8(&self->u.drift.offset, &self->pos, &v);
        model = self->model;
        model->pos.x = v.x;
        model->pos.y = v.y;
        model->pos.z = v.z;
        func_ov000_021903b4(self->model);
    }
    return r;
}

void func_ov003_021f3440(Ov003Blink *self) {
    s16 rot;
    func_ov000_021b4c60(self);
    if (func_0206fef8(self->id)->flip) {
        u16 a = self->rotY;
        if (a > 0x4000 && a < 0xc000) {
            self->model->flip = 1;
        }
    }
    rot = 0x1c3;
    rot += (s16)func_02040528(0xa4);
    func_ov000_021911c8(self->model, rot);
}
