#include "ov000/VObj.h"

struct Bits_20 { u32 b0 : 1; u32 b1 : 1; };

static inline BOOL Bit1_20_Inline(void *self) { return ((Bits_20 *)((u8 *)self + 0x20))->b1 != 0; }

extern "C" {

bool func_ov000_02172a3c(void *self) {
    return Bit1_20_Inline(self);
}

}
