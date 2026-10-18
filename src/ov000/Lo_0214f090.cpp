#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02172f7c(void *self, void *arg);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
BOOL func_02054f10(void *a, s32 b);

typedef struct {
    u8 pad[0x98];
    VObj *o[12];
} LoArr98;

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

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

void func_ov000_0214f090(void *self, void *arg) {
    BOOL ok = TRUE;
    void *q;
    if (LFLD(void *, self, 0x50) && !LoIsState5(LFLD(void *, self, 0x50))) {
        ok = FALSE;
    }
    q = LFLD(void *, self, 0x4c);
    if (q && !LoIsState5(q)) {
        ok = FALSE;
    }
    if (LFLD(void *, self, 0x5c) && !LoIsState5(LFLD(void *, self, 0x5c))) {
        ok = FALSE;
    }
    if (LFLD(void *, self, 0x60) && !LoIsState5(LFLD(void *, self, 0x60))) {
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
    if (LFLD(void *, self, 0x5c)) {
        LBIT(LFLD(void *, self, 0x5c), 0xc).b1 = 1;
    }
    if (LFLD(void *, self, 0x60)) {
        LBIT(LFLD(void *, self, 0x60), 0xc).b1 = 1;
    }
}

}
