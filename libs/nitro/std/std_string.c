#include "types.h"

#define STDi_HAS_ZERO(w) (~((((w) & 0x7f7f7f7f) + 0x7f7f7f7f) | (w) | 0x7f7f7f7f))

int STD_GetStringLength(const char *str);

char *STD_CopyString(char *destp, const char *srcp) {
    char *retval = destp;
    while (*srcp) {
        *destp++ = (char)*srcp++;
    }
    *destp = '\0';
    return retval;
}

int STD_CopyLStringZeroFill(char *destp, const char *srcp, int n) {
    int i;
    const char *s = srcp;
    for (i = 0; i < n - 1; i++) {
        destp[i] = (char)*s;
        if (*s) {
            s++;
        }
    }
    if (i < n) {
        destp[i] = '\0';
    }
    return STD_GetStringLength(srcp);
}

int STD_CopyLString(char *destp, const char *srcp, int siz) {
    u32 dstAlign = (u32)destp & 3;
    u32 srcAlign = (u32)srcp & 3;
    const char *s = srcp;
    int i = 0;

    if ((dstAlign ^ srcAlign) == 0) {
        if (dstAlign != 0) {
            for (; i + dstAlign < 4 && i < siz - 1; i++) {
                destp[i] = *s;
                if (*s == '\0') {
                    goto end;
                }
                s++;
            }
        }
        for (; i < siz - 4; i += 4) {
            u32 w = *(const u32 *)(srcp + i);
            if (STDi_HAS_ZERO(w)) {
                break;
            }
            *(u32 *)(destp + i) = w;
        }
        s = srcp + i;
    }
    for (; i < siz - 1; i++) {
        destp[i] = *s;
        if (*s == '\0') {
            break;
        }
        s++;
    }
end:
    if (i >= siz - 1 && siz > 0) {
        destp[i] = '\0';
    }
    if (*s) {
        i += STD_GetStringLength(s);
    }
    return i;
}

char *STD_SearchString(const char *srcp, const char *str) {
    int i;
    int n;
    for (i = 0; srcp[i]; i++) {
        n = 0;
        while (str[n] && srcp[i + n] == str[n]) {
            n++;
        }
        if (str[n] == '\0') {
            return (char *)&srcp[i];
        }
    }
    return NULL;
}

int STD_GetStringLength(const char *str) {
    int n = 0;
    const u32 *p;
    while (((u32)(str + n) & 3) != 0) {
        if (str[n] == '\0') {
            return n;
        }
        n++;
    }
    p = (const u32 *)(str + n);
    for (;;) {
        u32 w = *p;
        if (STDi_HAS_ZERO(w)) {
            break;
        }
        p++;
        n += 4;
    }
    while (str[n]) {
        n++;
    }
    return n;
}

char *STD_ConcatenateString(char *str1, const char *str2) {
    int n = STD_GetStringLength(str1);
    (void)STD_CopyString(&str1[n], str2);
    return str1;
}
