#include "ov010/ov010.h"

extern "C" {

extern VObj *func_02065f88(s32 a, VecFx32 *b);
extern u16 Ov003Vec_Pitch(VecFx32 *a);
extern u16 Ov003Vec_Yaw(VecFx32 *a);

static inline VObj *Ov010_SpawnFx192(Actor *self, u16 a, u16 b) {
    VecFx32 p;
    VObj *fx;
    {
        s32 y = self->pos.y;
        s32 z = self->pos.z;
        p.x = self->pos.x;
        p.y = y + self->height / 2;
        p.z = z;
    }
    fx = func_02065f88(0x192, &p);
    fx->vfunc_34(a, b, 0);
    return fx;
}

VObj *func_ov010_0220ea84(Actor *self, u16 a, u16 b) {
    return Ov010_SpawnFx192(self, a, b);
}

VObj *func_ov010_0220eaf0(Actor *self, const VecFx32 *a, const VecFx32 *b) {
    VecFx32 d;
    u16 ra, rb;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    VEC_Normalize(&d, &d);
    ra = Ov003Vec_Pitch(&d);
    rb = Ov003Vec_Yaw(&d);
    return Ov010_SpawnFx192(self, ra, rb);
}


}
