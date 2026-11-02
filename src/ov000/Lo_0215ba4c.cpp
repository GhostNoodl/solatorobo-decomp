#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_0216bae4(void *dst, void *src);
BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
void func_ov000_0215eab4(void *p);

static inline BOOL LoResDone(u8 *o) {
    if (LFLD(void *, o, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, o, 0x6c))) {
        LFLD(void *, o, 0x6c) = NULL;
    } else {
        return LBIT(o, 4).b6 ? FALSE : TRUE;
    }
    return TRUE;
}

void func_ov000_0215ba4c(LoBase021cafc0_021cb0b8 *self, s32 unused, s32 *pos) {
    s32 h = self->vfunc_40() << 12;
    s32 hh = h * self->cursor;
    s32 z;
    UiPanel *o;
    if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
        z = self->posZ - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = (UiPanel *)((u8 *)self->panel);
        o->unk_04 = pos[0] + ((self->width >> 1) << 12);
        o->unk_08 = y + 0x6000;
    } else {
        z = self->posZ - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = (UiPanel *)((u8 *)self->panel);
        o->unk_04 = pos[0] + ((self->width >> 1) << 12);
        o->unk_08 = y - 0x2000;
    }
    o->unk_0c = z;
    func_ov000_0215eab4(((u8 *)self->panel));
}

}
