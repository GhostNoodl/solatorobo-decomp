#include "ov000/ObjLayouts.h"
#include "ov000/ModelPart.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 13;
} Flags02161994;

#define FLAGS02161994(m) ((Flags02161994 *)&(m)->flags)

extern "C" {
extern const s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);

void func_ov000_02161994(Lo021cacd8 *self, s32 a1, s32 *pos, s32 y) {
    s32 t;
    s32 off;
    u8 alpha;
    s32 x;
    t = FX_Div(self->unk_94 << 12, 0x3c000);
    off = LO_FX_MUL(FX_SinCosTable_[(LO_FX_MUL(t, 0x7fff000) >> 16) * 2], 0x4000);
    alpha = FLAGS02161994(self->model)->alpha;
    if (self->upAlpha != 0) {
        FLAGS02161994(self->model)->unk_18 = 1;
        x = pos[0];
        y = pos[1];
        FLAGS02161994(self->model)->alpha = (u8)self->upAlpha;
        s32 py = y - 0x60000;
        py -= off + 0x4000;
        Model_SetPos(self->model, x - 0x9c000, py);
        Model_PlayPart(self->model, 10);
        FLAGS02161994(self->model)->unk_18 = 0;
    }
    if (self->downAlpha != 0) {
        x = pos[0];
        x -= 0x9c000;
        y = pos[1] - 0x60000;
        FLAGS02161994(self->model)->alpha = (u8)self->downAlpha;
        s32 py2 = y;
        py2 += off + 0x4000;
        Model_SetPos(self->model, x, py2);
        Model_PlayPart(self->model, 10);
    }
    FLAGS02161994(self->model)->alpha = alpha;
}

}
