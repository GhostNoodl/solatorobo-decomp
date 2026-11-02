#include "types.h"
#include "Main/Sys/Pad.h"

typedef struct {
    u32 b0 : 2;
    u32 b2 : 1;
    u32 rest : 29;
} Bits02161280;

typedef void (*Cb02161280)(u8 *self, BOOL ok);

extern "C" {
extern void *data_02097e4c;
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);

struct Obj02161280 {
    u8 unk_00[0xc];
    Bits02161280 unk_0c;
    u8 unk_10[0x78];
    u16 unk_88;
    u16 unk_8a;
    u8 unk_8c[0x4];
    Cb02161280 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
};

void func_ov000_02161280(Obj02161280 *self) {
    u32 rep;
    u32 trg;
    if (self->unk_0c.b2) {
        return;
    }
    trg = data_02097dc8->trig;
    rep = data_02097dc8->repeat;
    if (trg & 1) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        if (self->unk_90 != NULL) {
            self->unk_90((u8 *)self, TRUE);
        }
    } else if (trg & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        if (self->unk_90 != NULL) {
            self->unk_90((u8 *)self, FALSE);
        }
    } else if (rep & 0x40) {
        u16 old = self->unk_88;
        s32 v = old + 1;
        if (v >= self->unk_8a) {
            v = self->unk_8a;
        }
        self->unk_88 = v;
        if (old != self->unk_88) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x80) {
        u16 old = self->unk_88;
        s32 v = old - 1;
        self->unk_88 = v <= 1 ? 1 : v;
        if (old != self->unk_88) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x20) {
        u16 old = self->unk_88;
        s32 v = old + 10;
        if (v >= self->unk_8a) {
            v = self->unk_8a;
        }
        self->unk_88 = v;
        if (old != self->unk_88) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    } else if (rep & 0x10) {
        u16 old = self->unk_88;
        s32 v = old - 10;
        self->unk_88 = v <= 1 ? 1 : v;
        if (old != self->unk_88) {
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    self->unk_94++;
    self->unk_94 %= 60;
    if (self->unk_88 != self->unk_8a) {
        s32 x = self->unk_98 += 3;
        self->unk_98 = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = self->unk_98 -= 3;
        self->unk_98 = x <= 0 ? 0 : x;
    }
    if (self->unk_88 != 1) {
        s32 x = self->unk_9c += 3;
        self->unk_9c = x >= 0x1f ? 0x1f : x;
    } else {
        s32 x = self->unk_9c -= 3;
        self->unk_9c = x <= 0 ? 0 : x;
    }
}
}
