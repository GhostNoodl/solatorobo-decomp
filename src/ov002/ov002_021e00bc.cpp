#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e00bc(void *self) {
    u16 k = FIELD(data_02097dc8, 0x12, u16);
    void *w;
    u8 *q;
    if (k & 1) {
        FIELD(self, 0x18, s32) = 0x28;
        func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
        return;
    }
    if (!(k & 2) && !(k & 0x20)) {
        return;
    }
    {
        void *r = func_0206ec48(FIELD(FIELD(self, 0x10, void *), 0x48, u16));
        w = FIELD(self, 4, void *);
        func_ov000_0215bb14(FIELD(w, 0x20, void *), r);
        FIELD(w, 0x20, VObject *)->v0x70();
    }
    q = FIELD(FIELD(self, 4, void *), 4, u8 *);
    q[0x74] = 7;
    q[0x75] = 1;
    func_ov002_021e019c(self, FIELD(self, 0x1c, s32), FIELD(self, 0x20, s32));
    FIELD(self, 0x18, s32) = 0;
    func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
}

}
