#include "ov006/SlotManager.h"
#include "Main/Effect/Effect.h"

typedef struct ov006_Prop021ea328 {
    u8 unk0[0x70];
    VecFx32 pos;
    u8 unk7C[0x120];
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
        EffectObj *fx = func_02065f88(0x195, &self->pos);
        if (fx != NULL) {
            self->unk1D0 = fx->id;
            fx->speed = 0x2800;
        }
        func_02049f44(data_02097e4c, 0x11, &self->pos, 0);
    }
}

}
