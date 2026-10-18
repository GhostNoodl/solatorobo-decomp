#include "ov012/ov012.h"

extern "C" {
void func_ov012_02204d00(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x406, &self->pos, 0);
        FLD(s32, self, 0xf0) = 1;
        FLD(s32, self, 0x104) = 0;
        FLD(u8, self, 0xf8) = 0;
        FLD(s32, self, 0xf0) |= 0x400;
        func_ov003_021daab0(FLD(void *, self, 0x100));
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void func_ov012_02204d64(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x406, &self->pos, 0);
        FLD(s32, self, 0xf0) |= 0x800;
        func_ov003_021daab0(FLD(void *, self, 0x100));
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
BOOL func_ov012_02205080(Ov012Actor *self, s32 a);
void func_ov012_02204dbc(Ov012Actor *self) {
    Ov012Actor *t;
    Ov012Sub40 *s;
    Ov012Sub48 *m;
    if (FLD(u32, self, 0xf0) & 0x800) {
        Ov012_ResetF0(self);
        FLD(u32, self, 0xf0) |= 0x200000;
    }
    if (FLD(u32, self, 0xf0) & 8) {
    t = func_ov000_0218d240(self);
    s = self->unk_40;
    switch (*(volatile u16 *)&s->state) {
    case 0:
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
        self->unk_40->state++;
    case 1:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        self->unk_48->unk_9a_5 = 1;
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 2:
        if (*t->unk_50 != 0) {
            s->timer++;
            if (s->timer <= 0x28) {
                return;
            }
            if (!func_ov012_02205080(self, 0x1b)) {
                return;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0;
        } else {
            s->state++;
        }
        break;
    case 3:
        s->timer++;
        if (s->timer <= 10) {
            return;
        }
        self->unk_40->timer = 0;
        if (*t->unk_50 != 0) {
            Ov012_ResetF0(self);
            FLD(u32, self, 0xf0) |= 0x200000;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    } else {
        func_ov003_021d3d28(self);
    }
}
}

extern "C" {
void func_ov012_02204fc8(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480d, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4824, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4825, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4826, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2800);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
extern const u8 data_ov012_0220a680[];
extern const Ov012Vec data_ov012_0220a5f4;
BOOL func_ov012_02205080(Ov012Actor *self, s32 a) {
    Ov012V *e;
    switch (FLD(u8, self, 0xfc)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[1], a, 0);
        e = func_02065f88(0x25e, &self->pos);
        e->v34(0x9fff, self->rot[1], self->rot[2]);
        e->v20(data_ov012_0220a680);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xff, e);
        FLD(u8, self, 0xfc)++;
        break;
    case 1:
        if (FLD(u8, self, 0xf4) != 3) {
            u16 t = FLD(u16, func_ov000_0219bf90(), 0xb1e);
            if (t != self->id) {
            e = func_02065f88(0x12f, &self->pos);
            e->v24(0, 0x1000, 0);
            e->v0c(0xb33);
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0xfe, e);
            }
        }
        FLD(u8, self, 0xfc)++;
        break;
    case 2:
        if (func_ov003_021daa0c(FLD(void *, self, 0x100), 0xfe)) {
            Ov012V *o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0x100), 0xfe));
            if (o != NULL) {
                Ov012Vec t = data_ov012_0220a5f4;
                o->v20(&t);
            }
        } else {
            FLD(u8, self, 0xfc) = 1;
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov003_021daa6c(FLD(void *, self, 0x100), 0xff);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
}

extern "C" {
void func_ov012_02205254(Ov012Actor *self) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Actor *o;
    Ov012Spawn_Init(&d, 0x4824);
    v.x = -0x1000;
    v.y = 0x2ccd;
    v.z = 0x4000;
    func_01ffc9fc(&v, &v, self->rot[1]);
    func_02012be8(&self->pos, &v, &v);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
    if (o == NULL) {
        return;
    }
    FLD(Ov012Flags8, o, 0x16).b0 = 1;
    FLD(u16, o, 0x18) = 0;
    func_ov000_0219bebc(o, FLD(s16, self, 0x124));
    switch (FLD(u8, data_ov000_021ccd54, 0xca)) {
    case 8:
        Ov012_VecSet(&o->unk_84, 0, 0x2000, -0x1f0a);
        break;
    case 3:
        Ov012_VecSet(&o->unk_84, -0x34cd, 0x2000, 0x2333);
        break;
    }
    o->rot[1] = self->rot[1];
    o->unk_90 = self->unk_90;
    if (FLD(void *, o, 0x4c) != NULL) {
        FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    }
}
}

extern "C" {
void func_ov012_022053a4(Ov012Actor *self) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Actor *o;
    Ov012Actor *t;
    Ov012Spawn_Init(&d, 0x4826);
    v.y = 0x3000;
    v.z = 0x4000;
    v.x = 0;
    func_01ffc9fc(&v, &v, self->rot[1]);
    func_02012be8(&self->pos, &v, &v);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
    if (o == NULL) {
        return;
    }
    FLD(Ov012Flags8, o, 0x16).b0 = 1;
    t = func_ov000_0218d240(self);
    Ov012_VecSet(&o->unk_84, t->pos.x, 0x800, t->pos.z);
    o->rot[1] = self->rot[1];
    o->unk_90 = self->unk_90;
    if (FLD(u8, self, 0xf4) == 3) {
        FLD(u16, o, 0x18) = 1;
    }
    func_ov000_0219bebc(o, FLD(s16, self, 0x124));
    if (FLD(void *, o, 0x4c) != NULL) {
        FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    }
}
}

extern "C" {
extern const u8 data_ov012_0220a5e8[];
extern const u16 data_ov012_0220a58e[];
void func_ov012_022054cc(Ov012Actor *self) {
    Ov012Sub40 *s;
    Ov012V *e;
    switch (FLD(u8, self, 0xfd)) {
    case 0:
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        self->unk_40->timer = 0;
        FLD(u8, self, 0xfd)++;
        break;
    case 1:
        func_ov003_021daab0(FLD(void *, self, 0x100));
        e = func_02065f88(0x190, &self->pos);
        e->v0c(0x1800);
        e->v20(data_ov012_0220a5e8);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xfa, e);
        FLD(u8, self, 0xfd)++;
        break;
    case 2:
        if (!func_ov003_021daa0c(FLD(void *, self, 0x100), 0xfa)) {
            u16 hp;
            e = func_02065f88(0xcb, &self->pos);
            e->v0c(0x1800);
            e->v20(data_ov012_0220a5e8);
            {
                s16 v = self->unk_18 + 1;
                hp = data_ov012_0220a58e[v];
                self->unk_18 = v;
            }
            self->unk_50[1] = hp;
            self->unk_50[0] = hp;
            FLD(u8, self, 0xfd)++;
        }
        func_ov003_021dacfc(FLD(void *, self, 0x100));
        break;
    case 3: {
        Ov012Sub48 *m;
        Ov012Sub44 *n;
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x5a) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        {
            u8 *g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
        }
        Ov012_ResetF0(self);
        FLD(u32, self, 0xf0) |= 0x200000;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_40->timer = 0;
        FLD(u8, self, 0xfd) = 0;
        break;
    }
    }
}
}

extern "C" {
extern const u8 data_ov012_0220b09c[];
void func_ov012_022056d4(Ov012Actor *self) {
    func_ov000_0219433c(self);
    func_ov000_0218f074((u8 *)self + 0xd8, data_ov012_0220b09c, 1, 1, 0, 0);
    FLD(s16, self, 0xd8) = 0;
}
}

extern "C" {
BOOL func_ov012_02205714(Ov012Actor *self) {
    BOOL r = func_ov000_021946f8(self);
    if (FLD(s16, self, 0xd8) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0xd8)) ? TRUE : FALSE;
    }
    return r;
}
}
