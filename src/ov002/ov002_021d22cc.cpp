#include "ov002/ov002.h"

extern "C" {

Task021ef99c *func_ov002_021d22cc(void) {
    Task021ef99c *p = (Task021ef99c *)Heap_Alloc(0x118);
    if (p != NULL) {
        int i;
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef99c;
        __cxa_vec_ctor(p->unk_4c, 7, 0x18, (void (*)(void *))func_ov002_021e4714, (void (*)(void *))Ov002Vt_021f00fc_Dtor);
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = NULL;
        for (i = 0; i < 7; i++) {
            func_ov002_021e4904(&p->unk_4c[i]);
        }
        MI_CpuFill8(p->unk_f4, 0, 0x20);
        p->unk_114 = 0;
    }
    p->vfunc_08(0x18, 0x64);
    return p;
}

BOOL func_ov002_021d2390(UiObj *self, ListRow *arg) {
    Task021ef99c *owner = (Task021ef99c *)self->owner;
    if (arg != NULL) {
        u16 i = arg->index;
        if (i <= 7) {
            void *str = owner->unk_4c[i].desc;
            if (owner->unk_40 != NULL) {
                func_ov000_0215bb14(owner->unk_40, str);
                owner->unk_40->vfunc_70();
            }
            func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
        }
    }
    return TRUE;
}

}
