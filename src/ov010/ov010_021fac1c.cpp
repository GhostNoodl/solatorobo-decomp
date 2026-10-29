#include "ov010/ov010.h"

// Hit message handler (message 9 = damage)
struct Ov010Msg {
    u8 pad[5];
    u8 type;
    u16 a;
    u16 dmg;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern const Ov010Vec data_ov010_0220ed10;
extern BOOL func_ov003_021d1c00(void *self, Ov010Msg *msg);
extern void func_ov003_021cedf4(s32 a);
extern void func_ov003_021d97fc(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern Ov010V *func_020657b0(void *a, s32 b);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);

typedef Ov010Vec (*Ov010PosFn)(void *a);

static inline Ov010Vec Ov010e_AttachPos(void *self) {
    Ov010Vec r;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (self != NULL && (p = FLD(void *, self, 0x44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = FLD(u16, self, 0x7e);
        func_ov003_021d9900(&v, FLD(u16, self, 0x7c), &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&r, &v);
    VEC_Add(&r, &FLD(Ov010Vec, self, 0x70), &r);
    return r;
}

static inline BOOL Ov010e_Invul(void *self) {
    BOOL r = TRUE;
    if (FLD(Ov010Flags, self, 0xea).b13 && FLD(u16 *, self, 0x50)[5] == 0) {
        r = FALSE;
    }
    return r;
}

static inline BOOL Ov010e_Ignore(void *self) {
    BOOL r = TRUE;
    if (!Ov010e_Invul(self) && FLD(u8, FLD(u8 *, self, 0x40), 0x13) != 0x20) {
        r = FALSE;
    }
    return r;
}

static inline void *Ov010e_FindActor(u16 id) {
    void *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return a;
}

static inline Ov010V *Ov010e_Eff(u8 *p) {
    Ov010V *e = NULL;
    if (p != NULL) {
        e = func_020657b0(data_0214a420, FLD(Ov010Flags8, p, 0).b0 ? FLD(s32, p, 0x10) : 0);
    }
    return e;
}

static inline void Ov010e_Spawn(void *self) {
    if (FLD(Ov010Flags8, self, 0x138).b0 && FLD(s32, self, 0x140) == 0) {
        void *a = Ov010e_FindActor(FLD(u16, self, 0x13a));
        if (a != NULL) {
            Ov010V *e;
            Ov010Vec w;
            Ov010Vec u = ((Ov010PosFn)FLD(void *, self, 0x14c))(a);
            w.x = FLD(s32, a, 0x70);
            w.y = FLD(s32, a, 0x74);
            w.z = FLD(s32, a, 0x78);
            VEC_Add(&w, &u, &w);
            e = func_02065f88(FLD(s32, self, 0x144), &w);
            FLD(u8, e, 0xd0) = 1;
            FLD(s32, self, 0x148) = FLD(s32, e, 0x24);
            FLD(u8, self, 0x139) = 0x1f;
            FLD(s32, self, 0x140) = 1;
            FLD(u16, self, 0x13c) = 0;
        }
    }
}

BOOL func_ov010_021fac1c(void *self, Ov010Msg *msg) {
    if (msg->type == 9) {
        if (!Ov010e_Ignore(self)) {
            u16 *c;
            FLD(u16 *, self, 0x50)[2] = msg->a;
            FLD(u16 *, self, 0x50)[5] = 5;
            c = FLD(u16 *, self, 0xf8);
            c[0] = 0;
            c[1]++;
            func_ov003_021cedf4(8);
            c = FLD(u16 *, self, 0xf8);
            if (c[1] >= 0x14) {
                c[0] = 0;
                c[1] = 0;
                func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
                c = FLD(u16 *, self, 0xf8);
                c[0] = 0;
                c[1] = 0;
                if (FLD(Ov010Flags8, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
                    FLD(s32, self, 0x140) = 2;
                    FLD(u16, self, 0x13c) = 0;
                }
                func_ov000_02198360(FLD(void *, self, 0x40), 0x14, 0);
            } else {
                if (c[1] == 0xf) {
                    Ov010e_Spawn(self);
                    Ov010e_Eff((u8 *)self + 0x138)->v0c(0x1800);
                    Ov010Vec p = Ov010e_AttachPos(self);
                    Ov010Vec off = data_ov010_0220ed10;
                    Ov010Vec rr;
                    func_ov003_021d9980(&rr, FLD(u16, self, 0x7e), &off);
                    VEC_Add(&p, &rr, &p);
                    func_02065f88(0x44c, &p)->v0c(0x2000);
                    FLD(s16, self, 0xf2) = 0x800;
                    func_ov003_021d85c8((u8 *)self + 0x150, 10, 0, 0, 0);
                    {
                        u8 *g = data_ov000_021ccd54;
                        g[0x190] |= 0x1c;
                        g[0x18d] = 10;
                        g[0x18e] = 10;
                        g[0x18f] = 10;
                    }
                } else {
                    FLD(s16, self, 0xf2) = 0x500;
                    func_ov003_021d85c8((u8 *)self + 0x150, 7, 0, 0, 0);
                }
                {
                    u16 *hp = FLD(u16 *, self, 0x50);
                    u16 d = msg->dmg;
                    if (d >= hp[0]) {
                        hp[0] = 0;
                    } else {
                        hp[0] -= d;
                    }
                    if (hp[0] == 0) {
                        func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
                    }
                }
                func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
                func_ov000_02191418(FLD(void *, self, 0x38), 5, 0);
            }
        }
        FLD(u32, self, 0x30) |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern Ov010Heap *data_02097dd0;
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov003_021f4340;
extern u16 data_ov003_021f435c;
extern char data_ov010_0220fc0f[];
extern u8 data_ov010_0220ee6c[];
extern u8 data_ov010_0220fcac[];
extern u8 data_ov010_0220fc8c[];
extern u8 data_ov010_0220fc6c[];
extern u8 data_ov010_0220fc50[];
extern u8 data_ov010_0220fc34[];
extern const Ov010Vec data_ov010_0220fa88;
extern const Ov010Vec data_ov010_0220fa94;
extern const Ov010Vec data_ov010_0220ed1c;
extern u8 data_ov010_0220fa2c[];
extern u8 data_ov010_0220ec02[];
extern void func_ov003_021d112c(void *self);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern Ov010Vec func_ov010_021fa7e0(void *a);
extern BOOL func_ov003_021d8198(void *p);
extern int func_ov003_021cf330(void *p, const char *name, u8 v);
extern BOOL func_ov010_022019ac(void *p);
extern BOOL func_ov003_021d8f4c(void *p);
extern void func_ov003_021d95e8(void *p, void *tbl, u16 n);
extern void func_0203f2b8(void *p);
extern BOOL func_ov003_021d8980(void *p);
extern void func_ov003_021d8a30(void *p, u8 id, void *st);
extern void *func_ov010_02200d94(void *p);
extern BOOL func_ov010_02200dcc(void *p, u16 a, u16 b, u8 c, u16 d);
extern void *func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);
extern void *func_ov003_021d8b88(void *p);
extern BOOL func_ov003_021d8c10(void *p);
extern BOOL func_ov003_021cf458(void *p);
extern void *func_ov003_021cf52c(void *g, void *obj, u16 a, u16 b);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(void *u, s32 a, s32 b);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(void *self, const void *a);
extern s32 func_02049afc(void *mgr, s32 v);
extern void func_0204a058(void *mgr, u32 slot, s32 volume, s32 frames);

struct Ov010StBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
};

static inline void *Ov010e_NewVt(u32 size, void *vt) {
    void *o = func_0203dd9c(size);
    if (o != NULL) {
        FLD(void *, o, 0) = vt;
    }
    return o;
}

static inline void *Ov010e_NewC(void) {
    void *o = func_0203dd9c(0x18);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc6c;
        FLD(u8, o, 4) = 0;
        FLD(s32, o, 8) = 0;
        OV010_BLKCPY((u8 *)o + 0xc, &data_ov010_0220fa88);
    }
    return o;
}

static inline void *Ov010e_NewD(void) {
    void *o = func_0203dd9c(0xc);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc50;
        FLD(Ov010StBits, o, 4).b0 = 0;
        FLD(Ov010StBits, o, 4).b1 = 0;
        FLD(Ov010StBits, o, 4).b2 = 0;
        FLD(Ov010StBits, o, 4).b3 = 0;
        FLD(u16, o, 6) = 0;
        FLD(u16, o, 8) = 0;
    }
    return o;
}

static inline void *Ov010e_NewE(void) {
    void *o = func_0203dd9c(0x68);
    if (o != NULL) {
        FLD(void *, o, 0) = data_ov010_0220fc34;
        FLD(u8, o, 4) = 0;
        FLD(u16, o, 6) = 0;
        Ov010Vec t = data_ov010_0220ec20;
        FLD(Ov010Blk12, o, 8) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x14) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x20) = *(Ov010Blk12 *)&t;
        FLD(Ov010Blk12, o, 0x2c) = *(Ov010Blk12 *)&t;
        func_ov000_02198328((u8 *)o + 0x38);
        func_ov003_021da48c((u8 *)o + 0x38, 0);
    }
    return o;
}

static inline void Ov010e_StartE(u8 *o) {
    if (FLD(u8, o, 4) == 0) {
        FLD(u8, o, 4) = 1;
        OV010_BLKCPY(o + 0x4c, &data_ov010_0220fa94);
        FLD(s16, o, 0x58) = FLD(s16, data_ov010_0220fa2c, 0x74);
        FLD(s16, o, 0x5a) = FLD(s16, data_ov010_0220fa2c, 0x76);
        FLD(u16, o, 0x5c) = FLD(u16, data_ov010_0220fa2c, 0x78);
        FLD(s16, o, 0x5e) = FLD(s16, data_ov010_0220fa2c, 0x7a);
        FLD(s16, o, 0x60) = FLD(s16, data_ov010_0220fa2c, 0x7c);
        FLD(s16, o, 0x62) = FLD(s16, data_ov010_0220fa2c, 0x7e);
        FLD(s16, o, 0x64) = FLD(s16, data_ov010_0220fa2c, 0x80);
        FLD(s16, o, 0x66) = FLD(s16, data_ov010_0220fa2c, 0x82);
        func_ov003_021da48c(o + 0x38, 0);
    }
}

void func_ov010_021fb018(void *self) {
    u32 saved;
    void *o;
    u16 k;
    func_ov003_021d112c(self);
    func_ov003_021cf404(1);
    func_ov003_021cf400(1);
    FLD(Ov010Flags8, self, 0xf0).b2 = 1;
    FLD(Ov010Flags8, self, 0x138).b0 = 1;
    FLD(Ov010Flags8, self, 0x138).b1 = 0;
    FLD(s32, self, 0x144) = 0x322;
    FLD(void *, self, 0x14c) = (void *)func_ov010_021fa7e0;
    FLD(u8, self, 0x139) = 0x1f;
    FLD(u16, self, 0x13a) = FLD(u16, self, 0xc);
    FLD(u16, self, 0x13c) = 0;
    FLD(s32, self, 0x140) = 0;
    FLD(s32, self, 0x148) = 0;
    func_ov003_021d8198((u8 *)self + 0x150);
    func_ov003_021cf330((u8 *)self + 0x19c, data_ov010_0220fc0f, data_ov003_021f4340);
    func_ov010_022019ac((u8 *)self + 0x17c);
    func_ov003_021d8f4c((u8 *)self + 0x1ac);
    func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220ee6c, 0x2a);
    {
        u8 *p = FLD(u8 *, self, 0x44);
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0x61b2;
        FLD(s32, p, 0x14) = 0x24d5;
    }
    FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b4 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x48) != NULL) {
        void *q = FLD(void *, self, 0x48);
        if (q != NULL) {
            func_0203f2b8(q);
            func_0203de1c(q);
        }
        FLD(void *, self, 0x48) = NULL;
    }
    data_02097dd0->cur = saved;
    {
        u16 *c = (u16 *)func_0203dd9c(4);
        FLD(u16 *, self, 0xf8) = c;
        c[0] = 0;
        c[1] = 0;
    }
    FLD(void *, self, 0x110) = Ov010e_NewVt(8, data_ov010_0220fcac);
    FLD(void *, self, 0x114) = Ov010e_NewVt(8, data_ov010_0220fc8c);
    FLD(void *, self, 0x118) = Ov010e_NewC();
    func_ov003_021d8980((u8 *)self + 0x1c0);
    func_ov003_021d8a30((u8 *)self + 0x1c0, 1, FLD(void *, self, 0x110));
    func_ov003_021d8a30((u8 *)self + 0x1c0, 2, FLD(void *, self, 0x114));
    func_ov003_021d8a30((u8 *)self + 0x1c0, 3, FLD(void *, self, 0x118));
    o = func_0203dd9c(0x40);
    if (o != NULL) {
        o = func_ov010_02200d94(o);
    }
    FLD(void *, self, 0x100) = o;
    func_ov010_02200dcc(FLD(void *, self, 0x100), FLD(u16, self, 0xc), 0x78, 0x30, 2);
    FLD(void *, self, 0x108) = Ov010e_NewD();
    o = Ov010e_NewE();
    FLD(void *, self, 0x104) = o;
    Ov010e_StartE((u8 *)o);
    o = func_0203dd9c(0x20);
    if (o != NULL) {
        o = func_ov003_021d8b88(o);
    }
    FLD(void *, self, 0x10c) = o;
    func_ov003_021d8c10(o);
    func_ov003_021cf458((u8 *)self + 0x1d0);
    k = data_ov003_021f435c;
    func_ov003_021cf52c((u8 *)self + 0x1d0, FLD(void *, self, 0x104), k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, FLD(void *, self, 0x108), k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, FLD(void *, self, 0x10c), k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x150, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x17c, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x19c, k, k);
    func_ov003_021cf52c((u8 *)self + 0x1d0, (u8 *)self + 0x1c0, k, k);
    {
        u8 *u = func_ov000_0218bd5c(data_ov000_021ccd64, FLD(u16, self, 0x20));
        if (u != NULL) {
            func_ov000_0218b700(u, 0x3000, 0);
        }
    }
    FLD(s32, self, 0xc4) = 0;
    FLD(Ov010Flags8, self, 0x93).b4 = 1;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov010_0220ec02);
    }
    switch (FLD(s16, self, 0x18)) {
    case 0:
        FLD(Ov010Flags8, self, 0xf0).b2 = 0;
        FLD(s32, self, 0x11c) = func_02049afc(data_02097e4c, 0x4e);
        func_0204a058(data_02097e4c, FLD(s32, self, 0x11c), 0x78, 0);
        func_0204a058(data_02097e4c, FLD(s32, self, 0x11c), 0x28, 0x258);
        break;
    case 1:
        func_ov000_02198360(FLD(void *, self, 0x40), 0x2c, 0);
        func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
        FLD(Ov010Flags8, self, 0xf0).b2 = 0;
        break;
    case 2: {
        Ov010Vec v = data_ov010_0220ed1c;
        FLD(s32, self, 0x70) = v.x;
        FLD(s32, self, 0x74) = v.y;
        FLD(s32, self, 0x78) = v.z;
        FLD(u16, self, 0x7c) = 0;
        FLD(u16, self, 0x7e) = 0xbfff;
        FLD(u16, self, 0x80) = 0;
        FLD(Ov010Flags8, self, 0xf0).b2 = 1;
        break;
    }
    }
}

}
