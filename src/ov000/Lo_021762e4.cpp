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
s32 func_0206f080(void *p);
s32 func_0206f0f4(void *p);

typedef s32 (*LoCbFn)(void *self, s32 arg);

static inline BOOL LoIsLoaded(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd34, 0x14))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_021762e4(void *a, s32 mode) {
    void *t = LoFindTask(4);
    VObj *m;
    void *r;
    if (mode == 1 && func_0206f66c(a)) {
        return;
    }
    m = LFLD(VObj *, t, 0x4c);
    r = (void *)m->vfunc_74(func_0206ec48(a), a, (u16)func_0206f080(a), func_0206f0f4(a));
    if (mode == 1 && func_0206f66c(a)) {
        mode = 0;
        LFLD(s32, r, 0x10) = mode;
        LFLD(s32, r, 0xc) = -1;
        LFLD(s32, r, 0x24) = 0xe;
    }
    LFLD(s32, r, 0x10) = mode;
}

}
