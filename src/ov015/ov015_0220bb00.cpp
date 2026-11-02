#include "ov015/ov015.h"

extern "C" {

extern char data_ov015_02212e20[];
extern char data_ov015_02212e68[];
extern char data_ov015_02212e55[];
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212e0d[];
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);

BOOL Ov015FishState18_Exit(Ov015FishState18 *self) {
    EffectObj *o;
    void *saved;
    o = func_020657b0(data_0214a420, self->fxKey);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    return TRUE;
}

static inline void Ov015_Spawn0bb68(Ov015FishState18 *self, s32 s1, s32 s2) {
    s32 m = 0;
    EffectObj *o;
    Ov015Vec a;
    Ov015Vec b;
    Ov015Fish *q;
    s32 y;
    o = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e68, 0, &self->fish->pos);
    o->unk_d4 = 1;
    o->unk_28 = 1;
    o->unk_50 = -0xc8000;
    q = self->fish;
    a.x = q->pos.x;
    y = q->pos.y;
    if (y <= 0) m = y;
    a.y = m;
    a.z = q->pos.z;
    VCALL(o)->v18(&a);
    q = self->fish;
    {
        s32 k = q->scaleMul;
        b.x = FX_Mul(q->scale.x, k);
        b.y = FX_Mul(q->scale.y, k);
        b.z = FX_Mul(q->scale.z, k);
    }
    VCALL(o)->v10(&b);
    func_02049a48(data_02097e4c, s1, -1, -1, -1);
    func_02049a48(data_02097e4c, s2, -1, -1, -1);
}
void func_ov015_0220bb68(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015Vec t(*(Ov015Vec *)&p->pos);
    s32 d = 0x4000 - t.y;
    if ((d < 0 ? -d : d) <= 0x19a) {
        t.y = 0x4000;
    } else {
        t.y += FX_Mul(d, 0x29);
    }
    *(Ov015Vec *)&p->pos = t;
    if (self->timer == 0x50) {
        Ov015_Spawn0bb68(self, 0x19, 0x3e);
    } else if (self->timer == 1) {
        Ov015_Spawn0bb68(self, 0x3e, 0x1b);
    }
}

void func_ov015_0220be38(Ov015FishState18 *self, Ov015Fish *p) {
    Ov015Vec a;
    Ov015Vec c;
    Ov015Vec d;
    Ov015Vec b;
    EffectObj *e;
    Ov015Fish *q;
    s32 n;
    {
        Ov015Vec t(*(Ov015Vec *)&p->pos);
        s32 y = t.y;
        if ((y < 0 ? -y : y) >= 0x19a) {
            t.y = 0;
        } else {
            t.y = FX_Mul(y, 0xfd7);
        }
        *(Ov015Vec *)&p->pos = t;
    }
    q = self->fish;
    a.x = q->pos.x;
    a.y = q->pos.y > 0 ? 0 : q->pos.y;
    a.z = q->pos.z;
    e = func_020657b0(data_0214a420, self->fxKey);
    if (e == NULL) {
        e = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e55, 0, &self->fish->pos);
        e->unk_d4 = 1;
        e->unk_28 = 0;
        e->speed = 0x800;
        e->loopCount = -1;
        e->unk_50 = -0xc8000;
        e->SetRotXYZ(0, 0x3fff, 0);
        self->fxKey = e->id;
    }
    e->SetPos(&a);
    q = self->fish;
    {
        s32 k = q->scaleMul;
        b.x = FX_Mul(q->scale.x, k);
        b.y = FX_Mul(q->scale.y, k);
        b.z = FX_Mul(q->scale.z, k);
    }
    e->SetScale(&b);
    n = self->timer;
    if (n > 0x28) {
        s32 s = FX_Mul(FX_Div((0x50 - n) << 12, 0x28000), -0x99a) + 0x1000;
        c.x = FX_Mul(e->scale.x, s);
        c.y = FX_Mul(e->scale.y, s);
        c.z = FX_Mul(e->scale.z, s);
        e->SetScale(&c);
    } else if (n < 10) {
        s32 s = FX_Sqrt(FX_Mul(FX_Div((10 - n) << 12, 0xa000), 0x299a) + 0x666);
        d.x = FX_Mul(e->scale.x, s);
        d.y = FX_Mul(e->scale.y, s);
        d.z = FX_Mul(e->scale.z, s);
        e->SetScale(&d);
        if (self->timer == 1) {
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
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState1c_Enter(Ov015FishState1c *self, Ov015Fish *p) {
    self->fish = p;
    self->step = 0;
    self->timer = 0x1e;
    self->unk_0c = 0x4b0;
    self->unk_10 = 0;
    func_ov000_02190cb0(&p->model, data_ov015_02212e0d, 0x19a, 0);
    p->animSpeed = 0x1000;
    func_ov000_021915a0(&p->model);
    p->unk_bc = 4;
    p->drawMode = 2;

    return TRUE;
}


BOOL func_ov015_0220c810(Ov015FishState1c *self);
void func_ov015_0220c6c8(Ov015FishState1c *self, Ov015Fish *p);
s32 Rand_UpTo(s32 n);
void func_ov000_02191618(void *a);
extern u8 data_ov015_02212e74[];

BOOL Ov015FishState1c_Update(Ov015FishState1c *self, Ov015Fish *p) {
    BOOL ret = TRUE;
    s32 a;
    s32 off;
    s32 t;
    s32 v;
    self->fish = p;
    if (self->step != 0 && self->step != 5 && !func_ov015_0220c810(self)) {
        self->step = 5;
        self->timer = 0x5a;
        func_ov000_02190cb0(&p->model, data_ov015_02212e74, 0x19a, 0);
        p->animSpeed = 0x800;
        func_ov000_02191618(&p->model);
        p->unk_bc = 0;
    }
    switch (self->step) {
    case 0: {
        Ov015Vec t(*(Ov015Vec *)&p->pos);
        t.y -= FX_Div(0x28000, 0x1e000);
        *(Ov015Vec *)&p->pos = t;
        if (self->timer == 0) {
            s32 s = Rand_UpTo(1) ? 3 : 4;
            self->step = s;
            self->targetX = s == 3 ? p->maxX : -p->minX;
            self->timer = 0x1e;
            p->animSpeed = 0x800;
            p->unk_bc = 4;
        }
        break;
    }
    case 1: {
        Ov015Vec t(*(Ov015Vec *)&p->pos);
        t.x -= FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
        *(Ov015Vec *)&p->pos = t;
        if (t.x < self->targetX) {
            self->step = 4;
            self->timer = 0x1e;
        }
        break;
    }
    case 2: {
        Ov015Vec t(*(Ov015Vec *)&p->pos);
        t.x += FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
        *(Ov015Vec *)&p->pos = t;
        if (t.x > self->targetX) {
            self->step = 3;
            self->timer = 0x1e;
        }
        break;
    }
    case 3: {
        off = 0;
        a = FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
        t = FX_Div((self->timer - 0x1e) >> 1, 0xf);
        v = FX_Mul(a >> 1, FX_Mul(t, t));
        (self->fish)->unk_a8 = v;
        {
            Ov015Vec q(*(Ov015Vec *)&p->pos);
            q.x -= v;
            *(Ov015Vec *)&p->pos = q;
        }
        {
            Ov015Vec d2 = p->dir;
            if (d2.x > -0x1000) off = -0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, (&p->dir));
        }
        if (self->timer == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->timer <= 0) {
            s32 w;
            self->step = 1;
            w = p->minX;
            if (w < 0) w = -w;
            self->targetX = -Rand_UpTo(w);
        }
        break;
    }
    case 4: {
        off = 0;
        a = FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
        t = FX_Div((self->timer - 0x1e) >> 1, 0xf);
        v = FX_Mul(a >> 1, FX_Mul(t, t));
        (self->fish)->unk_a8 = v;
        {
            Ov015Vec q(*(Ov015Vec *)&p->pos);
            q.x += v;
            *(Ov015Vec *)&p->pos = q;
        }
        {
            Ov015Vec d2 = p->dir;
            if (d2.x < 0x1000) off = 0xcd;
            d2.z = -0x1000;
            d2.x += off;
            VEC_Normalize(&d2, (&p->dir));
        }
        if (self->timer == 0xf) {
            func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        }
        if (self->timer <= 0) {
            self->step = 2;
            self->targetX = Rand_UpTo(p->maxX);
        }
        break;
    }
    case 5:
        func_ov015_0220c6c8(self, p);
        if (self->timer == 0) ret = FALSE;
        break;
    }
    if (--self->timer < 0) self->timer = 0;
    return ret;
}

}
