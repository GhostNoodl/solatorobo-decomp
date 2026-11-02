#include "ov006/Label.h"

typedef struct ov006_Unk021e1ddc {
    u8 unk0[0x2c];
    ov006_Label *unk2C;
} ov006_Unk021e1ddc;

extern "C" {

void ov006_Unk021e1ddc_SetLabel(ov006_Unk021e1ddc *self, const char *a, const char *b, u16 c) {
    ov006_Label_Set(self->unk2C, a, b, c);
}

}
