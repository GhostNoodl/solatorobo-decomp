#include "ov006/ov006.h"

typedef struct ov006_Unk021e835c {
    u16 unk0;
} ov006_Unk021e835c;

typedef struct ov006_Obj021e835c {
    u8 unk0[0x38];
    void *unk38;
    u8 unk3C[4];
    ov006_Unk021e835c *unk40;
    u8 unk44[0x38];
    u16 unk7C;
    u8 unk7E[2];
    u16 unk80;
} ov006_Obj021e835c;

extern "C" {

extern char data_ov006_021ec4a7[];
BOOL Model0218fe1c_SetAnim(void *a, const void *b, int c, int d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_SetAnimSpeed(void *a, int b);
u16 Angle_Approach(u16 a, u16 b, s32 c, u32 d, u16 e);

void Ov006Racer_State01(ov006_Obj021e835c *self) {
    if (self->unk40->unk0 == 0) {
        Model0218fe1c_SetAnim(self->unk38, data_ov006_021ec4a7, 0x1000, 0);
        Model0218fe1c_SetLoop(self->unk38);
        Model0218fe1c_SetAnimSpeed(self->unk38, 0x333);
        self->unk40->unk0++;
    }
    self->unk7C = Angle_Approach(0, self->unk7C, 0x400, 1, 0x8000);
    self->unk80 = Angle_Approach(0, self->unk80, 0x400, 1, 0x8000);
}

}
