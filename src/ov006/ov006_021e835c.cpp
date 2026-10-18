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
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, int b);
u16 func_01ffc128(int a, u16 b, int c, int d, int e);

void func_ov006_021e835c(ov006_Obj021e835c *self) {
    if (self->unk40->unk0 == 0) {
        func_ov000_02190cb0(self->unk38, data_ov006_021ec4a7, 0x1000, 0);
        func_ov000_021915a0(self->unk38);
        func_ov000_021911c8(self->unk38, 0x333);
        self->unk40->unk0++;
    }
    self->unk7C = func_01ffc128(0, self->unk7C, 0x400, 1, 0x8000);
    self->unk80 = func_01ffc128(0, self->unk80, 0x400, 1, 0x8000);
}

}
