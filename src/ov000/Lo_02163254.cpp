#include "ov000/LoCommon.h"
#include "ov000/MsgBox.h"

extern "C" {

void MsgBox_Release(MsgBox *self) {
    HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
    HEAP_DELETE(MsgRes *, self->res, p->DeletingDtor());
    self->state = 4;
}

}
