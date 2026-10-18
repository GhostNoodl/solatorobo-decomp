#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Obj02152f7c;

void func_ov000_02152f78(void) {
}

void func_ov000_02152f7c(Obj02152f7c *self) {
    self->unk_0c |= 0x200;
}
