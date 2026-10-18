#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d79d0(void *p);

#pragma force_active on
void *func_ov011_021fc0a0(void *self) {
    func_ov003_021d79d0((u8 *)self + 8);
    return self;
}
#pragma force_active reset
}
