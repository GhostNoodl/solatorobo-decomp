#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern u8 data_ov009_022160a0[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void func_ov000_0219a210(VecFx32 *v, const void *a, u16 b);
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);

void Ov009ActSpin_StateShoot(Ov009ActVt_02217a00 *self) {
    VecFx32 p;
    Ov009Rot r;
    Ov003Actor *o;
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    p = self->pos;
    func_ov000_0219a210(&p, data_ov009_022160a0, self->rot_y);
    r.x = self->rot_x;
    r.y = self->rot_y;
    r.z = self->rot_z;
    if (self->unk_1a == 1) {
        r.y += 0x2000;
    }
    o = func_ov000_0219be1c(0x483f, &p, &r, self->id, self->target);
    if (o != NULL) {
        o->unk_1a = 1;
    }
    func_ov000_02198360(self->fsm, 1, 0);
}

}
