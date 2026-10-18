#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d36fc(Ov013Actor *self);
extern void func_ov003_021d3d28(Ov013Actor *self);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern u16 FX_Atan2(s32 y, s32 x);
extern char data_ov013_0220b5ca[];
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const Ov013Vec *a, const Ov013Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

void func_ov013_021fcef8(Ov013Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5ca, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0x214;
        self->unk_a0 = 0xcd;
        self->rot[1] = func_01ffc128(0x8000, self->rot[1], 0x1000, 1, 0x8000);
        self->unk_98 = self->rot[1];
        self->unk_50[2] = 0xffff;
        {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        FLD(u8 *, self, 0x4c)[0] = 1;
        self->unk_94_1 = 1;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    case 0x14:
        func_ov000_0218dbe0(self, 0);
        if (self->pos.y > 0x3000) {
            self->pos.y = 0x3000;
        }
        if (self->unk_38 == NULL) {
            return;
        }
        if (FLD(u8, self->unk_38, 0xbe) != 0) {
            u8 v;
            Ov013Sub40 *st = self->unk_40;
            st->timer++;
            v = 0x1f - (st->timer >> 2);
            if (v > 0x1f) {
                v = 0;
            }
            FLD(u8, self->unk_38, 0xbe) = v;
        } else {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

void func_ov013_021fd06c(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_02065804(data_0214a420, FLD(s32, self, 0xf4));
    }
    func_ov003_021d36fc(self);
}

void func_ov013_021fd0a4(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov013_021fd0c8(Ov013Actor *self) {
    Ov013Sub48 *m;
    if (self->unk_40->state == 0) {
        if (self->unk_40->unk_0c[0] == 0xb) {
            Ov013Actor *a;
            if (data_ov000_021ccd68 == NULL) {
                a = NULL;
            } else {
                a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x5000, 0x5c0a);
            }
            if (a != NULL && a->unk_44->unk_22_0 == 1 && a->unk_44->unk_22_1 == 1) {
                s32 ty = a->pos.y;
                s32 dist = Ov013_DistXZ(&self->pos, &a->pos);
                u16 ang = FX_Atan2(dist, ty + 0x3800 - self->pos.y);
                self->unk_9c = Ov013_FxMul(OV013_SIN(ang), 0x666);
                self->unk_a0 = Ov013_FxMul(OV013_COS(ang), 0x666);
            }
        }
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        self->unk_b6 = 300;
    }
    func_ov003_021d3d28(self);
}

}
