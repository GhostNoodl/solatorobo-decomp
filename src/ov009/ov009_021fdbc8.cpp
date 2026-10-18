#include "ov009/ov009.h"

extern "C" {

extern s32 func_02040528(s32 range);
extern Ov009Actor *func_ov000_0219bf90(void);
struct Ov009AngSrc3 {
    u8 unk_00[0x10];
    Ov009Vec pos;
    u8 unk_1c[0x24];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern s32 func_0204bfa8(Ov009AngSrc3 *p);

static inline s32 Ov009_GetAng3(Ov009AngSrc3 *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return func_0204bfa8(p);
}

void func_ov009_021fdbc8(Ov009Actor *self) {
    func_ov003_021d112c(self);
    switch (self->unk_1a) {
    case 0: {
        Ov009AngSrc3 *g = (Ov009AngSrc3 *)((u8 *)data_ov000_021ccd54 + 0xf4);
        u16 a = Ov009_GetAng3(g) + func_02040528(0x1000);
        s32 r = func_02040528(0x1800) + 0x3800;
        self->pos = g->pos;
        self->pos.x += Ov009_FxMul(r, OV009_SIN(a));
        self->pos.z += Ov009_FxMul(r, OV009_COS(a));
        self->pos.y += 0xa000;
        break;
    }
    case 1:
        self->unk_a0 = 0x466;
        func_ov000_02198360(self->unk_40, 0x20, 0);
        break;
    case 2: {
        Ov009Actor *t = func_ov000_0219bf90();
        if (t != NULL) {
            u16 r = t->rot[1];
            u16 a = r + func_02040528(0x1000);
            s64 k = 0x333;
            self->pos.x = t->pos.x;
            self->pos.y = t->pos.y;
            self->pos.z = t->pos.z;
            self->unk_9c = (s32)((OV009_SIN(a) * k + 0x800) >> 12);
            self->unk_a4 = (s32)((OV009_COS(a) * k + 0x800) >> 12);
            self->unk_a0 = 0x266;
            VEC_MultAdd(0x28000, (Ov009Vec *)&self->unk_9c, &self->pos, &self->pos);
        }
        func_ov000_02198360(self->unk_40, 0x20, 0);
        break;
    }
    }
    FLD(u16, self, 0xf4) = self->kind;
    switch (self->kind) {
    case 0x5013:
        FLD(u16, self, 0xf2) = 0x12c;
        break;
    case 0x5045:
        FLD(u16, self, 0xf2) = 0xc8;
        break;
    }
    if (FLD(u8, data_ov000_021ccd54, 0xca) == 2) {
        self->unk_18 = 1;
    }
    FLD(s32, self, 0xf8) = 0;
    self->unk_ea_6 = 1;
}

}
