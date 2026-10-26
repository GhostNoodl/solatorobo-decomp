#ifndef OV008_H
#define OV008_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov008V {
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
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
    virtual s32 v38(...);
    virtual s32 v3c(...);
    virtual s32 v40(...);
    virtual s32 v44(...);
    virtual s32 v48(...);
    virtual s32 v4c(...);
    virtual s32 v50(...);
    virtual s32 v54(...);
    virtual s32 v58(...);
    virtual s32 v5c(...);
    virtual s32 v60(...);
    virtual s32 v64(...);
    virtual s32 v68(...);
    virtual s32 v6c(...);
    virtual s32 v70(...);
    virtual s32 v74(...);
    virtual s32 v78(...);
    virtual s32 v7c(...);
    virtual s32 v80(...);
    virtual s32 v84(...);
    virtual s32 v88(...);
    virtual s32 v8c(...);
    virtual s32 v90(...);
    virtual s32 v94(...);
    virtual s32 v98(...);
    virtual s32 v9c(...);
    virtual s32 va0(...);
    virtual s32 va4(...);
    virtual s32 va8(...);
    virtual s32 vac(...);
    virtual s32 vb0(...);
    virtual s32 vb4(...);
    virtual s32 vb8(...);
    virtual s32 vbc(...);
    virtual s32 vc0(...);
    virtual s32 vc4(...);
    virtual s32 vc8(...);
    virtual s32 vcc(...);
    virtual s32 vd0(...);
    virtual s32 vd4(...);
    virtual s32 vd8(...);
    virtual s32 vdc(...);
    virtual s32 ve0(...);
    virtual s32 ve4(...);
    virtual s32 ve8(...);
    virtual s32 vec(...);
    virtual s32 vf0(...);
    virtual s32 vf4(...);
    virtual s32 vf8(...);
    virtual s32 vfc(...);
    virtual s32 v100(...);
    virtual s32 v104(...);
    virtual s32 v108(...);
    virtual s32 v10c(...);
    virtual s32 v110(...);
    virtual s32 v114(...);
    virtual s32 v118(...);
    virtual s32 v11c(...);
    virtual s32 v120(...);
    virtual s32 v124(...);
    virtual s32 v128(...);
    virtual s32 v12c(...);
    virtual s32 v130(...);
    virtual s32 v134(...);
    virtual s32 v138(...);
    virtual s32 v13c(...);
    virtual s32 v140(...);
    virtual s32 v144(...);
    virtual s32 v148(...);
    virtual s32 v14c(...);
    virtual s32 v150(...);
    virtual s32 v154(...);
    virtual s32 v158(...);
    virtual s32 v15c(...);
    virtual s32 v160(...);
    virtual s32 v164(...);
    virtual s32 v168(...);
    virtual s32 v16c(...);
    virtual s32 v170(...);
    virtual s32 v174(...);
    virtual s32 v178(...);
    virtual s32 v17c(...);
    virtual s32 v180(...);
    virtual s32 v184(...);
    virtual s32 v188(...);
    virtual s32 v18c(...);
    virtual s32 v190(...);
    virtual s32 v194(...);
    virtual s32 v198(...);
    virtual s32 v19c(...);
    virtual s32 v1a0(...);
    virtual s32 v1a4(...);
    virtual s32 v1a8(...);
    virtual s32 v1ac(...);
    virtual s32 v1b0(...);
    virtual s32 v1b4(...);
    virtual s32 v1b8(...);
    virtual s32 v1bc(...);
    virtual s32 v1c0(...);
    virtual s32 v1c4(...);
    virtual s32 v1c8(...);
    virtual s32 v1cc(...);
    virtual s32 v1d0(...);
    virtual s32 v1d4(...);
    virtual s32 v1d8(...);
    virtual s32 v1dc(...);
    virtual s32 v1e0(...);
    virtual s32 v1e4(...);
    virtual s32 v1e8(...);
    virtual s32 v1ec(...);
    virtual s32 v1f0(...);
    virtual s32 v1f4(...);
    virtual s32 v1f8(...);
    virtual s32 v1fc(...);
};

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))
#define VOBJ(p, off) ((Ov008V *)((u8 *)(p) + (off)))

struct Ov008Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern "C" {
extern Ov008Heap *data_02097dd0;
void *func_0203dd9c(u32 size);
void func_0203de1c(void *p);
void func_02041558(void *p);
void func_02041278(void *p);
void func_02041218(void *p);
void func_ov000_0218fee4(void *p);
}

// Frees the object at field with the default heap selected.
#define OV008_FREE(field, T, stmt)                      \
    {                                                   \
        u32 saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->def;        \
        if ((field) != NULL) {                          \
            T p_ = (field);                             \
            if (p_ != NULL) {                           \
                stmt;                                   \
            }                                           \
            (field) = NULL;                             \
        }                                               \
        data_02097dd0->cur = saved;                     \
    }

#define OV008_FREE_V(field, slot) OV008_FREE(field, Ov008V *, p_->slot())
#define OV008_FREE_D(field, dtor) OV008_FREE(field, void *, (dtor(p_), func_0203de1c(p_)))
#define OV008_FREE_M(field) \
    OV008_FREE(field, void *, (func_02041558(p_), func_02041278((u8 *)p_ + 0x88), func_0203de1c(p_)))

extern "C" {
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, u8 d);
}

static inline void Ov008_DrawModel(void *m) {
    void *anim;
    void *res = FLD(void *, m, 0x28);
    void *arg;
    void *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, m, 0x80) > 0) {
        anim = FLD(void *, m, 0x78);
    }
    if (anim != NULL && (t = FLD(void *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(m, arg, anim, 0);
}

static inline void *Ov008_GetTex(void *m, void *res, void *anim) {
    if (anim != NULL && FLD(void *, anim, 0x4) != NULL) {
        return FLD(void *, FLD(void *, anim, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0), 0xc));
}

static inline void Ov008_DrawModel2(void *m) {
    void *res = FLD(void *, m, 0x28);
    if (res != NULL) {
        void *anim = 0 >= FLD(s32, m, 0x80) ? NULL : FLD(void *, m, 0x78);
        func_02042628(m, Ov008_GetTex(m, res, anim), anim, 0);
    }
}

static inline s32 Ov008_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

#define OV008_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline s32 Ov008_Abs(s32 v) {
    return v < 0 ? -v : v;
}

#endif
