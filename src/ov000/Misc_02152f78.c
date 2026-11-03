#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Obj02152f7c;

void UiObj_PostUpdate(void) {
}

void UiObj_DrawBody(Obj02152f7c *self) {
    self->unk_0c |= 0x200;
}
