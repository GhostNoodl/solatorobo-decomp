#include "ov000/LoCommon.h"
#include "ov000/MsgBox.h"

extern "C" {

void func_ov000_02163254(MsgBox *self) {
    HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
    HEAP_DELETE(MsgRes *, self->res, p->DeletingDtor());
    self->state = 4;
}

}
