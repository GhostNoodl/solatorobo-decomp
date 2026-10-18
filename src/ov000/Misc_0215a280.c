#include "types.h"

typedef struct {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c_0 : 1;
    u32 unk_0c_1 : 1;
    u32 unk_0c_2 : 30;
    u8 unk_10[0x20];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
} Obj0215a284;

static inline void Obj0215a284_SetFlag0(Obj0215a284 *self) {
    self->unk_0c_0 = 1;
}

void func_ov000_0215a280(void) {
}

void func_ov000_0215a284(Obj0215a284 *self) {
    if (self->unk_04 != 2) {
        return;
    }
    self->unk_30 = self->unk_34;
    self->unk_38 = 0x1000;
    if (self->unk_0c_1) {
        Obj0215a284_SetFlag0(self);
        self->unk_04 = 1;
    }
}
