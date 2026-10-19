#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220ae4c(Ov009Actor *self) {
    Ov009Sub44 *s44;
    func_ov003_021d112c(self);
    FLD(u16, self, 0xfc) = self->rot[1];
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    self->unk_b8 = self->pos;
    FLD(u16, self, 0xea) |= 0x1000;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    FLD(u16, self, 0xfe) = 0;
}


struct Ov009RotS {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_0203f364(Ov009Sub48 *p);
extern BOOL func_01ffc624(const Ov009Vec *a, const Ov009Vec *b, Ov009RotS *r, s32 c, s32 d);

void func_ov009_0220aeb8(Ov009Actor *self) {
    Ov009Vec v;
    Ov009RotS r;
    Ov009Actor *pl;
    Ov009Sub40 *s = self->unk_40;
    u8 st = s->unk_13;
    if (st != 0x15) {
        u32 f = self->unk_48->unk_50;
        if ((f & 0x20000000) && (!(f & 0x400) || st == 0x13) && FLD(u16, FLD(void *, self, 0x4c), 0x1c) == 0xffff) {
            s->flags |= 0x200000;
            func_02049f44(data_02097e4c, 0x6c, &self->pos, 0);
            return;
        }
    }
    {
        Ov009Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    if (!Ov009_GameIdle()) {
        return;
    }
    {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    v = self->unk_b8;
    switch (FLD(u16, self, 0xb4)) {
    case 0:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            FLD(u16, self, 0xb4)++;
        }
        break;
    case 1:
        if ((self->unk_48->unk_50 & 0x40000000) || func_01ffc198(&self->pos, &v, self->unk_64 + 0xc00)) {
            {
                s32 z = func_02040528(0x800) + 0x2400;
                v.x = 0;
                v.y = 0;
                v.z = z;
            }
            func_01ffc9fc(&v, &v, (u16)(FLD(u16, self, 0xfc) - 0x4000));
            VEC_Add(&v, &FLD(Ov009Vec, self, 0xf0), &v);
            self->unk_b8 = v;
            self->unk_b6 = func_02040498(0x1e) + 0x14;
            FLD(u16, self, 0xb4) = 10;
        } else {
            self->unk_40->flags |= 4;
        }
        break;
    case 10:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            FLD(u16, self, 0xb4)++;
        }
        break;
    case 11:
        if ((self->unk_48->unk_50 & 0x40000000) || func_01ffc198(&self->pos, &v, self->unk_64 + 0xc00)) {
            {
                s32 z = func_02040528(0x800) + 0x2400;
                v.x = 0;
                v.y = 0;
                v.z = z;
            }
            func_01ffc9fc(&v, &v, (u16)(FLD(u16, self, 0xfc) + 0x4000));
            VEC_Add(&v, &FLD(Ov009Vec, self, 0xf0), &v);
            self->unk_b8 = v;
            self->unk_b6 = func_02040498(0x1e) + 0x14;
            FLD(u16, self, 0xb4) = 0;
        } else {
            self->unk_40->flags |= 4;
        }
        break;
    }
    if ((u8)(self->unk_40->unk_13 + 0xff) > 1) {
        return;
    }
    {
        u16 ry = FLD(u16, self, 0xfc);
        r.x = 0x4000;
        r.y = ry;
        r.z = 0;
    }
    if (!func_01ffc624(&pl->pos, &self->pos, &r, pl->unk_64 + 0x1800, 0x6000)) {
        return;
    }
    self->unk_40->flags |= 0x8000;
}

}
