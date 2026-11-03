#include "ov000/ModelPart.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/ActorMarker.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

struct Marker021beaec : ActorMarker {
    Model *unk_8c;
    u8 pad_90[4];
    s32 unk_94;
};

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

void func_ov000_021beaec(Marker021beaec *self) {
    s32 x;
    s32 y;
    s32 a;
    if (self->work.state != 10) {
        return;
    }
    x = (self->work.x >> 12) - 0x80;
    y = (self->work.y >> 12) - 0x60;
    self->unk_8c->unk_150 = self->work.z;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    a = FX_MUL(self->work.alpha, 0x1e000) >> 12;
    MODEL_FLAGS(self->unk_8c)->unk_19 = 1;
    MODEL_FLAGS(self->unk_8c)->unk_21 = 1;
    MODEL_FLAGS(self->unk_8c)->polygon_id = Gfx3DState_NextPolyId(gGfxSys->unk_8b0);
    MODEL_FLAGS(self->unk_8c)->alpha = (u8)a;
    Model_PlayPart(self->unk_8c, 15);
}

}
