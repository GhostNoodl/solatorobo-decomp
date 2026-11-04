#include "ov004/dsprot.h"

#pragma force_active on

extern char DSProt_BSS[];
extern char DSProt_ClassifyInsn[];
extern char Rc4_Init[];
extern char Rc4_NextByte[];
extern char Rc4_EncryptCode[];
extern char Rc4_DecryptCode[];
void DSProt_DescrambleRanges(u32 *t);
s32 DSProt_EncryptWithKey(const u8 *key, const u8 *src, u8 *dst, u32 len);
s32 DSProt_DecryptWithKey(const u8 *key, const u8 *src, u8 *dst, u32 len);

s32 DSProt_EncryptWithKey(const u8 *key, const u8 *src, u8 *dst, u32 len) {
    Rc4 ctx;
    DSPROT_FN(Ov004InitFn, 4)(&ctx, key, 0x10);
    return -(DSPROT_FN(Ov004CryptFn, 1)(&ctx, src, dst, len) == -1);
}

s32 DSProt_DecryptWithKey(const u8 *key, const u8 *src, u8 *dst, u32 len) {
    Rc4 ctx;
    DSPROT_FN(Ov004InitFn, 4)(&ctx, key, 0x10);
    return -(DSPROT_FN(Ov004CryptFn, 2)(&ctx, src, dst, len) == -1);
}

// DSProtect stub: its trailing words are the relocated pointers/keys of this file's functions.
asm void func_ov004_021cdc20(void) {
    orr r0, pc, #0
    adds r0, r0, #4
    bne DSProt_DescrambleRanges
    dcd Rc4_Init+0x3200
    dcd DSProt_BSS+0x3284
    dcd Rc4_EncryptCode+0x3200
    dcd DSProt_BSS+0x3344
    dcd Rc4_DecryptCode+0x3200
    dcd DSProt_BSS+0x33ac
    dcd DSProt_EncryptWithKey+0x3200
    dcd DSProt_BSS+0x3274
    dcd DSProt_DecryptWithKey+0x3200
    dcd DSProt_BSS+0x3274
    dcd Rc4_NextByte+0x3200
    dcd DSProt_BSS+0x3258
    dcd DSProt_ClassifyInsn+0x3200
    dcd DSProt_BSS+0x323c
    dcd 0x00000000
    dcd 0x00000000
}

#pragma force_active reset
