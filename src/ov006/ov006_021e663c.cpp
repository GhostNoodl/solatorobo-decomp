#include "ov006/SlotManager.h"

typedef struct ov006_Obj021e663c {
    u16 unk0;
} ov006_Obj021e663c;

typedef struct ov006_Prop021e663c {
    u8 unk0[0xe];
    u16 unkE;
    u8 unk10[0x24];
    ov006_Obj021e663c *unk34;
    u8 unk38[0x38];
    int unk70;
    int unk74;
    int unk78;
    u8 unk7C[0x30];
    int unkAC;
    u8 unkB0[0xec];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 6;
    u16 unk19C_8 : 1;
    u16 unk19C_9 : 1;
    u16 unk19C_10 : 6;
    u8 unk19E;
    u8 unk19F[0x21];
    int unk1C0;
    int unk1C4;
    int unk1C8;
} ov006_Prop021e663c;

typedef struct ov006_Save0214a424 {
    u8 unk0[0x18];
    u16 unk18_0 : 10;
    u16 unk18_10 : 1;
    u16 unk18_11 : 5;
} ov006_Save0214a424;

extern "C" {

extern ov006_Save0214a424 *data_0214a424;
void *func_0206fef8(u16 id);
int func_020706a0(u16 id);
int func_0207011c(u16 id);
ov006_Obj021e663c *func_ov000_0218e9c4(void *p);
void func_ov000_0218f074(ov006_Obj021e663c *a, int b, int c, int d, int e, int f);

void func_ov006_021e663c(ov006_Prop021e663c *self) {
    int res;
    ov006_Obj021e663c *obj;
    func_0206fef8(self->unkE);
    self->unkAC = func_020706a0(self->unkE);
    res = func_0207011c(self->unkE);
    obj = (ov006_Obj021e663c *)func_0203dd9c(0x138);
    if (obj != NULL) {
        obj = func_ov000_0218e9c4(obj);
    }
    self->unk34 = obj;
    func_ov000_0218f074(self->unk34, res, 1, 1, 0, 0);
    self->unk34->unk0 = 0;
    if (self->unk19E == data_ov006_021ec884->unk5) {
        self->unk19C_9 = data_0214a424->unk18_10 ? TRUE : FALSE;
        self->unk19C_8 = self->unk19C_9;
    }
    self->unk1C0 = self->unk70;
    self->unk1C4 = self->unk74;
    self->unk1C8 = self->unk78;
}

}
