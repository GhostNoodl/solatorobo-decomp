#include "ov010/ov010.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov003_021d7a44(void *self, const Ov010Vec *target, const Ov010Vec *start, s32 speed, s32 maxDist, u8 noSnap);
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern Ov010V *func_02065f88(s32 id, const Ov010Vec *pos);
extern void func_ov010_02209074(void *p);

static inline u8 *Ov010_FindActorD(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

extern void *data_ov000_021ccd54;
extern const Ov010Blk12 data_ov010_0220f588;
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);
extern BOOL func_ov003_021d98bc(Ov010Vec *a, void *b);
extern void func_ov003_021d9f80(void *rot, const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern u16 func_ov003_021d9c38(void *p);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov003_021d7bd4(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);

static inline void Ov010_Puff(u8 *self) {
    Ov010Vec q;
    Ov010V *e;
    *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
    e = func_02065f88(0x321, &q);
    e->v0c(0x1000);
    FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, e, 4) = 6;
}

static inline void Ov010_Dust(u8 *self) {
    u16 ry = FLD(u16, self, 0x7e);
    u16 rx = FLD(u16, self, 0x7c);
    Ov010Vec p;
    s32 y = FLD(s32, self, 0x74);
    s32 z = FLD(s32, self, 0x78);
    p.x = FLD(s32, self, 0x70);
    p.y = y + FLD(s32, self, 0x68) / 2;
    p.z = z;
    func_02065f88(0x192, &p)->v34(rx, ry, 0);
}

void func_ov010_0220cba0(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0:
    case 10: {
        u8 *t = Ov010_FindActorD(FLD(u16, self, 0xd0));
        Ov010Vec d;
        if (t == NULL || FLD(s32, self, 0xd8) != 1) {
            FLD(u16, self, 0x16c) = 0x1e;
            return;
        }
        FLD(s32, self, 0xd8) = 4;
        Ov010_VecCopy(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70));
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = FLD(s32, self, 0x74);
            s32 z = FLD(s32, self, 0x78);
            FLD(s32, self, 0x114) = x;
            FLD(s32, self, 0x118) = y;
            FLD(s32, self, 0x11c) = z;
            FLD(s32, self, 0x118) = FLD(s32, self, 0x118) + (0x5800 - FLD(s32, self, 0x100));
            FLD(s32, self, 0x9c) = 0xa00;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            d.x = FLD(s32, self, 0xf0) - x;
            d.y = FLD(s32, self, 0xf4) - y;
            d.z = FLD(s32, self, 0xf8) - z;
        }
        FLD(u16, self, 0x7e) = func_ov003_021d9c38(&d);
        func_0204a028(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 5);
        Ov010_Puff(self);
        FLD(u16, self, 0x16c) = 0xb;
        return;
    }
    case 0xb:
        if (FLD(s32, self, 0xa4) == 0) {
            if (func_ov003_021d9a80(&FLD(Ov010Vec, self, 0x114), &FLD(Ov010Vec, self, 0x70)) < 0x9000) {
                FLD(s32, self, 0xa4) = 0xa00;
            }
        }
        if (func_ov003_021d98bc(&FLD(Ov010Vec, self, 0x114), self + 0x70) || FLD(s32, self, 0x9c) < 0x80) {
            FLD(u16, self, 0x16c) = 0x14;
            return;
        }
        func_ov003_021d9f80(self + 0x7c, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70));
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x114), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        return;
    case 0x14:
        func_ov003_021d7a44(self + 0x120, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70), 0x100, 0x2000, 0);
        func_ov003_021d9f80(self + 0x7c, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, self, 0x16c) = 0x15;
        return;
    case 0x15: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010V *e;
        FLD(u16, self, 0x16e)++;
        if (FLD(u16, self, 0x16e) == 10) {
            Ov010_Dust(self);
        }
        {
            Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
            FLD(s32, self, 0x70) = v->x;
            FLD(s32, self, 0x74) = v->y;
            FLD(s32, self, 0x78) = v->z;
        }
        FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        {
            u16 mask = ~(1 << (FLD(u16, self, 0xc) >> 12));
            u16 dd = FLD(u16, FLD(u8 *, self, 0x4c), 0xa);
            u16 c = FLD(u16, FLD(u8 *, self, 0x4c), 8);
            void *x = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (func_ov000_0219aae8(self, x, c, dd, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
                Ov010_Puff(self);
                func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
                return;
            }
        }
        if (!(FLD(u32, FLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            if (!((Ov010V *)(self + 0x120))->v14()) {
                return;
            }
        }
        {
            u16 ang;
            u8 *g;
            u8 *m;
            *(Ov010Blk12 *)&a = FLD(Ov010Blk12, self, 0x70);
            *(Ov010Blk12 *)&b = data_ov010_0220f588;
            ang = func_ov003_021d9c38(func_ov003_021d7bd4(self + 0x120)) + 0x7fff;
            e = func_02065f88(0x67, &a);
            e->v34(0, ang, 0);
            e->v10(&b);
            Ov010_Puff(self);
            g = (u8 *)data_ov000_021ccd54;
            FLD(u8, g, 0x190) |= 0x1c;
            FLD(u8, g, 0x18d) = 5;
            FLD(u8, g, 0x18e) = 8;
            FLD(u8, g, 0x18f) = 8;
            {
                u16 r;
                if (FLD(u16, self, 0x7c) > 0x7fff) {
                    r = FLD(u16, self, 0x7c) - 0xe38;
                } else {
                    r = FLD(u16, self, 0x7c) + 0xe38;
                }
                FLD(u16, self, 0x7c) = r;
            }
            m = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            FLD(s32, self, 0xd8) = 6;
            FLD(u16, self, 0x16c) = 0x1e;
            FLD(u16, self, 0x16e) = 0;
            func_02049f44(data_02097e4c, 0x52, self + 0x70, 0);
        }
        return;
    }
    case 0x1e:
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        return;
    }
}


void func_ov010_0220d1c4(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0: {
        u8 *t = Ov010_FindActorD(FLD(u16, self, 0xd0));
        if (t != NULL && FLD(s32, self, 0xd8) == 1) {
            Ov010Vec p;
            Ov010Vec q;
            Ov010V *e;
            FLD(s32, self, 0xd8) = 3;
            Ov010_VecCopy(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70));
            VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
            FLD(u16, self, 0x7c) = 0xbfff;
            FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
            p.x = FLD(s32, self, 0x70);
            p.y = FLD(s32, self, 0x74) + 0xa000;
            p.z = FLD(s32, self, 0x78);
            func_ov003_021d7a44(self + 0x120, &p, &FLD(Ov010Vec, self, 0x70), 0x29, 0x4cd, 0);
            func_0204a028(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 5);
            OV010_BLKCPY(&q, self + 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            FLD(u16, self, 0x16c) = 1;
        } else {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 1: {
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
        FLD(s32, self, 0x70) = v->x;
        FLD(s32, self, 0x74) = v->y;
        FLD(s32, self, 0x78) = v->z;
        if (((Ov010V *)(self + 0x120))->v14()) {
            FLD(u16, self, 0x16c) = 2;
        }
        break;
    }
    case 2:
        FLD(s32, self, 0xd8) = 2;
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        break;
    }
}


extern const Ov010Blk12 data_ov010_0220f570;
extern s32 func_02040498(s32 max);

void func_ov010_0220d3d8(u8 *self) {
    switch (FLD(u16, self, 0x16c)) {
    case 0:
        if (FLD(s32, self, 0xd8) != 2) {
            FLD(u16, self, 0x16c) = 2;
            return;
        }
        FLD(s32, self, 0xd8) = 4;
        FLD(s32, self, 0x70) = FLD(s32, self, 0xf0);
        FLD(s32, self, 0x78) = FLD(s32, self, 0xf8);
        FLD(s32, self, 0x74) = FLD(s32, self, 0xf4) + 0xa000;
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xfc), &FLD(Ov010Vec, self, 0x70));
        FLD(u16, self, 0x7c) = 0x4000;
        FLD(u16, self, 0x7e) = func_02040498(0xffff);
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        func_ov003_021d7a44(self + 0x120, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0x70), 0x8cd, 0x8cd, 1);
        FLD(u16, self, 0x16c) = 1;
        break;
    case 1: {
        Ov010Vec a;
        Ov010Vec b;
        Ov010Vec q;
        Ov010Vec q2;
        Ov010V *e;
        Ov010Vec *v = (Ov010Vec *)((Ov010V *)(self + 0x120))->v10();
        FLD(s32, self, 0x70) = v->x;
        FLD(s32, self, 0x74) = v->y;
        FLD(s32, self, 0x78) = v->z;
        FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        {
        u16 mask = ~(1 << (FLD(u16, self, 0xc) >> 12));
        u16 d = FLD(u16, FLD(u8 *, self, 0x4c), 0xa);
        u16 c = FLD(u16, FLD(u8 *, self, 0x4c), 8);
        void *x = func_ov000_02199ba0(FLD(void *, self, 0x4c));
        if (func_ov000_0219aae8(self, x, c, d, mask, NULL, NULL, 0x400, 0, 0x38f, 0x1000)) {
            *(Ov010Blk12 *)&q = FLD(Ov010Blk12, self, 0x70);
            e = func_02065f88(0x321, &q);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
            return;
        }
        }
        if (FLD(u32, FLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            u16 ang;
            u8 *g;
            u8 *m;
            a.x = FLD(s32, self, 0x70);
            a.y = FLD(s32, self, 0x74) - FLD(s32, FLD(u8 *, self, 0x48), 0x38);
            a.z = FLD(s32, self, 0x78);
            *(Ov010Blk12 *)&b = data_ov010_0220f570;
            ang = func_ov003_021d9c38(func_ov003_021d7bd4(self + 0x120)) + 0x7fff;
            e = func_02065f88(0x66, &a);
            e->v34(0, ang, 0);
            e->v10(&b);
 *(Ov010Blk12 *)&q2 = FLD(Ov010Blk12, self, 0x70);
            e = func_02065f88(0x321, &q2);
            e->v0c(0x1000);
            FLD(void *, e, 0xdc) = (void *)func_ov010_02209074;
            FLD(s32, e, 4) = 6;
            g = (u8 *)data_ov000_021ccd54;
            FLD(u8, g, 0x190) |= 0x1c;
            FLD(u8, g, 0x18d) = 5;
            FLD(u8, g, 0x18e) = 8;
            FLD(u8, g, 0x18f) = 8;
            FLD(u16, self, 0x7c) += func_02040498(0x2aaa) - 0x1555;
            m = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
            FLD(u8, m, 0x111) |= 8;
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            FLD(u16, self, 0x16c) = 2;
            FLD(s32, self, 0xd8) = 6;
            func_02049f44(data_02097e4c, 0x52, self + 0x70, 0);
        }
        break;
    }
    case 2:
        ((Ov010V *)(self + 0x120))->v08();
        FLD(Ov010Flags8, self, 0xce).b1 = 0;
        break;
    }
}

}
