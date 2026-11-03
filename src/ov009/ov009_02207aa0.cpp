#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *m, void *res, s32 a, s32 b);
extern void Obj02190758_SetRot(Model0218fe1c *m, u16 *rot, s32 a);
extern BOOL Model021903b4_Draw(Model0218fe1c *m);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void Ov009ActVt_02217844_StateIdle(Ov009ActVt_02217844 *self) {
    if (self->fsm->st == 0) {
        self->model->visible = 0;
        self->modelObj.visible = 0;
        self->fsm->st++;
    }
}

void Ov009ActVt_02217844_StateAttack(Ov009ActVt_02217844 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_022172af, 0x1000, 1);
        self->model->visible = 1;
        Model0218fe1c_SetAnimByIndex(&self->modelObj, 0, 0x1000, 1);
        self->modelObj.visible = 1;
        self->fsm->st++;
        break;
    case 1:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->model->visible = 0;
            self->modelObj.visible = 0;
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
        }
        break;
    }
}

void Ov009ActVt_02217844_StateAttack2(Ov009ActVt_02217844 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_022172b5, 0x1000, 1);
        self->model->visible = 1;
        Model0218fe1c_SetAnimByIndex(&self->modelObj, 1, 0x1000, 1);
        self->modelObj.visible = 1;
        self->fsm->st++;
        break;
    case 1:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->model->visible = 0;
            self->modelObj.visible = 0;
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
        }
        break;
    }
}

// ActorHp::unk_18 of this actor: it takes no damage.
s32 func_ov009_02207cc4(s32 dmg) {
    return 0;
}

static inline void Set(Ov009Multi *self, VecFx32 p, u16 r) { self->unk_494.x = p.x; self->unk_492 = r; self->unk_494.y = p.y; self->unk_494.z = p.z; }
void Ov009Multi_Start(Ov009Multi *self) {
    s32 i;
    Ov003Actor_Start(self);
    self->unk_492 = self->rot_y;
    self->unk_494 = self->pos;
    for (i = 0; i < 4; i++) {
        s32 f = 1;
        if (i == 0) f = 2;
        Model0218fe1c_SetRes(&self->models[i], ((void *)self->unk_34), f, 0);
        self->models[i].trans = self->pos;
        Obj02190758_SetRot(&self->models[i], &self->rot_x, 0);
    }
    self->unk_490 = 4;
    self->hpObj->unk_18 = func_ov009_02207cc4;
    self->unk_ea_6 = 1;
}

}
