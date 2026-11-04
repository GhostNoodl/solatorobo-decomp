#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void AsmodeusMenu_Draw(Task021ef530 *self) {
    if (self->unk_3c != NULL && Model_IsReady(self->unk_3c, 0xffff)) {
        self->unk_3c->unk_150 = -0x1fe66;
        Model_PlayPart(self->unk_3c, 0);
    }
    if (self->fadeRatio == 0) {
        return;
    }
    Task_Draw(self);
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
}

}
