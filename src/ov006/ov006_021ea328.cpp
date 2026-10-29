#include "ov006/SlotManager.h"

typedef struct ov006_Fx021ea328 {
    u8 unk0[0x24];
    int unk24;
    u8 unk28[0x14];
    int unk3C;
} ov006_Fx021ea328;

typedef struct ov006_Prop021ea328 {
    u8 unk0[0x70];
    u8 unk70[0x12c];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 14;
    u8 unk19E[0x32];
    int unk1D0;
    u8 unk1D4[0x22];
    u16 unk1F6;
    u8 unk1F8[0x27];
    u8 unk21F;
} ov006_Prop021ea328;

extern "C" {

extern void *data_02097e4c;
ov006_Fx021ea328 *func_02065f88(int id, void *pos);
void *func_02049f44(void *a, int b, void *c, int d);

void func_ov006_021ea328(ov006_Prop021ea328 *self) {
    self->unk1F6 += 3000;
    if (self->unk1F6 > 30000) {
        self->unk1F6 = 30000;
    }
    if (data_ov006_021ec884->unk13D != 0) {
        return;
    }
    if (++self->unk21F > 99) {
        self->unk21F = 99;
    }
    if (self->unk19C_0 & 1) {
        ov006_Fx021ea328 *fx = func_02065f88(0x195, self->unk70);
        if (fx != NULL) {
            self->unk1D0 = fx->unk24;
            fx->unk3C = 0x2800;
        }
        func_02049f44(data_02097e4c, 0x11, self->unk70, 0);
    }
}

}
