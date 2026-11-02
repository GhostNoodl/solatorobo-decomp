#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_02172f7c(Task *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void func_ov000_02150b78(Lo021ca9c4 *self, void *arg) {
    BOOL ok = TRUE;
    void *q;
    if ((void *)self->unk_50 && !LoIsState5(self->unk_50)) {
        ok = FALSE;
    }
    q = self->unk_4c;
    if (q && !LoIsState5(q)) {
        ok = FALSE;
    }
    if ((void *)self->unk_58 && !LoIsState5(self->unk_58)) {
        ok = FALSE;
    }
    if (ok) {
        func_ov000_02172f7c(self, arg);
        return;
    }
    if (q) {
        LBIT(q, 0xc).b1 = 1;
    }
    if (self->unk_50) {
        self->unk_50->hidden = 1;
    }
    if (self->unk_58) {
        self->unk_58->hidden = 1;
    }
}

}
