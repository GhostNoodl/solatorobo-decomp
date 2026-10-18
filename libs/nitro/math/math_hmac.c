#include "math_sha1.h"

#define MATH_HASH_BLOCK_SIZE 64

void MATHi_CalcHMAC(void *mac, const void *message, u32 message_length, const void *key, u32 key_length,
                    MATHiHMACFuncs *funcs) {
    u8 hashed_key[MATH_HASH_BLOCK_SIZE];
    u8 ipad[MATH_HASH_BLOCK_SIZE];
    u8 opad[MATH_HASH_BLOCK_SIZE];
    const u8 *key_ptr = (const u8 *)key;
    u32 i;

    if (mac == NULL || message == NULL || message_length == 0 || key == NULL || key_length == 0 || funcs == NULL) {
        return;
    }

    if (key_length > funcs->blength) {
        funcs->HashReset(funcs->context);
        funcs->HashSetSource(funcs->context, key_ptr, key_length);
        funcs->HashGetDigest(funcs->context, hashed_key);
        key_ptr = hashed_key;
        key_length = funcs->dlength;
    }

    for (i = 0; i < key_length; i++) {
        ipad[i] = (u8)(key_ptr[i] ^ 0x36);
    }
    for (; i < funcs->blength; i++) {
        ipad[i] = 0x36;
    }

    funcs->HashReset(funcs->context);
    funcs->HashSetSource(funcs->context, ipad, funcs->blength);
    funcs->HashSetSource(funcs->context, message, message_length);
    funcs->HashGetDigest(funcs->context, funcs->hash_buf);

    for (i = 0; i < key_length; i++) {
        opad[i] = (u8)(key_ptr[i] ^ 0x5c);
    }
    for (; i < funcs->blength; i++) {
        opad[i] = 0x5c;
    }

    funcs->HashReset(funcs->context);
    funcs->HashSetSource(funcs->context, opad, funcs->blength);
    funcs->HashSetSource(funcs->context, funcs->hash_buf, funcs->dlength);
    funcs->HashGetDigest(funcs->context, mac);
}
