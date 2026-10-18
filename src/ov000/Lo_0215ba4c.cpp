#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
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

void func_ov000_0215ba4c(VObj *self, s32 unused, s32 *pos) {
    s32 h = self->vfunc_40() << 12;
    s32 hh = h * LFLD(s8, self, 0xb1);
    s32 z;
    u8 *o;
    if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
        z = LFLD(s16, self, 0x68) - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = LFLD(u8 *, self, 0xac);
        LFLD(s32, o, 4) = pos[0] + ((LFLD(s32, self, 0x24) >> 1) << 12);
        LFLD(s32, o, 8) = y + 0x6000;
    } else {
        z = LFLD(s16, self, 0x68) - 0x100;
        s32 y = hh + (pos[1] + (self->vfunc_34() << 12));
        o = LFLD(u8 *, self, 0xac);
        LFLD(s32, o, 4) = pos[0] + ((LFLD(s32, self, 0x24) >> 1) << 12);
        LFLD(s32, o, 8) = y - 0x2000;
    }
    LFLD(s32, o, 0xc) = z;
    func_ov000_0215eab4(LFLD(void *, self, 0xac));
}

}
