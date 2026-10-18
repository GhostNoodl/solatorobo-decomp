#include "ov002/ov002.h"

extern "C" {

static inline u8 *ov002_getSelected(void *list) {
    u8 *item = FIELD(list, 0x98, u8 *);
    if (item == NULL) {
        item = NULL;
    } else {
        s32 n = FIELD(list, 0xb1, s8);
        while (n-- != 0) {
            item = FIELD(item, 0x2c, u8 *);
        }
    }
    return item;
}

void func_ov002_021cffe8(void *self) {
    u16 keys;
    u16 id;
    u8 *item;
    keys = FIELD(data_02097dc8, 0x12, u16);
    item = ov002_getSelected(FIELD(self, 0x3c, void *));
    id = FIELD(item, 0x6, u16);
    if (id != FIELD(self, 0x44, u16)) {
        void *s;
        switch (id) {
        case 0xb:
            s = func_0204c0e8(data_02149ef8, 0xf3);
            break;
        case 0x14:
            s = func_0204c0e8(data_02149ef8, 0xf4);
            break;
        }
        func_ov000_0215bb14(FIELD(self, 0x40, void *), s);
        FIELD(self, 0x40, VObject *)->v0x70();
    }
    FIELD(self, 0x44, u16) = id;
    if (keys & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        FIELD(FIELD(self, 0x3c, void *), 0xc, u32) |= 2;
        FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 2;
        ((VObject *)self)->v0xc(0);
        return;
    }
    if (keys & 1) {
        item = ov002_getSelected(FIELD(self, 0x3c, void *));
        if (FIELD(item, 0x10, s32) >= 0) {
            func_ov000_0218084c(data_ov000_021ccd44, FIELD(item, 0x6, u16), (int)FIELD(self, 0xc, s32));
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            FIELD(FIELD(self, 0x3c, void *), 0xc, u32) |= 2;
            FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 2;
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
}

}
