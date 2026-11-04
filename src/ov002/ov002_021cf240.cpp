#include "ov002/ov002.h"

extern "C" {

void CabinMenu_PostUpdate(void) {
}

void CabinMenu_Draw(Task021ef4b0 *self) {
    if (self->fadeRatio != 0) {
        Task_Draw(self);
        self->unk_3c->vfunc_20();
        self->unk_40->vfunc_20();
    }
}

void CabinMenu_SetItemHelp(Task021ef4b0 *self, int kind) {
    void *msg;
    void *str;
    if (self->unk_40 == NULL) {
        return;
    }
    msg = gMsgRes;
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
    Obj0215bb14_SetText(self->unk_40, str);
    self->unk_40->vfunc_70();
}

}
