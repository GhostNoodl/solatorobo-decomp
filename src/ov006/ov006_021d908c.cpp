#include "ov006/ov006.h"

typedef struct ov006_Unk021d908c {
    void *vtbl;
    u8 unk4[0xc];
    int unk10[11];
    u8 unk3C;
    u16 unk3E;
    u16 unk40;
} ov006_Unk021d908c;

extern "C" {

extern u8 data_ov006_021ec040[];
void func_ov006_021ccda0(void *self);

ov006_Unk021d908c *func_ov006_021d908c(ov006_Unk021d908c *self) {
    func_ov006_021ccda0(self);
    self->vtbl = data_ov006_021ec040;
    self->unk10[0] = 0;
    self->unk10[1] = 0;
    self->unk10[2] = 0;
    self->unk10[3] = 0;
    self->unk10[4] = 0;
    self->unk10[5] = 0;
    self->unk10[6] = 0;
    self->unk10[7] = 0;
    self->unk10[8] = 0;
    self->unk10[9] = 0;
    self->unk10[10] = 0;
    self->unk3C = 0;
    self->unk3E = 0;
    self->unk40 = 0;
    return self;
}

}
