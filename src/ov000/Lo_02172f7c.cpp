#include "ov000/LoCommon.h"

extern "C" {

static inline void *GetCur02172f7c(void) {
    return LFLD(void *, data_ov000_021ccd34, 0x10);
}

void func_ov000_02172f7c(void *self, void *arg) {
    BOOL fl = FALSE;
    if (LBIT(self, 4).b7 == 1) {
        fl = TRUE;
    }
    LFLD(u32, self, 4) |= 4;
    if (LFLD(void *, self, 0x2c) != NULL) {
        LoSwitchTaskC(LFLD(s32, LFLD(void *, self, 0x2c), 0x14), 0);
        LFLD(void *, LFLD(void *, self, 0x2c), 0x18) = arg;
    } else if (arg == NULL) {
        s32 kind = LFLD(s32, self, 0x14);
        void *cur = GetCur02172f7c();
        LFLD(u8, data_ov000_021ccd34, 0) = 1;
        arg = LoFindTask(kind);
        if (arg != NULL) {
            ((VObj *)arg)->vfunc_50();
            LFLD(u32, arg, 4) |= 6;
            LFLD(LoTaskFlags, cur, 0).st = 2;
        }
    } else {
        LoSwitchTaskC((s32)arg, 0);
        fl = FALSE;
    }
    if (fl) {
        LFLD(u8, data_ov000_021ccd34, 0) = 1;
        LBIT(LFLD(void *, data_ov000_021ccd34, 0x10), 0).b0 = 1;
    }
    LFLD(void *, self, 0x2c) = NULL;
}

}
