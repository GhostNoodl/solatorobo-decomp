#include "ov010/ov010.h"

typedef s32 fx32;

// This TU's .rodata (all of it) and its .data up to the copies the static initialiser makes. The
// copied vectors and their sources are weak: the stub loads each through its own pool word, not
// from the section base. All objects are the TU's size-sorted group (order found with solve2.py).
// func_ov010_02203f08 at the end is part of this TU: it scales data_ov010_0220fe38, which it reads
// through the .data base plus an offset.
struct Ov010Rot { u16 x, y, z; };
struct Ov010Handler { s32 key; void (*fn)(void); s32 adj; };

extern "C" {

void func_ov010_02202838(void);
void func_ov010_022028ec(void);

extern const Ov010Rot data_ov010_0220efc8;
extern const Ov010Vec data_ov010_0220efd0;
extern const Ov010Vec data_ov010_0220efdc;
extern const Ov010Vec data_ov010_0220efe8;
extern const Ov010Vec data_ov010_0220eff4;
extern const Ov010Vec data_ov010_0220f000;
extern const Ov010Handler data_ov010_0220f00c[2];
extern const Ov010Rot data_ov010_0220fe30;
extern const Ov010Vec data_ov010_0220fe38;
extern const Ov010Vec data_ov010_0220fe44;
extern const Ov010Vec data_ov010_0220fe50;

static inline fx32 K(fx32 v) { return v; }

__declspec(weak) const Ov010Vec data_ov010_0220f000 = {0, 0, 0};
const Ov010Handler data_ov010_0220f00c[2] = {{0, func_ov010_02202838, 0}, {1, func_ov010_022028ec, 0}};
const Ov010Rot data_ov010_0220efc8 = {0, 0, 0};
const Ov010Rot data_ov010_0220fe30 = data_ov010_0220efc8;
const Ov010Vec data_ov010_0220efdc = {-0x1000, 0, 0};
const Ov010Vec data_ov010_0220efd0 = {0, 0, 0x1000};
__declspec(weak) const Ov010Vec data_ov010_0220fe50 = data_ov010_0220f000;
__declspec(weak) const Ov010Vec data_ov010_0220efe8 = {0, 0x1000, 0};
const Ov010Vec data_ov010_0220fe38 = {K(0x1000), K(0), K(0)};
__declspec(weak) const Ov010Vec data_ov010_0220fe44 = data_ov010_0220efe8;
const Ov010Vec data_ov010_0220eff4 = {0, 0x1be, -0x125e};

}

class Ov010Fx {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    s32 timer;
    s32 scale;
};

extern "C" {

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov010_VecScale(Ov010Vec *out, const Ov010Vec *in, s32 sc) {
    out->x = Ov010_FxMul(in->x, sc);
    out->y = Ov010_FxMul(in->y, sc);
    out->z = Ov010_FxMul(in->z, sc);
}

void func_ov010_02203f08(Ov010Fx *fx) {
    Ov010Vec v;
    if (fx == NULL) {
        return;
    }
    if (fx->timer < 0x14) {
        fx->scale += 0x20;
        fx->scale = Ov010_Clamp(fx->scale, 0, 0x600);
    } else {
        fx->scale += 0x100;
        fx->scale = Ov010_Clamp(fx->scale, 0, 0x2000);
    }
    Ov010_VecScale(&v, &data_ov010_0220fe38, fx->scale);
    fx->v20(&v);
    fx->timer++;
}

}
