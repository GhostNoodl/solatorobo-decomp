#include "ov000/LoCommon.h"

extern "C" {
extern void *data_02097e4c;
void func_02049a48(void *p, s32 id, s32 a, s32 b, s32 c);

void func_ov000_02178b10(VObj *self) {
    switch (LFLD(s32, self, 0x8)) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 13: {
        bool done;
        LFLD(VObj *, self, 0x54)->vfunc_1c();
        if (LFLD(s32, LFLD(VObj *, self, 0x54), 0x4) == 5) {
            LFLD(u32, LFLD(VObj *, self, 0x3c), 0xc) &= ~4;
        } else {
            LFLD(u32, LFLD(VObj *, self, 0x3c), 0xc) |= 4;
        }
        done = true;
        done &= !LFLD(VObj *, self, 0x3c)->vfunc_1c();
        done &= !LFLD(VObj *, self, 0x40)->vfunc_1c();
        done &= !LFLD(VObj *, self, 0x44)->vfunc_1c();
        if (LFLD(VObj *, self, 0x48) != NULL) {
            done &= !LFLD(VObj *, self, 0x48)->vfunc_1c();
        }
        if (LFLD(VObj *, self, 0x4c) != NULL) {
            done &= !LFLD(VObj *, self, 0x4c)->vfunc_1c();
        }
        done &= !LFLD(VObj *, self, 0x50)->vfunc_1c();
        if (done) {
            self->vfunc_0c(0);
        }
        break;
    }
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
}
}
