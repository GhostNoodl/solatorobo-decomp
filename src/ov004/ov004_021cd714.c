// DSProtect: classifies an ARM instruction as BLX (1), BL (2), B (3) or something else (0).
#include "types.h"

#pragma force_active on

s32 func_ov004_021cd714(u32 insn) {
    u32 hi = (insn >> 24) & 0xff;
    if ((hi & 0xe) == 0xa) {
        if ((hi & 0xf0) == 0xf0) {
            return 1;
        }
        return (hi & 1) ? 2 : 3;
    }
    return 0;
}

#pragma force_active reset
