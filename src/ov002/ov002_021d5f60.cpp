#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3620(void *self, void *a, s32 b);

BOOL func_ov000_0219bf90(void);

void func_ov000_021b1d28(void);

void func_0206d390(void *a, u8 b, u8 c);

s32 func_02049bdc(void *a, int b, int c);

void func_ov002_021d5f60(void *self) {
    void *g = FIELD(self, 0x50, void *);
    u16 prev;
    u8 *p;
    u8 i;
    if (g == NULL) {
        return;
    }
    prev = FIELD(self, 0x74, u16);
    p = FIELD(g, 0x98, u8 *);
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = FIELD(g, 0xb1, s8);
        while (n-- != 0) {
            p = FIELD(p, 0x2c, u8 *);
        }
    }
    FIELD(self, 0x74, u16) = FIELD(p, 0x6, u16);
    func_ov002_021e3620(FIELD(self, 0x50, void *), (void *)(u32)prev, 0);
    func_ov002_021e3620(FIELD(self, 0x50, void *), (void *)(u32)FIELD(self, 0x74, u16), 4);
    func_ov000_0215bb14(FIELD(self, 0x4c, void *), func_0206ec48(FIELD(self, 0x74, u16)));
    FIELD(self, 0x4c, VObject *)->v0x70();
    FIELD(data_0214a424, 0x18, Bits021d9e38).id = FIELD(self, 0x74, u16);
    if (func_ov000_0219bf90()) {
        func_ov000_021b1d28();
    } else {
        FIELD(data_0214a424, 0x18, Bits021d9e38).mode = 1;
    }
    for (i = 0; i < 5; i++) {
        s16 v = ((s16 *)((u8 *)self + 0x60))[i] + ((s16 *)((u8 *)self + 0x6a))[i];
        if (v < 0) {
            v = 0;
        } else if (v > 99) {
            v = 99;
        }
        func_0206d390(data_0214a424, i, (s8)v);
    }
    func_02049bdc(data_02097e4c, 0x2c, -5);
    func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
}

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

void func_ov000_021c95fc(void *p);

BOOL func_ov000_021633ac(void *p);

void func_ov000_02162a20(void *p);

static inline void *ov002_cursor60dc(void *g) {
    u8 *p = FIELD(g, 0x98, u8 *);
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = FIELD(g, 0xb1, s8);
        while (n-- != 0) {
            p = FIELD(p, 0x2c, u8 *);
        }
    }
    return p;
}

void func_ov002_021d60dc(void *self) {
    switch (FIELD(self, 0x8, s32)) {
    case 8:
        FIELD(FIELD(self, 0x4c, void *), 0xc, u32) &= ~2;
        FIELD(FIELD(self, 0x50, void *), 0xc, u32) &= ~2;
        FIELD(FIELD(self, 0x54, void *), 0xc, u32) &= ~2;
        break;
    case 13: {
        BOOL a = isState5(FIELD(self, 0x50, void *));
        if (a) {
            BOOL b = isState5(FIELD(self, 0x54, void *));
            if (b) {
                void *x = func_ov000_02173610(0x1b);
                if (x != NULL) {
                    u8 buf[0x14];
                    func_ov000_021c95fc(buf);
                    if (FIELD(x, 0x3c, void *) != NULL) {
                        MI_CpuCopy8(buf, (u8 *)FIELD(x, 0x3c, void *) + 0x2c, 0x14);
                    }
                    if (FIELD(x, 0x3c, void *) != NULL) {
                        func_ov002_021e2690(FIELD(x, 0x3c, void *), 0, 0);
                    }
                    if (FIELD(x, 0x3c, void *) != NULL) {
                        func_ov002_021e2754(FIELD(x, 0x3c, void *), 0xffff);
                    }
                }
                FIELD(self, 0x4, u32) |= 6;
                FIELD(self, 0x18, s32) = 0x1c;
            }
        }
        break;
    }
    }
    func_ov000_02162a20(FIELD(self, 0x58, void *));
    if (FIELD(self, 0x5c, void *) != NULL && !func_ov000_021633ac(FIELD(self, 0x5c, void *))) {
        u8 *p;
        u16 id;
        void *x;
        {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0x5c, VObject *));
            HEAP_POP(saved);
        }
        FIELD(FIELD(self, 0x50, void *), 0xc, u32) &= ~4;
        FIELD(FIELD(self, 0x54, void *), 0xc, u32) &= ~4;
        FIELD(FIELD(self, 0x54, void *), 0xc, u32) &= ~2;
        FIELD(self, 0x54, VObject *)->v0x1c();
        p = (u8 *)ov002_cursor60dc(FIELD(self, 0x50, void *));
        id = FIELD(p, 6, u16);
        if (FIELD(self, 0x54, void *) != NULL) {
            func_ov000_0215bb14(FIELD(self, 0x54, void *), func_0206ec8c(id));
            FIELD(self, 0x54, VObject *)->v0x70();
        }
        x = func_ov000_02173610(0x1b);
        if (x != NULL && FIELD(x, 0x3c, void *) != NULL) {
            func_ov002_021e2690(FIELD(x, 0x3c, void *), 9, 0);
        }
    }
    FIELD(self, 0x4c, VObject *)->v0x1c();
    FIELD(self, 0x50, VObject *)->v0x1c();
    FIELD(self, 0x54, VObject *)->v0x1c();
}

}
