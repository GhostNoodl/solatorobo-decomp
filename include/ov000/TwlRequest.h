#ifndef OV000_TWLREQUEST_H
#define OV000_TWLREQUEST_H

#include "types.h"

// A 0x1c-byte request object of the TWL-only code (Twl0214b570_Init; ov003's model loader and
// ov011 keep one). func_ov000_0214b5e8 starts it: on a TWL it goes to state 1 and the TWL code
// (absolute symbols) finishes it; on a DS it is done at once with unk_08 = 0.
typedef struct Twl0214b570 {
    u16 unk_00;
    s32 state;  // 0x04 0 idle, 1 running (TWL only), 2 done (func_ov000_0214b640)
    s32 unk_08; // -1 while a TWL request runs; read by func_ov000_0214b6d0
    s32 unk_0c; // the result func_ov000_0214b670 returns once done with unk_08 == -1
    s32 unk_10; // the argument of func_ov000_0214b5e8
    s32 unk_14;
    s32 unk_18;
} Twl0214b570;
SIZE_ASSERT(Twl0214b570, 0x1c);

#endif
