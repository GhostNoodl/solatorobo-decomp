#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov009_02215dc0[];
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b, s32 c);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021ffff4(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
    }
    func_ov003_021d5900(self);
}

void func_ov009_02200034(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void func_ov009_02200070(Ov009Actor *self) {
    Ov009Vec t;
    u32 saved;
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf8) = self->pos;
    self->unk_84 = self->pos;
    FLD(u8, self, 0xf0) = 0;
    func_01ffc9fc(&t, data_ov009_02215dc0, 0x5554, 0);
    VEC_Add(&self->unk_84, &t, &self->pos);
    self->unk_b8 = self->pos;
    switch (self->kind) {
    case 0x5423:
        FLD(s32, self, 0xf4) = 0x32000;
        break;
    case 0x5424:
        FLD(s32, self, 0xf4) = 0x6000;
        break;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            func_0203de1c(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_44 != NULL) {
        func_0203de1c(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d398(Ov009Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, Ov009Vec *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov009V *func_02065f88(s32 id, Ov009Vec *pos);
extern s32 VEC_Distance(const Ov009Vec *a, const Ov009Vec *b);

struct Ov009Bits3 {
    u16 b0 : 3;
};

struct Ov009Bits32 {
    u32 b0 : 1;
    u32 b1 : 1;
};

struct Ov009HitMsg2 {
    u8 a;
    u16 b;
    u16 c;
};

static inline s32 Ov009_StateOf(Ov009Sub40 *s) {
    return s != NULL ? s->unk_13 : 0;
}

void func_ov009_022001e8(Ov009Actor *self) {
    Ov009Vec v;
    Ov009HitMsg2 msg;
    Ov009Actor *pl;
    func_ov003_021d1e8c(self);
    pl = func_ov000_0219bf90();
    if (pl == NULL || *pl->unk_50 == 0) {
        return;
    }
    if (!(FLD(u8, self, 0xf0) & 1)) {
        return;
    }
    if (Ov009_StateOf(pl->unk_40) == 7 || Ov009_StateOf(pl->unk_40) == 0x16 || Ov009_StateOf(pl->unk_40) == 0x10) {
        FLD(u8, self, 0xf0) ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    } else if (FLD(Ov009Bits3, func_ov000_0219bf90(), 0xb22).b0 == 4) {
        FLD(u8, self, 0xf0) ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    } else if (Ov009_GameIdle()) {
        s16 cnt = FLD(s16, self, 0x18);
        switch (self->kind) {
        case 0x5424:
            msg.a = 1;
            msg.b = 0x333;
            msg.c = 0xf;
            func_ov000_0218d398(pl, self->id, 0xb, TRUE, 6, &msg);
            cnt++;
            if (cnt % 200 == 0) {
                Ov009V *e;
                cnt = 0;
                func_ov000_0219aae8(self, self, 0xa, 1, 2, NULL, 0, 0x2000, 0, -1, 0x1000);
                v.x = pl->pos.x;
                v.y = pl->pos.y;
                v.z = pl->pos.z;
                e = func_02065f88(0x38b, &v);
                e->v0c(0xb33);
                e->v24(0, 0x1000, 0);
                func_0204a028(data_02097e4c, 0x54, &v, -5);
            }
            FLD(s16, self, 0x18) = cnt;
            break;
        case 0x5423:
            if (FLD(Ov009Bits32, pl, 0xb24).b1) {
                cnt++;
                if (cnt % 100 == 0) {
                    cnt = 0;
                    func_0204a028(data_02097e4c, 0x36, &self->pos, -10);
                }
                FLD(s16, self, 0x18) = cnt;
                msg.a = 2;
                msg.c = 8;
                func_ov000_0218d398(pl, self->id, 0xb, TRUE, 6, &msg);
            }
            break;
        }
    }
    if (self->kind == 0x5423 && VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xf8)) > FLD(s32, self, 0xf4)) {
        FLD(u8, self, 0xf0) ^= 1;
        func_ov000_02198360(self->unk_40, 0x13, 0);
    }
}

extern void *data_ov009_02215d0c[];
extern u8 data_ov009_02215dcc[];
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern u16 FX_Atan2(s32 y, s32 x);
typedef void (*Ov009RotFn)(Ov009Vec *out, const void *a, s32 b);

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline BOOL Ov009_TickTimer(Ov009Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
    return s->timer == 0;
}

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_02200534(Ov009Actor *self) {
    Ov009Vec plpos;
    Ov009Vec off;
    Ov009Vec d;
    Ov009Actor *pl;
    Ov009Sub40 *st;
    s32 speed;
    u16 ang;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    plpos = pl->pos;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->timer = 0x3c;
            FLD(Ov009Vec, self, 0x104) = self->unk_b8;
            FLD(s32, self, 0x104) += func_02040528(0x800);
            FLD(s32, self, 0x10c) += func_02040528(0x800);
            FLD(s32, self, 0x108) += func_02040528(0x800);
        }
        d.x = FLD(s32, self, 0x104) - self->pos.x;
        d.y = FLD(s32, self, 0x108) - self->pos.y;
        d.z = FLD(s32, self, 0x10c) - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->unk_84, &plpos) <= FLD(s32, self, 0xf4)) {
            self->unk_40->state++;
        }
        break;
    case 2: {
        s64 sq;
        s32 dz;
        s32 dx;
        self->unk_84 = self->pos;
        ((Ov009RotFn)func_01ffc9fc)(&off, data_ov009_02215dcc, 0x5554);
        VEC_Add(&plpos, &off, &plpos);
        dz = self->pos.z - plpos.z;
        dx = self->pos.x - plpos.x;
        sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        ang = FX_Atan2(Ov009_Sqrt64(sq), plpos.y - self->pos.y);
        switch (self->kind) {
        case 0x5423:
            speed = 0x800;
            break;
        case 0x5424:
            speed = 0x333;
            break;
        }
        self->unk_9c = Ov009_FxMul(speed, OV009_SIN(ang));
        self->unk_a0 = Ov009_FxMul(speed, OV009_COS(ang));
        func_ov000_0218d918(self, &plpos, 0x1000);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        if (VEC_Distance(&self->pos, &plpos) > 0x1000) {
            return;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->kind == 0x5423) {
            self->unk_9c = 0x4cd;
        } else {
            self->unk_9c = speed;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        FLD(u8, self, 0xf0) |= 1;
        break;
    }
    case 3:
        func_ov000_0218dbe0(self, 0);
        self->pos.y = plpos.y + 0x2000;
        func_ov000_0218d918(self, &plpos, 0x19a);
        self->unk_98 = self->rot[1];
        self->unk_84 = plpos;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        {
            s32 se = 0x80;
            if (self->kind == 0x5423) {
                se = 0xa;
            }
            func_02049f44(data_02097e4c, se, &self->pos, 0);
        }
        self->unk_40->timer = 0x1e;
        break;
    }
}

}
