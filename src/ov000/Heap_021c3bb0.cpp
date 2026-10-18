#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

class Node021c3bb0 : public VObj {
public:
    u8 pad04[0x24];
    Node021c3bb0 *next;
};

typedef struct {
    u8 pad[0x84];
    void *unk_84;
    void *unk_88;
    void *unk_8c;
    void *unk_90;
    Node021c3bb0 *head;
} Obj021c3bb0;

extern "C" {

void func_ov000_0215ec80(void *p);

void func_ov000_021c3bb0(Obj021c3bb0 *self) {
    Node021c3bb0 *n;
    HEAP_DELETE_MODEL(self->unk_84);
    HEAP_DELETE_MODEL(self->unk_88);
    HEAP_DELETE_MODEL(self->unk_8c);
    HEAP_DELETE_FN(self->unk_90, func_ov000_0215ec80);
    n = self->head;
    while (n != NULL) {
        Node021c3bb0 *next = n->next;
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (n != NULL) {
            if (n != NULL) {
                n->vfunc_04();
            }
        }
        data_02097dd0->current = saved;
        n = next;
    }
    self->head = NULL;
}

}
