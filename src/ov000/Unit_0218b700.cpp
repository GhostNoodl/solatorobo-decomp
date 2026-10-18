#include "types.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0x74];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
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

}
