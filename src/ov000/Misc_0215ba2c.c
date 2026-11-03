#include "types.h"

typedef struct {
    u8 unk_00[0xd4];
    void *unk_d4;
} Obj0215ba34;

s32 LoBase021cafc0_021cb0b8_GetPadLeft(void) {
    return 0;
}

s32 LoBase021cafc0_021cb0b8_GetPadTop(Obj0215ba34 *self) {
    return (self->unk_d4 != NULL ? 0x10 : 0) + 0xa;
}
