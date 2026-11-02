#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"

extern "C" {

void Heap_Free(void *ptr);

static inline void Obj0214e014_Delete(Model *obj) {
    if (obj != NULL) {
        TexObj_Release(obj);
        PlttRes_Release(&obj->pltt);
        Heap_Free(obj);
    }
}

void func_ov000_0214e008(Lo021caac8 *self) {
    self->unk_e0 = NULL;
}

void func_ov000_0214e014(Lo021caac8 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_e0 != NULL) {
        Obj0214e014_Delete(self->unk_e0);
        self->unk_e0 = NULL;
    }
    data_02097dd0->cur = saved;
}

}
