#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
} Bits0218af9c;

typedef struct {
    u8 pad_00[0xc];
    Bits0218af9c flags;
    u8 count;
    u8 pad_0e[2];
    VecFx32 pos[4];
    u16 ang[4];
} Mgr0218af9c;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04[4];
    s16 unk_0c;
} Desc0218af9c;

typedef struct {
    VecFx32 pos;
    u16 ang;
} Pt0218af9c;

extern "C" {
extern Mgr0218af9c *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
u8 *func_ov000_0219bf90(void);
u8 *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_01ffc2a4(VecFx32 *a, VecFx32 *b, VecFx32 *min, VecFx32 *max);
BOOL func_01ffc89c(void *vol, VecFx32 *seg);
u16 FX_Atan2(s32 x, s32 z);
void func_ov000_0218b4b4(u8 *self, s32 mode, u8 *src);
u8 *func_ov000_0218bf1c(void *mgr, Desc0218af9c *d, void *pos, void *rot, u16 a);

static inline BOOL GBusy0218af9c(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline s16 GIdle0218af9c(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy0218af9c(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 FxMul0218af9c(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_0218af9c(u8 *self) {
    unsigned long on;
    s32 dist;
    BOOL any;
    u8 *pl;
    u8 i;
    Bits0218af9c *fl;
    s32 mode;
    u8 *best;
    u8 *tgt;
    Pt0218af9c t;
    VecFx32 tp;
    Desc0218af9c d;

    mode = 0;
    best = NULL;
    any = FALSE;
    pl = func_ov000_0219bf90();
    on = FALSE;
    fl = &LFLD(Bits0218af9c, self, 0xa2);
    if (LFLD(Bits0218af9c, self, 0xa2).b0 && data_ov000_021ccd64->flags.b1) {
        on = TRUE;
    }
    if (on && pl != NULL) {
        on = GIdle0218af9c();
    }
    for (i = 0; i < data_ov000_021ccd64->count; i++) {
        t.pos.x = data_ov000_021ccd64->pos[i].x;
        t.pos.y = data_ov000_021ccd64->pos[i].y;
        t.pos.z = data_ov000_021ccd64->pos[i].z;
        t.ang = data_ov000_021ccd64->ang[i];
        if (mode == 3 || mode == 1) {
            continue;
        }
        if (LFLD(u16, self, 0xe) != 0xffff && (u16)(LFLD(u16, self, 0xe) & 0xfff) != 0) {
            tgt = best;
            if (best == NULL) {
                if (data_ov000_021ccd68 == NULL) {
                    tgt = NULL;
                } else {
                    tgt = func_ov000_0218e640(data_ov000_021ccd68, LFLD(u16, self, 0xe));
                }
            }
            if (tgt != NULL) {
                BOOL r;
                any = TRUE;
                mode = 1;
                if (!on) {
                    continue;
                }
                if (pl != NULL) {
                    if (LFLD(u16, self, 0xe) == LFLD(u16, pl + 0xb00, 0x1c) || LFLD(u16, self, 0xe) == LFLD(u16, pl + 0xb00, 0x20)) {
                        continue;
                    }
                }
                tp = LFLD(VecFx32, tgt, 0x70);
                if (!func_01ffc2a4(&tp, &t.pos, (VecFx32 *)(self + 0x5c), (VecFx32 *)(self + 0x68))) {
                    r = TRUE;
                } else {

                    {
                        s32 dx = t.pos.x - tp.x;
                        s32 dz = t.pos.z - tp.z;
                        s64 sq = (s64)dx * dx;
                        sq += (s64)dz * dz;
                        REG_SQRTCNT = 1;
                        REG_SQRT_PARAM = (u64)(sq << 2);
                    }
                    while (REG_SQRTCNT & 0x8000) {
                    }
                    dist = (s32)(REG_SQRT_RESULT + 1) >> 1;
                    if (LFLD(s32, self, 0x78) < dist) {
                        r = TRUE;
                    } else if (!fl->b3) {
                        r = FALSE;
                    } else {
                        u16 a = FX_Atan2(tp.x - t.pos.x, tp.z - t.pos.z) - t.ang;
                        s32 k;
                        if (a > 0x8000) {
                            a = -a;
                        }
                        k = 0x119a - (a >> 3);
                        if (k > 0x1000) {
                            k = 0x1000;
                        } else if (k < 0x43d) {
                            k = 0x43d;
                        }
                        if (k == 0x1000) {
                            r = FALSE;
                        } else if (dist > FxMul0218af9c(LFLD(s32, self, 0x78), k)) {
                            r = TRUE;
                        } else {
                            r = FALSE;
                        }
                    }
                }
                if (r) {
                    best = tgt;
                    mode = 2;
                }
            } else {
                LFLD(u16, self, 0xe) = 0xffff;
                LFLD(u16, self, 0xc) = 0xffff;
            }
        } else if (LFLD(u16, self, 0xc) != 0xffff) {
            u8 *g = data_ov000_021ccd54;
            BOOL same;
            any = TRUE;
            same = FALSE;
            if (self[0x1a] == g[0xca] && self[0x1b] == g[0xcb] && self[0x1c] == g[0xcc]) {
                same = TRUE;
            }
            if (same) {
                tp = LFLD(VecFx32, self, 0x24);
                if (func_01ffc89c(self, &tp)) {
                    mode = 3;
                }
            }
        }
    }
    if (any) {
        switch (mode) {
        case 2:
            func_ov000_0218b4b4(self, 1, best);
            ((VObj *)best)->vfunc_08();
            break;
        case 3: {
            u16 kind = LFLD(u16, self, 8);
            s32 j;
            u8 *o;
            d.unk_00 = LFLD(u16, self, 0xc);
            d.unk_02 = LFLD(u16, self, 0xe) & 0xf000;
            for (j = 0; j < 4; j++) {
                d.unk_04[j] = LFLD(s16, self + j * 2, 0x10);
            }
            d.unk_0c = LFLD(s16, self, 0x18);
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, self + 0x24, self + 0x1e, kind);
            if (o != NULL) {
                LFLD(u16, self, 0xe) = LFLD(u16, o, 0xc);
            }
            if (o != NULL && self[0xa3] != 0xff) {
                o[0x17] = self[0xa3];
            }
            break;
        }
        }
    } else {
        self[0xb] = 0;
    }
}

}
