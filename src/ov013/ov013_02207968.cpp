#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bd2c;
extern Ov013Actor *func_ov000_0219bf90(void);

Ov013Act_02207968 *func_ov013_02207968(Ov013Act_02207968 *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov013_0220bd2c;
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    self->unk_f1 = 0;
    self->unk_f2 = 0;
    self->unk_110 = 0;
    self->unk_111 = 0;
    self->unk_f8.x = 0;
    self->unk_f8.y = 0;
    self->unk_f8.z = 0;
    self->unk_104.x = 0;
    self->unk_104.y = 0;
    self->unk_104.z = 0;
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
