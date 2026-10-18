#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);

void func_ov009_021fd71c(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Actor *o;
    Ov009Actor *t;
    u16 kind = 0x483f;
    p = self->pos;
    if (self->kind == 0x5012) {
        p.y += 0xccd;
    } else {
        p.y -= 0x2800;
        kind = 0x482d;
    }
    o = func_ov000_0219be1c(kind, &p, self->rot, self->id, self->unk_90);
    if (self->unk_18 == 1) {
        func_02049f44(data_02097e4c, 0xd02, &self->pos, 0);
        t = func_ov000_0218d240(self);
        if (t != NULL) {
            Ov009Vec tp;
            tp = t->pos;
            if (func_01ffc584(&p, &tp, 0x6800, 0x7000)) {
                Ov009Rot r;
                r.x = 0xf000;
                r.y = o->rot[1];
                r.z = o->rot[2];
                *(Ov009Rot *)o->rot = r;
            }
        }
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void func_0203f364(Ov009Sub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

static inline void Ov009_VecSet(Ov009Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov009_ReleaseFx(Ov009Actor *self) {
    u16 id;
    switch (self->kind) {
    case 0x5012:
        id = 0x5013;
        break;
    case 0x5038:
    case 0x5044:
        id = 0x5045;
        break;
    }
    func_ov000_0218e8ec(data_ov000_021ccd68, id, 0x15);
    func_ov000_0218e8ec(data_ov000_021ccd68, 0x483f, 0x15);
    func_ov000_0218e8ec(data_ov000_021ccd68, 0x482d, 0x15);
}

void func_ov009_021fd830(Ov009Actor *self) {
    Ov009Sub48 *s48;
    Ov009Sub44 *s44;
    Ov009Sub38 *m;
    Ov009V *e;
    s32 spd;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        *self->unk_50 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        if (FLD(u8, data_ov000_021ccd54, 0xca) == 0x11) {
            Ov009_VecSet((Ov009Vec *)&self->unk_9c, 0, 0, 0);
        } else {
            Ov009_VecSet((Ov009Vec *)&self->unk_9c, func_02040528(0x29), -0x71, func_02040528(0x29));
        }
        Ov009_ReleaseFx(self);
        m = self->unk_38;
        m->unk_c2_9 = 2;
        NNSi_G3dModifyPolygonAttrMask(m->unk_04, 0, 0xc0);
        self->unk_40->state++;
    case 1:
        if (self->unk_40->timer > 0x78) {
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            e = func_02065f88(5, &self->pos);
            spd = 0x6000;
            if (self->kind != 0x5012) {
                spd = 0x4800;
            }
            e->v0c(spd);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((self->unk_40->timer & 0xf) == 0) {
            Ov009Vec v;
            s32 a = -1;
            s32 b = 100;
            switch (self->unk_40->timer & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                a = 3;
                b = 0x19;
                break;
            case 0x20:
                break;
            case 0x30:
                a = 3;
                b = 0x32;
                break;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            func_ov000_0219b71c(&self->pos, &v, 0xc00, 0x1400, a, b);
            func_ov000_0218996c(6, 10);
        }
        self->unk_40->timer++;
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Ov009_ReleaseFx(self);
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        if ((u8)self->unk_40->timer < 0x1f) {
            func_ov003_021d6954(self, self->unk_40->timer);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    }
}

}
