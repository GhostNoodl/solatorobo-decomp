#include "ov000/VObj.h"

typedef struct Node021c6474 {
    u8 unk_00[0x28];
    struct Node021c6474 *next;
    struct Node021c6474 *prev;
} Node021c6474;

typedef struct {
    u8 unk_00[0x84];
    Node021c6474 *head;
    u8 unk_88[0x8];
    s32 count;
} List021c6474;

extern "C" {

void func_ov000_021c6474(List021c6474 *self, Node021c6474 *n) {
    Node021c6474 *p = self->head;
    if (p == NULL) {
        self->head = n;
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
