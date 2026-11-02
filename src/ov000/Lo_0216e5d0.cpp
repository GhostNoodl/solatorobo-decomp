#include "ov000/LoCommon.h"
#include "ov000/LoTimer.h"

extern "C" {

void LoTimer_FreeModels(LoTimer *self) {
    LO_FREE_M(self, 0x10); // unk_10
    LO_FREE_M(self, 0x14); // unk_14
}

}
