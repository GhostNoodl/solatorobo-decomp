#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

struct Obj02153fd8 {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
};

void func_ov000_02153fd8(Obj02153fd8 *self) {
    LO_FREE_V(self, 0x1c);
    LO_FREE_V(self, 0x20);
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0xffff;
    self->unk_0a = 0xffff;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
}

}
