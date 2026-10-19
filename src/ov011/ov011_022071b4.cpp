#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d0edc(void *self);

void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_02040528(s32 max);
s32 *NNS_G3dGlbGetInvV(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
extern const Ov011Vec data_02092a50;
extern void *data_02097e4c;
Ov011V *func_02065f88(s32 id, Ov011Vec *pos);
void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
void func_ov000_0218996c(s32 a, s32 b);
void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);
void *func_ov000_0219b71c(Ov011Vec *base, Ov011Vec *range, s32 min, s32 max, s32 kind, s32 chance);

static inline void Ov011_MulVec33b(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

struct Ov011RotB {
    u16 x, y, z;
};

void VEC_Normalize(const Ov011Vec *a, Ov011Vec *b);
u16 FX_Atan(s32 x);
u16 FX_Atan2(s32 y, s32 x);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_0204a028(void *a, s32 b, Ov011Vec *c, s32 d);
void func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);
void *func_ov000_0219be1c(s32 kind, Ov011Vec *pos, u16 *rot, u16 a, u16 b);
u16 func_01ffc128(u16 target, u16 cur, s32 a, s32 b, s32 c);
extern u8 data_ov011_02207658[];

struct Ov011Tbl63 {
    u8 b[6][3];
};

extern const Ov011Tbl63 data_ov011_0220752c;
extern u8 data_ov011_02207610[];
s32 func_02040498(s32 max);

void func_ov011_022063b0(Ov011Actor *self) {
    Ov011Vec v;
    Ov011Tbl63 tbl;
    Ov011Vec w;
    Ov011RotB r;
    Ov011Sub40 *s;
    tbl = data_ov011_0220752c;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        FLD(u16, self, 0xde) = 0xffff;
        FLD(u8, self, 0x36e) = 0;
        FLD(u8, self, 0x36f) = func_02040498(5);
        self->unk_40->state++;
    case 1: {
        Ov011V *e;
        Ov011Sub40 *s1 = self->unk_40;
        Ov011Vec *arr;
        u8 c;
        if (s1->timer != 0) {
            s1->timer--;
        }
        if (s1->timer != 0) {
            return;
        }
        {
            Ov011Vec *p;
            s32 y;
            c = tbl.b[FLD(u8, self, 0x36f)][FLD(u8, self, 0x36e)];
            Ov011_VecSet(&(&FLD(Ov011Vec, self, 0x370))[FLD(u8, self, 0x36e)], (c << 14) - 0x4000, func_02040528(0x1800) + 0x3000, -0xf000);
            p = &(&FLD(Ov011Vec, self, 0x370))[FLD(u8, self, 0x36e)];
            Ov011_MulVec33b(p, NNS_G3dGlbGetInvV(), &v);
        }
        VEC_Add(&v, &data_02092a50, &v);
        e = func_02065f88(0x389, &v);
        if (e != NULL) {
            e->v0c(0x3000);
            FLD(s32, e, 0x3c) = 0xccd;
        }
        e = func_02065f88(0x5e4, &v);
        if (e != NULL) {
            e->v0c(0x2000);
        }
        func_02049f44(data_02097e4c, 0x5b, &v, 0);
        if (++FLD(u8, self, 0x36e) >= 3) {
            FLD(u8, self, 0x36e) = 0;
            self->unk_40->state = 10;
            return;
        }
        self->unk_40->timer = ((u32)(u16)(self->unk_50[0] * 100 / self->unk_50[1]) >> 2) + 0x16;
        break;
    }
    case 10: {
        Ov011Vec *p;
        void *o;
        u16 h;
        if (FLD(u16, self, 0xde) != 0xffff) {
            return;
        }
        r = *(Ov011RotB *)self->rot;
        r.x += 0xa00;
        p = &(&FLD(Ov011Vec, self, 0x370))[FLD(u8, self, 0x36e)];
        Ov011_MulVec33b(p, NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &data_02092a50, &w);
        h = 0xffff;
        o = func_ov000_0219be1c(0x4838, &w, &r.x, self->id, self->unk_90);
        if (o != NULL) {
            FLD(void *, o, 0x60) = data_ov011_02207610;
            h = FLD(u16, o, 0xc);
        }
        FLD(u16, self, 0xde) = h;
        self->unk_40->timer = 3;
        self->unk_40->state++;
        break;
    }
    case 11:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 12: {
        Ov011Actor *o = (Ov011Actor *)Ov011_FindActor(FLD(u16, self, 0xde));
        if (o != NULL) {
            Ov011Sub40 *t;
            r = *(Ov011RotB *)o->rot;
            t = self->unk_40;
            t->timer++;
            r.x -= (u16)(t->timer * 5 + 0x10);
            *(Ov011RotB *)o->rot = r;
        } else {
            self->unk_40->timer = ((u32)(u16)(self->unk_50[0] * 100 / self->unk_50[1]) >> 4) + 1;
            self->unk_40->state++;
        }
        break;
    }
    case 13:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        FLD(u16, self, 0xde) = 0xffff;
        FLD(u8, self, 0x36e)++;
        if (FLD(u8, self, 0x36e) < 3) {
            self->unk_40->state = 10;
        } else {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov011_02206920(Ov011Actor *self) {
    Ov011Vec v;
    Ov011Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        Ov011V *e;
        Ov011_VecSet(&self->unk_84, 0, 0x3000, -0xf000);
        Ov011_MulVec33b(&self->unk_84, NNS_G3dGlbGetInvV(), &v);
        VEC_Add(&v, &data_02092a50, &v);
        e = func_02065f88(0x389, &v);
        if (e != NULL) {
            e->v0c(0x5000);
            FLD(s32, e, 0x3c) = 0xccd;
        }
        e = func_02065f88(0x5e4, &v);
        if (e != NULL) {
            e->v0c(0x3800);
        }
        e = func_02065f88(0x322, &v);
        if (e != NULL) {
            e->v0c(0x3000);
        }
        func_0204a028(data_02097e4c, 0x5b, &v, -2);
        self->unk_40->state++;
        self->unk_40->timer = 0x5a;
        break;
    }
    case 1: {
        Ov011Vec w;
        void *o;
        u16 h;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            break;
        }
        h = 0xffff;
        Ov011_MulVec33b(&self->unk_84, NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &data_02092a50, &w);
        o = func_ov000_0219be1c(0x4839, &w, self->rot, self->id, self->unk_90);
        if (o != NULL) {
            FLD(void *, o, 0x60) = data_ov011_02207658;
            h = FLD(u16, o, 0xc);
        }
        FLD(u16, self, 0xde) = h;
        FLD(Ov011Vec, self, 0x370) = self->unk_84;
        self->unk_40->state++;
        self->unk_40->timer = 0xf;
        break;
    }
    case 2:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_40->state++;
        }
        break;
    case 3: {
        Ov011Actor *o;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            u8 *pl;
            self->unk_40->timer = 0x28;
            pl = (u8 *)func_ov000_0219bf90();
            if (pl != NULL) {
                FLD(s32, self, 0x370) = FLD(s32, pl, 0xaf0);
                FLD(s32, self, 0x374) = FLD(s32, pl, 0xaf4);
                FLD(s32, self, 0x378) = FLD(s32, pl, 0xaf8);
            }
            Ov011_MulVec33b(&FLD(Ov011Vec, self, 0x370), NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            func_02049f44(data_02097e4c, 0x5c, &v, 0);
        }
        o = (Ov011Actor *)Ov011_FindActor(FLD(u16, self, 0xde));
        if (o != NULL) {
            Ov011RotB r;
            v.x = FLD(s32, self, 0x370);
            v.y = FLD(s32, self, 0x374);
            v.z = FLD(s32, self, 0x378);
            v.y += 0x4000;
            v.x -= self->unk_84.x;
            v.y -= self->unk_84.y;
            v.z -= self->unk_84.z;
            VEC_Normalize(&v, &v);
            r = *(Ov011RotB *)o->rot;
            r.x = func_01ffc128(FX_Atan(-v.y), r.x, 0x21, 1, 0x8000);
            r.y = func_01ffc128(FX_Atan2(v.x, v.z), r.y, 0x21, 1, 0x8000);
            *(Ov011RotB *)o->rot = r;
        } else {
            FLD(u16, self, 0xde) = 0xffff;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
}

void func_ov011_02206e18(Ov011Actor *self) {
    Ov011Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        Ov011Sub44 *p;
        void *o;
        Ov011V *e;
        *self->unk_50 = 0;
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        Ov011_VecSet((Ov011Vec *)&self->unk_9c, func_02040528(0x29), -0x71, func_02040528(0x29));
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4804, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4805, 0x15);
        o = Ov011_FindActor(FLD(u16, self, 0xde));
        if (o != NULL) {
            FLD(s16, o, 0x1a) = 1;
        }
        e = func_02065f88(0x69, &self->pos);
        e->v14(0x7800, 0x7800, 0x7800);
        self->unk_40->state++;
    }
    case 1: {
        u16 t = self->unk_40->timer;
        if (t > 0x78) {
            Ov011V *e;
            func_ov000_0218996c(0xf, 0x3c);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            e = func_02065f88(0x322, &self->pos);
            e->v14(0x5800, 0x5800, 0x5800);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((t & 0xf) == 0) {
            Ov011Vec w;
            Ov011Vec v;
            s32 kind = -1;
            s32 chance = 100;
            switch (t & 0x3f) {
            case 0:
                kind = 0x38a;
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
                func_ov000_0218996c(10, 0x14);
                break;
            case 0x10:
                kind = 0x38a;
                chance = 0x19;
                break;
            case 0x20:
                func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
                func_ov000_0218996c(10, 0x14);
                break;
            case 0x30:
                kind = 0x38a;
                chance = 0x32;
                break;
            }
            w.x = 0x3000;
            w.y = 0x2800;
            w.z = 0x1800;
            v.x = 0;
            v.y = 0x3000;
            v.z = -0xf000;
            Ov011_MulVec33b(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            func_ov000_0219b71c(&v, &w, 0x1000, 0x1c00, kind, chance);
        }
        self->unk_40->timer++;
        VEC_Add(&self->pos, (Ov011Vec *)&self->unk_9c, &self->pos);
        break;
    }
    case 2:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state = 0xffff;
        }
        break;
    }
}

#pragma force_active on
void func_ov011_022071b4(void **self) {
    ((void (*)(void *)) * (void **)((u8 *)*self + 0x7c))(self);
}

void *func_ov011_022071c8(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_022071dc(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov011_022071f8(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_0220720c(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov011_02207228(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_0220723c(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
#pragma force_active reset
}
