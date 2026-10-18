#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022169c0[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_ov000_02199ba0(void *p);

void func_ov014_022054f8(void) {
}

void func_ov014_022054fc(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(u8, self, 0xe4) = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->unk_38;
    Ov014_VecCopyYZ(&FLD(Ov014Vec, self, 0xd4), &FLD(Ov014Vec, m, 0xa8));
    FLD(Ov014Vec, m, 0xa8) = FLD(Ov014Vec, data_ov014_022169c0, 0x14);
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_022055ac(Ov014Actor *self) {
    Ov014Sub38 *m;
    s32 s;
    if (!func_ov000_02199ba0(FLD(void *, self, 0x4c))) {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (self->unk_40->state != 0) {
        return;
    }
    if (FLD(s32, self, 0xe0) < FLD(s32, self, 0xd4)) {
        FLD(s32, self, 0xe0) += 0xcd;
    } else {
        FLD(s32, self, 0xe0) = FLD(s32, self, 0xd4);
        func_ov000_02198360(self->unk_40, 0xb, 0);
    }
    m = self->unk_38;
    s = FLD(s32, self, 0xe0);
    FLD(Ov014Vec, m, 0xa8).x = s;
    FLD(Ov014Vec, m, 0xa8).y = s;
    FLD(Ov014Vec, m, 0xa8).z = s;
}

}
