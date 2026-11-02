#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021d3c30(UiList *self, UiListItem *ev) {
    Task021ef81c *t = (Task021ef81c *)self->owner;
    Lo021cadcc *w = t->unk_40;
    if (ev != NULL && ev->id != 0) {
        if (t->unk_4c == 0) {
            func_ov000_0215bb14(w, MsgRes_GetString(data_02149ef8, 0xf3));
            w->vfunc_70();
            t->unk_4c = 1;
        }
    } else {
        func_ov000_0215bb14(w, MsgRes_GetString(data_02149ef8, 0x9d));
        w->vfunc_70();
        t->unk_4c = 0;
    }
    return TRUE;
}

}
