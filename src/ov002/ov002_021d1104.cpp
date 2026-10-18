#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1104(void) {
}

void func_ov002_021d1108(Task50 *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
}

Task50 *func_ov002_021d1144(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x70);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef71c;
        MIi_CpuClear32(-1, (u8 *)p + 0x3c, 0x20);
        FIELD(p, 0x5c, s32) = 0;
        FIELD(p, 0x60, s32) = -1;
        FIELD(p, 0x64, s32) = 0;
        FIELD(p, 0x68, u8) = 0;
        FIELD(p, 0x69, u8) = 0;
    }
    p->v0x8(0x16, 0x64);
    return p;
}

Task50 *func_ov002_021d11cc(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef71c;
    func_ov002_021e916c();
    TaskBase_dtor(self);
    return self;
}

Task50 *func_ov002_021d1208(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef71c;
    func_ov002_021e916c();
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021d124c(Task50 *self) {
    func_ov000_02173648(self);
}

}
