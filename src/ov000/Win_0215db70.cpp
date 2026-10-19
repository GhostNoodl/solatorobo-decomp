#include "ov000/ModelPart.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 5;
    u32 b5 : 1;
    u32 rest : 26;
} Bits0215db70;

extern "C" {
extern u16 data_ov000_021cabe0[];
void func_02041c18(Model *model, s32 a);

static inline BOOL Lo_IsShown(VObj *self) {
    return LFLD(Bits0215db70, self, 0xc).b5 == 0 ? TRUE : FALSE;
}

void func_ov000_0215db70(VObj *self, s32 a, s32 *pos, s32 d) {
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
    if (LFLD(s32, self, 0x24) != 0 && LFLD(s32, self, 0x28) != 0) {
        self->vfunc_64(a, pos, d);
    }
    px = pos[0];
    py = pos[1];
    x = self->vfunc_30() + (px >> 12);
    y = self->vfunc_34() + (py >> 12);
    if (LFLD(s32, self, 0x84) != 4) {
        Model_SetPos(LFLD(Model *, self, 0x90), (x - 0x84) << 12, (y - 0x56) << 12);
        LFLD(Model *, self, 0x90)->unk_150 = LFLD(s16, self, 0x68);
        Model_PlayPart(LFLD(Model *, self, 0x90), data_ov000_021cabe0[LFLD(s32, self, 0x84) * 2]);
        px = LFLD(s32, self, 0x24) + (px >> 12);
        px -= LFLD(s32, LFLD(VObj *, self, 0x94), 0x44) + 4;
        LFLD(s32, LFLD(VObj *, self, 0x94), 0x70) = LFLD(s16, self, 0x68);
        LFLD(VObj *, self, 0x94)->vfunc_20(px, y);
        LFLD(VObj *, self, 0x94)->vfunc_90();
        px -= self->vfunc_74();
        func_02041c18(LFLD(Model *, self, 0x90), LFLD(s32, self, 0x88));
        Model_SetPos(LFLD(Model *, self, 0x90), (px - 0x80) << 12, (y - 0x5f) << 12);
        LFLD(Model *, self, 0x90)->unk_150 = LFLD(s16, self, 0x68);
        Model_PlayPart(LFLD(Model *, self, 0x90), 6);
    } else {
        LFLD(s32, LFLD(VObj *, self, 0x94), 0x70) = LFLD(s16, self, 0x68);
        LFLD(VObj *, self, 0x94)->vfunc_20(x, y);
        LFLD(VObj *, self, 0x94)->vfunc_90();
        px = LFLD(s32, self, 0x24) + (px >> 12) - 4;
        px -= self->vfunc_74();
        func_02041c18(LFLD(Model *, self, 0x90), LFLD(s32, self, 0x88));
        Model_SetPos(LFLD(Model *, self, 0x90), (px - 0x80) << 12, (y - 0x5f) << 12);
        LFLD(Model *, self, 0x90)->unk_150 = LFLD(s16, self, 0x68);
        Model_PlayPart(LFLD(Model *, self, 0x90), 6);
    }
    LFLD(u32, self, 0xc) |= 0x200;
}

}

