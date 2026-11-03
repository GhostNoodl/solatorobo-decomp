#include "ov002/ov002.h"

extern "C" {

void Task021ef430_Start(Task021ef430 *self) {
    void *m;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        char *nm = data_ov002_021ef3f9;
        char *file = data_ov002_021ef3e4;
        if (nm) {
            PlttRes_Init_02041218((PlttRes *)((u8 *)m + 0x88));
            TexObj_Init((Model *)m, nm, 0);
            STD_CopyString((char *)((u8 *)m + 0x2c), file);
        }
    }
    self->unk_3c = (Model *)m;
    TexObj_SetRes((Model *)self->unk_3c, ResList_FindType2(ResMgr_GetArchiveList(data_ov002_021ef3e4, data_ov002_021ef3f9, 2), data_ov002_021ef3f9));
    self->unk_3c->flags |= 2;
    TexObj_SelectImage((Model *)self->unk_3c, 0, 0);
    {
        Model *p = self->unk_3c;
        p->x = 0;
        p->y = 0;
    }
    self->unk_3c->unk_150 = -0x1fe66;
    self->parent = NULL;
    TaskList_Insert(self);
    self->unk_4c = 0;
    self->unk_4d = 0;
    self->unk_4e = 3;
}

}
