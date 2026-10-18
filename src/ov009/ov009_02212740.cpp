#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern u8 data_ov009_022160a0[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0219a210(Ov009Vec *v, const void *a, u16 b);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);

void func_ov009_02212740(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Rot r;
    Ov009Actor *o;
    if (func_ov000_0218d240(self) == NULL) {
        return;
    }
    p = self->pos;
    func_ov000_0219a210(&p, data_ov009_022160a0, self->rot[1]);
    r.x = self->rot[0];
    r.y = self->rot[1];
    r.z = self->rot[2];
    if (self->unk_1a == 1) {
        r.y += 0x2000;
    }
    o = func_ov000_0219be1c(0x483f, &p, &r, self->id, self->unk_90);
    if (o != NULL) {
        o->unk_1a = 1;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
