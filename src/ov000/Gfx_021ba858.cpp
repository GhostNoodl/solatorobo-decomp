#include "types.h"

extern "C" {

void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

void func_ov000_021ba858(void *self, s32 x, s32 y) {
    s32 trans[3];
    u32 begin;
    s32 vtx[2];
    u32 xy0;
    u32 xy1;
    u32 xy2;

    if (x < 0) {
        return;
    }
    trans[0] = x << 12;
    trans[1] = y << 12;
    trans[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, trans, 3);
    begin = 1;
    NNS_G3dGeBufferOP_N(0x40, &begin, 1);
    vtx[0] = 0xf000;
    vtx[1] = 0;
    NNS_G3dGeBufferOP_N(0x23, vtx, 2);
    xy0 = 0x1000f000;
    NNS_G3dGeBufferOP_N(0x25, &xy0, 1);
    xy1 = 0x10000000;
    NNS_G3dGeBufferOP_N(0x25, &xy1, 1);
    xy2 = 0;
    NNS_G3dGeBufferOP_N(0x25, &xy2, 1);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
