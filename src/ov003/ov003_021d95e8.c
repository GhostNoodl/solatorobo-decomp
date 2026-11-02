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

void func_ov003_021d95e8(Ov003Sequence *self, Ov003SeqEntry *entries, u16 length) {
    if (!self->active || entries == NULL) {
        return;
    }
    self->b5 = 0;
    self->b6 = 0;
    self->entries = entries;
    self->length = length;
    self->index = 0;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;
    self->unk_04 = 0;
}

Ov003BytePair func_ov003_021d9644(Ov003Sequence *self) {
    Ov003BytePair r;
    BOOL ok = FALSE;
    if (self->active) {
        if (!self->b5) {
            ok = self->b1;
        }
    }
    if (ok) {
        r.a = self->pairA;
        r.b = self->pairB;
    }
    return r;
}
