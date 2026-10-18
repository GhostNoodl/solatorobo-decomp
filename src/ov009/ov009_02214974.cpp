#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_0221801c[];
extern void *func_ov000_02199ba0(void *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_ov000_02196060(Ov009Actor *self);

void func_ov009_02214974(Ov009Actor *self) {
    u8 *p = (u8 *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (p != NULL) {
        FLD(u16, self, 0xd2) = FLD(u16, p, 0xc);
        if (FLD(u16, p, 0xe) == 0x501d && self->unk_40->state == 0) {
            Ov009Sub44 *s44;
            func_ov000_02190cb0(self->unk_38, data_ov009_0221801c, 0x1000, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0x2f6;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0x29;
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            if (self->unk_48 != NULL) {
                Ov009Sub48 *s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
                s48 = self->unk_48;
                s48->unk_9a_1 = 1;
                s48->unk_9a_4 = 1;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0;
        } else {
            func_ov000_02196060(self);
        }
    } else {
        FLD(u16, self, 0xd2) = 0xffff;
        func_ov000_02198360(self->unk_40, 4, 0);
    }
}

}
