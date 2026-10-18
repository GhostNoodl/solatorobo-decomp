#include "ov011/ov011.h"

struct Ov011TwA {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 t;
    Ov011Vec from;
    Ov011Vec to;
    Ov011Vec cur;
};

struct Ov011TwB {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 dist;
    Ov011Vec cur;
    Ov011Vec to;
};

struct Ov011Mov {
    u8 active;
    u8 unk_01[0x3];
    s32 accel;
    Ov011Vec pos;
    Ov011Vec vel;
};

extern "C" {

extern u16 data_ov011_02207f00;
extern u8 data_ov011_022079d0[];
extern u8 data_ov011_022079b0[];
extern u8 data_ov011_02207418[];
extern u8 data_ov011_022074f8[];
s32 VEC_Distance(const Ov011Vec *a, const Ov011Vec *b);
s32 FX_Div(s32 a, s32 b);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);
s32 VEC_Mag(const Ov011Vec *v);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
void func_ov003_021d112c(void *p);
BOOL func_020621c4(void);
void func_ov003_021d6bac(void *p, void *data);

void func_ov011_02202a38(void) {
    data_ov011_02207f00 += 0x51e;
}

Ov011TwA *func_ov011_02202a54(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    self->b0 = 0;
    return self;
}

Ov011TwA *func_ov011_02202a70(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwA *func_ov011_02202a98(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    ((Ov011V *)self)->v08();
    func_0203de1c(self);
    return self;
}

BOOL func_ov011_02202ac8(Ov011TwA *self, const Ov011Vec *to, const Ov011Vec *from, s32 speed, u8 loop) {
    self->b0 = 1;
    self->b1 = loop;
    self->t = 0;
    self->from = *from;
    self->to = *to;
    self->cur = *from;
    self->speed = FX_Div(speed, VEC_Distance(to, from));
    return TRUE;
}

void func_ov011_02202b5c(Ov011TwA *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline void Ov011_Lerp(s32 t, const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out) {
    Ov011Vec d;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    VEC_MultAdd(t, &d, a, out);
}

void func_ov011_02202b74(Ov011TwA *self) {
    if (!self->b0) {
        return;
    }
    self->t += self->speed;
    if (!self->b1 && self->t >= 0x1000) {
        self->t = 0x1000;
        return;
    }
    Ov011_Lerp(self->t, &self->from, &self->to, &self->cur);
}

Ov011Vec *func_ov011_02202c10(Ov011TwA *self) {
    Ov011Vec *r = NULL;
    if (self->b0) {
        r = &self->cur;
    }
    return r;
}

BOOL func_ov011_02202c2c(Ov011TwA *self) {
    if (self->b0 && self->t >= 0x1000) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov011TwB_SetBoth(Ov011TwB *t, const Ov011Vec *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->cur.x = x;
    y = src->y;
    t->cur.y = y;
    z = src->z;
    t->cur.z = z;
    t->to.x = x;
    t->to.y = y;
    t->to.z = z;
}

Ov011TwB *func_ov011_02202c54(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &FLD(Ov011Vec, data_ov011_02207418, 0x20));
    return self;
}

Ov011TwB *func_ov011_02202cac(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwB *func_ov011_02202cd4(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    ((Ov011V *)self)->v08();
    func_0203de1c(self);
    return self;
}

BOOL func_ov011_02202d04(Ov011TwB *self, const Ov011Vec *to, const Ov011Vec *from, s16 speed) {
    self->b0 = 1;
    self->cur = *from;
    self->to = *to;
    self->speed = speed;
    self->dist = Ov011_FxMul(VEC_Distance(&self->to, &self->cur), 0x14);
    return TRUE;
}

void func_ov011_02202d88(Ov011TwB *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &FLD(Ov011Vec, data_ov011_02207418, 0x20));
}

void func_ov011_02202de0(Ov011TwB *self) {
    Ov011Vec d;
    s32 len;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        return;
    }
    d.x = self->to.x - self->cur.x;
    d.y = self->to.y - self->cur.y;
    d.z = self->to.z - self->cur.z;
    len = VEC_Mag(&d);
    if (len < 0) {
        len = -len;
    }
    if (len <= self->dist) {
        self->cur = self->to;
        self->b1 = 1;
    } else {
        VEC_MultAdd(self->speed, &d, &self->cur, &self->cur);
    }
}

Ov011Vec *func_ov011_02202ea4(Ov011TwB *self) {
    return self->b0 ? &self->cur : NULL;
}

u32 func_ov011_02202ebc(Ov011TwB *self) {
    return self->b1;
}

u32 func_ov011_02202ecc(Ov011TwB *self) {
    return self->b0;
}

void func_ov011_02202edc(Ov011Mov *self) {
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void func_ov011_02202f04(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

BOOL func_ov011_02202f38(Ov011Mov *self, const Ov011Vec *pos, const Ov011Vec *vel, s32 scale, s32 accel) {
    self->active = 1;
    self->pos = *pos;
    self->vel.x = Ov011_FxMul(vel->x, scale);
    self->vel.y = Ov011_FxMul(vel->y, scale);
    self->vel.z = Ov011_FxMul(vel->z, scale);
    self->accel = accel;
    return TRUE;
}

void func_ov011_02202fbc(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void func_ov011_02202ff0(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->vel.y += self->accel;
    VEC_Add(&self->pos, &self->vel, &self->pos);
}

Ov011Vec *func_ov011_02203028(Ov011Mov *self) {
    Ov011Vec *r = NULL;
    if (self->active) {
        r = &self->pos;
    }
    return r;
}

void func_ov011_02203040(void *self) {
    if (FLD(void *, self, 0x38) == NULL) {
        return;
    }
    func_ov000_02190a80(FLD(void *, self, 0x38), func_0203db40((u8 *)self + 0x24));
}

void func_ov011_0220306c(void *self) {
}

void func_ov011_02203070(void *self) {
}

void func_ov011_02203074(void *self) {
}

void func_ov011_02203078(void *self) {
}

void func_ov011_0220307c(void *self) {
}

void func_ov011_02203080(void *self) {
}

void func_ov011_02203084(void *self) {
}

void func_ov011_02203088(void *self) {
    func_ov003_021d112c(self);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov011_022074f8);
    }
}

}
