#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cf240(void) {
}

void func_ov002_021cf244(Task021ef4b0 *self) {
    if (self->fadeRatio != 0) {
        func_ov000_0217357c(self);
        self->unk_3c->vfunc_20();
        self->unk_40->vfunc_20();
    }
}

void func_ov002_021cf280(Task021ef4b0 *self, int kind) {
    void *msg;
    void *str;
    if (self->unk_40 == NULL) {
        return;
    }
    msg = data_02149ef8;
    str = data_ov002_021ef3f8;
    switch (kind) {
    case 0:
        str = MsgRes_GetString(msg, 0xea);
        break;
    case 1:
        str = MsgRes_GetString(msg, 0xed);
        break;
    case 2:
        str = MsgRes_GetString(msg, 0xf0);
        break;
    case 3:
        str = MsgRes_GetString(msg, 0xe7);
        break;
    case 4:
        str = MsgRes_GetString(msg, 0xe4);
        break;
    }
    func_ov000_0215bb14(self->unk_40, str);
    self->unk_40->vfunc_70();
}

}
