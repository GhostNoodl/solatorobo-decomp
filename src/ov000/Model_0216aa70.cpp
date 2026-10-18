#include "ov000/ModelPart.h"
#include "nitro/fx.h"

typedef struct {
    u8 pad[0xc];
    u32 b0 : 10;
    u32 b10 : 1;
    u32 rest : 21;
    u8 pad10[0x8c];
    Model *m0;
    Model *m1;
} Obj0216aa70;

extern "C" {

void func_ov000_02160534(Obj0216aa70 *self, s32 a, VecFx32 *pos, s32 c, s32 d);

void func_ov000_0216aa70(Obj0216aa70 *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    Model *m;
    s32 x;
    s32 y;
    func_ov000_02160534(self, a, pos, c, d);
    x = pos->x - 0x81000;
    y = pos->y - 0x61000;
    self->m0->unk_150 = pos->z;
    Model_SetPos(self->m0, x, y);
    MODEL_FLAGS(self->m0)->alpha = 0x1e;
    self->m0->flags |= 0x200000;
    m = self->m0;
    Model_PlayPart(m, 2);
    if (self->b10) {
        return;
    }
    self->m1->unk_150 = pos->z + 0x20;
    Model_SetPos(self->m1, x, y);
    MODEL_FLAGS(self->m1)->alpha = 0x1e;
    self->m1->flags |= 0x200000;
    m = self->m1;
    Model_PlayPart(m, 0x21);
}

}
