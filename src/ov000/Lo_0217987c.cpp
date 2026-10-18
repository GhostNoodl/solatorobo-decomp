#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

void func_ov000_0217987c(void *self) {
    s32 s;
    if (LFLD(s32, self, 0x24) == 0 || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        if (LFLD(VObj *, self, 0x40) != NULL) {
            LFLD(VObj *, self, 0x40)->vfunc_20();
        }
        if (LFLD(VObj *, self, 0x44) != NULL) {
            LFLD(VObj *, self, 0x44)->vfunc_20();
        }
        break;
    case 1:
        if (LFLD(VObj *, self, 0x50) != NULL) {
            LFLD(VObj *, self, 0x50)->vfunc_90();
        }
        break;
    }
}

BOOL func_ov000_02179910(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg == NULL) {
        return FALSE;
    }
    LFLD(u16, o, 0x4c) = LFLD(s32, msg, 4);
    if (LFLD(void *, o, 0x40) != NULL) {
        LBIT(LFLD(void *, o, 0x40), 0xc).b1 = 1;
    }
    if (LFLD(void *, o, 0x44) != NULL) {
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
    }
    func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    return TRUE;
}

}
