#ifndef OV000_VEC_H
#define OV000_VEC_H

#include "types.h"

#ifndef VECFX32_DEFINED
#define VECFX32_DEFINED
typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;
#endif

// FX_SinCosTable_ (0x02071060): entry pairs are {sin, cos}.
#ifdef __cplusplus
extern "C" {
#endif
extern const s16 FX_SinCosTable_[];
#ifdef __cplusplus
}
#endif

#endif
