#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern u8 data_ov009_022160a0[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Geom_AddRotatedOffset(VecFx32 *v, const void *a, u16 b);
extern Ov003Actor *Actor_SpawnKind(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);

void Ov009ActSpin_StateShoot(Ov009ActVt_02217a00 *self) {
    VecFx32 p;
    Ov009Rot r;
    Ov003Actor *o;
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    p = self->pos;
    Geom_AddRotatedOffset(&p, data_ov009_022160a0, self->rot_y);
    r.x = self->rot_x;
    r.y = self->rot_y;
    r.z = self->rot_z;
    if (self->unk_1a == 1) {
        r.y += 0x2000;
    }
    o = Actor_SpawnKind(0x483f, &p, &r, self->id, self->target);
    if (o != NULL) {
        o->unk_1a = 1;
    }
    History_SetState(self->fsm, 1, 0);
}

}
