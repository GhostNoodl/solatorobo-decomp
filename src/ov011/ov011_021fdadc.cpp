#include "ov011/ov011.h"

extern "C" {

struct Ov011Link {
    u32 unk_00;
    Ov011Link *next;
};

Ov011Link *func_ov011_021fdadc(Ov011Link *head, Ov011Link *n) {
    Ov011Link *cur;
    Ov011Link *prev;
    if (head == NULL || n == NULL) {
        return head;
    }
    cur = head;
    prev = NULL;
    while (cur != NULL) {
        if (cur == n) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}
}
