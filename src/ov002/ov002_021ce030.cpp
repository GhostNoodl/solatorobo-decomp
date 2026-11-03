#include "ov002/ov002.h"

extern "C" {

Task021ef430 *Task021ef430_New(void) {
    Task021ef430 *p = (Task021ef430 *)Heap_Alloc(0x50);
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
    p->vfunc_08(0x11, 0x3e8);
    return p;
}

void Task021ef430_Load(Task021ef430 *self) {
    ResMgr_LoadArchive(data_ov002_021ef3e4, data_ov002_021ef3f9, 2, 0);
    self->unk_4f = 1;
}

bool Task021ef430_IsLoaded(void) {
    return ResMgr_IsArchiveLoaded(data_ov002_021ef3e4, data_ov002_021ef3f9, 2) & 1;
}

}
