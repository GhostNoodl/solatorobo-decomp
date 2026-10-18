#include "ov002/ov002.h"

extern "C" {

typedef struct BgmInfo {
    u16 id : 14;
    u16 type : 2;
} BgmInfo;

BgmInfo *func_0206ee58(u16 id);

void func_0204aab0(void *p);

BOOL func_ov002_021d0270(void *self, void *ev) {
    BgmInfo *info = func_0206ee58(FIELD(ev, 0x8, u32));
    if (info != NULL) {
        {
            u8 *m = data_02097e48;
            FIELD(m, 0x80, u16) = 0x8000;
            FIELD(m, 0x7c, u16) = 0;
        }
        {
            u8 *m = data_02097e48;
            if (FIELD(m, 0x0, Bits16).b3) {
                FIELD(m, 0x6, u16) = 0x8000;
                FIELD(m, 0x8, u16) = 0;
                FIELD(m, 0x2, u16) = 0;
            }
        }
        if (info->type == 0) {
            u16 id = info->id;
            u8 *m = data_02097e48;
            if (FIELD(m, 0x80, u16) != 0xffff || FIELD(m, 0x7e, u16) != id) {
                FIELD(m, 0x80, u16) = id;
                FIELD(m, 0x7c, u16) = 0;
            }
        } else if (info->type == 1) {
            u8 *m;
            u16 id;
            FIELD(data_02097e48, 0x0, Bits16).b0 = 1;
            FIELD(data_02097e48, 0x0, u16) |= 8;
            m = data_02097e48;
            id = info->id;
            if (FIELD(m, 0x0, Bits16).b0) {
                if (FIELD(m, 0x6, u16) != 0xffff || FIELD(m, 0x4, u16) != id) {
                    u16 st;
                    if (FIELD(m, 0x2, u16) != 10 && FIELD(m, 0x2, u16) != 0) {
                        if (FIELD(m, 0x6, u16) != 0xffff) {
                            func_0204aab0(m);
                        }
                        st = 1;
                    } else {
                        st = 0;
                    }
                    FIELD(m, 0x2, u16) = st;
                    FIELD(m, 0x6, u16) = id;
                    FIELD(m, 0x8, u16) = 10;
                }
            }
        }
    }
    return TRUE;
}

}
