#include "ov006/ov006.h"
#include "ov006/Tasks.h"


extern "C" {

int FX_Div(int a, int b);

void ov006_Gauge_SetRatio(ov006_Gauge *self, int a, int b, u8 c) {
    if (a > b) {
        return;
    }
    self->unkC = FX_Div(a, b);
    self->unk5 = c;
}

}
