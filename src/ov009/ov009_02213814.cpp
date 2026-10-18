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

extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_02213814(Ov009Actor *self) {
    u8 k;
    Ov009Actor *t;
    Ov009Vec v;
    s32 dist;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->unk_40->unk_13;
    t = func_ov000_0219bf90();
    if (t == NULL) {
        return;
    }
    v = t->pos;
    dist = Ov009_DistXZ(&self->pos, &v);
    if (dist > 0x6000) {
        self->unk_b8 = v;
        self->unk_40->flags |= 4;
    }
    if (k == 1 || k == 2) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 != 0) {
            return;
        }
        if (dist >= 0x7000) {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        } else if (func_02040498(6) != 0) {
            func_ov000_02198360(self->unk_40, 0xf, 0);
        } else {
            func_ov000_02198360(self->unk_40, 0x10, 0);
        }
        self->unk_b6 = func_02040498(0x14) + 0x64;
    }
}

}
