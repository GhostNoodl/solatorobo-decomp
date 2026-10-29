#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[0x14];
    s16 hx;
    s16 hy;
} Info0219d1a8;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 12;
} B16_0219d1a8;

typedef struct {
    u16 max;
    u16 cur;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    void *fn10;
    void *fn14;
    void *fn18;
} Gauge0219d1a8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
} Trio0219d1a8;

extern "C" {

extern u8 *data_0214a424;
extern char data_ov000_021cc60f[];
void *func_ov003_021ce630(void);
u16 func_ov003_021ce6fc(void);
u16 func_ov003_021ce79c(void);
u16 func_ov003_021ce7c0(void);
void *func_0203dd9c(u32 size);
Info0219d1a8 *func_0206fef8(u16 id);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
s32 func_ov000_021909a8(void *m, void *p, const char *name);
void func_ov000_0219c8e0(u8 *self);
void func_ov000_02198c8c(void *o, u16 id);
void func_0203f364(void *o);
void *func_ov000_021984c8(void *p);
void *func_ov000_02198328(void *p);
void *func_ov000_021bd198(void *p);
BOOL func_ov000_021bd314(void *p, s32 a);
void func_02062764(s32 a, s32 b);

static inline void *NewObj44_0219d1a8(void) {
    void *p = func_0203dd9c(0x24);
    if (p != NULL) {
        p = func_ov000_021984c8(p);
    }
    return p;
}

static inline void *NewObj40_0219d1a8(void) {
    void *p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_ov000_02198328(p);
    }
    return p;
}

static inline void *NewObj5c_0219d1a8(void) {
    void *p = func_0203dd9c(0xa8);
    if (p != NULL) {
        func_ov000_021bd198(p);
    }
    return p;
}

static inline Gauge0219d1a8 *NewGauge0219d1a8(void) {
    Gauge0219d1a8 *g = (Gauge0219d1a8 *)func_0203dd9c(0x1c);
    if (g != NULL) {
        g->max = 100;
        g->cur = g->max;
        g->unk_04 = 0xffff;
        g->unk_0a = 0;
        g->unk_0e = 0;
        g->unk_0c = 0;
        g->fn10 = NULL;
        g->fn14 = NULL;
        g->fn18 = NULL;
    }
    return g;
}

static inline Trio0219d1a8 *NewTrio0219d1a8(void) {
    Trio0219d1a8 *t = (Trio0219d1a8 *)func_0203dd9c(6);
    if (t != NULL) {
        t->a = 0;
        t->b = 0;
        t->c = 0;
    }
    return t;
}

void func_ov000_0219d1a8(u8 *self) {
    Info0219d1a8 *info = func_0206fef8(LFLD(u16, self, 0xe));
    u8 *p;
    u32 *q;
    s32 x;
    s32 z;
    u16 n;

    LFLD(s32, self, 0x64) = info->hx << 4;
    LFLD(s32, self, 0x68) = info->hy << 4;
    LFLD(s32, self, 0x6c) = LFLD(s32, self, 0x68) >> 1;
    func_ov000_0218ffdc(self + 0xac, self + 0x194, 0, 1);
    LFLD(u16, self, 0x160) = LFLD(u16, self, 0xc);
    LFLD(void *, self, 0x18c) = (void *)func_ov003_021ce630;
    p = NULL;
    q = LFLD(u32 *, self, 0x254);
    if (q != NULL) {
        p = (u8 *)*q + 8;
    }
    LFLD(u8 *, self, 0x17c) = p;
    if (p != NULL && LFLD(u16, p, 2) == 0) {
        LFLD(u8 *, self, 0x180) = p + 4 + LFLD(u16, p, 0) * 12;
    }
    LFLD(u8, self, 0xa4b) = 0;
    LFLD(u16, self, 0x16e) |= 0x100;
    if (!LBIT(self, 0xb24).b1) {
        LFLD(u16, self, 0x178) = 0x320;
    }
    LFLD(u8, self, 0xa4c) = 0;
    LFLD(u8, self, 0xa48) = func_ov000_021909a8(self + 0xac, self + 0x200, data_ov000_021cc60f);
    func_ov000_0218ffdc(self + 0x778, self + 0x860, 0, 1);
    LFLD(u16, self, 0x82c) = LFLD(u16, self, 0xc);
    func_ov000_0219c8e0(self);
    x = LFLD(s32, self, 0x64);
    z = LFLD(s32, self, 0x6c);
    func_ov000_02198c8c(self + 0x2cc, LFLD(u16, self, 0xc));
    LFLD(s32, self, 0x304) = (x >> 1) + (x >> 3);
    LFLD(s32, self, 0x2f4) = 2;
    LFLD(s32, self, 0x32c) = z - (z >> 3);
    LFLD(B16_0219d1a8, self, 0x366).b0 = 0;
    LFLD(B16_0219d1a8, self, 0x366).b3 = 0;
    func_0203f364(self + 0x2cc);
    func_ov000_02198c8c(self + 0x6c0, LFLD(u16, self, 0xc));
    LFLD(s32, self, 0x6e8) = 2;
    LFLD(B16_0219d1a8, self, 0x75a).b0 = 0;
    LFLD(s32, self, 0x6f8) = x;
    LFLD(s32, self, 0x720) = z;
    LFLD(B16_0219d1a8, self, 0x75a).b3 = 0;
    func_0203f364(self + 0x6c0);
    LFLD(s32, self, 0x708) = x;
    LFLD(void *, self, 0x44) = NewObj44_0219d1a8();
    LFLD(u16, LFLD(u8 *, self, 0x44), 0x20) = LFLD(u16, self, 0xc);
    LFLD(s32, LFLD(u8 *, self, 0x44), 0x1c) = x;
    LFLD(s32, LFLD(u8 *, self, 0x44), 0x10) = z;
    {
        u8 *o = LFLD(u8 *, self, 0x44);
        LFLD(B16_0219d1a8, o, 0x22).b0 = 1;
        LFLD(B16_0219d1a8, o, 0x22).b1 = 1;
    }
    LFLD(void *, self, 0x40) = NewObj40_0219d1a8();
    n = data_0214a424[0x1a] * 100 + 500;
    LFLD(Gauge0219d1a8 *, self, 0x50) = NewGauge0219d1a8();
    LFLD(Gauge0219d1a8 *, self, 0x50)->max = n;
    LFLD(Gauge0219d1a8 *, self, 0x50)->cur = n;
    LFLD(Gauge0219d1a8 *, self, 0x50)->unk_0c = 0x30;
    LFLD(Gauge0219d1a8 *, self, 0x50)->fn10 = (void *)func_ov003_021ce6fc;
    LFLD(Gauge0219d1a8 *, self, 0x50)->fn14 = (void *)func_ov003_021ce79c;
    LFLD(Gauge0219d1a8 *, self, 0x50)->fn18 = (void *)func_ov003_021ce7c0;
    LFLD(u16, self, 0xb34) = n;
    LFLD(Trio0219d1a8 *, self, 0x54) = NewTrio0219d1a8();
    LFLD(u8, self, 0x15) = 3;
    LFLD(void *, self, 0x5c) = NewObj5c_0219d1a8();
    func_ov000_021bd314(LFLD(void *, self, 0x5c), 0);
    LFLD(s32, LFLD(u8 *, self, 0x5c), 0x4c) = 0x400;
    LFLD(void *, self, 0x9b0) = NewObj5c_0219d1a8();
    LFLD(s32, LFLD(u8 *, self, 0x9b0), 0x28) = 3;
    func_ov000_021bd314(LFLD(void *, self, 0x9b0), 6);
    LFLD(s32, LFLD(u8 *, self, 0x9b0), 0x5c) = z >> 1;
    LFLD(void *, self, 0x9b4) = NewObj5c_0219d1a8();
    func_ov000_021bd314(LFLD(void *, self, 0x9b4), 9);
    {
        s32 v = 1;
        if (!LBIT(self, 0xb24).b1) {
            v = 2;
        }
        func_02062764(3, v);
    }
}

}
