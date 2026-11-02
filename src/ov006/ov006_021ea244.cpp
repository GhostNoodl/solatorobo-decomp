#include "ov006/SlotManager.h"
#include "Main/Effect/Effect.h"

typedef struct ov006_Prop021ea244 {
    u8 unk0[0x70];
    VecFx32 pos;
    u8 unk7C[0x120];
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
void *func_02049f44(void *a, int b, void *c, int d);

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
        EffectObj *fx = func_02065f88(0x196, &self->pos);
        if (fx != NULL) {
            self->unk1D0 = fx->id;
            fx->speed = 0x2800;
        }
        func_02049f44(data_02097e4c, 0x85, &self->pos, 0);
    }
}

}
