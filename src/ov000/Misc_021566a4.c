#include "types.h"

typedef struct {
    u8 unk_00[0xb8];
    void *unk_b8;
} Obj021566ac;

s32 func_ov000_021566a4(void) {
    return 6;
}

s32 func_ov000_021566ac(Obj021566ac *self) {
    return self->unk_b8 != NULL ? 0x12 : 0;
}
