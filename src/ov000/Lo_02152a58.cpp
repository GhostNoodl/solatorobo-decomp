#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"

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


BOOL func_ov000_02152a58(UiObj *self) {
    BOOL ok = TRUE;
    if (self->model && !func_02054f10(self->model, 0xffff)) {
        ok = FALSE;
    }
    if (((u8 *)self->title) && !LoResDone(((u8 *)self->title))) {
        ok = FALSE;
    }
    if (((u8 *)self->caption) && !LoResDone(((u8 *)self->caption))) {
        ok = FALSE;
    }
    return ok;
}

}
