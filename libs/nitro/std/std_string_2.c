#include "types.h"

#define STDi_HAS_ZERO(w) (~((((w) & 0x7f7f7f7f) + 0x7f7f7f7f) | (w) | 0x7f7f7f7f))

int STD_CompareNString(const char *str1, const char *str2, int len) {
    if (len) {
        u32 align1 = (u32)str1 & 3;
        u32 align2 = (u32)str2 & 3;
        int i = 0;
        int c, d;

        if ((align1 ^ align2) == 0) {
            if (align1 != 0) {
                for (; i + align1 < 4 && i < len; i++) {
                    c = ((const u8 *)str1)[i];
                    d = ((const u8 *)str2)[i];
                    if (c != d || c == 0) {
                        return c - d;
                    }
                }
            }
            for (; i <= len - 4; i += 4) {
                u32 w1 = *(const u32 *)(str1 + i);
                u32 w2 = *(const u32 *)(str2 + i);
                if (w1 != w2 || STDi_HAS_ZERO(w1)) {
                    break;
                }
            }
        }
        for (; i < len; i++) {
            c = ((const u8 *)str1)[i];
            d = ((const u8 *)str2)[i];
            if (c != d || c == 0) {
                return c - d;
            }
        }
    }
    return 0;
}

int func_0201e950(const char *str1, const char *str2, int len) {
    while (len-- != 0 && *str2 != '\0') {
        int c = *(const u8 *)str1;
        int d = *(const u8 *)str2;
        if (c != d) {
            return c - d;
        }
        str1++;
        str2++;
    }
    return *(const u8 *)str1;
}
