#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_021903b4(void *p);
extern void func_ov000_02190a80(void *p, s32 a);

BOOL Ov009ActVt_02217594_Draw(Ov009ActVt_02217594 *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (r) {
        func_ov000_021903b4(&self->modelObj);
    }
    return r;
}

void func_ov009_0220923c(Ov009ActVt_02217594 *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80(&self->modelObj, 0x1000);
}

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(const VecFx32 *a, const VecFx32 *b, s32 r, s32 h);

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
