#include "types.h"

// The tail of printf.c after __pformatter (__pformatter).

typedef char *va_list;
#define va_start(ap, parm) ((ap) = (va_list)((char *)((unsigned long)(&parm) & ~3U) + ((sizeof(parm) + 3U) & ~3U)))

typedef struct __OutStrCtrl {
    /* 0x0 */ char *CharStr;
    /* 0x4 */ u32 MaxCharCount;
    /* 0x8 */ u32 CharsWritten;
} __OutStrCtrl;

extern void *func_020056fc(void *dst, const void *src, u32 n);
extern int __pformatter(void *(*WriteProc)(void *, const char *, u32), void *WriteProcArg, const char *format_str, va_list arg, int is_secure);

extern void (*data_0208de70)(void *a, void *b, void *c);

void *func_020076f4(void *osc, const char *Buffer, u32 NumChars) {
    u32 CharsToBeWritten;
    __OutStrCtrl *Oscp = (__OutStrCtrl *)osc;
    CharsToBeWritten = ((Oscp->CharsWritten + NumChars) <= Oscp->MaxCharCount) ? NumChars : Oscp->MaxCharCount - Oscp->CharsWritten;
    func_020056fc(Oscp->CharStr + Oscp->CharsWritten, Buffer, CharsToBeWritten);
    Oscp->CharsWritten += CharsToBeWritten;
    return (void *)1;
}

int func_02007738(char *s, u32 n, const char *format, va_list arg) {
    int end;
    __OutStrCtrl osc;
    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;
    end = __pformatter(func_020076f4, &osc, format, arg, 0);
    if (s) {
        if (end < n) {
            s[end] = '\0';
        } else if (n > 0) {
            *(s + n - 1) = '\0';
        }
    }
    return end;
}

int func_0200779c(char *s, const char *format, ...) {
    va_list args;
    va_start(args, format);
    return func_02007738(s, (u32)-1, format, args);
}

void func_020077f0(void *a, void *b, void *c);

void func_020077c8(void *a, void *b, void *c) {
    if (data_0208de70 != NULL) {
        data_0208de70(a, b, c);
    } else {
        func_020077f0(a, b, c);
    }
}

void func_020077f0(void *a, void *b, void *c) {
}
