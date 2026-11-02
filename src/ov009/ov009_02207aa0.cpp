#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern BOOL func_ov000_0218ffdc(Model0218fe1c *m, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Model0218fe1c *m, u16 *rot, s32 a);
extern BOOL func_ov000_021903b4(Model0218fe1c *m);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_02207aa0(Ov009ActVt_02217844 *self) {
    if (self->fsm->st == 0) {
        self->model->visible = 0;
        self->modelObj.visible = 0;
        self->fsm->st++;
    }
}

void func_ov009_02207ae4(Ov009ActVt_02217844 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172af, 0x1000, 1);
        self->model->visible = 1;
        func_ov000_02190e98(&self->modelObj, 0, 0x1000, 1);
        self->modelObj.visible = 1;
        self->fsm->st++;
        break;
    case 1:
        if (func_ov000_02191120(self->model)) {
            self->model->visible = 0;
            self->modelObj.visible = 0;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
}

void func_ov009_02207bd4(Ov009ActVt_02217844 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172b5, 0x1000, 1);
        self->model->visible = 1;
        func_ov000_02190e98(&self->modelObj, 1, 0x1000, 1);
        self->modelObj.visible = 1;
        self->fsm->st++;
        break;
    case 1:
        if (func_ov000_02191120(self->model)) {
            self->model->visible = 0;
            self->modelObj.visible = 0;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
}

BOOL func_ov009_02207cc4(void) {
    return FALSE;
}

static inline void Set(Ov009Multi *self, VecFx32 p, u16 r) { self->unk_494.x = p.x; self->unk_492 = r; self->unk_494.y = p.y; self->unk_494.z = p.z; }
void Ov009Multi_Start(Ov009Multi *self) {
    s32 i;
    func_ov003_021d112c(self);
    self->unk_492 = self->rot_y;
    self->unk_494 = self->pos;
    for (i = 0; i < 4; i++) {
        s32 f = 1;
        if (i == 0) f = 2;
        func_ov000_0218ffdc(&self->models[i], ((void *)self->unk_34), f, 0);
        self->models[i].trans = self->pos;
        func_ov000_02190758(&self->models[i], &self->rot_x, 0);
    }
    self->unk_490 = 4;
    FLD(void *, self->hp, 0x18) = (void *)func_ov009_02207cc4;
    self->unk_ea_6 = 1;
}

}
