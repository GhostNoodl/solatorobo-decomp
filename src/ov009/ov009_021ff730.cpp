#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];

void func_ov009_021ff730(Ov009Actor *self) {
    if (FLD(u16, self, 0xf4) != 0) {
        FLD(u16, self, 0xf4)--;
    } else {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    self->v50();
}

void func_ov009_021ff770(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    Ov009Vec *f8 = &FLD(Ov009Vec, self, 0xf8);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_b8 = self->pos;
        FLD(u16, self, 0xf0) = 1;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->timer = 0x3c;
            *f8 = self->unk_b8;
            f8->x += func_02040528(0x800);
            f8->z += func_02040528(0x800);
            func_ov000_0219a2f4(f8, self->pos.y + 0x2000, -0xa000);
            f8->y = f8->y + func_02040528(0x800) + 0x3000;
        }
        d.x = f8->x - self->pos.x;
        d.y = f8->y - self->pos.y;
        d.z = f8->z - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_021ff908(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec p;
    s32 d;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    v = self->unk_b8;
    self->unk_9c = self->unk_b0->unk_00;
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    p = self->pos;
    d = self->pos.y + 0x2000;
    func_ov000_0219a2f4(&p, d, -0xa000);
    d = p.y + 0x3000;
    d -= self->pos.y;
    self->pos.y += Ov009_FxMul(d, 0xcd);
    p.y += 0x3000;
    VEC_Distance(&self->pos, &p);
}

}
