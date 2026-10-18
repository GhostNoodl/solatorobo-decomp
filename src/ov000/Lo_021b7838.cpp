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

static inline void Advance021b7838(u8 *self, Anim021b7838 *a, s32 step) {
    s32 max;
    if (a != NULL) {
        a->frame += step;
        max = (LFLD(u16, a->res, 4) << 12) - 0x1000;
        if (a->frame >= max) {
            if (LFLD(Bits021b7838, self, 0xbd).loop) {
                max = 0;
            }
            a->frame = max;
        }
    }
}

void func_ov000_021b7838(u8 *self, s32 speed) {
    s32 step;
    if (LFLD(Bits021b7838, self, 0xbd).stop) {
        return;
    }
    if (LFLD(s32, LFLD(u8 *, self, 0), 0x1c) == 0) {
        return;
    }
    if (self[0xbb] != 0) {
        return;
    }
    if (speed == 0x1000) {
        step = LFLD(s16, self, 0xb8);
    } else if (LFLD(s16, self, 0xb8) == 0x1000) {
        step = speed;
    } else {
        step = (s16)(((s64)LFLD(s16, self, 0xb8) * speed + 0x800) >> 12);
    }
    Advance021b7838(self, LFLD(Anim021b7838 *, self, 0x4), step);
    Advance021b7838(self, LFLD(Anim021b7838 *, self, 0x8), step);
    Advance021b7838(self, LFLD(Anim021b7838 *, self, 0xc), step);
    Advance021b7838(self, LFLD(Anim021b7838 *, self, 0x10), step);
    Advance021b7838(self, LFLD(Anim021b7838 *, self, 0x14), step);
}
}
