#include "ov006/ov006.h"

typedef struct ov006_Unk021db95c {
    void *vtbl;
} ov006_Unk021db95c;

extern "C" {

extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cac60[];

static inline void ov006_Unk021db95c_dtor(ov006_Unk021db95c *self) {
    self->vtbl = data_ov000_021cb0b8;
    VCALL(self, 2C);
    self->vtbl = data_ov000_021cb1b0;
    VCALL(self, 2C);
    self->vtbl = data_ov000_021caec8;
    VCALL(self, 2C);
    self->vtbl = data_ov000_021cac60;
    VCALL(self, 2C);
}

ov006_Unk021db95c *func_ov006_021db95c(ov006_Unk021db95c *self) {
    ov006_Unk021db95c_dtor(self);
    return self;
}

ov006_Unk021db95c *func_ov006_021db9d8(ov006_Unk021db95c *self) {
    ov006_Unk021db95c_dtor(self);
    func_0203de1c(self);
    return self;
}

}
