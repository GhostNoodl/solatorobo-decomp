#include "ov000/TextList.h"

extern "C" {

void List021c6474_Append(TextList *self, ListRow *n) {
    ListRow *p = self->rows;
    if (p == NULL) {
        self->rows = n;
    } else {
        while (p != NULL) {
            if (p->next == NULL) {
                p->next = n;
                n->prev = p;
                break;
            }
            p = p->next;
        }
    }
    self->count++;
}

}
