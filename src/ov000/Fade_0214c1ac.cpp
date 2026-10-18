#include "types.h"

typedef struct {
    s32 v[4];
} FadeParam;

extern "C" {

extern u8 data_ov000_021ccd24[];

void func_020708fc(s32 a, FadeParam *out);
void func_02070b98(s32 a, FadeParam *out, s32 b, s32 c);
void func_020359fc(FadeParam *a, FadeParam *b, s32 c, s32 d);
void func_02035acc(FadeParam *a, FadeParam *b, s32 c);
BOOL func_02035bd4(FadeParam *a, FadeParam *b, s32 c);

void func_ov000_0214c1ac(void) {
    FadeParam a;
    FadeParam b;

    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    func_020359fc(&a, &b, 2, 0);
    data_ov000_021ccd24[0] = 1;
}

void func_ov000_0214c210(void) {
    FadeParam a;
    FadeParam b;

    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    func_02035acc(&a, &b, 2);
    data_ov000_021ccd24[0] = 0;
}

BOOL func_ov000_0214c270(void) {
    FadeParam a;
    FadeParam b;
    BOOL ret = TRUE;

    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    if (!func_02035bd4(&a, &b, 2)) {
        ret = FALSE;
    }
    return ret;
}

}
