#include "ov009/ov009.h"

extern "C" {

extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);

void func_ov009_0220b48c(Ov009Actor *self) {
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    FLD(u16, self, 0xea) |= 0x1000;
    if (self->unk_48->unk_54 & 0x400) {
        return;
    }
    func_ov003_021d6a3c(self, 1, 1, 0);
}

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_01ffc198(const Ov009Vec *a, const Ov009Vec *b, s32 r);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
void func_ov009_0220b4e4(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub48 *s48;
    Ov009Actor *t;
    BOOL in;
    if (st->unk_13 != 0x15 && (self->unk_48->unk_50 & 0x20000000) && !(self->unk_48->unk_50 & 0x400) &&
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) == 0xffff) {
        st->flags |= 0x200000;
        func_02049f44(data_02097e4c, 0x6c, &self->pos, 0);
        return;
    }
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    if (!Ov009_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    t = func_ov000_0219bf90();
    if (t != NULL) {
        self->unk_90 = t->id;
    }
    in = FALSE;
    if (t != NULL && t->unk_48 != NULL && (t->unk_48->unk_54 & 0x400)) {
        in = TRUE;
    }
    if (in) {
        Ov009Vec v;
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        self->unk_b8 = v;
        if (!func_01ffc198(&self->pos, &v, self->unk_64 + 0x1800)) {
            self->unk_40->flags |= 4;
            return;
        }
        self->unk_40->flags |= 0x8000;
        return;
    }
    {
        Ov009Vec p;
        p.x = FLD(Ov009Vec, self, 0xf0).x;
        p.y = FLD(Ov009Vec, self, 0xf0).y;
        p.z = FLD(Ov009Vec, self, 0xf0).z;
        p.y -= 0xa000;
        if (func_01ffc584(&self->pos, &p, self->unk_64 + 0x1000, 0x14000)) {
            return;
        }
    }
    self->unk_b8 = FLD(Ov009Vec, self, 0xf0);
    self->unk_40->flags |= 4;
}

}
