#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

struct Ov013Pair {
    u8 a;
    u8 b;
};

typedef void (Ov013Actor::*Ov013ActFn)();

struct Ov013StEnt {
    u8 key;
    Ov013ActFn fn;
};

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

struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01;
    s16 unk_02;
    Ov013Vec v;
    Ov013Vec w;
};

extern "C" {

extern BOOL func_ov003_021da03c(Ov013Actor *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov013Pair func_ov003_021d9644(void *p);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern void func_ov003_021d6548(Ov013Actor *self, void *p);
extern void func_ov003_021d68e0(Ov013Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern BOOL func_ov003_021d1c00(Ov013Actor *self, Ov013Msg *msg);

void func_ov013_021ff1ec(void) {
}

void func_ov013_021ff1f0(Ov013Actor *self) {
    Ov013Pair p;
    if (!func_ov003_021da03c(self)) {
        return;
    }
    self->unk_93_4 = 1;
    self->unk_c4 = 0;
    FLD(Ov013Flags8, self, 0xf0).b0 = 0;
    func_ov003_021d8fc0((u8 *)self + 0x14c);
    if (!func_ov003_021d9878((u8 *)self + 0x14c)) {
        return;
    }
    p = func_ov003_021d9644((u8 *)self + 0x14c);
    FLD(u8, self, 0x15c) = p.a;
    FLD(u8, self, 0x15d) = p.b;
    func_ov000_02198360(self->unk_40, p.a, 1);
}

void func_ov013_021ff288(Ov013Actor *self) {
    func_ov003_021da40c(self->unk_40);
    func_ov000_0218d7e8(self, self->unk_40->unk_13);
}

static inline void Ov013_Ack(Ov013Actor *self, Ov013Msg *msg) {
    self->unk_30 |= 1 << msg->type;
    msg->type = 0;
}

static inline BOOL Ov013_Ignore(Ov013Actor *self, Ov013Msg *msg) {
    if (FLD(Ov013Flags8, self, 0xf0).b0 && msg->type == 9) {
        Ov013_Ack(self, msg);
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Ov013_IsInvul(u16 *hp) {
    return hp[5] != 0;
}

static inline BOOL Ov013_IsBusy(u8 s) {
    BOOL r = FALSE;
    switch (s) {
    case 2:
    case 0xf:
    case 0x15:
    case 0x20:
    case 0x29:
    case 0x2a:
        r = TRUE;
        break;
    }
    return r;
}

static inline BOOL Ov013_CanFlinch(Ov013Actor *self, Ov013Msg *msg) {
    BOOL r = FALSE;
    if (msg->type == 9) {
        if (!Ov013_IsBusy(self->unk_40->unk_13)) {
            r = TRUE;
        }
    }
    return r;
}

BOOL func_ov013_021ff2ac(Ov013Actor *self, Ov013Msg *msg) {
    if (FLD(Ov013Flags8, self, 0xf0).b0 && msg->type == 9) {
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    if (msg->type == 9) {
        if (!Ov013_IsInvul(self->unk_50) && self->unk_40->unk_13 != 0x20) {
            self->unk_50[2] = FLD(u16, msg, 6);
            func_ov003_021d6548(self, (u8 *)msg + 8);
            func_ov003_021d68e0(self, 0x14bf, 0x739f, 10);
            self->unk_50[5] = 5;
            func_ov000_02191418(self->unk_38, 5, 0);
            if (self->unk_50[0] == 0) {
                self->unk_40->flags |= 0x200000;
            } else if (Ov013_CanFlinch(self, msg)) {
                func_ov000_02198360(self->unk_40, 0x12, 1);
            }
        }
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

extern const Ov013StEnt data_ov013_0220b1ac[];
extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af34;
extern void *data_0214a420;
extern void func_ov003_021d3008(Ov013Actor *self);
extern void func_ov000_0218fa28(void *a, void *b, void *c, void *d, const char *e, s32 f, s32 g);
extern u8 func_ov003_021cf408(void);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_020657b0(void *a, s32 b);
extern void func_02065860(void *a, s32 b);
extern void func_ov003_021d6868(Ov013Actor *self, s32 a);
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_0203f364(void *p);
extern void func_0203f324(void *p);

struct Ov013Blk12 {
    s32 w[3];
};

static inline void Ov013_MoveToward(Ov013Vec *v, const Ov013Vec *w, s32 k, Ov013Vec &d) {
    d.x = w->x - v->x;
    d.y = w->y - v->y;
    d.z = w->z - v->z;
    VEC_MultAdd(k, &d, v, v);
}


void func_ov013_021ff45c(Ov013Actor *self) {
    Ov013Vec w;
    Ov013Vec d;
    Ov013Vec off;
    Ov013Vec pos;
    u32 i;
    u8 key = self->unk_40->unk_13;
    for (i = 0; i < 9; i++) {
        if (key == data_ov013_0220b1ac[i].key && *(s32 *)((u8 *)&data_ov013_0220b1ac[i] + 4) != 0) {
            (self->*data_ov013_0220b1ac[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (FLD(Ov013Flags8, self, 0xf0).b4) {
        const char *anim;
        void *m;
        if (FLD(Ov013Flags8, self, 0xf0).b3) {
            anim = FLD(const char *, data_ov013_0220aedc, 0x10);
        } else {
            anim = FLD(const char *, data_ov013_0220aedc, 0x14);
        }
        m = self->unk_38;
        if (FLD(void *, m, 0x1c) != NULL) {
            void *o = FLD(void *, m, 0);
            func_ov000_0218fa28(FLD(void *, m, 0x1c), (u8 *)m + 0x24, o, FLD(void *, FLD(void *, o, 0x48), 0x10), anim, 0x1000, 0);
        }
    }
    FLD(Ov013Flags8, self, 0xf0).b4 = 1;
    if (func_ov003_021cf408()) {
        FLD(u8, self, 0x15) = func_ov003_021cf408();
    }
    {
        Ov013Opt120 *p = FLD(Ov013Opt120 *, self, 0x120);
        if (p->b0) {
            Ov013_MoveToward(&p->v, &p->w, p->unk_02, d);
            p->w = FLD(Ov013Vec, data_ov013_0220aedc, 0x4c);
        }
    }
    {
        Ov013Obj1c *q = FLD(Ov013Obj1c *, self, 0x124);
        if (q->b0 && q->b1) {
            if (q->unk_04 % 10 == 0) {
                void *a = q->unk_14->unk_38;
                FLD(u16, a, 0xb6) = 0x7fff;
                FLD(u16, a, 0xb8) = 0x3eaf;
                FLD(u16, a, 0xba) = 6;
                FLD(u16, a, 0xbc) = 5;
            }
            if (q->unk_04 % 50 == 0) {
                Ov013_VecCopy(&pos, &q->unk_14->pos);
                q->unk_18(&off, &q->v, q->unk_14);
                VEC_Add(&pos, &off, &pos);
                func_02065f88(0x66, &pos)->v0c(q->unk_02);
            }
            q->unk_04++;
        }
    }
    ((Ov013V *)((u8 *)self + 0x12c))->v0c();
    if (!FLD(Ov013Flags8, self, 0xf0).b1) {
        Ov013Obj1c *q = FLD(Ov013Obj1c *, self, 0x124);
        if (q->b0 && q->b1) {
            q->b1 = 0;
        }
    }
    FLD(Ov013Flags8, self, 0xf0).b1 = 0;
    if (self->pos.y > -0xee1) {
        if (func_020657b0(data_0214a420, FLD(s32, self, 0x104)) == NULL && !FLD(Ov013Flags8, self, 0xf0).b2) {
            Ov013Vec v;
            Ov013V *e;
            func_ov003_021d9980(&v, self->rot[1], &data_ov013_0220af34);
            VEC_Add(&v, &self->pos, &v);
            *(Ov013Blk12 *)&w = *(Ov013Blk12 *)&v;
            w.y = 0x1000;
            e = func_02065f88(0x2bd, &w);
            e->v0c(0x4000);
            FLD(s32, self, 0x104) = FLD(s32, e, 0x24);
        }
    } else {
        func_02065860(data_0214a420, FLD(s32, self, 0x104));
        FLD(s32, self, 0x104) = 0;
        func_ov003_021d6868(self, 0x4698);
    }
    FLD(Ov013Flags8, self, 0xf0).b2 = 0;
    if (self->unk_40->unk_13 != 0x15) {
        if (self->pos.y < -0xc000) {
            self->unk_38->unk_c2_0 = 0;
        } else {
            s32 a;
            self->unk_38->unk_c2_0 = 1;
            a = 0x1f;
            if (self->pos.y < -0x8000) {
                a = 0x1f >> (5 - ((self->pos.y + 0xd000) >> 12));
            }
            if (a > 0x1f) {
                a = 0x1f;
            } else if (a < 1) {
                a = 1;
            }
            FLD(u8, self->unk_38, 0xbe) = a;
        }
    }
    if (FLD(Ov013Flags8, self, 0xf0).b0) {
        Ov013Sub48 *m = self->unk_48;
        if (m != NULL) {
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
    } else {
        Ov013Sub48 *m = self->unk_48;
        if (m != NULL) {
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
        }
        self->unk_ea_0 = 0;
    }
}

}
