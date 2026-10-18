#include "ov009/ov009.h"

extern "C" {

extern void func_ov003_021d3d28(Ov009Actor *self);

void func_ov009_0220ac74(Ov009Actor *self) {
    func_ov003_021d3d28(self);
    if (self->unk_90 != 0xffff) {
        return;
    }
    if (self->unk_48->unk_54 & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

}
