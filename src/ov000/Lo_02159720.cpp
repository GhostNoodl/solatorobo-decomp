#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

void Obj0215eab4_Draw(void *p);

static inline void SetVec(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov000_02159720(Lo021cb3a8 *self, s32 unused, VecFx32 *pos) {
    s32 x;
    s32 y;
    UiPanel *t;
    TextWin *e;
    if (self->items == NULL || (void *)self->text == NULL) {
        return;
    }
    t = (UiPanel *)((u8 *)self->panel);
    x = pos->x + ((((0x100 - (t->width >> 12)) >> 1) - self->posX) << 12);
    y = pos->y - 0x14000;
    SetVec((VecFx32 *)(&t->x), x, y, self->posZ - 0xc0);
    Obj0215eab4_Draw(((u8 *)self->panel));
    e = self->text;
    if (e == NULL) {
        return;
    }
    {
        s32 px;
        y = (y >> 12) + 2;
        px = (self->panel->width >> 13) - ((s32)e->width >> 1) + (x >> 12);
        e->posZ = self->posZ - 0x80;
        self->text->unk_vf20(px, y);
    }
    self->text->Render();
}

}
