#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *data_0214a420;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_0203f920(void *p);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0219b400(void *a, void *b, s32 c, Ov009Vec *pos, u16 *rot, s32 d);
extern void func_ov000_0219b5dc(u16 id, const Ov009Vec *pos, const u16 *rot);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    Ov009Actor *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return a;
}

void func_ov009_02203428(Ov009Actor *self) {
    Ov009V *e;
    Ov009Actor *a;
    Ov009Sub40 *st;
    u8 *c;
    if (FLD(void *, self, 0x58) != NULL) {
        func_0203f920(FLD(void *, self, 0x58));
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *m;
        Ov009Sub44 *s;
        *self->unk_50 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        e = func_02065f88(0x322, &self->pos);
        e->v24(0, FLD(s32, self, 0x6c), 0);
        e->v0c(0x2000);
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, self, 0xf4) = FLD(s32, e, 0x24);
        switch (self->kind) {
        case 0x5049:
            a = Ov009_FindActor(FLD(u16, self, 0xde));
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0x15);
            }
            break;
        case 0x5055:
            a = Ov009_FindActor(FLD(u16, self, 0xde));
            if (a != NULL) {
                a->unk_1a = 1;
            }
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4003, 0x15);
            break;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        u16 t;
        st = self->unk_40;
        st->timer++;
        t = st->timer;
        if (t >= 0x78) {
            func_ov000_0218996c(10, 0x3c);
            func_02065804(data_0214a420, FLD(s32, self, 0xf4));
            func_02065f88(1, &self->pos)->v24(0, FLD(s32, self, 0x6c), 0);
            e = func_02065f88(5, &self->pos);
            e->v24(0, FLD(s32, self, 0x6c), 0);
            e->v0c(0x4000);
            a = Ov009_FindActor(FLD(u16, self, 0xf0));
            if (a != NULL) {
                func_ov000_0218d46c(a, FLD(u16, self, 0xf0), 0x15);
            }
            self->unk_40->state = 10;
            break;
        }
        if (t >= 0x28 && t % 10 == 0) {
            Ov009Vec p;
            Ov009Vec v;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += FLD(s32, self, 0x6c);
            v.x = self->unk_64;
            v.y = FLD(s32, self, 0x68) >> 2;
            v.z = self->unk_64;
            func_ov000_0219b71c(&p, &v, 0x733, 0xccd, 4, 0x32);
            func_ov000_0218996c(8, 8);
            func_02049f44(data_02097e4c, 0x35, &p, 0);
        }
        break;
    }
    case 10:
        c = func_02070558((void *)self->kind);
        func_ov000_0219b400(c + 0x3e, c + 0x42, 2, &self->pos, self->rot, 1);
        func_ov000_0219b5dc(FLD(u16, self->unk_b0, 6), &self->pos, self->rot);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 11:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
            func_ov003_021d6a3c(self, 1, 1, 1);
            break;
        }
        func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        break;
    }
}

}
