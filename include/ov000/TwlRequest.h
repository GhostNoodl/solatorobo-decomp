#ifndef OV000_TWLREQUEST_H
#define OV000_TWLREQUEST_H

#include "types.h"

// A 0x1c-byte request object of the TWL-only code (Twl0214b570_Init; ov003's model loader and
// ov011 keep one). Twl0214b570_Start starts it: on a TWL it goes to state 1 and the TWL code
// (absolute symbols) finishes it; on a DS it is done at once with unk_08 = 0.
typedef struct Twl0214b570 {
    u16 unk_00;
    s32 state;  // 0x04 0 idle, 1 running (TWL only), 2 done (Twl0214b570_IsDone)
    s32 unk_08; // -1 while a TWL request runs; read by Twl0214b570_GetStatus
    void *unk_0c; // the result Twl0214b570_GetResult returns once done with unk_08 == -1 (ov003 and
                  // ov011 bind it as texture image data)
    const char *unk_10; // the argument of Twl0214b570_Start (ov003 and ov011 pass a name)
    s32 unk_14;
    s32 unk_18;
} Twl0214b570;
SIZE_ASSERT(Twl0214b570, 0x1c);

#ifdef __cplusplus
extern "C" {
#endif

Twl0214b570 *Twl0214b570_Init(Twl0214b570 *self);
Twl0214b570 *Twl0214b570_Dtor(Twl0214b570 *self);
void Twl0214b570_Poll(Twl0214b570 *self);
void Twl0214b570_Start(Twl0214b570 *self, const char *arg);
BOOL Twl0214b570_IsDone(Twl0214b570 *self);
BOOL Twl0214b570_HasResult(Twl0214b570 *self);
void *Twl0214b570_GetResult(Twl0214b570 *self);
u32 Twl0214b570_GetStatus(Twl0214b570 *self);

#ifdef __cplusplus
}
#endif

#endif
