#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021d3c30(void *self, void *ev) {
    u8 *t = FIELD(self, 8, u8 *);
    VObj *w = FIELD(t, 0x40, VObj *);
    if (ev != NULL && FIELD(ev, 6, u16) != 0) {
        if (t[0x4c] == 0) {
            func_ov000_0215bb14(w, MsgRes_GetString(data_02149ef8, 0xf3));
            w->vfunc_70();
            t[0x4c] = 1;
        }
    } else {
        func_ov000_0215bb14(w, MsgRes_GetString(data_02149ef8, 0x9d));
        w->vfunc_70();
        t[0x4c] = 0;
    }
    return TRUE;
}

}
