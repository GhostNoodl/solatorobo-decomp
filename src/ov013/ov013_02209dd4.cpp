#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220be7c[];
extern char data_ov013_0220be82[];
extern void *data_ov000_021ccd68;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}
extern char data_ov013_0220bea0[];
extern char data_ov013_0220bea6[];
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov000_0218ddd4(Ov013Actor *self, Ov013Vec *v, s32 a);

extern void func_ov003_021d112c(Ov013Actor *self);
extern s32 func_02040528(s32 a);
extern s32 func_02040498(s32 a);

extern void *func_ov000_0218e4cc(void *mgr, s32 a);
extern u16 func_ov000_0218dfb4(void *p, s32 a);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);


s32 func_ov013_02209b44(Ov013Actor *self) {
    s32 rnd;
    s32 st;
    u16 pct;
    u32 n;
    rnd = func_02040498(0x63);
    pct = self->unk_50[0] * 100 / self->unk_50[1];
    n = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0x4813);
    st = 0xe;
    if ((FLD(u8, self, 0xf2) == 2 && rnd % 2 == 0) || FLD(u8, self, 0xf2) == 3) {
        st = 0xf;
    }
    if (st == 0xe) {
        if (pct <= 0x32) {
            if (!func_ov000_021983b0(self->unk_40, 0x10, 3, 1)) {
                st = 0x10;
                if (n != 0) {
                    st = 1;
                    FLD(u8, self, 0xf0) = 1;
                }
            }
        } else if (pct <= 0x46) {
            if (n == 0) {
                st = 0x10;
            }
        }
    }
    if (st == 0xe && n >= 3) {
        st = 0xf;
    }
    if (!func_ov000_021983b0(self->unk_40, 0xf, 7, 1)) {
        if (FLD(u8, self, 0xf1) != 0xf) {
            st = 0xf;
        }
    }
    switch (st) {
    case 1:
    case 0xf:
    case 0x10:
        FLD(u8, self, 0xf2) = 0;
        break;
    case 0xe:
        FLD(u8, self, 0xf2)++;
        break;
    }
    return st;
}

void func_ov013_02209cac(Ov013Actor *self) {
    s32 r;
    Ov013Vec *v;
    func_ov003_021d112c(self);
    FLD(u16, self, 0xf0) = self->rot[1] + func_02040528(0x3400);
    v = &FLD(Ov013Vec, self, 0xf4);
    Ov013_VecCopy(v, &self->pos);
    r = func_02040498(0x800) + 0x3800;
    v->x += Ov013_FxMul(r, OV013_SIN(self->rot[1]));
    v->z += Ov013_FxMul(r, OV013_COS(self->rot[1]));
    FLD(s32, self, 0x104) = v->y;
    self->unk_b8.y = v->y;
    FLD(s32, self, 0x100) = v->x;
    self->unk_b8.x = v->x;
    self->unk_1c = 0x96;
    FLD(s32, self, 0x108) = v->z;
    self->unk_b8.z = v->z;
    self->unk_ea_6 = 1;
    {
        Ov013Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    self->unk_48->unk_30 = 0;
    self->unk_48->unk_48 = 0x1000;
    self->unk_c8 = 0xf000;
    self->unk_cc = 0x5000;
}

void func_ov013_02209dd4(Ov013Actor *self) {
    Ov013Vec d;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 1: {
        Ov013Sub40 *q = self->unk_40;
        q->timer++;
        if (q->timer > 0x1e) {
            Ov013Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
    d.x = FLD(s32, self, 0x100) - self->pos.x;
    d.y = FLD(s32, self, 0x104) - self->pos.y;
    d.z = FLD(s32, self, 0x108) - self->pos.z;
    VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

void func_ov013_02209ed8(Ov013Actor *self) {
    Ov013Vec d;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x200, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 1: {
        Ov013Sub40 *q = self->unk_40;
        if (q->timer != 0) {
            q->timer--;
        }
        if (q->timer == 0) {
            self->unk_40->timer = 0x3c;
            FLD(Ov013Vec, self, 0x100) = self->unk_b8;
            FLD(s32, self, 0x100) += func_02040528(0x8cd);
            FLD(s32, self, 0x108) += func_02040528(0x8cd);
            FLD(s32, self, 0x104) = FLD(s32, self, 0x104) + func_02040528(0x8cd) + 0x1800;
        }
        break;
    }
    }
    d.x = FLD(s32, self, 0x100) - self->pos.x;
    d.y = FLD(s32, self, 0x104) - self->pos.y;
    d.z = FLD(s32, self, 0x108) - self->pos.z;
    d.x = Ov013_FxMul(d.x, 0x33);
    d.y = Ov013_FxMul(d.y, 0x33);
    d.z = Ov013_FxMul(d.z, 0x33);
    d.y *= 3;
    VEC_Add(&self->pos, &d, &self->pos);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

void func_ov013_0220a080(Ov013Actor *self) {
    Ov013Vec v;
    if (self->unk_40->state == 0) {
        const char *name = data_ov013_0220bea0;
        if (self->unk_ee_0) {
            name = data_ov013_0220bea6;
        }
        func_ov000_02190cb0(self->unk_38, name, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    self->unk_9c = self->unk_b0->unk_00;
    v = self->unk_b8;
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    self->pos.y += Ov013_FxMul(v.y + 0x1800 - self->pos.y, 0xcd);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

void func_ov013_0220a17c(Ov013Actor *self) {
    Ov013Sub40 *q;
    if (!Ov013_GameIdle()) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    q = self->unk_40;
    switch (q->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be82, 0x200, 1);
        self->unk_40->state++;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        break;
    case 1:
        func_ov000_0218d988(self, Ov013_FindActor(self->unk_90), self->unk_b0->unk_02);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_40->state++;
        }
        break;
    case 2: {
        s32 y = self->unk_48->unk_68.y;
        q->timer++;
        if (q->timer > 0x2d || self->pos.y < y + 0x1400) {
            func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x200, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->timer = 0;
            self->unk_40->state++;
            if (self->pos.y < y + 0x1400) {
                self->unk_a0 >>= 1;
            }
        }
        break;
    }
    case 3: {
        s32 lim;
        self->unk_9c -= self->unk_9c >> 3;
        self->unk_a0 -= self->unk_a0 >> 2;
        lim = self->unk_1c;
        q->timer++;
        if (q->timer > lim) {
            func_ov000_02198360(self->unk_40, 1, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
        }
        break;
    }
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

}
