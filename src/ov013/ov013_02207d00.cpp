#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be7c[];
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void VEC_MultAdd(s32 s, const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov013Actor *a);
extern void func_ov000_02182590(void *p);
extern void func_ov003_021ce9c4(u16 a);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern s32 func_ov013_02209b44(Ov013Actor *self);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline void CP_SetSqrtImm64_NS_(u64 param) {
    OV013_SQRT_PARAM = param;
}

static inline void CP_SetSqrt64(u64 param) {
    OV013_SQRTCNT = 1;
    CP_SetSqrtImm64_NS_(param);
}

static inline void CP_WaitSqrt(void) {
    while (OV013_SQRTCNT & 0x8000) {
    }
}

static inline u32 CP_GetSqrtResult32(void) {
    return OV013_SQRT_RESULT;
}

static inline s32 Ov013_Sqrt2(s64 sq) {
    CP_SetSqrt64((u64)(sq << 2));
    CP_WaitSqrt();
    return (s32)(CP_GetSqrtResult32() + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const Ov013Vec *a, const Ov013Vec *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    return Ov013_Sqrt2((s64)dx * dx + (s64)dz * dz);
}

void func_ov013_02207a6c(Ov013Actor *self) {
    Ov013Actor *pl;
    s32 dist;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_94_1 = 1;
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    if (FLD(u8, self, 0x110) != 0) {
        self->unk_40->flags |= 4;
    }
    if (FLD(u8, self, 0x111) == 0) {
        u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
        if (pct <= 0x14 && pl != NULL && !func_ov000_021b4738(pl)) {
            Ov013Game54 *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(5);
            g = data_ov000_021ccd54;
            FLD(u8, g, 0xac) = 1;
            func_ov000_02182590(&FLD(u8, g, 0xac));
            func_ov003_021ce9c4(FLD(u16, self->unk_b0, 4));
            {
                Ov013Sub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            self->unk_50[2] = 0xffff;
            FLD(u8, self, 0x111) = 1;
        }
    }
    if (self->unk_40->unk_13 != 1 || FLD(u8, self, 0xf0) != 0) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    dist = 0;
    {
        Ov013Actor *t = func_ov000_0218d240(self);
        if (t != NULL) {
            s32 dz = self->pos.z - t->pos.z;
            s32 dx = self->pos.x - t->pos.x;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            dist = Ov013_Sqrt2(sq);
        }
    }
    if (dist < 0x6800 && !func_ov000_021983b0(self->unk_40, 2, 2, 1)) {
        self->unk_40->flags |= 4;
        self->unk_b6 = 0x23;
        return;
    }
    self->unk_40->flags |= 1ull << func_ov013_02209b44(self);
    self->unk_b6 = 0x46;
}

void func_ov013_02207d00(Ov013Actor *self) {
    Ov013Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->rot[1] = 0;
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    case 1: {
        s32 d = 0x9000 - self->pos.y;
        if (d > 0x3000) {
            Ov013Vec v = {0, d, 0};
            VEC_MultAdd(0x52, &v, &self->pos, &self->pos);
            return;
        }
        func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        break;
    }
    case 7:
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

extern void *data_ov000_021ccd68;
extern void *func_ov000_0218e4cc(void *mgr, s32 a);
extern u32 func_ov000_0218dfb4(void *p, s32 a);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);

void func_ov013_02207eac(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        self->unk_48->unk_30 = 0x40000000;
    }
    switch (FLD(u8, self, 0xf0)) {
    case 1:
        if (func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0x4813) != 0) {
            return;
        }
        self->unk_40->flags |= 0x10000;
        FLD(u8, self, 0xf0) = 0;
        return;
    case 2:
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x19a;
        FLD(u8, self, 0xf0) = 3;
        if (self->pos.y < 0x3000) {
            Ov013_VecSet(&self->unk_b8, self->pos.x, 0x3000, self->pos.z);
            self->unk_a0 = 0xcd;
            return;
        }
        Ov013_VecCopy(&self->unk_b8, &self->pos);
        return;
    case 3: {
        s32 y = self->unk_b8.y;
        if (self->pos.y < y) {
            func_ov000_0218dbe0(self, 0);
            if (self->pos.y > y) {
                self->pos.y = y;
            }
            self->rot[0] = func_01ffc128(0, self->rot[0], 0xcd, 1, 0x8000);
        }
        {
            Ov013Sub40 *st = self->unk_40;
            st->timer++;
            if (st->timer <= 0x14) {
                return;
            }
        }
        self->unk_a0 = 0x334;
        FLD(u8, self, 0xf0) = 4;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0xe4, 0);
        return;
    }
    case 4:
        func_ov000_0218dbe0(self, 0);
        self->rot[0] = func_01ffc128(0, self->rot[0], 0xcd, 1, 0x8000);
        if (self->pos.y >= 0x9000) {
            self->pos.y = 0x9000;
            FLD(u8, self, 0xf0) = 0;
            self->unk_40->state = 0;
        }
        return;
    }
}

}
