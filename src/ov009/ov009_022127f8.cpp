#include "ov009/ov009.h"

extern "C" {

void func_ov009_022127f8(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        FLD(Ov009Vec, self, 0x128) = self->pos;
        FLD(Ov009Vec, self, 0x128).y -= 0x1800;
        if (FLD(Ov009Vec, self, 0x128).y < FLD(s32, self, 0x138) - 0x2000) {
            FLD(Ov009Vec, self, 0x128).y = FLD(s32, self, 0x138) - 0x2000;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c || func_02013068(&self->pos, &FLD(Ov009Vec, self, 0x128)) < 0x19a) {
            if (self->unk_1a == 1) {
                func_ov000_02198360(self->unk_40, 1, 0);
            } else {
                FLD(Ov009Vec, self, 0x128).x = FLD(Ov009Vec, self, 0x134).x;
                FLD(Ov009Vec, self, 0x128).y = FLD(Ov009Vec, self, 0x134).y;
                FLD(Ov009Vec, self, 0x128).z = FLD(Ov009Vec, self, 0x134).z;
                self->unk_40->state++;
                self->unk_40->timer = 0;
            }
        }
        break;
    case 2:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x78 || func_02013068(&self->pos, &FLD(Ov009Vec, self, 0x128)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    d.x = FLD(Ov009Vec, self, 0x128).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0x128).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0x128).z - self->pos.z;
    func_02012fb8(0x7b, &d, &self->pos, &self->pos);
}

}
