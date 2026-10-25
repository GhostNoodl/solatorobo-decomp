#include "ov000/VObj.h"

typedef struct {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
} Lerp0218a56c;

typedef struct {
    s32 x0;
    s32 x1;
    u16 y0;
    u16 y1;
} LerpAngle0218a5ec;

extern "C" {

s32 FX_Div(s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

s32 func_ov000_0218a56c(Lerp0218a56c *self, s32 v) {
    s32 x0 = self->x0;
    s32 x1 = self->x1;
    s32 r = 0;
    if (x0 < x1) {
        if (v < x0) {
            r = self->y0;
        } else if (v > x1) {
            r = self->y1;
        }
    } else {
        if (v > x0) {
            r = self->y0;
        } else if (v < x1) {
            r = self->y1;
        }
    }
    if (r != 0) {
        return r;
    }
    return self->y0 + FX_Mul(self->y1 - self->y0, FX_Div(v - x0, x1 - x0));
}

/* The angle form of the lerp above; the const pointee lets the 0x8000 stack argument go out before the
 * two halfword loads. */
u16 func_ov000_0218a5ec(const LerpAngle0218a5ec *self, s32 v) {
    s32 x0 = self->x0;
    s32 x1 = self->x1;
    u16 r = 0;
    if (x0 < x1) {
        if (v < x0) {
            r = self->y0;
        } else if (v > x1) {
            r = self->y1;
        }
    } else {
        if (v > x0) {
            r = self->y0;
        } else if (v < x1) {
            r = self->y1;
        }
    }
    if (r == 0) {
        r = func_01ffc128(self->y1, self->y0, FX_Div(v - x0, x1 - x0), 1, 0x8000);
    }
    return r;
}

}
