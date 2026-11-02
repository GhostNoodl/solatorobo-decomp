#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d6350(Task021efc24 *self) {
    s32 x = self->unk_40;
    s32 v = 0;
    if (x < 0x1000000) {
        v = x + 0x8000;
    }
    self->unk_40 = v;
    x = self->unk_44;
    if (x >= 0x1000000) {
        x = 0;
    } else {
        x += 0x8000;
    }
    self->unk_44 = x;
}

}
