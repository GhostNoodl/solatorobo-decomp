#include "ov000/LoCommon.h"
#include "nitro/std.h"

extern "C" {


struct Obj02163254 {
    u8 unk_00[0x28];
    s32 unk_28;
};

void func_ov000_02163254(Obj02163254 *self) {
    LO_FREE_V(self, 0x20);
    LO_FREE_V(self, 0x24);
    self->unk_28 = 4;
}

}
