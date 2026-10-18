#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d3530(void *self) {
    s32 cnt;
    if (FIELD(self, 0x8, s32) != 0xd) {
        return;
    }
    cnt = 0;
    if (FIELD(self, 0x3c, VObject *) != NULL && FIELD(self, 0x3c, VObject *)->v0x1c()) {
        s32 n = FIELD(FIELD(self, 0x3c, void *), 0x94, s32) + FIELD(self, 0xbc, s32) * 3;
        cnt++;
        if (FIELD(self, 0xcc, s32) != n) {
            func_ov002_021d36b8(self, n);
        }
    }
    if (FIELD(self, 0x40, VObject *) != NULL && FIELD(self, 0x40, VObject *)->v0x1c()) {
        cnt++;
    }
    if (cnt == 0) {
        ((VObject *)self)->v0xc(0);
    }
}

}
