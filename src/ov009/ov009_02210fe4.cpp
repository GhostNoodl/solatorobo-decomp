#include "ov009/ov009.h"

extern "C" {

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

void func_ov009_02210fe4(Ov009Actor *self) {
    Ov009Vec v;
    if (!Ov009_GameIdle()) {
        return;
    }
    v = *(Ov009Vec *)(FLD(u8 *, self, 0x100) + FLD(u8, self, 0xfc) * 16);
    if (Ov009_DistXZ(&self->pos, &v) > 0x333) {
        self->unk_b8 = v;
        self->unk_40->flags |= 4;
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x4000;
}

}
