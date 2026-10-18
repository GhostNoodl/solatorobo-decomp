#include "ov006/ov006.h"

typedef struct ov006_Unk021e2878 {
    u8 unk0[4];
    u8 unk4;
    u8 unk5[0x5b];
    void *unk60;
} ov006_Unk021e2878;

extern "C" {

BOOL func_02054f10(void *a, int b);

void func_ov006_021e2878(ov006_Unk021e2878 *self) {
    if (self->unk4) {
        return;
    }
    if (self->unk60 == NULL) {
        return;
    }
    if (func_02054f10(self->unk60, 0xffff)) {
        self->unk4 = 1;
    }
}

}
