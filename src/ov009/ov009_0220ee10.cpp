#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220ee10(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        FLD(Ov009Vec, self, 0xfc) = self->pos;
        FLD(Ov009Vec, self, 0xfc).x += 0x2000;
        FLD(Ov009Vec, self, 0xfc).y -= 0x1000;
        st->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x28 || VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
            FLD(Ov009Vec, self, 0xfc).x = self->pos.x;
            FLD(Ov009Vec, self, 0xfc).y = self->pos.y;
            FLD(Ov009Vec, self, 0xfc).z = self->pos.z;
        }
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
        break;
    }
}

}
