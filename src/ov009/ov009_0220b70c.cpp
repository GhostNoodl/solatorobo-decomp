#include "ov009/ov009.h"

extern "C" {

extern const Ov009Vec data_ov009_02215f74[];
extern Ov009Vec data_ov009_02215f78[];
extern Ov009Vec data_ov009_02215f7c[];
extern u8 data_ov009_02215efc[];
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);

static inline void Ov009_SetPos(Ov009Actor *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

void func_ov009_0220b70c(Ov009Actor *self) {
    Ov009Sub48 *s48;
    func_ov003_021d112c(self);
    if (self->unk_1a != 0) {
        Ov009_SetPos(self, data_ov009_02215f74[self->unk_1a - 1].x, data_ov009_02215f74[self->unk_1a - 1].y, data_ov009_02215f74[self->unk_1a - 1].z);
    }
    switch (self->kind) {
    case 0x5808:
    case 0x580a:
        FLD(u8, self, 0xf7) = 0;
        break;
    case 0x5809:
    case 0x580b: {
        Ov009Sub48 *p;
        FLD(u8, self, 0xf7) = 1;
        func_01ffc9fc(&FLD(Ov009Vec, self, 0xfc), data_ov009_02215efc, (u16)(func_02040528(0x3c) * 0xb6));
        self->pos = FLD(Ov009Vec, self, 0xfc);
        FLD(u16, self, 0xf2) = self->kind == 0x5809 ? 0x78 : 0xa0;
        p = self->unk_48;
        FLD(s32, self, 0xf8) = p->unk_38 << 1;
        p->unk_30 = 0;
        self->unk_93_4 = 1;
        break;
    }
    }
    switch (self->kind) {
    case 0x580b:
        FLD(u8, self, 0xf6) = 0x96;
        FLD(u16, self, 0xf4) = 0x64;
        break;
    case 0x5809:
        FLD(u8, self, 0xf6) = 0xaa;
        FLD(u16, self, 0xf4) = 0x96;
        break;
    }
    FLD(u16, self, 0xf0) = 0;
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_14 = 1;
}

}
