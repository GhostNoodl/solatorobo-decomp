// The SHA-1 HMAC parameter template that MATH_CalcHMACSHA1 copies and fills in: the digest and
// block sizes, with the context, buffer and hash callbacks left NULL. Written as an asm block so it
// lands in main's .text with the other read-only data (see libs/msl/ctype.c).

#define MATH_SHA1_DIGEST_SIZE 20
#define MATH_SHA1_BLOCK_SIZE  64

#pragma force_active on

// const MATHiHMACFuncs MATHi_HMACSHA1FuncsTemplate
void MATHi_HMACSHA1FuncsTemplate(void);

asm void MATHi_HMACSHA1FuncsTemplate(void) {
    dcd MATH_SHA1_DIGEST_SIZE // dlength
    dcd MATH_SHA1_BLOCK_SIZE  // blength
    dcd 0                     // context
    dcd 0                     // hash_buf
    dcd 0                     // HashReset
    dcd 0                     // HashSetSource
    dcd 0                     // HashGetDigest
}

#pragma force_active reset
