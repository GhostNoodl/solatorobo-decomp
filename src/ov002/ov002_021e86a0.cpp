#include "ov002/ov002.h"

extern "C" {

extern void *data_ov002_021f0104[];

extern void *data_02097e4c;

void func_02041c34(void *a, int b, void *c, int d);

void func_0204aad0(void *a);

void func_0204a360(void *a, int b);

BOOL func_0204985c(void *a);

void func_ov002_021eaf20(void *self);

Oam021e7ab8 *func_ov002_021e7ab8(void *self, u16 *flag, Oam021e7ab8 *oam, u16 *count);

void func_ov002_021ead1c(void *self, u8 *a, s32 b, u8 c);

BOOL func_ov002_021e86a0(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x8, s32)) {
    case 0: {
        void **tbl;
        void *res;
        void *m = func_0203dd9c(0x160);
        if (m != NULL) {
            void *file = data_ov002_021f0104[1];
            void *name = data_ov002_021f0104[2];
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, name, 0);
            func_0201e520((u8 *)m + 0x2c, file);
        }
        FIELD(self, 0x124, void *) = m;
        tbl = data_ov002_021f0104;
        res = func_02035f30(tbl[1], tbl[2], 2);
        func_020417e0(FIELD(self, 0x124, void *), func_02034d88(res, tbl[2]));
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 2;
        FIELD(FIELD(self, 0x124, void *), 0x150, s32) = -9;
        func_02041c34(FIELD(self, 0x124, void *), 0, (void *)func_ov002_021e7ab8, 0);
        func_02041d9c(FIELD(self, 0x124, void *), 0, 0);
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 0x80000;
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) |= 0x200000;
        FIELD(FIELD(self, 0x124, void *), 0x6c, u32) = (FIELD(FIELD(self, 0x124, void *), 0x6c, u32) & ~0x7c) | 0x78;
        func_0204aad0(data_02097e48);
        if (FIELD(self, 0x68, void *) != NULL) {
            func_ov002_021ead1c((u8 *)self + 0x6c, *FIELD(self, 0x68, u8 **), FIELD(self, 0x44, s32), 1);
            func_ov002_021eaf20((u8 *)self + 0x6c);
        }
        func_0204a360(data_02097e4c, -1);
        FIELD(self, 0x8, s32) = 10;
    }
    case 10:
        if (func_0204985c(data_02097e4c)) {
            FIELD(self, 0x8, s32) = 0x14;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e4dd4(void *n);

void func_ov002_021e8bbc(void *self, void *n);

void MI_Copy64B(void *src, void *dst);

typedef struct Blk24_8828 { s32 v[9]; } Blk24_8828;

static inline BOOL ov002_inRange8828(void *self) {
    BOOL r = FALSE;
    if (FIELD(self, 0x14, s32) >= 0 && FIELD(self, 0x14, s32) <= FIELD(self, 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov002_021e8828(void *self) {
    BOOL ret = TRUE;
    BOOL busy = FALSE;
    BOOL in;
    BOOL r;
    u8 *next;
    u8 *n;
    if (FIELD(self, 0x1c, s32) != 0x5c && FIELD(self, 0x1c, s32) != 0x1e) {
        if ((FIELD(data_02097dc8, 0x12, u16) & 8) && FIELD(self, 0x1a, u8) != 0) {
            ret = busy;
        }
    }
    for (n = FIELD(self, 0xdc, u8 *); n != NULL; n = next) {
        next = FIELD(n, 0x24, u8 *);
        r = func_ov002_021e4dd4(n);
        if (FIELD(n, 0x4, s32) == 7 && FIELD(self, 0xc, s32) == FIELD(n, 0x8, s32)) {
            {
                s32 *sv = (s32 *)(n + 0x50);
                s32 a0 = sv[0], a1 = sv[1], a2 = sv[2], a3 = sv[3], a4 = sv[4], a5 = sv[5], a6 = sv[6], a7 = sv[7], a8 = sv[8];
                s32 *d = (s32 *)((u8 *)data_0214a420 + 0x38);
                d[0] = a0; d[1] = a1; d[2] = a2; d[3] = a3; d[4] = a4; d[5] = a5; d[6] = a6; d[7] = a7; d[8] = a8;
            }
            MI_Copy64B(n + 0x74, (u8 *)data_0214a420 + 0x5c);
        }
        if (!r) {
            if (FIELD(n, 0x4, s32) == 9) {
                ret = FALSE;
            }
            func_ov002_021e8bbc(self, n);
            {
                u32 saved;
                HEAP_PUSH(saved);
                if (n != NULL) {
                    if (n != NULL) {
                        ((VObject *)n)->v0x4();
                    }
                }
                HEAP_POP(saved);
            }
        } else if (!((VObject *)n)->v0x8()) {
            busy = TRUE;
        }
    }
    in = ov002_inRange8828(self);
    if (in && (FIELD(self, 0x18, u16) & FIELD(data_02097dc8, 0x12, u16))) {
        u8 *ctx = (u8 *)data_ov002_021f0f98[1];
        FIELD(ctx, 0x14, s32) = -1;
        FIELD(ctx, 0x18, u16) = 0;
    }
    if (FIELD(self, 0xc, s32) == 2) {
        if (FIELD(self, 0x10, u8) == 0) {
            u8 *p;
            FIELD(self, 0xd4, s32) = FIELD(self, 0xd0, s32);
            FIELD(self, 0xd0, s32) = FIELD(self, 0xd0, s32) + FIELD(self, 0xd8, s32);
            func_02065ac0(data_0214a420);
            for (p = FIELD(data_0214a420, 0x20, u8 *); p != NULL; p = FIELD(p, 0xec, u8 *)) {
                FIELD(p, 0x3c, s32) = FIELD(self, 0xd8, s32);
            }
            FIELD(data_0214a420, 0x34, u8) = 1;
        }
        { BOOL v = TRUE; if (!busy && !ov002_inRange8828(self)) v = FALSE; FIELD(self, 0x10, u8) = v; }
    }
    return ret;
}

}
