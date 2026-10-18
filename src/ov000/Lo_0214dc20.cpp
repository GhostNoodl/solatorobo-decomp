#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
void func_ov000_0215eab4(void *p);
void func_020592c4(void *a, s32 b, s32 c, u16 d, s32 e);

void func_ov000_0214dc20(void *self, s32 *msg) {
    if (msg[0] != 0x25) {
        return;
    }
    switch (msg[1]) {
    case 0:
        LFLD(u16, self, 0x30) = msg[2];
        if (msg[2] != LFLD(u16, data_02fe1534, 0x46)) {
            LFLD(s32, self, 0x24) = 0xe;
            return;
        }
        func_020592c4(data_02fe152c, 1, 0x101, LFLD(u16, self, 6), 0);
        break;
    case 1:
        LFLD(u16, self, 0x32) = msg[2];
        break;
    case 2:
        LFLD(u16, self, 0x34) = msg[2];
        break;
    case 3:
        LFLD(u16, self, 0x36) = msg[2];
        break;
    }
}

}
