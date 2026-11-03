#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Task_Exit(Task *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void Lo021ca9c4_Exit(Lo021ca9c4 *self, void *arg) {
    BOOL ok = TRUE;
    Lo021cb5a8 *q;
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
        Task_Exit(self, arg);
        return;
    }
    if (q) {
        q->hidden = 1;
    }
    if (self->unk_50) {
        self->unk_50->hidden = 1;
    }
    if (self->unk_58) {
        self->unk_58->hidden = 1;
    }
}

}
