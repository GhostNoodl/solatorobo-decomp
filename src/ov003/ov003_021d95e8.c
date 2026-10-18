#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 id;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
} Ov003SeqEntry;

typedef struct {
    u8 a;
    u8 b;
} Ov003BytePair;

typedef struct {
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pairA;
    u8 pairB;
    u16 unk_04;
    u16 index;
    u16 length;
    Ov003SeqEntry *entries;
} Ov003Sequence;

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
