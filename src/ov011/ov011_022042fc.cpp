#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d112c(void *p);

static inline void Ov011_FreeSub48(Ov011Actor *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (self->unk_48 != NULL) {
        void *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            Heap_Free(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
}

void Ov011Act7c4c_Start(Ov011Act7c4c *self) {
    func_ov003_021d112c(self);
    Ov011_FreeSub48(self);
    Ov011_VecSet(&self->unk_44->unk_0c, 0, 0x1800, -self->unk_64 >> 1);
    self->unk_f0.x = 0;
    self->unk_f0.y = 0x1000;
    self->unk_f0.z = -0x32666;
    self->unk_84.x = 0;
    self->unk_84.y = 0;
    self->unk_84.z = -0x12000;
    self->unk_fc = 0;
    self->unk_38->alpha = 0;
    self->unk_ea_10 = 1;
    self->unk_ea_6 = 1;
}

void func_ov011_022043cc(Ov011Act7c4c *self) {
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
        self->unk_fc = 20;
    }
}

}
