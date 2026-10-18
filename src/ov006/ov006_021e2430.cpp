#include "ov006/ov006.h"

typedef struct ov006_Elem021e2430 {
    u8 unk0[0x24];
} ov006_Elem021e2430;

typedef struct ov006_Unk021e2430 {
    void *vtbl;
    u8 unk4;
    u8 unk5[0xb];
    ov006_Elem021e2430 elems[4];
    void *unkA0;
} ov006_Unk021e2430;

extern "C" {

BOOL func_02054f10(void *a, int b);
void func_ov006_021e1f80(ov006_Elem021e2430 *e);

void func_ov006_021e2430(ov006_Unk021e2430 *self) {
    int i;
    if (!self->unk4) {
        if (self->unkA0 == NULL) {
            return;
        }
        if (!func_02054f10(self->unkA0, 0xffff)) {
            return;
        }
        self->unk4 = 1;
    }
    for (i = 0; i < 4; i++) {
        func_ov006_021e1f80(&self->elems[i]);
    }
}

}
