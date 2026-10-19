#include "ov013/ov013.h"

extern "C" {
extern Ov013Game54 *data_ov000_021ccd54;
extern Ov013Actor *func_ov000_0219bf90(void);
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af34;
extern const Ov013Vec data_ov013_0220af7c;
extern const Ov013Vec data_ov013_0220af88;
extern Ov013Actor *func_ov003_021da32c(s32 id);
extern void *func_0206fef8(u16 id);
extern Ov013V *func_02066774(const void *a, const void *b, s32 c, Ov013Vec *pos);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov013_02205bec(Ov013Actor *a, Ov013Vec *v, u16 id, u16 plid, u16 r, u16 rot);
extern u32 func_ov013_02205c64(Ov013Actor *self);
extern s32 func_ov003_021d9a80(const Ov013Vec *a, const Ov013Vec *b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void func_ov003_021d88ec(u32 *p);
extern void func_ov003_021d8b60(void *sm, void *arg);
extern void func_ov003_021d969c(void *p, s32 a);

struct Ov013Opt120b {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

static inline void Ov013b_PathTarget(Ov013Actor *self, const Ov013Vec &v) {
    Ov013Opt120b *p = FLD(Ov013Opt120b *, self, 0x120);
    if (p->b0) {
        p->w = v;
    }
}

static inline void Ov013b_PathSpeed(Ov013Actor *self, s16 sp) {
    Ov013Opt120b *p = FLD(Ov013Opt120b *, self, 0x120);
    if (p->b0) {
        p->unk_02 = sp;
    }
}

static inline Ov013Vec Ov013b_FrontPos(Ov013Actor *self, const Ov013Vec *off) {
    Ov013Vec v;
    func_ov003_021d9980(&v, self->rot[1], off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

static inline Ov013Vec Ov013b_Lift(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x900);
    return v;
}

static inline void Ov013b_Set84(Ov013Actor *self, const Ov013Vec &v) {
    self->unk_84.x = v.x;
    self->unk_84.y = v.y;
    self->unk_84.z = v.z;
}

static inline void Ov013b_Place(Ov013Actor *self, Ov013Actor *o, Ov013Actor *pl, s32 x, u16 dr) {
    u16 rot = self->rot[1];
    Ov013Vec v;
    u16 r;
    v.x = x;
    v.y = 0x4cd;
    v.z = 0;
    r = rot + dr;
    func_ov003_021d9980(&v, self->rot[1], &v);
    VEC_Add(&v, &self->pos, &v);
    func_ov013_02205bec(o, &v, self->id, pl->id, r, self->rot[1]);
}

static inline Ov013Actor *Ov013b_Find(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov013b_PartSet(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = 1;
    }
}

static inline void Ov013b_PartClr(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b3 = 0;
    }
}

static inline void Ov013b_PartB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline void Ov013b_PartsSet(void *m) {
    if (m != NULL) {
        Ov013b_PartSet(m, 0);
        Ov013b_PartSet(m, 1);
        Ov013b_PartSet(m, 3);
        Ov013b_PartSet(m, 4);
    }
}

static inline void Ov013b_PartsClr(void *m) {
    if (m != NULL) {
        Ov013b_PartClr(m, 0);
        Ov013b_PartClr(m, 1);
        Ov013b_PartClr(m, 3);
        Ov013b_PartClr(m, 4);
    }
}

static inline void Ov013b_Fade(void) {
    u8 *g = (u8 *)data_ov000_021ccd54;
    FLD(Ov013Flags8, g, 0x190).b2 = 1;
    FLD(Ov013Flags8, g, 0x190).b3 = 1;
    FLD(Ov013Flags8, g, 0x190).b4 = 1;
    g[0x18d] = 10;
    g[0x18e] = 0xf;
    g[0x18f] = 0xf;
}

static inline void Ov013b_Link(Ov013Actor *self, u16 *out, s32 kind) {
    Ov013Actor *o = func_ov003_021da32c(kind);
    FLD(Ov013Flags8, o, 0x16).b0 = 1;
    o->unk_90 = func_ov000_0219bf90()->id;
    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    o->rot[1] = self->rot[1];
    *out = o->id;
}

void func_ov013_022001e4(Ov013Actor *self) {
    Ov013Actor *a = NULL;
    Ov013Actor *b = NULL;
    s32 zone = 0;
    BOOL move = FALSE;
    BOOL path = TRUE;
    FLD(Ov013Flags8, self, 0xf0).b2 = 1;
    FLD(Ov013Flags8, self, 0xf0).b4 = 0;
    switch (self->unk_40->state) {
    case 0: {
        void *info;
        s32 k;
        Ov013V *o;
        void *m;
        move = TRUE;
        FLD(Ov013Flags8, self, 0xf0).b3 = 1;
        Ov013b_Link(self, &FLD(u16, self, 0xf4), 0x4808);
        Ov013b_Link(self, &FLD(u16, self, 0xf6), 0x4809);
        self->unk_a8 = 0x60;
        self->unk_a0 = 0x800;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        Ov013b_Set84(self, Ov013b_Lift(k));
        o = func_02066774(FLD(void *, data_ov013_0220aedc, 8), FLD(void *, data_ov013_0220aedc, 0xc), 0, &self->pos);
        FLD(u8, o, 0x28) = 0;
        o->v10(&data_ov013_0220af7c);
        self->rot[0] = 0;
        Ov013b_Fade();
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x2c), 0x1000, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        self->unk_40->state = 0xa;
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3c, &self->pos, -5);
        break;
    }
    case 0xa:
        move = TRUE;
        if (self->unk_a0 < 0) {
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        a = Ov013b_Find(FLD(u16, self, 0xf4));
        b = Ov013b_Find(FLD(u16, self, 0xf6));
        if (a == NULL || b == NULL) {
            self->unk_40->state = 0x50;
        } else if (a != NULL && b != NULL && FLD(u8, a, 0x14) == 2 && FLD(u8, b, 0x14) == 2) {
            self->unk_40->state = 0x28;
        }
        break;
    }
    case 0x28:
        Ov013b_PartsClr(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x29;
        func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
        break;
    case 0x29:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            Ov013Actor *pl;
            a = Ov013b_Find(FLD(u16, self, 0xf4));
            b = Ov013b_Find(FLD(u16, self, 0xf6));
            pl = func_ov000_0219bf90();
            if (a == NULL || b == NULL || pl == NULL) {
                self->unk_40->state = 0x50;
            } else {
                Ov013Vec v;
                u16 r;
                r = self->rot[1] + 0xbfff;
                v.x = -0x14d1;
                v.y = 0x4cd;
                v.z = 0;
                func_ov003_021d9980(&v, self->rot[1], &v);
                VEC_Add(&v, &self->pos, &v);
                func_ov013_02205bec(a, &v, self->id, pl->id, r, self->rot[1]);
                r = self->rot[1] + 0x4000;
                v.y = 0x4cd;
                v.x = 0x14d1;
                v.z = 0;
                func_ov003_021d9980(&v, self->rot[1], &v);
                VEC_Add(&v, &self->pos, &v);
                func_ov013_02205bec(b, &v, self->id, pl->id, r, self->rot[1]);
            }
            func_0204a028(data_02097e4c, 0x32, &self->pos, 10);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 3) {
            Ov013b_PartsSet(self->unk_38);
            self->unk_40->state = 0x32;
        }
        break;
    case 0x32: {
        a = Ov013b_Find(FLD(u16, self, 0xf4));
        b = Ov013b_Find(FLD(u16, self, 0xf6));
        if (a != NULL && func_ov013_02205c64(a)) {
            Ov013Vec p;
            p.x = a->pos.x;
            p.y = a->pos.y;
            p.z = a->pos.z;
            if (func_ov003_021d9a80(&self->pos, &p) < 0x9000) {
                a->v08();
                FLD(u16, self, 0xf4) = 0xffff;
            }
        }
        if (b != NULL && func_ov013_02205c64(b)) {
            Ov013Vec p;
            p.x = b->pos.x;
            p.y = b->pos.y;
            p.z = b->pos.z;
            if (func_ov003_021d9a80(&self->pos, &p) < 0x9000) {
                b->v08();
                FLD(u16, self, 0xf6) = 0xffff;
            }
        }
        if (a == NULL && b == NULL) {
            func_0204a028(data_02097e4c, 0x66, &self->pos, -5);
            self->unk_40->state = 0x3c;
        }
        break;
    }
    case 0x3c:
        move = TRUE;
        Ov013b_PartsClr(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0x4cd;
        self->unk_a4 = 0x1000;
        self->unk_a8 = 0x19a;
        self->unk_40->state = 0x3d;
        break;
    case 0x3d: {
        move = TRUE;
        if (self->pos.y > 0x2000) {
            zone = 0;
        } else if (self->pos.y <= 0x2000 && self->pos.y > 0) {
            zone = 1;
        } else {
            zone = 2;
        }
        if (zone == 1) {
            self->unk_40->state = 0x46;
        } else if (FLD(s16, self->unk_38, 0xc4) == 4) {
            Ov013b_PartsSet(self->unk_38);
        }
        break;
    }
    case 0x46: {
        path = FALSE;
        Ov013b_PartsClr(self->unk_38);
        Ov013b_Fade();
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x47;
        {
            Ov013Vec t = Ov013b_FrontPos(self, &data_ov013_0220af34);
            Ov013V *o = func_02066774(FLD(void *, data_ov013_0220aedc, 8), FLD(void *, data_ov013_0220aedc, 0xc), 0, &t);
            FLD(u8, o, 0x28) = 0;
            o->v10(&data_ov013_0220af88);
        }
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3d, &self->pos, -5);
        break;
    }
    case 0x47:
        path = FALSE;
        self->unk_40->timer++;
        if (self->unk_40->timer > 0x14 && func_ov000_02191120(self->unk_38)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x50;
            break;
        }
        if (self->unk_40->timer > 10) {
            Ov013b_PathTarget(self, FLD(Ov013Vec, data_ov013_0220aedc, 0x4c));
            Ov013b_PathSpeed(self, 0x180);
        } else {
            Ov013b_PathTarget(self, self->unk_84);
            Ov013b_PathSpeed(self, 0x140);
        }
        break;
    case 0x50: {
        void *m;
        const char *name;
        path = FALSE;
        FLD(Ov013Flags8, self, 0xf0).b4 = 1;
        FLD(u16, self, 0xf4) = 0xffff;
        FLD(u16, self, 0xf6) = 0xffff;
        name = FLD(const char *, data_ov013_0220aedc, 4);
        func_ov000_02190cb0(self->unk_38, name, 0x800, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), name, 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013b_PartB2(m, 0);
            Ov013b_PartB2(m, 1);
            Ov013b_PartB2(m, 3);
            Ov013b_PartB2(m, 4);
        }
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
    if (move) {
        func_ov000_0218dbe0(self, 0);
    }
    if (path) {
        u32 cmd[4];
        func_ov003_021d88ec(cmd);
        cmd[0] = 0x2800;
        func_ov003_021d8b60((u8 *)self + 0x12c, cmd);
    }
}



extern void *data_02097e4c;
extern const Ov013Vec data_ov013_0220af34;
extern u8 data_ov013_0220b090[];
extern u8 data_ov013_0220b0cc[];
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov013_02203494(Ov013Actor *self, BOOL a, BOOL b, s32 c, void *d);
extern void func_ov003_021d64f0(Ov013Actor *self);

static inline Ov013V *Ov013_SpawnFx(s32 id, const Ov013Vec &pos) {
    return func_02065f88(id, (Ov013Vec *)&pos);
}

static inline Ov013Vec Ov013_FrontPos(Ov013Actor *self, const Ov013Vec *off) {
    Ov013Vec v;
    func_ov003_021d9980(&v, self->rot[1], off);
    VEC_Add(&v, &self->pos, &v);
    return v;
}

void func_ov013_02200fe8(Ov013Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02191418(self->unk_38, 0x28, 1);
    Ov013_SpawnFx(0x196, Ov013_FrontPos(self, &data_ov013_0220af34))->v0c(0x2000);
    func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
    func_02049f44(data_02097e4c, 0x36, &self->pos, 0);
    self->unk_40->state++;
}

void func_ov013_022010b8(Ov013Actor *self) {
    s32 c = 0;
    BOOL a = TRUE;
    BOOL b = TRUE;
    void *d = NULL;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        d = data_ov013_0220b090;
        break;
    case 2:
        b = FALSE;
        d = data_ov013_0220b090;
        break;
    case 3:
        a = FALSE;
        d = data_ov013_0220b090;
        break;
    case 4:
        b = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 5:
        a = FALSE;
        c = 0xd00;
        d = data_ov013_0220b0cc;
        break;
    case 6:
        d = data_ov013_0220b0cc;
        c = 0xd00;
        break;
    }
    func_ov013_02203494(self, a, b, c, d);
}

void func_ov013_02201144(Ov013Actor *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->unk_18) {
    case 0:
        func_ov003_021d64f0(self);
        break;
    case 1: {
        Ov013Sub40 *s = self->unk_40;
        if (s->state == 0) {
            self->pos.x = -0x212b;
            self->pos.y = 0x2000;
            self->pos.z = -0xb3a2;
            self->rot[1] = 0;
            s->state++;
        } else {
            s->timer++;
            if (self->unk_40->timer > 0x1e) {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
    }
}


struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af88;
extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b150[];
extern u8 data_ov013_0220b218[];
extern void func_ov003_021d969c(void *p, s32 a);
extern void func_ov003_021d97fc(void *p, s32 a);
extern void *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern Ov013Actor *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 func_02040528(s32 max);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_02049bdc(void *a, s32 b, s32 c);
extern BOOL func_ov000_0218fd84(void *a);
extern BOOL func_ov000_02191508(void *m);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern Ov013V *func_02066774(const void *a, const void *b, s32 c, Ov013Vec *pos);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern void *func_0206fef8(u16 id);
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);

static inline Ov013Vec Ov013_MakeVec(s32 x, s32 y, s32 z) {
    Ov013Vec v;
    Ov013_VecSet(&v, x, y, z);
    return v;
}

static inline Ov013Vec Ov013_Lift(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x600);
    return v;
}

static inline void Ov013_PathTarget(Ov013Actor *self, const Ov013Vec &v) {
    Ov013Opt120 *p = FLD(Ov013Opt120 *, self, 0x120);
    if (p->b0) {
        p->w = v;
    }
}

static inline void Ov013_PathSpeed(Ov013Actor *self, s16 sp) {
    Ov013Opt120 *p = FLD(Ov013Opt120 *, self, 0x120);
    if (p->b0) {
        p->unk_02 = sp;
    }
}

void func_ov013_022011ec(Ov013Actor *self) {
    self->unk_48->unk_9a_4 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        u16 ang;
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
        func_ov003_021d97fc((u8 *)self + 0x14c, 1);
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x24), 0x800, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        func_ov000_02191418(self->unk_38, 5, 1);
        if (FLD(void *, self, 0x50) != NULL) {
            Ov013Actor *a = func_ov000_02199f60(FLD(void *, self, 0x50));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot[1];
            }
        } else {
            ang = self->rot[1];
        }
        FLD(u16, self, 0x96) = ang;
        self->unk_98 = FLD(u16, self, 0x96) + 0x8000 + func_02040528(0x2000);
        self->rot[1] = func_01ffc128(FLD(u16, self, 0x96), self->rot[1], 0x8cd, 1, 0x8000);
        self->unk_9c = 0x27b;
        self->unk_a0 = 0x39a;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4808, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4809, 0x15);
        func_02049bdc(data_02097e4c, 0x41, 4);
        if (self->pos.y - 0x2000 > 0x2000) {
            self->unk_40->state = 0x14;
        } else {
            self->unk_40->state = 0xa;
        }
        break;
    }
    case 0xa:
        if (self->unk_48->unk_50 & 0x20000000) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            if (func_ov000_0218fd84(func_ov000_02190a30(self->unk_38, 0))) {
                self->unk_40->state = 0x64;
            }
            break;
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        break;
    case 0x14:
        if (self->unk_48->unk_50 & 0x20000000) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state = 0x1e;
            break;
        }
        if (!func_ov000_02191508(self->unk_38)) {
            func_ov000_0218dbe0(self, 0);
        }
        break;
    case 0x1e: {
        Ov013Vec t = Ov013_FrontPos(self, &data_ov013_0220af34);
        Ov013V *o;
        void *info;
        s32 k;
        o = func_02066774(FLD(void *, data_ov013_0220aedc, 8), FLD(void *, data_ov013_0220aedc, 0xc), 0, &t);
        FLD(u8, o, 0x28) = 0;
        o->v10(&data_ov013_0220af88);
        func_0204a028(data_02097e4c, 0x3e, &self->pos, 5);
        func_0204a028(data_02097e4c, 0x3d, &self->pos, -5);
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            Ov013Vec w2 = Ov013_Lift(k);
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
        }
        self->unk_40->state = 0x1f;
    }
    case 0x1f:
        self->unk_40->timer++;
        if (self->unk_40->timer > 0xf && func_ov000_02191120(self->unk_38)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x64;
            break;
        }
        if (self->unk_40->timer > 6) {
            Ov013_PathTarget(self, FLD(Ov013Vec, data_ov013_0220aedc, 0x4c));
            Ov013_PathSpeed(self, 0x280);
        } else {
            Ov013_PathTarget(self, self->unk_84);
            Ov013_PathSpeed(self, 0x240);
        }
        break;
    case 0x64: {
        s32 r = (self->unk_50[0] << 12) / self->unk_50[1];
        if (r <= 0x666) {
            if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b218) || func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b150)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b108, 0xc);
            } else if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b03a)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b064, 7);
            }
        } else if (r <= 0xccd) {
            if (func_ov003_021d984c((u8 *)self + 0x14c, data_ov013_0220b150)) {
                func_ov003_021d95e8((u8 *)self + 0x14c, data_ov013_0220b218, 0x14);
            }
        }
        func_ov003_021d97fc((u8 *)self + 0x14c, 0);
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

extern void *data_0214a420;
extern void func_02065804(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern void func_0203f364(Ov013Sub48 *p);
extern Ov013Vec func_ov003_021da214(Ov013Actor *self);
extern void func_ov003_021da4a8(Ov013Vec *pos, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov013Actor *self, u8 a);

#define OV013_CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : ((x) < (lo) ? (lo) : (x)))

void func_ov013_022017f8(Ov013Actor *self) {
    self->unk_48->unk_9a_4 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013Sub48 *m48;
        Ov013Sub44 *n;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x24), 0x800, 1);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        func_ov000_02191418(self->unk_38, 5, 1);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x483e, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4808, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4809, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4807, 0x15);
        func_02065804(data_0214a420, FLD(s32, self, 0x100));
        self->unk_50[0] = 0;
        m48 = self->unk_48;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        self->unk_9c = 0x27b;
        self->unk_a0 = 0x39a;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        if (FLD(void *, self, 0x50) != NULL) {
            Ov013Actor *a = func_ov000_02199f60(FLD(void *, self, 0x50));
            if (a != NULL && a != self) {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            } else {
                ang = self->rot[1];
            }
        } else {
            ang = self->rot[1];
        }
        FLD(u16, self, 0x96) = ang;
        self->unk_98 = FLD(u16, self, 0x96) + 0x8000 + func_02040528(0x2000);
        self->unk_9c = 0x27b;
        self->unk_a0 = 0;
        self->unk_a4 = 0xcb8;
        self->unk_a8 = 0x52;
        self->unk_40->state = 0xa;
        break;
    }
    case 0xa:
        if (self->unk_48->unk_50 & 0x20000000) {
            Ov013Vec p = func_ov003_021da214(self);
            Ov013V *o = func_02065f88(0x390, &self->pos);
            if (o != NULL) {
                FLD(s32, self, 0x100) = FLD(s32, o, 0x24);
                o->v20(&p);
                o->v0c(0x1800);
            }
            o = func_02065f88(0x69, &self->pos);
            if (o != NULL) {
                o->v20(&p);
                o->v0c(0x5000);
            }
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_ov000_0218996c(0xc, 0x28);
            self->unk_40->state = 0x14;
        }
    case 0x14: {
        Ov013Sub40 *q = self->unk_40;
        u16 t;
        q->timer++;
        t = q->timer;
        if (t >= 0x78) {
            if (t % 30 == 0) {
                Ov013Vec a = func_ov003_021da214(self);
                Ov013Vec b;
                VEC_Add(&self->pos, &a, &b);
                func_ov003_021da4a8(&b, self->unk_64, 0x38b);
                func_ov000_0218996c(8, 8);
                func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
            }
            if (t >= 0x12b) {
                func_ov000_0218996c(0x14, 0x78);
                self->unk_40->timer = 0;
                self->unk_40->state = 0x1e;
            }
        } else {
            if (t % 25 == 0) {
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
            if (t == 0x6e) {
                func_02065860(data_0214a420, FLD(s32, self, 0x100));
                FLD(s32, self, 0x100) = 0;
            }
        }
        break;
    }
    case 0x1e: {
        Ov013Vec p = func_ov003_021da214(self);
        Ov013V *o = func_02065f88(0x38b, &self->pos);
        if (o != NULL) {
            o->v20(&p);
            o->v0c(0x3000);
        }
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->v20(&p);
            o->v0c(0x5000);
            FLD(s32, o, 0x3c) = 0xccd;
        }
        func_0204a028(data_02097e4c, 0x56, &self->pos, -8);
        func_0204a028(data_02097e4c, 0x41, &self->pos, 4);
        self->unk_40->state = 0x64;
        break;
    }
    case 0x64:
        FLD(Ov013Flags8, self, 0xf0).b2 = 1;
        {
            Ov013Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer > 0x78) {
                func_ov003_021d6a3c(self, 1, 1, 1);
                break;
            }
        }
        {
            s32 a = 0x1f - (self->unk_40->timer >> 1);
            func_ov003_021d6954(self, OV013_CLAMP(a, 1, 0x1f));
        }
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    if (self->unk_48->unk_50 & 0x20000000) {
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    } else {
        func_ov000_0218dbe0(self, 0);
    }
}

struct Ov013Obj1c;
typedef void (*Ov013OffFn)(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);

struct Ov013Obj1c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    u32 unk_04;
    Ov013Vec v;
    Ov013Actor *unk_14;
    Ov013OffFn unk_18;
};

extern void func_ov013_02204428(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);
extern void func_ov013_02204408(Ov013Vec *out, Ov013Vec *v, Ov013Actor *a);
extern BOOL func_ov003_021d9edc(u16 kind);
extern void func_ov003_021d96e0(void *p);
extern s32 func_ov013_021fe9f8(Ov013Actor **out, s32 max, u16 kind, Ov013Vec *pos, s32 dist);
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013V *func_020657b0(void *a, s32 b);

static inline void Ov013_PartFlagB2(void *m, s32 i) {
    if (func_ov000_02190a30(m, i) != NULL) {
        FLD(Ov013Flags8, func_ov000_02190a30(m, i), 0x111).b2 = 1;
    }
}

static inline Ov013Vec Ov013_Lift2(s32 h) {
    Ov013Vec v = {0, 0, 0};
    v.y = -Ov013_FxMul(h, 0x480);
    return v;
}

struct Ov013ObjHdr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};
static inline BOOL Ov013Obj_IsIdle2(const Ov013ObjHdr &h) {
    BOOL r = TRUE;
    if (h.b0 && h.b1) {
        r = FALSE;
    }
    return r;
}
static inline BOOL Ov013Obj_IsIdle(Ov013Obj1c *q) {
    return Ov013Obj_IsIdle2(*(Ov013ObjHdr *)q);
}

static inline void Ov013Obj_SetSpeed(Ov013Obj1c *q, s16 sp) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->unk_02 = sp;
    }
}
static inline void Ov013Obj_SetVec(Ov013Obj1c *q, s32 x, s32 y, s32 z) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->v.x = x;
        q->v.y = y;
        q->v.z = z;
    }
}
static inline void Ov013Obj_SetFn(Ov013Obj1c *q, Ov013OffFn fn) {
    if (q->b0 && !Ov013Obj_IsIdle(q)) {
        q->unk_18 = fn;
    }
}

static inline void Ov013Obj_Start(Ov013Obj1c *q, Ov013Actor *owner, s16 sp, const Ov013Vec *v, Ov013OffFn fn) {
    if (q->b0 && !q->b1) {
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = sp;
        q->unk_04 = 0;
        q->v.x = v->x;
        q->v.y = v->y;
        q->v.z = v->z;
        q->unk_18 = fn;
        q->b0 = 1;
        q->b1 = 1;
        q->unk_14 = owner;
    }
}

static inline s32 Ov013_Mode(Ov013Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

static inline BOOL Ov013_IsMarked(Ov013Actor *a) {
    if (a == NULL) {
        return FALSE;
    }
    if (a->kind != 0x483e) {
        return FALSE;
    }
    if (Ov013_Mode(a) != 0xb) {
        return FALSE;
    }
    if (func_ov000_0219bf90() == NULL) {
        return FALSE;
    }
    u16 id = func_ov000_0219bf90()->id;
    if (id != FLD(u16, FLD(void *, a, 0x4c), 0x1c)) {
        return FALSE;
    }
    return TRUE;
}

void func_ov013_02201de8(Ov013Actor *self) {
    Ov013Actor *list[8];
    FLD(Ov013Flags8, self, 0xf0).b2 = 1;
    switch (self->unk_40->state) {
    case 0: {
        void *m;
        Ov013Obj1c *q;
        Ov013V *o;
        void *info;
        s32 k;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov013_0220aedc, 0x34), 0x266, 0);
        m = self->unk_38;
        if (FLD(void *, m, 0x14) != NULL) {
            void *p = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x14), (u8 *)m + 0x24, p, FLD(void *, FLD(void *, p, 0x48), 8), FLD(const char *, data_ov013_0220aedc, 4), 0x1000, 0);
        }
        FLD(Ov013Flags8, func_ov000_02190a30(self->unk_38, 2), 0x111).b2 = 1;
        m = self->unk_38;
        if (m != NULL) {
            Ov013_PartFlagB2(m, 0);
            Ov013_PartFlagB2(m, 1);
            Ov013_PartFlagB2(m, 3);
            Ov013_PartFlagB2(m, 4);
        }
        Ov013Obj_Start(FLD(Ov013Obj1c *, self, 0x124), self, 0x1000, &FLD(Ov013Vec, data_ov013_0220aedc, 0x4c), func_ov013_02204428);
        Ov013Obj_SetSpeed(FLD(Ov013Obj1c *, self, 0x124), 0x3000);
        Ov013Obj_SetVec(FLD(Ov013Obj1c *, self, 0x124), 0, 0, -0x3000);
        Ov013Obj_SetFn(FLD(Ov013Obj1c *, self, 0x124), func_ov013_02204408);
        self->rot[0] = 0;
        self->rot[2] = 0;
        func_0204a028(data_02097e4c, 0x44, &self->pos, 3);
        o = func_02065f88(0x69, &self->pos);
        o->v0c(0x2000);
        func_02065804(data_0214a420, FLD(s32, self, 0x100));
        FLD(s32, self, 0x100) = FLD(s32, o, 0x24);
        info = func_0206fef8(self->kind);
        k = Ov013_FxMul(FLD(s16, info, 0x16) << 4, FLD(s16, info, 0x10));
        {
            Ov013Vec w2 = Ov013_Lift2(k);
            Ov013Sub48 *m48;
            self->unk_84.x = w2.x;
            self->unk_84.y = w2.y;
            self->unk_84.z = w2.z;
            m48 = self->unk_48;
            m48->unk_9a_0 = 0;
            m48->unk_9a_3 = 0;
            func_0203f364(m48);
        }
        self->unk_40->state = 1;
    }
    case 1: {
        s32 n;
        s32 i;
        BOOL found;
        Ov013V *p;
        if (!func_ov003_021d9edc(0x483e)) {
            func_ov003_021d96e0((u8 *)self + 0x14c);
            self->unk_40->state = 2;
            break;
        }
        n = func_ov013_021fe9f8(list, 8, 0x483e, &self->pos, Ov013_FxMul(self->unk_64, FLD(s32, self->unk_38, 0xa8)) / 2 + 0x5000);
        found = FALSE;
        for (i = 0; i < n; i++) {
            if (Ov013_IsMarked(list[i])) {
                found = TRUE;
                break;
            }
        }
        if (found) {
            func_ov003_021d97fc((u8 *)self + 0x14c, 1);
            func_ov003_021d96e0((u8 *)self + 0x14c);
            func_ov000_02198360(self->unk_40, 0x31, 1);
        }
        p = func_020657b0(data_0214a420, FLD(s32, self, 0x100));
        if (p == NULL) {
            FLD(s32, self, 0x100) = 0;
        } else {
            p->v34(FLD(u16, p, 0x64), (u16)(FLD(u16, p, 0x66) + 0x400), FLD(u16, p, 0x68));
        }
        break;
    }
    }
    FLD(Ov013Flags8, self, 0xf0).b1 = 1;
    Ov013_PathSpeed(self, 0x100);
    Ov013_PathTarget(self, self->unk_84);
}
}
