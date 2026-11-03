#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"



extern "C" {

static inline void Ent02154c34_Dtor(UiListItem *e) {
    LO_FREE_V(e, 0x1c);
    LO_FREE_V(e, 0x20);
    e->name = 0;
    e->index = 0;
    e->id = 0;
    e->unk_08 = 0xffff;
    e->unk_0a = 0xffff;
    e->unk_0c = 0;
    e->unk_10 = 0;
    e->unk_14 = 0;
    e->unk_18 = 0;
    e->label = NULL;
    e->unk_20 = NULL;
    e->unk_24 = 0;
    e->prev = 0;
    e->next = NULL;
}

static inline void Sub02154c34_Dtor(UiPanel *s) {
    LO_FREE_M(s, 0x28);
    s->flags = 0;
    s->x = 0;
    s->y = 0;
    s->z = 0;
    s->dy = 0;
    s->dx = 0;
    s->width = 0x80000;
    s->height = 0xf000;
    s->unk_20 = 0;
    s->unk_24 = 0;
    s->model = NULL;
}


void UiList_Release(UiList *self) {
    UiListItem *e = self->items;
    while (e != NULL) {
        UiListItem *next = e->next;
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (e != NULL) {
            UiListItem *p = e;
            if (p != NULL) {
                Ent02154c34_Dtor(p);
                Heap_Free(p);
            }
            e = NULL;
        }
        LO_HEAP_POP(saved);
        e = next;
    }
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (self->panel != NULL) {
            UiPanel *p = self->panel;
            if (p != NULL) {
                Sub02154c34_Dtor(p);
                Heap_Free(p);
            }
            self->panel = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_M(self, 0xb8);
    LO_FREE_M(self, 0xbc);
    LO_FREE_M(self, 0xb4);
}

}
