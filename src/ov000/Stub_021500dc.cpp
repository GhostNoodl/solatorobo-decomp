#include "ov000/VObj.h"

extern "C" void *data_ov000_021ccd40;

static inline BOOL IsCur_Inline(void *self) { return data_ov000_021ccd40 == self; }

extern "C" {

void func_ov000_0214f188(void *a, s32 b);

bool func_ov000_021500dc(void *self) {
    return IsCur_Inline(self);
}

BOOL func_ov000_02150104(void *self, void *p) {
    void *q = *(void **)((u8 *)self + 8);
    if (p != NULL) {
        func_ov000_0214f188(q, *(u16 *)((u8 *)p + 0x30));
    } else {
        func_ov000_0214f188(q, -1);
    }
    return TRUE;
}

}
