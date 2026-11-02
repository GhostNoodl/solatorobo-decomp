#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d01cc(Task021ef79c *self) {
    if (self->vfunc_28() == 0) {
        return;
    }
    TASK_VOBJ(self, 0x3c)->vfunc_20();
    self->unk_40->vfunc_20();
}

Task021efa1c *func_ov002_021d020c(void) {
    Task021efa1c *p = (Task021efa1c *)Heap_Alloc(0x44);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efa1c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
    }
    p->vfunc_08(0x14, 0x64);
    return p;
}

}
