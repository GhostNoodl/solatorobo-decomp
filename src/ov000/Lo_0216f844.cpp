#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

void func_ov000_0216f844(void *self, s32 a) {
    if (LFLD(s32, self, 0x2c) == 0) {
        if (a == LFLD(s32, self, 0x28)) {
            if (LFLD(VObj *, self, 0x30) != NULL) {
                LFLD(VObj *, self, 0x30)->vfunc_0c();
            }
            return;
        }
        LFLD(s32, self, 0x2c) = a;
        LFLD(s32, self, 0x20) = 3;
        LFLD(s32, self, 0x24) = 0;
    } else if (a != LFLD(s32, self, 0x2c)) {
        LFLD(s32, self, 0x2c) = a;
        LFLD(s32, self, 0x20) = 3;
        LFLD(s32, self, 0x24) = 0;
    }
}

}
