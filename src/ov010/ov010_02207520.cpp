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

struct Obj022075bc {
    u8 unk_00[0x124];
    void *unk_124;
};

static inline void Ov010_FreeV(Obj022075bc *self, u32 off) {
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

struct Obj02207520 {
    u8 unk_00[0xf0];
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u16 unk_f4;
    u8 unk_f6[0x2];
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
    s32 unk_110;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
    s32 unk_120;
    s32 unk_124;
    s32 unk_128;
    u8 unk_12c[0x24];
    Ov010Vec unk_150;
    s32 unk_15c;
    u8 unk_160[0x10];
    u8 unk_170;
    u8 unk_171;
};

void func_ov010_02207520(Obj02207520 *self) {
    self->unk_f0 = 0;
    self->unk_f1 = 0;
    self->unk_f2 = 0;
    self->unk_f3 = 0;
    self->unk_f4 = 0;
    self->unk_f8 = 0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    self->unk_110 = 0;
    self->unk_114 = 0;
    self->unk_118 = 0;
    self->unk_11c = 0;
    self->unk_120 = 0;
    self->unk_124 = 0;
    self->unk_128 = -1;
    MI_CpuFill8((u8 *)self + 0x12c, 0, 0x24);
    self->unk_150 = FLD(Ov010Vec, data_ov010_0220f024, 0x84);
    self->unk_15c = -1;
    self->unk_170 = 0;
    self->unk_171 = 0xff;
}

void func_ov010_022075bc(Obj022075bc *self) {
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
    if (self->unk_124 != NULL) {
        func_0203de1c(self->unk_124);
        self->unk_124 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021d8fa8((u8 *)self + 0x160);
    func_ov010_0220d834((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v08();
    ((Ov010V *)((u8 *)self + 0x1dc))->v08();
    FLD(Ov010Flags8, data_ov000_021ccd54, 0x1cc).b0 = 0;
    func_ov010_02207520((Obj02207520 *)self);
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

struct Obj02207828 : public Ov010Obj {
    u8 unk_ac[0xc];
    Ov010Vec unk_b8;
    u8 unk_c4[0x2f];
    u8 unk_f3;
    u8 unk_f4[0x5c];
    Ov010Vec unk_150;
    u8 unk_15c[0xa0];
    u8 unk_1fc;
    u8 unk_1fd[0x3];
    s32 unk_200;
};

static inline void Ov010_Move(Obj02207828 *self) {
    func_ov003_021d9e90(&self->pos, &self->unk_150, &self->pos, self->unk_9c, self->unk_a0);
    func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
}

void func_ov010_02207828(Obj02207828 *self) {
    Ov010Vec t;
    t.x = self->unk_b8.x;
    t.y = self->unk_b8.y;
    t.z = self->unk_b8.z;
    if (VEC_Distance(&t, &self->pos) >= 0x3000) {
        self->unk_9c += 0x180;
        self->unk_9c = Ov010_Clamp(self->unk_9c, 0, 0xd00);
        Ov010_Move(self);
        return;
    } else {
        BOOL slow = TRUE;
        if (self->unk_9c >= 0x40) {
            slow = FALSE;
        }
        if (func_ov003_021d98bc(&self->pos, &t) || slow) {
            self->unk_9c = 0;
            return;
        }
        self->unk_a4 = 0xf00;
        if (self->unk_9c >= 0x400) {
            self->unk_9c = 0x400;
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

struct Obj0220794c {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x62];
    Ov010Vec unk_70;
    u8 unk_7c[0x2];
    u16 unk_7e;
};

BOOL func_ov010_0220794c(Obj0220794c *self) {
    void *list[0x20];
    Ov010Query q;
    s32 out;
    BOOL found = FALSE;
    s32 n;
    s32 i;
    Ov010Query_Set(&q, &self->unk_70, self->unk_7e, 0x10, 0x5000);
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
            if (st == 0xb && FLD(u16, a, 0x90) == self->unk_0c) {
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
extern void *func_ov010_0220d79c(void *p);
extern void *func_ov003_021d7f0c(void *p);
extern void *func_ov003_021d8b88(void *p);
extern void func_ov003_021cf340(const char *p);
extern void func_ov003_021cf3fc(s32 a);
extern void func_ov003_021cf39c(s32 a, const char *b);
extern void func_ov010_02207520(Obj02207520 *self);
extern void func_ov010_022046ac(void *self);
extern BOOL func_ov010_0220441c(void *self, void *msg);

struct Ov010_02204204_BodySelf {
    void *unk_00;
};

static inline void Ov010_02204204_Body(Ov010_02204204_BodySelf *self) {
    func_ov003_021d0c1c(self);
    self->unk_00 = data_ov010_02210154;
    func_ov003_021d8f24((u8 *)self + 0x160);
    func_ov010_0220d79c((u8 *)self + 0x174);
    func_ov003_021d7f0c((u8 *)self + 0x1b0);
    func_ov003_021d8b88((u8 *)self + 0x1dc);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520((Obj02207520 *)self);
}

u16 func_ov010_02207a44(s32 i) {
    Ov010U16x6 t = FLD(Ov010U16x6, data_ov010_0220f024, 0xb4);
    if (i < 6) {
        return t.v[i];
    }
    return t.v[5] + (u16)((i - 5) * 0x5a);
}

void *func_ov010_02207ac4(Obj02207828 *self) {
    Ov010_02204204_Body((Ov010_02204204_BodySelf *)self);
    self->unk_1fc = 0;
    self->unk_200 = 0;
    *(void * *)self = data_ov010_0220ffe4;
    return self;
}

void func_ov010_02207b6c(Obj02207828 *self) {
    func_ov010_022046ac(self);
    self->unk_f3 = self->unk_18[0] == 3;
}

void func_ov010_02207b90(Obj02207828 *self, void *msg) {
    if (msg != NULL && FLD(u8, msg, 5) == 2) {
        self->unk_1fc = 0;
    }
    func_ov010_0220441c(self, msg);
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern void func_ov003_021d3008(void *self);
extern int func_ov003_021cf408(void);
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
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d64f0(void *self);
extern u16 FX_Atan2(s32 y, s32 x);

void func_ov010_02207d2c(Obj02207828 *self) {
    FLD(Ov010Flags, self->unk_38, 0xc2).b0 = 1;
    switch (self->unk_18[0]) {
    case 0: {
        u16 *st = self->unk_40;
        switch (st[0]) {
        case 0:
            func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
            func_ov000_021915a0(self->unk_38);
            Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
            self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
            self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
            self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
            self->pos.y += 0x5000;
            self->unk_9c = 0xcd;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_02049f44(data_02097e4c, 0x51, &self->pos, 0);
            self->unk_40[0] = 1;
            return;
        case 1:
            if (self->unk_9c >= 0x20) {
                const Ov010Vec *t = &data_ov010_0220f0fc;
                if (self->unk_a4 == 0) {
                    if (VEC_Distance(t, &self->pos) < 0x333) {
                        self->unk_a4 = 0xe66;
                    }
                }
                func_ov003_021d9dbc(&self->pos, t, &self->pos, self->unk_9c, self->unk_a0);
                func_ov003_021da2c8(self, self->unk_9c, self->unk_a0, self->unk_a4, self->unk_a8);
                self->unk_98 = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
                return;
            }
            func_02065f88(0x12f, &self->pos)->v0c(0xe66);
            self->unk_40[0] = 2;
            return;
        case 2:
            st[1]++;
            if (self->unk_40[1] <= 0x5a) {
                return;
            }
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov003_021d64f0(self);
            return;
        }
        return;
    }
    case 1:
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
        self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
        self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
        func_ov003_021d64f0(self);
        return;
    case 2:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        func_ov003_021d64f0(self);
        return;
    case 3:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        func_ov003_021d64f0(self);
        return;
    }
}

extern void VEC_Normalize(const Ov010Vec *src, Ov010Vec *dst);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

void func_ov010_02208018(Obj02207828 *self) {
    if (self->unk_40[0] == 0) {
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        self->pos.y += 0x8000;
        Ov010_VecSet(&self->unk_b8, 0x1da2, -0xb42d, 0x266f);
        Ov010_VecSub(&self->unk_b8, &self->pos, &self->unk_150);
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->unk_98 = FX_Atan2(self->unk_150.x, self->unk_150.z);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->unk_40[0]++;
        return;
    }
    func_ov010_02207828(self);
    if (self->unk_9c == 0) {
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

extern void func_ov000_021911c8(void *a, s32 b);
extern BOOL func_ov000_02191120(void *a);
extern Ov010V *func_ov010_0220ea84(void *self, u16 a, u16 b);
extern const Ov010Vec data_ov010_0220f108;
extern Ov010Vec data_ov010_0220f114;
extern Ov010Vec data_ov010_0220f120;
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void *func_ov003_021da32c(u16 kind);

struct Ov010Rot3 {
    s16 v[3];
};

void func_ov010_0220813c(Obj02207828 *self) {
    switch (self->unk_40[0]) {
    case 0:
        self->unk_40[0] = 10;
        return;
    case 10:
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov010_0220f024, 0x8), 0x266, 0);
        func_ov000_021911c8(self->unk_38, 0x1800);
        self->unk_40[0] = 0xb;
    case 0xb:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40[0] = 0x14;
        }
        return;
    case 0x14: {
        u8 *g;
        func_ov000_02190cb0(self->unk_38, FLD(const char *, data_ov010_0220f024, 0xc), 0x266, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_98 = self->rot_y;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 0x28;
        FLD(u8, g, 0x18f) = 0x28;
        func_ov010_0220ea84(self, 0, self->unk_98)->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        self->unk_40[0] = 0x15;
    }
    case 0x15:
        if (VEC_Distance(&self->pos, &data_ov010_0220f108) <= 0x14000) {
            self->unk_9c += 0x333;
            self->unk_9c = Ov010_Clamp(self->unk_9c, 0, 0x1000);
            func_ov000_0218dbe0(self, 0x1000);
        }
        self->unk_40[1]++;
        if (self->unk_40[1] <= 0x5a) {
            return;
        }
        self->unk_40[1] = 0;
        self->unk_40[0] = 0x1e;
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        return;
    case 0x1e:
        func_02065f88(0x389, &data_ov010_0220f114)->v0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->v0c(0x1800);
        func_02065f88(0x389, &data_ov010_0220f120)->v0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->v0c(0x1800);
        func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        self->unk_40[0] = 0x1f;
        self->unk_40[1] = 0x28;
        return;
    case 0x1f: {
        u16 *st = self->unk_40;
        if (st[1] != 0) {
            st[1]--;
        }
        if (st[1] == 0) {
            self->unk_40[0] = 0x28;
        }
        return;
    }
    case 0x28: {
        Ov010Rot3 r;
        void *o;
        r = FLD(Ov010Rot3, data_ov010_0220f024, 0x5c);
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(Ov010Vec, o, 0x70), 0x2ee1, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0];
        FLD(u16, o, 0x7e) = r.v[1];
        FLD(u16, o, 0x80) = r.v[2];
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(Ov010Vec, o, 0x70), -0x2571, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0];
        FLD(u16, o, 0x7e) = r.v[1];
        FLD(u16, o, 0x80) = r.v[2];
        func_02065f88(0x579, &data_ov010_0220f114)->v0c(0x2000);
        func_02065f88(0x579, &data_ov010_0220f120)->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        self->unk_40[0] = 0x64;
        return;
    }
    case 0x64:
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        self->unk_40[0] = 0x65;
        self->unk_1fc = 1;
        return;
    case 0x65:
        return;
    }
}

}
