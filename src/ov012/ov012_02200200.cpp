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
