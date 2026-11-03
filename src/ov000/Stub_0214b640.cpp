#include "ov000/TwlRequest.h"

extern "C" {

BOOL func_ov000_0214b640(Twl0214b570 *self) {
    return self->state == 2;
}

/* Nothing references this one, so keep the linker from stripping it. */
#pragma force_active on
BOOL func_ov000_0214b654(Twl0214b570 *self) {
    return self->state == 2 && self->unk_08 == -1 ? TRUE : FALSE;
}
#pragma force_active reset

}
