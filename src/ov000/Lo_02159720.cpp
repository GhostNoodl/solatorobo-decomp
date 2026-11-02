#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

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
    UiPanel *t;
    VObj *e;
    if (self->items == NULL || (void *)self->unk_ec == NULL) {
        return;
    }
    t = (UiPanel *)((u8 *)self->panel);
    x = pos->x + ((((0x100 - (t->unk_10 >> 12)) >> 1) - self->posX) << 12);
    y = pos->y - 0x14000;
    SetVec((VecFx32 *)(&t->unk_04), x, y, self->posZ - 0xc0);
    func_ov000_0215eab4(((u8 *)self->panel));
    e = self->unk_ec;
    if (e == NULL) {
        return;
    }
    {
        s32 px;
        y = (y >> 12) + 2;
        px = (self->panel->unk_10 >> 13) - (LFLD(s32, e, 0x44) >> 1) + (x >> 12);
        LFLD(s32, e, 0x70) = self->posZ - 0x80;
        self->unk_ec->vfunc_20(px, y);
    }
    self->unk_ec->vfunc_90();
}

}
