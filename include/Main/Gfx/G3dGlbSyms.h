#ifndef MAIN_GFX_G3DGLBSYMS_H
#define MAIN_GFX_G3DGLBSYMS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// NNS_G3dGlb (0x020927f8) .projMtx, .cameraMtx, .prmBaseRot, .prmBaseTrans and .prmBaseScale, reached through
// their own symbols. They stay byte arrays: declaring them MtxFx44 / MtxFx43 / ... changes func_02064410's code.
extern u8 data_02092800[];
extern u8 data_02092844[];
extern u8 data_020928b4[];
extern u8 data_020928d8[];
extern u8 data_020928e4[];

#ifdef __cplusplus
}
#endif

#endif
