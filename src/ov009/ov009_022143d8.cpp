#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_022161c8[];
extern void func_0203f364(Ov009Sub48 *p);

void func_ov009_022143d8(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub48 *s48;
        func_ov000_02190cb0(self->unk_38, data_ov009_022161c8[0], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        FLD(u8, self, 0xce) = 0;
        if (self->kind == 0x408f) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->unk_40->state++;
    }
    self->unk_94_1 = FLD(u8, self, 0xce);
}

}
