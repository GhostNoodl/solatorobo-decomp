#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208ca18[];
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
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

void func_ov000_021764c4(void) {
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) - 1;
    if (LFLD(s8, data_ov000_021ccd34, 1) != 0) {
        return;
    }
    LO_FREE_V(data_ov000_021ccd34, 0x14);
}

}
