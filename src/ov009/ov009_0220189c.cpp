#include "ov009/ov009.h"

struct Ov009Rot {
    u16 x, y, z;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_02215d0c[];
extern s32 data_ov009_02215e14[];
extern Ov009Vec data_ov009_02215de4;
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *dst, const Ov009Vec *src, u16 angle);
extern void func_ov003_021da9ac(void *mgr, s32 id, void *obj);
extern void func_ov003_021daa6c(void *mgr, s32 id);
extern void func_ov003_021daae4(void *mgr, s32 id, const Ov009Vec *pos, const void *a, s32 b, const void *c, const void *d);
extern s32 func_02049afc(void *mgr, s32 id);
extern void func_02049bb4(void *mgr, s32 id);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *c);
extern void func_ov000_0218d918(Ov009Actor *self, Ov009Vec *v, s32 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);

static inline void Ov009_VSet(Ov009Vec *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
void func_ov009_0220189c(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Rot r;
    Ov009V *o;
    u16 tm;
    Ov009Actor *t;
    t = func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[0], 0x400, 0);
        FLD(u8, self, 0xf4) = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            func_02049f44(data_02097e4c, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            o = func_02065f88(0x25a, &self->pos);
            o->v30(self->rot);
            func_01ffc9fc(&v, &data_ov009_02215de4, self->rot[1]);
            o->v20(&v);
            o->v0c(0x1800);
            func_ov003_021da9ac(FLD(void *, self, 0x104), 0xff, o);
            FLD(s32, self, 0x108) = func_02049afc(data_02097e4c, 0x4c);
            self->unk_40->state++;
        }
        break;
    case 3: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        tm = st->timer;
        if (tm % 50 == 0 || tm == 1) {
            v.x = 0x3000;
            v.y = 0;
            v.z = 0x3000;
            FLD(u16, self, 0xf0) ^= 4;
            if (FLD(u16, self, 0xf0) & 4) {
                v.x = -v.x;
            }
            func_01ffc9fc(&v, &v, self->rot[1]);
            VEC_Add(&self->pos, &v, &self->unk_84);
        }
        func_ov000_0218d918(self, &self->unk_84, 0x52);
        func_ov003_021daae4(FLD(void *, self, 0x104), 0xff, &self->pos, self->rot, 0, &data_ov009_02215de4, self->rot);
        if (*func_ov000_0219bf90()->unk_50 != 0) {
            r.x = self->rot[0];
            r.y = self->rot[1];
            r.z = self->rot[2];
            r.x += 0x4000;
            func_ov000_0219aae8(self, self, FLD(u16, self, 0xf2), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, &data_ov009_02215de4, &r, 0x99a, 0x6000, 0x258, 0x2800);
        }
        if (t->unk_50 != NULL && *t->unk_50 == 0) {
            tm = 200;
        }
        if (!Ov009_GameIdle()) {
            tm = 200;
        }
        if (tm >= 200) {
            u8 i;
            func_ov003_021daa6c(FLD(void *, self, 0x104), 0xff);
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x108));
            FLD(s32, self, 0x108) = -1;
            func_ov000_02191690(self->unk_38);
            for (i = 0; i < 2; i++) {
                o = func_02065f88(0x25e, &self->pos);
                o->v34(0x8aaa, self->rot[1], 0);
                v.x = 0x1000;
                v.y = 0x4000;
                v.z = 0xb33;
                if (i == 1) {
                    v.x = -v.x;
                }
                func_01ffc9fc(&v, &v, self->rot[1]);
                o->v20(&v);
                func_ov003_021da9ac(FLD(void *, self, 0x104), 0xfe, o);
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 4: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer == 100) {
            func_ov003_021daa6c(FLD(void *, self, 0x104), 0xfe);
            func_ov000_02191708(self->unk_38);
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            o = func_02065f88(0x12f, &self->pos);
            o->v24(0, 0x2000, 0);
            o->v0c(0x99a);
            FLD(u8, self, 0xf4) = 0;
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
        } else if (st->timer == 300) {
            void *m = self->unk_38;
            FLD(s32, self, 0xf8) = FLD(s32, m, 0xa8);
            FLD(s32, self, 0xfc) = FLD(s32, m, 0xac);
            FLD(s32, self, 0x100) = FLD(s32, m, 0xb0);
            FLD(u8, self, 0xf4) = 1;
            o = func_02065f88(0x12f, &self->pos);
            o->v24(0, 0x2000, 0);
            o->v0c(0x99a);
            {
                s32 a = Ov009_FxMul(FLD(s32, self, 0xf8), 0x14cd);
                s32 b = FLD(s32, self, 0xfc);
                void *mm = self->unk_38;
                FLD(s32, mm, 0xa8) = a;
                FLD(s32, mm, 0xac) = b;
                FLD(s32, mm, 0xb0) = a;
            }
            func_02049f44(data_02097e4c, 0x72, &self->pos, 0);
            self->unk_40->state = 0x1e;
        }
        break;
    }
    case 0x1e: {
        s32 x = FLD(s32, self->unk_38, 0xa8);
        if (x > FLD(s32, self, 0xf8)) {
            x -= 0x19a;
            if (x <= FLD(s32, self, 0xf8)) {
                x = FLD(s32, self, 0xf8);
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            Ov009_VSet(&FLD(Ov009Vec, self->unk_38, 0xa8), x, FLD(s32, self, 0xfc), x);
        }
        break;
    }
    }
    if ((s32)self->unk_40->state >= 1) {
        self->unk_ea_0 = 3;
    }
}

extern Ov009Vec data_ov009_02215dd8;
extern Ov009Vec data_ov009_02215d78;
extern void *data_0214a420;
extern BOOL func_ov003_021daa0c(void *mgr, s32 id);
extern s32 func_ov003_021daa3c(void *mgr, s32 id);
extern Ov009V *func_020657b0(void *mgr, s32 h);
extern s32 FX_Div(s32 a, s32 b);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern s32 func_ov000_0219a510(Ov009Actor *self, u16 mask, Ov009Vec *pos, s32 r, s32 a, Ov009Actor **list);
extern Ov009Actor *func_ov000_021985c0(Ov009Actor *p);
extern Ov009Actor *func_ov000_02199ba0(void *p);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);

struct Ov009B24 {
    u32 b0 : 5;
    u32 b5 : 2;
    u32 b7 : 25;
};

void func_ov009_02201eac(Ov009Actor *self) {
    Ov009Actor *list[32];
    Ov009Vec v;
    Ov009Vec w;
    Ov009V *o;
    Ov009Sub38 *m;
    s32 i;
    s32 n;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[0], 0x400, 0);
        FLD(u8, self, 0xf4) = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        o = func_02065f88(0x5e2, &self->pos);
        o->v20(&data_ov009_02215dd8);
        func_ov003_021da9ac(FLD(void *, self, 0x104), 0xfc, o);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 2:
        if (func_ov003_021daa0c(FLD(void *, self, 0x104), 0xfc)) {
            return;
        }
        func_02049f44(data_02097e4c, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
        o = func_02065f88(0x321, &self->pos);
        o->v20(&data_ov009_02215d78);
        o->v0c(0x19a);
        FLD(s32, o, 0x7c) = FX_Div(0x10000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0x104), 0xfb, o);
        self->unk_40->state++;
        return;
    case 3: {
        s32 a;
        o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0x104), 0xfb));
        if (o == NULL) {
            return;
        }
        a = FLD(s32, o, 0x40);
        o->v0c(a + 0x666);
        if (a + 0x666 < 0x3333) {
            return;
        }
        FLD(s32, self, 0x108) = func_02049afc(data_02097e4c, 0x76);
        m = self->unk_38;
        FLD(u16, m, 0xb6) = 0x7c00;
        FLD(u16, m, 0xb8) = 0x7c00;
        FLD(u16, m, 0xba) = 0xc9;
        FLD(u16, m, 0xbc) = 0xc8;
        m = self->unk_38;
        m->unk_c2_9 = 2;
        NNSi_G3dModifyPolygonAttrMask(m->unk_04, 0, 0xc0);
        self->unk_40->state++;
        return;
    }
    case 4:
        if (*func_ov000_0219bf90()->unk_50 != 0 && Ov009_GameIdle()) {
            if (func_ov000_0219aae8(self, self, FLD(u16, self, 0xf2), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, &data_ov009_02215d78, NULL, 0x4ccd, 0, 0x322, 0xccd)) {
                v = func_ov000_0219bf90()->pos;
                func_02049f44(data_02097e4c, 0x77, &v, 0);
            }
        } else {
            self->unk_40->timer = 200;
            m = self->unk_38;
            FLD(u16, m, 0xb6) = 0x7c00;
            FLD(u16, m, 0xb8) = 0x7c00;
            FLD(u16, m, 0xba) = 2;
            FLD(u16, m, 0xbc) = 1;
        }
        {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 200) {
            func_ov003_021daa6c(FLD(void *, self, 0x104), 0xfb);
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x108));
            FLD(s32, self, 0x108) = -1;
            o = func_02065f88(0x69, &self->pos);
            o->v20(&data_ov009_02215d78);
            o->v0c(0x2000);
            func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            m = self->unk_38;
            m->unk_c2_9 = 3;
            NNSi_G3dModifyPolygonAttrMask(m->unk_04, 1, 0xc0);
            FLD(u8, self, 0xf4) = 0;
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        }
        VEC_Add(&self->pos, &data_ov009_02215d78, &w);
        n = func_ov000_0219a510(self, 0x10, &w, 0x4ccd, 0, list);
        if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov009Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                void *s = FLD(void *, q, 0x4c);
                if (s != NULL && (u8)(FLD(u8, s, 2) + 0xff) <= 1) {
                    Ov009Actor *b = func_ov000_02199ba0(s);
                    if (b != NULL && b->kind == 0x1000 && FLD(Ov009B24, func_ov000_0219bf90(), 0xb24).b5 == 0) {
                        func_ov000_0218d46c(q, q->id, 0x15);
                    }
                }
            }
        }
        }
        return;
    case 0x1e: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 300) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        return;
    }
    }
}

}
