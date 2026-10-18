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

void func_ov000_0214b5e8(Twl0214b570 *self, s32 arg) {
    if (OS_IsRunOnTwl()) {
        if (self->state != 0) {
            return;
        }
        self->unk_00 = 0;
        self->state = 1;
        self->unk_08 = -1;
        self->unk_10 = arg;
        return;
    }
    self->state = 2;
    self->unk_08 = 0;
}

}
