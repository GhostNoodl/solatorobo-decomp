#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "ov002/Ov002Task.h"

extern "C" {
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
extern const s16 FX_SinCosTable_[];

void Task021ef69c_PreUpdate(Task021ef69c *self) {
    TextList *o;
    s32 bz;
    s32 by;
    s32 bx;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    switch (self->state) {
        case 8:
            SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
            self->unk_3c->flags &= ~2;
            self->unk_40->flags &= ~2;
            break;
        case 10:
            self->unk_3c->flags |= 2;
            self->unk_40->flags |= 2;
            SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
            break;
    }
    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
    o = self->unk_3c;
    bx = self->unk_5c;
    k = 0x1000 - FX_SinCosTable_[((s32)(o->openRatio << 14) >> 16) * 2];
    y = o->lift;
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
