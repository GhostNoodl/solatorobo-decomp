#include "ov002/ov002.h"

extern "C" {

extern void *data_ov002_021f0fac[];

static inline void ov002_unlink7f8(u8 *n) {
    s32 k = *FIELD(n, 0x20, s32 *);
    u8 *c;
    u8 *prev = NULL;
    for (c = (u8 *)data_ov002_021f0fac[k]; c != NULL; c = FIELD(c, 0x30, u8 *)) {
        if (c == n) {
            if (prev == NULL) {
                data_ov002_021f0fac[k] = FIELD(n, 0x30, void *);
            } else {
                FIELD(prev, 0x30, void *) = FIELD(n, 0x30, void *);
            }
            FIELD(n, 0x30, void *) = NULL;
            break;
        }
        prev = c;
    }
    if (FIELD(n, 0x28, u8 *) != NULL) {
        FIELD(FIELD(n, 0x28, u8 *), 0x2c, void *) = FIELD(n, 0x2c, void *);
    } else {
        data_ov002_021f0fa0[0] = FIELD(n, 0x2c, void *);
    }
    if (FIELD(n, 0x2c, u8 *) != NULL) {
        FIELD(FIELD(n, 0x2c, u8 *), 0x28, void *) = FIELD(n, 0x28, void *);
    } else {
        data_ov002_021f0fa0[2] = FIELD(n, 0x28, void *);
    }
    FIELD(n, 0x28, void *) = NULL;
    FIELD(n, 0x2c, void *) = NULL;
    {
        u32 s2;
        HEAP_PUSH(s2);
        if (n != NULL) {
            if (n != NULL) {
                ((VObject *)n)->v0x4();
            }
        }
        HEAP_POP(s2);
    }
}

static inline BOOL ov002_flag3_7f8(void *self) {
    return FIELD(self, 4, Bits32).b3 == 1 ? TRUE : FALSE;
}

void func_ov002_021ee7f8(void *self) {
    u8 *n;
    u8 *next;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        n = (u8 *)data_ov002_021f0fa0[0];
        FIELD(self, 0x28, s32) = 0;
        for (; n != NULL; n = next) {
            next = FIELD(n, 0x2c, u8 *);
            if (!((VObject *)n)->v0x8((u8 *)self + 4)) {
                ov002_unlink7f8(n);
            }
        }
        if (ov002_flag3_7f8(self) && FIELD(self, 0x8, s32) != 3) {
            FIELD(self, 0xc, s32) = 3;
        }
        if (FIELD(self, 0x8, s32) != 3) {
            return;
        }
        if (FIELD(self, 0x14, s32) <= 0x78000) {
            return;
        }
        {
            u8 *m;
            u8 *mnext;
            for (m = (u8 *)data_ov002_021f0fa0[0]; m != NULL; m = mnext) {
                mnext = FIELD(m, 0x2c, u8 *);
                ov002_unlink7f8(m);
            }
        }
        FIELD(self, 0x10, s32)++;
        break;
    case 5:
        if (FIELD(self, 0x8, s32) != 8) {
            FIELD(self, 0xc, s32) = 8;
        }
        break;
    default:
        FIELD(self, 0x10, s32)++;
        break;
    }
}

}
