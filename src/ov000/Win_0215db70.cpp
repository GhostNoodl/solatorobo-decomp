#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"


typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 rest : 26;
} Bits0215db70;

extern "C" {
extern u16 data_ov000_021cabe0[];
void func_02041c18(Model *model, s32 a);

static inline BOOL Lo_IsShown(Lo021cae48 *self) {
    return self->flag5 == 0 ? TRUE : FALSE;
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
    if (self->width != 0 && self->height != 0) {
        self->vfunc_64(a, pos, d);
    }
    px = pos[0];
    py = pos[1];
    x = self->vfunc_30() + (px >> 12);
    y = self->vfunc_34() + (py >> 12);
    if (self->style != 4) {
        Model_SetPos(self->digits, (x - 0x84) << 12, (y - 0x56) << 12);
        self->digits->unk_150 = self->posZ;
        Model_PlayPart(self->digits, data_ov000_021cabe0[self->style * 2]);
        px = self->width + (px >> 12);
        px -= (s32)self->label->width + 4;
        self->label->posZ = self->posZ;
        self->label->unk_vf20(px, y);
        self->label->Render();
        px -= self->vfunc_74();
        func_02041c18(self->digits, self->shown);
        Model_SetPos(self->digits, (px - 0x80) << 12, (y - 0x5f) << 12);
        self->digits->unk_150 = self->posZ;
        Model_PlayPart(self->digits, 6);
    } else {
        self->label->posZ = self->posZ;
        ((VObj *)self->label)->vfunc_20(x, y);
        self->label->Render();
        px = self->width + (px >> 12) - 4;
        px -= self->vfunc_74();
        func_02041c18(self->digits, self->shown);
        Model_SetPos(self->digits, (px - 0x80) << 12, (y - 0x5f) << 12);
        self->digits->unk_150 = self->posZ;
        Model_PlayPart(self->digits, 6);
    }
    self->flags |= 0x200;
}

}

