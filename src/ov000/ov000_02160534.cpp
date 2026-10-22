#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

#define FX_F32_TO_FX32(x) ((s32)((x) > 0 ? (x) * 4096.0f + 0.5f : (x) * 4096.0f - 0.5f))

typedef struct {
    u32 b0 : 4;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 2;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 rest : 21;
} Bits02160534;

extern "C" {

extern u8 *data_02097d48;
s32 func_02043d84(void *a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
s32 FX_Div(s32 a, s32 b);

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

/* pid, y and x are assigned before use: declaring them as parameters (pid in the
 * unused second argument) gives the target's spill slots and registers. */
void func_ov000_02160534(VObj *self, s32 pid, VecFx32 *pos, s32 c, s32 d, s32 y, s32 x) {
    u8 *g;
    s32 z;
    s32 v;
    s32 alpha;
    s64 dd;
    s32 r;
    s32 i;
    g = data_02097d48;
    {
        u32 n = LFLD(u8, self, 0x98);
        v = (s32)(n > 0 ? 0.5f + (float)(s32)(n << 12) : (float)(s32)(n << 12) - 0.5f);
    }
    dd = d;
    pid = 0;
    alpha = LO_FX_MUL(d, v) >> 12;
    if (alpha >= 0x1f) {
        pid = func_02043d84(g + 0x8b0);
    }
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x8d0 | ((alpha >= 0x1f ? pid : func_02043d84(g + 0x8b0)) << 24) | (alpha << 16));
    x = LFLD(s32, self, 0x50) << 12;
    y = LFLD(s32, self, 0x54) << 12;
    z = pos->z;
    self->vfunc_44(pos->x, pos->y, z, x, y, 1);
    self->vfunc_44(pos->x - 0x1000, pos->y - 0x1000, z, x + 0x2000, y + 0x2000, 0);
    if (LFLD(Bits02160534, self, 0xc).b5) {
        self->vfunc_40(pos->x - 0x2000, pos->y, z, y, 0);
        self->vfunc_40(pos->x + x + 0x1000, pos->y, z, y, 0);
    }
    if (!LFLD(Bits02160534, self, 0xc).b10) {
        return;
    }
    if (LFLD(Bits02160534, self, 0xc).b8 && LFLD(s32, self, 0x5c) < LFLD(s32, self, 0x68)) {
        G3_Cmd1(0x29, 0x48d0 | (func_02043d84(g + 0x8b0) << 24) | ((LO_FX_MUL(dd, 0x14000) >> 12) << 16));
        r = FX_Div(LFLD(s32, self, 0x68), LFLD(s32, self, 0x60));
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_44(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 3);
    }
    if (LFLD(s32, self, 0x5c) > 0) {
        G3_Cmd1(0x29, 0x48d0 | ((alpha >= 0x1f ? pid : func_02043d84(g + 0x8b0)) << 24) | (alpha << 16));
        r = FX_Div(LFLD(s32, self, 0x5c), LFLD(s32, self, 0x60));
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_48(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 2);
    }
    if (LFLD(s32, self, 0x58) > 1) {
        if (alpha < 0x1f) {
            pid = func_02043d84(g + 0x8b0);
        }
        G3_Cmd1(0x29, 0x48d0 | (pid << 24) | (alpha << 16));
        alpha = FX_Div(x, LFLD(s32, self, 0x58) << 12);
        for (i = 1; i < LFLD(s32, self, 0x58); i++) {
            self->vfunc_40(pos->x + alpha * i, pos->y, z, y, 0);
        }
    }
    if (!LFLD(Bits02160534, self, 0xc).b4) {
        return;
    }
    alpha = LO_FX_MUL(LO_FX_MUL(LFLD(s32, self, 0x48), dd), 0x10000) >> 12;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x29, 0x48d0 | (func_02043d84(g + 0x8b0) << 24) | (alpha << 16));
    self->vfunc_44(pos->x, pos->y, pos->z, x, y, 4);
}

}
