#include "ov002/ov002.h"

extern "C" {

extern u8 data_ov002_021efe30[];

static inline BOOL ov002_Menu_IsBusy(u8 *m) {
    return (FIELD(m, 0x98, s32) != FIELD(m, 0xa4, s32) || FIELD(m, 0xb3, s8) != 0) ? TRUE : FALSE;
}

static inline u8 *ov002_Menu_GetSel(u8 *m) {
    u8 *p = FIELD(m, 0x98, u8 *);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = FIELD(m, 0xb1, s8);
    while (n-- != 0) {
        p = FIELD(p, 0x2c, u8 *);
    }
    return p;
}

static inline void ov002_Menu_Close(void *self) {
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) |= 2;
    FIELD(FIELD(self, 0x10, void *), 0xc, u32) |= 2;
    *(u8 *)data_ov002_021f0f90 = FIELD(self, 0x14, s32);
    FIELD(self, 0x18, s32) = 2;
    if (FIELD(self, 0x8, s32) == 2 || FIELD(self, 0x8, s32) == 3) {
        func_0203cc58(0xa000, 2, -1);
    }
}

void func_ov002_021db2a4(void *self) {
    u16 id;
    u32 flags;
    if (FIELD(self, 0x18, s32) >= 2) {
        return;
    }
    if (FIELD(self, 0xc, void *) != NULL) {
        if (ov002_Menu_IsBusy(FIELD(self, 0xc, u8 *))) {
            return;
        }
        if (!FIELD(self, 0xc, VObject *)->v0xc()) {
            return;
        }
    }
    id = FIELD(ov002_Menu_GetSel(FIELD(self, 0xc, u8 *)), 0x6, u16);
    if (FIELD(self, 0x14, s32) != id && FIELD(self, 0x10, void *) != NULL) {
        void *str;
        void *g = data_02149ef8;
        switch (id) {
        case 0:
            str = func_0204c0e8(g, 0xbd);
            break;
        case 1:
            str = func_0204c0e8(g, 0xbf);
            break;
        case 2:
            str = func_0204c0e8(g, 0xfb);
            break;
        default:
            str = data_ov002_021efe30;
            break;
        }
        func_ov000_0215bb14(FIELD(self, 0x10, void *), str);
        FIELD(self, 0x10, VObject *)->v0x70();
    }
    FIELD(self, 0x14, s32) = id;
    flags = FIELD(self, 0x1c, u32);
    if (flags & 1) {
        switch (id) {
        case 0:
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            FIELD(self, 0x8, s32) = 1;
            ov002_Menu_Close(self);
            break;
        case 1:
            if (FIELD(self, 0x20, u8) == 0) {
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                FIELD(self, 0x8, s32) = 2;
                ov002_Menu_Close(self);
            } else {
                void *str;
                void *g;
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                g = data_02149ef8;
                str = NULL;
                if (FIELD(self, 0x20, u8) == 1) {
                    str = func_0204c0e8(g, 0xc0);
                } else if (FIELD(self, 0x20, u8) == 2) {
                    str = func_0204c0e8(g, 0xc1);
                }
                if (str != NULL) {
                    func_ov000_0215bb14(FIELD(self, 0x10, void *), str);
                    FIELD(self, 0x10, VObject *)->v0x70();
                }
            }
            break;
        case 2:
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            FIELD(self, 0x8, s32) = 3;
            ov002_Menu_Close(self);
            break;
        }
    } else if (flags & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        FIELD(self, 0x8, s32) = 3;
        ov002_Menu_Close(self);
    }
    FIELD(self, 0x1c, u32) = 0;
}

}
