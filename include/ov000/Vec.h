#ifndef OV000_VEC_H
#define OV000_VEC_H

#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

// FX_SinCosTable_ (0x02071060) sits in main's unsplit .text with no symbol of its own, so
// it is addressed from the nearest main symbol. Each entry pair is {sin, cos}.
#ifdef __cplusplus
extern "C" {
#endif
void *func_02070dcc(int kind);
#ifdef __cplusplus
}
#endif
#define FX_SinCosTable_ ((const s16 *)((const u8 *)func_02070dcc + 0x294))

#endif
