#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097cdc;
extern char data_ov013_0220b860[];
extern void *data_ov013_0220b7d0[];
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void *func_020657b0(void *a, s32 b);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_020359d0(void *a, s32 b, s32 c);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern void func_ov000_02194758(void *self);
extern Ov013Actor *func_ov000_0219bf90(void);

void func_ov013_021fd258(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_02065804(data_0214a420, FLD(s32, self, 0xf4));
    }
    if (self->unk_40->unk_0c[0] == 2) {
        func_ov003_021d6a3c(self, 1, 1, 1);
        return;
    }
    func_ov003_021d6054(self);
}

void func_ov013_021fd2b8(Ov013Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov013_021fd2d8(Ov013Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov013_021fd2f8(void) {
}

void func_ov013_021fd2fc(void) {
}

void func_ov013_021fd300(void) {
}

void func_ov013_021fd304(void) {
}

void func_ov013_021fd308(void) {
}

void func_ov013_021fd30c(void) {
}

void func_ov013_021fd310(void) {
}

void func_ov013_021fd314(void) {
}

void func_ov013_021fd318(Ov013Actor *self) {
    self->v54();
}

void func_ov013_021fd32c(Ov013Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov013_021fd34c(Ov013Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov013_021fd370(Ov013Actor *self) {
    self->unk_ee_2 = 1;
    self->v64();
}

Ov013Actor *func_ov013_021fd394(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_021fd3a8(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_021fd3c4(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_021fd3d8(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

static inline void Ov013_StopHtr(Ov013Actor *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void *p = func_020657b0(data_0214a420, FLD(s32, (u8 *)self + i * 4, 0xd0));
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
        }
    }
    if (func_02035b90(data_ov013_0220b860, 7)) {
        func_02036838(data_02097cdc, data_ov013_0220b860, 7, 0);
    }
}

Ov013Actor *func_ov013_021fd3f4(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    return self;
}

Ov013Actor *func_ov013_021fd488(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov013_021fd524(Ov013Actor *self) {
    func_ov000_0219433c(self);
    func_020359d0(data_ov013_0220b860, 7, 0);
}

BOOL func_ov013_021fd544(Ov013Actor *self) {
    BOOL r = func_ov000_021946f8(self);
    return (r & func_02035b90(data_ov013_0220b860, 7)) ? TRUE : FALSE;
}

void func_ov013_021fd570(Ov013Actor *self) {
    Ov013Actor *p;
    s32 i;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    for (i = 0; i < 2; i++) {
        FLD(s32, (u8 *)self + i * 4, 0xd0) = -1;
    }
    FLD(u16, self, 0xce) = 0x96;
    FLD(s32, self, 0xd8) = 0xccd;
    if (self->unk_9c == 0) {
        self->unk_9c = 0x19a;
    }
    if (self->unk_a0 == 0) {
        self->unk_a0 = -0xcd;
    }
}


extern void *data_ov000_021ccd68;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern const Ov013Vec data_ov013_0220aeb8;
extern char data_ov013_0220b86f[];
extern char data_ov013_0220b87b[];
extern void func_ov000_0219a210(Ov013Vec *v, const Ov013Vec *off, u16 rot);
extern Ov013V *func_02066774(const void *a, const void *b, s32 c, Ov013Vec *pos);
extern Ov013V *func_02066900(const void *a, const void *b, Ov013Vec *pos);
extern void func_020639d4(Ov013V *o, s32 a, s32 b);
extern BOOL func_ov000_021b4738(Ov013Actor *p);
extern void func_ov000_0218d918(Ov013Actor *self, Ov013Vec *p, s32 a);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void VEC_Normalize(const Ov013Vec *in, Ov013Vec *out);
extern void func_ov000_0219b808(u16 id, Ov013Vec *pos, void *box, s32 a, s32 b);

struct Ov013HitBox {
    Ov013Vec min;
    Ov013Vec max;
    u16 rot[3];
    u16 unk_1e;
    u32 unk_20;
    Ov013Vec v;
    s32 unk_30;
};

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013_SetAlpha(void *o, s32 v) {
    FLD(s32, o, 0x7c) = v < 0 ? 0 : v;
    FLD(s32, o, 0x7c) = v > 0x1000 ? 0x1000 : v;
}

void func_ov013_021fd5fc(Ov013Actor *self) {
    Ov013Vec pos;
    Ov013Vec pp;
    Ov013HitBox box;
    Ov013Actor *pl = Ov013_FindActor(self->unk_90);
    u8 i;
    if (pl == NULL) {
        return;
    }
    pos.x = self->pos.x;
    pos.y = self->pos.y;
    pos.z = self->pos.z;
    switch (self->unk_40->state) {
    case 0: {
        const char *f;
        Ov013V *o;
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        func_ov000_0219a210(&pos, &data_ov013_0220aeb8, self->rot[1]);
        f = data_ov013_0220b860;
        o = func_02066774(f, data_ov013_0220b86f, 0, &pos);
        FLD(s32, o, 0xc8) = -1;
        o->v0c(FLD(s32, self, 0xd8));
        func_020639d4(o, 0x3e, 6);
        FLD(s32, self, 0xd0) = FLD(s32, o, 0x24);
        o = func_02066900(f, data_ov013_0220b87b, &pos);
        FLD(s32, o, 0xc8) = -1;
        o->v0c(FLD(s32, self, 0xd8) >> 1);
        FLD(s32, self, 0xd4) = FLD(s32, o, 0x24);
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    }
    case 1: {
        Ov013Actor *p;
        FLD(s32, self, 0xd8) += 0x31;
        p = func_ov000_0219bf90();
        if (p == NULL || func_ov000_021b4738(p)) {
            FLD(u16, self, 0xce) = 1;
        }
        FLD(u16, self, 0xce)--;
        if (FLD(u16, self, 0xce) == 0) {
            FLD(u16, self, 0xce) = 0;
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    }
    case 2: {
        void *o = func_020657b0(data_0214a420, FLD(s32, self, 0xd0));
        s32 v = 0;
        if (o != NULL) {
            void *o2;
            v = FLD(s32, o, 0x7c);
            if (v > 0) {
                v -= 0x52;
            }
            if (v < 0) {
                v = 0;
            }
            Ov013_SetAlpha(o, v);
            o2 = func_020657b0(data_0214a420, FLD(s32, self, 0xd4));
            Ov013_SetAlpha(o2, v);
            if (FLD(void *, o2, 0xf0) != NULL) {
                Ov013_SetAlpha(FLD(void *, o2, 0xf0), v);
            }
        }
        if (v <= 0) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
    if (FLD(u16, self, 0xce) > 0x3c) {
        pp.x = pl->pos.x;
        pp.y = pl->pos.y;
        pp.z = pl->pos.z;
        func_ov000_0218d918(self, &pp, 0xcd);
        self->unk_98 = self->rot[1];
    }
    func_ov000_0218dbe0(self, 0);
    for (i = 0; i < 2; i++) {
        Ov013V *o = (Ov013V *)func_020657b0(data_0214a420, FLD(s32, (u8 *)self + i * 4, 0xd0));
        if (o != NULL) {
            if (i == 0) {
                o->v14(FLD(s32, self, 0xd8), Ov013_FxMul(FLD(s32, self, 0xd8), 0x1333), FLD(s32, self, 0xd8));
            } else {
                o->v0c(FLD(s32, self, 0xd8) >> 1);
            }
            o->v18(&self->pos);
        }
    }
    if (self->pos.y < 0) {
        self->pos.y = 0;
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 1 << (pl->id >> 12), NULL, NULL, Ov013_FxMul(FLD(s32, self, 0xd8), 0x800), 0x2000, 100, 0x1000);
    if (pl->unk_50[0] == 0) {
        return;
    }
    {
        s32 s;
        box.unk_1e = 2;
        box.unk_20 = 0x20000000;
        box.rot[0] = self->rot[0];
        box.rot[1] = self->rot[1];
        box.rot[2] = self->rot[2];
        s = FLD(s32, self, 0xd8) + 0x3800;
        box.min.x = -s;
        box.min.y = -0x800;
        box.min.z = -s;
        box.max.x = s;
        box.max.y = 0x800;
        box.max.z = s;
        {
            s32 px = pl->pos.x;
            s32 py = pl->pos.y;
            s32 pz = pl->pos.z;
            box.v.x = self->pos.x - px;
            box.v.y = self->pos.y - py;
            box.v.z = self->pos.z - pz;
        }
        box.v.y = 0;
        VEC_Normalize(&box.v, &box.v);
        box.v.x = Ov013_FxMul(box.v.x, 0xb8);
        box.v.y = Ov013_FxMul(box.v.y, 0xb8);
        box.v.z = Ov013_FxMul(box.v.z, 0xb8);
        box.unk_30 = -1;
        func_ov000_0219b808(self->id, &self->pos, &box, 0, 0);
    }
}
}
