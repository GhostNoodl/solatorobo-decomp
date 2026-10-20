#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[0xc];
    s32 x;
    s32 y;
    s32 z;
    s32 unk_18;
    u8 pad_1c[0x14];
    VObj *unk_30;
    VObj *unk_34;
    u8 pad_38[8];
    u8 unk_40;
} Obj021c2e64;

static inline void SetPos3(VObj *p, s32 x, s32 y, s32 z) {
    LFLD(s32, p, 0x74) = x;
    LFLD(s32, p, 0x78) = y;
    LFLD(s32, p, 0x7c) = z;
}

static inline void Move2e64(VObj *o, s32 x, s32 y, s32 h) {
    x += 0x8000;
    y += (h - LFLD(s32, o, 0x48)) << 11;
    o->vfunc_20(x >> 12, y >> 12);
}
extern "C" {

void func_ov000_021c2e64(Obj021c2e64 *self) {
    s32 x;
    s32 z;
    if (self->unk_40 == 0) {
        return;
    }
    z = self->z;
    x = self->x;
    Move2e64(self->unk_34, x, self->y, self->unk_18);
    LFLD(s32, self->unk_34, 0x70) = z + 0x20;
    self->unk_34->vfunc_90();
    SetPos3(self->unk_30, (x + 0x70000) >> 12, (self->y + ((self->unk_18 - 5) << 11)) >> 12, z + 0x20);
    self->unk_30->vfunc_10();
}
}