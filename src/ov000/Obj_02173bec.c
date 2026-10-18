#include "types.h"

typedef struct {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x34];
    s32 unk_40;
    s32 unk_44;
} Obj02173bec;

void func_ov000_02173bec(Obj02173bec *self) {
    if (self->unk_08 != 0xd) {
        return;
    }
    self->unk_40 += 0x8000;
    self->unk_44 += 0x8000;
    if (self->unk_40 >= 0x1000000) {
        self->unk_40 -= 0x1000000;
    }
    if (self->unk_44 >= 0x1000000) {
        self->unk_44 -= 0x1000000;
    }
}
