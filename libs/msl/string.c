#include "types.h"
typedef unsigned long size_t;

size_t strlen(const char *str) {
    size_t len = -1;
    const unsigned char *p = (const unsigned char *)str;
    do
        len++;
    while (*p++);
    return len;
}

char *strncpy(char *dst, const char *src, size_t n) {
    const unsigned char *p = (const unsigned char *)src;
    unsigned char *q = (unsigned char *)dst;
    unsigned char *t;
    if (n) {
        do {
            t = q;
            *q++ = *p++;
            if (!*t) {
                while (--n)
                    *q++ = 0;
                break;
            }
        } while (--n);
    }
    return dst;
}

char *strchr(const char *str, int chr) {
    const unsigned char *p = (const unsigned char *)str;
    unsigned char c = (chr & 0xff);
    unsigned char ch;
    while (ch = *p++)
        if (ch == c)
            return (char *)(p - 1);
    return c ? 0 : (char *)(p - 1);
}
