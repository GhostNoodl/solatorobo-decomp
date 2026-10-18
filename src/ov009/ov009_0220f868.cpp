#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_021983b0(Ov009Sub40 *st, s32 a, s32 b, s32 c);

void func_ov009_0220f868(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        FLD(u8, self, 0x108) = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->unk_40, 0x13, 1, 0)) {
            self->unk_40->timer = 0x2d;
            self->unk_40->state++;
            return;
        }
        FLD(Ov009Vec, self, 0xfc) = self->pos;
        FLD(Ov009Vec, self, 0xfc).x += func_02040528(0x1800);
        FLD(Ov009Vec, self, 0xfc).y -= 0x2333;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x3c || func_02013068(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
            FLD(Ov009Vec, self, 0xfc).x = FLD(Ov009Vec, self, 0xf0).x;
            FLD(Ov009Vec, self, 0xfc).y = FLD(Ov009Vec, self, 0xf0).y;
            FLD(Ov009Vec, self, 0xfc).z = FLD(Ov009Vec, self, 0xf0).z;
        }
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        func_02012fb8(0x7b, &d, &self->pos, &self->pos);
        break;
    }
}

}
