#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

// Appends an item, as UiList_AddItem without the item's unk_08 / unk_0c.
void Lo021cb5a8_AddItem(Lo021cb5a8 *self, s32 id, const char *name) {
    UiListItem *n = (UiListItem *)Heap_Alloc(sizeof(UiListItem));
    UiListItem *t;
    UiListItem *nx;
    s16 index;
    if (n) {
        n->name = NULL;
        n->index = 0;
        n->id = 0;
        n->unk_08 = 0xffff;
        n->unk_0a = 0xffff;
        n->unk_0c = 0;
        n->unk_10 = 0;
        n->unk_14 = 0;
        n->unk_18 = 0;
        n->label = NULL;
        n->unk_20 = NULL;
        n->unk_24 = 0;
        n->prev = NULL;
        n->next = NULL;
    }
    n->name = name;
    index = self->itemCount;
    self->itemCount = index + 1;
    n->index = index;
    n->id = id;
    t = self->items;
    if (t == NULL) {
        self->items = n;
        self->topItem = n;
        return;
    }
    for (nx = t->next; nx != NULL; nx = nx->next) {
        t = nx;
    }
    t->next = n;
    n->prev = t;
}

}
