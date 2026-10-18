#include "nitro/fx.h"

u16 FX_Atan(fx32 x) {
    if (x >= 0) {
        if (x > FX32_ONE) {
            return (u16)(16384 - FX_AtanTable_[FX_Inv(x) >> 5]);
        } else if (x < FX32_ONE) {
            return (u16)FX_AtanTable_[x >> 5];
        } else {
            return (u16)8192;
        }
    } else {
        if (x < -FX32_ONE) {
            return (u16)(FX_AtanTable_[FX_Inv(-x) >> 5] - 16384);
        } else if (x > -FX32_ONE) {
            return (u16)(-FX_AtanTable_[-x >> 5]);
        } else {
            return (u16)(-8192);
        }
    }
}

u16 FX_Atan2(fx32 y, fx32 x) {
    fx32 a, b;
    int c;
    BOOL sgn;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                a = y;
                b = x;
                c = 0;
                sgn = TRUE;
            } else if (x < y) {
                a = x;
                b = y;
                c = 16384;
                sgn = FALSE;
            } else {
                return (u16)8192;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                a = x;
                b = y;
                c = 16384;
                sgn = TRUE;
            } else if (x > y) {
                a = y;
                b = x;
                c = 32768;
                sgn = FALSE;
            } else {
                return (u16)24576;
            }
        } else {
            return (u16)16384;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                a = y;
                b = x;
                c = -32768;
                sgn = TRUE;
            } else if (x < y) {
                a = x;
                b = y;
                c = -16384;
                sgn = FALSE;
            } else {
                return (u16)-24576;
            }
        } else if (x > 0) {
            if (x < y) {
                a = x;
                b = y;
                c = -16384;
                sgn = TRUE;
            } else if (x > y) {
                a = y;
                b = x;
                c = 0;
                sgn = FALSE;
            } else {
                return (u16)-8192;
            }
        } else {
            return (u16)-16384;
        }
    } else {
        if (x >= 0) {
            return 0;
        } else {
            return (u16)32768;
        }
    }

    if (b == 0) {
        return 0;
    }
    if (sgn) {
        return (u16)(c + FX_AtanTable_[FX_Div(a, b) >> 5]);
    } else {
        return (u16)(c - FX_AtanTable_[FX_Div(a, b) >> 5]);
    }
}
