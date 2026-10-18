#ifndef OV003_VEC_H
#define OV003_VEC_H

#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov003Vec() {}
};

struct Ov003Rot {
    s16 x;
    s16 y;
    s16 z;
};

struct Ov003Mtx33 {
    s32 m[9];
};

static inline s32 Ov003_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

extern "C" {
extern void func_0201146c(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void func_02011488(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void func_020114a4(Ov003Mtx33 *m, s32 sin, s32 cos);
extern void func_020117a4(const Ov003Vec *v, const Ov003Mtx33 *m, Ov003Vec *out);
extern s32 func_02012ab8(s32 a, s32 b);
extern void func_02012be8(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern s32 func_02012d18(const Ov003Vec *v);
extern void func_02012d78(const Ov003Vec *src, Ov003Vec *dst);
extern void func_02012fb8(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern s32 func_02013068(const Ov003Vec *a, const Ov003Vec *b);
extern u16 func_0201319c(s32 x, s32 z);
extern u16 func_020133a8(s32 v);
extern s16 func_02040528(s32 max);
}

static inline u16 Ov003_Pitch(s32 y) {
    u16 r = 0;
    u16 a = func_020133a8(Ov003_FxMul(y, 0x1000));
    if (a < 0x4000) {
        r = a + 0xbfff;
    } else if (a > 0x4000) {
        r = a - 0x4000;
    }
    return r;
}

#endif
