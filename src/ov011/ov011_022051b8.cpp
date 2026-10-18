#include "ov011/ov011.h"

extern "C" {

extern u8 *data_02097d48;
void func_02043d9c(void *p);
void func_ov003_021d16cc(void *p);

#pragma force_active on
void func_ov011_022051b8(void *self) {
    u8 v = data_02097d48[0x8b3];
    func_02043d9c(data_02097d48 + 0x8b0);
    (*(u8 **)((u8 *)self + 0x38))[0xc1] = v;
    func_ov003_021d16cc(self);
}
#pragma force_active reset
}
