#include "ov002/ov002.h"

extern "C" {

Task50 *func_ov002_021d397c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x50);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef81c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = 0;
    }
    p->v0x8(0xb, 0x64);
    return p;
}

}
