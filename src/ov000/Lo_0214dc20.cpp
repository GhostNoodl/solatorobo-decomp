#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
void func_ov000_0215eab4(void *p);
void func_020592c4(void *a, s32 b, s32 c, u16 d, s32 e);

struct Obj0214dc20 {
    u8 unk_00[0x6];
    u16 unk_06;
    u8 unk_08[0x1c];
    s32 unk_24;
    u8 unk_28[0x8];
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
};

void func_ov000_0214dc20(Obj0214dc20 *self, s32 *msg) {
    if (msg[0] != 0x25) {
        return;
    }
    switch (msg[1]) {
    case 0:
        self->unk_30 = msg[2];
        if (msg[2] != LFLD(u16, data_02fe1534, 0x46)) {
            self->unk_24 = 0xe;
            return;
        }
        func_020592c4(data_02fe152c, 1, 0x101, self->unk_06, 0);
        break;
    case 1:
        self->unk_32 = msg[2];
        break;
    case 2:
        self->unk_34 = msg[2];
        break;
    case 3:
        self->unk_36 = msg[2];
        break;
    }
}

}
