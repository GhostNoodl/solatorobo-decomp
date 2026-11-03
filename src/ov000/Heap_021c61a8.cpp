#include "ov000/TextList.h"
#include "ov000/HeapScope.h"

extern "C" {

void UiPanel_Release(UiPanel *p);

void Obj021c61a8_Release(TextList *self) {
    ListRow *node;
    HEAP_DELETE(UiPanel *, self->panel, UiPanel_Release(p); Heap_Free(p));
    HEAP_DELETE(TextWin *, self->panelText, p->unk_vf04());
    node = self->rows;
    while (node != NULL) {
        ListRow *next = node->next;
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        gSysState->cur = saved;
        node = next;
    }
}

}
