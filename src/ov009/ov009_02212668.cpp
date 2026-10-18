#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_021984f4(void *a, void *b, s32 c);

void func_ov009_02212668(Ov009Actor *self) {
    if (self->unk_44 == NULL) {
        return;
    }
    func_ov000_021984f4(self->unk_44, (u8 *)self + 0x11c, 0);
}

}
