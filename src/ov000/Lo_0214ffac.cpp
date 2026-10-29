#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
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

BOOL func_ov000_0214ffac(void *self, void *msg) {
    VObj *obj = LFLD(VObj *, self, 8);
    u16 id;
    u8 *p;
    if (msg == NULL) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        obj->vfunc_0c(0);
        return FALSE;
    }
    id = LFLD(u16, msg, 6);
    if (id == 0x8000) {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
    } else {
        p = (u8 *)func_ov000_0218084c(data_ov000_021ccd44, 0xf, 0);
        LFLD(u16, p, 0x40) = LFLD(s32, obj, 0xc);
        LFLD(u16, p, 0x42) = id;
        obj->vfunc_48();
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

}
