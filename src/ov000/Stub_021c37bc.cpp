#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x18];
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20[0x10];
    s32 unk_30;
    void *unk_34;
    void *unk_38;
    s32 unk_3c;
    u16 unk_40;
} Obj021c37bc;

extern "C" {

extern u8 data_ov000_021cc9bc[];

void func_ov000_021c37bc(Obj021c37bc *self) {
    self->unk_1c = 0xf4;
    self->unk_18 = 0xb8;
    self->unk_30 = 0;
    self->unk_34 = data_ov000_021cc9bc;
    self->unk_38 = data_ov000_021cc9bc;
    self->unk_3c = 0;
    self->unk_40 = 0;
}

}
