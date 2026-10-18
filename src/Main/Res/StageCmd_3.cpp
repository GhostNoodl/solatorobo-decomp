#include "Main/Res/StageCmd.h"

extern "C" {

int func_0205cb9c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state = data_ov000_021ccd54;
    state->unk_0d3 = 0;
    state->bits190.flag0 = 1;
    return 1;
}

}
