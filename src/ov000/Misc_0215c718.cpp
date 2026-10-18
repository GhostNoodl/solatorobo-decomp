#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c_0 : 3;
    u32 unk_0c_3 : 1;
    u32 unk_0c_4 : 28;
} Obj0215c720;

static inline BOOL Obj0215c720_TestBit3(Obj0215c720 *self) {
    return self->unk_0c_3 ? TRUE : FALSE;
}

extern "C" {

s32 func_ov000_0215c718(void) {
    return 0x14;
}

s32 func_ov000_0215c720(Obj0215c720 *self) {
    return Obj0215c720_TestBit3(self) ? 9 : 0xc;
}

}
