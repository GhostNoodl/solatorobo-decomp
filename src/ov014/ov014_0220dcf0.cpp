#include "ov014/ov014.h"

static inline void Ov014_VecSub(Ov014Vec *d, const Ov014Vec *a, const Ov014Vec *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

struct Ov014Mtx33 {
    s32 m[9];
};

extern "C" {

extern void *data_0214a420;
extern u8 data_ov014_02217b44[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_02065804(void *a, void *b);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191618(void *p);

void func_ov014_0220dcf0(void) {
}

#pragma force_active on
Ov014Actor *func_ov014_0220dcf4(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217b44;
    FLD(void *, self, 0xd0) = NULL;
    FLD(u8, self, 0xd4) = 0;
    FLD(s16, self, 0xd6) = 0;
    FLD(s16, self, 0xd8) = 0;
    FLD(s16, self, 0xda) = 0;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_0220dd2c(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217b44;
    func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_0220dd64(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217b44;
    func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220dda4(Ov014Actor *self) {
    func_ov000_02194c08(self);
}

void func_ov014_0220ddb0(Ov014Actor *self) {
    Ov014Sub44 *n;
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    func_ov000_02198360(self->unk_40, 1, 0);
    func_ov000_02191690(self->unk_38);
    func_ov000_02191618(self->unk_38);
    FLD(u8, self, 0xd4) = self->unk_18 != 0 ? 1 : 0;
}

extern void *data_02097e4c;
extern void MTX_Identity33_(Ov014Mtx33 *m);
extern void MTX_RotX33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov014Mtx33 *a, Ov014Mtx33 *b, Ov014Mtx33 *out);
extern void MTX_MultVec33(Ov014Vec *v, Ov014Mtx33 *m, Ov014Vec *out);
extern u8 *func_ov014_0220f7f0(s32 k, Ov014Vec *pos);
extern void func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern Ov014V *func_020657b0(void *a, void *b);
extern s32 func_02049130(s32 a, s32 b, s32 c);
extern s32 FX_Div(s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern s32 VEC_Mag(const Ov014Vec *v);
extern void VEC_Normalize(const Ov014Vec *in, Ov014Vec *out);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_02040578(u16 *ang, const Ov014Vec *v);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_02065860(void *a, void *b);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, Ov014Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov000_02191708(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_0203f324(Ov014Sub48 *p);

void func_ov014_0220de34(Ov014Actor *self) {
    Ov014Sub40 *st = self->unk_40;
    Ov014Mtx33 m;
    Ov014Vec dir;
    Ov014Vec to;
    Ov014Vec n;
    Ov014Vec p;
    Ov014Mtx33 t;
    Ov014Vec v;
    u16 ang[4];
    switch (st->state) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        ry = self->rot[1];
        set = FALSE;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0x1000;
        rz = self->rot[2];
        rx = self->rot[0];
        MTX_Identity33_(&m);
        if (ry != 0) {
            MTX_RotY33_(&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        MTX_MultVec33((Ov014Vec *)&self->unk_9c, &m, (Ov014Vec *)&self->unk_9c);
        self->unk_9c = (s32)(((s64)self->unk_9c * 0x29 + 0x800) >> 12);
        self->unk_a0 = (s32)(((s64)self->unk_a0 * 0x29 + 0x800) >> 12);
        self->unk_a4 = (s32)(((s64)self->unk_a4 * 0x29 + 0x800) >> 12);
        FLD(void *, self, 0xd0) = FLD(void *, func_ov014_0220f7f0(0, &self->pos), 0x24);
        self->unk_40->state++;
        self->unk_40->timer = 0x1e;
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
    }
    case 1: {
        Ov014V *e;
        self->pos.y -= 0xcd;
        e = func_020657b0(data_0214a420, FLD(void *, self, 0xd0));
        if (e != NULL) {
            s32 s = func_02049130(FX_Div(self->unk_40->timer << 12, 0x1e000), 0x19a, 0x3000);
            e->v1c(self->pos.x, self->pos.y - 0x1000, self->pos.z);
            e->v14(s, s, s);
        }
        if (self->unk_40->timer == 0xf) {
            func_ov000_0218996c(10, 10);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_02065804(data_0214a420, FLD(void *, self, 0xd0));
        FLD(void *, self, 0xd0) = NULL;
        self->unk_40->state = 10;
        self->unk_40->timer = 0x1e;
        break;
    }
    case 10: {
        u8 *q;
        self->pos.y += (0x1e - st->timer) * 0x7b;
        if (st->timer == 0xf) {
            func_02049f44(data_02097e4c, 0x50, &self->pos, 0);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        q = func_ov014_0220f7f0(0, &self->pos);
        ((Ov014V *)q)->v0c(0x1000);
        FLD(void *, self, 0xd0) = FLD(void *, q, 0x24);
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    }
    case 0x14: {
        Ov014V *e;
        s32 oldy = self->pos.y;
        s32 mag = VEC_Mag((Ov014Vec *)&self->unk_9c);
        s32 sp;
        VEC_Normalize((Ov014Vec *)&self->unk_9c, &dir);
        to.x = self->unk_84.x - self->pos.x;
        to.y = self->unk_84.y - self->pos.y;
        to.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&to, &to);
        VEC_MultAdd(0x333, &to, &dir, &dir);
        VEC_Normalize(&dir, &dir);
        sp = mag + 0x52;
        if (sp > 0x800) {
            sp = 0x800;
        }
        self->unk_9c = Ov014_FxMul(dir.x, sp);
        self->unk_a0 = Ov014_FxMul(dir.y, sp);
        self->unk_a4 = Ov014_FxMul(dir.z, sp);
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        self->rot[0] += 0x1ff;
        self->rot[1] = FLD(u16, self, 0xd8);
        self->rot[2] = FLD(u16, self, 0xda);
        n.x = -dir.x;
        n.y = -dir.y;
        n.z = -dir.z;
        e = func_020657b0(data_0214a420, FLD(void *, self, 0xd0));
        if (e != NULL) {
            e->v18(&self->pos);
            func_02040578(ang, &n);
            e->v30(ang);
        }
        if (self->pos.y < 0x5000 && oldy >= 0x5000) {
            func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
        }
        self->unk_40->timer++;
        if (!(self->unk_48->unk_50 & 0x60000000)) {
            return;
        }
        self->pos.y = FLD(s32, self, 0x68) >> 3;
        func_ov000_0218996c(0x14, 0x14);
        func_02065f88(5, &self->pos)->v0c(0x4000);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        func_02065860(data_0214a420, FLD(void *, self, 0xd0));
        FLD(void *, self, 0xd0) = NULL;
        if (FLD(u8, self, 0xd4) == 0) {
            Ov014Sub44 *q4;
            self->unk_38->unk_c2_0 = 0;
            q4 = self->unk_44;
            q4->unk_22_0 = 0;
            q4->unk_22_1 = 0;
        }
        self->unk_40->state = 0x19;
        self->unk_40->timer = 0x1e;
        break;
    }
    case 0x19: {
        u16 t = st->timer;
        if (t & 3) {
            void *a = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            v.x = self->pos.x - FLD(s32, self, 0x70);
            v.y = self->pos.y - FLD(s32, self, 0x74);
            v.z = self->pos.z - FLD(s32, self, 0x78);
            func_ov000_0219aae8(self, a, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, &v, 0,
                                0x4000, 0, 0x6a, 0x1000);
        }
        if (t % 15 == 0) {
            u16 a = func_02040498(0xffff);
            p.x = self->pos.x + Ov014_FxMul(OV014_SIN(a), 0x4000);
            p.y = self->pos.y;
            p.z = self->pos.z + Ov014_FxMul(OV014_COS(a), 0x4000);
            func_02065f88(0x6d, &p);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        if (FLD(u8, self, 0xd4) == 0) {
            FLD(u8, FLD(void *, self, 0x4c), 2) = 0;
            func_ov000_02198360(self->unk_40, 0x15, 0);
            return;
        }
        func_ov000_02191708(self->unk_38);
        func_ov000_02191618(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x19a);
        {
            Ov014Sub44 *q4 = self->unk_44;
            Ov014Sub48 *q8;
            q4->unk_22_0 = 1;
            q4->unk_22_1 = 1;
            q8 = self->unk_48;
            q8->unk_9a_0 = 1;
            q8->unk_9a_3 = 1;
            func_0203f324(q8);
        }
        self->unk_40->state = 0x28;
        self->unk_40->timer = 0x258;
        break;
    }
    case 0x28:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

}
