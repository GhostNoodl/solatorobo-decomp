#include "ov011/ov011.h"

extern "C" {

#pragma force_active on
void func_ov011_02204ff0(Ov011Actor *self) {
    Ov011Actor *pl;
    u16 pct;
    self->unk_93_4 = 1;
    if (self->unk_50[0] == 0) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (Ov011Actor *)func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    self->unk_90 = pl->id;
    if (FLD(u8, self->unk_40, 0x13) != 1) {
        return;
    }
    pct = self->unk_50[0] * 100 / self->unk_50[1];
    switch (FLD(u16, self, 0xb4)) {
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
            FLD(u16, self, 0xb4) = 2;
        } else if (FLD(u16, self, 0xb4) == 0) {
            self->unk_b6 = (pct >> 2) + 100;
            FLD(u16, self, 0xb4)++;
        } else {
            self->unk_b6 = (pct >> 2) + 0x78;
            FLD(u16, self, 0xb4) = 0;
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
            FLD(u16, self, 0xb4)++;
        } else {
            FLD(u16, self, 0xb4) = 1;
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
        FLD(u16, self, 0xb4) = 0;
        break;
    }
}
#pragma force_active reset


extern u8 *data_02097d48;
void func_02043d9c(void *p);
void func_ov003_021d16cc(void *p);

#pragma force_active on
void func_ov011_022051b8(void *self) {
    u8 v = data_02097d48[0x8b3];
    func_02043d9c(data_02097d48 + 0x8b0);
    (*(u8 **)((u8 *)self + 0x38))[0xc1] = v;
    func_ov003_021d16cc(self);
}
#pragma force_active reset
}
