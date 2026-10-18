#include "ov002/ov002.h"

extern "C" {

static inline bool func_ov002_021d3434_idle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}
void func_ov002_021d3434(Task50 *self) {
    void *t;
    if (!(FIELD(data_02097dc8, 0x12, u16) & 2) || FIELD(self, 0xc4, void *) == NULL) {
        return;
    }
    if (!func_ov002_021d3434_idle()) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    if (self->unk_3c != NULL) {
        FIELD(self->unk_3c, 0xc, u32) |= 2;
    }
    if (self->unk_40 != NULL) {
        FIELD(self->unk_40, 0xc, u32) |= 2;
    }
    self->flag0 = 1;
    t = data_ov000_021ccd30;
    if (t != NULL && FIELD(t, 0x118, void *) != NULL) {
        func_ov000_0216f844(FIELD(t, 0x118, void *), 1);
    }
}

void func_ov002_021d3518(Task50 *self) {
    if (self->unk_08 == 0xd) {
        func_ov002_021d37f8(self);
    }
}

}
