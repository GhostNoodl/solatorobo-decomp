#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void LoBase021ccb54_021ccbe0_AppendRow(LoBase021ccb54_021ccbe0 *self, ListRow *n) {
    ListRow *p = self->unk_94;
    if (p == NULL) {
        self->unk_94 = n;
    } else {
        while (p != NULL) {
            if (p->next == NULL) {
                break;
            }
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
    self->unk_98++;
}

ListRow *LoBase021ccb54_021ccbe0_FindRow(LoBase021ccb54_021ccbe0 *self, s32 id) {
    ListRow *n;
    for (n = self->unk_94; n != NULL; n = n->next) {
        if (id == n->index) {
            return n;
        }
    }
    return n;
}

}
