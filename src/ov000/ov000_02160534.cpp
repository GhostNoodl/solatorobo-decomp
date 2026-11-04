#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "Main/Gfx/GfxMgr.h"

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

s32 Gfx3DState_NextPolyIdB(void *a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
s32 FX_Div(s32 a, s32 b);

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

/* pid, y and x are assigned before use: declaring them as parameters (pid in the
 * unused second argument) gives the target's spill slots and registers. */
struct Obj02160534 : public VObj {
    u8 unk_04[0x8];
    Bits02160534 unk_0c;
    u8 unk_10[0x38];
    s32 unk_48;
    u8 unk_4c[0x4];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x4];
    s32 unk_68;
    u8 unk_6c[0x2c];
    u8 unk_98;
};


#ifdef NONMATCHING
void Ov000Vt_021cac0c_DrawFrame(Obj02160534 *self, s32 a, VecFx32 *pos, s32 c, s32 d);
// Status (round auA): demoted in the honesty audit. The match declared the locals y and x as unused parameters past
// the slot's five (self, a, pos, c, d) and reused a as the pid local; with real locals at every position the
// registers differ. This file is the function's whole .text, so it has no delinks entry. The score is in
// docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Ov000Vt_021cac0c_DrawFrame(Obj02160534 *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    s32 pid;
    s32 y;
    s32 x;
    GfxSys *g;
    s32 z;
    s32 v;
    s32 alpha;
    s64 dd;
    s32 r;
    s32 i;
    g = gGfxSys;
    {
        u32 n = self->unk_98;
        v = (s32)(n > 0 ? 0.5f + (float)(s32)(n << 12) : (float)(s32)(n << 12) - 0.5f);
    }
    dd = d;
    pid = 0;
    alpha = LO_FX_MUL(d, v) >> 12;
    if (alpha >= 0x1f) {
        pid = Gfx3DState_NextPolyIdB(g->unk_8b0);
    }
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x8d0 | ((alpha >= 0x1f ? pid : Gfx3DState_NextPolyIdB(g->unk_8b0)) << 24) | (alpha << 16));
    x = self->unk_50 << 12;
    y = self->unk_54 << 12;
    z = pos->z;
    self->vfunc_44(pos->x, pos->y, z, x, y, 1);
    self->vfunc_44(pos->x - 0x1000, pos->y - 0x1000, z, x + 0x2000, y + 0x2000, 0);
    if (self->unk_0c.b5) {
        self->vfunc_40(pos->x - 0x2000, pos->y, z, y, 0);
        self->vfunc_40(pos->x + x + 0x1000, pos->y, z, y, 0);
    }
    if (!self->unk_0c.b10) {
        return;
    }
    if (self->unk_0c.b8 && self->unk_5c < self->unk_68) {
        G3_Cmd1(0x29, 0x48d0 | (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | ((LO_FX_MUL(dd, 0x14000) >> 12) << 16));
        r = FX_Div(self->unk_68, self->unk_60);
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_44(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 3);
    }
    if (self->unk_5c > 0) {
        G3_Cmd1(0x29, 0x48d0 | ((alpha >= 0x1f ? pid : Gfx3DState_NextPolyIdB(g->unk_8b0)) << 24) | (alpha << 16));
        r = FX_Div(self->unk_5c, self->unk_60);
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_48(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 2);
    }
    if (self->unk_58 > 1) {
        if (alpha < 0x1f) {
            pid = Gfx3DState_NextPolyIdB(g->unk_8b0);
        }
        G3_Cmd1(0x29, 0x48d0 | (pid << 24) | (alpha << 16));
        alpha = FX_Div(x, self->unk_58 << 12);
        for (i = 1; i < self->unk_58; i++) {
            self->vfunc_40(pos->x + alpha * i, pos->y, z, y, 0);
        }
    }
    if (!self->unk_0c.b4) {
        return;
    }
    alpha = LO_FX_MUL(LO_FX_MUL(self->unk_48, dd), 0x10000) >> 12;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x29, 0x48d0 | (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | (alpha << 16));
    self->vfunc_44(pos->x, pos->y, pos->z, x, y, 4);
}
#else
// Round fkA fakematch (docs/FAKEMATCHES.md). The honest draft is the NONMATCHING branch above.
// FAKEMATCH: the slot's second parameter a is reused as the pid local, and y and x are locals declared as fake
// parameters past the slot's five (callers pass five); this gives the ROM's registers and stack slots.
void Ov000Vt_021cac0c_DrawFrame(Obj02160534 *self, s32 pid, VecFx32 *pos, s32 c, s32 d, s32 y, s32 x) {
    GfxSys *g;
    s32 z;
    s32 v;
    s32 alpha;
    s64 dd;
    s32 r;
    s32 i;
    g = gGfxSys;
    {
        u32 n = self->unk_98;
        v = (s32)(n > 0 ? 0.5f + (float)(s32)(n << 12) : (float)(s32)(n << 12) - 0.5f);
    }
    dd = d;
    pid = 0;
    alpha = LO_FX_MUL(d, v) >> 12;
    if (alpha >= 0x1f) {
        pid = Gfx3DState_NextPolyIdB(g->unk_8b0);
    }
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x8d0 | ((alpha >= 0x1f ? pid : Gfx3DState_NextPolyIdB(g->unk_8b0)) << 24) | (alpha << 16));
    x = self->unk_50 << 12;
    y = self->unk_54 << 12;
    z = pos->z;
    self->vfunc_44(pos->x, pos->y, z, x, y, 1);
    self->vfunc_44(pos->x - 0x1000, pos->y - 0x1000, z, x + 0x2000, y + 0x2000, 0);
    if (self->unk_0c.b5) {
        self->vfunc_40(pos->x - 0x2000, pos->y, z, y, 0);
        self->vfunc_40(pos->x + x + 0x1000, pos->y, z, y, 0);
    }
    if (!self->unk_0c.b10) {
        return;
    }
    if (self->unk_0c.b8 && self->unk_5c < self->unk_68) {
        G3_Cmd1(0x29, 0x48d0 | (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | ((LO_FX_MUL(dd, 0x14000) >> 12) << 16));
        r = FX_Div(self->unk_68, self->unk_60);
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_44(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 3);
    }
    if (self->unk_5c > 0) {
        G3_Cmd1(0x29, 0x48d0 | ((alpha >= 0x1f ? pid : Gfx3DState_NextPolyIdB(g->unk_8b0)) << 24) | (alpha << 16));
        r = FX_Div(self->unk_5c, self->unk_60);
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        self->vfunc_48(pos->x, pos->y, z, (LO_FX_MUL(x, r) + 0x800) & 0x7ffff000, y, 2);
    }
    if (self->unk_58 > 1) {
        if (alpha < 0x1f) {
            pid = Gfx3DState_NextPolyIdB(g->unk_8b0);
        }
        G3_Cmd1(0x29, 0x48d0 | (pid << 24) | (alpha << 16));
        alpha = FX_Div(x, self->unk_58 << 12);
        for (i = 1; i < self->unk_58; i++) {
            self->vfunc_40(pos->x + alpha * i, pos->y, z, y, 0);
        }
    }
    if (!self->unk_0c.b4) {
        return;
    }
    alpha = LO_FX_MUL(LO_FX_MUL(self->unk_48, dd), 0x10000) >> 12;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x29, 0x48d0 | (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | (alpha << 16));
    self->vfunc_44(pos->x, pos->y, pos->z, x, y, 4);
}
#endif

}
