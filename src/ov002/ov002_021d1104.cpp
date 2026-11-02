#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1104(void) {
}

void func_ov002_021d1108(Task021ef89c *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
}

Task021ef71c *func_ov002_021d1144(void) {
    Task021ef71c *p = (Task021ef71c *)Heap_Alloc(0x70);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef71c;
        MIi_CpuClear32(-1, (u8 *)p + 0x3c, 0x20);
        p->unk_5c = 0;
        p->unk_60 = -1;
        p->unk_64 = 0;
        p->unk_68 = 0;
        p->unk_69 = 0;
    }
    p->vfunc_08(0x16, 0x64);
    return p;
}

Task021ef71c *Ov002TaskVt_021ef71c_Dtor(Task021ef71c *self) {
    *(VFunc **)self = data_ov002_021ef71c;
    func_ov002_021e916c();
    TaskBase_dtor(self);
    return self;
}

Task021ef71c *Ov002TaskVt_021ef71c_DtorDelete(Task021ef71c *self) {
    *(VFunc **)self = data_ov002_021ef71c;
    func_ov002_021e916c();
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021d124c(Task021ef71c *self) {
    func_ov000_02173648(self);
}

}
