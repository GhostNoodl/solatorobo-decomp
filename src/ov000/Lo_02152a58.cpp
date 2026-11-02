#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_0216bae4(void *dst, void *src);
BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
void func_ov000_0215eab4(void *p);

static inline BOOL LoResDone(u8 *o) {
    if (LFLD(void *, o, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, o, 0x6c))) {
        LFLD(void *, o, 0x6c) = NULL;
    } else {
        return LBIT(o, 4).b6 ? FALSE : TRUE;
    }
    return TRUE;
}

struct Obj02152a58 {
    u8 unk_00[0x10];
    void *unk_10;
    u8 *unk_14;
    u8 *unk_18;
};

BOOL func_ov000_02152a58(Obj02152a58 *self) {
    BOOL ok = TRUE;
    if (self->unk_10 && !func_02054f10(self->unk_10, 0xffff)) {
        ok = FALSE;
    }
    if (self->unk_14 && !LoResDone(self->unk_14)) {
        ok = FALSE;
    }
    if (self->unk_18 && !LoResDone(self->unk_18)) {
        ok = FALSE;
    }
    return ok;
}

}
