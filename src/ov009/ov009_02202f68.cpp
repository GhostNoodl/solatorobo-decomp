#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *data_0214a420;
extern const Ov009Vec data_ov009_02215d84;
extern const Ov009Vec data_ov009_02215db4;
extern const s32 data_ov009_02215d54[];
extern u8 data_ov009_02215e60[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_020657b0(void *mgr, s32 h);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov009_0220387c(Ov009Actor *self);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov009_02202f68(Ov009Actor *self) {
    Ov009Vec tmp;
    Ov009Vec tp;
    Ov009Vec off;
    Ov009Actor *t;
    s32 lim;
    u16 id;
    Ov009V *e;
    u8 *c;
    Ov009Sub40 *st;
    Ov009Actor *a;
    t = Ov009_FindActor(self->unk_90);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    func_01ffc9fc(&off, &data_ov009_02215d84, self->rot[1]);
    st = self->unk_40;
    lim = self->pos.y + FLD(s32, self, 0x68);
    switch (st->state) {
    case 0:
        if (self->kind == 0x5055 && tp.y <= lim) {
            e = func_02065f88(0x640, &self->pos);
            e->v0c(0xccd);
            e->v20(&off);
            FLD(s32, self, 0xf4) = FLD(s32, e, 0x24);
        }
        func_02049f44(data_02097e4c, 0x46, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        e = func_020657b0(data_0214a420, FLD(s32, self, 0xf4));
        if (e != NULL) {
            VEC_Add(&off, &self->pos, &tmp);
            e->v18(&tmp);
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x32) {
            func_02049f44(data_02097e4c, 0x73, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        if (tp.y > lim) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    case 2:
        st->timer++;
        if (st->timer > 10) {
            func_02049f44(data_02097e4c, data_ov009_02215d54[self->unk_1a], &self->pos, 0);
            func_ov000_0218996c(10, 0xf);
            self->unk_40->timer = 0;
            if (self->kind == 0x5055) {
                self->unk_40->state = 10;
            } else {
                self->unk_40->state++;
            }
        }
        break;
    case 3:
        c = func_02070558((void *)self->kind);
        if (c != NULL) {
            u16 *p = (u16 *)(c + 0x3a);
            if (p != NULL) {
                u16 k = *p;
                if (k != 0xffff) {
                    id = k;
                }
                VEC_Add(&off, &self->pos, &tmp);
                a = func_ov003_021d69f0(self, id, &tmp, self->rot, t);
                if (a != NULL) {
                    FLD(void *, a, 0x60) = data_ov009_02215e60;
                    func_ov000_0218d46c(a, self->id, 0xb);
                }
            }
        }
        self->unk_40->state = 0x1e;
        break;
    case 10: {
        func_ov000_02191690(self->unk_38);
        func_ov009_0220387c(self);
        tp.x -= self->pos.x;
        tp.y -= self->pos.y;
        tp.z -= self->pos.z;
        func_01ffc9fc(&tp, &tp, (u16)(0xffff - self->rot[1]));
        Ov009Vec v = data_ov009_02215db4;
        if (tp.x <= 0) {
            v.x = Ov009_FxMulL(v.x, -0x1000);
        }
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(&v, &self->pos, &v);
        self->unk_84.x = v.x;
        self->unk_84.y = v.y;
        self->unk_84.z = v.z;
        self->unk_40->state++;
    }
    case 11:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_0218d918(self, &self->unk_84, 0x3d);
            a = Ov009_FindActor(FLD(u16, self, 0xde));
            if (a != NULL) {
                a->rot[1] = self->rot[1];
            } else {
                func_ov000_02191708(self->unk_38);
                self->unk_40->state = 0x1e;
            }
        }
        break;
    case 0x1e:
        st->timer++;
        if (st->timer >= 200) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_ea_0 = 3;
}

}
