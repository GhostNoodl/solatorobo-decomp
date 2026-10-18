#include "types.h"

typedef struct {
    u16 unk_00;
    s32 state;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Twl0214b570;

extern "C" {

void func_ov000_0214b570(Twl0214b570 *self) {
    self->unk_00 = 0;
    self->state = 0;
    self->unk_08 = -1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
}

}
