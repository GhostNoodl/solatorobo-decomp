#include "ov006/ov006.h"

typedef struct ov006_Unk021dd5b8 {
    void *vtbl;
    u8 unk4[4];
    u8 unk8;
    u8 unk9[0xf];
    void *unk18;
} ov006_Unk021dd5b8;

extern "C" {

void Obj0215fdfc_SetRange(void *a, int b, int c);

void ov006_Unk021dd5b8_SetText(ov006_Unk021dd5b8 *self, int a, int b, u8 c) {
    if (self->unk18 != NULL) {
        Obj0215fdfc_SetRange(self->unk18, a, b);
    }
    self->unk8 = c;
}

}
