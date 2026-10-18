#include "ov002/ov002.h"

extern "C" {

extern u8 *data_ov000_021ccd70;

typedef struct Pair021efa94 { s32 a; s32 b; } Pair021efa94;

extern Pair021efa94 data_ov002_021efa94;

void func_ov000_02163224(void *o);

void func_ov000_021632f0(void *o, u16 id, s32 a, s32 b, int z);

static inline BOOL ov002_isIdle637c(void) {
    return FIELD(data_ov000_021ccd70, 4, void *) == NULL;
}

static inline BOOL ov002_moving637c(void *g) {
    return !(FIELD(g, 0x98, s32) == FIELD(g, 0xa4, s32) && FIELD(g, 0xb3, s8) == 0);
}

static inline BOOL ov002_has74_637c(void *g) {
    return FIELD(g, 0x74, void *) != NULL;
}

static inline BOOL ov002_busy637c(void *g) {
    return ov002_has74_637c(g) != FALSE;
}

static inline BOOL ov002_unsel637c(void *g) {
    return FIELD(g, 0xc, Bits32).b0 == 0;
}

static inline void *ov002_cursor637c(void *g) {
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

static inline void *ov002_new637c(void) {
    void *o = func_0203dd9c(0x2c);
    if (o != NULL) {
        *(VFunc **)o = data_ov002_021efb04;
        func_ov000_02163224(o);
    }
    return o;
}

void func_ov002_021d637c(void *self) {
    s32 z = 0;
    void *g;
    u16 keys;
    u8 *p;
    void *o;
    void *x;
    if (FIELD(self, 0x5c, void *) != NULL) {
        return;
    }
    if (!ov002_isIdle637c()) {
        return;
    }
    g = FIELD(self, 0x50, void *);
    if (g != NULL) {
        if (ov002_moving637c(g)) {
            return;
        }
        if (!((VObject *)g)->v0xc()) {
            return;
        }
    }
    g = FIELD(self, 0x50, void *);
    keys = FIELD(data_02097dc8, 0x12, u16);
    if (ov002_unsel637c(g) && (keys & 2)) {
        z = -1;
        func_02049a48(data_02097e4c, 0x1f, z, z, z);
        FIELD(FIELD(self, 0x4c, void *), 0xc, u32) |= 2;
        FIELD(FIELD(self, 0x50, void *), 0xc, u32) |= 2;
        FIELD(FIELD(self, 0x54, void *), 0xc, u32) |= 2;
        func_0203cc58(FIELD(FIELD(self, 0x50, void *), 0x34, int), 2, z);
        FIELD(self, 0x4, Bits32).b0 = 1;
        return;
    }
    if (!(keys & 0x800)) {
        return;
    }
    if (ov002_busy637c(g)) {
        return;
    }
    p = (u8 *)ov002_cursor637c(g);
    if (p == NULL) {
        return;
    }
    FIELD(self, 0x5c, void *) = ov002_new637c();
    func_ov000_021632f0(FIELD(self, 0x5c, void *), FIELD(p, 6, u16) & 0xfff, data_ov002_021efa94.a, data_ov002_021efa94.b, z);
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) |= 4;
    FIELD(FIELD(self, 0x54, void *), 0xc, u32) |= 4;
    FIELD(FIELD(self, 0x54, void *), 0xc, u32) |= 2;
    x = func_ov000_02173610(0x1b);
    if (x != NULL && FIELD(x, 0x3c, void *) != NULL) {
        func_ov002_021e2690(FIELD(x, 0x3c, void *), z, z);
    }
}

}
