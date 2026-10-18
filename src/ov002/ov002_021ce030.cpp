#include "ov002/ov002.h"

extern "C" {

Task50 *func_ov002_021ce030(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x50);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef430;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = 0;
        p->unk_4d = 0;
        p->unk_4e = 3;
        p->unk_4f = 0;
    }
    p->v0x8(0x11, 0x3e8);
    return p;
}

void func_ov002_021ce0b0(Task50 *self) {
    func_020359fc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2, 0);
    self->unk_4f = 1;
}

bool func_ov002_021ce0e0(void) {
    return func_02035bd4(data_ov002_021ef3e4, data_ov002_021ef3f9, 2) & 1;
}

}
