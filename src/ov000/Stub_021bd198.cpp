#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08[8];
    s32 unk_28[6];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68[9];
} Obj021bd198;

extern "C" {

void func_02016e28(void *dst, s32 val, u32 size);

void func_ov000_021bd198(Obj021bd198 *self) {
    s32 i;
    self->unk_00 = 0;
    self->unk_04 = 0;
    for (i = 0; i < 8; i++) {
        self->unk_08[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        self->unk_28[i] = 0;
    }
    self->unk_40 = 10;
    self->unk_44 = -1;
    self->unk_48 = -1;
    self->unk_4c = 0x1000;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    func_02016e28(self->unk_68, 0, sizeof(self->unk_68));
    self->unk_68[0] = 4;
}

}
