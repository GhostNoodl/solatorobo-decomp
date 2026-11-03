#include "ov000/TwlRequest.h"

extern "C" {

BOOL Twl0214b570_IsDone(Twl0214b570 *self) {
    return self->state == 2;
}

/* Nothing references this one, so keep the linker from stripping it. */
#pragma force_active on
BOOL Twl0214b570_HasResult(Twl0214b570 *self) {
    return self->state == 2 && self->unk_08 == -1 ? TRUE : FALSE;
}
#pragma force_active reset

}
