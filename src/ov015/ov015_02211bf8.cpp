#include "ov015/ov015.h"

extern "C" {

extern Ov015Obj290 *data_ov015_0221336c;
BOOL func_ov000_021903b4(void *a);
BOOL func_ov000_02191120(void *p);
void func_ov000_02190a80(void *a, s32 b);
extern char data_ov015_02213286[];
extern char data_ov015_0221329a[];
extern u8 data_ov015_022132a6[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_021911c8(void *a, s32 b);
extern u8 data_ov015_02213280[];

BOOL func_ov015_02211bf8(Ov015Obj290 *self) {
    BOOL r = TRUE;
    switch (self->step) {
    case 0:
        if (VCALL(self)->v2c() == 0) self->step = 1;
        break;
    case 1:
        if (VCALL(self)->v30() == 0) self->step = 2;
        break;
    case 2:
        if (VCALL(self)->v34() == 0) self->step = 3;
        break;
    case 3:
        if (VCALL(self)->v38() == 0) self->step = 4;
        break;
    case 4:
        r = FALSE;
        break;
    }
    return r;
}

BOOL func_ov015_02211c98(void) {
    return TRUE;
}

void func_ov015_02211ca0(Ov015Obj290 *self) {
    self->unk_240 = self->unk_234;
    data_ov015_0221336c = self;
    self->model.trans = self->unk_27c;
    MI_Copy36B(&self->rot, &self->model.rot);
    self->model.scale.x = 0x1000;
    self->model.scale.y = 0x1000;
    self->model.scale.z = 0x1000;
    func_ov000_021903b4(&self->model);
    data_ov015_0221336c = NULL;
}

BOOL func_ov015_02211d14(Ov015Obj290 *self) {
    u8 m[0x24];
    BOOL r;
    u16 a = self->yaw;
    u16 b = self->unk_28a;
    r = TRUE;
    BOOL done = FALSE;
    MTX_Identity33_((MtxFx33 *)(&self->rot));
    if (a != 0) {
        MTX_RotY33_((MtxFx33 *)(&self->rot), FX_SinCosTable_[((a) >> 4) * 2], FX_SinCosTable_[((a) >> 4) * 2 + 1]);
        done = r;
    }
    if (b != 0) {
        if (done) {
            MTX_RotZ33_((MtxFx33 *)m, FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
            MTX_Concat33((MtxFx33 *)m, (MtxFx33 *)(&self->rot), (MtxFx33 *)(&self->rot));
        } else {
            MTX_RotZ33_((MtxFx33 *)(&self->rot), FX_SinCosTable_[((b) >> 4) * 2], FX_SinCosTable_[((b) >> 4) * 2 + 1]);
        }
    }
    if (self->unk_10 % 10 == 0) {
        EffectObj *e = func_02065f88(0x12d, &self->unk_234);
        e->unk_d4 = 3;
        e->unk_50 = 0xa000;
    }
    self->unk_10 = (u16)(self->unk_10 + 1);
    func_ov000_02190a80(&self->model, 0x1000);
    if (func_ov000_02191120(&self->model)) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        r = FALSE;
    }
    return r;
}

BOOL func_ov015_02211e88(Ov015Obj290 *self) {
    Ov015Vec v;
    EffectObj *o;
    v = self->unk_27c;
    v.y = 0;
    o = Effect3D_Create(data_ov015_02213286, data_ov015_0221329a, 0, &v);
    o->unk_d4 = 1;
    o->unk_28 = 1;
    o->unk_50 = -0xc8000;
    VCALL(o)->v14(0x59a, 0x59a, 0x59a);
    func_ov000_02190cb0(&self->model, data_ov015_022132a6, 0x1000, 0);
    func_ov000_02191318(&self->model, 0);
    func_ov000_021911c8(&self->model, 0x1000);
    self->model.flags.visible = 1;
    return FALSE;
}

BOOL func_ov015_02211f54(Ov015Obj290 *self) {
    BOOL r = TRUE;
    func_ov000_02190a80(&self->model, 0x1000);
    if (func_ov000_02191120(&self->model)) {
        r = FALSE;
        func_ov000_02190cb0(&self->model, data_ov015_02213280, 0x1000, 0);
        func_ov000_02191318(&self->model, 0);
        FLD(Ov015Flags18, self, 0x20e).b0 = 0;

    }
    return r;
}

void func_ov000_02191618(void *a);
void func_ov015_02211fc0(Ov015Obj290 *self, const Ov015Vec *to, const Ov015Vec *from) {
    Ov015Vec d;
    s32 x, y, z;
    if (from != NULL) {
        self->unk_270 = *from;
    } else {
        self->unk_270.x = 0;
        self->unk_270.y = 0;
        self->unk_270.z = 0;
    }
    Ov015Vec t(*to);
    self->unk_27c = t;
    d.x = t.x - self->unk_270.x;
    d.y = t.y - self->unk_270.y;
    d.z = t.z - self->unk_270.z;
    VEC_Normalize(&d, &d);
    self->yaw = FX_Atan2(d.x, d.z) + 0x7fff;
    func_ov000_02190cb0(&self->model, data_ov015_02213280, 0x1000, 0);
    func_ov000_021911c8(&self->model, (s16)self->animSpeed);
    func_ov000_02191318(&self->model, 0);
    func_ov000_02191618(&self->model);
    self->model.flags.visible = 1;
    self->step = 1;
}

}
