#include "ov000/VObj.h"

extern "C" {

extern u8 *data_02097d48;
void func_02043d20(void *p, s32 a);
void func_ov000_021badd4(void *self);

void func_ov000_021bac78(void *self) {
    s32 state = *(s32 *)((u8 *)self + 0x4);
    if (state != 0xb && state != 0xc && state != 0xd) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    func_ov000_021badd4(self);
}

}
