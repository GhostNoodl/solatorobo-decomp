#include "ov000/VObj.h"
#include "ov000/LoTicker.h"
#include "ov000/HeapScope.h"
#include "nitro/mi.h"

extern "C" {

static inline void Res_Release(LoTextHolder *r) {
    if (r->win != NULL) {
        if (--r->count == 0) {
            HEAP_DELETE(TextWin *, r->win, p->unk_vf04());
        }
    }
}

void func_ov000_0216bcbc(LoTicker *self) {
    s32 i;
    LoTickerSlot *slot;
    for (i = 0; i < 16; i++) {
        self->msgs[i].kind = -1;
        self->msgs[i].text[0] = 0;
    }
    self->read = 0;
    self->write = 0;
    slot = self->slots;
    for (i = 0; i < 6; i++, slot++) {
        if (slot->flags & 1) {
            Res_Release(&self->res[data_ov000_021c9bb4[slot->kind].a]);
            Res_Release(&self->res[data_ov000_021c9bb4[slot->kind].b]);
            HEAP_DELETE(TextWin *, slot->text, p->unk_vf04());
        }
    }
    self->head = NULL;
    self->tail = NULL;
    MI_CpuFill8(self->slots, 0, sizeof(self->slots));
    self->cur = NULL;
}

}
