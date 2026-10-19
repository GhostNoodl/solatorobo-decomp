#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0x4];
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
} Obj0215eab4;

typedef struct {
    u8 unk_00[0x68];
    s16 unk_68;
    u8 unk_6a[0x26];
    Obj0215eab4 *unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u16 unk_ac;
    u8 unk_ae[0x6];
    s32 unk_b4;
} Obj021c4fdc;

extern "C" {

void func_ov000_0215eab4(Obj0215eab4 *p);

static inline void SetPos0215eab4(Obj0215eab4 *p, s32 x, s32 y, s32 z) {
    p->unk_04 = x;
    p->unk_08 = y;
    p->unk_0c = z;
}

void func_ov000_021c4fdc(Obj021c4fdc *self, s32 a, const VecFx32 *v) {
    VecFx32 p;
    if (self->unk_94 == 0) {
        return;
    }
    p = *v;
    p.x += self->unk_b4;
    p.y += self->unk_ac << 12;
    p.z = self->unk_68 - 0x100;
    SetPos0215eab4(self->unk_90, p.x, p.y, p.z);
    func_ov000_0215eab4(self->unk_90);
}

}
