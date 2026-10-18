#include "ov010/ov010.h"

struct Ov010Rot {
    u16 v[3];
};

struct Ov010Toggle {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

struct Ov010G54 {
    u8 unk_000[0x1ce];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 4;
    u8 unk_1cf;
    s32 unk_1d0;
    s32 unk_1d4;
    s32 unk_1d8;
    u8 unk_1dc[0xc];
    s32 unk_1e8;
};

extern "C" {

extern u8 data_ov010_0220ebc0[];
extern const Ov010Vec data_ov010_0220ec80;
extern const Ov010Vec data_ov010_0220ec74;
extern u8 data_ov010_0220ef68[];
extern Ov010G54 *data_ov000_021ccd54;
extern void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);

static inline void Ov010_SetSky(void) {
    Ov010G54 *g = data_ov000_021ccd54;
    g->unk_1d0 = 0;
    g->unk_1d4 = 0x5580;
    g->unk_1d8 = 0;
    g->b0 = 1;
    g = data_ov000_021ccd54;
    g->unk_1e8 = 0x5c00;
    g->b2 = 2;
}

BOOL func_ov010_021fff80(Ov010Toggle *o) {
    o->b0 = 1;
    o->b1 = 0;
    return TRUE;
}

void func_ov010_021fffa0(void *self) {
    if (FLD(void *, self, 0x44) != NULL) {
        func_ov000_021984f4(FLD(void *, self, 0x44), 0, 0);
    }
}

void func_ov010_021fffc0(void *self) {
    if (FLD(void *, self, 0x48) != NULL) {
        func_ov000_0219864c(FLD(void *, self, 0x48), 0, 0);
    }
}

void func_ov010_021fffe0(void) {
}

void func_ov010_021fffe4(void) {
}

void func_ov010_021fffe8(void) {
}

void func_ov010_021fffec(void) {
}

void func_ov010_021ffff0(void) {
}

void func_ov010_021ffff4(void) {
}

void func_ov010_021ffff8(void) {
}

void func_ov010_021ffffc(Ov010V *self) {
    self->v54();
}

void func_ov010_02200010(Ov010V *self) {
    FLD(Ov010Flags, self, 0xee).b5 = 1;
    self->v70();
}

void func_ov010_02200030(void) {
}

void func_ov010_02200034(void) {
}

void func_ov010_02200038(void) {
}

void func_ov010_0220003c(void) {
}

void func_ov010_02200040(void) {
}

void func_ov010_02200044(void) {
}

BOOL func_ov010_02200048(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    FLD(Ov010Flags8, o, 0).b0 = 1;
    FLD(Ov010Flags8, o, 0).b1 = 0;
    FLD(u8, o, 1) = c;
    FLD(u16, o, 2) = b;
    FLD(u16, o, 4) = d;
    FLD(u16, o, 6) = 0;
    FLD(u16, o, 8) = 0;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(u16, o, 0xe) = 0;
    FLD(u16, o, 0x10) = 0;
    FLD(u16, o, 0x12) = a;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0;
    FLD(s32, o, 0x20) = 0;
    FLD(Ov010Vec, o, 0x24) = FLD(Ov010Vec, data_ov010_0220ef68, 0x24);
    func_ov003_021da48c(o + 0x30, 0);
    return TRUE;
}

}
