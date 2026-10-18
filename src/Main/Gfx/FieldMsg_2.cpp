#include "Main/Gfx/FieldMsg.h"
#include "Main/Sys/Field.h"

extern "C" {

void func_0205592c(GlyphCache *cache);

BOOL func_020559c8(FieldMsg *msg) {
    if (msg->flag16) {
        return FALSE;
    }
    msg->flag15 = 1;
    msg->flag16 = 1;
    msg->unk_35c = 0;
    msg->unk_360 = 0;
    return TRUE;
}

BOOL func_020559f8(s32 id) {
    FieldState *state = data_ov000_021ccd54;
    s32 i;
    for (i = state->head; i != state->tail;) {
        if (id == state->queue[i]) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL Field_IsIdle(void) {
    return data_ov000_021ccd70->unk_04 == NULL ? TRUE : FALSE;
}

BOOL func_02055a4c(void) {
    return Field_IsIdle() ? TRUE : FALSE;
}

void func_02055a78(void) {
    func_ov000_021bc458(data_ov000_021ccd70);
}

void func_02055a90(s32 *p) {
    *p = -1;
}

void *func_02055a9c(u8 *p) {
    return p + 0x134;
}

}
