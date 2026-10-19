#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215eab4(void *p);

static inline void SetVec(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov000_02159720(VObj *self, s32 unused, VecFx32 *pos) {
    s32 x;
    s32 y;
    u8 *t;
    VObj *e;
    if (LFLD(void *, self, 0x94) == NULL || LFLD(void *, self, 0xec) == NULL) {
        return;
    }
    t = LFLD(u8 *, self, 0xac);
    x = pos->x + ((((0x100 - (LFLD(s32, t, 0x10) >> 12)) >> 1) - LFLD(s16, self, 0x64)) << 12);
    y = pos->y - 0x14000;
    SetVec((VecFx32 *)(t + 4), x, y, LFLD(s16, self, 0x68) - 0xc0);
    func_ov000_0215eab4(LFLD(void *, self, 0xac));
    e = LFLD(VObj *, self, 0xec);
    if (e == NULL) {
        return;
    }
    {
        s32 px;
        y = (y >> 12) + 2;
        px = (LFLD(s32, LFLD(u8 *, self, 0xac), 0x10) >> 13) - (LFLD(s32, e, 0x44) >> 1) + (x >> 12);
        LFLD(s32, e, 0x70) = LFLD(s16, self, 0x68) - 0x80;
        LFLD(VObj *, self, 0xec)->vfunc_20(px, y);
    }
    LFLD(VObj *, self, 0xec)->vfunc_90();
}

}
