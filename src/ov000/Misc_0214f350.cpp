#include "types.h"

typedef struct {
    u8 unk_00[0x20];
    s32 unk_20;
    u8 unk_24[0x18];
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    u8 unk_54[0x4];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u16 unk_64;
} Obj0214f350;

extern "C" {

void func_ov000_0214f350(Obj0214f350 *self) {
    self->unk_20 = 0x1000;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0xffff;
}

}
