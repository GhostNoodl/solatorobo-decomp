#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d0740(Task50 *self) {
    u16 k = FIELD(data_02097dc8, 0x12, u16);
    if (k & 0x800) {
        u8 *g = data_02097e48;
        if (FIELD(g, 0, Bits16).b3) {
            FIELD(g, 0x6, u16) = 0x8000;
            FIELD(g, 0x8, u16) = 10;
            FIELD(g, 0x2, u16) = 0;
        }
        g = data_02097e48;
        FIELD(g, 0x80, u16) = 0x8000;
        FIELD(g, 0x7c, u16) = 0;
    }
    if (!(k & 2)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    data_ov002_021f0f84[0] = FIELD(FIELD(self->unk_3c, 0xa0, void *), 4, s32);
    self->v0xc(0);
}

}
