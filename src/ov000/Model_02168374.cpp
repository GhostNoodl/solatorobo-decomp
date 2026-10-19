#include "ov000/ModelPart.h"
#include "nitro/fx.h"

typedef struct {
    u8 pad[0x50];
    s32 unk_50;
    u8 pad54[0x48];
    Model *m0;
} Obj02168374;

extern "C" {

void func_ov000_02160534(Obj02168374 *self, s32 a, VecFx32 *pos, s32 c, s32 d);

void func_ov000_02168374(Obj02168374 *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    Model *m;
    s32 x;
    s32 y;
    func_ov000_02160534(self, a, pos, c, d);
    x = pos->x + ((self->unk_50 >> 1) << 12) - 0x81000;
    y = pos->y - 0x61000;
    self->m0->unk_150 = pos->z;
    Model_SetPos(self->m0, x, y);
    MODEL_FLAGS(self->m0)->alpha = (u8)(FX_Mul(d, 0x1e000) >> 12);
    self->m0->flags |= 0x200000;
    m = self->m0;
    Model_PlayPart(m, 3);
}

}
