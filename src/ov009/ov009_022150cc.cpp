#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern const Ov009Vec data_ov009_022161ec;
extern const Ov009Vec data_ov009_022161d4;
extern void *func_ov000_02199ba0(void *p);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_ov009_02215714(Ov009Actor *self);
extern void func_ov009_02215a6c(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const Ov009Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_RotX(Ov009Vec *out, const Ov009Vec *v, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 s = OV009_SIN(ang);
    s32 c = OV009_COS(ang);
    if (v->y != 0) {
        y += Ov009_FxMul(c, v->y);
        z += Ov009_FxMul(s, v->y);
    }
    if (v->z != 0) {
        y += Ov009_FxMul(-s, v->z);
        z += Ov009_FxMul(c, v->z);
    }
    out->x = v->x;
    out->y = y;
    out->z = z;
}

void func_ov009_022150cc(Ov009Actor *self) {
    Ov009Actor *p;
    Ov009Sub48 *m;
    p = (Ov009Actor *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (p != NULL) {
        m = p->unk_48;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    } else {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (p->kind == 0x1000) {
        func_ov009_02215714(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        func_02065f88(0x6a, &self->pos)->v0c(0xccd);
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        FLD(s32, self, 0xd8) = func_02040528(0x14) + 0x7b;
        if (self->unk_18 == 1) {
            FLD(s32, self, 0xd8) = 0x3d;
        }
        FLD(u8, self, 0xd4) = 0;
        self->unk_92 = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Vec a = data_ov009_022161ec;
        func_01ffc9fc(&a, &a, self->rot[1]);
        VEC_Add(&a, &self->pos, &a);
        func_ov000_0218d9e8(self, &a, FLD(s32, self, 0xd8));
        if (self->unk_48->unk_50 & 0x40000000) {
            self->rot[0] = 0x3ffc;
        } else if (self->rot[0] < 0xbff4 && self->rot[0] > 0x3ffc) {
            self->rot[0] = 0x3ffc;
        }
        Ov009Vec v = data_ov009_022161d4;
        Ov009_RotX(&v, &v, self->rot[0]);
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Normalize(&v, &v);
        self->unk_9c = Ov009_FxMulL(v.x, 0x333);
        self->unk_a0 = Ov009_FxMulL(v.y, 0x333);
        self->unk_a4 = Ov009_FxMulL(v.z, 0x333);
        switch (self->unk_18) {
        case 1:
            if (p->pos.y > 0x9000) {
                self->unk_9c = Ov009_FxMulL(v.x, 0x51f);
                self->unk_a0 = Ov009_FxMulL(v.y, 0x51f);
                self->unk_a4 = Ov009_FxMulL(v.z, 0x51f);
            } else {
                self->unk_9c = Ov009_FxMulL(v.x, 0x59a);
                self->unk_a0 = Ov009_FxMulL(v.y, 0x59a);
                self->unk_a4 = Ov009_FxMulL(v.z, 0x59a);
            }
            break;
        case 2:
            self->unk_9c = Ov009_FxMulL(v.x, 0x47b);
            self->unk_a0 = Ov009_FxMulL(v.y, 0x47b);
            self->unk_a4 = Ov009_FxMulL(v.z, 0x47b);
            break;
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        func_ov009_02215a6c(self);
        m = self->unk_48;
        if (m->unk_50 & 0x20000000) {
            self->unk_a0 = 0x266;
            self->unk_a8 = 0x29;
            self->unk_92++;
            m->unk_9a_0 = true;
            m->unk_9a_3 = 1;
            func_0203f324(m);
            self->unk_40->state++;
        }
        if (++FLD(u8, self, 0xd4) >= 0x96) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    case 2:
        if (self->unk_a0 <= 0 && (self->unk_48->unk_50 & 0x20000000)) {
            if (++self->unk_92 <= 2) {
                self->unk_a0 = 0x19a;
            } else {
                Ov009Sub44 *s;
                func_ov000_0218996c(10, 10);
                func_02065f88(5, &self->pos)->v0c(0x3000);
                func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, NULL, 0, 0x4000, 0, 0x64, 0x1000);
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                s = self->unk_44;
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        }
        func_ov000_0218dbe0(self, 0);
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
