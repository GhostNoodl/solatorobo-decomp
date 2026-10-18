#include "ov014/ov014.h"

extern "C" {

extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

s32 func_ov014_022128f4(Ov014Actor *self, Ov014Msg *msg) {
    s32 r = 0;
    if (msg->type == 6) {
        FLD(u16, self, 0x310) |= msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}

}
