#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {
void Win021c4460_Update(void *self);
void func_ov000_021c4b00(void *self);
void func_ov000_0215f330(UiLabel *p);
void func_ov000_021c4c10(void *self);

void func_ov000_021c56c0(Lo021ccb54 *self) {
    s32 i;
    ListRow *n;

    if (self->state == 2) {
        if (self->hidden) {
            self->state = 1;
        }
        Win021c4460_Update(self);
        func_ov000_021c4b00(self);
        self->unk_d4++;
        if (self->unk_d4 < 20) {
            self->unk_d8 += LO_FX_MUL(0x6000 - self->unk_d8, 0x19a);
        } else if (self->unk_d4 >= 50) {
            self->unk_d4 = 0;
            self->unk_d8 = 0;
        } else {
            self->unk_d8 += LO_FX_MUL(0 - self->unk_d8, 0xcd);
        }
        func_ov000_0215f330(self->unk_f4);
        func_ov000_0215f330(self->unk_f8);
        func_ov000_0215f330(self->unk_fc);
    }
    i = 0;
    for (n = self->unk_94; n != NULL; n = n->next) {
        BOOL on = FALSE;
        switch (self->unk_df) {
        case 0:
            on = i >= self->unk_9c && i <= self->unk_9c + (self->rows - 1);
            break;
        case 1:
            on = i >= self->unk_9c && i <= self->unk_9c + self->rows;
            break;
        case 2:
            on = i >= self->unk_9c - 1 && i <= self->unk_9c + self->rows - 1;
            break;
        }
        if (on) n->shown = 1; else n->shown = 0;
        n->focus = 0;
        n->vfunc_08();
        i++;
    }
    if (self->unk_a0 != NULL) {
        self->unk_a0->focus = 1;
    }
    func_ov000_021c4c10(self);
}
}
