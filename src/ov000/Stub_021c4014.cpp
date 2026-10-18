#include "ov000/VObj.h"

typedef struct Node021c4014 {
    u8 unk_00[4];
    s32 id;
    u8 unk_08[0x20];
    struct Node021c4014 *next;
    struct Node021c4014 *prev;
} Node021c4014;

typedef struct {
    u8 unk_00[0x94];
    Node021c4014 *head;
    s32 count;
} List021c4014;

extern "C" {

void func_ov000_021c3fd4(List021c4014 *self, Node021c4014 *n) {
    Node021c4014 *p = self->head;
    if (p == NULL) {
        self->head = n;
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
    self->count++;
}

Node021c4014 *func_ov000_021c4014(void *self, s32 id) {
    Node021c4014 *n;
    for (n = *(Node021c4014 **)((u8 *)self + 0x94); n != NULL; n = n->next) {
        if (id == n->id) {
            return n;
        }
    }
    return n;
}

}
