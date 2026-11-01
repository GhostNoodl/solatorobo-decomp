#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
void MTX_Identity43_(void *m);
void MTX_RotY43_(void *m, s32 s, s32 c);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

struct Obj0216c954 {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u16 unk_1c;
    u8 unk_1e[0x2];
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u16 unk_2a;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
};

void func_ov000_0216c954(Obj0216c954 *self, u16 a, s32 b) {
    self->unk_00 = 0;
    LBIT(self, 0).b2 = 0;
    self->unk_04 = 2;
    self->unk_1c = a;
    self->unk_08 = b;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0xffff;
    self->unk_2a = 0xffff;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
}

}
