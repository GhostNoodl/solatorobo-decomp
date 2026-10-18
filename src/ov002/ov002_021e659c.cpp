#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e659c(void *self) {
    FIELD(self, 0x6c, s32) = FIELD(self, 0x18, s32);
    return TRUE;
}

}
