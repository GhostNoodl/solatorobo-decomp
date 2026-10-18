#include "ov009/ov009.h"

extern "C" {

extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);

void func_ov009_0220e4fc(Ov009Actor *self) {
    Ov009Vec d;
    if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0xcd) {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            s32 r;
            FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
            r = func_02040528(0x7000);
            if (FLD(u8, self, 0x108) != 0 && r > 0) {
                r = -r;
            }
            FLD(Ov009Vec, self, 0xfc).x += r;
            FLD(Ov009Vec, self, 0xfc).y += func_02040528(0x3000);
            self->unk_40->timer = 0;
        }
    }
    d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}

}
