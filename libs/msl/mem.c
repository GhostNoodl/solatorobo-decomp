#include "types.h"

void *func_020056fc(void *dst, const void *src, u32 n) {
    const u8 *p;
    u8 *q;
    for (p = (const u8 *)src, q = (u8 *)dst, n++; --n;) {
        *q++ = *p++;
    }
    return dst;
}

void *memchr(const void *src, int val, u32 n) {
    const u8 *p;
    u32 v = val & 0xff;
    for (p = (const u8 *)src, n++; --n;) {
        if (*p++ == v) {
            return (void *)(p - 1);
        }
    }
    return NULL;
}
