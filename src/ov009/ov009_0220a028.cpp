#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0219864c(Ov009Sub48 *p, s32 a, s32 b);

void func_ov009_0220a028(Ov009Actor *self) {
    Ov009Actor *a;
    Ov009Sub44 *s44;
    func_ov003_021d112c(self);
    self->unk_ea_6 = 1;
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    FLD(u16, self, 0xf4) = self->rot[1];
    FLD(Ov009Vec, self, 0xf8) = self->pos;
    self->unk_b8 = self->pos;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    FLD(u16, self, 0xf2) = 0;
    FLD(u16, self, 0xf0) = 0;
    if (self->unk_1a == 1) {
        self->unk_b6 = func_02040498(0x3c) + 0x3c;
    }
    if (self->unk_48 != NULL) {
        self->unk_48->unk_48 = self->unk_64 << 1;
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
    func_ov000_02198360(self->unk_40, 0x20, 0);
    self->unk_38->unk_c2_0 = 0;
    FLD(u8, self, 0x93) |= 0x80;
}

}
