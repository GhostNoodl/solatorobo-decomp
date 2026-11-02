#include "ov000/MsgBox.h"

extern "C" {

void MsgBox_Init(MsgBox *self) {
    self->arcName = NULL;
    self->name = NULL;
    self->unk_10 = 0;
    self->msgId = 0;
    self->numLines = 0;
    self->text = NULL;
    self->win = NULL;
    self->res = NULL;
    self->state = 4;
}

}
