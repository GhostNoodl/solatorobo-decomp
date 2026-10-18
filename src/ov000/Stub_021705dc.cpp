#include "ov000/VObj.h"

static inline BOOL NotNull54_Inline(void *self) { return *(void **)((u8 *)self + 0x54) != NULL; }

extern "C" {

void func_ov000_0216ca64(void *self, s32 a, s32 b);

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
