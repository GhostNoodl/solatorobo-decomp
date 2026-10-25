#include "ov012/ov012.h"

extern "C" {
BOOL func_ov012_02201910(Ov012Actor *self, void *p, s32 a);
void func_ov012_02200200(Ov012Actor *self) {
    u32 f = FLD(u32, self, 0x100);
    if ((f & 0x200) || (f & 0x800) || (f & 0x400000)) {
        switch (self->unk_40->state) {
        case 0: {
            Ov012Sub48 *m;
            s32 x = 0x3000;
            if (FLD(u8, self, 0x106) == 1) {
                x = -0x3000;
            }
            Ov012_VecSet(&self->unk_b8, x, self->pos.y, 0);
            FLD(u8, self, 0x107) = 0;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[0], 0x111, 0);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->unk_48->unk_30 = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            if (func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
                if (FLD(u32, self, 0x100) & 0x200) {
                    FLD(u32, self, 0x100) ^= 0x200;
                }
                if (FLD(u32, self, 0x100) & 0x800) {
                    FLD(u32, self, 0x100) ^= 0x800;
                }
                if (FLD(u32, self, 0x100) & 0x400000) {
                    FLD(u32, self, 0x100) ^= 0x400000;
                }
                self->unk_40->state = 0;
            }
            break;
        }
    } else if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
}
}

extern "C" {
BOOL func_ov012_022016d8(Ov012Actor *self, s32 a);
extern char data_ov012_0220ab2d[];

void func_ov012_02200398(Ov012Actor *self) {
    Ov012Actor *pl = func_ov000_0218d240(self);
    Ov012Vec t;
    Ov012Vec v;
    s32 py = pl->pos.y;
    s32 pz = pl->pos.z;
    t = FLD(Ov012Vec, self, 0xf0);
    t.x = Ov012_FxMul(t.x, -0x1000);
    self->unk_ea_0 = 3;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.y = py;
        v.z = pz;
        v.x = 0;
        self->unk_b8 = v;
        func_02049f44(data_02097e4c, 0x601, &self->pos, 0);
        FLD(u8, self, 0x107) = 0;
        self->unk_40->state++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00 * 2)) {
            return;
        }
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        self->unk_40->state++;
        return;
    case 2:
        v = self->unk_b8;
        func_ov000_0218ddd4(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0 && !func_01ffc198(&pl->pos, &self->pos, pl->unk_64 + 0x2000)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab2d, 0x111, 0);
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        func_02049f44(data_02097e4c, 0x600, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 3: {
        Ov012Sub40 *s;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        s = self->unk_40;
        s->timer++;
        if (s->timer == 1) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            return;
        }
        if (s->timer == 0x1e) {
            Ov012V *e = func_02065f88(0x12f, &self->pos);
            e->v24(0, 0x800, 0);
            e->v14(0x800, 0x800, 0x800);
            return;
        }
        if (s->timer < 0x50) {
            return;
        }
        FLD(s32, self, 0x100) = 1;
        v.x = 0x3000;
        v.y = 0;
        v.z = 0;
        if (FLD(u8, self, 0x106) == 0) {
            v.x = -v.x;
        }
        v.y = self->pos.y;
        self->unk_b8 = v;
        FLD(u8, self, 0x107) = 0;
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        self->unk_94_1 = 1;
        self->unk_40->state++;
        return;
    }
    case 4:
        if (!func_ov012_02201910(self, &t, self->unk_b0->unk_00 * 2)) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {
extern char data_ov012_0220ab33[];

void func_ov012_022007a0(Ov012Actor *self) {
    Ov012Vec v;
    Ov012Vec w;
    func_ov000_0218d240(self);
    self->unk_ea_0 = 3;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.x = 0x2800;
        v.y = 0;
        v.z = 0x3800;
        if (FLD(u8, self, 0x106) == 1) {
            v.x = Ov012_FxMul(v.x, -0x1000);
        }
        if ((u8)func_02040498(1)) {
            v.z = Ov012_FxMul(v.z, -0x1000);
        }
        self->unk_b8 = v;
        FLD(u8, self, 0x107) = 0;
        self->unk_40->state++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00)) {
            return;
        }
        {
            Ov012Sub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        self->unk_40->state++;
        return;
    case 2:
        v = self->unk_b8;
        func_ov000_0218ddd4(self, &v, 0);
        w = v;
        w.z = Ov012_FxMul(w.z, -0x1000);
        func_ov000_0218d918(self, &w, 0x19a);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab33, 0x111, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    case 3: {
        u16 t;
        Ov012Sub40 *s = self->unk_40;
        s->timer++;
        t = s->timer;
        if (t > 0x69) {
            self->unk_94_1 = 1;
            if (t != 0x6e) {
                return;
            }
            {
                Ov012Sub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            self->unk_40->timer = 0;
            self->unk_40->state++;
            return;
        }
        if (t == 0x14) {
            Ov012V *e = func_02065f88(0x391, &self->pos);
            e->v24(0, 0x1000, 0);
            func_ov003_021da9ac(FLD(void *, self, 0x108), 0, e);
            func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        }
        if (t == 0x64) {
            Ov012V *e = func_02065f88(0x69, &self->pos);
            e->v24(0, 0x1000, 0);
            e->v0c(0xb33);
            func_02049f44(data_02097e4c, 0x601, &self->pos, 0);
        }
        w = self->unk_b8;
        w.z = Ov012_FxMul(w.z, -0x1000);
        func_ov000_0218d918(self, &w, 0x19a);
        return;
    }
    case 4:
        if (func_ov000_02191120(self->unk_38)) {
            FLD(s32, self, 0x100) = 1;
            v.x = 0x3000;
            v.y = 0;
            v.z = 0;
            if (FLD(u8, self, 0x106) == 1) {
                v.x = -v.x;
            }
            v.y = self->pos.y;
            self->unk_b8 = v;
            FLD(u8, self, 0x107) = 0;
            {
                Ov012Sub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            {
                Ov012Sub48 *m = self->unk_48;
                m->unk_9a_0 = 0;
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
            self->unk_40->state++;
        }
        self->unk_94_1 = 1;
        return;
    case 5:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00)) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}

extern "C" {
extern void *data_ov000_021ccd68;
extern u16 func_ov000_02199e94(void *p);
extern char data_ov012_0220ab1b[];
extern u8 func_ov000_02199f08(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, void *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
extern void func_ov000_0218d398(Ov012Actor *self, u16 id, s32 a, s32 b, s32 c, void *arg);
extern void *func_020658cc(void *a, s32 b);
extern void func_ov003_021d3d28(void *self);

struct Ov012HitArg {
    u16 a;
    u8 kind;
    u16 b;
};

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov012_Flash(s32 b) {
    u8 *g = (u8 *)data_ov000_021ccd54;
    u8 c = (b << 1) + 0x14 + b;
    FLD(Ov012Flags8, g, 0x190).b2 = 1;
    FLD(Ov012Flags8, g, 0x190).b3 = 1;
    FLD(Ov012Flags8, g, 0x190).b4 = 1;
    g[0x18d] = b * 2 + 6;
    g[0x18e] = c;
    g[0x18f] = c;
}

void func_ov012_02200cd4(Ov012Actor *self) {
    Ov012Vec t;
    Ov012Vec hv;
    Ov012Actor *pl;
    s32 k;
    Ov012Sub40 *s;

    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    k = pl->unk_40 != NULL ? pl->unk_40->unk_13 : 0;
    if (k == 0x11 || (FLD(u32, self, 0x100) & 0x400000)) {
        s = self->unk_40;
        switch (s->state) {
        case 0:
            self->unk_48->unk_30 = 0;
            FLD(u32, self, 0x100) |= 0x400000;
            break;
        case 1:
            s->timer = 0;
            break;
        }
        func_ov003_021d3d28(self);
        return;
    }
    if ((FLD(u32, self, 0x100) & 0x200) || (FLD(u32, self, 0x100) & 0x800)) {
        s = self->unk_40;
        switch (s->state) {
        case 0: {
            Ov012Sub44 *q = self->unk_44;
            Ov012Sub48 *m;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            self->unk_48->unk_30 = 0x40000000;
            m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
            if (self->unk_a8 == 0) {
                self->unk_a8 = 0x52;
            }
            self->unk_40->state++;
            break;
        }
        case 1:
            s->timer = 0;
            break;
        }
        func_ov003_021d3d28(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub48 *m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_48->unk_30 = 0;
        self->unk_40->state++;
    }
    case 1: {
        BOOL hit;
        u16 x;
        s32 j;
        Ov012Actor *g;
        Ov012Sub48 *m;
        Ov012Sub48 *gm;
        void *p;
        BOOL re;
        if (FLD(u32, self, 0x100) & 0x100) {
            Ov012Actor *o = (Ov012Actor *)Ov012_FindRes(0x5000, 0x5c02);
            if (o != NULL) {
                s32 d;
                u16 a;
                s32 dx = o->pos.x; dx = self->pos.x - dx;
                s64 sq = (s64)dx * dx;
                s32 dz = o->pos.z; dz = self->pos.z - dz;
                s32 oy = o->pos.y;
                sq += (s64)dz * dz;
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                d = Ov012_Sqrt2(sq);
                a = FX_Atan2(d, oy + 0x3000 - self->pos.y);
                self->unk_9c = Ov012_FxMul64d(OV012_SIN(a), 0x666);
                self->unk_a0 = Ov012_FxMul64d(OV012_COS(a), 0x666);
                FLD(u32, self, 0x100) ^= 0x100;
            }
        }
        g = NULL;
        if (FLD(void *, self, 0x4c) != NULL) {
            g = (Ov012Actor *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
        }
        if (g != NULL && FLD(u8, FLD(void *, self, 0x4c), 1) == 1) {
            m = self->unk_48;
            if ((m->unk_50 & 0x60000000) || FLD(u32, m, 0x58) != 0) {
                Ov012HitArg arg;
                u8 kind;
                hit = FALSE;
                if ((u32)self & 3) { hit = FALSE; }
                x = func_ov000_02199e94(FLD(void *, self, 0x4c));
                j = hit - 1;
                if (!(self->unk_48->unk_50 & 0x20000000)) {
                    Ov012V *e = func_02065f88(0x65, &self->pos);
                    e->v34(0x1800, (u16)(self->rot[1] + 0x8000), hit);
                    {
                        Ov012_Flash(FLD(u8, FLD(void *, self, 0x4c), 0x1a));
                    }
                    func_02049f44(data_02097e4c, 0x1a, &self->pos, hit);
                    self->unk_40->state = 10;
                }
                if (FLD(u8, FLD(void *, self, 0x4c), 3) == 1) {
                    s32 lim = self->unk_64 + 0xccd;
                    if (lim < 0x199a) {
                        lim = 0x199a;
                    }
                    hv.y = FLD(s32, self, 0x68) >> 1;
                    hv.x = 0;
                    hv.z = 0;
                    hit = func_ov000_0219aae8(self, g, x, FLD(u16, FLD(void *, self, 0x4c), 0xa), 0x20, &hv, NULL, lim, 0, j, 0x1000);
                }
                kind = 0x40;
                if (FLD(u8, FLD(void *, self, 0x4c), 0x19)) {
                    kind = func_ov000_02199f08(FLD(void *, self, 0x4c));
                    FLD(u32, self, 0x100) |= 0x100000;
                }
                arg.a = 0;
                arg.kind = kind;
                arg.b = 0xffff;
                if (hit && kind == 0x41) {
                    g = self;
                }
                if (g != NULL) {
                    func_ov000_0218d398(self, g->id, 9, 0, 6, &arg);
                }
                FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
            }
        }
        gm = NULL;
        func_ov000_0218dbe0(self, 0);
        m = self->unk_48;
        if (m == NULL) {
            return;
        }
        re = FALSE;
        p = FLD(void *, self, 0x4c);
        if (p != NULL && FLD(u16, p, 0x1c) != 0xffff && FLD(u8, p, 1) == 1) {
            Ov012Actor *g2;
            s32 v = self->unk_64 + 0x4cd;
            if (v < 0xccd) {
                v = 0xccd;
            }
            FLD(s32, m, 0x44) = v;
            g2 = (Ov012Actor *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (g2 != NULL && (gm = g2->unk_48) != NULL && gm->unk_9a_3) {
                gm->unk_9a_3 = 0;
                func_0203f364(gm);
                re = TRUE;
            }
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (re) {
            gm->unk_9a_3 = 1;
            func_0203f324(gm);
        }
        break;
    }
    case 10: {
        Ov012Sub44 *q;
        Ov012Sub48 *m;
        void *e;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00 * 2;
        self->unk_a0 = 0x333;
        self->unk_a8 = 0x52;
        self->unk_b8.x = 0;
        self->unk_b8.y = 0;
        self->unk_b8.z = 0xa000;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->unk_48;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        e = func_020658cc(data_0214a420, 0x321);
        if (e != NULL) {
            FLD(s32, e, 0x1c) = 4;
        }
        self->unk_40->state++;
        break;
    }
    case 11: {
        Ov012Sub48 *m;
        Ov012V *o;
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_ov000_02191418(self->unk_38, 0x1e, 0);
        }
        t = self->unk_b8;
        func_ov000_0218ddd4(self, &t, 0);
        func_ov000_0218d918(self, &t, 0x400);
        self->unk_48->unk_9a_5 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        o = func_02065f88(0x12f, &self->pos);
        o->v0c(0x800);
        func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
        t.x = 0x3000;
        t.y = 0;
        t.z = 0;
        if (FLD(u8, self, 0x106) == 1) {
            t.x = -t.x;
        }
        t.y = self->pos.y;
        self->unk_b8 = t;
        FLD(u8, self, 0x107) = 0;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[0], 0x111, 0);
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->unk_48;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
        self->unk_40->state++;
        break;
    }
    case 12:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
            return;
        }
        if (FLD(u32, self, 0x100) & 0x100000) {
            FLD(u32, self, 0x100) ^= 0x100000;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}
}
