#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct Node02159e40 {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    VObj *unk_1c;
    VObj *unk_20;
    s32 unk_24;
    struct Node02159e40 *prev;
    struct Node02159e40 *next;
} Node02159e40;

typedef struct {
    u8 pad[0x94];
    Node02159e40 *head;
    u8 pad98[4];
    s16 count;
} Owner02159e40;

extern "C" {

static inline void Node02159e40_Delete(Node02159e40 *o) {
    HEAP_DELETE_VOBJ(o->unk_1c);
    HEAP_DELETE_VOBJ(o->unk_20);
    o->unk_00 = 0;
    o->unk_04 = 0;
    o->unk_06 = 0;
    o->unk_08 = 0xffff;
    o->unk_0a = 0xffff;
    o->unk_0c = 0;
    o->unk_10 = 0;
    o->unk_14 = 0;
    o->unk_18 = 0;
    o->unk_1c = 0;
    o->unk_20 = 0;
    o->unk_24 = 0;
    o->prev = 0;
    o->next = 0;
    func_0203de1c(o);
}

void func_ov000_02159e40(Owner02159e40 *self, Node02159e40 *node) {
    if (node == self->head) {
        self->head = node->next;
        if (self->head != NULL) {
            self->head->prev = NULL;
        }
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    self->count--;
    {
        void *saved = data_02097dd0->current;
        Node02159e40 *p;
        data_02097dd0->current = data_02097dd0->unk_08;
        p = node;
        if (p != NULL) {
            if (p != NULL) {
                Node02159e40_Delete(p);
            }
        }
        data_02097dd0->current = saved;
    }
}

}
