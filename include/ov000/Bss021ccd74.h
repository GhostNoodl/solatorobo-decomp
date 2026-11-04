#ifndef OV000_BSS021CCD74_H
#define OV000_BSS021CCD74_H

#include "types.h"
#include "nitro/fx.h"

struct Model;

// data_ov000_021ccd74 (.bss): three models made by Bss021ccd74_LoadModels and freed by
// Bss021ccd74_FreeModels, the alpha cap that ActorMarker_DrawKind0b sets each frame, and a pending matrix and
// offset that Obj021c2114_Draw posts and Obj021c2114_JointCallback consumes (and clears).
typedef struct Bss021ccd74 {
    /* 0x00 */ s8 alpha; // the polygon alpha cap of ActorMarker_MatCallback0b (0..30, from the drawn object's alpha)
    /* 0x04 */ struct Model *unk_04;
    /* 0x08 */ MtxFx33 *jointRot;  // copied to the joint's rotation by Obj021c2114_JointCallback
    /* 0x0c */ struct Model *unk_0c;
    /* 0x10 */ VecFx32 *jointTrans; // added to the joint's translation by Obj021c2114_JointCallback
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
