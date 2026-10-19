#ifndef OV004_DSPROT_H
#define OV004_DSPROT_H

// DSProtect anti-tamper library linked into overlay 4. Its code stores function and data
// addresses with 0x3200 added and subtracts it again before use.

#include "types.h"

typedef struct {
    u32 x;
    u32 i;
    u32 j;
    u8 s[0x100];
} Rc4;

typedef s32 (*Ov004ClassifyFn)(u32 insn);
typedef u8 (*Ov004NextFn)(Rc4 *c);
typedef void (*Ov004InitFn)(Rc4 *c, const u8 *key, u32 len);
typedef s32 (*Ov004CryptFn)(Rc4 *c, const u8 *src, u8 *dst, u32 len);

// { classify, encrypt, decrypt, next byte, init }, each with 0x3200 added.
extern const u32 data_ov004_021cf7a4[];

#define DSPROT_FN(type, i) ((type)(data_ov004_021cf7a4[i] - 0x3200))

#endif
