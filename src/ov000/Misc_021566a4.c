#include "types.h"

typedef struct {
    u8 unk_00[0xb8];
    void *unk_b8;
} Obj021566ac;

s32 UiList_GetPadTop(void) {
    return 6;
}

s32 UiList_GetIconWidth(Obj021566ac *self) {
    return self->unk_b8 != NULL ? 0x12 : 0;
}
