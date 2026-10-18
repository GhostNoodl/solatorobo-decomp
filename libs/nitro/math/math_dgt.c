#include "math_sha1.h"

extern const MATHiHMACFuncs MATHi_HMACSHA1FuncsTemplate;

#pragma force_active on
void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength) {
    MATHSHA1Context context;
    MATH_SHA1Init(&context);
    MATH_SHA1Update(&context, data, dataLength);
    MATH_SHA1GetHash(&context, digest);
}
#pragma force_active reset

void MATH_CalcHMACSHA1(void *digest, const void *bin_ptr, u32 bin_len, const void *key_ptr, u32 key_len) {
    MATHSHA1Context context;
    u8 hash_buf[MATH_SHA1_DIGEST_SIZE];
    MATHiHMACFuncs hash2funcs = MATHi_HMACSHA1FuncsTemplate;
    hash2funcs.context = &context;
    hash2funcs.hash_buf = hash_buf;
    hash2funcs.HashReset = (void (*)(void *))MATH_SHA1Init;
    hash2funcs.HashSetSource = (void (*)(void *, const void *, u32))MATH_SHA1Update;
    hash2funcs.HashGetDigest = (void (*)(void *, void *))MATH_SHA1GetHash;
    MATHi_CalcHMAC(digest, bin_ptr, bin_len, key_ptr, key_len, &hash2funcs);
}
