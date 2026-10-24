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

BOOL OS_IsRunOnTwl(void);

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
void func_0222e6d0(Twl0214b570 *self);
void func_0222e2a4(Twl0214b570 *self);

#pragma force_active on

Twl0214b570 *func_ov000_0214b598(Twl0214b570 *self) {
    if (OS_IsRunOnTwl()) {
        func_0222e6d0(self);
    }
    return self;
}

void func_ov000_0214b5bc(Twl0214b570 *self) {
    if (!OS_IsRunOnTwl()) {
        return;
    }
    if (self->state != 1) {
        return;
    }
    func_0222e2a4(self);
}

#pragma force_active reset

}
