#include "ov002/ov002.h"

extern "C" {

Task021ef81c *ComposeMenu_New(void) {
    Task021ef81c *p = (Task021ef81c *)Heap_Alloc(0x50);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021ef81c_vtbl;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = 0;
    }
    p->vfunc_08(0xb, 0x64);
    return p;
}

}
