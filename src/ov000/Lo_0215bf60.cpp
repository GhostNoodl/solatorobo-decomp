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

void func_ov000_0215bf60(void *self) {
    switch (LFLD(s32, self, 4)) {
    case 5:
        if (LBIT(self, 0xc).b1 == 1) {
            LO_FREE_V(self, 0x84);
        }
        break;
    case 0:
        if (LBIT(self, 0xc).b4 ? TRUE : FALSE) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    case 1:
        if (LBIT(self, 0xc).b4 ? TRUE : FALSE) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    }
}

}
