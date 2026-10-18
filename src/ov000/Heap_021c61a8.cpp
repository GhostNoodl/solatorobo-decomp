#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct Node021c61a8 : public VObj {
    u8 pad_04[0x24];
    struct Node021c61a8 *unk_28;
} Node021c61a8;

typedef struct {
    u8 pad_00[0x84];
    Node021c61a8 *unk_84;
    u8 pad_88[0x14];
    void *unk_9c;
    VObj *unk_a0;
} Obj021c61a8;

extern "C" {

void func_ov000_0215ec80(void *p);

void func_ov000_021c61a8(Obj021c61a8 *self) {
    Node021c61a8 *node;
    HEAP_DELETE_FN(self->unk_9c, func_ov000_0215ec80);
    HEAP_DELETE_VOBJ(self->unk_a0);
    node = self->unk_84;
    while (node != NULL) {
        Node021c61a8 *next = node->unk_28;
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        data_02097dd0->current = saved;
        node = next;
    }
}

}
