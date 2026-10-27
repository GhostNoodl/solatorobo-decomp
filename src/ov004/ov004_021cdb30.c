#include "ov004/dsprot.h"

#pragma force_active on

extern char DSProt_BSS[];
extern char func_ov004_021cd714[];
extern char func_ov004_021cd750[];
extern char func_ov004_021cd7dc[];
extern char func_ov004_021cd834[];
extern char func_ov004_021cd97c[];
void func_ov004_021ce574(void);
s32 func_ov004_021cdb30(const u8 *key, const u8 *src, u8 *dst, u32 len);
s32 func_ov004_021cdba8(const u8 *key, const u8 *src, u8 *dst, u32 len);

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

// DSProtect stub: its trailing words are the relocated pointers/keys of this file's functions.
asm void func_ov004_021cdc20(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne func_ov004_021ce574
    dcd func_ov004_021cd750+0x3200
    dcd DSProt_BSS+0x3284
    dcd func_ov004_021cd834+0x3200
    dcd DSProt_BSS+0x3344
    dcd func_ov004_021cd97c+0x3200
    dcd DSProt_BSS+0x33ac
    dcd func_ov004_021cdb30+0x3200
    dcd DSProt_BSS+0x3274
    dcd func_ov004_021cdba8+0x3200
    dcd DSProt_BSS+0x3274
    dcd func_ov004_021cd7dc+0x3200
    dcd DSProt_BSS+0x3258
    dcd func_ov004_021cd714+0x3200
    dcd DSProt_BSS+0x323c
    dcd 0x00000000
    dcd 0x00000000
}

#pragma force_active reset
