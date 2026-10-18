#include "ov000/LoCommon.h"

typedef void (*StFn021bd624)(void *self);

typedef struct {
    StFn021bd624 enter;
    StFn021bd624 update;
} St021bd624;

extern "C" {

extern St021bd624 data_ov000_021cc934[];
extern St021bd624 data_ov000_021cc938[];
BOOL func_ov000_021bd8ac(void *self);
BOOL func_0203e688(void);
BOOL func_02054f10(void *p, u16 a);
void MI_CpuFill8(void *dst, u8 value, u32 size);

static inline s32 Norm021bd624(s32 k) {
    if (k >= 12 && k < 16) {
        k = 11;
    }
    return k;
}

void func_ov000_021bd624(u8 *self) {
    switch (LFLD(s32, self, 0x40)) {
    case 7:
        if (!func_ov000_021bd8ac(self)) {
            break;
        }
        LFLD(s32, self, 0x40) = 8;
    case 8: {
        s32 i;
        BOOL ok;
        s32 k = Norm021bd624(LFLD(s32, self, 0x48));
        ok = FALSE;
        if (k == 11) {
            if (func_0203e688()) {
                ok = TRUE;
            }
        } else {
            for (i = 0; i < 8; i++) {
                if (((void **)(self + 8))[i] != NULL && !func_02054f10(((void **)(self + 8))[i], 0xffff)) {
                    break;
                }
            }
            if (i == 8) {
                ok = TRUE;
            }
        }
        if (!ok) {
            break;
        }
        LFLD(s32, self, 0x40) = 9;
    }
    case 9: {
        s32 n;
        s32 k;
        if (LFLD(s32, self, 0x68) != 4) {
            break;
        }
        LBIT(self, 0).b3 = 0;
        LFLD(s32, self, 0x68) = 5;
        if (LFLD(StFn021bd624, self, 0x60) != NULL) {
            LFLD(StFn021bd624, self, 0x60)(self);
        }
        MI_CpuFill8(self + 0x68, 0, 0x24);
        LFLD(s32, self, 0x68) = 1;
        n = Norm021bd624(LFLD(s32, self, 0x48));
        LFLD(s32, self, 0x44) = LFLD(s32, self, 0x48);
        LFLD(s32, self, 0x48) = -1;
        LFLD(StFn021bd624, self, 0x60) = data_ov000_021cc934[n].enter;
        LFLD(StFn021bd624, self, 0x64) = data_ov000_021cc938[n].enter;
        if (LFLD(StFn021bd624, self, 0x60) != NULL) {
            LFLD(StFn021bd624, self, 0x60)(self);
        }
        LFLD(s32, self, 0x40) = 10;
    }
    }
    if (LFLD(StFn021bd624, self, 0x60) != NULL) {
        LFLD(StFn021bd624, self, 0x60)(self);
    }
}

}
