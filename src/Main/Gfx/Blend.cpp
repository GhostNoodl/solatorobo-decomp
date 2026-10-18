#include "types.h"

extern "C" {

extern int func_02012ab8(int a, int b);
extern void func_0201378c(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern s16 FX_SinCosTable_[];

static inline int FX_SinIdx(int idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

static inline int Blend_Lerp(int a, int b, int t) {
    return a + (FX_Mul((b - a) << 12, t) >> 12);
}

int data_02097e24[3];
int data_02097e18[3];
int data_02097e0c[3];
int data_02097e00[3];
int data_02097e30[3];

void func_02042eac(int ch, int planes) {
    data_02097e24[ch] = planes;
}

void func_02042ebc(int ch, int duration, int start, int end) {
    data_02097e18[ch] = 0;
    data_02097e0c[ch] = duration;
    data_02097e30[ch] = start;
    data_02097e00[ch] = end;
}

BOOL func_02042ef8(int ch) {
    if (data_02097e24[ch] == 0) {
        return FALSE;
    }
    if (++data_02097e18[ch] >= data_02097e0c[ch]) {
        data_02097e18[ch] = data_02097e0c[ch];
    }
    return TRUE;
}

#ifdef NONMATCHING
// Register allocation differs around the lerp.
void func_02042f40(int ch) {
    int t;
    int ev1;
    int ev2;
    BOOL done = FALSE;
    if (data_02097e24[ch] == 0) {
        return;
    }
    t = func_02012ab8(data_02097e18[ch] << 12, data_02097e0c[ch] << 12);
    if (t >= 0x1000) {
        t = 0x1000;
        done = TRUE;
    }
    ev1 = Blend_Lerp(data_02097e30[ch], data_02097e00[ch], FX_SinIdx((t << 14) >> 16));
    ev2 = 16 - ev1;
    if (ev1 < 0) {
        ev1 = 0;
    } else if (ev1 > 16) {
        ev1 = 16;
    }
    if (ev2 < 0) {
        ev2 = 0;
    } else if (ev2 > 16) {
        ev2 = 16;
    }
    if (ch == 1) {
        func_0201378c((volatile void *)0x4000050, 0, data_02097e24[ch], ev1, ev2);
    } else {
        func_0201378c((volatile void *)0x4001050, 0, data_02097e24[ch], ev1, ev2);
    }
    if (done) {
        data_02097e24[ch] = 0;
    }
}
#endif

}
