#include "ov006/SlotManager.h"

typedef struct ov006_Fx021ea244 {
    u8 unk0[0x24];
    int unk24;
    u8 unk28[0x14];
    int unk3C;
} ov006_Fx021ea244;

typedef struct ov006_Prop021ea244 {
    u8 unk0[0x70];
    u8 unk70[0x12c];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 14;
    u8 unk19E[0xc];
    u8 unk1AA;
    u8 unk1AB;
    u8 unk1AC;
    u8 unk1AD;
    u8 unk1AE[0x22];
    int unk1D0;
    u8 unk1D4[0x4c];
    u8 unk220;
} ov006_Prop021ea244;

extern "C" {

extern void *data_02097e4c;
extern const u8 data_ov006_021eb918[][6];
ov006_Fx021ea244 *func_02065f88(int id, void *pos);
void func_02049f44(void *a, int b, void *c, int d);

void func_ov006_021ea244(ov006_Prop021ea244 *self) {
    if (self->unk1AA == 0 && self->unk1AB == 0) {
        self->unk1AB = data_ov006_021eb918[self->unk1AD][self->unk1AC];
        self->unk1AC++;
        if (self->unk1AC > 6) {
            self->unk1AC = 0;
        }
    }
    if (data_ov006_021ec884->unk13D != 0) {
        return;
    }
    if (++self->unk220 > 99) {
        self->unk220 = 99;
    }
    if (self->unk19C_0 & 1) {
        ov006_Fx021ea244 *fx = func_02065f88(0x196, self->unk70);
        if (fx != NULL) {
            self->unk1D0 = fx->unk24;
            fx->unk3C = 0x2800;
        }
        func_02049f44(data_02097e4c, 0x85, self->unk70, 0);
    }
}

}
