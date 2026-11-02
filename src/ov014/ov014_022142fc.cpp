#include "ov014/ov014.h"

struct Ov014Mtx33 {
    s32 m[9];
};

static inline s32 Ov014_FxMul64(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ov014_VecScale(Ov014Vec *v, s32 s) {
    v->x = FX_Mul(v->x, s);
    v->y = FX_Mul(v->y, s);
    v->z = FX_Mul(v->z, s);
}

static inline s32 Ov014_Approach(s32 cur, s32 target) {
    s32 d = target - cur;
    if ((d < 0 ? -d : d) > 0x29) {
        return cur + (s32)(((s64)d * 0x7b + 0x800) >> 12);
    }
    return cur;
}
extern "C" {

extern u8 data_ov014_02217fb0[];
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014Actor *Target_Get(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Obj *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);

#pragma force_active on
Ov014ActEx_022142fc *Ov014ActEx_022142fc_Ctor(Ov014ActEx_022142fc *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_02217fb0;
    self->unk_d0.x = 0;
    self->unk_d0.y = 0;
    self->unk_d0.z = 0;
    self->unk_dc = 0;
    self->unk_e0 = 0;
    return self;
}
#pragma force_active reset

void *Ov014ActEx_022142fc_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov014ActEx_022142fc_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_022142fc_Start(Ov014ActEx_022142fc *self) {
    Ov014Sub44 *n;
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->unk_44->unk_1c = 0x4000;
    self->unk_44->unk_10 = 0x4cd;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->unk_48->unk_4c = 0x28000;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void Ov014ActEx_022142fc_Draw(Ov014ActEx_022142fc *self) {
    func_ov000_02194c08(self);
}

BOOL func_ov014_022143f4(Ov014Obj *self) {
    Ov014Actor *list[0x20];
    BOOL r = FALSE;
    Ov014Actor *o;
    Ov014Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = Target_Get(self->unk_4c);
    p = func_ov000_0219bf90();
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->unk_64;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (p != NULL && FLD(u16, p, 0xb1e) == self->id) {
        rad >>= 1;
    }
    n = func_ov000_0219a510(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov014Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL && q->kind != self->kind) {
                Ov014Target *s = q->unk_4c;
                if (s == NULL || k != (u16)(s->target & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}

extern void *data_02097e4c;
extern char data_ov014_02218040[];
extern char data_ov014_0221804f[];
extern char data_ov014_0221805b[];
extern void *data_0214a420;
extern void *Actor_GetTarget(void *self);
extern void func_ov014_02214f10(Ov014Obj *self);
extern void *func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern void HitSphere_Link(Ov014Sub48 *p);
extern Ov014V *func_02066774(void *a, void *b, s32 c, Ov014Vec *d);
extern Ov014V *EffectGroup_Create(void *a, void *b, Ov014Vec *d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern Ov014V *func_020657b0(void *a, void *b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, Ov014Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov014_022144f8(Ov014ActEx_022142fc *self) {
    Ov014Mtx33 m;
    Ov014Vec q;
    Ov014Vec w;
    Ov014Mtx33 t;
    Ov014Vec v;
    Ov014Vec v2;
    Ov014Actor *o;
    Ov014Sub40 *st;
    o = Target_Get(self->unk_4c);
    Actor_GetTarget(self);
    if (o == NULL) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (o->kind == 0x1000) {
        func_ov014_02214f10(self);
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        Ov014_VecCopy(&self->unk_d0, &self->unk_84);
        self->unk_d0.x += Rand_PlusMinus(0x800);
        self->unk_d0.y += 0x14000;
        self->unk_d0.z += Rand_PlusMinus(0x800);
        ry = self->rot[1];
        rz = self->rot[2];
        rx = self->rot[0];
        set = FALSE;
        MTX_Identity33_((MtxFx33 *)&m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_((MtxFx33 *)&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_((MtxFx33 *)&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotZ33_((MtxFx33 *)&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        self->unk_a4 = 0x1000;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        MTX_MultVec33((Ov014Vec *)&self->unk_9c, (MtxFx33 *)&m, (Ov014Vec *)&self->unk_9c);
        self->unk_dc = 0x333;
        self->unk_9c = FX_Mul(self->unk_9c, self->unk_dc);
        self->unk_a0 = FX_Mul(self->unk_a0, self->unk_dc);
        self->unk_a4 = FX_Mul(self->unk_a4, self->unk_dc);
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0x14;
        break;
    }
    case 1:
        if (st->timer != 0) {
            FX_Div(st->timer << 12, 0x14000);
            VEC_Add((Ov014Vec *)&self->unk_9c, &self->pos, &self->pos);
            st = self->unk_40;
            if (st->timer != 0) {
                st->timer--;
            }
            break;
        }
        func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    case 10:
        if (self->pos.y < self->unk_d0.y) {
            s32 s = self->unk_dc;
            self->unk_a0 += Ov014_FxMul64(s, 0x19a);
            self->unk_dc = Ov014_Approach(s, 0x666);
            VEC_Normalize((Ov014Vec *)&self->unk_9c, (Ov014Vec *)&self->unk_9c);
            Ov014_VecScale((Ov014Vec *)&self->unk_9c, self->unk_dc);
            VEC_Add((Ov014Vec *)&self->unk_9c, &self->pos, &self->pos);
            break;
        }
        st->state = 0x14;
    case 0x14: {
        s32 x = self->unk_d0.x;
        s32 y = self->unk_d0.y;
        s32 z = self->unk_d0.z;
        Ov014V *e;
        Ov014Sub44 *q4;
        Ov014Sub48 *q8;
        self->pos.x = x;
        self->pos.y = y;
        self->pos.z = z;
        self->unk_9c = self->unk_84.x - x;
        self->unk_a0 = self->unk_84.y - y;
        self->unk_a4 = self->unk_84.z - z;
        self->unk_dc = 0;
        q4 = self->unk_44;
        q4->unk_22_0 = 1;
        q4->unk_22_1 = 1;
        q8 = self->unk_48;
        q8->unk_9a_0 = 1;
        q8->unk_9a_3 = 1;
        HitSphere_Link(q8);
        q.x = self->unk_84.x;
        q.y = self->unk_84.y;
        q.z = self->unk_84.z;
        q.y += 0xd9a;
        e = func_02066774(data_ov014_02218040, data_ov014_0221804f, 0, &q);
        e->v14(0x1ccd, 0xccd, 0x1ccd);
        FLD(s32, e, 0x3c) = 0x1400;
        self->unk_40->state++;
        break;
    }
    case 0x15: {
        s32 oldy;
        self->unk_dc = Ov014_Approach(self->unk_dc, 0x4cd);
        VEC_Normalize((Ov014Vec *)&self->unk_9c, (Ov014Vec *)&self->unk_9c);
        Ov014_VecScale((Ov014Vec *)&self->unk_9c, self->unk_dc);
        oldy = self->pos.y;
        VEC_Add((Ov014Vec *)&self->unk_9c, &self->pos, &self->pos);
        if (self->pos.y < 0xa000 && oldy >= 0xa000) {
            func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
            Ov014V *e = func_02065f88(0x4b0, &self->pos);
            e->v14(0x59a, 0x1333, 0x59a);
            e->v34(0x3fff, 0, 0);
            self->unk_e0 = FLD(s32, e, 0x24);
        }
        {
            Ov014V *e2 = func_020657b0(data_0214a420, ((void *)self->unk_e0));
            if (e2 != NULL) {
                e2->v18(&self->pos);
            }
        }
        if (self->unk_48->unk_50 & 0xe0000000) {
            self->unk_40->state = 0x1e;
            self->unk_40->timer = 0;
            break;
        }
        if (!func_ov014_022143f4(self)) {
            break;
        }
        {
            u16 mask;
            s32 r;
            Ov014Actor *a;
            r = self->unk_64 + 0xccd;
            v.y = self->unk_6c;
            v.x = 0;
            v.z = 0;
            mask = 0;
            a = Target_Get(self->unk_4c);
            if (a != NULL) {
                mask = ~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            func_ov000_0219aae8(self, a, self->unk_4c->unk_08, self->unk_4c->unk_0a, mask, &v, 0,
                                r, 0, 0x64, 0x1000);
        }
        self->unk_4c->target = 0xffff;
        {
            s32 sc = self->unk_64;
            Ov014V *f = EffectGroup_Create(data_ov014_02218040, data_ov014_0221805b, &self->pos);
            f->v14(sc, sc, sc);
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
    case 0x1e: {
        Ov014V *e;
        Ov014Sub44 *q4;
        self->unk_38->unk_c2_0 = 0;
        q4 = self->unk_44;
        q4->unk_22_0 = 0;
        q4->unk_22_1 = 0;
        w.x = self->pos.x;
        w.y = self->pos.y;
        w.z = self->pos.z;
        w.y = self->unk_48->unk_68.y;
        e = func_02066774(data_ov014_02218040, data_ov014_0221804f, 0, &w);
        e->v14(0x24cd, 0x299a, 0x24cd);
        func_02049f44(data_02097e4c, 0x56, &w, 0);
        func_ov000_0218996c(0xc, 0x19);
        self->unk_40->state++;
        self->unk_40->timer = 0x14;
    }
    case 0x1f:
        if (!(self->unk_40->timer & 3)) {
            u16 mask;
            Ov014Actor *a;
            a = Target_Get(self->unk_4c);
            mask = 0xffff;
            if (a != NULL) {
                mask &= (u16)~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            v2.y = self->unk_48->unk_68.y - self->pos.y;
            v2.x = 0;
            v2.z = 0;
            func_ov000_0219aae8(self, a, self->unk_4c->unk_08, self->unk_4c->unk_0a, mask, &v2, 0,
                                self->unk_64 + 0xccd, 0x3000, 0x64, 0x1000);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

extern Ov014Vec *func_ov000_0218d2e0(void *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014k_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02214f10(Ov014Obj *self) {
    Ov014Vec d;
    Ov014Vec v;
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        {
            Ov014Target *q = self->unk_4c;
            q->unk_50 = 0x1000;
            q->unk_54 = 0x29;
            q->unk_58 = 0;
        }
        self->unk_48->unk_30 = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot[1]));
            d.z = FX_Mul(r, OV014_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov014k_FxMul64(d.x, 0x39a);
            self->unk_a0 = Ov014k_FxMul64(d.y, 0x39a);
            self->unk_a4 = Ov014k_FxMul64(d.z, 0x39a);
        } else {
            self->unk_9c = OV014_SIN(self->rot[1]);
            self->unk_a4 = OV014_COS(self->rot[1]);
            self->unk_9c = Ov014k_FxMul64(self->unk_9c, 0x39a);
            self->unk_a0 = Ov014k_FxMul64(self->unk_a0, 0x39a);
            self->unk_a4 = Ov014k_FxMul64(self->unk_a4, 0x39a);
        }
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 1:
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        if (!(self->unk_48->unk_50 & 0xe0000000)) {
            if (!func_ov014_022143f4(self)) {
                break;
            }
        }
        {
            u16 mask;
            s32 r;
            Ov014Actor *a;
            r = self->unk_64 + 0xccd;
            v.y = self->unk_6c;
            v.x = 0;
            v.z = 0;
            mask = 0;
            a = Target_Get(self->unk_4c);
            if (a != NULL) {
                mask = ~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            func_ov000_0219aae8(self, a, self->unk_4c->unk_08, self->unk_4c->unk_0a, mask, &v, 0,
                                r, 0, 0x64, 0x1000);
        }
        self->unk_4c->target = 0xffff;
        {
            s32 sc = self->unk_64;
            Ov014V *f = EffectGroup_Create(data_ov014_02218040, data_ov014_0221805b, &self->pos);
            f->v14(sc, sc, sc);
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

}
