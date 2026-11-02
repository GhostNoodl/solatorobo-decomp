#include "ov000/LoCommon.h"
#include "ov000/MsgBox.h"

extern "C" {

void MsgBox_Open(MsgBox *self, s32 msgId, char *arcName, char *name, u8 a4) {
    HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
    HEAP_DELETE(MsgRes *, self->res, p->DeletingDtor());
    self->msgId = msgId;
    self->arcName = arcName;
    self->name = name;
    self->unk_10 = a4;
    self->state = 0;
}

}
