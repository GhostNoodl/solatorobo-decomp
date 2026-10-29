#include "ov000/LoCommon.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
extern u8 *data_02097dc8;
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
void func_ov000_02152294(void *self, s32 a, s32 b, void *cb);
BOOL func_ov000_02151664(void *p, u8 *msg);
void func_ov000_0215f334(void *p);

void func_ov000_02150f24(VObj *self) {
    u16 k;
    void *p;
    if (LFLD(void *, self, 0x58)) {
        return;
    }
    if (LFLD(void *, self, 0x50) == NULL) {
        return;
    }
    LBIT(LFLD(void *, self, 0x50), 0xc).b2 = 0;
    p = LFLD(void *, self, 0x50);
    if (!(LBIT(p, 0xc).b0 ? FALSE : TRUE)) {
        return;
    }
    k = LFLD(u16, data_02097dc8, 0x12);
    if (k & 1) {
        if (LFLD(u16, self, 0x42) == 0xffff) {
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
