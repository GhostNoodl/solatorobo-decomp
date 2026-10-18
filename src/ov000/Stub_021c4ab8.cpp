#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x20];
    s32 unk_20;
    u8 unk_24[0x74];
    s32 unk_98;
    s32 unk_9c;
    u8 unk_a0[0x24];
    s32 unk_c4;
    s32 unk_c8;
} Obj021c4ab8;

extern "C" {

s32 FX_Div(s32 a, s32 b);

void func_ov000_021c4ab8(Obj021c4ab8 *self) {
    if (self->unk_98 < self->unk_20) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->unk_20 << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
}

}
