#include "ov002/ov002.h"

extern "C" {

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

void func_ov000_0215d980(void *a, u16 b, int c);

void func_ov002_021d9ed8(void *a, void *b, int c);

void *func_ov002_021e3874(s32 *v, int a, int b);

void *func_02065f88(int a, s32 *v);

void func_ov002_021dd7f0(void *self, void *a, void *b, int c);

void func_ov002_021dd130(void *self) {
    s32 out[3];
    s32 a[2];
    s32 b[2];
    u8 *e;
    {
        BOOL st = isState5(FIELD(self, 0xc, void *));
        if (!st) {
            return;
        }
    }
    e = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    if (FIELD(self, 0x1c, s32) == 0) {
        u16 y = FIELD(FIELD(self, 0x2c, u8 *), 0xa8, u16);
        u16 x = FIELD(e, 0x8a, u16);
        FIELD(e, 0x8a, u16) = x > y ? x - y : 0;
        func_ov000_0215d980(FIELD(FIELD(self, 0x4, u8 *), 0x24, void *), FIELD(e, 0x8a, u16), 0);
        func_ov002_021d9ed8(e, FIELD(self, 0x2c, void *), 1);
        func_02049a48(data_02097e4c, 0x6e, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
        a[0] = FIELD(FIELD(self, 0x2c, u8 *), 0x54, s32);
        a[1] = FIELD(FIELD(self, 0x2c, u8 *), 0x58, s32);
        b[0] = FIELD(FIELD(self, 0x2c, u8 *), 0x64, s32);
        b[1] = FIELD(FIELD(self, 0x2c, u8 *), 0x68, s32);
        func_ov002_021e3b0c(out, a, b);
        out[1] = 0x266;
        func_ov002_021e3874(out, 0x80, 1);
        func_02065f88(0x6d, out);
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    FIELD(self, 0x18, s32) = 10;
    FIELD(self, 0x2c, void *) = NULL;
}

static inline bool ov002_flag1(void *p) {
    return FIELD(p, 0xc, Bits32).b1;
}

void func_ov002_021d9ed8(void *self, void *node, BOOL del);

s32 func_02049bdc(void *a, int b, int c);

void func_ov002_021dd29c(void *self) {
    switch (FIELD(self, 0x18, s32)) {
    case 0x28: {
        BOOL t = ov002_flag1(FIELD(self, 0xc, void *));
        if (!t) {
            return;
        }
        if (FIELD(self, 0x1c, s32) == 0) {
            u8 *o = FIELD(self, 0x30, u8 *);
            if (FIELD(o, 0xac, s32) != 8 && FIELD(o, 0xa4, s32) == 0) {
                func_ov002_021e3b0c((s32 *)(o + 0xbc), (s32 *)(o + 0x54), (s32 *)(o + 0x64));
                FIELD(o, 0xc0, s32) = 0x400;
                FIELD(o, 0xb0, s32) = 0xb33;
                FIELD(o, 0xb8, s32) = 0;
                FIELD(o, 0xb4, s32) = 0x400;
                FIELD(o, 0xa4, s32) = 0x14;
                FIELD(o, 0xa8, s32) = 0x14;
                FIELD(o, 0xac, s32) = 8;
            }
            FIELD(self, 0x18, s32)++;
            func_02049bdc(data_02097e4c, 0x47, -5);
        } else {
            FIELD(self, 0x18, s32) += 2;
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
        break;
    }
    case 0x29: {
        u8 *o = FIELD(self, 0x30, u8 *);
        u8 *q;
        if (FIELD(o, 0xac, s32) != 0) {
            return;
        }
        q = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
        (q + 8)[(u16)(FIELD(o, 0x48, u16) & 0xfff)]++;
        func_ov002_021d9ed8(q, o, 1);
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
        FIELD(self, 0x18, s32)++;
        break;
    }
    case 0x2a:
        {
            BOOL st = isState5(FIELD(self, 0xc, void *));
            if (st) {
                FIELD(self, 0x18, s32) = 10;
            }
        }
        break;
    }
}

extern u8 data_ov002_021efe30[];

void func_ov002_021dd434(void *self) {
    u8 *w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    u8 *o;
    switch (FIELD(self, 0x18, s32)) {
    case 0x32: {
        BOOL t = ov002_flag1(FIELD(self, 0xc, void *));
        if (!t) {
            return;
        }
        if (FIELD(self, 0x1c, s32) == 0) {
            u8 *m;
            for (o = FIELD(w, 0x6c, u8 *); o != NULL; o = FIELD(o, 0x70, u8 *)) {
                if (FIELD(o, 0x4a, u8) == 1 && FIELD(o, 0xac, s32) != 8 && FIELD(o, 0xa4, s32) == 0) {
                    func_ov002_021e3b0c((s32 *)(o + 0xbc), (s32 *)(o + 0x54), (s32 *)(o + 0x64));
                    FIELD(o, 0xc0, s32) = 0x400;
                    FIELD(o, 0xb0, s32) = 0xb33;
                    FIELD(o, 0xb8, s32) = 0;
                    FIELD(o, 0xb4, s32) = 0x400;
                    FIELD(o, 0xa4, s32) = 0x14;
                    FIELD(o, 0xa8, s32) = 0x14;
                    FIELD(o, 0xac, s32) = 8;
                }
            }
            m = FIELD(self, 0x4, u8 *);
            func_ov000_0215bb14(FIELD(m, 0x20, void *), data_ov002_021efe30);
            FIELD(m, 0x20, VObject *)->v0x70();
            FIELD(self, 0x18, s32)++;
            func_02049bdc(data_02097e4c, 0x5c, 5);
        } else {
            FIELD(self, 0x18, s32) += 2;
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
        break;
    }
    case 0x33: {
        bool all = TRUE;
        u8 *next;
        for (o = FIELD(w, 0x6c, u8 *); o != NULL; o = FIELD(o, 0x70, u8 *)) {
            if (FIELD(o, 0x4a, u8) == 1) {
                all &= FIELD(o, 0xac, s32) == 0;
            }
        }
        if (!all) {
            return;
        }
        for (o = FIELD(w, 0x6c, u8 *); o != NULL; o = next) {
            next = FIELD(o, 0x70, u8 *);
            if (FIELD(o, 0x4a, u8) == 1) {
                u8 *q = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
                (&FIELD(q, 8, u8))[(u16)(FIELD(o, 0x48, u16) & 0xfff)]++;
                func_ov002_021d9ed8(q, o, 1);
            }
        }
        FIELD(self, 0x18, s32)++;
        break;
    }
    case 0x34: {
        BOOL st = isState5(FIELD(self, 0xc, void *));
        if (!st) {
            return;
        }
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
        FIELD(self, 0x18, s32) = 10;
        break;
    }
    }
}

extern VFunc data_ov000_021cb1b0[];

extern VFunc data_ov000_021cb0b8[];

BOOL func_ov002_021e046c(void *self, void *ev);

void *func_ov002_021dd6a4(void *self, s32 a, u16 b) {
    VObject *p;
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 0xc, VObject *));
        HEAP_POP(saved);
    }
    p = (VObject *)func_0203dd9c(0x1e4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021caec8;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cb1b0;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cb0b8;
        p->v0x28();
    }
    FIELD(self, 0xc, VObject *) = p;
    FIELD(p, 0x1d8, u16) = b;
    FIELD(FIELD(self, 0xc, void *), 0x1dc, s32) = a;
    FIELD(FIELD(self, 0xc, void *), 0x1e0, u16) = 1;
    FIELD(FIELD(self, 0xc, void *), 0x84, void *) = (void *)func_ov002_021e046c;
    FIELD(FIELD(self, 0xc, void *), 0x8, void *) = (u8 *)self + 0x1c;
    FIELD(self, 0xc, VObject *)->v0x8();
    FIELD(FIELD(self, 0xc, void *), 0x68, s16) = -0x1666;
    FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~2;
    return FIELD(self, 0xc, void *);
}

}
