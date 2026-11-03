#include "ov002/ov002.h"

extern "C" {

BOOL Task021ef81c_List3cOnCursor(UiList *self, UiListItem *ev) {
    Task021ef81c *t = (Task021ef81c *)self->owner;
    Lo021cadcc *w = t->unk_40;
    if (ev != NULL && ev->id != 0) {
        if (t->unk_4c == 0) {
            Obj0215bb14_SetText(w, MsgRes_GetString(gMsgRes, 0xf3));
            w->vfunc_70();
            t->unk_4c = 1;
        }
    } else {
        Obj0215bb14_SetText(w, MsgRes_GetString(gMsgRes, 0x9d));
        w->vfunc_70();
        t->unk_4c = 0;
    }
    return TRUE;
}

}
