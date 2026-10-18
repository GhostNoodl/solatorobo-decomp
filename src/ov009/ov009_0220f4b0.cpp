#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Bits16 {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

extern Ov009Vec data_ov009_02216040;
extern Ov009Vec data_ov009_0221604c;
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern u16 FX_Atan2(s32 x, s32 z);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220f4b0(Ov009Actor *self) {
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Vec *off;
    Ov009Vec a;
    Ov009Vec b;
    Ov009Rot r;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    if (FLD(u8, self, 0x108) % 2 == 0) {
        off = &data_ov009_02216040;
        VEC_Add(&self->pos, off, &a);
    } else {
        off = &data_ov009_0221604c;
        VEC_Add(&self->pos, off, &a);
    }
    VEC_Add(&self->pos, off, &b);
    r.y = FX_Atan2(a.x - t->pos.x, a.z - t->pos.z) + 0x7a00 + func_02040498(0x800);
    r.x = 0;
    r.z = 0;
    if (r.y < 0xea9c) {
        if (r.y > 0x1554) {
            r.y = 0xea9c;
        }
    }
    o = func_ov003_021d69f0(self, 0x482d, &a, &r, t);
    if (o != NULL) {
        FLD(u16, o, 0x18) = 1;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
    }
    func_02065f88(0x325, &b)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
