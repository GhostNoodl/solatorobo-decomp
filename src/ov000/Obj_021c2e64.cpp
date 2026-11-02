#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

static inline void SetPos3(ObjBase021cac0c_021cb6f0 *p, s32 x, s32 y, s32 z) {
    p->unk_74 = x;
    p->unk_78 = y;
    p->unk_7c = z;
}

static inline void Move2e64(TextWin *o, s32 x, s32 y, s32 h) {
    x += 0x8000;
    y += (h - (s32)o->height) << 11;
    o->unk_vf20(x >> 12, y >> 12);
}
extern "C" {

void func_ov000_021c2e64(ListRowGauge *self) {
    s32 x;
    s32 z;
    if (self->built == 0) {
        return;
    }
    z = self->z;
    x = self->x;
    Move2e64(self->label, x, self->y, self->height);
    self->label->posZ = z + 0x20;
    self->label->Render();
    SetPos3(self->bar, (x + 0x70000) >> 12, (self->y + ((self->height - 5) << 11)) >> 12, z + 0x20);
    self->bar->vfunc_10();
}
}