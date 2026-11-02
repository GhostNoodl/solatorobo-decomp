#include "ov012/ov012.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name and
// offsets. The pointer to the name and the two offsets are read by the functions of
// 0x02201c70..0x02202994 (ov012_02201c70.cpp, merged in round dtD in its own namespace).
extern const char *const data_ov012_0220a510;
extern const VecFx32 data_ov012_0220a51c;
extern const VecFx32 data_ov012_0220a528;
extern char data_ov012_0220aef6[];
const char *const data_ov012_0220a510 = data_ov012_0220aef6;
static const VecFx16 data_ov012_0220a514 = {0, 0, 0};
const VecFx32 data_ov012_0220a51c = {0, 0, 4 * FX32_ONE};
const VecFx32 data_ov012_0220a528 = {0, -2 * FX32_ONE, 4 * FX32_ONE};
static const VecFx32 data_ov012_0220a534 = {0, 0, 0};
static const VecFx16 data_ov012_0220aef0 = data_ov012_0220a514;
char data_ov012_0220aef6[] = "nut00";
static const VecFx32 data_ov012_0220aefc = data_ov012_0220a534;

// ---- merged from ov012_02201c70.cpp
namespace m_02201c70 {
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
void *Ov012Act_021fee1c_DtorDelete(void *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void *Ov012Act_021fee1c_Dtor(void *self) {
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a54c[];
void Ov012ActExVt_0220af10_Start(Ov012ActExVt_0220af10 *self) {
    s16 t;
    void *p;
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov000_02194758(self);
    self->unk_e2 = self->unk_18;
    self->unk_bc = NULL;
    self->unk_de = 0;
    self->unk_e3 = 1;
    self->unk_dc = 10;
    self->unk_1a = Rand_UpTo(0x32) + 0x82;
    self->unk_1c = 0xb4;
    t = 0;
    if (self->unk_e2) {
        t = self->unk_e2 - Rand_UpTo(1);
    }
    self->unk_1e = t;
    p = Target_Get(self->unk_4c);
    if (p != NULL) {
        self->unk_e0 = FLD(u16, p, 0xc);
    }
    VEC_Add(&self->pos, &data_ov012_0220a54c[self->unk_e2], &self->unk_84);
    {
        self->unk_d0 = self->unk_84;
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
void Ov012ActExVt_0220af10_Update(Ov012ActExVt_0220af10 *self) {
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
    o = (Ov012Actor *)func_ov000_0219bf90();
    if (o != NULL) {
        self->unk_90 = o->id;
    }
    self->unk_4c->target = self->unk_e0;
    self->unk_40->flags |= 0x800;
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a540;
s32 Rand_Fx(void);
void func_ov000_02196060(Ov012ActorEx *self);
void Actor_PitchToPos(void *self, Ov012Vec *v, s32 a);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);

#define OV012_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

static inline void Ov012_MoveTo(Ov012ActExVt_0220af10 *self, const Ov012Vec *t, s32 k) {
    Ov012Vec d;
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

static inline void Ov012_FxMid(Ov012ActExVt_0220af10 *self) {
    Ov012Vec v;
    v.x = self->pos.x;
    v.y = self->pos.y;
    v.z = self->pos.z;
    v.y = v.y + (self->unk_68 >> 1);
    Ov012V *e = func_02065f88(1, &v);
    e->v0c(self->unk_64 + (self->unk_64 >> 2));
}

void func_ov012_02201f48(Ov012ActExVt_0220af10 *self) {
    Ov012Actor *o;
    Ov012Vec w;
    Ov012Vec tp;
    s32 dist;
    Ov012Sub40 *s;
    o = (Ov012Actor *)Target_Get(self->unk_4c);
    if (o == NULL) {
        return;
    }
    if (o->kind == 0x1000) {
        void *p = self->unk_4c;
        FLD(s32, p, 0x50) = 0x1000;
        FLD(s32, p, 0x54) = 0x29;
        FLD(s32, p, 0x58) = 0;
        self->unk_48->unk_30 = 0;
        func_ov000_02196060(self);
        return;
    }
    tp = Actor_GetTarget(self)->pos;
    dist = VEC_Distance(&self->pos, &tp);
    s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a510, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        if (self->unk_e3 & 4) {
            self->unk_e3 ^= 4;
            self->unk_48->unk_30 = 0;
            self->unk_1c = 0xb4;
            self->unk_40->timer = 0xb4;
            self->unk_40->state = 6;
            return;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1: {
        u16 t;
        Ov012_MoveTo(self, &self->unk_84, 0x19a);
        {
            Ov012Sub40 *q = self->unk_40;
            q->timer++;
            t = q->timer;
        }
        if (t == 5) {
            Ov012V *e = func_02065f88(0x68, &self->pos);
            e->v34(0x3fff, 0, 0);
            e->v0c(0xccd);
        }
        if (t >= 0x28) {
            self->unk_40->state++;
        }
        break;
    }
    case 2: {
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_40->timer = 0x1e;
            self->unk_d0 = self->unk_84;
            self->unk_d0.x += Rand_Fx();
            self->unk_d0.y += Rand_Fx();
            self->unk_d0.z += Rand_Fx();
        }
        Ov012_MoveTo(self, &(self->unk_d0), 0xa4);
        if (self->unk_e3 & 2) {
            s16 b = self->unk_1e;
            s16 a = self->unk_1a;
            u16 c = self->unk_de++;
            u16 d = self->unk_dc;
            if (c == d + a * b) {
                Ov012Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                self->unk_40->state = 4;
            }
            {
                Ov012Vec v2 = data_ov012_0220a51c;
                func_01ffc9fc(&v2, &v2, self->rot[1]);
                VEC_Add(&self->pos, &v2, &v2);
                Actor_PitchToPos(self, &v2, 0x11f);
            }
        }
        if (self->unk_e3 & 2) {
            return;
        }
        {
            s16 b = self->unk_1e;
            s16 a = self->unk_1a;
            u16 c = self->unk_de++;
            u16 d = self->unk_dc;
            if (c != d + a * b) {
                return;
            }
        }
        self->unk_e3 |= 2;
        {
            const Ov012Vec *b = &data_ov012_0220a54c[self->unk_e2];
            self->unk_84.x = self->unk_84.x - b->x;
            self->unk_84.y = self->unk_84.y - b->y;
            self->unk_84.z = self->unk_84.z - b->z;
            Ov012Vec r2 = {Rand_PlusMinus(0x4000), Rand_PlusMinus(0x800), Rand_PlusMinus(0x4000)};
            VEC_Add(&r2, &data_ov012_0220a540, &r2);
            VEC_Add(&self->unk_84, &r2, &self->unk_84);
        }
        FLD(u16, self->unk_48, 0x9a) |= 0x12;
        func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        self->unk_40->state++;
        break;
    }
    case 3: {
        s32 k;
        w.x = self->unk_84.x - self->pos.x;
        w.y = self->unk_84.y - self->pos.y;
        w.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&w, &w);
        w.x = OV012_FXMUL_K(w.x, 0x4cd);
        w.y = OV012_FXMUL_K(w.y, 0x4cd);
        w.z = OV012_FXMUL_K(w.z, 0x4cd);
        k = OV012_FXMUL_K(OV012_SINCOS[0x4e], 0xccd);
        if (self->unk_e2 % 2 == 0) {
            w.x = w.x - k;
        } else {
            w.x = w.x + k;
        }
        w.y = w.y + k;
        VEC_Add(&self->pos, &w, &self->pos);
        Actor_TurnToPos(self, &self->unk_84, 0x11f);
        if (VEC_Distance(&self->pos, &self->unk_84) < 0x800) {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)m);
            self->unk_dc = 0x28;
            self->unk_40->timer = 0;
            self->unk_40->state = 2;
        }
        {
            Ov012Vec v3 = data_ov012_0220a528;
            func_01ffc9fc(&v3, &v3, self->rot[1]);
            VEC_Add(&self->pos, &v3, &v3);
            Actor_PitchToPos(self, &v3, 0x11f);
        }
        break;
    }
    case 4: {
        Ov012_MoveTo(self, &tp, 0x3d);
        if (dist < 0x5000) {
            self->unk_40->state++;
        }
        break;
    }
    case 5: {
        w.x = self->pos.x;
        w.y = self->pos.y;
        w.z = self->pos.z;
        w.y = -0x1000;
        Ov012_MoveTo(self, &w, 0x66);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        w.y = 0x333;
        if (VEC_Distance(&self->pos, &w) >= 0xcd) {
            return;
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 6:
        if (dist >= 0x3000) {
            s->timer++;
            if (s->timer < 0xaa) {
                return;
            }
        }
        self->unk_40->timer = 0xb4;
        func_02065f88(4, &self->pos);
        func_02049f44(data_02097e4c, 0x78, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 7: {
        u16 t;
        if (s->timer != 0) {
            s->timer--;
        }
        t = s->timer;
        if (t <= 0x38) {
            self->unk_94_1 = 1;
        }
        if (t <= self->unk_1c) {
            Ov012Sub38 *g = self->unk_38;
            g->unk_b6 = 0x14bf;
            g->unk_b8 = 0x14bf;
            g->unk_ba = 9;
            g->unk_bc = 8;
            self->unk_1c = (self->unk_1c >> 3) * 7;
        }
        if (t == 0x38) {
            Ov012V *e = func_02065f88(0x196, &self->pos);
            e->v0c(0x800);
            e->v24(0, 0x800, 0);
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        if (t == 0) {
            self->unk_40->state++;
        }
        break;
    }
    case 8: {
        func_ov000_0218996c(10, 0x14);
        func_02065f88(5, &self->pos)->v0c(0x4000);
        func_02065f88(0x6d, &self->pos)->v0c(0x2000);
        Ov012_FxMid(self);
        func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    case 9: {
        void *p = self->unk_4c;
        BOOL r = func_ov000_0219aae8(self, self, FLD(u16, p, 8), FLD(u16, p, 0xa), 2, NULL, 0, 0x4000, 0, 100, 0x1000);
        self->unk_38->unk_be = 0;
        {
            Ov012Sub40 *q = self->unk_40;
            q->timer++;
            if ((s32)q->timer < 0x14 && r == 0) {
                return;
            }
        }
        self->unk_4c->target = 0xffff;
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
        break;
    }
    }
}
}
}  // namespace m_02201c70
