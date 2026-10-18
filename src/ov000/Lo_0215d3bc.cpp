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

void func_ov000_0215d3bc(VObj *self, void *a, s32 *pos, s32 d) {
    s32 i;
    if (a == NULL) {
        return;
    }
    if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
        self->vfunc_68(a, pos, d);
    } else {
        self->vfunc_64(a, pos, d);
    }
    if (LFLD(s32, self, 4) != 2 && d != 0x1000) {
        return;
    }
    for (i = 0; i < 12; i++) {
        VObj *o = ((LoArr98 *)self)->o[i];
        if (o) {
            s32 x0 = LFLD(s32, o, 0x3c);
            s32 y0 = LFLD(s32, o, 0x40);
            o->vfunc_20(x0 + (pos[0] >> 12), y0 + (pos[1] >> 12));
            LFLD(s32, ((LoArr98 *)self)->o[i], 0x70) = LFLD(s16, self, 0x68) - 0x40;
            ((LoArr98 *)self)->o[i]->vfunc_90();
            ((LoArr98 *)self)->o[i]->vfunc_20(x0, y0);
        }
    }
    LFLD(u32, self, 0xc) |= 0x200;
}

}
