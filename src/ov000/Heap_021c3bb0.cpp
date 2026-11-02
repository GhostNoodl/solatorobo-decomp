#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215ec80(void *p);

void func_ov000_021c3bb0(LoBase021ccb54_021ccbe0 *self) {
    ListRow *n;
    HEAP_DELETE_MODEL(self->unk_84);
    HEAP_DELETE_MODEL(self->unk_88);
    HEAP_DELETE_MODEL(self->unk_8c);
    HEAP_DELETE_FN(self->unk_90, func_ov000_0215ec80);
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
