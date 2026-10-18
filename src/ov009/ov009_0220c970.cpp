#include "ov009/ov009.h"

extern "C" {

extern void func_0203f364(Ov009Sub48 *p);
extern void *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(void *p, s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

void func_ov009_0220c970(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *s48 = self->unk_48;
        Ov009Sub44 *s44;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        func_020639d4(func_02065f88(0x38a, &self->pos), 0x40, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        } else {
            func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        }
        break;
    }
    }
}

extern u8 data_ov009_02215f14[];
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

void func_ov009_0220ca64(Ov009Actor *self) {
    Ov009Vec t;
    Ov009Actor *a;
    Ov009Sub44 *s44;
    u32 saved;
    func_ov003_021d112c(self);
    self->unk_9c = 0x52;
    func_01ffc9fc(&t, data_ov009_02215f14, (u16)(func_02040528(0x1e) * 0xb6));
    VEC_Add(&self->pos, &t, &self->pos);
    a = func_ov000_0219bf90();
    {
        s32 x = a->pos.x;
        s32 z = a->pos.z;
        s32 y = self->pos.y;
        self->unk_b8.x = x;
        self->unk_b8.y = y;
        self->unk_b8.z = z;
    }
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_6 = 1;
    self->unk_48->unk_30 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
}

}
