#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
extern u8 *data_02097dc8;
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
void func_ov000_02152294(UiList *self, s32 a, s32 b, void *cb);
BOOL func_ov000_02151664(UiList *p, UiListItem *msg);

void func_ov000_02150f24(Lo021ca9c4 *self) {
    u16 k;
    Lo021caac8 *p;
    if (self->unk_58) {
        return;
    }
    if ((void *)self->unk_50 == NULL) {
        return;
    }
    self->unk_50->flag2 = 0;
    p = self->unk_50;
    if (!(p->busy ? FALSE : TRUE)) {
        return;
    }
    k = LFLD(u16, data_02097dc8, 0x12);
    if (k & 1) {
        if (self->unk_42 == 0xffff) {
            return;
        }
        func_ov000_02152294(p, 0x8e, 0x18, (void *)func_ov000_02151664);
        return;
    }
    if (!(k & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    self->vfunc_0c(0);
}

}
