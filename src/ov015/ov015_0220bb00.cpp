#include "ov015/ov015.h"

extern "C" {

extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
extern void *data_02097e4c;
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e68[];
void *func_02049a48(void *a, int b, int c, int d, int e);
u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e55[];
s32 FX_Div(s32 a, s32 b);
s32 FX_Sqrt(s32 a);
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);

BOOL Ov015FishState18_Exit(Ov015FishState18 *self) {
    Ov015V *o;
    u32 saved;
    o = func_020657b0(data_0214a420, self->unk_14);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    return TRUE;
}

static inline void Ov015_Spawn0bb68(Ov015FishState18 *self, s32 s1, s32 s2) {
    s32 m = 0;
    u8 *o;
    Ov015Vec a;
    Ov015Vec b;
    Ov015Fish *q;
    s32 y;
    o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, &self->unk_04->unk_40);
    FLD(s32, o, 0xd4) = 1;
    FLD(u8, o, 0x28) = 1;
    FLD(s32, o, 0x50) = -0xc8000;
    q = self->unk_04;
    a.x = q->unk_40.x;
    y = q->unk_40.y;
    if (y <= 0) m = y;
    a.y = m;
    a.z = q->unk_40.z;
    VCALL(o)->v18(&a);
    q = self->unk_04;
    {
        s32 k = q->unk_7c;
        b.x = Ov015_FxMul(q->unk_70, k);
        b.y = Ov015_FxMul(q->unk_74, k);
        b.z = Ov015_FxMul(q->unk_78, k);
    }
    VCALL(o)->v10(&b);
    func_02049a48(data_02097e4c, s1, -1, -1, -1);
    func_02049a48(data_02097e4c, s2, -1, -1, -1);
}
void func_ov015_0220bb68(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015VecC t(*(Ov015VecC *)&p->unk_40);
    s32 d = 0x4000 - t.y;
    if ((d < 0 ? -d : d) <= 0x19a) {
        t.y = 0x4000;
    } else {
        t.y += Ov015_FxMul(d, 0x29);
    }
    *(Ov015VecC *)&p->unk_40 = t;
    if (self->unk_0c == 0x50) {
        Ov015_Spawn0bb68(self, 0x19, 0x3e);
    } else if (self->unk_0c == 1) {
        Ov015_Spawn0bb68(self, 0x3e, 0x1b);
    }
}

void func_ov015_0220be38(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015Vec a;
    Ov015Vec c;
    Ov015Vec d;
    Ov015Vec b;
    Ov015V *e;
    Ov015Fish *q;
    s32 n;
    {
        Ov015VecC t(*(Ov015VecC *)&p->unk_40);
        s32 y = t.y;
        if ((y < 0 ? -y : y) >= 0x19a) {
            t.y = 0;
        } else {
            t.y = Ov015_FxMul(y, 0xfd7);
        }
        *(Ov015VecC *)&p->unk_40 = t;
    }
    q = self->unk_04;
    a.x = q->unk_40.x;
    a.y = q->unk_40.y > 0 ? 0 : q->unk_40.y;
    a.z = q->unk_40.z;
    e = func_020657b0(data_0214a420, self->unk_14);
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e55, 0, &self->unk_04->unk_40);
        FLD(s32, e, 0xd4) = 1;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0x3c) = 0x800;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        e->v34(0, 0x3fff, 0);
        self->unk_14 = FLD(void *, e, 0x24);
    }
    e->v18(&a);
    q = self->unk_04;
    {
        s32 k = q->unk_7c;
        b.x = Ov015_FxMul(q->unk_70, k);
        b.y = Ov015_FxMul(q->unk_74, k);
        b.z = Ov015_FxMul(q->unk_78, k);
    }
    e->v10(&b);
    n = self->unk_0c;
    if (n > 0x28) {
        s32 s = Ov015_FxMul(FX_Div((0x50 - n) << 12, 0x28000), -0x99a) + 0x1000;
        c.x = Ov015_FxMul(FLD(s32, e, 0x40), s);
        c.y = Ov015_FxMul(FLD(s32, e, 0x44), s);
        c.z = Ov015_FxMul(FLD(s32, e, 0x48), s);
        e->v10(&c);
    } else if (n < 10) {
        s32 s = FX_Sqrt(Ov015_FxMul(FX_Div((10 - n) << 12, 0xa000), 0x299a) + 0x666);
        d.x = Ov015_FxMul(FLD(s32, e, 0x40), s);
        d.y = Ov015_FxMul(FLD(s32, e, 0x44), s);
        d.z = Ov015_FxMul(FLD(s32, e, 0x48), s);
        e->v10(&d);
        if (self->unk_0c == 1) {
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        }
    }
}

void *Ov015FishState1c_Dtor(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState1c_DtorDelete(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL Ov015FishState1c_Enter(Ov015FishState1c *self, Ov015Fish *p) {
    self->unk_18 = p;
    self->unk_04 = 0;
    self->unk_08 = 0x1e;
    self->unk_0c = 0x4b0;
    self->unk_10 = 0;
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e0d, 0x19a, 0);
    p->unk_104 = 0x1000;
    func_ov000_021915a0(&p->unk_244);
    p->unk_bc = 4;
    p->unk_108 = 2;

    return TRUE;
}


BOOL func_ov015_0220c810(Ov015FishState1c *self);
void func_ov015_0220c6c8(Ov015FishState1c *self, Ov015Fish *p);
s32 func_02040498(s32 n);
void func_ov000_02191618(void *a);
void VEC_Normalize(void *src, void *dst);
extern u8 data_ov015_02212e74[];

BOOL Ov015FishState1c_Update(Ov015FishState1c *self, Ov015Fish *p) {
    BOOL ret = TRUE;
    s32 a;
    s32 off;
    s32 t;
    s32 v;
    self->unk_18 = p;
    if (self->unk_04 != 0 && self->unk_04 != 5 && !func_ov015_0220c810(self)) {
        self->unk_04 = 5;
        self->unk_08 = 0x5a;
        func_ov000_02190cb0(&p->unk_244, data_ov015_02212e74, 0x19a, 0);
        p->unk_104 = 0x800;
        func_ov000_02191618(&p->unk_244);
        p->unk_bc = 0;
    }
    switch (self->unk_04) {
    case 0: {
        Ov015VecC t(*(Ov015VecC *)&p->unk_40);
        t.y -= FX_Div(0x28000, 0x1e000);
        *(Ov015VecC *)&p->unk_40 = t;
        if (self->unk_08 == 0) {
            s32 s = func_02040498(1) ? 3 : 4;
            self->unk_04 = s;
            self->unk_14 = s == 3 ? p->unk_b0 : -p->unk_ac;
            self->unk_08 = 0x1e;
            p->unk_104 = 0x800;
            p->unk_bc = 4;
        }
        break;
    }
    case 1: {
        Ov015VecC t(*(Ov015VecC *)&p->unk_40);
        t.x -= Ov015_FxMul((self->unk_18)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
        *(Ov015VecC *)&p->unk_40 = t;
        if (t.x < self->unk_14) {
            self->unk_04 = 4;
            self->unk_08 = 0x1e;
        }
        break;
    }
    case 2: {
        Ov015VecC t(*(Ov015VecC *)&p->unk_40);
        t.x += Ov015_FxMul((self->unk_18)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
        *(Ov015VecC *)&p->unk_40 = t;
        if (t.x > self->unk_14) {
            self->unk_04 = 3;
            self->unk_08 = 0x1e;
        }
        break;
    }
    case 3: {
        off = 0;
        a = Ov015_FxMul((self->unk_18)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
        t = FX_Div((self->unk_08 - 0x1e) >> 1, 0xf);
        v = Ov015_FxMul(a >> 1, Ov015_FxMul(t, t));
        (self->unk_18)->unk_a8 = v;
        {
            Ov015VecC q(*(Ov015VecC *)&p->unk_40);
            q.x -= v;
            *(Ov015VecC *)&p->unk_40 = q;
        }
        {
            Ov015Vec d2 = p->unk_9c;
            if (d2.x > -0x1000) off = -0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, &p->unk_9c);
        }
        if (self->unk_08 == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->unk_08 <= 0) {
            s32 w;
            self->unk_04 = 1;
            w = p->unk_ac;
            if (w < 0) w = -w;
            self->unk_14 = -func_02040498(w);
        }
        break;
    }
    case 4: {
        off = 0;
        a = Ov015_FxMul((self->unk_18)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
        t = FX_Div((self->unk_08 - 0x1e) >> 1, 0xf);
        v = Ov015_FxMul(a >> 1, Ov015_FxMul(t, t));
        (self->unk_18)->unk_a8 = v;
        {
            Ov015VecC q(*(Ov015VecC *)&p->unk_40);
            q.x += v;
            *(Ov015VecC *)&p->unk_40 = q;
        }
        {
            Ov015Vec d2 = p->unk_9c;
            if (d2.x < 0x1000) off = 0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, &p->unk_9c);
        }
        if (self->unk_08 == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->unk_08 <= 0) {
            self->unk_04 = 2;
            self->unk_14 = func_02040498(p->unk_b0);
        }
        break;
    }
    case 5:
        func_ov015_0220c6c8(self, p);
        if (self->unk_08 == 0) ret = FALSE;
        break;
    }
    if (--self->unk_08 < 0) self->unk_08 = 0;
    return ret;
}

}
