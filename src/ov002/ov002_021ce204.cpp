#include "ov002/ov002.h"

extern "C" {

static inline BOOL ov002_ResReady(void) {
    return (ResMgr_IsArchiveLoaded(data_ov002_021ef3e4, data_ov002_021ef3f9, 2) & 1) ? TRUE : FALSE;
}

void Task021ef430_PreUpdate(Task021ef430 *self) {
    void *saved;
    switch (self->state) {
    case 8:
        break;
    case 0xc:
        TaskHost_RequestSwitch(*(void **)&gTaskHost, 0x12, 0);
        self->vfunc_4c();
        break;
    }
    switch (self->unk_4e) {
    case 0:
        ResMgr_LoadArchive(data_ov002_021ef3e4, data_ov002_021ef3f9, 2, 0);
        self->unk_4f = 1;
        self->unk_4e = 1;
    case 1:
        if (!ov002_ResReady()) {
            return;
        }
        self->unk_4e = 2;
    case 2: {
        void *m = Heap_Alloc(0x160);
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
        self->unk_4e = 3;
        break;
    }
    case 3:
        if (self->unk_4d == 0) {
            return;
        }
        self->unk_4d = 0;
        HEAP_PUSH(saved);
        {
            void *p = self->unk_3c;
            if (p != NULL) {
                if (p != NULL) {
                    TexObj_Release((Model *)p);
                    PlttRes_Release((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                self->unk_3c = NULL;
            }
        }
        HEAP_POP(saved);
        if (self->unk_4f != 0) {
            ResMgr_ReleaseArchive(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
        }
        self->unk_4f = 0;
        self->unk_4e = 4;
        break;
    case 4:
        if (self->unk_4c != 0) {
            self->unk_4c = 0;
            self->unk_4e = 0;
        }
        break;
    }
}

}
