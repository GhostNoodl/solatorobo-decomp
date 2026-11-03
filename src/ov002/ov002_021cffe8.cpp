#include "ov002/ov002.h"

extern "C" {


void Task021ef79c_UpdateActive(Task021ef79c *self) {
    u16 keys;
    u16 id;
    UiListItem *item;
    keys = data_02097dc8->trig;
    item = UiList_GetCurrent(self->unk_3c);
    id = item->id;
    if (id != self->unk_44) {
        void *s;
        switch (id) {
        case 0xb:
            s = MsgRes_GetString(data_02149ef8, 0xf3);
            break;
        case 0x14:
            s = MsgRes_GetString(data_02149ef8, 0xf4);
            break;
        }
        Obj0215bb14_SetText(self->unk_40, s);
        self->unk_40->vfunc_70();
    }
    self->unk_44 = id;
    if (keys & 2) {
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->vfunc_0c(0);
        return;
    }
    if (keys & 1) {
        item = UiList_GetCurrent(self->unk_3c);
        if ((s32)item->unk_10 >= 0) {
            TaskHost_RequestSwitch(data_ov000_021ccd44, item->id, (int)self->param);
            SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
            self->unk_3c->flags |= 2;
            self->unk_40->flags |= 2;
        } else {
            SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
}

}
