#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);

void func_ov000_021c2a88(u8 *self, s32 arg) {
    u8 *p;
    if (LFLD(u8 *, self, 0x38) == NULL) {
        p = (u8 *)func_0203dd9c(0xb8);
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, data_0208ba70);
            func_0204c7d0(p);
        }
        LFLD(u8 *, self, 0x38) = p;
    }
    LFLD(VObj *, self, 0x38)->vfunc_08();
    LFLD(s32, LFLD(u8 *, self, 0x38), 0x28) = 8;
    p = LFLD(u8 *, self, 0x38);
    LFLD(s32, p, 0x24) = arg;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) = (LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) & ~0x1f00) | 0x1e00;
    LFLD(VObj *, self, 0x38)->vfunc_14();
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) |= 0x200000;
    LFLD(u32, LFLD(u8 *, self, 0x38), 0x4) |= 0x4;
    LFLD(s32, self, 0x40) = arg;
}
}
