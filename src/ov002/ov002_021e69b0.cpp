#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e69b0(void *self) {
    s16 *p;
    s32 v;
    while ((p = FIELD(self, 0xa8, s16 *)) != NULL && FIELD((u8 *)data_ov002_021f0f98[1], 0xd4, s32) < (v = *p << 12) && v <= FIELD((u8 *)data_ov002_021f0f98[1], 0xd0, s32)) {
        func_0204aaec(data_02097e48, p);
        func_ov002_021ec2ac((u8 *)self + 0x94);
    }
    return TRUE;
}

}
