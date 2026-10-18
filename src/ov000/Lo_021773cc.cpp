#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

void func_ov000_021773cc(void *self) {
    s32 s;
    if (LFLD(void *, self, 0x24) == NULL || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (LFLD(VObj *, self, 0x3c)) {
        LFLD(VObj *, self, 0x3c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x40)) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44)) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x48)) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x4c)) {
        LFLD(VObj *, self, 0x4c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x50)) {
        LFLD(VObj *, self, 0x50)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x58)) {
        LFLD(VObj *, self, 0x58)->vfunc_20();
    }
}

}
