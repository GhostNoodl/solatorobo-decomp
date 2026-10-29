#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern void *data_02097e4c;
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern u16 func_ov003_021d9edc(s32 id);
extern void func_ov014_021fe3ec(Ov014Actor *self);

void func_ov014_021ff318(Ov014Actor *self) {
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e = func_02065f88(0x2bd, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x8000);
        e->v34(0x4000, 0, 0);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        self->unk_40->state++;
    }
    case 1: {
        u8 i;
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
            return;
        }
        for (i = 0; i < 2; i++) {
            Ov014V *e = func_02065f88(0x57e, &self->pos);
            e->v24(0, 0, 0x7000);
            e->v0c(0x3000);
            func_0204a028(data_02097e4c, 0x79, &self->pos, -5);
        }
        self->unk_40->state++;
        break;
    }
    case 2: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        self->unk_40->timer = 0;
        if (FLD(s16 *, self, 0x15c)[0] == 12 && !func_ov003_021d9edc(0x482b)) {
            self->unk_40->state = 10;
        } else {
            self->unk_40->state = 0x1e;
        }
        func_ov014_021fe3ec(self);
        break;
    }
    case 10: {
        Ov014Sub40 *w = self->unk_40;
        w->timer++;
        if (w->timer < FLD(u16 *, self, 0x15c)[1]) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_40->state = 1;
        break;
    }
    case 0x1e: {
        u16 lim = 0;
        Ov014Sub40 *w = self->unk_40;
        if (FLD(u16 *, self, 0x15c) != NULL) {
            lim = FLD(u16 *, self, 0x15c)[3];
        }
        w->timer++;
        if (w->timer < lim) {
            return;
        }
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u8, self, 0x138) ^= 0x80;
        self->unk_40->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_020639d4(void *e, s32 a, s32 b);
extern Ov014Actor *func_ov000_0219bf90(void);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov014Actor *a, s32 b);

void func_ov014_021ff59c(Ov014Actor *self) {
    if (FLD(s16, self, 0xf0) != 1) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x482b, 0x15);
        e = func_02065f88(0x2bd, &self->pos);
        e->v24(0, 0, 0x7000);
        e->v0c(0x8000);
        e->v34(0x4000, 0, 0);
        func_020639d4(e, 0x44, 0);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        FLD(u8, self, 0xf9) = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        u8 i;
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
            for (i = 0; i < 2; i++) {
                Ov014V *e = func_02065f88(0x57e, &self->pos);
                e->v24(0, 0, 0x7000);
                e->v0c(0x3000);
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 1, e);
            }
            if (FLD(u8, self, 0xf9) == 1) {
                Ov014SpawnDesc desc;
                Ov014Actor *o;
                Ov014Spawn_Init(&desc, 0xffff);
                Ov014Spawn_Set(&desc, 0x482c);
                o = func_ov000_02192b24(&desc);
                if (o != NULL) {
                    o->pos.x = 0;
                    o->pos.y = 0x4719a;
                    o->pos.z = 0xf000;
                    o->unk_90 = self->unk_90;
                    o->v04();
                    FLD(Ov014Flags8, o, 0x16).b0 = 1;
                    func_ov000_0219bebc(o, FLD(s16, self, 0x13a));
                    if (FLD(u8 *, o, 0x4c) != NULL) {
                        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
                    }
                }
            }
            if (FLD(u8, self, 0xf9) >= 2) {
                self->unk_40->state = 0x1e;
            } else {
                self->unk_40->state++;
            }
        } else {
            Ov014Actor *pl = func_ov000_0219bf90();
            if (pl != NULL) {
                FLD(s32, pl, 0xb90) = self->pos.x;
                FLD(s32, pl, 0xb94) = self->pos.y;
                FLD(s32, pl, 0xb98) = self->pos.z;
                FLD(s32, pl, 0xb9c) = 0x400;
            }
        }
        break;
    }
    case 2:
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 1)) {
            FLD(u8, self, 0xf9)++;
            self->unk_40->state = 1;
        }
        break;
    case 0x1e:
        if (!func_ov003_021d9edc(0x482c)) {
            if (FLD(u32, self, 0xf4) & 0x10) {
                FLD(u32, self, 0xf4) ^= 0x10;
            }
            FLD(u32, self, 0xf4) |= 1;
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}


struct Ov014CamDa {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
};

struct Ov014PlB24 {
    u32 b0 : 1;
    u32 rest : 31;
};

static inline void Ov014Cam_SetY(u8 *cam, u16 x) {
    FLD(u16, cam, 0xfa) = x;
    FLD(Ov014CamDa, cam, 0xda).b4 = 1;
}
static inline void Ov014Cam_SetX(u8 *cam, u16 x) {
    FLD(u16, cam, 0xf8) = x;
    FLD(Ov014CamDa, cam, 0xda).b5 = 1;
}
static inline BOOL Ov014_PlBusy(Ov014Actor *pl) {
    return FLD(Ov014PlB24, pl, 0xb24).b0 ? TRUE : FALSE;
}

extern const Ov014Vec data_ov014_02216600;
extern const Ov014Vec data_ov014_022165f4;
extern void *data_ov014_02216500[];
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *o);
extern void VEC_MultAdd(s32 a, const Ov014Vec *v1, const Ov014Vec *v2, Ov014Vec *out);
extern s32 VEC_Distance(const Ov014Vec *a, const Ov014Vec *b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern void *func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d87d0(void *p, s32 a);
extern s32 func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern void func_ov003_021d6a3c(Ov014Actor *self, s32 a, s32 b, s32 c);
extern BOOL func_ov000_021b4738(Ov014Actor *p);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov003_021dacfc(void *p);

void func_ov014_021ff8f0(Ov014Actor *self) {
    Ov014Vec p = data_ov014_02216600;
    VEC_Add(&p, &self->pos, &p);
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        switch (self->unk_40->state) {
        case 0: {
            Ov014Sub48 *m;
            Ov014Sub44 *n;
            u8 *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(5);
            g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            self->unk_1a = 0xb60;
            self->unk_1c = 0xaaa;
            self->unk_1e = 0x3c;
            self->unk_84 = self->pos;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            break;
        }
        case 1: {
            Ov014Sub40 *s = self->unk_40;
            s->timer++;
            if (s->timer == 50) {
                func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x111, 0);
            } else if (self->unk_40->timer > 50) {
                if (func_ov000_02191120(self->unk_38)) {
                    func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
                    func_ov000_021915a0(self->unk_38);
                    self->unk_40->timer = 0;
                    self->unk_40->state++;
                }
                if (self->unk_40->timer == 0x46) {
                    Ov014V *e;
                    func_02049f44(data_02097e4c, 0x5b, &p, 0);
                    func_02049f44(data_02097e4c, 0x56, &p, 0);
                    e = func_02065f88(0x68, &self->pos);
                    e->v0c(0x4000);
                    e->v34(0x4000, 0, 0);
                    func_ov000_0218996c(10, 0x14);
                }
            }
            break;
        }
        case 2: {
            Ov014Sub40 *s = self->unk_40;
            u16 t;
            s->timer++;
            t = s->timer;
            if (t == 50) {
                func_ov003_021d87d0((u8 *)self + 0x100, 0);
                func_ov003_021d85c8((u8 *)self + 0x100, 0x1e, 0, 0, 0);
            }
            if (t == 100) {
                Ov014Vec q = data_ov014_022165f4;
                u8 *g;
                Ov014V *e;
                VEC_Add(&self->pos, &q, &q);
                self->unk_b8 = q;
                g = (u8 *)data_ov000_021ccd54;
                FLD(u8, g, 0x190) |= 0x1c;
                FLD(u8, g, 0x18d) = 0xf;
                FLD(u8, g, 0x18e) = 0xf;
                FLD(u8, g, 0x18f) = 0xf;
                func_02049f44(data_02097e4c, 0x53, &p, 0);
                e = func_02065f88(0x68, &self->pos);
                e->v0c(0x5000);
                e->v34(0x4000, 0, 0);
                self->unk_40->timer = 50;
                self->unk_40->state++;
            }
            break;
        }
        case 3: {
            Ov014Vec d;
            s32 tx = self->unk_b8.x;
            s32 ty = self->unk_b8.y;
            s32 tz = self->unk_b8.z;
            d.x = tx - self->pos.x;
            d.y = ty - self->pos.y;
            d.z = tz - self->pos.z;
            VEC_MultAdd(0x4cd, &d, &self->pos, &self->pos);
            if (VEC_Distance(&self->pos, &self->unk_b8) < 0x19a) {
                self->unk_40->state++;
            }
            break;
        }
        case 4: {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer) {
                s->timer--;
            }
            if (s->timer == 0) {
                Ov014V *e = func_02065f88(0x2bd, &self->pos);
                e->v24(0, 0, 0x5000);
                e->v0c(0x8000);
                e->v34(0x4000, 0, 0);
                func_02049f44(data_02097e4c, 0x44, &p, 0);
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
                self->unk_40->state++;
            }
            break;
        }
        case 5:
            if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 0)) {
                self->unk_9c = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                self->unk_a0 = 0x29;
                func_ov000_0218996c(0x1e, 0x32);
                self->unk_40->timer = 0x19;
                func_02049f44(data_02097e4c, 0x1b, &p, 0);
                func_02049f44(data_02097e4c, 0x53, &p, 0);
                FLD(u8, self, 0xf9) = 0;
                self->unk_40->state++;
            }
            break;
        case 6: {
            Ov014Sub40 *s;
            func_ov000_0218dbe0(self, 0);
            s = self->unk_40;
            if (s->timer) {
                s->timer--;
            }
            if (s->timer == 0) {
                func_ov000_0218996c(10, 0x1e);
                self->unk_40->timer = 0x19;
                FLD(u8, self, 0xf9)++;
            }
            if (FLD(u8, self, 0xf9) == 7) {
                self->unk_40->state = 0x1e;
            }
            break;
        }
        case 0x1e:
            self->unk_93_4 = 0;
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state++;
            break;
        }
        if (self->unk_40->state < 0x1e) {
            Ov014Actor *pl = func_ov000_0219bf90();
            if (pl != NULL && !Ov014_PlBusy(pl)) {
                u8 *cam = (u8 *)data_ov000_021ccd54 + 0xf4;
                s16 c;
                s16 a;
                s16 b;
                FLD(Ov014Vec, cam, 0xe8) = self->unk_84;
                FLD(Ov014CamDa, cam, 0xda).b1 = 1;
                FLD(s32, cam, 0xf4) = -0x2000;
                FLD(Ov014CamDa, cam, 0xda).b2 = 2;
                c = self->unk_1e;
                a = self->unk_1a;
                b = self->unk_1c;
                if (c <= 0) {
                    if (a > 0) {
                        a = a - 0xb;
                        if (a <= 0) {
                            a = 0;
                        }
                        self->unk_1a = a;
                    }
                    if (b > 0) {
                        b = b - 0xc;
                        if (b <= 0) {
                            b = 0;
                        }
                        self->unk_1c = b;
                    }
                } else {
                    c = c - 1;
                    if (c <= 0) {
                        c = 0;
                    }
                    self->unk_1e = c;
                }
                Ov014Cam_SetY(cam, a + 0x7c71);
                Ov014Cam_SetX(cam, b - 0x4fa);
            }
        }
        break;
    case 1:
        FLD(u16, self, 0xea) |= 0x200;
        switch (self->unk_40->state) {
        case 0: {
            Ov014Sub48 *m = self->unk_48;
            Ov014Sub44 *n;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            func_ov003_021d87d0((u8 *)self + 0x100, 0);
            func_ov003_021d85c8((u8 *)self + 0x100, 0, 0, 1, 0);
            self->unk_40->state++;
        }
        case 1:
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x482b, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x482c, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x580c, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x580d, 0x15);
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x580e, 0x15);
            self->unk_93_4 = 0;
            func_ov003_021d6a3c(self, 0, 1, 1);
            {
            Ov014Actor *pl = func_ov000_0219bf90();
            if (pl != NULL && !func_ov000_021b4738(pl)) {
                func_02049a48(data_02097e4c, 0x38, 0x50, -1, -1);
            }
            }
            self->unk_40->state++;
            break;
        }
        break;
    }
    func_ov003_021dacfc(FLD(void *, self, 0xfc));
}

}
