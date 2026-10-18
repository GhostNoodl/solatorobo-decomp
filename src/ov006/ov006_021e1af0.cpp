#include "ov006/Slider.h"

typedef struct ov006_Unk021e1af0 {
    void *vtbl;
    u8 unk4;
    u8 unk5[0x1f];
    ov006_Slider *unk24;
    void *unk28;
    void *unk2C;
} ov006_Unk021e1af0;

extern "C" {

void func_ov006_021dc054(void *a);

void func_ov006_021e1af0(ov006_Unk021e1af0 *self) {
    if (!self->unk4 && self->unk28 != NULL && func_02054f10(self->unk28, 0xffff)) {
        self->unk4 = 1;
    }
    ov006_Slider_Update(self->unk24);
    func_ov006_021dc054(self->unk2C);
}

}
