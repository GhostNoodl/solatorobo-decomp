#include "ov004/dsprot.h"

#pragma force_active on

s32 func_ov004_021cdb30(const u8 *key, const u8 *src, u8 *dst, u32 len) {
    Rc4 ctx;
    DSPROT_FN(Ov004InitFn, 4)(&ctx, key, 0x10);
    return -(DSPROT_FN(Ov004CryptFn, 1)(&ctx, src, dst, len) == -1);
}

s32 func_ov004_021cdba8(const u8 *key, const u8 *src, u8 *dst, u32 len) {
    Rc4 ctx;
    DSPROT_FN(Ov004InitFn, 4)(&ctx, key, 0x10);
    return -(DSPROT_FN(Ov004CryptFn, 2)(&ctx, src, dst, len) == -1);
}

#pragma force_active reset
