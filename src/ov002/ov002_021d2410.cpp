#include "ov002/ov002.h"

extern "C" {

u32 func_ov002_021e4c30(int which);

u32 func_ov002_021e4960(void *self, s32 val);

void func_ov000_0215c1bc(void *a, int b, void *c);

extern VFunc data_ov000_021cad50[];

extern void *data_ov002_021ef634[];

BOOL func_ov002_021d2410(void *self, void *ev) {
    u8 *owner = FIELD(self, 0x8, u8 *);
    if (ev != NULL) {
        u16 idx = FIELD(ev, 0x4, u32);
        s32 n = func_ov002_021e4960(owner + 0x4c + idx * 0x18, func_ov002_021e4c30(idx));
        if (n <= 0) {
            VObject *p;
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            p = (VObject *)func_0203dd9c(0xe8);
            if (p != NULL) {
                *(VFunc **)p = data_ov000_021cac60;
                p->v0x28();
                *(VFunc **)p = data_ov000_021cad50;
                p->v0x28();
            }
            FIELD(owner, 0x48, VObject *) = p;
            func_ov000_0215c1bc(FIELD(owner, 0x48, void *), 0x11, func_0204c0e8(data_02149ef8, 0xf6));
            FIELD(FIELD(owner, 0x48, void *), 0xc, u32) &= ~0x10000;
            FIELD(owner, 0x48, VObject *)->v0x8();
            FIELD(owner, 0x48, VObject *)->v0x70();
        } else {
            u8 *w = (u8 *)func_ov000_0218084c(data_ov000_021ccd44, 0x19, 0);
            if (idx < 7) {
                int mode = func_0206e8f0();
                func_ov002_021d4540(w + 0x44, 0x20, data_ov002_021ef5ac[3], data_ov002_021ef650, mode);
                func_ov002_021d4540(w + 0x64, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac[1], mode);
                func_ov002_021d4540(w + 0x7c, 0x18, data_ov002_021ef634[idx], data_ov002_021ef5ac[0], mode);
                FIELD(w, 0xbc, s32) = idx;
                FIELD(w, 0xc0, s32) = (u16)n;
                func_ov002_021d36b8(w, (u16)(idx * 3));
            }
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        }
    }
    return TRUE;
}

}
