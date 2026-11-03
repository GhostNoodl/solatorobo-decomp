#include "ov000/MessageQueue.h"

extern "C" {

void func_ov000_0216f23c(BufferList *list, BOOL mode);

void func_ov000_0216f814(MessageQueue *self) {
    func_ov000_0216f23c(&self->list, 1);
}

// The body of the TimedBuffer021cb920 constructor (func_ov000_021814dc, ov002's func_ov002_021ccda0).
void func_ov000_0216f828(TimedBuffer021cb920 *self) {
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = NULL;
}

}
