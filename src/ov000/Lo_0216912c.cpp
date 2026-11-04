#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u32 Rand_GetGlobal(void);
void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);
void Obj021c2114_Release(void *p);


void Lo021cb7ec_SetValue(Lo021cb7ec *self, s32 a, s32 b, s32 c, LoDE de) {
    if (self->unk_a0 != a) {
        self->unk_a0 = a;
        self->unk_5c = 0;
        self->unk_60 = 0;
        self->unk_64 = 0;
        self->unk_68 = 0;
        self->unk_6c = 0x1000;
        self->unk_58 = b;
    }
    if (c < (self->unk_64 >> 12)) {
        self->unk_a8 = 10;
        self->unk_ac = self->unk_5c;
        self->unk_a4 = Rand_GetGlobal();
    }
    if (self->unk_60 == 0) {
        self->unk_5c = c << 12;
    }
    Obj0215fdfc_SetRange(self, c, de.d);
    self->unk_80.x = de.e[0];
    self->unk_80.y = de.e[1];
    self->unk_80.z = de.e[2];
    self->unk_0c_1 = 0;
    self->unk_0c_16 = 1;
}

}
