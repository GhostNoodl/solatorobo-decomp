#include "types.h"
typedef unsigned long size_t;

void func_020086e0(const char *s);
void func_020086e4(const char *s);
int func_020086e8(void);
void func_020086f0(void);

#pragma force_active on
void *func_020086b0(void *p, size_t n) {
    unsigned char *q = (unsigned char *)p;
    if (p == NULL || n == 0)
        return p;
    do {
        *q++ = 0;
    } while (--n);
    return p;
}
#pragma force_active reset

void func_020086d4(void) {
    func_020086f0();
}

void func_020086e0(const char *s) {
}

void func_020086e4(const char *s) {
}

int func_020086e8(void) {
    return 0;
}

void func_020086f0(void) {
}

int __read_console(u32 handle, unsigned char *buffer, size_t *count) {
    size_t i = 0;
    size_t limit = *count;
    while (i < limit) {
        buffer[i] = func_020086e8();
        if (buffer[i] == '\r' || buffer[i] == '\n') {
            *count = i + 1;
            break;
        }
        i++;
    }
    return 0;
}

int __write_console(u32 handle, unsigned char *buffer, size_t *count) {
    char c;
    if (*count > 1) {
        c = buffer[*count - 1];
        buffer[*count - 1] = 0;
        func_020086e4((const char *)buffer);
        func_020086e0(&c);
    } else
        func_020086e0((const char *)buffer);
    return 0;
}

int __close_console(u32 handle) {
    return 0;
}
