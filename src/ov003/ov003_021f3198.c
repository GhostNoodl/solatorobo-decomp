#include "types.h"
#include "nitro/fx.h"
#include "ov003/Blink.h"

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *func_ov000_0219bf90(void);
extern BOOL func_ov000_02191120(void *model);
extern char data_ov003_021fa2d2[];

extern void Ov000ActVt_021cc7cc_Start(void *self);
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern s32 Rand_PlusMinus(s32 max);
extern Ov003BlinkInfo *func_0206fef8(u16 id);
extern BOOL func_ov000_0218cea4(void *self);
extern BOOL func_ov000_021903b4(void *model);

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

void Ov003ActVt_021fa3e8_Start(Ov003Blink *self) {
    Ov000ActVt_021cc7cc_Start(self);
    self->u.drift.offset.x = 0;
    self->u.drift.offset.y = 0;
    self->u.drift.offset.z = 0;
    self->u.drift.phase = 0;
    func_ov000_02190cb0(self->model, data_ov003_021fa2d2, 0x1000, 0);
    func_ov000_021915a0(self->model);
}

void func_ov003_021f32c0(Ov003Blink *self) {
    VecFx32 v;
    s32 z;
    self->u.drift.phase += Rand_PlusMinus(0xe1) + 0x9a;
    if (self->u.drift.phase > 0x1000) {
        self->u.drift.phase = 0;
    }
    z = Rand_PlusMinus(0x400);
    v.x = Rand_PlusMinus(0x400) - self->u.drift.offset.x;
    v.y = -self->u.drift.offset.y;
    v.z = z - self->u.drift.offset.z;
    VEC_MultAdd(0x400, &v, &self->u.drift.offset, &self->u.drift.offset);
}

BOOL Ov003ActVt_021fa3e8_Draw(Ov003Blink *self) {
    s32 s = func_0206fef8(self->id)->scale;
    BOOL r;
    VecFx32 v;
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
        s32 d = s + FX_Mul(self->u.drift.phase, 0x59a);
        model = self->model;
        model->scaleX = d + 0x333;
        model->scaleY = d;
        model->scaleZ = d + 0x333;
        self->model->alpha = 0x12 - (self->u.drift.phase >> 8);
        VEC_Add(&self->u.drift.offset, &self->pos, &v);
        model = self->model;
        model->pos.x = v.x;
        model->pos.y = v.y;
        model->pos.z = v.z;
        func_ov000_021903b4(self->model);
    }
    return r;
}

void Ov003ActVt_021fa338_Start(Ov003Blink *self) {
    s16 rot;
    Ov000ActVt_021cc7cc_Start(self);
    if (func_0206fef8(self->id)->flip) {
        u16 a = self->rotY;
        if (a > 0x4000 && a < 0xc000) {
            self->model->flip = 1;
        }
    }
    rot = 0x1c3;
    rot += (s16)Rand_PlusMinus(0xa4);
    func_ov000_021911c8(self->model, rot);
}
