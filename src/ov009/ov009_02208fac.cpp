#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

BOOL func_ov009_02208fac(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110(&FLD(u8, self, 0xf0))) {
        r = FALSE;
    }
    return r;
}

}
