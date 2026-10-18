#include "ov006/Slider.h"

typedef struct ov006_Unk021e2f3c {
    void *vtbl;
    u8 unk4;
    u8 unk5[0xb];
    void *unk10;
    ov006_Slider *unk14;
    ov006_Slider *unk18[3];
} ov006_Unk021e2f3c;

extern "C" void func_ov006_021e2f3c(ov006_Unk021e2f3c *self) {
    int i;

    if (!self->unk4 && self->unk10 != NULL && func_02054f10(self->unk10, 0xffff)) {
        self->unk4 = 1;
    }
    ov006_Slider_Update(self->unk14);
    for (i = 0; i < 3; i++) {
        if (self->unk18[i] != NULL) {
            ov006_Slider_Update(self->unk18[i]);
        }
    }
}
