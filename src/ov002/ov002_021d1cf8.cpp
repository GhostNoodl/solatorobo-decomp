#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "ov002/Ov002Task.h"

extern "C" {
typedef int (*VFunc)();
#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
extern const s16 FX_SinCosTable_[];

void func_ov002_021d1cf8(Task021ef69c *self) {
    void *o;
    s32 bz;
    s32 by;
    s32 bx;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    switch (self->state) {
        case 8:
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
            self->unk_3c->flags &= ~2;
            self->unk_40->flags &= ~2;
            break;
        case 10:
            self->unk_3c->flags |= 2;
            self->unk_40->flags |= 2;
            func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
            break;
    }
    ((void (*)(void *))(*(VFunc **)self->unk_3c)[7])(self->unk_3c);
    ((void (*)(void *))(*(VFunc **)self->unk_40)[7])(self->unk_40);
    o = self->unk_3c;
    bx = self->unk_5c;
    k = 0x1000 - FX_SinCosTable_[((s32)(FIELD(o, 0x38, s32) << 14) >> 16) * 2];
    y = FIELD(o, 0xc0, s32);
    bz = self->unk_64;
    by = self->unk_60;
    x = FX_MUL(k, bx);
    z = bz + FX_MUL(k, bz);
    y = FX_MUL(k, by) - y * 15;
    self->unk_50 = x;
    self->unk_54 = y;
    self->unk_58 = z;
}

}
