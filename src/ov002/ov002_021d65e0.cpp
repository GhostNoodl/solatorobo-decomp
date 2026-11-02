#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void Task021efc24_Draw(Task021efc24 *self) {
    if (!self->vfunc_28()) {
        return;
    }
    Model_PlayPart(self->unk_3c, 0);
    self->unk_4c->vfunc_20();
    self->unk_50->vfunc_20();
    self->unk_54->vfunc_20();
    ModelViewer_Draw(self->unk_58);
    if (self->unk_5c != NULL) {
        MsgBox_Render(self->unk_5c);
    }
}

}
