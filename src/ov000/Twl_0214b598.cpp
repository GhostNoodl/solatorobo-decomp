#include "ov000/TwlRequest.h"

extern "C" {

BOOL OS_IsRunOnTwl(void);

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
void func_0222e6d0(Twl0214b570 *self);
void func_0222e2a4(Twl0214b570 *self);

#pragma force_active on

Twl0214b570 *Twl0214b570_Dtor(Twl0214b570 *self) {
    if (OS_IsRunOnTwl()) {
        func_0222e6d0(self);
    }
    return self;
}

void Twl0214b570_Poll(Twl0214b570 *self) {
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
