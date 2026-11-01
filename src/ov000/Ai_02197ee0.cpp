#include "ov000/LoCommon.h"
#include "nitro/fx.h"


#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u64 mask;
    u8 history[7];
    u8 current;
} Hist02197ee0;

typedef struct {
    u16 st;
    u16 timer;
    VecFx32 pos;
} AiState02197ee0;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd6c;
u8 *func_ov000_0219bf90(void);
void func_ov000_0218d988(void *self, void *other, s32 a);
u8 *func_ov000_021b68b8(void *a, void *pos);
s32 func_02040498(s32 max);
u16 FX_Atan2(s32 x, s32 z);
u16 func_ov000_0219a36c(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask);

static inline BOOL GBusy02197ee0(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle02197ee0(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy02197ee0(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 Dist02197ee0(s32 dx, s32 dz) {
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT + 1) >> 1;
}

static inline s32 FX_Mul02197ee0(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Polar02197ee0(VecFx32 *p, s32 r, s16 sn, s16 cs) {
    p->x += FX_Mul02197ee0(r, sn);
    p->z += FX_Mul02197ee0(r, cs);
}

struct Obj02197ee0 {
    u8 unk_00[0x40];
    Hist02197ee0 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 unk_4c[0x20];
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0x14];
    u16 unk_90;
};

void func_ov000_02197ee0(Obj02197ee0 *self, AiState02197ee0 *st, s32 near, s32 arg, s32 radius) {
    Hist02197ee0 *h;
    u8 cur;
    u8 *obj;
    s32 dist;
    if (!GIdle02197ee0()) {
        return;
    }
    h = self->unk_40;
    cur = h->current;
    if (cur == 0 || (h->mask & 1) != 0) {
        st->st = 0;
        return;
    }
    obj = NULL;
    dist = 0x7fffffff;
    if ((u8)(cur + 0xff) <= 1) {
        self->unk_90 = 0xffff;
        obj = func_ov000_0219bf90();
        if (obj != NULL) {
            self->unk_90 = LFLD(u16, obj, 0xc);
        }
        {
            s32 dx = self->unk_70 - LFLD(s32, obj, 0x70);
            s32 dz = self->unk_78 - LFLD(s32, obj, 0x78);
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            /* non-volatile store: the target computes both halves before storing */
            *(u64 *)0x40002b8 = (u64)(sq << 2);
            while (REG_SQRTCNT & 0x8000) {
            }
            dist = (s32)(REG_SQRT_RESULT + 1) >> 1;
        }
        if (dist > 0x14000) {
            st->st = 0;
            return;
        }
    }
    switch (st->st) {
    case 0:
        if (self->unk_40->current != 1) {
            return;
        }
        st->st++;
        st->timer = 0;
    case 1: {
        VecFx32 p;
        u8 *o;
        u16 ang;
        if (dist >= radius - 0x1000 && dist <= radius + 0x2800) {
            st->st = 10;
            st->timer = 0;
            func_ov000_0218d988(self, obj, arg);
            return;
        }
        p = LFLD(VecFx32, obj, 0x70);
        o = func_ov000_021b68b8(data_ov000_021ccd6c, (u8 *)self + 0x70);
        if (o != NULL) {
            ang = LFLD(u16, o, 0x1a);
        } else {
            p.y += self->unk_6c;
            ang = FX_Atan2(p.x - self->unk_70, p.z - self->unk_78);
            ang = func_ov000_0219a36c(&p, radius, (u16)(ang + (u16)(func_02040498(0x2000) + 0x7000)), 5, 0, 0xc0000000);
        }
        Polar02197ee0(&p, radius, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        p.y = self->unk_74;
        st->pos = p;
        st->st++;
        st->timer = 0;
    }
    case 2:
        st->timer++;
        if (LFLD(s32, self->unk_48, 0x58) != 0 || st->timer >= 0x78 ||
            near + (near >> 2) > Dist02197ee0(self->unk_70 - st->pos.x, self->unk_78 - st->pos.z)) {
            st->st = 0;
        }
        if ((LFLD(u32, self->unk_48, 0x50) & 0x40000000) && st->timer >= 0x14) {
            st->st = 0;
        }
        self->unk_40->mask |= 4;
        return;
    case 10:
        st->timer++;
        if (st->timer >= 0x14) {
            st->st = 0;
        }
        func_ov000_0218d988(self, obj, arg);
        return;
    }
}
}
