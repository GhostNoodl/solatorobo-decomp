#include "ov009/ov009.h"

extern "C" {

extern void Obj021984c8_UpdatePos(void *a, void *b, s32 c);

void Ov009ActSpin_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 == NULL) {
        return;
    }
    Obj021984c8_UpdatePos(self->unk_44, (u8 *)self + 0x11c, 0);
}

extern char data_ov009_022179b4[];
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);

void Ov009ActSpin_StateIdle(Ov009ActSpin *self) {
    VecFx32 d;
    s32 x, y, z;
    x = self->unk_134.x;
    self->unk_f2 += 0x60;
    y = self->unk_134.y + OV009_SIN(self->unk_f2);
    z = self->unk_134.z;
    d.x = x - self->pos.x;
    d.y = y - self->pos.y;
    d.z = z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
    Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x2ab, 0);
    Model0218fe1c_SetLoop(self->model);
    Model0218fe1c_SetAnimSpeed(self->model, 0x99a);
}

}
