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

extern Ov009Vec data_ov009_02216010;
extern u8 data_ov009_022160d0[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_02012be8(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern u16 func_0201319c(s32 x, s32 z);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220d90c(Ov009Actor *self) {
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Vec a;
    Ov009Vec b;
    Ov009Rot r;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    func_02012be8(&self->pos, &data_ov009_02216010, &a);
    r.y = func_0201319c(a.x - t->pos.x, a.z - t->pos.z) + 0x7c00 + func_02040498(0x800);
    r.x = 0;
    r.z = 0;
    o = func_ov000_0219be1c(0x480b, &a, &r, self->id, self->unk_90);
    if (o != NULL) {
        FLD(void *, o, 0x60) = data_ov009_022160d0;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
        func_02012be8(&self->pos, &data_ov009_02216010, &b);
        func_02065f88(0x325, &b)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
