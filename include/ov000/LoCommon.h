#ifndef OV000_LOCOMMON_H
#define OV000_LOCOMMON_H

#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct LoBits {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 1;
    u32 b12 : 1;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 b15 : 1;
    u32 b16 : 1;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 1;
    u32 b26 : 1;
    u32 b27 : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 b30 : 1;
    u32 b31 : 1;
} LoBits;

#define LBIT(obj, off) LFLD(LoBits, obj, off)
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef void *(*LoCreateFn)(void);

#ifdef __cplusplus
extern "C" {
#endif

extern LoCreateFn data_ov000_021c9c6c[];
void *func_0203dd9c(u32 size);
void func_ov000_02173648(void *self);
void func_ov000_02178dcc(void *p, BOOL add);

#ifdef __cplusplus
}
#endif

#define LO_HEAP_PUSH(saved)                          \
    do {                                             \
        (saved) = (u32)data_02097dd0->current;       \
        data_02097dd0->current = data_02097dd0->unk_08; \
    } while (0)
#define LO_HEAP_POP(saved) (data_02097dd0->current = (void *)(saved))

#define LO_FREE_V(self, off)                          \
    do {                                              \
        u32 saved;                                    \
        LO_HEAP_PUSH(saved);                          \
        if (LFLD(VObj *, self, off) != NULL) {        \
            VObj *p_ = LFLD(VObj *, self, off);       \
            if (p_ != NULL) {                         \
                p_->vfunc_04();                       \
            }                                         \
            LFLD(VObj *, self, off) = NULL;           \
        }                                             \
        LO_HEAP_POP(saved);                           \
    } while (0)

/* Free a model-like object: dtor parts then operator delete. */
#define LO_FREE_M(self, off)                          \
    do {                                              \
        u32 saved;                                    \
        LO_HEAP_PUSH(saved);                          \
        if (LFLD(void *, self, off) != NULL) {        \
            void *p_ = LFLD(void *, self, off);       \
            if (p_ != NULL) {                         \
                func_02041558((struct Model *)p_);    \
                func_02041278((u8 *)p_ + 0x88);       \
                func_0203de1c(p_);                    \
            }                                         \
            LFLD(void *, self, off) = NULL;           \
        }                                             \
        LO_HEAP_POP(saved);                           \
    } while (0)

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 st : 2;
} LoTaskFlags;

#endif
