#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021d3c30(void *self, void *ev) {
    u8 *t = FIELD(self, 8, u8 *);
    VObject *w = FIELD(t, 0x40, VObject *);
    if (ev != NULL && FIELD(ev, 6, u16) != 0) {
        if (t[0x4c] == 0) {
            func_ov000_0215bb14(w, func_0204c0e8(data_02149ef8, 0xf3));
            w->v0x70();
            t[0x4c] = 1;
        }
    } else {
        func_ov000_0215bb14(w, func_0204c0e8(data_02149ef8, 0x9d));
        w->v0x70();
        t[0x4c] = 0;
    }
    return TRUE;
}

}
