#include "ov013/ov013.h"

extern "C" {

extern const u8 data_ov003_021f4344;
extern char data_ov013_0220ba79[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov013Sub48 *p);
extern void func_ov003_021cf330(void *p, const char *name, u8 a);
extern BOOL func_ov000_021950e8(Ov013Actor *self, Ov013Msg *msg);

void func_ov013_02205fa4(Ov013Actor *self) {
    Ov013Sub48 *m;
    func_ov000_02194758(self);
    switch (self->kind) {
    case 0x4808:
        FLD(u16, self, 0xd0) = 0x1555;
        break;
    case 0x4809:
        FLD(u16, self, 0xd0) = 0xeaaa;
        break;
    }
    self->unk_38->unk_c2_0 = 0;
    func_ov000_02198360(self->unk_40, 0x20, 0);
    m = self->unk_48;
    m->unk_9a_1 = 1;
    m->unk_9a_4 = 1;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->unk_48->unk_9a_6 = 0;
    self->unk_48->unk_30 = 0x20000000;
    func_ov003_021cf330((u8 *)self + 0xe0, data_ov013_0220ba79, data_ov003_021f4344);
}

BOOL func_ov013_02206074(Ov013Actor *self, Ov013Msg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        if (FLD(u8, msg, 8) == 1) {
            FLD(Ov013Flags8, self, 0xce).b1 = 1;
        }
        r = TRUE;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

void func_ov013_022060c8(void) {
}

struct Ov013Blk12 {
    s32 w[3];
};

extern void *data_02097e4c;
extern const Ov013Vec data_ov013_0220b2cc;
extern char data_ov013_0220b290[];
extern const Ov013Blk12 data_ov013_0220b2a8;
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern Ov013Actor *func_ov000_02199ba0(void *p);
extern void VEC_Normalize(const Ov013Vec *a, Ov013Vec *b);
extern void func_ov013_02205c74(Ov013Vec *dir, Ov013Vec *target, Ov013Vec *pos, Ov013Vec *n, u16 rate);
extern void func_ov000_0219bd20(u16 kind, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_0204a028(void *a, s32 b, Ov013Vec *c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov013Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);

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

static inline s32 Ov013_DistXZ3(const Ov013Vec *a, const Ov013Vec *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

static inline void Ov013_Steer(Ov013Actor *self, Ov013Vec *t, u16 rate) {
    Ov013Vec n;
    VEC_Normalize(&FLD(Ov013Vec, self, 0xd4), &n);
    func_ov013_02205c74(&FLD(Ov013Vec, self, 0xd4), t, &self->pos, &n, rate);
}

void func_ov013_022060cc(Ov013Actor *self) {
    Ov013Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov013Vec v;
        Ov013Actor *o;
        self->unk_38->unk_c2_0 = 1;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov003_021d9980(&v, self->rot[1], &data_ov013_0220b2cc);
        VEC_MultAdd(0x14000, &v, &self->pos, &self->unk_84);
        o = func_ov000_0218d240(self);
        if (o == NULL || o->unk_48 == NULL) {
            self->unk_40->state = 0x15;
            break;
        }
        self->unk_84.y = FLD(s32, o->unk_48, 0x6c) + 0xccd;
        self->unk_40->state = 10;
        self->unk_40->timer = 0;
        break;
    }
    case 10: {
        s32 sp = self->unk_9c + 0x40;
        Ov013Vec t;
        s32 d;
        if (sp > 0x1600) {
            sp = 0x1600;
        } else if (sp < 0) {
            sp = 0;
        }
        self->unk_9c = sp;
        t = self->unk_84;
        d = Ov013_DistXZ3(&self->pos, &t);
        if (d > 0x5000) {
            d = 0x5000;
        }
        t.y += d - 0x5000;
        Ov013_Steer(self, &t, FLD(u16, self, 0xd2));
        VEC_MultAdd(self->unk_9c, &FLD(Ov013Vec, self, 0xd4), &self->pos, &self->pos);
        {
            s32 r = FLD(u16, self, 0xd2) + 8;
            if (r > 0x800) {
                r = 0x800;
            } else if (r < 0) {
                r = 0;
            }
            FLD(u16, self, 0xd2) = r;
        }
        if (VEC_Distance(&self->pos, &self->unk_84) <= 0x3000) {
            const char *p = data_ov013_0220b290;
            func_ov000_0219bd20(self->kind, self->id, 0xe, FALSE, 1, &p);
            self->unk_40->state = 0x14;
        } else if (FLD(Ov013Flags8, self, 0xce).b1) {
            self->unk_40->state = 0x14;
        }
        {
            Ov013Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer % 20 == 0) {
                func_0204a028(data_02097e4c, 9, &self->pos, -5);
            }
        }
        break;
    }
    case 0x14: {
        Ov013Actor *pl;
        Ov013Vec t;
        s32 d;
        FLD(Ov013Flags8, self, 0xce).b0 = 1;
        self->unk_9c = Ov013_FxMul(self->unk_9c, 0xf40);
        self->unk_9c = self->unk_9c < 0x400 ? 0x400 : self->unk_9c;
        pl = func_ov000_02199ba0(FLD(void *, self, 0x4c));
        if (pl == NULL) {
            self->unk_40->state = 0x15;
            break;
        }
        {
            s32 r = FLD(u16, self, 0xd2) + 8;
            if (r > 0x2000) {
                r = 0x2000;
            } else if (r < 0) {
                r = 0;
            }
            FLD(u16, self, 0xd2) = r;
        }
        t = pl->pos;
        d = Ov013_DistXZ3(&self->pos, &t);
        if (d > 0x5000) {
            d = 0x5000;
        }
        t.y -= Ov013_FxMul(d, 0x99a);
        Ov013_Steer(self, &t, FLD(u16, self, 0xd2));
        VEC_MultAdd(self->unk_9c, &FLD(Ov013Vec, self, 0xd4), &self->pos, &self->pos);
        {
            Ov013Sub40 *q = self->unk_40;
            q->timer++;
            if (q->timer % 20 == 0) {
                func_0204a028(data_02097e4c, 9, &self->pos, -5);
            }
        }
        break;
    }
    case 0x15:
        func_ov000_02198360(st, 0x15, 0);
        break;
    }
    self->rot[1] += FLD(u16, self, 0xd0);
    {
        Ov013Blk12 off = data_ov013_0220b2a8;
        func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, (Ov013Vec *)&off, 0, 0x3000, 0xccd, 0x64, 0x1000);
    }
}

}
