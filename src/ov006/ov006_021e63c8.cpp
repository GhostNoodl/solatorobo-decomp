#include "ov006/ov006.h"

typedef struct ov006_Prop63c8 {
    void *vtbl;
    u8 unk4[0xa8];
    int unkAC;
    u8 unkB0[0xe8];
    int unk198;
    u16 unk19C;
    u8 unk19E;
    u8 unk19F;
    int unk1A0;
    u16 unk1A4;
    u16 unk1A6;
    u16 unk1A8;
    u8 unk1AA;
    u8 unk1AB;
    u8 unk1AC;
    u8 unk1AD;
    u16 unk1AE[9];
    int unk1C0[13];
    u8 unk1F4;
    u8 unk1F5;
    u16 unk1F6;
    u16 unk1F8;
    u16 unk1FA;
    u16 unk1FC;
    s16 unk1FE;
    int unk200;
    int unk204;
    u8 unk208;
    u8 unk209;
    u8 unk20A;
    u8 unk20B;
    u16 unk20C[6];
    u8 unk218[6];
    u8 unk21E[8];
    u8 unk226;
    u8 unk227;
} ov006_Prop63c8;

extern "C" {

extern u8 data_ov006_021ec4f4[];
void func_ov000_0218c2d4(void *self);
void func_ov000_0218fe1c(void *p);
u8 func_ov006_021d8d9c(void);
int func_ov006_021d8d4c(void);
int func_ov006_021d8de0(void);

ov006_Prop63c8 *func_ov006_021e63c8(ov006_Prop63c8 *self) {
    int i;
    func_ov000_0218c2d4(self);
    self->vtbl = data_ov006_021ec4f4;
    func_ov000_0218fe1c(self->unkB0);
    self->unkAC = 0;
    self->unk198 = 0;
    self->unk19C = 0;
    self->unk19F = 0;
    self->unk1A0 = 0;
    self->unk1A4 = 0;
    self->unk1A6 = 0;
    self->unk1A8 = 0;
    self->unk1AA = 0;
    self->unk1AB = 0;
    self->unk1AC = 0;
    self->unk1AD = 0xff;
    self->unk1AE[0] = 0;
    self->unk1AE[1] = 0;
    self->unk1AE[2] = 0;
    self->unk1AE[3] = 0;
    self->unk1AE[4] = 0;
    self->unk1AE[5] = 0;
    self->unk1AE[6] = 0;
    self->unk1AE[7] = 0;
    self->unk1AE[8] = 0;
    self->unk1C0[0] = 0;
    self->unk1C0[1] = 0;
    self->unk1C0[2] = 0;
    self->unk1C0[3] = 0;
    self->unk1C0[4] = 0;
    self->unk1C0[5] = 0;
    self->unk1C0[6] = 0;
    self->unk1C0[7] = 0;
    self->unk1C0[8] = 0;
    self->unk1C0[9] = 0;
    self->unk1C0[10] = 0;
    self->unk1C0[11] = 0;
    self->unk1C0[12] = 0;
    self->unk1F4 = 0;
    self->unk1F5 = 0;
    self->unk1F6 = 1000;
    self->unk1F8 = 0;
    self->unk1FA = 0;
    self->unk1FC = 0;
    self->unk1FE = -1;
    self->unk208 = func_ov006_021d8d9c();
    self->unk200 = func_ov006_021d8d4c();
    self->unk204 = func_ov006_021d8de0();
    self->unk209 = 0;
    self->unk20A = 1;
    self->unk20B = 0;
    self->unk20C[0] = 0;
    self->unk20C[1] = 0;
    self->unk20C[2] = 0;
    self->unk20C[3] = 0;
    self->unk20C[4] = 0;
    self->unk20C[5] = 0;
    for (i = 0; i < 8; i++) {
        self->unk21E[i] = 0;
    }
    self->unk227 = 0;
    self->unk226 = 0;
    return self;
}

}
