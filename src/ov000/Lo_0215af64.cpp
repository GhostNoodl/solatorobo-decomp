#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
extern u8 *data_02097dc8;
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
BOOL func_ov000_02151664(UiList *p, UiListItem *msg);

void func_ov000_0215af64(LoBase021cafc0_021cb0b8 *self, void *a, void *b, s32 d) {
    if (a == NULL) {
        return;
    }
    if (self->flags & 0x80000) {
        self->vfunc_d4(d, b, d);
    }
    if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
        self->vfunc_68(a, b, d);
    } else {
        self->vfunc_64(a, b, d);
    }
    self->vfunc_e8(a, b, d);
    self->vfunc_d8(a, b, d);
    if (func_02054f10(self->model, 0xffff)) {
        self->vfunc_60(a, b, d);
        self->flags |= 0x200;
    }
}

}
