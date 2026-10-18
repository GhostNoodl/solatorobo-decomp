#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d01cc(Task50 *self) {
    if (self->v0x28() == 0) {
        return;
    }
    TASK_VOBJ(self, 0x3c)->v0x20();
    self->unk_40->v0x20();
}

Task50 *func_ov002_021d020c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x44);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efa1c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
    }
    p->v0x8(0x14, 0x64);
    return p;
}

}
