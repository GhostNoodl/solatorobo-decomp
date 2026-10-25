#include "ov010/ov010.h"

struct Ov010Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
};

struct Ov010G190 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

extern "C" {

extern const u8 data_ov010_0220f098[];
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern s32 func_ov003_021d6548(void *self, void *p);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d982c(void *p, u8 v);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(void *self, u8 *msg);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);

static inline u8 Ov010_HitKind(s32 i) {
    if (i >= 0 && (u32)i < 7) {
        return data_ov010_0220f098[i];
    }
    return 2;
}

static inline BOOL Ov010_IsInvul(u16 *hp) {
    return hp[5] != 0;
}

static inline BOOL Ov010_HasFlag(Ov010Sub40 *s, u64 m) {
    BOOL r = FALSE;
    if (s->flags & m) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov010_0220441c(u8 *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 1:
            func_ov003_021d85c8(self + 0x1b0, 3, 0, 0, 0);
            break;
        case 0: {
            u16 *hp = FLD(u16 *, self, 0x50);
            if (!Ov010_IsInvul(hp)) {
                s32 n;
                u8 st;
                u8 *g;
                hp[2] = FLD(u16, msg, 6);
                n = func_ov003_021d6548(self, msg + 0xa);
                hp = FLD(u16 *, self, 0x50);
                st = FLD(u8, hp, 9);
                if (hp[0] <= FLD(u16, self, 0xf4)) {
                    n = 0x15;
                    hp[0] = FLD(u16, self, 0xf4);
                }
                if (n != 0) {
                    FLD(u8, self, 0x170) = n;
                    FLD(u8, self, 0x171) = Ov010_HitKind(msg[9]);
                    FLD(Ov010Sub40 *, self, 0x40)->flags |= 1ull << n;
                    func_ov003_021d982c(self + 0x160, 1);
                }
                if (st != 1) {
                    func_ov000_02191418(FLD(void *, self, 0x38), 5, 0);
                }
                g = data_ov000_021ccd54;
                FLD(Ov010G190, g, 0x190).b2 = 1;
                FLD(Ov010G190, g, 0x190).b3 = 1;
                FLD(Ov010G190, g, 0x190).b4 = 1;
                FLD(u8, g, 0x18d) = 0x14;
                FLD(u8, g, 0x18e) = 0x1e;
                FLD(u8, g, 0x18f) = 0x1e;
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_02049f44(data_02097e4c, 0x1b, self + 0x70, 0);
            }
            break;
        }
        }
        FLD(u32, self, 0x30) |= 1 << msg[5];
        msg[5] = 0;
        r = TRUE;
    } else if (msg[5] == 9) {
        u8 *o;
        u16 *p;
        r = func_ov003_021d1c00(self, msg);
        {
            u16 id = FLD(u16, msg, 0xc);
            o = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (o != NULL && FLD(u16, o, 0xe) == 0x4817) {
            u16 *hp = FLD(u16 *, self, 0x50);
            if (hp[0] <= FLD(u16, self, 0xf4)) {
                hp[0] = FLD(u16, self, 0xf4) + 1;
                FLD(Ov010Sub40 *, self, 0x40)->flags = 0;
            }
        }
        FLD(u16 *, self, 0x124)[0] = FLD(u16, o, 0x7e);
        FLD(u16 *, self, 0x124)[1] = 0xa00;
        FLD(u16 *, self, 0x124)[2] = 0x600;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x12c), self + 0x70, 0);
        if (!Ov010_HasFlag(FLD(Ov010Sub40 *, self, 0x40), 0x200000)) {
            FLD(Ov010Sub40 *, self, 0x40)->flags = 0;
        }
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}

}
