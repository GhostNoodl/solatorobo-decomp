#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022172b5[];
extern void func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern void func_ov000_02191618(void *model);
extern void func_0203f364(Ov009Sub48 *p);

void func_ov009_02209a08(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        Ov009Sub48 *s48;
        switch (self->unk_1a) {
        case 0:
        case 1:
            func_ov000_02190cb0(self->unk_38, data_ov009_022172b5, 0x1000, 0);
            func_ov000_02191318(self->unk_38, 0x49000);
            func_ov000_02191618(self->unk_38);
            break;
        }
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s48 = self->unk_48;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
        s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
            FLD(u16, self, 0x310) = 0;
        }
        break;
    }
}

}
