#include "ov010/ov010.h"

extern "C" {

extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void VEC_Normalize(Ov010Vec *a, Ov010Vec *b);
extern u16 func_ov003_021d9c74(Ov010Vec *a);
extern u16 func_ov003_021d9c38(Ov010Vec *a);

static inline Ov010V *Ov010_SpawnFx192(void *self, u16 a, u16 b) {
    Ov010Vec p;
    Ov010V *fx;
    {
        s32 y = FLD(s32, self, 0x74);
        s32 z = FLD(s32, self, 0x78);
        p.x = FLD(s32, self, 0x70);
        p.y = y + FLD(s32, self, 0x68) / 2;
        p.z = z;
    }
    fx = func_02065f88(0x192, &p);
    fx->v34(a, b, 0);
    return fx;
}

Ov010V *func_ov010_0220ea84(void *self, u16 a, u16 b) {
    return Ov010_SpawnFx192(self, a, b);
}

Ov010V *func_ov010_0220eaf0(void *self, const Ov010Vec *a, const Ov010Vec *b) {
    Ov010Vec d;
    u16 ra, rb;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    VEC_Normalize(&d, &d);
    ra = func_ov003_021d9c74(&d);
    rb = func_ov003_021d9c38(&d);
    return Ov010_SpawnFx192(self, ra, rb);
}


}
