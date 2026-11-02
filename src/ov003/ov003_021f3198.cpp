#include "types.h"
#include "nitro/fx.h"
#include "ov003/Blink.h"
#include "ov003/Prop.h"

extern "C" {

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *ActorMgr_FindPlayer(void);
extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern char data_ov003_021fa2d2[];

extern BOOL Model0218fe1c_SetAnim(void *model, const void *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(void *model);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 v);
extern s32 Rand_PlusMinus(s32 max);
extern Ov003BlinkInfo *Tbl_FindEntry_0206fef8(u16 id);
extern BOOL Model021903b4_Draw(void *model);

void Ov003PropBlink_Apply(Ov003PropBlink *self) {
    u16 v = (u16)self->unk_18 >> ((3 - self->phase) * 4);
    u32 n = v & 0xf;
    u16 a;
    if (n == 0) {
        self->model->visible = 0;
        return;
    }
    self->model->visible = 1;
    if (n >= 2) {
        Model0218fe1c_SetAnim(self->model, data_ov003_021f738c[self->phase], 0x19a, 0);
        if (n >= 3) {
            Model0218fe1c_SetLoop(self->model);
        }
    }
    a = 0x40;
    switch (self->phase) {
    case 0:
        a = (u16)self->unk_1a >> 8;
        break;
    case 1:
        a = (u16)self->unk_1a;
        break;
    case 2:
        a = (u16)self->unk_1c >> 8;
        break;
    case 3:
        a = (u16)self->unk_1c;
        break;
    }
    Model0218fe1c_SetAnimSpeed(self->model, (s16)((u8)a << 6));
}

void Ov003ActVt_021fa3e8_Start(Ov003PropDrift *self) {
    Ov000ActVt_021cc7cc_Start(self);
    self->offset.x = 0;
    self->offset.y = 0;
    self->offset.z = 0;
    self->phase = 0;
    Model0218fe1c_SetAnim(self->model, data_ov003_021fa2d2, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
}

void Ov003ActVt_021fa3e8_RunState(Ov003PropDrift *self) {
    VecFx32 v;
    s32 z;
    self->phase += Rand_PlusMinus(0xe1) + 0x9a;
    if (self->phase > 0x1000) {
        self->phase = 0;
    }
    z = Rand_PlusMinus(0x400);
    v.x = Rand_PlusMinus(0x400) - self->offset.x;
    v.y = -self->offset.y;
    v.z = z - self->offset.z;
    VEC_MultAdd(0x400, &v, &self->offset, &self->offset);
}

BOOL Ov003ActVt_021fa3e8_Draw(Ov003PropDrift *self) {
    s32 s = Tbl_FindEntry_0206fef8(self->kind)->scale;
    BOOL r;
    VecFx32 v;
    Model0218fe1c *model;
    model = self->model;
    model->scale.x = s;
    model->scale.y = s;
    model->scale.z = s;
    self->model->alpha = 0x1f;
    model = self->model;
    model->trans.x = self->pos.x;
    model->trans.y = self->pos.y;
    model->trans.z = self->pos.z;
    r = Actor_Draw(self);
    if (r) {
        s32 d = s + FX_Mul(self->phase, 0x59a);
        model = self->model;
        model->scale.x = d + 0x333;
        model->scale.y = d;
        model->scale.z = d + 0x333;
        self->model->alpha = 0x12 - (self->phase >> 8);
        VEC_Add(&self->offset, &self->pos, &v);
        model = self->model;
        model->trans.x = v.x;
        model->trans.y = v.y;
        model->trans.z = v.z;
        Model021903b4_Draw(self->model);
    }
    return r;
}

void Ov003ActVt_021fa338_Start(Ov003Prop *self) {
    s16 rot;
    Ov000ActVt_021cc7cc_Start(self);
    if (Tbl_FindEntry_0206fef8(self->kind)->flip) {
        u16 a = self->rot_y;
        if (a > 0x4000 && a < 0xc000) {
            self->model->flipX = 1;
        }
    }
    rot = 0x1c3;
    rot += (s16)Rand_PlusMinus(0xa4);
    Model0218fe1c_SetAnimSpeed(self->model, rot);
}

} // extern "C"
