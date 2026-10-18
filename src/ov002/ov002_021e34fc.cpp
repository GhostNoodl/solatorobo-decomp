#include "ov002/ov002.h"

extern "C" {

typedef struct Node021e34fc {
    u8 unk_00[0x28];
    struct Node021e34fc *next;
    struct Node021e34fc *prev;
} Node021e34fc;

static inline void ov002_Node_Unlink(Node021e34fc *node) {
    Node021e34fc *nx = node->next;
    Node021e34fc *pr = node->prev;
    if (pr != NULL) {
        pr->next = nx;
    }
    if (nx != NULL) {
        nx->prev = pr;
    }
}

void func_ov002_021e34fc(void *self, s32 (*cmp)(void *, void *)) {
    Node021e34fc *head = FIELD(self, 0x94, Node021e34fc *);
    Node021e34fc *p;
    Node021e34fc *next;
    Node021e34fc *n;
    Node021e34fc *cur;
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
    FIELD(self, 0x94, Node021e34fc *) = head;
    func_ov000_021c4738(self, FIELD(self, 0xa8, void *));
}

}
