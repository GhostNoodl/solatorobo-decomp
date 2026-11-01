#include "ov011/ov011.h"

extern "C" {

#pragma force_active on
void func_ov011_02204ff0(Ov011Act7da4 *self) {
    Ov011Actor *pl;
    u16 pct;
    self->unk_93_4 = 1;
    if (self->hp[0] == 0) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov011Actor *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->target = pl->id;
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    pct = self->hp[0] * 100 / self->hp[1];
    switch (self->unk_b4) {
    case 0:
    case 1:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        if (pct <= 0x46) {
            self->unk_40->flags |= 0x20000;
        } else {
            self->unk_40->flags |= 0x4000;
        }
        if (pct <= 0x4b) {
            self->unk_b6 = (pct >> 2) + 100;
            self->unk_b4 = 2;
        } else if (self->unk_b4 == 0) {
            self->unk_b6 = (pct >> 2) + 100;
            self->unk_b4++;
        } else {
            self->unk_b6 = (pct >> 2) + 0x78;
            self->unk_b4 = 0;
        }
        break;
    case 2:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        self->unk_40->flags |= 0x8000;
        self->unk_b6 = (pct >> 2) + 100;
        if (pct <= 0x28) {
            self->unk_b4++;
        } else {
            self->unk_b4 = 1;
        }
        break;
    case 3:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        self->unk_40->flags |= 0x10000;
        self->unk_b6 = (pct >> 2) + 0x5a;
        self->unk_b4 = 0;
        break;
    }
}
#pragma force_active reset


extern u8 *data_02097d48;
int func_02043d9c(void *p);
u16 func_ov003_021d16cc(void *p);

#pragma force_active on
void func_ov011_022051b8(Ov011Act7da4 *self) {
    u8 v = data_02097d48[0x8b3];
    func_02043d9c(data_02097d48 + 0x8b0);
    self->unk_38->unk_c1 = v;
    func_ov003_021d16cc(self);
}
#pragma force_active reset
}
