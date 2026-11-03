#include "ov002/ov002.h"

extern "C" {

// The onDecide callback of Obj021eff74's list (Obj021eff74_Init; the list's owner is the
// Obj021eff74): sets bit 1 of its unk_1c when called without an item, bit 0 with one.
int func_ov002_021dac8c(UiList *self, UiListItem *item) {
    Obj021eff74 *p = (Obj021eff74 *)self->owner;
    if (item == NULL) {
        p->unk_1c |= 2;
        return 1;
    }
    p->unk_1c |= 1;
    return 1;
}

}
