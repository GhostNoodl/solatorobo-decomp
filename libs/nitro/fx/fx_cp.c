#include "nitro/fx.h"

fx32 FX_Div(fx32 numer, fx32 denom) {
    FX_DivAsync(numer, denom);
    return FX_GetDivResult();
}

fx32 FX_Inv(fx32 denom) {
    FX_InvAsync(denom);
    return FX_GetDivResult();
}

fx32 FX_Sqrt(fx32 x) {
    if (x > 0) {
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)((fx64)x << 32);
        return FX_GetSqrtResult();
    } else {
        return 0;
    }
}

// The library reads the 64-bit result with one ldm, which dsi/1.3p1 only emits for a non-volatile read
fx64c FX_GetDivResultFx64c(void) {
    while (REG_DIVCNT & REG_DIVCNT_BUSY_MASK) {
    }
    return (fx64c)*(u64 *)0x040002a0;
}

fx32 FX_GetDivResult(void) {
    while (REG_DIVCNT & REG_DIVCNT_BUSY_MASK) {
    }
    return (fx32)((*(u64 *)0x040002a0 + (1 << (32 - FX32_SHIFT - 1))) >> (32 - FX32_SHIFT));
}

void FX_InvAsync(fx32 denom) {
    REG_DIVCNT = 1;
    REG_DIV_NUMER = (u64)FX32_ONE << 32;
    REG_DIV_DENOM = (u32)denom;
}

fx32 FX_GetSqrtResult(void) {
    while (REG_SQRTCNT & REG_SQRTCNT_BUSY_MASK) {
    }
    return (fx32)((REG_SQRT_RESULT + (1 << (10 - 1))) >> 10);
}

void FX_DivAsync(fx32 numer, fx32 denom) {
    REG_DIVCNT = 1;
    REG_DIV_NUMER = (u64)numer << 32;
    REG_DIV_DENOM = (u32)denom;
}
