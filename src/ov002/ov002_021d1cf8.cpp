#include "types.h"

extern "C" {
typedef int (*VFunc)();
typedef struct Task50 {
    VFunc *vt;
    u32 flags;
    s32 unk_08;
    u8 unk_0c[0x30];
    void *unk_3c;
    void *unk_40;
} Task50;
#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
extern const s16 FX_SinCosTable_[];
extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);

void func_ov002_021d1cf8(Task50 *self) {
    void *o;
    s32 bz;
    s32 by;
    s32 bx;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    switch (self->unk_08) {
        case 8:
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
            FIELD(self->unk_3c, 0xc, u32) &= ~2;
            FIELD(self->unk_40, 0xc, u32) &= ~2;
            break;
        case 10:
            FIELD(self->unk_3c, 0xc, u32) |= 2;
            FIELD(self->unk_40, 0xc, u32) |= 2;
            func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
            break;
    }
    ((void (*)(void *))(*(VFunc **)self->unk_3c)[7])(self->unk_3c);
    ((void (*)(void *))(*(VFunc **)self->unk_40)[7])(self->unk_40);
    o = self->unk_3c;
    bx = FIELD(self, 0x5c, s32);
    k = 0x1000 - FX_SinCosTable_[((s32)(FIELD(o, 0x38, s32) << 14) >> 16) * 2];
    y = FIELD(o, 0xc0, s32);
    bz = FIELD(self, 0x64, s32);
    by = FIELD(self, 0x60, s32);
    x = FX_MUL(k, bx);
    z = bz + FX_MUL(k, bz);
    y = FX_MUL(k, by) - y * 15;
    FIELD(self, 0x50, s32) = x;
    FIELD(self, 0x54, s32) = y;
    FIELD(self, 0x58, s32) = z;
}

}
