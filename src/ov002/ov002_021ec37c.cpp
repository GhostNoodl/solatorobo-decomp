#include "ov002/ov002.h"

extern "C" {

void Ov002Vt_021f0f2c_Clear(void *self) {
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
}

void Ov002Vt_021f0f2c_Unload(void) {
}

}
