#include "ov009/ov009.h"

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0221327c(Ov009Actor *self) {
    Ov009Vec p;
    Ov009V *e;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        self->unk_ea_6 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x483f, 0x15);
        func_ov000_0218996c(10, 0x28);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        e = func_02065f88(5, &self->pos);
        e->v14(0x7800, 0x7800, 0x7800);
        self->unk_40->state++;
        break;
    }
    case 1:
        func_ov003_021d6a3c(self, 0, 1, 1);
        self->unk_40->state++;
        break;
    }
    self->v50();
    st = self->unk_40;
    st->timer++;
    if (st->timer != 0x5a) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    {
        s32 w = self->unk_64;
        p.x += func_02040498(w >> 1) + (w >> 1);
    }
    p.y += func_02040528(FLD(s32, self, 0x68));
    p.z += func_02040528(0x4000) + 0x3000;
    e = func_02065f88(0x325, &p);
    e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    self->unk_40->timer = 0;
}

extern void *data_ov000_021ccd64;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
static inline Ov009Actor *Ov009_FindActor4(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_02213460(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Sub40 *st = self->unk_40;
    u16 t;
    switch (st->state) {
    case 0:
        self->unk_9c = 0;
        self->unk_a0 = -0x71;
        self->unk_a4 = 0;
        *self->unk_50 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st->timer++;
        t = st->timer;
        if (t > 0xb4) {
            Ov009Actor *a = Ov009_FindActor4(FLD(u16, self, 0xf0));
            if (a != NULL) {
                func_ov000_0218d46c(a, FLD(u16, self, 0xf0), 0x15);
            }
            func_ov000_0218996c(0xf, 0x50);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->v14(0x8000, 0x8000, 0x8000);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if (t % 20 == 0) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            v.x = 0x1333;
            v.y = 0x2000;
            v.z = 0x7800;
            func_ov000_0219b71c(&p, &v, 0x666, 0x1000, 3, 0x46);
            func_ov000_0218996c(8, 8);
            func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
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
