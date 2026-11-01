#include "ov000/LoCommon.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

struct Obj02152cbc {
    u8 unk_00[0x4];
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
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s16 unk_48;
    s16 unk_4a;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x2];
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
};

void func_ov000_02152cbc(Obj02152cbc *self) {
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_1c = 8;
    self->unk_20 = 1;
    self->unk_24 = 0x80;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 0xc000;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = 0xc000;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4a = 0xb;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_66 = 0;
    self->unk_68 = 0;
    self->unk_54 = 0x14;
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
}

}
