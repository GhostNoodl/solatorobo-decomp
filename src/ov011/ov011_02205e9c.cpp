#include "ov011/ov011.h"

extern "C" {

void func_ov000_02198360(void *a, s32 b, s32 c);

#pragma force_active on
void func_ov011_02205e9c(void *self) {
    func_ov000_02198360(*(void **)((u8 *)self + 0x40), 1, 0);
}
#pragma force_active reset
}
