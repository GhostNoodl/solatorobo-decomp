#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bf4c;
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);

struct Ov013Pair89 {
    u8 a;
    u8 b;
};

struct Ov013Sub50a {
    u8 unk_00[0x4];
    u16 unk_04;
    u8 unk_06[0x2];
    Ov013Pair89 unk_08;
};

static inline void Ov013_SetPair(Ov013Pair89 *d, const Ov013Pair89 *s, u8 b) {
    d->a = s->a;
    d->b = b;
}

void func_ov013_0220a38c(Ov013Actor *self) {
    Ov013Sub40 *q;
    if ((((Ov013Sub50a *)self->unk_50)->unk_04 >> 12) == 5) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    q = self->unk_40;
    if (q->state == 0) {
        Ov013Sub50a *p;
        FLD(Ov013Vec, self, 0xb8) = self->pos;
        p = (Ov013Sub50a *)self->unk_50;
        if ((u8)(p->unk_08.b + 0xf0) <= 1) {
            Ov013_SetPair(&p->unk_08, &p->unk_08, 0x20);
        }
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 4) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void func_ov013_0220a428(Ov013Actor *self) {
    self->v80();
}

Ov013Actor *func_ov013_0220a43c(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a458(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

void func_ov013_0220a46c(Ov013Actor *self) {
    self->v7c();
}

Ov013Actor *func_ov013_0220a480(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a494(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4b0(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a4c4(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4e0(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220bf4c;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    return self;
}

void func_ov013_0220a518(Ov013Actor *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_48->unk_60 = -0x800;
    self->unk_48->unk_48 = self->unk_64;
}

}
