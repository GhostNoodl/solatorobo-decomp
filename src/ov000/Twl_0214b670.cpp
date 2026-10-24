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

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
s32 func_02224e44(s32 a);
s32 func_02224eb8(s32 a);

#pragma force_active on

s32 func_ov000_0214b670(Twl0214b570 *self) {
    if (self->state == 2 && self->unk_08 == -1) {
        return self->unk_0c;
    }
    return 0;
}

s32 func_ov000_0214b68c(Twl0214b570 *self) {
    s32 w = func_02224e44(4);
    s32 h = func_02224eb8(4);
    s32 size = w * h * 2;
    if (self->state == 2 && self->unk_08 == -1) {
        return size;
    }
    return 0;
}

#pragma force_active reset

}
