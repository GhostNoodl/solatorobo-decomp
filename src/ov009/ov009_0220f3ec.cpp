#include "ov009/ov009.h"

extern "C" {

extern void func_02012d78(const Ov009Vec *in, Ov009Vec *out);

void func_ov009_0220f3ec(Ov009Actor *self) {
    Ov009Vec d;
    if (func_02013068(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x19a) {
        FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
        FLD(Ov009Vec, self, 0xfc).x += func_02040528(0x7000);
        FLD(Ov009Vec, self, 0xfc).y += func_02040528(0x2000);
    }
    d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
    func_02012d78(&d, &d);
    func_02012fb8(0x52, &d, &self->pos, &self->pos);
}

}
