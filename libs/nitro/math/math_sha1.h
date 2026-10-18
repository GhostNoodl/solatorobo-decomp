#ifndef NITRO_MATH_SHA1_H
#define NITRO_MATH_SHA1_H

#include "types.h"

#define MATH_SHA1_DIGEST_SIZE 20
#define MATH_SHA1_BLOCK_SIZE  64

typedef struct MATHSHA1Context {
    u32 h[5];
    u8 block[MATH_SHA1_BLOCK_SIZE];
    u32 pool;
    u32 blocks_low;
    u32 blocks_high;
} MATHSHA1Context;

typedef struct MATHiHMACFuncs {
    u32 dlength;
    u32 blength;
    void *context;
    void *hash_buf;
    void (*HashReset)(void *context);
    void (*HashSetSource)(void *context, const void *input, u32 length);
    void (*HashGetDigest)(void *context, void *digest);
} MATHiHMACFuncs;

void MATH_SHA1Init(MATHSHA1Context *context);
void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length);
void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest);
void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length,
                    MATHiHMACFuncs *funcs);

#endif
