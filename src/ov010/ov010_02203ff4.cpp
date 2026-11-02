#include "ov010/ov010.h"

extern "C" {

extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
void func_ov010_02203f08(EffectObj *fx);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

void func_ov010_02203ff4(Actor *self) {
    if (self->model == NULL) {
        return;
    }
    func_ov000_02190a80(self->model, func_0203db40((u8 *)self + 0x24));
}

void func_ov010_02204020(void) {
}

void func_ov010_02204024(void) {
}

void func_ov010_02204028(void) {
}

void func_ov010_0220402c(void) {
}

#ifdef NONMATCHING
// func_ov010_02204030 (0x1d4 bytes, picks the point of a ring around c nearest to tgt): 26 / 23 (raw / masked).
// This file's .text ends at 0x02204030, so it goes here once it matches. Blocker: pressure-mode register
// allocation of the loop's LICM'd preheader values; two of the misses are bl against the ROM's blx to the Thumb
// MTX_RotY33_ (only the link resolves that). History: docs/MATCHING.md rounds qpA, pmA, nmA, mtA; docs/UNMATCHED.md.
typedef struct Ov010Ring4030 {
    VecFx32 pos;
    s32 unk_0c;
    s32 r;
} Ov010Ring4030;

// MTX_RotY33_, MTX_MultVec33 and VEC_Add come from nitro/fx.h (through ov010/ov010.h).
extern s32 Ov003Vec_DistSq(const VecFx32 *a, const VecFx32 *b);

static inline s16 Ov010_SinIdx(int idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline s16 Ov010_CosIdx(int idx) {
    return FX_SinCosTable_[idx * 2 + 1];
}

static inline void Ov010_RotY33(MtxFx33 *m, s32 s, s32 c) {
    MTX_RotY33_(m, s, c);
}

void func_ov010_02204030(VecFx32 *out, const Ov010Ring4030 *c, const VecFx32 *tgt, s32 n, u16 ang) {
    VecFx32 v;
    VecFx32 t;
    MtxFx33 m;
    MtxFx33 m2;
    u16 cur = ang;
    u16 step = 0xffff / n;
    s32 best;
    s32 i;
    s32 y;
    s32 d;
    Ov010_VecSet(&v, 0, 0, Ov010_FxMul(c->r, 0x1000));
    y = c->pos.y;
    Ov010_RotY33(&m, Ov010_SinIdx(ang >> 4), Ov010_CosIdx(ang >> 4));
    MTX_MultVec33(&v, &m, &v);
    VEC_Add(&v, &c->pos, &v);
    v.y = y;
    best = Ov003Vec_DistSq(&v, tgt);
    for (i = 1; i < n; i++) {
        cur += step;
        Ov010_VecSet(&t, 0, 0, Ov010_FxMul(c->r, 0x1000));
        Ov010_RotY33(&m2, Ov010_SinIdx(cur >> 4), Ov010_CosIdx(cur >> 4));
        MTX_MultVec33(&t, &m2, &t);
        VEC_Add(&t, &c->pos, &t);
        t.y = y;
        d = Ov003Vec_DistSq(&t, tgt);
        if (best > d) {
            best = d;
            v = t;
        }
    }
    *out = v;
}
#endif

}
