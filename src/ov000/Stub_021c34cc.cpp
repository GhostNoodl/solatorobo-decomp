#include "ov000/VObj.h"

extern "C" {

BOOL func_02054f10(void *p, s32 a);
void func_ov000_021c34fc(void *self);

void func_ov000_021c34cc(void *self) {
    void *p = *(void **)((u8 *)self + 0x38);
    if (p == NULL) {
        return;
    }
    if (func_02054f10(p, 0) == 0) {
        return;
    }
    func_ov000_021c34fc(self);
}

}
