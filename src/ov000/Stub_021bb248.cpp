#include "ov000/VObj.h"

typedef struct {
    u32 unk_0_0 : 11;
    u32 unk_0_11 : 1;
    u32 unk_0_12 : 4;
    u32 unk_0_16 : 5;
    u32 unk_0_21 : 3;
    u32 unk_0_24 : 6;
    u32 unk_0_30 : 2;
} Bits021bb248;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Sub021bb248;

typedef struct {
    u8 unk_00[0xb0];
    Sub021bb248 *unk_b0;
} Obj021bb248;

extern "C" {

extern u8 *const data_02097d48;
s32 func_02043d48(void *p);

void func_ov000_021bb248(Obj021bb248 *self) {
    Sub021bb248 *sub = self->unk_b0;
    u8 *p = data_02097d48;
    u32 flags = sub->unk_0c;
    u32 v = (flags & 0x1f0000) >> 16;
    if (v > 0x1e) {
        v = 0x1e;
    }
    sub->unk_0c = (flags & 0xc0e0f7ff) | (v << 16) | (func_02043d48(p + 0x8b0) << 24) | 0x800;
}

}
