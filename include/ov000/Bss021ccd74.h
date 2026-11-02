#ifndef OV000_BSS021CCD74_H
#define OV000_BSS021CCD74_H

#include "types.h"
#include "nitro/fx.h"

struct Model;

// data_ov000_021ccd74 (.bss): three models made by func_ov000_021bce90 and freed by
// func_ov000_021bd09c, a byte that func_ov000_021c17dc sets each frame, and a pending matrix and
// offset that func_ov000_021c1e78 posts and func_ov000_021c2090 consumes (and clears).
typedef struct Bss021ccd74 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ struct Model *unk_04;
    /* 0x08 */ MtxFx33 *unk_08;
    /* 0x0c */ struct Model *unk_0c;
    /* 0x10 */ VecFx32 *unk_10;
    /* 0x14 */ struct Model *unk_14;
} Bss021ccd74;

#ifdef __cplusplus
extern "C" {
#endif
extern Bss021ccd74 data_ov000_021ccd74;
#ifdef __cplusplus
}
#endif

#endif
