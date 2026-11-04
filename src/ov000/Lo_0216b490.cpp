#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {

u32 Rand_GetGlobal(void);

void Lo0216b474_Release(Lo0216b474 *self) {
    LO_FREE_M(self, 0x8);
    self->flags = 0;
    self->state = 2;
    self->model = NULL;
    self->frame = 0;
    self->ratio = 0;
}

void Lo0216b474_Ask(Lo0216b474 *self, s32 want, s32 part22) {
    self->want = want != 0 ? 1 : 0;
    self->part22 = part22 != 0 ? 1 : 0;
    self->asked = 1;
}

}
