#include "ov015/ov015.h"

extern "C" {

extern Ov015Obj290 *data_ov015_0221336c;
BOOL Model021903b4_Draw(void *a);
BOOL Model0218fe1c_IsAnimDone(void *p);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
extern char data_ov015_02213286[];
extern char data_ov015_0221329a[];
extern u8 data_ov015_022132a6[];
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
extern u8 data_ov015_02213280[];

BOOL func_ov015_02211bf8(Ov015Obj290 *self) {
    BOOL r = TRUE;
    switch (self->step) {
    case 0:
        if (self->vfunc_2c() == 0) self->step = 1;
        break;
    case 1:
        if (self->vfunc_30() == 0) self->step = 2;
        break;
    case 2:
        if (self->vfunc_34() == 0) self->step = 3;
        break;
    case 3:
        if (self->vfunc_38() == 0) self->step = 4;
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
    Model021903b4_Draw(&self->model);
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
        EffectObj *e = Effect_SpawnId(0x12d, &self->unk_234);
        e->unk_d4 = 3;
        e->unk_50 = 0xa000;
    }
    self->unk_10 = (u16)(self->unk_10 + 1);
    Model0218fe1c_UpdateAnim(&self->model, 0x1000);
    if (Model0218fe1c_IsAnimDone(&self->model)) {
        SndMgr_PlayVolume(data_02097e4c, 0x56, -1, -1, -1);
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
    o->SetScaleXYZ(0x59a, 0x59a, 0x59a);
    Model0218fe1c_SetAnim(&self->model, data_ov015_022132a6, 0x1000, 0);
    Model0218fe1c_SetAnimFrame(&self->model, 0);
    Model0218fe1c_SetAnimSpeed(&self->model, 0x1000);
    self->model.flags.visible = 1;
    return FALSE;
}

BOOL func_ov015_02211f54(Ov015Obj290 *self) {
    BOOL r = TRUE;
    Model0218fe1c_UpdateAnim(&self->model, 0x1000);
    if (Model0218fe1c_IsAnimDone(&self->model)) {
        r = FALSE;
        Model0218fe1c_SetAnim(&self->model, data_ov015_02213280, 0x1000, 0);
        Model0218fe1c_SetAnimFrame(&self->model, 0);
        self->model.flags.visible = 0;

    }
    return r;
}

void Model0218fe1c_ClearLoop(void *a);
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
    Model0218fe1c_SetAnim(&self->model, data_ov015_02213280, 0x1000, 0);
    Model0218fe1c_SetAnimSpeed(&self->model, (s16)self->animSpeed);
    Model0218fe1c_SetAnimFrame(&self->model, 0);
    Model0218fe1c_ClearLoop(&self->model);
    self->model.flags.visible = 1;
    self->step = 1;
}

}
