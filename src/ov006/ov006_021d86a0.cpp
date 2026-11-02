#include "ov006/ov006.h"
#include "ov006/Window.h"

typedef struct ov006_Task021d86a0 {
    u8 unk0[0x34];
    ov006_ListWin *unk34;
    u8 unk38[4];
} ov006_Task021d86a0;

extern "C" {

ov006_ListWin *ov006_Window_Ctor(ov006_ListWin *self);
BOOL func_ov006_021d88f8(UiList *self, UiListItem *item);

void func_ov006_021d86a0(ov006_Task021d86a0 *self, u16 a, char *text) {
    ov006_ListWin *w;
    OV006_DELETE_OBJECT(self->unk34);
    w = (ov006_ListWin *)Heap_Alloc(0x1e8);
    if (w != NULL) {
        w = ov006_Window_Ctor(w);
    }
    self->unk34 = w;
    self->unk34->msgId = a;
    self->unk34->text = text;
    self->unk34->key = 0;
    self->unk34->flags |= 0x4000000;
    self->unk34->onDecide = func_ov006_021d88f8;
    self->unk34->owner = self->unk38;
    self->unk34->vfunc_08();
    self->unk34->posZ = -0x1666;
    self->unk34->flags &= ~2;
}

}
