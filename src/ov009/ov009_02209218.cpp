#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_021903b4(void *p);
extern void func_ov000_02190a80(void *p, s32 a);

BOOL func_ov009_02209218(Ov009Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (r) {
        func_ov000_021903b4(&FLD(u8, self, 0x228));
    }
    return r;
}

void func_ov009_0220923c(Ov009Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80(&FLD(u8, self, 0x228), 0x1000);
}

extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);

void func_ov009_02209258(Ov009Actor *self) {
    Ov009Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
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
        Ov009Vec p;
        {
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        s32 y = self->pos.y - 0x1000;
        p.x = x;
        p.y = y;
        p.z = z;
        }
        if (!func_01ffc584(&t->pos, &p, t->unk_64 + 0x4000, 0x6000)) {
            return;
        }
        self->unk_40->flags |= 0x8000;
        self->unk_b6 = 0x28;
        break;
    }
    case 2:
        self->unk_40->flags |= 0x10000;
        self->unk_b6 = 0x5a;
        break;
    }
}

}
