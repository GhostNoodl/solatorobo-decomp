#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02172f7c(void *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void func_ov000_02150b78(void *self, void *arg) {
    BOOL ok = TRUE;
    void *q;
    if (LFLD(void *, self, 0x50) && !LoIsState5(LFLD(void *, self, 0x50))) {
        ok = FALSE;
    }
    q = LFLD(void *, self, 0x4c);
    if (q && !LoIsState5(q)) {
        ok = FALSE;
    }
    if (LFLD(void *, self, 0x58) && !LoIsState5(LFLD(void *, self, 0x58))) {
        ok = FALSE;
    }
    if (ok) {
        func_ov000_02172f7c(self, arg);
        return;
    }
    if (q) {
        LBIT(q, 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x50)) {
        LBIT(LFLD(void *, self, 0x50), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x58)) {
        LBIT(LFLD(void *, self, 0x58), 0xc).b1 = 1;
    }
}

}
