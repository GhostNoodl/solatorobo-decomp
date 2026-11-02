#include "ov000/VObj.h"

struct Bits_04 { u32 b0 : 4; u32 b4 : 1; };

static inline BOOL Bit4_Inline(void *self) { return ((Bits_04 *)((u8 *)self + 4))->b4 != 0; }

extern "C" {

bool Task_GetFlag4(void *self) {
    return Bit4_Inline(self);
}

}
