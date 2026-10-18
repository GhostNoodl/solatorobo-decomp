#include "ov012/ov012.h"

extern "C" {
void func_ov012_02201c70(Ov012Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}
}

extern "C" {
void func_ov012_02201c90(Ov012Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}
}

extern "C" {
void func_ov012_02201cb0(void) {
}
}

extern "C" {
void func_ov012_02201cb4(void) {
}
}

extern "C" {
void func_ov012_02201cb8(void) {
}
}

extern "C" {
void func_ov012_02201cbc(void) {
}
}

extern "C" {
void func_ov012_02201cc0(void) {
}
}

extern "C" {
void func_ov012_02201cc4(void) {
}
}

extern "C" {
void func_ov012_02201cc8(void) {
}
}

extern "C" {
void func_ov012_02201ccc(void) {
}
}

extern "C" {
void func_ov012_02201cd0(Ov012Actor *self) {
    self->v54();
}
}

extern "C" {
void func_ov012_02201ce4(Ov012Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}
}

extern "C" {
void func_ov012_02201d04(Ov012Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}
}

extern "C" {
void func_ov012_02201d28(Ov012Actor *self) {
    self->unk_ee_2 = 1;
    self->v64();
}
}

extern "C" {
void *func_ov012_02201d4c(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void *func_ov012_02201d68(void *self) {
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a54c[];
void func_ov012_02201d7c(Ov012Actor *self) {
    s16 t;
    void *p;
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov000_02194758(self);
    FLD(u8, self, 0xe2) = self->unk_18;
    FLD(s32, self, 0xbc) = 0;
    FLD(u16, self, 0xde) = 0;
    FLD(u8, self, 0xe3) = 1;
    FLD(u16, self, 0xdc) = 10;
    self->unk_1a = func_02040498(0x32) + 0x82;
    self->unk_1c = 0xb4;
    t = 0;
    if (FLD(u8, self, 0xe2)) {
        t = FLD(u8, self, 0xe2) - func_02040498(1);
    }
    self->unk_1e = t;
    p = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (p != NULL) {
        FLD(u16, self, 0xe0) = FLD(u16, p, 0xc);
    }
    func_02012be8(&self->pos, &data_ov012_0220a54c[FLD(u8, self, 0xe2)], &self->unk_84);
    {
        FLD(Ov012Vec, self, 0xd0) = self->unk_84;
    }
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}

extern "C" {
void func_ov012_02201ecc(Ov012Actor *self) {
    Ov012Actor *o;
    func_ov000_021953b4(self);
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    FLD(Ov012Flags8, self, 0xe3).b2 = 1;
    self->unk_90 = 0xffff;
    o = func_ov000_0219bf90();
    if (o != NULL) {
        self->unk_90 = o->id;
    }
    FLD(u16, FLD(void *, self, 0x4c), 0x1c) = FLD(u16, self, 0xe0);
    self->unk_40->flags |= 0x800;
}
}
