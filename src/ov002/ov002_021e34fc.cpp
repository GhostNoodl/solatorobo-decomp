#include "ov002/ov002.h"

extern "C" {

static inline void ov002_Node_Unlink(ListRow *node) {
    ListRow *nx = node->next;
    ListRow *pr = node->prev;
    if (pr != NULL) {
        pr->next = nx;
    }
    if (nx != NULL) {
        nx->prev = pr;
    }
}

// Insertion-sorts the rows of a row list by cmp, then reselects row unk_a8.
void LoBase021ccb54_021ccbe0_SortRows(LoBase021ccb54_021ccbe0 *self, s32 (*cmp)(void *, void *)) {
    ListRow *head = self->unk_94;
    ListRow *p;
    ListRow *next;
    ListRow *n;
    ListRow *cur;
    if (head == NULL) {
        return;
    }
    for (cur = head->next; cur != NULL; cur = next) {
        p = cur->prev;
        next = cur->next;
        while (p != NULL) {
            if (cmp(p, cur) > 0) {
                break;
            }
            p = p->prev;
        }
        ov002_Node_Unlink(cur);
        if (p != NULL) {
            n = p->next;
            if (n != NULL) {
                n->prev = cur;
            }
            cur->prev = p;
            cur->next = n;
            p->next = cur;
        } else {
            head->prev = cur;
            cur->prev = NULL;
            cur->next = head;
            head = cur;
        }
    }
    self->unk_94 = head;
    func_ov000_021c4738(self, self->unk_a8);
}

}
