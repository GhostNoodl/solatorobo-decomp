#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char gCommonTextPath[];
extern void *ArcPath_Menu;
extern void *ArcPath_MenuBattle;
extern void *gTaskHost;
extern u8 Ov000Vt_021cb940_vtbl[];
extern u8 Ov000Vt_021cb6d0_vtbl[];
void BufferList_Run(void *p, s32 a);
BOOL TaskHost_Update(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

void *Ov000Vt_021cb940_DtorDelete(ListBuffer *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb940_vtbl);
    ListBuffer021cb940_Release(self);
    VOBJ_SET_VTABLE(self, Ov000Vt_021cb6d0_vtbl);
    if ((self->flags & 0x20) && self->unk_0c != 0) {
        Heap_FreeHi((void *)self->unk_0c);
    }
    self->flags = 0;
    self->priority = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->prev = NULL;
    self->next = NULL;
    Heap_Free(self);
    return self;
}

}
