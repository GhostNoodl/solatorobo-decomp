#include "ov006/Slider.h"

typedef struct ov006_Unk021e1af0 {
    void *vtbl;
    u8 unk4;
    u8 unk5[0x1f];
    ov006_Caption *unk24;
    void *unk28;
    void *unk2C;
} ov006_Unk021e1af0;

extern "C" {

void ov006_Label_Update(void *a);

void ov006_Unk021e1af0_Update(ov006_Unk021e1af0 *self) {
    if (!self->unk4 && self->unk28 != NULL && func_02054f10(self->unk28, 0xffff)) {
        self->unk4 = 1;
    }
    ov006_Slider_Update(self->unk24);
    ov006_Label_Update(self->unk2C);
}

}
