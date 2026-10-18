#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_0203f2b8(void *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern s32 func_02049afc(void *mgr, s32 id);

extern Ov009Vec data_ov009_02215f98[];
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern u16 FX_Atan2(s32 x, s32 z);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_0204a058(void *mgr, s32 a, s32 b, s32 c);

extern void *data_ov000_021ccd64;
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
extern void func_02049bb4(void *mgr, s32 id);
extern BOOL func_ov000_021b4738(Ov009Actor *a);

extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);

struct Ov009Rot {
    s16 x;
    s16 y;
    s16 z;
};

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_02206ae4(Ov009Actor *self) {
    Ov009Actor *a;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    self->unk_b6++;
    self->unk_93_4 = 1;
    if (self->unk_b6 <= 0xdc) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    self->unk_40->flags |= 0x4000;
    self->unk_b6 = 0;
}

void func_ov009_02206bb4(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        FLD(s32, self, 0x10c) = func_02049afc(data_02097e4c, 0x3f);
        self->unk_40->state++;
        break;
    case 1:
        st->timer++;
        if (st->timer >= 0x1e0) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        d.x = FLD(s32, self, 0xf0) - self->pos.x;
        d.y = FLD(s32, self, 0xf4) - self->pos.y;
        d.z = FLD(s32, self, 0xf8) - self->pos.z;
        VEC_MultAdd(0x3d, &d, &self->pos, &self->pos);
        break;
    }
}

void func_ov009_02206c84(Ov009Actor *self) {
    Ov009Vec t;
    Ov009Rot r;
    Ov009Actor *a;
    Ov009Actor *o;
    Ov009V *e;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        a = func_ov000_0219bf90();
        if (a != NULL) {
            self->unk_90 = a->id;
        }
        VEC_Add(&self->pos, &data_ov009_02215f98[FLD(u16, self, 0x108)], &t);
        r.y = FX_Atan2(t.x - a->pos.x, t.z - a->pos.z) + 0x7800;
        r.x = 0;
        r.z = 0;
        o = func_ov000_0219be1c(0x480b, &t, &r, self->id, self->unk_90);
        if (o == NULL) {
            return;
        }
        FLD(u16, o, 0x18) = 5;
        e = func_02065f88(0x325, &self->pos);
        e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        e->v20(&data_ov009_02215f98[FLD(u16, self, 0x108)]);
        self->unk_40->state++;
        break;
    case 1:
        st->timer++;
        if (st->timer <= 0x3c) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        func_0204a058(data_02097e4c, FLD(s32, self, 0x10c), 0x14, 0x1c2);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

void func_ov009_02206e30(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    Ov009V *e;
    Ov009Vec *v = &FLD(Ov009Vec, self, 0x9c);
    switch (self->unk_40->state) {
    case 0:
        v->x = 0;
        v->y = -0x48;
        v->z = 0x50;
        VEC_Add(&self->pos, v, &self->pos);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xf) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 1:
        d.x = 0 - v->x;
        d.y = -0x133 - v->y;
        d.z = 0x19a - v->z;
        VEC_MultAdd(0x66, &d, v, v);
        VEC_Add(&self->pos, v, &self->pos);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x104) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
    if (!(self->unk_40->timer & 0x3f)) {
        s32 a;
        s32 b;
        e = func_02065f88(0x325, &self->pos);
        e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        e->v14(0x1ccd, 0x1ccd, 0x1ccd);
        a = func_02040498(0x4000);
        b = func_02040498(0x4000);
        e->v24(-0x3800, a + 0x2800, -0x3000 - b);
    }
}

void func_ov009_0220703c(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec *t = &FLD(Ov009Vec, self, 0xfc);
    Ov009Actor *a;
    if (st->timer != 0) {
        st->timer--;
    }
    if (st->timer == 0) {
        self->unk_40->timer = 0x4b;
        *t = FLD(Ov009Vec, self, 0xf0);
        t->x += func_02040528(0x8cd);
        t->y += func_02040528(0x8cd);
        t->z += func_02040528(0x8cd);
    }
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
    if (FLD(s32, self, 0x10c) < 0) {
        return;
    }
    a = func_ov000_0219bf90();
    if (a != NULL && !func_ov000_021b4738(a)) {
        return;
    }
    func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
    FLD(s32, self, 0x10c) = -1;
}

void func_ov009_02207164(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Rot r;
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009V *e;
    u16 ang;
    t = func_ov000_0218d240(self);
    if (t == NULL) {
        return;
    }
    p = t->pos;
    if (p.z - self->pos.z < -0x14000) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    if (p.z > self->pos.z) {
        FLD(u16, self, 0x108) = 0;
        ang = func_02040498(0xc00) - 0x200;
    } else {
        FLD(u16, self, 0x108)++;
        if (FLD(u16, self, 0x108) >= 3) {
            FLD(u16, self, 0x108) = 1;
        }
        ang = -func_02040498(0xc00);
    }
    VEC_Add(&self->pos, &data_ov009_02215f98[FLD(u16, self, 0x108)], &p);
    r.y = ang + (FX_Atan2(p.x - t->pos.x, p.z - t->pos.z) + 0x8000);
    r.x = 0;
    r.z = 0;
    o = func_ov000_0219be1c(0x480b, &p, &r, self->id, self->unk_90);
    if (o != NULL) {
        FLD(u16, o, 0x18) = 5;
        e = func_02065f88(0x325, &self->pos);
        e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        e->v20(&data_ov009_02215f98[FLD(u16, self, 0x108)]);
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
