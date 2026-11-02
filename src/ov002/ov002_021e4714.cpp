#include "ov002/ov002.h"

extern "C" {

void Ov002LevelTable_Ctor(Ov002LevelTable *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    self->src = NULL;
    self->count = 0;
    self->thresholds = NULL;
    self->label = NULL;
    self->desc = NULL;
}

Ov002LevelTable *Ov002Vt_021f00fc_Dtor(Ov002LevelTable *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    func_ov002_021e4904_inline(self);
    return self;
}

Ov002LevelTable *Ov002Vt_021f00fc_DtorDelete(Ov002LevelTable *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    func_ov002_021e4904_inline(self);
    Heap_Free(self);
    return self;
}

}
