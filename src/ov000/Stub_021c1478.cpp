#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
} Sub021c1478;

typedef struct {
    u8 unk_00[0xb0];
    Sub021c1478 *unk_b0;
} Obj021c1478;

extern "C" {

extern u8 *data_02097d48;
extern s8 data_ov000_021ccd74;
s32 func_02043d48(void *p);

void func_ov000_021c1478(Obj021c1478 *self) {
    u32 flags;
    u32 v;
    Sub021c1478 *sub = self->unk_b0;
    u8 *p;
    flags = sub->unk_0c;
    v = (flags & 0x1f0000) >> 16;
    p = data_02097d48;
    if ((u32)data_ov000_021ccd74 < v) {
        v = data_ov000_021ccd74;
    }
    if (v >= 0x1e) {
        v = 0x1f;
    }
    sub->unk_0c = (flags & 0xc0e0ffbf) | 0xc0 | (v << 16) | (func_02043d48(p + 0x8b0) << 24);
}

}
