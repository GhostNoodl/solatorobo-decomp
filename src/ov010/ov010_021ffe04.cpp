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

BOOL func_ov010_021ffe04(Ov010Toggle *o) {
    o->b0 = 1;
    o->b1 = 0;
    return TRUE;
}

void func_ov010_021ffe24(Ov010Toggle *o, s32 *msg) {
    switch (msg[0]) {
    case 1:
        o->b0 = msg[1] == 0;
        break;
    case 4:
        o->b1 = msg[1] == 1;
        break;
    }
}

}
