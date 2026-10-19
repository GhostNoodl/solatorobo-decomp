#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220b88d[];
extern void *func_020657b0(void *a, s32 b);
extern void func_ov000_0219763c(Ov013Actor *self);
extern void func_ov000_02195d88(Ov013Actor *self);
extern void func_ov000_02196060(Ov013Actor *self);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov003_021d98bc(void *a, const Ov013Spot *b);

void func_ov013_021fe730(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
    }
    func_ov000_02195d88(self);
}

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

void func_ov013_021fe778(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        Ov013Actor *t = NULL;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        {
            u16 id = self->unk_90;
            if (data_ov000_021ccd68 != NULL) {
                t = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
        }
        if (t != NULL) {
            s32 ty = t->pos.y;
            s32 d = Ov013_DistXZ(&self->pos, &t->pos);
            s32 dy = self->pos.y >= ty ? self->pos.y - ty : ty - self->pos.y;
            u8 *m = FLD(u8 *, self, 0x4c);
            FLD(s32, m, 0x50) = d;
            FLD(s32, m, 0x54) = dy;
            FLD(s32, m, 0x58) = 0;
        }
        FLD(s32, self->unk_48, 0x30) = 0;
    }
    func_ov000_02196060(self);
}

}
