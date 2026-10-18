#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern void *data_ov000_021ccd44;
void *func_ov000_0218084c(void *a, s32 b, s32 c);

static inline BOOL LoGBusy(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}
BOOL func_02054f10(void *a, s32 b);

BOOL func_ov000_0216a7dc(void *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0xc).b1 = 1;
    }
    switch (LFLD(s32, self, 4)) {
    case 6:
        LFLD(u8, self, 0xa4) = 0;
        if (!LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!func_02054f10(LFLD(void *, self, 0x9c), 0xffff) || !func_02054f10(LFLD(void *, self, 0xa0), 0xffff)) {
            return FALSE;
        }
        LFLD(u16, self, 0xa6) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LBIT(self, 0xc).b3 = 1;
        LBIT(self, 0xc).b10 = 1;
        break;
    }
    return TRUE;
}

}
