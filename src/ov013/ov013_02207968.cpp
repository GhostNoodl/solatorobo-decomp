#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bd2c;
extern Ov013Actor *func_ov000_0219bf90(void);

Ov013Actor *func_ov013_02207968(Ov013Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov013_0220bd2c;
    FLD(u8, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(u8, self, 0xf1) = 0;
    FLD(u8, self, 0xf2) = 0;
    FLD(u8, self, 0x110) = 0;
    FLD(u8, self, 0x111) = 0;
    FLD(s32, self, 0xf8) = 0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(s32, self, 0x108) = 0;
    FLD(s32, self, 0x10c) = 0;
    return self;
}

void func_ov013_022079bc(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Actor *p;
    func_ov003_021d112c(self);
    self->pos.x = -0x3000;
    self->pos.y = -0x32000;
    self->pos.z = -0x8000;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_48, 0x5c), 0, -0x4cd, 0);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_44, 0xc), 0, -0x4cd, 0);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    self->unk_93_4 = 1;
    self->unk_94_1 = 1;
    self->unk_b6 = 0x46;
}

}
