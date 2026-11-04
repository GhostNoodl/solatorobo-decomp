#include "ov000/MessageQueue.h"

extern "C" {

void BufferList_Run(BufferList *list, BOOL mode);

void MessageQueue_Draw(MessageQueue *self) {
    BufferList_Run(&self->list, 1);
}

// The body of the TimedBuffer021cb920 constructor (Field_Create, ov002's Ov002Session_Create).
void func_ov000_0216f828(TimedBuffer021cb920 *self) {
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = NULL;
}

}
