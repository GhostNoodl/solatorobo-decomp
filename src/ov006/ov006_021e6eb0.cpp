#include "ov006/SlotManager.h"

typedef struct ov006_Sub021e6eb0 {
    u16 buttons;
    u8 kind : 3;
    u8 b3 : 1;
    u8 flag : 1;
    u8 b5 : 3;
    u8 bits;
    s32 x;
    s32 y;
    s32 z;
} ov006_Sub021e6eb0;

typedef struct ov006_Prop021e6eb0 {
    u8 unk0[0x70];
    s32 x;
    s32 y;
    s32 z;
    u8 unk7C[0x120];
    u16 unk19C_0 : 8;
    u16 flag : 1;
    u16 toggle : 1;
    u16 unk19C_10 : 6;
    u8 idx;
    u8 unk19F;
    int unk1A0;
    u16 held;
    u16 trig;
    u16 release;
    u8 kind;
    u8 unk1AB;
    u8 unk1AC;
    u8 unk1AD;
} ov006_Prop021e6eb0;

typedef struct ov006_Disp021e6eb0 {
    u8 unk0[0x18];
    u16 unk18_0 : 10;
    u16 unk18_10 : 1;
    u16 unk18_11 : 5;
} ov006_Disp021e6eb0;

extern "C" {

extern ov006_Disp021e6eb0 *data_0214a424;
const ov006_Sub021e6eb0 *func_ov006_021dab98(ov006_Slot *self);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);

void func_ov006_021e6eb0(ov006_Prop021e6eb0 *self) {
    const ov006_Sub021e6eb0 *sub;
    sub = func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, 0));
    self->unk1AD = (sub->bits >> (self->idx * 2)) & 3;
    sub = func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, self->idx));
    {
        u16 old = self->held;
        u16 cur = sub->buttons;
        self->trig = cur;
        self->trig &= (u16)~old;
        self->release = old;
        self->release &= (u16)~cur;
        self->held = cur;
    }
    self->kind = sub->kind;
    self->flag = sub->flag;
    self->x = sub->x;
    self->y = sub->y;
    self->z = sub->z;
    if (!(self->trig & 4)) {
        return;
    }
    self->toggle = (u16)(self->toggle == 0 ? 1 : 0);
    if (self->idx != data_ov006_021ec884->unk5) {
        return;
    }
    if (self->toggle) {
        data_0214a424->unk18_10 = 1;
    } else {
        data_0214a424->unk18_10 = 0;
    }
}

}
