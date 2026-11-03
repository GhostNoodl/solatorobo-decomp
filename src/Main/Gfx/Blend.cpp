#include "types.h"

extern "C" {

extern int FX_Div(int a, int b);
extern void G2x_SetBlendAlpha_(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern const s16 FX_SinCosTable_[];

static inline int FX_SinIdx(int idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

static inline int Blend_Lerp(int a, int b, int t) {
    return a + (FX_Mul((b - a) << 12, t) >> 12);
}

int gBlendPlanes[3];
int gBlendTimer[3];
int gBlendDuration[3];
int gBlendEnd[3];
int gBlendStart[3];

void Blend_SetPlanes(int ch, int planes) {
    gBlendPlanes[ch] = planes;
}

void Blend_Start(int ch, int duration, int start, int end) {
    gBlendTimer[ch] = 0;
    gBlendDuration[ch] = duration;
    gBlendStart[ch] = start;
    gBlendEnd[ch] = end;
}

BOOL Blend_Tick(int ch) {
    if (gBlendPlanes[ch] == 0) {
        return FALSE;
    }
    if (++gBlendTimer[ch] >= gBlendDuration[ch]) {
        gBlendTimer[ch] = gBlendDuration[ch];
    }
    return TRUE;
}

void func_02042f40(int ch);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match needed a `volatile int` parameter on FX_SinIdx to keep
// the index a separate value; without it the lerp's registers differ. The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void func_02042f40(int ch) {
    int t;
    int ev1;
    int ev2;
    BOOL done = FALSE;
    if (gBlendPlanes[ch] == 0) {
        return;
    }
    t = FX_Div(gBlendTimer[ch] << 12, gBlendDuration[ch] << 12);
    if (t >= 0x1000) {
        t = 0x1000;
        done = TRUE;
    }
    ev1 = Blend_Lerp(gBlendStart[ch], gBlendEnd[ch], FX_SinIdx((t << 14) >> 16));
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
        G2x_SetBlendAlpha_((volatile void *)0x4000050, 0, gBlendPlanes[ch], ev1, ev2);
    } else {
        G2x_SetBlendAlpha_((volatile void *)0x4001050, 0, gBlendPlanes[ch], ev1, ev2);
    }
    if (done) {
        gBlendPlanes[ch] = 0;
    }
}
#endif

}
