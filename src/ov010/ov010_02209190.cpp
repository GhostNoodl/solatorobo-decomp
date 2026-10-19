#include "ov010/ov010.h"

struct Ov010Mtx33 {
    s32 m[3][3];
};

extern "C" {

extern const Ov010Blk12 data_ov010_0220f594;
extern const Ov010Vec data_ov010_0220f54c;
extern void MTX_RotAxis33(Ov010Mtx33 *m, const Ov010Vec *v, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33 *m, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *src, Ov010Vec *dst);
extern u16 func_ov003_021d9c38(Ov010Vec *v);

void func_ov010_02209190(s32 type, const s32 *rect, const Ov010Vec *c, const Ov010Vec *p, u16 ang) {
    Ov010Vec v;
    Ov010Vec a;
    Ov010Mtx33 m;
    *(Ov010Blk12 *)&v = data_ov010_0220f594;
    switch (type) {
    case 0:
        if (p->x < rect[0]) {
            v.x = 0x1000;
        } else if (rect[2] < p->x) {
            v.x = -0x1000;
        }
        if (p->z < rect[1]) {
            v.z = 0x1000;
        } else if (rect[3] < p->z) {
            v.z = -0x1000;
        }
        break;
    case 1:
        v.x = c->x - p->x;
        v.y = c->y - p->y;
        v.z = c->z - p->z;
        VEC_Normalize(&v, &v);
        break;
    }
    func_ov003_021d9980(&a, ang + 0x7fff, (Ov010Vec *)&data_ov010_0220f54c);
    MTX_RotAxis33(&m, &v, OV010_SIN(0x7ff0), OV010_COS(0x7ff0));
    MTX_MultVec33(&a, &m, &a);
    func_ov003_021d9c38(&a);
}

}
