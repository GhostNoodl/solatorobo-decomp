#include "ov006/ov006.h"

extern "C" {

void func_ov006_021e4c5c(ov006_Unk021ec888 *self);

void func_ov006_021d0188(void) {
    if (data_ov006_021ec888->unk8 != 1) {
        func_ov006_021e4c5c(data_ov006_021ec888);
    }
}

}
