#include "ov000/MessageQueue.h"

extern "C" {

Message *func_ov000_0216f674(MessageQueue *self, s32 id) {
    return MessageQueue_FindById(self, id);
}

void func_ov000_0216f6d0(MessageQueue *self, s32 id, u32 a, u32 b) {
    Message *msg;
    do {
        msg = MessageQueue_Find(self, id, a, b);
        if (msg != NULL) {
            msg->id = 0;
        }
    } while (msg != NULL);
}

void func_ov000_0216f758(MessageQueue *self) {
    if (self->unk_04) {
        return;
    }
    self->unk_04 = 1;
    self->vfunc_0c(2, 1, 0, 0);
}

}

