#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0x12];
    u16 trg;
    u8 pad_14[2];
    u16 rep;
} Pad02161280;

typedef struct {
    u32 b0 : 2;
    u32 b2 : 1;
    u32 rest : 29;
} Bits02161280;

typedef void (*Cb02161280)(u8 *self, BOOL ok);

extern "C" {
extern Pad02161280 *data_02097dc8;
extern void *data_02097e4c;
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);

void func_ov000_02161280(u8 *self) {
    u32 rep;
    u32 trg;
    if (LFLD(Bits02161280, self, 0xc).b2) {
        return;
    }
    trg = data_02097dc8->trg;
    rep = data_02097dc8->rep;
    if (trg & 1) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        if (LFLD(Cb02161280, self, 0x90) != NULL) {
            LFLD(Cb02161280, self, 0x90)(self, TRUE);
        }
    } else if (trg & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        if (LFLD(Cb02161280, self, 0x90) != NULL) {
            LFLD(Cb02161280, self, 0x90)(self, FALSE);
        }
    } else if (rep & 0x40) {
        u16 old = LFLD(u16, self, 0x88);
        s32 v = old + 1;
        if (v >= LFLD(u16, self, 0x8a)) {
            v = LFLD(u16, self, 0x8a);
        }
        LFLD(u16, self, 0x88) = v;
        if (old != LFLD(u16, self, 0x88)) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x80) {
        u16 old = LFLD(u16, self, 0x88);
        s32 v = old - 1;
        LFLD(u16, self, 0x88) = v <= 1 ? 1 : v;
        if (old != LFLD(u16, self, 0x88)) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x20) {
        u16 old = LFLD(u16, self, 0x88);
        s32 v = old + 10;
        if (v >= LFLD(u16, self, 0x8a)) {
            v = LFLD(u16, self, 0x8a);
        }
        LFLD(u16, self, 0x88) = v;
        if (old != LFLD(u16, self, 0x88)) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x10) {
        u16 old = LFLD(u16, self, 0x88);
        s32 v = old - 10;
        LFLD(u16, self, 0x88) = v <= 1 ? 1 : v;
        if (old != LFLD(u16, self, 0x88)) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    LFLD(s32, self, 0x94)++;
    LFLD(s32, self, 0x94) %= 60;
    if (LFLD(u16, self, 0x88) != LFLD(u16, self, 0x8a)) {
        s32 x = LFLD(s32, self, 0x98) += 3;
        LFLD(s32, self, 0x98) = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = LFLD(s32, self, 0x98) -= 3;
        LFLD(s32, self, 0x98) = x <= 0 ? 0 : x;
    }
    if (LFLD(u16, self, 0x88) != 1) {
        s32 x = LFLD(s32, self, 0x9c) += 3;
        LFLD(s32, self, 0x9c) = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = LFLD(s32, self, 0x9c) -= 3;
        LFLD(s32, self, 0x9c) = x <= 0 ? 0 : x;
    }
}
}
