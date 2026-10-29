#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d112c(void *p);
void func_0203f2b8(void *p);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov011_FreeSub48(Ov011Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        void *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            func_0203de1c(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_ov011_022042fc(Ov011Actor *self) {
    func_ov003_021d112c(self);
    Ov011_FreeSub48(self);
    Ov011_VecSet(&FLD(Ov011Vec, self->unk_44, 0xc), 0, 0x1800, -self->unk_64 >> 1);
    FLD(s32, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = 0x1000;
    FLD(s32, self, 0xf8) = -0x32666;
    self->unk_84.x = 0;
    self->unk_84.y = 0;
    self->unk_84.z = -0x12000;
    FLD(u16, self, 0xfc) = 0;
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_10 = 1;
    self->unk_ea_6 = 1;
}

void func_ov011_022043cc(Ov011Actor *self) {
    Ov011Sub40 *s = self->unk_40;
    u64 f = s->flags;
    if (f == 0) {
        return;
    }
    if (f & 0x200000) {
        func_ov000_02198360(s, 0x15, 0);
        return;
    }
    if (f & 0x40000) {
        FLD(u16, self, 0xfc) = 20;
    }
}

}
