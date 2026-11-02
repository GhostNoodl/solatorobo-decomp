#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"

extern "C" {

void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

struct Obj0216e574 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    u16 unk_44;
    u8 unk_46[0x2];
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
};
SIZE_ASSERT(Obj0216e574, 0x54);

void func_ov000_0216e574(Obj0216e574 *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 1;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
}

}
