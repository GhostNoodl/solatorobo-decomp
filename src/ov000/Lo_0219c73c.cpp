#include "ov000/LoCommon.h"

typedef struct {
    u16 b0 : 11;
    u16 b11 : 1;
    u16 b12 : 4;
} Bits0219c73c;

extern "C" {
BOOL func_ov000_0218f110(void *p);
BOOL func_ov000_02191b9c(void *p);
void func_ov000_0219c8e0(void *self);

BOOL func_ov000_0219c73c(u8 *self) {
    BOOL ret = TRUE;
    if (LFLD(s16, self, 0x194) >= 0 && !func_ov000_0218f110(self + 0x194)) {
        ret = FALSE;
    }
    if (LFLD(s16, self, 0x860) >= 0 && !func_ov000_0218f110(self + 0x860)) {
        ret = FALSE;
    }
    {
        u8 *p = LFLD(u8 *, self, 0x3c);
        BOOL ok = TRUE;
        if (p[0x1b] != 3 && p[0x1b] != 0) {
            ok = FALSE;
        }
        if (!ok && !func_ov000_02191b9c(p)) {
            ret = FALSE;
        }
    }
    if (LFLD(s16, self, 0x450) >= 0 && !func_ov000_0218f110(self + 0x450)) {
        ret = FALSE;
    }
    {
        u8 *p = LFLD(u8 *, self, 0xba0);
        if (p != NULL && p[0x18] != 0 && LFLD(s16, self, 0x588) >= 0 && !func_ov000_0218f110(self + 0x588)) {
            ret = FALSE;
        }
    }
    {
        s16 *q = LFLD(s16 *, self, 0x99c);
        if (q != NULL && *q >= 0 && !func_ov000_0218f110(q)) {
            ret = FALSE;
        }
    }
    if (ret && LFLD(Bits0219c73c, self, 0xb22).b11) {
        func_ov000_0219c8e0(self);
        LFLD(Bits0219c73c, self, 0xb22).b11 = 0;
    }
    return ret;
}

}
