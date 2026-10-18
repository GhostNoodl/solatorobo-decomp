#include "ov000/VObj.h"

typedef struct {
    u8 pad_00[0x18];
    s32 unk_18;
} Obj021c4c10Sub;

typedef struct {
    u8 pad_00[0x94];
    Obj021c4c10Sub *unk_94;
    u8 pad_98[0xde - 0x98];
    u8 unk_de;
    u8 unk_df;
    s32 unk_e0;
} Obj021c4c10;

extern "C" {

s32 FX_Div(s32 a, s32 b);

void func_ov000_021c4c10(Obj021c4c10 *self) {
    s32 a;
    s32 r;

    if (self->unk_de != 0) {
        self->unk_de--;
        a = (u16)self->unk_94->unk_18 << 12;
        r = FX_Div(a, 0x4000);
        if (r == 0) {
            r = 1;
        }
        if (self->unk_df == 1) {
            self->unk_e0 = (0x7800 - a) + r * (4 - self->unk_de);
            return;
        }
        if (self->unk_df != 2) {
            return;
        }
        self->unk_e0 = 0x7800 - r * (4 - self->unk_de);
        return;
    }
    self->unk_e0 = 0x7800;
    self->unk_de = 0;
    self->unk_df = 0;
}

}
