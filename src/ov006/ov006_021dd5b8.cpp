#include "ov006/ov006.h"

typedef struct ov006_Unk021dd5b8 {
    void *vtbl;
    u8 unk4[4];
    u8 unk8;
    u8 unk9[0xf];
    void *unk18;
} ov006_Unk021dd5b8;

extern "C" {

void func_ov000_0215fe1c(void *a, int b, int c);

void func_ov006_021dd5b8(ov006_Unk021dd5b8 *self, int a, int b, u8 c) {
    if (self->unk18 != NULL) {
        func_ov000_0215fe1c(self->unk18, a, b);
    }
    self->unk8 = c;
}

}
