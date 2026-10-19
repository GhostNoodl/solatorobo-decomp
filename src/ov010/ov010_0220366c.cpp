#include "ov010/ov010.h"

struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
    u8 unk_08[4];
    s32 fx0;
    s32 fx1;
};

struct Ov010Sub48b {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[0x10];
    s32 unk_58;
    u8 unk_5c[0x3e];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 rest : 12;
};

struct Ov010Owner {
    u8 unk_00;
    u8 kind;
    u8 unk_02[0x1a];
    u16 id;
};

struct Ov010B0 {
    u16 unk_00;
    u16 mode : 3;
    u16 rest : 13;
};

extern "C" {
extern void *data_0214a420;
extern void func_02065804(void *a, s32 b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02196060(void *self);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov010_02203bf8(Ov010FxSet *p);

void func_ov010_0220366c(void *self) {
    if (FLD(u16 *, self, 0x40)[0] == 0) {
        Ov010FxSet *s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 0;
            func_02065804(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b2 = 0;
            func_02065804(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
    }
    func_ov000_02195d88(self);
}

void func_ov010_022036fc(void *self) {
    BOOL first = FALSE;
    if (FLD(u16 *, self, 0x40)[0] == 0) {
        first = TRUE;
    }
    func_ov000_02196060(self);
    if (first) {
        Ov010FxSet *s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        Ov010_VecSet(&FLD(Ov010Vec, self, 0xa0), 0, 0, 0);
        FLD(Ov010Flags8, self, 0xce).b2 = 1;
        FLD(s32, self, 0x9c) = 0x4c0;
        FLD(u16, self, 0x90) = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0x90);
    }
    func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
}

extern void *data_ov000_021ccd68;
extern Ov010Vec data_ov010_0220efd0;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov000_02196c40(void *self);
extern Ov010Vec func_ov003_021da214(void *actor);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern s32 func_ov000_0219a510(void *self, u16 mask, Ov010Vec *pos, s32 r, s32 a, void **list);
extern void func_ov003_021f0c60(void *self, s32 a);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_0203f324(Ov010Sub48b *p);
extern void func_0203f364(Ov010Sub48b *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(Ov010Vec *v);

static inline void *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov010_02203788(void *self) {
    u16 *st;
    void *actor;
    if (!FLD(Ov010Flags8, self, 0xce).b2) {
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = FLD(u16, func_ov000_0219bf90(), 0xc);
        func_ov000_02196c40(self);
        return;
    }
    switch (FLD(u16 *, self, 0x40)[0]) {
    case 0:
        actor = Ov010_FindActor(FLD(u16, self, 0x90));
        if (actor != NULL) {
            Ov010Vec c;
            Ov010Vec b = func_ov003_021da214(actor);
            c.x = FLD(s32, actor, 0x70);
            c.y = FLD(s32, actor, 0x74);
            c.z = FLD(s32, actor, 0x78);
            VEC_Add(&c, &b, &c);
            FLD(s32, self, 0xec) = c.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0xf0) = c.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0xf4) = c.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0xec), &FLD(Ov010Vec, self, 0xec));
        } else {
            func_ov003_021d9980(&FLD(Ov010Vec, self, 0xec), FLD(u16, self, 0x7e), &data_ov010_0220efd0);
        }
        FLD(u16 *, self, 0x40)[0] = 10;
        break;
    case 10: {
        void *list[32];
        actor = Ov010_FindActor(FLD(u16, self, 0x90));
        if (actor != NULL) {
            Ov010Vec c;
            Ov010Vec b = func_ov003_021da214(actor);
            c.x = FLD(s32, actor, 0x70);
            c.y = FLD(s32, actor, 0x74);
            c.z = FLD(s32, actor, 0x78);
            VEC_Add(&c, &b, &c);
            FLD(s32, self, 0xec) = c.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0xf0) = c.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0xf4) = c.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0xec), &FLD(Ov010Vec, self, 0xec));
        }
        if (func_ov000_0219a510(self, 0x20, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x64), 0, list) != 0 ||
            FLD(Ov010Sub48b *, self, 0x48)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(FLD(u16 *, self, 0x40), 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x3c) {
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 0x14;
        }
        break;
    }
    case 0x14: {
        void *list[32];
        if (func_ov000_0219a510(self, 0x20, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x64), 0, list) != 0 ||
            FLD(Ov010Sub48b *, self, 0x48)->unk_58 != 0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(FLD(u16 *, self, 0x40), 0x15, 0);
            func_ov000_0218996c(0xf, 10);
            return;
        }
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x3c) {
            func_ov000_02198360(FLD(u16 *, self, 0x40), 0x15, 0);
            return;
        }
        break;
    }
    }
    {
        s32 v = FLD(s32, self, 0x9c) + 0x14;
        FLD(s32, self, 0x9c) = v;
        if (v > 0xa00) {
            v = 0xa00;
        } else if (v < 0) {
            v = 0;
        }
        FLD(s32, self, 0x9c) = v;
    }
    func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xec), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), 0);
    if (FLD(Ov010Sub48b *, self, 0x48) != NULL) {
        Ov010Sub48b *o;
        BOOL f;
        if (FLD(Ov010B0 *, self, 0xb0)->mode == 2) {
            Ov010Sub48b *m = FLD(Ov010Sub48b *, self, 0x48);
            m->b0 = 1;
            m->b3 = 1;
            func_0203f324(m);
        }
        o = NULL;
        f = FALSE;
        {
            Ov010Owner *ow = FLD(Ov010Owner *, self, 0x4c);
            if (ow != NULL && ow->id != 0xffff && ow->kind == 1) {
                s32 r = FLD(s32, self, 0x64) + 0x4cd;
                void *p;
                if (r < 0xccd) {
                    r = 0xccd;
                }
                FLD(Ov010Sub48b *, self, 0x48)->unk_44 = r;
                p = func_ov000_02199ba0(FLD(void *, self, 0x4c));
                if (p != NULL && (o = FLD(Ov010Sub48b *, p, 0x48)) != NULL && o->b3) {
                    o->b3 = 0;
                    func_0203f364(o);
                    f = TRUE;
                }
            }
        }
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        if (f) {
            o->b3 = 1;
            func_0203f324(o);
        }
    }
    FLD(u16, self, 0x7c) = func_ov003_021d9c74(&FLD(Ov010Vec, self, 0xec));
    FLD(u16, self, 0x7e) = func_ov003_021d9c38(&FLD(Ov010Vec, self, 0xec));
    func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
}
}
