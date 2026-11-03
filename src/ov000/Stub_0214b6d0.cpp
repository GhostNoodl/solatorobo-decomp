#include "ov000/TwlRequest.h"

extern "C" {

u32 Twl0214b570_GetStatus(Twl0214b570 *self) {
    return self->unk_08;
}

}
