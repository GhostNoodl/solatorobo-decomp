#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220fd70[];
extern void func_ov003_021da48c(void *p, s32 a);
extern void func_ov000_02198328(void *p);
extern void func_ov010_02200ee0(void *p);
extern BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d);

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

struct Ov010BeamSt {
    u16 state;
    u16 timer;
};

u8 *func_ov010_02200d94(u8 *o) {
    FLD(Ov010Flags8, o, 0).b0 = 0;
    func_ov000_02198328(o + 0x2c);
    return o;
}

u8 *func_ov010_02200db8(u8 *o) {
    func_ov010_02200ee0(o);
    return o;
}

static inline u8 *Ov010Beam_New(void) {
    u8 *n = (u8 *)func_0203dd9c(0x8c);
    if (n != NULL) {
        FLD(u8, n, 0xc) = 0;
        FLD(Ov010Flags8, n, 0x34).b0 = 0;
        func_ov000_02198328(n + 0x64);
        func_ov000_02198328(n + 0x78);
    }
    return n;
}

static inline u8 *Ov010List_Push(u8 *head, u8 *n) {
    if (n != NULL) {
        FLD(u8 *, n, 8) = head;
        return n;
    }
    return head;
}

BOOL func_ov010_02200dcc(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    s32 i;
    FLD(Ov010Flags8, o, 0).b0 = 1;
    FLD(u8, o, 1) = c;
    FLD(u16, o, 2) = a;
    FLD(u16, o, 4) = b;
    FLD(u16, o, 6) = d;
    FLD(u16, o, 8) = 0;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(void *, o, 0x10) = NULL;
    FLD(Ov010Vec, o, 0x14) = FLD(Ov010Vec, data_ov010_0220fd70, 0x20);
    FLD(Ov010Vec, o, 0x20) = FLD(Ov010Vec, o, 0x14);
    func_ov003_021da48c(o + 0x2c, 0);
    FLD(u16, o, 0x2c) = 0x65;
    for (i = 0; i < 3; i++) {
        u8 *n = Ov010Beam_New();
        func_ov010_022006fc(n + 0xc, a, b, c, d);
        FLD(u8 *, n, 8) = NULL;
        FLD(u8 *, o, 0x10) = Ov010List_Push(FLD(u8 *, o, 0x10), n);
        if (i == 0) {
            FLD(u8, n, 0xd) = 1;
        }
    }
    return TRUE;
}

}
