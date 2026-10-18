#include "ov010/ov010.h"

class Ov010Cls;
typedef void (Ov010Cls::*Ov010Fn)();
struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};


struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010Query {
    Ov010Vec pos;
    u16 rot;
    u16 kind;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;

    Ov010Query() {
        kind = 0;
        unk_10 = 0xffff;
        unk_12 = 0;
        unk_14 = 0;
        unk_18 = 0;
        unk_1c = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0xffff;
        *(u8 *)((u8 *)this + 0x2a) = 0;
    }
};

struct Ov010U16x6 {
    u16 v[6];
};

extern "C" {

extern Ov010Heap *data_02097dd0;
extern u8 *data_ov000_021ccd54;
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void func_ov003_021d8fa8(void *p);
extern void func_ov010_0220d834(void *p);

static inline void Ov010_FreeV(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        Ov010V *p = FLD(Ov010V *, self, off);
        if (p != NULL) {
            p->v04();
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

extern u8 data_ov010_0220f024[];
extern void MI_CpuFill8(void *p, s32 v, s32 n);

void func_ov010_02207520(void *self) {
    FLD(u8, self, 0xf0) = 0;
    FLD(u8, self, 0xf1) = 0;
    FLD(u8, self, 0xf2) = 0;
    FLD(u8, self, 0xf3) = 0;
    FLD(u16, self, 0xf4) = 0;
    FLD(s32, self, 0xf8) = 0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(s32, self, 0x108) = 0;
    FLD(s32, self, 0x10c) = 0;
    FLD(s32, self, 0x110) = 0;
    FLD(s32, self, 0x114) = 0;
    FLD(s32, self, 0x118) = 0;
    FLD(s32, self, 0x11c) = 0;
    FLD(s32, self, 0x120) = 0;
    FLD(s32, self, 0x124) = 0;
    FLD(s32, self, 0x128) = -1;
    MI_CpuFill8((u8 *)self + 0x12c, 0, 0x24);
    FLD(Ov010Vec, self, 0x150) = FLD(Ov010Vec, data_ov010_0220f024, 0x84);
    FLD(s32, self, 0x15c) = -1;
    FLD(u8, self, 0x170) = 0;
    FLD(u8, self, 0x171) = 0xff;
}

void func_ov010_022075bc(void *self) {
    u32 saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    Ov010_FreeV(self, 0x104);
    Ov010_FreeV(self, 0x108);
    Ov010_FreeV(self, 0x10c);
    Ov010_FreeV(self, 0x110);
    Ov010_FreeV(self, 0x114);
    Ov010_FreeV(self, 0x118);
    Ov010_FreeV(self, 0x11c);
    Ov010_FreeV(self, 0x120);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x124) != NULL) {
        func_0203de1c(FLD(void *, self, 0x124));
        FLD(void *, self, 0x124) = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021d8fa8((u8 *)self + 0x160);
    func_ov010_0220d834((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v08();
    ((Ov010V *)((u8 *)self + 0x1dc))->v08();
    FLD(Ov010Flags8, data_ov000_021ccd54, 0x1cc).b0 = 0;
    func_ov010_02207520(self);
    func_ov003_021cf400(0);
}

extern s32 func_ov000_02199128(s32 *out, Ov010Query *q, void **list, s32 max);

extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern BOOL func_ov003_021d98bc(Ov010Vec *a, Ov010Vec *b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov010_Move(void *self) {
    func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
    func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
}

void func_ov010_02207828(void *self) {
    Ov010Vec t;
    t.x = FLD(s32, self, 0xb8);
    t.y = FLD(s32, self, 0xbc);
    t.z = FLD(s32, self, 0xc0);
    if (VEC_Distance(&t, &FLD(Ov010Vec, self, 0x70)) >= 0x3000) {
        FLD(s32, self, 0x9c) += 0x180;
        FLD(s32, self, 0x9c) = Ov010_Clamp(FLD(s32, self, 0x9c), 0, 0xd00);
        Ov010_Move(self);
        return;
    } else {
        BOOL slow = TRUE;
        if (FLD(s32, self, 0x9c) >= 0x40) {
            slow = FALSE;
        }
        if (func_ov003_021d98bc(&FLD(Ov010Vec, self, 0x70), &t) || slow) {
            FLD(s32, self, 0x9c) = 0;
            return;
        }
        FLD(s32, self, 0xa4) = 0xf00;
        if (FLD(s32, self, 0x9c) >= 0x400) {
            FLD(s32, self, 0x9c) = 0x400;
        }
    }
    Ov010_Move(self);
}

static inline void Ov010Query_Set(Ov010Query *q, const Ov010Vec *pos, u16 rot, u16 kind, s32 r) {
    q->pos.x = pos->x;
    q->pos.y = pos->y;
    q->pos.z = pos->z;
    q->rot = rot;
    q->kind = kind;
    q->unk_10 = 0xffff;
    q->unk_18 = 0;
    q->unk_1c = r;
    q->b2 = 0;
}

BOOL func_ov010_0220794c(void *self) {
    void *list[0x20];
    Ov010Query q;
    s32 out;
    BOOL found = FALSE;
    s32 n;
    s32 i;
    Ov010Query_Set(&q, &FLD(Ov010Vec, self, 0x70), FLD(u16, self, 0x7e), 0x10, 0x5000);
    out = 0;
    n = func_ov000_02199128(&out, &q, list, 0x20);
    for (i = 0; i < n; i++) {
        void *a = list[i];
        if (a != NULL) {
            u8 st;
            if (FLD(void *, a, 0x40) != NULL) {
                st = FLD(u8, FLD(void *, a, 0x40), 0x13);
            } else {
                st = 0;
            }
            if (st == 0xb && FLD(u16, a, 0x90) == FLD(u16, self, 0xc)) {
                found = TRUE;
            }
        }
    }
    return found;
}

extern u8 data_ov010_02210154[];
extern u8 data_ov010_0220ffe4[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void func_ov003_021d0c1c(void *self);
extern void func_ov003_021d8f24(void *p);
extern void func_ov010_0220d79c(void *p);
extern void func_ov003_021d7f0c(void *p);
extern void func_ov003_021d8b88(void *p);
extern void func_ov003_021cf340(const char *p);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov003_021cf39c(s32 a, const char *b);
extern void func_ov010_02207520(void *self);
extern void func_ov010_022046ac(void *self);
extern void func_ov010_0220441c(void *self, void *msg);

static inline void Ov010_02204204_Body(void *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov010_02210154;
    func_ov003_021d8f24((u8 *)self + 0x160);
    func_ov010_0220d79c((u8 *)self + 0x174);
    func_ov003_021d7f0c((u8 *)self + 0x1b0);
    func_ov003_021d8b88((u8 *)self + 0x1dc);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520(self);
}

u16 func_ov010_02207a44(s32 i) {
    Ov010U16x6 t = FLD(Ov010U16x6, data_ov010_0220f024, 0xb4);
    if (i < 6) {
        return t.v[i];
    }
    return t.v[5] + (u16)((i - 5) * 0x5a);
}

void *func_ov010_02207ac4(void *self) {
    Ov010_02204204_Body(self);
    FLD(u8, self, 0x1fc) = 0;
    FLD(s32, self, 0x200) = 0;
    FLD(void *, self, 0) = data_ov010_0220ffe4;
    return self;
}

void func_ov010_02207b6c(void *self) {
    func_ov010_022046ac(self);
    FLD(u8, self, 0xf3) = FLD(s16, self, 0x18) == 3;
}

void func_ov010_02207b90(void *self, void *msg) {
    if (msg != NULL && FLD(u8, msg, 5) == 2) {
        FLD(u8, self, 0x1fc) = 0;
    }
    func_ov010_0220441c(self, msg);
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern void func_ov003_021d3008(void *self);
extern u8 func_ov003_021cf408(void);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const Ov010Vec *b, const Ov010Vec *c, Ov010Vec *out);
extern void func_ov010_0220d858(void *p);


void func_ov010_02207bb4(Ov010Cls *self) {
    u32 i;
    u8 *pl;
    s16 *p;
    u8 key;
    if (FLD(u8, self, 0x1fc) != 0) {
        return;
    }
    key = FLD(u8, FLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        FLD(u8, self, 0x15) = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&FLD(Ov010Vec, pl, 0xb90), &FLD(Ov010Vec, self, 0x70));
        FLD(s32, pl, 0xb9c) = 0x800;
    }
    p = FLD(s16 *, self, 0x124);
    if (p != NULL) {
        Ov010Vec v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x70));
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v0c();
    ((Ov010V *)((u8 *)self + 0x1dc))->v0c();
    if (FLD(Ov010V *, self, 0x118) != NULL) {
        FLD(Ov010V *, self, 0x118)->v0c();
    }
}

extern void *data_02097e4c;
extern const Ov010Vec data_ov010_0220f0fc;
extern void func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d64f0(void *self);
extern u16 FX_Atan2(s32 y, s32 x);

void func_ov010_02207d2c(void *self) {
    FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 1;
    switch (FLD(s16, self, 0x18)) {
    case 0: {
        u16 *st = FLD(u16 *, self, 0x40);
        switch (st[0]) {
        case 0:
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
            func_ov000_021915a0(FLD(void *, self, 0x38));
            Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), 0x19a, 0x1b3b, -0x3a77);
            FLD(u16, self, 0x7c) = FLD(u16, data_ov010_0220f024, 0x50);
            FLD(u16, self, 0x7e) = FLD(u16, data_ov010_0220f024, 0x52);
            FLD(u16, self, 0x80) = FLD(u16, data_ov010_0220f024, 0x54);
            FLD(s32, self, 0x74) += 0x5000;
            FLD(s32, self, 0x9c) = 0xcd;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            func_02049f44(data_02097e4c, 0x51, &FLD(Ov010Vec, self, 0x70), 0);
            FLD(u16 *, self, 0x40)[0] = 1;
            return;
        case 1:
            if (FLD(s32, self, 0x9c) >= 0x20) {
                const Ov010Vec *t = &data_ov010_0220f0fc;
                if (FLD(s32, self, 0xa4) == 0) {
                    if (VEC_Distance(t, &FLD(Ov010Vec, self, 0x70)) < 0x333) {
                        FLD(s32, self, 0xa4) = 0xe66;
                    }
                }
                func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), t, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
                func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
                FLD(u16, self, 0x98) = FX_Atan2(t->x - FLD(s32, self, 0x70), t->z - FLD(s32, self, 0x78));
                return;
            }
            func_02065f88(0x12f, &FLD(Ov010Vec, self, 0x70))->v0c(0xe66);
            FLD(u16 *, self, 0x40)[0] = 2;
            return;
        case 2:
            st[1]++;
            if (FLD(u16 *, self, 0x40)[1] <= 0x5a) {
                return;
            }
            FLD(s32, self, 0x9c) = 0;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            func_ov003_021d64f0(self);
            return;
        }
        return;
    }
    case 1:
        Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), 0x19a, 0x1b3b, -0x3a77);
        FLD(u16, self, 0x7c) = FLD(u16, data_ov010_0220f024, 0x50);
        FLD(u16, self, 0x7e) = FLD(u16, data_ov010_0220f024, 0x52);
        FLD(u16, self, 0x80) = FLD(u16, data_ov010_0220f024, 0x54);
        func_ov003_021d64f0(self);
        return;
    case 2:
        Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), 0x1da2, -0xb42d, 0x266f);
        FLD(u16, self, 0x7c) = 0;
        FLD(u16, self, 0x7e) = 0x7fff;
        FLD(u16, self, 0x80) = 0;
        func_ov003_021d64f0(self);
        return;
    case 3:
        Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), 0x1da2, -0xb42d, 0x266f);
        FLD(u16, self, 0x7c) = 0;
        FLD(u16, self, 0x7e) = 0x7fff;
        FLD(u16, self, 0x80) = 0;
        func_ov003_021d64f0(self);
        return;
    }
}

}
