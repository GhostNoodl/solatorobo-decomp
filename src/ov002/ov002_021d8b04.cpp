#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d8b04(void *self, Vec2 *out) {
    out->x = FIELD(self, 0x54, s32);
    out->y = FIELD(self, 0x58, s32);
}

}
