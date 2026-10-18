#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02177028(u8 *self) {
    LO_FREE_V(self, 0x58);
    LO_FREE_V(self, 0x3c);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LFLD(s8, data_ov000_021ccd34, 1) = LFLD(s8, data_ov000_021ccd34, 1) - 1;
    if (LFLD(s8, data_ov000_021ccd34, 1) != 0) {
        return;
    }
    LO_FREE_V(data_ov000_021ccd34, 0x14);
}
}
