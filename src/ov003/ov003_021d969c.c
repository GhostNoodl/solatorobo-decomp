#include "types.h"
#include "ov003/Sequence.h"


static inline void Ov003Sequence_Step(Ov003Sequence *self) {
    self->index++;
    if (self->index == self->length) {
        self->index = 0;
    }
    self->unk_04 = 0;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;
}

void Ov003Sequence_Signal(Ov003Sequence *self, u8 v) {
    if (!self->active) {
        return;
    }
    if (!self->b2) {
        return;
    }
    if (self->b3) {
        return;
    }
    self->b3 = 1;
    self->b4 = v;
}
