#include "ov010/ov010.h"

struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010Shake {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
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
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
extern void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);

void func_ov010_021ff924(Ov010Shake *o) {
    if (!o->b1) {
        if (o->b2) {
            o->unk_08 = func_01ffc128(o->unk_06, o->unk_08, 0x148, 1, 0x8000);
            o->b2 = 0;
            o->b3 = 1;
            o->unk_06 = 0;
        } else if (o->b3) {
            o->unk_08 = func_01ffc128(0, o->unk_08, 0x148, 1, 0x8000);
            if (o->unk_08 < 0x200 || o->unk_08 >= 0xfdff) {
                o->b3 = 0;
                o->unk_0a = 0;
            }
        } else {
            o->unk_0a += 0x80;
            o->unk_08 = func_01ffc128((u16)((s32)(((s64)OV010_SIN(o->unk_0a) * 0xc00000 + 0x800) >> 12) >> 12), o->unk_08, 0x100, 1, 0x8000);
        }
    }
    o->b1 = o->b0;
}

}
