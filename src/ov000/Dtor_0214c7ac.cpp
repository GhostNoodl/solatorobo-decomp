#include "ov000/LoCommon.h"

extern "C" {

void Menu021ca94c_Release(u8 *self) {
    LO_FREE_V(self, 0x8c);
    VOBJ_AT(self, 0x90)->vfunc_08();
    VOBJ_AT(self, 0x148)->vfunc_08();
    LO_FREE_V(self, 0x200);
    LO_FREE_M(self, 0x84);
    LO_FREE_M(self, 0x88);
}
}
