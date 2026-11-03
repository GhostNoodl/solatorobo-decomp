#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *gDataRes;
void Obj0215eab4_Draw(void *p);
void DataRes_WriteEntry(void *a, s32 b, s32 c, u16 d, s32 e);

void UiList_DrawCursor(UiList *self, s32 unused, s32 *pos) {
    s32 cur;
    s32 xoff;
    s32 h;
    s32 hh;
    s32 z;
    s32 y;
    s32 py;
    s32 px;
    UiPanel *t;
    if (self->items == NULL) {
        return;
    }
    if (!(self->flags & 0x2000000)) {
        return;
    }
    h = self->vfunc_40() << 12;
    if (self->flags & 0x1000000) {
        xoff = (0x80 - self->posX) << 12;
    } else {
        xoff = -0x8000;
    }
    if (self->flags & 0x20000) {
        hh = h * (self->cursor + 1);
    } else {
        hh = h * self->cursor;
    }
    z = self->posZ - 0xc0;
    y = self->vfunc_34();
    px = pos[0];
    py = pos[1];
    {
    s32 yy = hh + (py + (y << 12));
    t = self->panel;
    t->x = px + xoff;
    t->y = yy - 0x2000;
    }
    t->z = z;
    Obj0215eab4_Draw(self->panel);
}

}
