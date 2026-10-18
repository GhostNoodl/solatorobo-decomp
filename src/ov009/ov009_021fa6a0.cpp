#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void func_0203f364(Ov009Sub48 *p);
extern s32 func_01ffbd6c(Ov009Vec *a, Ov009Vec *b, s32 c, s32 d, s32 e, s32 f);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
void func_ov009_021fa6a0(Ov009Actor *self) {
    s32 dist;
    Ov009Actor *o;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->unk_50 != NULL && *self->unk_50 == 0) {
        return;
    }
    dist = 0x7fffffff;
    o = func_ov000_0219bf90();
    if (o != NULL) {
        if (func_ov000_021b4738(o)) {
            return;
        }
        self->unk_90 = o->id;
        dist = VEC_Distance(&self->pos, &o->pos);
    }
    if (dist > 0x12000) {
        self->unk_93_4 = 0;
        return;
    }
    if (self->unk_1a == 1) {
        if (dist > 0xa000) {
            Ov009Sub48 *s48;
            func_ov000_02198360(self->unk_40, 0, 0);
            self->unk_38->unk_c2_0 = 0;
            s48 = self->unk_48;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            self->unk_44->unk_22_1 = 0;
            self->unk_93_4 = 0;
            return;
        }
        self->unk_40->flags |= 2;
        self->unk_1a = 0;
        self->unk_38->unk_c2_0 = 1;
    } else if (self->unk_1a == 2) {
        if (!self->unk_93_4) {
            Ov009Vec a;
            Ov009Vec b;
            a.x = o->pos.x;
            a.y = o->pos.y;
            a.z = o->pos.z;
            b.x = self->pos.x;
            b.y = self->pos.y;
            b.z = self->pos.z;
            a.y += FLD(s32, o, 0x6c);
            b.y += FLD(s32, self, 0x6c);
            if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) != -0x1000) {
                return;
            }
        }
    }
    self->unk_93_4 = 1;
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    {
        Ov009Actor *e = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        if (e != NULL && FLD(u16, e, 0x16) <= 3) {
            if (self->unk_b6 != 0) {
                self->unk_b6--;
            }
        }
    }
    if (self->unk_b6 != 0 && dist > 0x4000) {
        return;
    }
    self->unk_40->flags |= 0x8000;
    self->unk_b6 = 0x5a;
}
extern u8 data_ov009_02216aa4[];
extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216ab0[];
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_021911c8(void *model, s32 a);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern Ov009Actor *func_ov003_021d69a0(Ov009Actor *self, u16 kind, s32 a);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern s32 func_02040498(s32 max);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
static inline Ov009Actor *Ov009_FindActor5b(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_021fa934(Ov009Actor *self) {
    Ov009Actor *t = Ov009_FindActor5b(self->unk_90);
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216aa4, 0x400, 0);
        FLD(u16, self, 0xf0) = 100;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0x2d;
        if (self->kind == 0x5422) {
            self->unk_40->timer = 0x1e;
        }
        break;
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216aaa, 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_a0 = 0x59a;
            self->unk_a8 = 0x52;
            self->unk_40->state++;
            self->unk_40->timer = 0;
            return;
        }
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        break;
    case 2: {
        u16 flag;
        u16 a;
        Ov009Actor *g;
        u16 lim;
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab0, 0x800, 0);
        if (t != NULL) {
            func_ov000_0219aae8(self, self, FLD(u16, self, 0xf0), 0x20, (u16)(1 << (t->id >> 12)), NULL, 0, 0x3400, 0x2800, 0x64, 0x1000);
        }
        func_02065f88(0x66, &self->pos)->v0c(0x1c00);
        g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
        lim = 4;
        if (FLD(u8, data_ov000_021ccd54, 0xca) == 2) {
            lim = 3;
        }
        if (g != NULL && FLD(u16, g, 0x16) < lim) {
            u16 k = 0x5401;
            Ov009Actor *o;
            flag = 0;
            if (self->kind == 0x5422) {
                k = 0x541f;
                flag = 1;
            }
            o = func_ov003_021d69a0(self, k, 4);
            if (o != NULL) {
                Ov009Vec v;
                s32 z = self->unk_64;
                v.y = 0x2000;
                v.x = 0;
                v.z = z;
                a = self->rot[1] + 0xe800 + func_02040498(0x3000);
                func_01ffc9fc(&v, &v, a);
                VEC_Add(&v, &self->pos, &v);
                o->pos.x = v.x;
                o->pos.y = v.y;
                o->pos.z = v.z;
                o->unk_9c = func_02040498(0x80) + 0x19a;
                o->unk_a0 = 0x333;
                o->unk_a4 = 0;
                o->unk_a8 = 0x52;
                o->unk_98 = a;
                if (flag) {
                    o->unk_1a = flag;
                }
            }
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        if (self->kind == 0x5422) {
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_b6 = 1;
        }
        break;
    }
    case 3:
        st->timer++;
        if (st->timer > 0x28) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        self->unk_48->unk_9a_5 = 1;
        break;
    }
}

}
