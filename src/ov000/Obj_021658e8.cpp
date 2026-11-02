#include "ov000/HeapScope.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"

extern "C" {

void func_ov000_021658e8(Lo021cb6b0 *self) {
    s32 i;
    if (self->unk_30 == NULL) {
        return;
    }
    for (i = 0; i < self->unk_30->slotCount; i++) {
        if (self->unk_30->slots[i].list != NULL) {
            Heap_FreeHi(self->unk_30->slots[i].list);
            self->unk_30->slots[i].list = NULL;
        }
    }
    if (self->unk_30->slots != NULL) {
        Heap_FreeHi(self->unk_30->slots);
        self->unk_30->slots = NULL;
    }
    if (self->unk_30->nodes != NULL) {
        Heap_FreeHi(self->unk_30->nodes);
        self->unk_30->nodes = NULL;
    }
    if (self->unk_30->items != NULL) {
        Heap_FreeHi(self->unk_30->items);
        self->unk_30->items = NULL;
    }
    if (self->unk_30->parts != NULL) {
        Heap_FreeHi(self->unk_30->parts);
        self->unk_30->parts = NULL;
    }
    HEAP_DELETE(PlttRes *, self->unk_30->pltt, func_02041278(p); Heap_Free(p));
    if (self->unk_30 != NULL) {
        Heap_FreeHi(self->unk_30);
        self->unk_30 = NULL;
    }
}
}
