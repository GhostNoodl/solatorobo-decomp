#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"
#include "ov000/HeapScope.h"
#include "ov000/ListRow.h"

extern "C" {

extern char data_ov000_021cc9bc[];

void func_ov000_021c22d8(ListRow *self) {
    self->index = 0;
    self->x = 0;
    self->y = 0;
    self->z = 0;
    self->width = 0xa0;
    self->height = 0xc;
    self->next = NULL;
    self->prev = NULL;
    self->unk_20 = 0;
    self->unk_24 = 0;
}

void func_ov000_021c2310(ListRow *self) {
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
}

void func_ov000_021c2334(Hud021cca10 *self) {
    self->height = 0xf;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->text = 0;
    self->unk_3c = 0;
    self->str = data_ov000_021cc9bc;
    self->built = 0;
}

void func_ov000_021c2364(Hud021cca10 *self) {
    HEAP_DELETE_MODEL(self->unk_30);
    HEAP_DELETE_MODEL(self->unk_34);
    {
        void *saved = data_02097dd0->cur;
        VObj *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = (VObj *)self->text;
        if (p != NULL) {
            if (p != NULL) {
                p->vfunc_04();
            }
            self->text = 0;
        }
        data_02097dd0->cur = saved;
    }
}

}
