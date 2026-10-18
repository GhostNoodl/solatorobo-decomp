#include "ov006/ov006.h"

typedef struct ov006_Unk021e139c {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[6];
    int unkC;
} ov006_Unk021e139c;

extern "C" {

int func_02012ab8(int a, int b);

void func_ov006_021e139c(ov006_Unk021e139c *self, int a, int b, u8 c) {
    if (a > b) {
        return;
    }
    self->unkC = func_02012ab8(a, b);
    self->unk5 = c;
}

}
