#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL func_0205a9c8(void *p);
BOOL func_0206f66c(void *p);
s32 func_0206ec48(void *p);
u16 func_0206f080(void *p);
s32 func_0206f0f4(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd34, 0x14))) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_02175e6c(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    s32 v;
    if (msg == NULL) {
        if (LFLD(u32, self, 0xc) & 0x4000000) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            return TRUE;
        }
        v = 0xff;
    } else {
        v = LFLD(u16, msg, 6);
    }
    LFLD(u16, o, 0x44) = v;
    if (LFLD(LoCbFn, o, 0x30)(o, 2)) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        ((VObj *)o)->vfunc_0c(0);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

void func_ov000_02175f34(VObj *self) {
    LBIT(self, 4).b1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    LFLD(LoCbFn, self, 0x30)(self, 0);
    func_ov000_02173648(self);
}

}
