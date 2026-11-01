#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 rest : 26;
} Bits0215db70;

extern "C" {
extern u16 data_ov000_021cabe0[];
void func_02041c18(Model *model, s32 a);

static inline BOOL Lo_IsShown(Lo021cae48 *self) {
    return LFLD(Bits0215db70, self, 0xc).b5 == 0 ? TRUE : FALSE;
}

void func_ov000_0215db70(Lo021cae48 *self, s32 a, s32 *pos, s32 d) {
    s32 px;
    s32 py;
    s32 x;
    s32 y;
    if (a == 0) {
        return;
    }
    if (!Lo_IsShown(self)) {
        return;
    }
    if (self->unk_24 != 0 && self->unk_28 != 0) {
        self->vfunc_64(a, pos, d);
    }
    px = pos[0];
    py = pos[1];
    x = self->vfunc_30() + (px >> 12);
    y = self->vfunc_34() + (py >> 12);
    if (self->unk_84 != 4) {
        Model_SetPos(self->unk_90, (x - 0x84) << 12, (y - 0x56) << 12);
        self->unk_90->unk_150 = self->unk_68;
        Model_PlayPart(self->unk_90, data_ov000_021cabe0[self->unk_84 * 2]);
        px = self->unk_24 + (px >> 12);
        px -= LFLD(s32, self->unk_94, 0x44) + 4;
        LFLD(s32, self->unk_94, 0x70) = self->unk_68;
        ((VObj *)self->unk_94)->vfunc_20(px, y);
        ((VObj *)self->unk_94)->vfunc_90();
        px -= self->vfunc_74();
        func_02041c18(self->unk_90, self->unk_88);
        Model_SetPos(self->unk_90, (px - 0x80) << 12, (y - 0x5f) << 12);
        self->unk_90->unk_150 = self->unk_68;
        Model_PlayPart(self->unk_90, 6);
    } else {
        LFLD(s32, self->unk_94, 0x70) = self->unk_68;
        ((VObj *)self->unk_94)->vfunc_20(x, y);
        ((VObj *)self->unk_94)->vfunc_90();
        px = self->unk_24 + (px >> 12) - 4;
        px -= self->vfunc_74();
        func_02041c18(self->unk_90, self->unk_88);
        Model_SetPos(self->unk_90, (px - 0x80) << 12, (y - 0x5f) << 12);
        self->unk_90->unk_150 = self->unk_68;
        Model_PlayPart(self->unk_90, 6);
    }
    self->unk_0c |= 0x200;
}

}

