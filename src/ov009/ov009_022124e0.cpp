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

void func_ov009_022124e0(Ov009Actor *self) {
    Ov009Actor *t;
    if (!Ov009_GameIdle()) {
        return;
    }
    t = func_ov000_0219bf90();
    if (t == NULL) {
        return;
    }
    if (Ov009_DistXZ(&self->pos, &t->pos) > 0x32000) {
        self->unk_93_4 = 0;
        self->unk_ea_6 = 1;
    } else {
        if (*self->unk_50 == 0) {
            self->unk_93_4 = 0;
        } else {
            self->unk_93_4 = 1;
        }
        self->unk_ea_6 = 0;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (!self->unk_93_4) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    if (t != NULL) {
        self->unk_90 = t->id;
    }
    self->unk_40->flags |= 0x4000;
    self->unk_b6 = 0x10e;
}

}
