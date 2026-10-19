#include "types.h"

typedef u16 wchar_t;

typedef struct MSLCtypeCmpt {
    u8 unk_00[4];
    int (*encode_mb)(char *s, wchar_t wc);
} MSLCtypeCmpt;

typedef struct MSLLocale {
    u8 unk_00[8];
    MSLCtypeCmpt *ctype_cmpt_ptr;
} MSLLocale;

extern MSLLocale data_0208abb8;
extern char *strncpy(char *dst, const char *src, u32 n);

int __mbtowc_noconv(wchar_t *pwc, const char *s, u32 n) {
    if (!s) {
        return 0;
    }
    if (!n) {
        return -1;
    }
    if (pwc) {
        *pwc = (u8)*s;
    }
    if (!*(const u8 *)s) {
        return 0;
    }
    return 1;
}

int __wctomb_noconv(char *s, wchar_t wchar) {
    if (!s) {
        return 0;
    }
    *s = wchar;
    return 1;
}

int wctomb(char *s, wchar_t wchar) {
    return data_0208abb8.ctype_cmpt_ptr->encode_mb(s, wchar);
}

u32 wcstombs(char *s, const wchar_t *pwcs, u32 n) {
    u32 chars_written = 0;
    int result;
    char temp[3];
    const wchar_t *source;
    if (!s || !pwcs) {
        return 0;
    }
    source = pwcs;
    while (chars_written <= n) {
        if (!*source) {
            s[chars_written] = '\0';
            break;
        } else {
            result = wctomb(temp, *source++);
            if (chars_written + result <= n) {
                strncpy(s + chars_written, temp, result);
                chars_written += result;
            } else {
                break;
            }
        }
    }
    return chars_written;
}
