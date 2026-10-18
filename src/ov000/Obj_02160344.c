#include "types.h"

typedef struct {
    u8 unk_00[0x4];
    u32 unk_04;
    u32 unk_08;
    union {
        u32 raw;
        struct {
            u32 unk_0 : 7;
            u32 unk_7 : 1;
            u32 unk_8 : 2;
            u32 unk_10 : 1;
            u32 unk_11 : 21;
        } bits;
    } unk_0c;
    void *unk_10[6];
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6c;
    u16 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u32 unk_8c;
    u32 unk_90;
    u32 unk_94;
    u8 unk_98;
} Obj02160344;

extern u8 data_ov000_021c9912[];

void func_ov000_02160344(Obj02160344 *self) {
    s32 i;
    self->unk_04 = 4;
    self->unk_08 = 0;
    self->unk_0c.raw = 0;
    self->unk_0c.bits.unk_10 = 1;
    for (i = 0; i < 6; i++) {
        self->unk_10[i] = &data_ov000_021c9912[i * 6];
    }
    self->unk_28 = 1;
    self->unk_2c = 0;
    self->unk_30 = 0xc000;
    self->unk_34 = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->unk_6c = 0x1000;
    self->unk_70 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->unk_94 = 0;
    self->unk_98 = 0x1e;
}

void func_ov000_0216040c(void) {
}

void func_ov000_02160410(void) {
}
