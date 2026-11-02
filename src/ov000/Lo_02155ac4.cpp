#include "types.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline void Arrive02155ac4(UiList *self, u8 *tgt) {
    if (((u8 *)self->topItem) == tgt) {
        if (self->unk_b3 > 1) {
            self->unk_b2 = 0;
        }
    } else {
        self->unk_b2 = 10;
        self->unk_b3 = 2;
    }
}

void func_ov000_02155ac4(UiList *self) {
    s32 w = self->vfunc_40();
    u8 *cur;
    u8 *tgt;
    if (self->flags & 0x300000) {
        if (self->flags & 0x100000) {
            self->unk_a0 -= self->unk_a2;
            if (self->unk_a0 > -w) {
                return;
            }
            self->vfunc_c0();
        } else {
            self->unk_a0 += self->unk_a2;
            if (self->unk_a0 < w) {
                return;
            }
            self->vfunc_c0();
        }
        return;
    }
    tgt = (u8 *)self->unk_a4;
    cur = (u8 *)self->topItem;
    if (cur == tgt) {
        self->unk_9e = 0;
        return;
    }
    if (LFLD(s16, tgt, 4) > LFLD(s16, cur, 4)) {
        self->unk_9e -= self->unk_a2;
        if (self->unk_9e > -w) {
            return;
        }
        self->unk_9e += (s16)w;
        self->topItem = (UiListItem *)LFLD(u8 *, cur, 0x2c);
        Arrive02155ac4(self, tgt);
    } else {
        self->unk_9e += self->unk_a2;
        if (self->unk_9e < w) {
            return;
        }
        self->unk_9e -= (s16)w;
        self->topItem = (UiListItem *)LFLD(u8 *, cur, 0x28);
        Arrive02155ac4(self, tgt);
    }
}
}
