#include "ov006/ov006.h"
#include "ov006/Tasks.h"


extern "C" {

int FX_Div(int a, int b);

void func_ov006_021e139c(ov006_Unk021e139c *self, int a, int b, u8 c) {
    if (a > b) {
        return;
    }
    self->unkC = FX_Div(a, b);
    self->unk5 = c;
}

}
