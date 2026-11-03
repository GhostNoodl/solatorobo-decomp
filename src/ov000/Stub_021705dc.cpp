#include "ov000/MessageQueue.h"
#include "ov000/Obj0216c954.h"

static inline BOOL NotNull54_Inline(ListBuffer021cb940 *self) { return self->unk_54 != NULL; }

extern "C" {


BOOL ListBuffer021cb940_IsBusy(ListBuffer021cb940 *self) {
    if (self->state == 7 || self->unk_3c != NULL ||
        self->unk_40 != NULL || self->unk_44 != NULL) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021705a0(ListBuffer021cb940 *self, s32 check) {
    void *p = self->unk_34;
    if (p == NULL) {
        return FALSE;
    }
    if (check) {
        if (*(s32 *)((u8 *)p + 0x44) == 0xb ? TRUE : FALSE) {
            return FALSE;
        }
    }
    return TRUE;
}

void ListBuffer021cb940_SetEventCount(ListBuffer021cb940 *self, s32 a, s32 b) {
    Obj0216c954_SetCount(self->unk_50, a, b);
}

bool func_ov000_021705ec(ListBuffer021cb940 *self) {
    return NotNull54_Inline(self);
}

s32 ListBuffer021cb940_HasDialog(ListBuffer021cb940 *self) {
    return self->dialog != NULL ? 0x1 : 0x0;
}

}
