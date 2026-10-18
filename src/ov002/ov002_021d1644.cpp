#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1644(void *self) {
    if (FIELD(self, 0x68, u8) == 0 && FIELD(self, 0x8, s32) == 0xd && FIELD(self, 0x64, s32) == 1) {
        func_ov002_021e90dc();
    }
}

BOOL func_ov002_021d166c(void *self) {
    BOOL result = TRUE;
    switch (FIELD(self, 0x64, s32)) {
    case 0:
        if (FIELD(self, 0x5c, s32) < 8 && ((s32 *)((u8 *)self + 0x3c))[FIELD(self, 0x5c, s32)] >= 0) {
            func_0203caf8(-1);
            func_020444b0(data_02097e3c, ((s32 *)((u8 *)self + 0x3c))[FIELD(self, 0x5c, s32)], -1, 0);
            FIELD(self, 0x64, s32) = 1;
        } else {
            func_0203cc58(0xa000, 2, 0);
            FIELD(self, 0x64, s32) = 2;
        }
        break;
    case 1:
        if (FIELD(data_02097dc8, 0x12, u16) & 0xa) {
            func_02044524(data_02097e3c);
        }
        if (FIELD(data_02097e3c, 0x149, u8) == 0) {
            FIELD(self, 0x64, s32) = 0;
            FIELD(self, 0x5c, s32)++;
        }
        break;
    case 2:
        if (func_ov002_isMode4()) {
            result = FALSE;
        }
        break;
    }
    return result;
}

BOOL func_ov002_021d178c(void *self) {
    BOOL result = TRUE;
    switch (FIELD(self, 0x64, s32)) {
    case 0:
        if (FIELD(self, 0x5c, s32) < 8 && ((s32 *)((u8 *)self + 0x3c))[FIELD(self, 0x5c, s32)] >= 0) {
            func_ov002_021e8f04(((s32 *)((u8 *)self + 0x3c))[FIELD(self, 0x5c, s32)]);
            FIELD(self, 0x64, s32) = 1;
        } else {
            FIELD(self, 0x64, s32) = 2;
            break;
        }
    case 1:
        if (FIELD(data_02097dc8, 0x12, u16) & 2) {
            func_ov002_021e9b28(FIELD(data_ov002_021f0f9c, 0xd0, void *));
            FIELD(self, 0x5c, s32) = 7;
        }
        if (!func_ov002_021e90ac()) {
            func_ov002_021e916c();
            FIELD(self, 0x64, s32) = 0;
            FIELD(self, 0x5c, s32)++;
        }
        break;
    case 2:
        result = FALSE;
        break;
    }
    return result;
}

Task50 *func_ov002_021d184c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x68);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef69c;
        FIELD(p, 0x3c, s32) = 0;
        FIELD(p, 0x40, s32) = 0;
        FIELD(p, 0x44, s32) = 0;
        FIELD(p, 0x48, s32) = 0;
        FIELD(p, 0x4c, s32) = 0;
        FIELD(p, 0x50, s32) = 0;
        FIELD(p, 0x54, s32) = 0;
        FIELD(p, 0x58, s32) = 0;
        FIELD(p, 0x5c, s32) = 0;
        FIELD(p, 0x60, s32) = 0;
        FIELD(p, 0x64, s32) = 0;
    }
    p->v0x8(0x17, 0x64);
    return p;
}

BOOL func_ov002_021d18d4(void *self, void *arg) {
    func_ov000_021c64b4(self, FIELD(arg, 0x40, void *));
    return TRUE;
}

BOOL func_ov002_021d18e8(void *self, void *ev) {
    void *owner = FIELD(self, 0x8, void *);
    if (FIELD(ev, 0x52, u8) != 0) {
        if (FIELD(ev, 0x58, s32) <= 0x99a) {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            FIELD(owner, 0x44, void *) = ev;
            func_ov000_021c7000(FIELD(owner, 0x3c, void *));
            FIELD(ev, 0x6c, u8) = 1;
        }
    } else {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
    }
    return TRUE;
}

}
