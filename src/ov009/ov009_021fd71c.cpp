#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);

void func_ov009_021fd71c(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Actor *o;
    Ov009Actor *t;
    u16 kind = 0x483f;
    p = self->pos;
    if (self->kind == 0x5012) {
        p.y += 0xccd;
    } else {
        p.y -= 0x2800;
        kind = 0x482d;
    }
    o = func_ov000_0219be1c(kind, &p, self->rot, self->id, self->unk_90);
    if (self->unk_18 == 1) {
        func_02049f44(data_02097e4c, 0xd02, &self->pos, 0);
        t = func_ov000_0218d240(self);
        if (t != NULL) {
            Ov009Vec tp;
            tp = t->pos;
            if (func_01ffc584(&p, &tp, 0x6800, 0x7000)) {
                Ov009Rot r;
                r.x = 0xf000;
                r.y = o->rot[1];
                r.z = o->rot[2];
                *(Ov009Rot *)o->rot = r;
            }
        }
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
