#include "ov000/TwlRequest.h"

extern "C" {

Twl0214b570 *Twl0214b570_Init(Twl0214b570 *self) {
    self->unk_00 = 0;
    self->state = 0;
    self->unk_08 = -1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    return self;
}

}
