#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_021c403c(LoBase021ccb54_021ccbe0 *self, u16 index);

static inline void SelectNode(LoBase021ccb54_021ccbe0 *self, ListRow *target) {
    ListRow *n = self->unk_94;
    s32 i = 0;
    while (n != NULL) {
        if (n == target) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n == NULL) {
        i = -1;
    }
    if (i >= 0) {
        func_ov000_021c403c(self, i);
    } else {
        func_ov000_021c403c(self, 0);
    }
}

void func_ov000_021c414c(LoBase021ccb54_021ccbe0 *self, ListRow *target) {
    ListRow *n = self->unk_94;
    s32 i = 0;
    while (n != NULL) {
        if (n == target) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n == NULL) {
        i = -1;
    }
    if (i >= 0) {
        func_ov000_021c403c(self, i);
    } else {
        func_ov000_021c403c(self, 0);
    }
}


void func_ov000_021c41a4(LoBase021ccb54_021ccbe0 *self, s32 id) {
    ListRow *n;
    for (n = self->unk_94; n != NULL; n = n->next) {
        if (id == n->index) {
            break;
        }
    }
    if (n != NULL) {
        SelectNode(self, n);
    } else {
        func_ov000_021c403c(self, 0);
    }
}

}
