#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ListRow.h"

static inline void Set(UiObj *p, s16 x, s16 y, s16 z) {
    p->posX = x;
    p->posY = y;
    p->posZ = z;
}

extern "C" {

void ListRowText_Draw(ListRowText *self) {
    Lo021cb3a8 *win = self->win;
    if (win == NULL) {
        return;
    }
    Set(win, (self->x >> 12) + ((0x100 - self->width) >> 1), (self->y >> 12) + 0x28, self->z);
    self->win->vfunc_20();
}

void func_ov000_021c3af4(LoBase021ccb54_021ccbe0 *self) {
    self->flags |= 0x40000;
    self->flags |= 0x10;
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->unk_94 = 0;
    self->unk_98 = 0;
    self->unk_9c = 0;
    self->unk_a4 = 0;
    self->unk_a0 = 0;
    self->unk_a8 = 0;
    self->unk_ac = 7;
    self->unk_b0 = 0x80000000;
    self->unk_b4 = 0x80000000;
    self->unk_b8 = 0x80000000;
    self->unk_bc = 0;
    self->unk_c0 = 0xc8000;
    self->unk_c8 = 0x19a;
    self->unk_c4 = 0;
    self->unk_cc = 0;
    self->unk_cd = 0;
    self->unk_ce = 0;
    self->unk_d0 = 0;
    self->unk_d4 = 0;
    self->unk_d8 = 0;
    self->unk_dc = 0;
    self->unk_dd = 0;
    self->unk_de = 0;
    self->unk_df = 0;
    self->unk_e0 = 0x7800;
    self->onDecide = 0;
    self->onCursor = 0;
    self->unk_ec = 0;
    self->unk_f0 = 1;
}

}
