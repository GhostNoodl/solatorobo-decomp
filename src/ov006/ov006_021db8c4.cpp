#include "ov006/ov006.h"

typedef struct ov006_Unk021db8c4 {
    void *vtbl;
    u8 unk4[0x1de];
    u16 unk1E2;
    u16 unk1E4;
} ov006_Unk021db8c4;

extern "C" {

extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov006_021ec30c[];

ov006_Unk021db8c4 *func_ov006_021db8c4(ov006_Unk021db8c4 *self) {
    self->vtbl = data_ov000_021cac60;
    VCALL(self, 28);
    self->vtbl = data_ov000_021caec8;
    VCALL(self, 28);
    self->vtbl = data_ov000_021cb1b0;
    VCALL(self, 28);
    self->vtbl = data_ov000_021cb0b8;
    VCALL(self, 28);
    self->vtbl = data_ov006_021ec30c;
    self->unk1E2 = 0;
    self->unk1E4 = 0;
    return self;
}

}
