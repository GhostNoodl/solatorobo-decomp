#include "ov002/ov002.h"

extern "C" {

void Ov002StageFile_DtorBase(Ov002StageFile *self) {
    Ov002StageFile_Free(self);
}

void Ov002StageFile_Free(Ov002StageFile *self) {
    {
        void *saved;
        HEAP_PUSH(saved);
        if (((void *)self->links) != NULL) {
            Heap_FreeArray(((void *)self->links));
            self->links = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (((void *)self->unk_44) != NULL) {
            Heap_FreeArray(((void *)self->unk_44));
            self->unk_44 = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (((void *)self->unk_48) != NULL) {
            Heap_FreeArray(((void *)self->unk_48));
            self->unk_48 = NULL;
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (((void *)self->unk_4c) != NULL) {
            Heap_FreeArray(((void *)self->unk_4c));
            self->unk_4c = NULL;
        }
        HEAP_POP(saved);
    }
    self->linkCount = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
}

}
