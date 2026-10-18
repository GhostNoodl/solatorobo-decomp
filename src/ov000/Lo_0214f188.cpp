#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
u32 *func_0206e7d0(u8 id);

void func_ov000_0214f188(VObj *self, s32 idx) {
    u32 *info;
    u32 val;
    u8 *p;

    if (idx == -1) {
        LO_FREE_V(self, 0x48);
        return;
    }
    info = func_0206e7d0(idx);
    if (LFLD(u8 *, self, 0x48) != NULL && idx + 1 == LFLD(s32, LFLD(u8 *, self, 0x48), 0x80)) {
        return;
    }
    if (LFLD(u8 *, self, 0x48) != NULL) {
        LO_FREE_V(self, 0x48);
    }
    val = info[0];
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(s32, p, 0x28) = 8;
    LFLD(s32, p, 0x24) = val;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(s32, p, 0x2c) = 0;
    LFLD(u16, p, 0x74) = 0x77df;
    LFLD(u16, p, 0x76) = 0x67e;
    LFLD(u32, p, 0x4) |= 0x40;
    LFLD(u32, p, 0x4) |= 0x1400000;
    ((VObj *)p)->vfunc_14();
    LFLD(s32, p, 0x78) = 0x9000;
    LFLD(s32, p, 0x70) = -0x1ccd;
    LFLD(u32, p, 0x4) |= 0x40000004;
    LFLD(u8 *, self, 0x48) = p;
    LFLD(s32, p, 0x80) = idx + 1;
}
}
