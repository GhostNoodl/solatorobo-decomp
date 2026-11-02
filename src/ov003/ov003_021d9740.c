#include "types.h"
#include "ov003/Sequence.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

static inline void Ov003Sequence_Step(Ov003Sequence *self) {
    self->index++;
    if (self->index == self->length) {
        self->index = 0;
    }
    self->b1 = 0;
    self->unk_04 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;
}

void Ov003Sequence_Update(Ov003Sequence *self) {
    if (!self->active) {
        return;
    }
    Ov003Sequence_Step(self);
}

void func_ov003_021d9740(Ov003Sequence *self, u8 id) {
    Ov003SeqEntry e;
    if (!self->active) {
        return;
    }
    do {
        Ov003Sequence_Step(self);
        e = self->entries[self->index];
    } while (id != e.id);
}

void func_ov003_021d97fc(Ov003Sequence *self, u8 v) {
    if (self->active) {
        self->b5 = v;
        self->b6 = v;
    }
}

void func_ov003_021d982c(Ov003Sequence *self, u8 v) {
    if (self->active) {
        self->b6 = v;
    }
}

BOOL Ov003Sequence_HasEntries(Ov003Sequence *self, Ov003SeqEntry *entries) {
    BOOL r = FALSE;
    if (self->active && entries != NULL) {
        if (self->entries == entries) {
            r = TRUE;
        }
    }
    return r;
}

BOOL func_ov003_021d9878(Ov003Sequence *self) {
    BOOL r = FALSE;
    if (self->active) {
        if (!self->b5) {
            r = self->b1;
        }
    }
    return r;
}

BOOL func_ov003_021d98a0(Ov003Sequence *self) {
    return self->active ? self->b6 : 0;
}

BOOL Ov003Vec_Equal(Ov003Vec *a, Ov003Vec *b) {
    BOOL r = FALSE;
    if (a != NULL && b != NULL) {
        r = (a->x == b->x && a->y == b->y && a->z == b->z);
    }
    return r;
}
