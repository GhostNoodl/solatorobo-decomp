#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void Obj0215eab4_Draw(void *p);

void func_ov000_0215ba4c(LoBase021cafc0_021cb0b8 *self, s32 unused, s32 *pos) {
    s32 h = self->vfunc_40() << 12;
    s32 hh = h * self->cursor;
    s32 z;
    UiPanel *o;
    if (self->flag3 ? TRUE : FALSE) {
        z = self->posZ - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = (UiPanel *)((u8 *)self->panel);
        o->x = pos[0] + ((self->width >> 1) << 12);
        o->y = y + 0x6000;
    } else {
        z = self->posZ - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = (UiPanel *)((u8 *)self->panel);
        o->x = pos[0] + ((self->width >> 1) << 12);
        o->y = y - 0x2000;
    }
    o->z = z;
    Obj0215eab4_Draw(((u8 *)self->panel));
}

}
