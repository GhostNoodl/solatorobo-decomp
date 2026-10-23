#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov013_0220bb20;
extern char data_ov013_0220b360[];
extern void func_ov000_02194074(void *self);
extern void func_ov003_021db244(Ov013Actor *self);
extern void func_ov003_021dae44(Ov013Actor *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *func_020657b0(void *a, s32 b);
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);

Ov013Actor *func_ov013_022065ac(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220bb20;
    FLD(u8, self, 0xf4) = 0;
    FLD(u16, self, 0xf6) = 0;
    return self;
}

void func_ov013_022065d8(Ov013Actor *self, u16 a) {
    FLD(u16, self, 0xf6) = a;
}

void func_ov013_022065e0(Ov013Actor *self, u8 a) {
    FLD(u8, self, 0xf4) = a;
}

void func_ov013_022065e8(Ov013Actor *self) {
    func_ov003_021db244(self);
    if (FLD(u16, self, 0xf6) != 0) {
        self->rot[1] += FLD(u16, self, 0xf6);
    } else {
        self->rot[1] = FX_Atan2(self->unk_9c, self->unk_a4);
    }
    if (FLD(u8, self, 0xf4) != 0 && FLD(s32, self, 0xbc) != 0) {
        void *p = func_020657b0(data_0214a420, FLD(s32, self, 0xbc));
        if (p != NULL) {
            FLD(s32, p, 0xc8) = -1;
        }
    }
}

Ov013Actor *func_ov013_0220664c(Ov013Actor *self) {
    func_ov003_021dae44(self);
    return self;
}

Ov013Actor *func_ov013_02206660(Ov013Actor *self) {
    func_ov003_021dae44(self);
    func_0203de1c(self);
    return self;
}

void func_ov013_0220667c(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Sub44 *n;
    Ov013Actor *p;
    func_ov003_021d112c(self);
    self->pos.x = -0x3000;
    self->pos.y = 0x5333;
    self->pos.z = -0xe000;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_48, 0x5c), 0, -0x1800, 0x5800);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    self->unk_48->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_44, 0xc), 0, -0x1800, 0x5800);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    self->unk_93_4 = 1;
    self->unk_b6 = 0x5a;
    FLD(u16, self, 0xfe) = 0x1000;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220b360);
        FLD(u16, self, 0xfe) = 0x1800;
    }
}

extern void *data_ov000_021ccd68;
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u32 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov013_Sqrt2(s64 sq) {
    OV013_SQRTCNT = 1;
    OV013_SQRT_PARAM = (u64)(sq << 2);
    while (OV013_SQRTCNT & 0x8000) {
    }
    return (s32)(OV013_SQRT_RESULT + 1) >> 1;
}

// `b` is a local written as an unused trailing parameter, and `t` is `volatile`:
// both are register-allocation / scheduling levers (docs/MATCHING.md).
void func_ov013_02206764(Ov013Actor *self, Ov013Actor *b) {
    BOOL ok;
    s32 n;
    s32 m;
    Ov013Actor *a;
    volatile Ov013Actor *t;
    if (!Ov013_GameIdle()) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    a = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
    b = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
    ok = TRUE;
    if (a != NULL) {
        n = func_02040498(9);
        m = 4;
        if (self->unk_50[0] < (self->unk_50[1] >> 1)) {
            m = 5;
        }
        if (func_ov000_0218dfb4(a, 0x540c) >= 2 || func_ov000_021983b0(self->unk_40, 0x10, m, 1) || n == 0) {
            ok = FALSE;
        }
    }
    if (ok) {
        self->unk_40->flags |= 0x10000;
    } else {
        ok = TRUE;
        n = (u16)(self->unk_50[0] * 100 / self->unk_50[1]);
        m = 0;
        t = func_ov000_0218d240(self);
        if (t != NULL) {
            s32 dz = self->pos.z - t->pos.z;
            s32 dx = self->pos.x - t->pos.x;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            m = Ov013_Sqrt2(sq);
            if (m < 0xd000) {
                ok = FALSE;
            }
        }
        if (ok && b != NULL) {
            s32 th = 0x1e;
            if (m > 0x11000) {
                th += 10;
            }
            if ((u32)n > 0x50) {
                th -= 0xf;
            }
            m = th;
            n = func_02040498(n);
            if (func_ov000_0218dfb4(b, 0x4813) >= 2 || n > m || func_ov000_021983b0(self->unk_40, 0xe, 2, 1)) {
                ok = FALSE;
            }
        }
        if (ok) {
            self->unk_40->flags |= 0x4000;
        } else {
            self->unk_40->flags |= 0x8000;
        }
    }
    self->unk_b6 = 0x5a;
}

}
