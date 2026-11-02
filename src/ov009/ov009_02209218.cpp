#include "ov009/ov009.h"

extern "C" {

extern BOOL Model021903b4_Draw(void *p);
extern void Model0218fe1c_UpdateAnim(Model0218fe1c *p, s16 a);

BOOL Ov009ActVt_02217594_Draw(Ov009ActVt_02217594 *self) {
    BOOL r = Ov003Actor_Draw(self);
    if (r) {
        Model021903b4_Draw(&self->modelObj);
    }
    return r;
}

void Ov009ActVt_02217594_Animate(Ov009ActVt_02217594 *self) {
    Ov003Actor_Animate(self);
    Model0218fe1c_UpdateAnim(&self->modelObj, 0x1000);
}

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);

void Ov009ActVt_02217594_Update(Ov009ActVt_02217594 *self) {
    Ov003Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    switch (self->unk_1a) {
    case 0:
    case 1: {
        VecFx32 p;
        {
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        s32 y = self->pos.y - 0x1000;
        p.x = x;
        p.y = y;
        p.z = z;
        }
        if (!Hit_DiffInCylinder(&t->pos, &p, t->radius + 0x4000, 0x6000)) {
            return;
        }
        self->fsm->flags |= 0x8000;
        self->unk_b6 = 0x28;
        break;
    }
    case 2:
        self->fsm->flags |= 0x10000;
        self->unk_b6 = 0x5a;
        break;
    }
}

}
