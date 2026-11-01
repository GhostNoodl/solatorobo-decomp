#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    u8 b0 : 1;
    u8 loop : 1;
    u8 stop : 1;
    u8 rest : 5;
} Bits021b7838;

typedef struct {
    s32 frame;
    s32 unk_04;
    u8 *res;
} Anim021b7838;

struct Obj021b7838 {
    u8 *unk_00;
    Anim021b7838 *unk_04;
    Anim021b7838 *unk_08;
    Anim021b7838 *unk_0c;
    Anim021b7838 *unk_10;
    Anim021b7838 *unk_14;
    u8 unk_18[0xa0];
    s16 unk_b8;
    u8 unk_ba[0x1];
    u8 unk_bb;
    u8 unk_bc[0x1];
    Bits021b7838 unk_bd;
};

static inline void Advance021b7838(Obj021b7838 *self, Anim021b7838 *a, s32 step) {
    s32 max;
    if (a != NULL) {
        a->frame += step;
        max = (LFLD(u16, a->res, 4) << 12) - 0x1000;
        if (a->frame >= max) {
            if (self->unk_bd.loop) {
                max = 0;
            }
            a->frame = max;
        }
    }
}

void func_ov000_021b7838(Obj021b7838 *self, s32 speed) {
    s32 step;
    if (self->unk_bd.stop) {
        return;
    }
    if (LFLD(s32, self->unk_00, 0x1c) == 0) {
        return;
    }
    if (self->unk_bb != 0) {
        return;
    }
    if (speed == 0x1000) {
        step = self->unk_b8;
    } else if (self->unk_b8 == 0x1000) {
        step = speed;
    } else {
        step = (s16)(((s64)self->unk_b8 * speed + 0x800) >> 12);
    }
    Advance021b7838(self, self->unk_04, step);
    Advance021b7838(self, self->unk_08, step);
    Advance021b7838(self, self->unk_0c, step);
    Advance021b7838(self, self->unk_10, step);
    Advance021b7838(self, self->unk_14, step);
}
}
