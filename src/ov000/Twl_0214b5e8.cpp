#include "ov000/TwlRequest.h"

extern "C" {

BOOL OS_IsRunOnTwl(void);

void Twl0214b570_Start(Twl0214b570 *self, const char *arg) {
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
