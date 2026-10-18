#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_021983b0(Ov009Sub40 *st, s32 a, s32 b, s32 c);

void func_ov009_0220da24(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        FLD(u8, self, 0x108) = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->unk_40, 0x13, 1, 0)) {
            self->unk_40->timer = 0x3c;
            self->unk_40->state++;
            return;
        }
        FLD(Ov009Vec, self, 0xfc) = self->pos;
        FLD(Ov009Vec, self, 0xfc).x += 0x2800;
        FLD(Ov009Vec, self, 0xfc).y -= 0x2000;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x41 || VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
            FLD(Ov009Vec, self, 0xfc).x = FLD(Ov009Vec, self, 0xf0).x;
            FLD(Ov009Vec, self, 0xfc).y = FLD(Ov009Vec, self, 0xf0).y;
            FLD(Ov009Vec, self, 0xfc).z = FLD(Ov009Vec, self, 0xf0).z;
        }
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
        break;
    }
}

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220dba4(Ov009Actor *self) {
    Ov009Vec p;
    Ov009V *e;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480b, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x482e, 0x15);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_ov000_0218996c(0x10, 0x3c);
        self->unk_ea_6 = 1;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (self->unk_40->timer >= 10) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state++;
        }
        break;
    }
    self->v50();
    st = self->unk_40;
    st->timer++;
    if (st->timer != 0x78) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.x += func_02040528(self->unk_64 >> 1);
    p.y += func_02040528(FLD(s32, self, 0x68));
    p.z += func_02040498(0x1000) + 0x6000;
    e = func_02065f88(0x325, &p);
    e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    self->unk_40->timer = 0;
}

extern void *data_ov000_021ccd64;
extern void func_02049bb4(void *mgr, s32 id);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
void func_ov009_0220dd84(Ov009Actor *self) {
    Ov009Vec p0;
    Ov009Vec v;
    Ov009Vec p1;
    Ov009Vec d;
    Ov009Sub40 *st;
    u16 t;
    d.x = 0x2cd - self->unk_9c;
    d.y = 0x148 - 0x2cd - self->unk_a0;
    d.z = -self->unk_a4;
    VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    st = self->unk_40;
    st->timer++;
    t = st->timer;
    if (t == 300) {
        func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
    if (t > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
    }
    if ((t & 0x3f) == 1) {
        Ov009V *e;
        p0.x = self->pos.x;
        p0.y = self->pos.y;
        p0.z = self->pos.z;
        p0.x += func_02040528(self->unk_64 >> 1);
        p0.y += func_02040528(FLD(s32, self, 0x68));
        p0.z += func_02040498(0x1000) + 0x6000;
        e = func_02065f88(0x325, &p0);
        e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    }
    if ((t & 0xf) == 0) {
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
        v.z = 0x800;
        p1.x = self->pos.x;
        p1.y = self->pos.y;
        p1.z = self->pos.z + 0x7000;
        func_ov000_0219b71c(&p1, &v, 0xc00, 0x1400, a, b);
        func_ov000_0218996c(6, 10);
    }
}

}
