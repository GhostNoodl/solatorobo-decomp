#include "types.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Unit0218b700Bits;

typedef struct {
    u8 pad_00[0x74];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    u8 pad_88[0xa2 - 0x88];
    Unit0218b700Bits bits;
} Unit0218b700;

extern "C" {

void func_ov000_0218b420(Unit0218b700 *u);

void func_ov000_0218b700(Unit0218b700 *u, s32 a, s32 b) {
    if (b == 0) {
        b = a;
    }
    u->unk_74 = FX_MUL(a, 0x37000);
    u->unk_7c = FX_MUL(b, 0x14000);
    u->unk_78 = FX_MUL(a, 0x39000);
    u->unk_80 = FX_MUL(b, 0x16000);
    u->unk_84 = FX_MUL(a, 0x32000);
    func_ov000_0218b420(u);
}

static inline void Unit0218b700_SetSize(Unit0218b700 *u, s32 a, s32 b) {
    if (b == 0) {
        b = a;
    }
    u->unk_74 = FX_MUL(a, 0x37000);
    u->unk_7c = FX_MUL(b, 0x14000);
    u->unk_78 = FX_MUL(a, 0x39000);
    u->unk_80 = FX_MUL(b, 0x16000);
    u->unk_84 = FX_MUL(a, 0x32000);
    func_ov000_0218b420(u);
}

// Case 6 comes before case 3 in the first switch (the compiler cross-jumps the identical bodies),
// and the mode 5 path edits a copy of the flag byte so the bits are stored once.
void func_ov000_0218b7c0(Unit0218b700 *u, s32 kind, s32 mode) {
    s32 x = 0x1000;
    s32 y = x;
    if (mode == 5) {
        Unit0218b700Bits t = u->bits;
        t.b3 = 0;
        t.b4 = 0;
        x = 0x599a;
        y = 0x4000;
        if (kind == 6) {
            x = 0xc000;
        }
        t.b5 = 1;
        u->bits = t;
    } else {
        switch (kind) {
        case 6:
            u->bits.b0 = 0;
            u->bits.b1 = 0;
            func_ov000_0218b420(u);
            u->bits.b2 = 0;
            func_ov000_0218b420(u);
            u->bits.b5 = 1;
            break;
        case 3:
            u->bits.b0 = 0;
            u->bits.b1 = 0;
            func_ov000_0218b420(u);
            u->bits.b2 = 0;
            func_ov000_0218b420(u);
            u->bits.b5 = 1;
            break;
        case 4:
            u->bits.b6 = 1;
            break;
        }
        switch (mode) {
        case 1:
        case 2:
            u->bits.b0 = 0;
            u->bits.b1 = 0;
            func_ov000_0218b420(u);
            u->bits.b2 = 0;
            func_ov000_0218b420(u);
            break;
        case 3:
            u->bits.b2 = 0;
            func_ov000_0218b420(u);
            x = 0x2000;
            y = 0x1ccd;
            u->bits.b3 = 0;
            u->bits.b4 = 0;
            break;
        case 4:
            u->bits.b2 = 0;
            func_ov000_0218b420(u);
            y = 0x1ccd;
            x = 0x2000;
            u->bits.b3 = 0;
            break;
        }
    }
    if (x != 0x1000 || y != 0x1000) {
        Unit0218b700_SetSize(u, x, y);
    }
}

}
