#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d2ef4(void) {
}

void func_ov002_021d2ef8(Task50 *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->v0x20();
    }
    if (TASK_VOBJ(self, 0x48) != NULL) {
        TASK_VOBJ(self, 0x48)->v0x20();
    }
}

Task50 *func_ov002_021d2f64(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0xd0);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef91c;
        func_ov002_021e4714((u8 *)p + 0x94);
        func_ov002_021e49a0((u8 *)p + 0xac);
        p->v0x58();
    }
    p->v0x8(0x19, 0xc8);
    return p;
}

}
