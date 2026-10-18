#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217d7c[];
extern u8 data_ov014_02217d82[];
extern void func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *a);
extern BOOL func_ov000_02191120(void *a);

void func_ov014_02211f0c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n;
        if (FLD(u16, self, 0x150) == 0x4806) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x1000, 0);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d82, 0x1000, 0);
        }
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 0;
        break;
    }
    case 1: {
        Ov014Sub44 *n;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        self->unk_40->state = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        break;
    }
    default: {
        Ov014Sub44 *n;
        self->unk_40->state = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        break;
    }
    }
}

}
