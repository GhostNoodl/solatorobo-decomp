#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e4904(Ov002LevelTable *self) {
    func_ov002_021e4904_inline(self);
}

u32 func_ov002_021e4960(Ov002LevelTable *self, s32 val) {
    u32 n = self->count;
    s32 *arr;
    u32 i;
    if (n == 0 || (arr = self->thresholds) == NULL) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > val) {
            return i;
        }
    }
    return i;
}

void func_ov002_021e49a0(Ov002StrTable *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    self->src = NULL;
    self->count = 0;
    self->pairs = NULL;
}

Ov002StrTable *Ov002Vt_021f00ec_Dtor(Ov002StrTable *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->pairs != NULL) {
            Heap_FreeArray(self->pairs);
            self->pairs = NULL;
        }
        HEAP_POP(saved);
    }
    return self;
}

Ov002StrTable *Ov002Vt_021f00ec_DtorDelete(Ov002StrTable *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->pairs != NULL) {
            Heap_FreeArray(self->pairs);
            self->pairs = NULL;
        }
        HEAP_POP(saved);
    }
    Heap_Free(self);
    return self;
}

}
