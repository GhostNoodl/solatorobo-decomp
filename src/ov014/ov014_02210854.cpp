#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_021984f4(void *a, void *b, s32 c);

void func_ov014_02210854(Ov014Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, (u8 *)self + 0x118, 0);
    }
}

}
