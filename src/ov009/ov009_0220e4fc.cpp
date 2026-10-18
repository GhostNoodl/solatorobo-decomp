#include "ov009/ov009.h"

extern "C" {

extern void func_02012d78(const Ov009Vec *in, Ov009Vec *out);

void func_ov009_0220e4fc(Ov009Actor *self) {
    Ov009Vec d;
    if (func_02013068(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0xcd) {
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
    func_02012d78(&d, &d);
    func_02012fb8(0x7b, &d, &self->pos, &self->pos);
}

}
