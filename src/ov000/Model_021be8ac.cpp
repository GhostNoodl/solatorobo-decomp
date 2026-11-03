#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ActorMarker.h"

struct Marker021be8ac : ActorMarker {
    Model *unk_8c;
    u8 pad_90[4];
    s32 unk_94;
};

extern "C" {

void ActorMarker_DrawKind01(Marker021be8ac *self) {
    s32 x;
    s32 y;
    if (self->work.state != 10) {
        return;
    }
    x = (self->work.x >> 12) - 0x80;
    y = (self->work.y >> 12) - 0x60 + (self->unk_94 >> 12);
    self->unk_8c->unk_150 = self->work.z;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    Model_PlayPart(self->unk_8c, 4);
}

}
