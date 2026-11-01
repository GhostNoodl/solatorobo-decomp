#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215eab4(void *p);

static inline void SetVec(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov000_02159720(Lo021cb3a8 *self, s32 unused, VecFx32 *pos) {
    s32 x;
    s32 y;
    u8 *t;
    VObj *e;
    if (self->unk_94 == NULL || (void *)self->unk_ec == NULL) {
        return;
    }
    t = self->unk_ac;
    x = pos->x + ((((0x100 - (LFLD(s32, t, 0x10) >> 12)) >> 1) - self->unk_64) << 12);
    y = pos->y - 0x14000;
    SetVec((VecFx32 *)(t + 4), x, y, self->unk_68 - 0xc0);
    func_ov000_0215eab4(self->unk_ac);
    e = self->unk_ec;
    if (e == NULL) {
        return;
    }
    {
        s32 px;
        y = (y >> 12) + 2;
        px = (LFLD(s32, self->unk_ac, 0x10) >> 13) - (LFLD(s32, e, 0x44) >> 1) + (x >> 12);
        LFLD(s32, e, 0x70) = self->unk_68 - 0x80;
        self->unk_ec->vfunc_20(px, y);
    }
    self->unk_ec->vfunc_90();
}

}
