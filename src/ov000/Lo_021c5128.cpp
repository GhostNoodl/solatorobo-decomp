#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 1;
    u32 unk_20 : 1;
    u32 unk_21 : 1;
    u32 unk_22 : 10;
} Flags021c5128;

#define FLAGSX(m) ((Flags021c5128 *)&(m)->flags)

extern "C" {

void func_02041c20(Model *model, s32 a, void *b);
void func_ov000_021c79a0(BOOL alt, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

void func_ov000_021c5128(LoBase021ccb54_021ccbe0 *self, s32 unused, s32 *pos) {
    s16 z = self->unk_68 + 0x80;
    self->unk_10->unk_158 = (void *)func_ov000_021c79a0;
    self->unk_10->flags |= 0x80000;
    self->unk_10->flags |= 0x200000;
    FLAGSX(self->unk_10)->alpha = 0x1e;
    {
        s32 x = pos[0];
        s32 y = pos[1];
        x += (self->unk_24 << 12) - self->unk_b8;
        y += ((self->unk_28 << 12) - self->unk_c0) >> 1;
        Model_SetPos(self->unk_10, x, y);
    }
    self->unk_10->unk_150 = z;
    func_02041c20(self->unk_10, 6, (u8 *)self + 0xc0);
    Model_PlayPart(self->unk_10, 6);
    self->unk_10->unk_158 = NULL;
}

}
