#include "ov000/VObj.h"

static inline BOOL NotNull54_Inline(void *self) { return *(void **)((u8 *)self + 0x54) != NULL; }

extern "C" {

void func_ov000_0216ca64(void *self, s32 a, s32 b);

BOOL func_ov000_02170568(void *self) {
    if (*(s32 *)((u8 *)self + 0x24) == 7 || *(s32 *)((u8 *)self + 0x3c) != 0 ||
        *(s32 *)((u8 *)self + 0x40) != 0 || *(s32 *)((u8 *)self + 0x44) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021705a0(void *self, s32 check) {
    void *p = *(void **)((u8 *)self + 0x34);
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

void func_ov000_021705dc(void *self, s32 a, s32 b) {
    func_ov000_0216ca64(*(void **)((u8 *)self + 0x50), a, b);
}

bool func_ov000_021705ec(void *self) {
    return NotNull54_Inline(self);
}

s32 func_ov000_0217060c(void *self) {
    return *(void **)((u8 *)self + 0x48) != NULL ? 0x1 : 0x0;
}

}
