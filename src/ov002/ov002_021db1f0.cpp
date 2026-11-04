#include "ov002/ov002.h"

extern "C" {

static inline BOOL func_ov002_021db1f0_is5(UiObj *t) {
    return t->state == 5 ? TRUE : FALSE;
}
void CustomizeMenu_Update(Obj021eff74 *self) {
    switch (self->unk_18) {
    case 0:
        self->unk_0c->flags &= ~2;
        self->unk_10->flags &= ~2;
        self->unk_18 = 1;
        break;
    case 1:
        break;
    case 2:
        if (func_ov002_021db1f0_is5(self->unk_0c) && func_ov002_021db1f0_is5(self->unk_10)) {
            self->unk_18 = 3;
        }
        break;
    case 3:
        break;
    }
    self->unk_0c->vfunc_1c();
    self->unk_10->vfunc_1c();
}

}
