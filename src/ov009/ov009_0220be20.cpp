#include "ov009/ov009.h"

extern "C" {

extern void *const data_ov009_02215ee4[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_0220be20(Ov009Actor *self) {
    Ov009Vec d;
    switch (self->unk_40->state) {
    case 0:
        {
            Ov009Sub38 *m = self->unk_38;
            void *an = data_ov009_02215ee4[0];
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov000_02190cb0(m, an, 0x89, 0);
        }
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (FLD(u8, self, 0xf7) == 1) {
            Ov009Sub40 *st = self->unk_40;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                self->unk_40->timer = 0x32;
                FLD(Ov009Vec, self, 0x108) = FLD(Ov009Vec, self, 0xfc);
                FLD(Ov009Vec, self, 0x108).x += func_02040528(0x800);
                FLD(Ov009Vec, self, 0x108).y += func_02040528(0x800);
                FLD(Ov009Vec, self, 0x108).z += func_02040528(0x800);
            }
            d.x = FLD(Ov009Vec, self, 0x108).x - self->pos.x;
            d.y = FLD(Ov009Vec, self, 0x108).y - self->pos.y;
            d.z = FLD(Ov009Vec, self, 0x108).z - self->pos.z;
            VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
        }
        break;
    }
    if (FLD(u8, self, 0xf7) != 1) {
        return;
    }
    if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) > 0x6000) {
        FLD(u16, self, 0xf0) = 0x10;
        func_ov000_02198360(self->unk_40, 0x11, 0);
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), self->unk_b0->unk_02);
}

}
