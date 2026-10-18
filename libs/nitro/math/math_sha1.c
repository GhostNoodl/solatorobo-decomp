#include "math_sha1.h"
#include "nitro/mi.h"

typedef void (*MATHiSHA1ProcessBlockFunc)(MATHSHA1Context *context);

void MATHi_SHA1ProcessBlock(MATHSHA1Context *context);

extern MATHiSHA1ProcessBlockFunc MATHi_SHA1ProcessBlockFunc;
extern BOOL MATHi_OverlayTableMode;
extern const u8 MATHi_SHA1PadLead[1];
extern const u8 MATHi_SHA1PadAlign[8];

static void MATHi_SHA1ProcessBlockForOverlay(MATHSHA1Context *context) {
    u32 tmp1 = *(u32 *)&context->block[0x18];
    u32 tmp2 = *(u32 *)&context->block[0x38];
    *(u32 *)&context->block[0x18] = 0;
    *(u32 *)&context->block[0x38] = 0;
    MATHi_SHA1ProcessBlock(context);
    *(u32 *)&context->block[0x18] = tmp1;
    *(u32 *)&context->block[0x38] = tmp2;
}

static void MATHi_SHA1Fill(MATHSHA1Context *context, u8 input, u32 length) {
    while (length > 0) {
        u32 rest = MATH_SHA1_BLOCK_SIZE - context->pool;
        if (rest > length) {
            rest = length;
        }
        MI_CpuFill8(&context->block[context->pool], input, rest);
        length -= rest;
        context->pool += rest;
        if (context->pool >= MATH_SHA1_BLOCK_SIZE) {
            MATHi_SHA1ProcessBlockFunc(context);
            context->pool = 0;
            ++context->blocks_low;
            if (!context->blocks_low) {
                ++context->blocks_high;
            }
        }
    }
}

BOOL MATHi_SetOverlayTableMode(BOOL flag) {
    BOOL old = MATHi_OverlayTableMode;
    MATHi_OverlayTableMode = flag;
    if (flag) {
        MATHi_SHA1ProcessBlockFunc = MATHi_SHA1ProcessBlockForOverlay;
    } else {
        MATHi_SHA1ProcessBlockFunc = MATHi_SHA1ProcessBlock;
    }
    return old;
}

void MATH_SHA1Init(MATHSHA1Context *context) {
    context->blocks_low = 0;
    context->blocks_high = 0;
    context->pool = 0;
    context->h[0] = 0x67452301;
    context->h[1] = 0xefcdab89;
    context->h[2] = 0x98badcfe;
    context->h[3] = 0x10325476;
    context->h[4] = 0xc3d2e1f0;
}

void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length) {
    while (length > 0) {
        u32 rest = MATH_SHA1_BLOCK_SIZE - context->pool;
        if (rest > length) {
            rest = length;
        }
        MI_CpuCopy8(input, &context->block[context->pool], rest);
        input = (const u8 *)input + rest;
        length -= rest;
        context->pool += rest;
        if (context->pool >= MATH_SHA1_BLOCK_SIZE) {
            MATHi_SHA1ProcessBlockFunc(context);
            context->pool = 0;
            ++context->blocks_low;
            if (!context->blocks_low) {
                ++context->blocks_high;
            }
        }
    }
}

static inline u32 MATHi_HToBE32(u32 v) {
    return ((v >> 24) & 0xff) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | ((v << 24) & 0xff000000);
}

void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest) {
    u32 footer[2];
    footer[1] = MATHi_HToBE32((context->blocks_low << (6 + 3)) + (context->pool << 3));
    footer[0] = MATHi_HToBE32((context->blocks_high << (6 + 3)) + (context->blocks_low >> (32 - (6 + 3))));
    MATH_SHA1Update(context, MATHi_SHA1PadLead, sizeof(MATHi_SHA1PadLead));
    if (MATH_SHA1_BLOCK_SIZE - context->pool < sizeof(footer)) {
        MATH_SHA1Update(context, MATHi_SHA1PadAlign, MATH_SHA1_BLOCK_SIZE - context->pool);
    }
    MATHi_SHA1Fill(context, 0, MATH_SHA1_BLOCK_SIZE - sizeof(footer) - context->pool);
    MATH_SHA1Update(context, footer, sizeof(footer));
    context->h[0] = MATHi_HToBE32(context->h[0]);
    context->h[1] = MATHi_HToBE32(context->h[1]);
    context->h[2] = MATHi_HToBE32(context->h[2]);
    context->h[3] = MATHi_HToBE32(context->h[3]);
    context->h[4] = MATHi_HToBE32(context->h[4]);
    MI_CpuCopy8(context->h, digest, MATH_SHA1_DIGEST_SIZE);
}
