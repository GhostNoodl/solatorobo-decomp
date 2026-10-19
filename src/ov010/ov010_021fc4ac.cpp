#include "ov010/ov010.h"

extern "C" {

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

extern void *data_ov010_0220ebc0[];
extern const Ov010Vec data_ov010_0220ec14;
extern const Ov010Vec data_ov010_0220ec2c;
extern const Ov010Vec data_ov010_0220ecd4;
extern const Ov010Vec data_ov010_0220ed04;
extern const Ov010Vec data_ov010_0220ec38;
extern const Ov010Vec data_ov010_0220fa64;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov010_02201b48(void *p);
extern void *func_ov000_0219bf90(void);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov010_02201ad4(void *p, void *fn, u32 time);
extern void *func_ov010_02201f18(void);
extern void func_ov010_02202074(void *t, u16 a, u16 id, const Ov010Vec *v0, const Ov010Vec *v1);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern s32 VEC_Mag(const Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern Ov010V *func_ov010_02203ee0(s32 a, void *b);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d9b8c(Ov010Vec *out, const Ov010Vec *in, s32 max, s32 sub);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);
extern void func_ov010_02201bf4(void *p);
extern BOOL func_ov010_02201c34(void *p);
extern void func_ov003_021d969c(void *p, s32 a);

extern char data_ov010_0220fc13[];
extern void *data_ov000_021ccd68;
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern Ov010V *func_ov003_021da788(s32 id, void *self, Ov010Vec *ofs);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov010_022016a0(void *p, Ov010Vec *a, Ov010Vec *b, s32 c);
extern void func_ov010_02201830(void *p, Ov010Vec *a);
extern void func_ov010_02201898(void *p, Ov010Vec *a);
extern void func_ov010_02201700(void *p);
extern BOOL func_ov010_0220180c(void *p);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern Ov010Vec data_ov010_0220ec5c;

struct Ov010Bits16 {
    u16 b0 : 1;
    u16 rest : 15;
};

struct Ov010StBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
};

static inline void Ov010e_Cmd(void *dst, s32 a, s32 b) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = a;
    cmd.b = b;
    func_ov003_021d8b60(dst, &cmd);
}

void func_ov010_021fc4ac(void *self) {
    void **tbl = data_ov010_0220ebc0;
    Ov010Vec up = data_ov010_0220ec14;
    void *anim = tbl[4];
    const Ov010Vec *tgt = &data_ov010_0220ecd4;
    const Ov010Vec *grav = &data_ov010_0220ec2c;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec rot;
        Ov010Vec ofs;
        u8 *pl;
        s32 i = 0;
        func_ov000_02190cb0(FLD(void *, self, 0x38), tbl[3], 0x1000, i);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = i;
            FLD(u16, cam, 6) = i;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 4, 1);
        FLD(s32, self, 0x9c) = i;
        FLD(s32, self, 0xa0) = i;
        FLD(s32, self, 0xa4) = i;
        FLD(s32, self, 0xa8) = i;
        FLD(s32, self, 0x120) = FLD(s32, tbl, 0x60);
        FLD(s32, self, 0x124) = FLD(s32, tbl, 0x64);
        FLD(s32, self, 0x128) = FLD(s32, tbl, 0x68);
        FLD(s32, self, 0x70) = 0x9600;
        FLD(s32, self, 0x74) = 0x17d9e;
        FLD(s32, self, 0x78) = i;
        func_ov010_02201b48((u8 *)self + 0x17c);
        pl = (u8 *)func_ov000_0219bf90();
        if (pl == NULL) {
            func_ov000_02198360(FLD(void *, self, 0x40), 100, i);
            break;
        }
        for (; i < 3; i++) {
            void *t;
            func_ov003_021d9900(&rot, i * 0xb00 + 0xf800, (Ov010Vec *)&data_ov010_0220ec38);
            ofs.x = -0x1333;
            ofs.y = 0x8000;
            ofs.z = 0x2666;
            t = func_ov010_02201ad4((u8 *)self + 0x17c, (void *)func_ov010_02201f18, i * 15 + 0x50);
            func_ov010_02202074(t, FLD(u16, pl, 0xc), FLD(u16, self, 0xc), &rot, &ofs);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    }
    case 10: {
        Ov010Vec d;
        Ov010Vec n;
        FLD(s32, self, 0x120) = FLD(s32, tbl, 0x60);
        FLD(s32, self, 0x124) = FLD(s32, tbl, 0x64);
        FLD(s32, self, 0x128) = FLD(s32, tbl, 0x68);
        d.x = tgt->x - FLD(s32, self, 0x70);
        d.y = tgt->y - FLD(s32, self, 0x74);
        d.z = tgt->z - FLD(s32, self, 0x78);
        VEC_Normalize(&d, &n);
        VEC_MultAdd(0xa00, &n, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        if (VEC_Mag(&d) <= 0xa00) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        break;
    }
    case 0x1e: {
        u8 *g;
        func_ov010_02203ee0(0x12e, (u8 *)self + 0x70)->v0c(0x3000);
        g = data_ov000_021ccd54;
        g[0x190] |= 0x1c;
        g[0x18d] = 10;
        g[0x18e] = 0x1e;
        g[0x18f] = 0x1e;
        func_ov000_02190cb0(FLD(void *, self, 0x38), tbl[8], 0x80, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
        func_02049f44(data_02097e4c, 0x35, (u8 *)self + 0x70, 0);
        break;
    }
    case 0x1f:
        VEC_MultAdd(0x18, &data_ov010_0220ed04, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(0x50, grav, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x400, 0x80);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x28) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
        }
        break;
    case 0x28:
        FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0xf50);
        FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0xf50);
        FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0xf50);
        VEC_MultAdd(4, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x400, 0x20);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32:
        func_ov000_02190cb0(FLD(void *, self, 0x38), anim, 0x90, 0);
        func_ov010_02201bf4((u8 *)self + 0x17c);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x33;
        func_02049a48(data_02097e4c, 0xb03, -1, -1, -1);
        break;
    case 0x33:
        VEC_MultAdd(0xc, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(9, &up, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(4, &data_ov010_0220ec38, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120), 0x2000);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if ((s32)FLD(u16, FLD(u8 *, self, 0x40), 2) > 0xf0 && func_ov010_02201c34((u8 *)self + 0x17c)) {
            FLD(Ov010Bits16, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_ov000_02190cb0(FLD(void *, self, 0x38), tbl[8], 0x1000, 0);
        func_ov010_02201b48((u8 *)self + 0x17c);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
    {
        u8 *c = FLD(u8 *, self, 0x108);
        FLD(Ov010StBits, c, 4).b2 = 1;
        FLD(u16, c, 6) = 0;
    }
}

static inline void *Ov010e_FindActor(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
}
static inline void Ov010e_Pull(void *self, s32 rate) {
    void *a = Ov010e_FindActor(FLD(u16, self, 0x90));
    if (a != NULL) {
        Ov010Vec d;
        s32 x = FLD(s32, a, 0x70);
        s32 y = FLD(s32, a, 0x74);
        s32 z = FLD(s32, a, 0x78);
        d.x = x - FLD(s32, self, 0x12c);
        d.y = y - FLD(s32, self, 0x130);
        d.z = z - FLD(s32, self, 0x134);
        VEC_MultAdd(rate, &d, &FLD(Ov010Vec, self, 0x12c), &FLD(Ov010Vec, self, 0x12c));
    }
}

void func_ov010_021fca40(void *self) {
    BOOL follow = TRUE;
    s32 rate = 0;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *pl;
        rate = 0x100;
        pl = (u8 *)func_ov000_0219bf90();
        if (pl == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        } else {
            FLD(s32, self, 0x12c) = FLD(s32, pl, 0x70);
            FLD(s32, self, 0x130) = FLD(s32, pl, 0x74);
            FLD(s32, self, 0x134) = FLD(s32, pl, 0x78);
            FLD(u16, self, 0x90) = FLD(u16, pl, 0xc);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        }
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        break;
    }
    case 10:
    case 11:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        rate = 0x100;
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
                FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
                FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
            }
        }
        break;
    case 0x28: {
        Ov010V *e;
        rate = 0x100;
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, -0x2800);
        e = func_ov003_021da788(0x196, self, &data_ov010_0220ec5c);
        if (e != NULL) {
            e->v0c(0x1a00);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x29;
        func_02049f44(data_02097e4c, 0x5b, (u8 *)self + 0x70, 0);
        func_02049a48(data_02097e4c, 0xb02, -1, -1, -1);
        break;
    }
    case 0x29:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        rate = 0x100;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x46) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32: {
        Ov010Vec v;
        rate = 0x100;
        func_ov003_021d9980(&v, FLD(u16, self, 0x7e), &data_ov010_0220ec5c);
        VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
        func_ov010_022016a0(FLD(void *, self, 0x100), &FLD(Ov010Vec, self, 0x12c), &v, 0x2bc);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0xf00;
        }
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0x3000);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x33;
        break;
    }
    case 0x33: {
        Ov010Vec v;
        follow = FALSE;
        rate = 0x100;
        func_ov003_021d9980(&v, FLD(u16, self, 0x7e), &data_ov010_0220ec5c);
        VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
        func_ov010_02201830(FLD(void *, self, 0x100), &v);
        func_ov010_02201898(FLD(void *, self, 0x100), &FLD(Ov010Vec, self, 0x12c));
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
            void *a = Ov010e_FindActor(FLD(u16, self, 0x90));
            if (a != NULL) {
                Ov010Vec p;
                p.x = FLD(s32, a, 0x70);
                p.y = FLD(s32, a, 0x74);
                p.z = FLD(s32, a, 0x78);
                if (VEC_Distance(&p, &FLD(Ov010Vec, self, 0x84)) > 0x10000) {
                    func_ov010_02201700(FLD(void *, self, 0x100));
                }
            }
        }
        if (func_ov010_0220180c(FLD(void *, self, 0x100))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x3c;
        }
        break;
    }
    case 0x3c:
        Ov010e_Cmd((u8 *)self + 0x1c0, 3, 0);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x3d;
        break;
    case 0x3d:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x46;
        }
        break;
    case 0x46:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220ebc0[8], 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x47;
        break;
    case 0x47:
        if (func_ov000_02191120(FLD(void *, self, 0x38))) {
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    Ov010e_Pull(self, rate);
    if (follow) {
        FLD(s32, self, 0x84) = FLD(s32, self, 0x12c);
        FLD(s32, self, 0x88) = FLD(s32, self, 0x130);
        FLD(s32, self, 0x8c) = FLD(s32, self, 0x134);
    }
    func_ov000_0218d918(self, (u8 *)self + 0x84, 0x180);
    {
        u8 *c = FLD(u8 *, self, 0x108);
        FLD(Ov010StBits, c, 4).b2 = 1;
        FLD(u16, c, 6) = 0;
    }
}


struct Ov010Flags8b {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern void *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 x, s32 z);
extern s32 func_02040528(s32 n);
extern s32 func_02040498(s32 max);
extern void func_ov003_021d6868(void *self, s32 a);
extern void func_ov010_0220172c(void *p);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov003_021da108(void *t, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern void func_ov003_021d97fc(void *p, s32 a);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern char data_ov010_0220fc19[];
extern char data_ov010_0220fc1f[];
extern const Ov010Vec data_ov010_0220ec44;
extern u8 data_ov010_0220edd4[];

typedef Ov010Blk12 (*Ov010PosFn)(void *a);

static inline u16 Ov010e_AngTo(void *self, u8 *a) {
    if (a == NULL || a == self) {
        return FLD(u16, self, 0x7e);
    }
    return FX_Atan2(FLD(s32, a, 0x70) - FLD(s32, self, 0x70), FLD(s32, a, 0x78) - FLD(s32, self, 0x78));
}

static inline void Ov010e_Spawn(void *self) {
    if (FLD(Ov010Flags8b, self, 0x138).b0 && FLD(s32, self, 0x140) == 0) {
        void *a = Ov010e_FindActor(FLD(u16, self, 0x13a));
        if (a != NULL) {
            Ov010V *e;
            Ov010Vec w;
            Ov010Vec u;
            *(Ov010Blk12 *)&u = ((Ov010PosFn)FLD(void *, self, 0x14c))(a);
            w.x = FLD(s32, a, 0x70);
            w.y = FLD(s32, a, 0x74);
            w.z = FLD(s32, a, 0x78);
            VEC_Add(&w, &u, &w);
            e = func_02065f88(FLD(s32, self, 0x144), &w);
            FLD(u8, e, 0xd0) = 1;
            FLD(s32, self, 0x148) = FLD(s32, e, 0x24);
            FLD(u8, self, 0x139) = 0x1f;
            FLD(u16, self, 0x13c) = 0;
            FLD(s32, self, 0x140) = 1;
        }
    }
}

void func_ov010_021fcf70(void *self) {
    u16 st;
    s32 i;
    FLD(Ov010Flags8b, self, 0xf0).b1 = 0;
    st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    switch (st) {
    case 0:
    case 1:
        if (st == 0) {
            if (FLD(void *, self, 0x50) != NULL && func_ov000_02199f60(FLD(void *, self, 0x50)) != NULL) {
                FLD(u16, self, 0x98) = Ov010e_AngTo(self, (u8 *)func_ov000_02199f60(FLD(void *, self, 0x50)));
            } else {
                FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
            }
            FLD(u16, self, 0x98) += (u16)(func_02040528(0x2000) + 0x7fff);
            FLD(s32, self, 0x120) = FLD(s32, data_ov010_0220ebc0, 0x60);
            FLD(s32, self, 0x124) = FLD(s32, data_ov010_0220ebc0, 0x64);
            FLD(s32, self, 0x128) = FLD(s32, data_ov010_0220ebc0, 0x68);
            func_ov000_02191418(FLD(void *, self, 0x38), 3, 0);
            Ov010e_Cmd((u8 *)self + 0x1c0, 2, 1);
            func_ov010_0220172c(FLD(void *, self, 0x100));
            func_ov010_02201b48((u8 *)self + 0x17c);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        }
        func_ov003_021d6868(self, 0x739f);
        if (FLD(Ov010Flags8b, self, 0x138).b0) {
            FLD(Ov010Flags8b, self, 0x138).b1 = 1;
        }
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 3) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        } else {
            (*(volatile u16 *)&FLD(u16, FLD(u8 *, self, 0x40), 2))++;
        }
        break;
    case 0x14:
    case 0x15:
        if (st == 0x14) {
            u16 rx = (func_02040498(0x2000) - 0x2000) >> 1;
            u16 ry = (func_02040498(0x2000) - 0x2000) >> 1;
            u16 rz = (func_02040498(0x2000) - 0x2000) >> 1;
            FLD(u16, self, 0x7c) += rx;
            FLD(u16, self, 0x7e) += ry;
            FLD(u16, self, 0x80) += rz;
            {
                u16 *hp = FLD(u16 *, self, 0x50);
                u16 d = Ov010_FxMul(hp[1] << 12, 0x19a) >> 12;
                if (d >= hp[0]) {
                    hp[0] = 0;
                } else {
                    hp[0] -= d;
                }
            }
            FLD(s16, self, 0xf2) = 0x1000;
            func_ov003_021d85c8((u8 *)self + 0x150, 0x14, 0, 0, 0);
            {
                u8 *g = data_ov000_021ccd54;
                g[0x190] |= 0x1c;
                g[0x18d] = 0xf;
                g[0x18e] = 0xf;
                g[0x18f] = 0xf;
            }
            func_ov003_021d68e0(self, 0x5adf, 0x739f, 10);
            func_ov003_021d9980(&FLD(Ov010Vec, self, 0x120), FLD(u16, self, 0x98), (Ov010Vec *)&data_ov010_0220ec38);
            FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0x800);
            FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0x800);
            FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0x800);
            if (FLD(Ov010Flags8b, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
                FLD(s32, self, 0x140) = 2;
                FLD(u16, self, 0x13c) = 0;
            }
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc19, 0x800, 1);
            FLD(u16, self, 0xb4) = 0;
            FLD(u16, self, 0xb6) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x15;
            func_02049a48(data_02097e4c, 0xb04, -1, -1, -1);
            func_02049f44(data_02097e4c, 0x1a, (u8 *)self + 0x70, 0);
        }
        for (i = 0; i < 3; i++) {
            s32 k = i * 5;
            if (k == FLD(u16, FLD(u8 *, self, 0x40), 2)) {
                func_ov003_021da108(self, 0x6000, 0x6b, 0x1000, 0x3000);
            }
        }
        FLD(s32, self, 0x120) = Ov010_FxMul(FLD(s32, self, 0x120), 0xec0);
        FLD(s32, self, 0x124) = Ov010_FxMul(FLD(s32, self, 0x124), 0xec0);
        FLD(s32, self, 0x128) = Ov010_FxMul(FLD(s32, self, 0x128), 0xec0);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x19) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc1f, 0x89, 0);
            func_ov000_021915a0(FLD(void *, self, 0x38));
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        break;
    case 0x32:
        VEC_MultAdd(0x20, &data_ov010_0220ec44, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_MultAdd(0x30, &data_ov010_0220fa64, &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x120));
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x120), &FLD(Ov010Vec, self, 0x70));
        if (FLD(s32, self, 0x74) <= -0x16000) {
            u16 *hp = FLD(u16 *, self, 0x50);
            if ((hp[0] << 12) / hp[1] <= 0x333) {
                Ov010e_Spawn(self);
                if (!func_ov003_021d984c((u8 *)self + 0x1ac, data_ov010_0220edd4)) {
                    func_ov003_021d95e8((u8 *)self + 0x1ac, data_ov010_0220edd4, 0x19);
                    func_ov003_021d97fc((u8 *)self + 0x1ac, 1);
                }
            }
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        FLD(u16, self, 0x7c) = func_01ffc128(0, FLD(u16, self, 0x7c), 0x148, 1, 0x8000);
        FLD(u16, self, 0x7e) = func_01ffc128(0xbfff, FLD(u16, self, 0x7e), 0x148, 1, 0x8000);
        FLD(u16, self, 0x80) = func_01ffc128(0, FLD(u16, self, 0x80), 0x148, 1, 0x8000);
        break;
    case 100:
        func_ov000_02198360(FLD(void *, self, 0x40), 0x2b, 0);
        break;
    }
    FLD(Ov010Flags8b, FLD(u8 *, self, 0x108), 4).b1 = 1;
    {
        u8 *cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0;
    }
    FLD(u16 *, self, 0x50)[5] = 5;
}

}
