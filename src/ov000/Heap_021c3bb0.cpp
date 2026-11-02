#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void UiPanel_Release(void *p);

void LoBase021ccb54_021ccbe0_Release(LoBase021ccb54_021ccbe0 *self) {
    ListRow *n;
    HEAP_DELETE_MODEL(self->unk_84);
    HEAP_DELETE_MODEL(self->unk_88);
    HEAP_DELETE_MODEL(self->unk_8c);
    HEAP_DELETE_FN(self->unk_90, UiPanel_Release);
    n = self->unk_94;
    while (n != NULL) {
        ListRow *next = n->next;
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (n != NULL) {
            if (n != NULL) {
                n->vfunc_04();
            }
        }
        data_02097dd0->cur = saved;
        n = next;
    }
    self->unk_94 = NULL;
}

}
