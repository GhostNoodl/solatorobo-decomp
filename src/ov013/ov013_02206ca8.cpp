#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220be7c[];
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);

void func_ov013_02206ca8(Ov013Actor *self) {
    Ov013Actor *t;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, 0xcd);
    }
}

extern void *data_ov000_021ccd68;
extern char data_ov013_0220be82[];
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_021911c8(void *p, s32 a);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_02206d28(Ov013Actor *self) {
    Ov013Actor *t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        self->unk_ee_2 = 0;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be82, 0x2ab, 0);
        func_ov000_021911c8(self->unk_38, 0x99a);
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        self->unk_ea_0 = 3;
        break;
    case 1:
        func_ov000_0218d988(self, t, 0x400);
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        self->unk_40->state = 5;
        self->unk_40->timer = 0;
        func_ov000_021911c8(self->unk_38, 0x1000);
        break;
    case 5:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        FLD(u8, self, 0xfd) = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        break;
    case 10: {
        Ov013Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x14) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

struct Ov013Blk12 {
    s32 w[3];
};

extern void *data_02097e4c;
extern char data_ov013_0220be88[];
extern const Ov013Blk12 data_ov013_0220b3e0;
extern void *func_ov000_0218e4cc(void *mgr, s32 a);
extern u16 func_ov000_0218dfb4(void *p, s32 a);
extern Ov013Actor *func_ov003_021d69a0(Ov013Actor *self, s32 a, s32 b);
extern void func_ov000_0219a210(Ov013Vec *p, Ov013Vec *o, u16 rot);
extern void *func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);

void func_ov013_02206edc(Ov013Actor *self) {
    s32 flip;
    Ov013Actor *a;
    void *mgr;
    Ov013Actor *t;
    t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        self->unk_ee_2 = 1;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be88, 0x2ab, 0);
        self->unk_40->state = 5;
        self->unk_40->timer = 0;
        break;
    case 5:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            mgr = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
            if (mgr != NULL) {
                flip = func_02040498(1);
                if (func_ov000_0218dfb4(mgr, 0x540c) < 2) {
                    Ov013Vec p;
                    Ov013Vec o;
                    Ov013Blk12 base = data_ov013_0220b3e0;
                    do {
                        a = func_ov003_021d69a0(self, 0x540c, 0x20);
                        if (a != NULL) {
                            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
                            *(Ov013Blk12 *)&o = base;
                            o.x = func_02040498(0x1800) + 0x1000;
                            o.y = func_02040528(0x666) + -0x333;
                            if (!flip) {
                                flip = 1;
                            } else {
                                o.x = -o.x;
                                flip = 0;
                            }
                            func_ov000_0219a210(&p, &o, self->rot[1]);
                            if (p.z < -0x5000) {
                                p.z = -0x5000;
                            }
                            if (p.y > 0x6000) {
                                p.y = 0x6000;
                            }
                            Ov013_VecCopy(&a->pos, &p);
                        }
                    } while (func_ov000_0218dfb4(mgr, 0x540c) < 2);
                }
            }
        }
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_0204a028(data_02097e4c, 0x54, &self->pos, 5);
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        FLD(u8, self, 0xfd) = 0;
        break;
    case 10: {
        Ov013Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x2d) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

extern char data_ov013_0220be8e[];
extern const Ov013Blk12 data_ov013_0220b3d4;
extern const Ov013Blk12 data_ov013_0220b3c8;
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern Ov013Actor *func_ov000_0219be1c(s32 kind, Ov013Vec *pos, u16 *rot, u16 id, u16 owner);
extern void func_ov000_0219bebc(Ov013Actor *a, s32 b);
extern u8 *func_0206fef8(u16 kind);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov013_Sqrt2(s64 sq) {
    OV013_SQRTCNT = 1;
    OV013_SQRT_PARAM = (u64)(sq << 2);
    while (OV013_SQRTCNT & 0x8000) {
    }
    return (s32)(OV013_SQRT_RESULT + 1) >> 1;
}

void func_ov013_02207180(Ov013Actor *self) {
    s16 r;
    s32 tx;
    s32 ty;
    s32 tz;
    Ov013Actor *t;
    t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be8e, 0x2ab, 0);
        self->unk_40->state = 1;
        break;
    case 1:
        func_ov000_0218d988(self, t, 0x400);
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        self->unk_40->state = 5;
        func_02049f44(data_02097e4c, 0x43, &self->pos, 0);
        break;
    case 5: {
        Ov013Vec p;
        Ov013Actor *a;
        u16 id;
        if (FLD(s16, self->unk_38, 0xc4) != 2) {
            return;
        }
        FLD(u16, self, 0xde) = 0xffff;
        *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
        {
            Ov013Vec o = {0, 0, self->unk_48->unk_38 + 0x5800};
            func_ov000_0219a210(&p, &o, self->rot[1]);
        }
        tz = t->pos.z;
        tx = t->pos.x;
        ty = t->pos.y;
        if (ty > 0x2000) {
            ty = 0x2000;
        }
        {
            s32 dz = self->pos.z - tz;
            s32 dx = self->pos.x - tx;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            if (Ov013_Sqrt2(sq) > 0x11000) {
                ty = 0x800;
            }
        }
        r = FLD(s16, self, 0xfe);
        a = func_ov000_0219be1c(0x4811, &p, self->rot, self->id, self->unk_90);
        if (a != NULL) {
            FLD(s32, a, 0xd0) = 0xd9a;
            FLD(s32, a, 0xd4) = tx;
            FLD(s32, a, 0xd8) = ty;
            FLD(s32, a, 0xdc) = tz - 0x400;
            FLD(u16, func_0206fef8(a->kind), 0x10) = 0xd9a;
            func_ov000_0219bebc(a, r);
            id = a->id;
        } else {
            id = 0xffff;
        }
        FLD(u16, self, 0xde) = id;
        self->unk_40->state = 7;
        self->unk_40->timer = 0;
        break;
    }
    case 7: {
        Ov013Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 10) {
            return;
        }
        {
            Ov013Vec p;
            Ov013Vec o;
            Ov013Vec s;
            Ov013V *e;
            *(Ov013Blk12 *)&p = *(Ov013Blk12 *)&self->pos;
            *(Ov013Blk12 *)&o = data_ov013_0220b3d4;
            *(Ov013Blk12 *)&s = data_ov013_0220b3c8;
            func_ov000_0219a210(&p, &o, self->rot[1]);
            e = func_02065f88(0x12c, &p);
            e->v10(&s);
            e->v34(0, self->rot[1], 0);
        }
        self->unk_40->state = 6;
        break;
    }
    case 6:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        FLD(u8, self, 0xfd) = 0;
        break;
    case 10: {
        Ov013Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x2d) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

}
