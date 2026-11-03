#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Obj0215eab4_Draw(UiPanel *p);

static inline void SetPos0215eab4(UiPanel *p, s32 x, s32 y, s32 z) {
    p->x = x;
    p->y = y;
    p->z = z;
}

void LoBase021ccb54_021ccbe0_DrawCursor(LoBase021ccb54_021ccbe0 *self, s32 a, const VecFx32 *v) {
    VecFx32 p;
    if (self->unk_94 == NULL) {
        return;
    }
    p = *v;
    p.x += self->unk_b4;
    p.y += self->unk_ac << 12;
    p.z = self->posZ - 0x100;
    SetPos0215eab4(self->unk_90, p.x, p.y, p.z);
    Obj0215eab4_Draw(self->unk_90);
}

}
