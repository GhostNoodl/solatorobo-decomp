#include "ov013/ov013.h"

class Ef13 {
public:
    virtual void Dtor();
    virtual void Delete();
    virtual void SetParam(s32 param);
    virtual void vf0c();
    virtual void SetScale(const Ov013Vec *scale);
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void SetPos(const Ov013Vec *pos);
    virtual void SetPosXYZ(s32 x, s32 y, s32 z);
    virtual void AddPos(const Ov013Vec *delta);
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
    virtual void vf28();
    virtual void vf2c();
    virtual void SetRot(const void *rot);
    virtual void SetRotXYZ(u16 x, u16 y, u16 z);
    u8 pad04[0x20];
    u32 id;
    u8 pad28[0x14];
    s32 speed;
    u8 pad40[0x88];
    s32 loopCount;
};
extern "C" {

extern void *data_ov000_021ccd68;
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u16 func_ov000_0218dfb4(Ov013Actor *a, u16 id);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);

s32 func_ov013_021fc400(Ov013Actor *self) {
    s32 r = 0x10;
    s32 a = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000), 0x4823);
    s32 b = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x5c17);
    if (b >= 2 || a >= 4 || func_ov000_021983b0(self->unk_40, r, 3, 1)) {
        s32 rnd = func_02040498(0x63);
        u16 pct = self->unk_50[0] * 100 / self->unk_50[1];
        FLD(u8, self, 0xf1) = 0;
        if (pct >= 0x4b) {
            r = 0xf;
        } else if (pct >= 0x32) {
            if (rnd % 2 == 0) {
                r = 0xf;
            } else {
                r = 0xe;
            }
        } else {
            if ((u32)rnd % pct < 0x19) {
                FLD(u8, self, 0xf1) = 2;
                FLD(u8, self, 0xf0) = 1;
            }
            r = 0xe;
        }
    }
    if (!func_ov000_021983b0(self->unk_40, 0x10, 7, 1)) {
        r = 0x10;
    }
    return r;
}

void func_ov013_021fc518(Ov013Actor *self) {
    Ov013Sub48 *m;
    s32 n;
    Ov013Actor *a;
    func_ov003_021d112c(self);
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    FLD(u8, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = -1;
    n = func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x5c17);
    FLD(u8, self, 0xf8) = n % 2;
    if (n == 2) {
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x5000, 0x5c17);
        }
        if (a != NULL && a == self) {
            FLD(u8, self, 0xf8) = 1;
        }
    }
    func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x1000, 0);
    func_ov000_021915a0(self->unk_38);
    func_ov000_02198360(self->unk_40, 0xf, 0);
    self->unk_ea_6 = 1;
    self->unk_93_4 = 1;
    self->unk_b6 = 100;
}

void func_ov013_021fc624(Ov013Actor *self) {
    Ov013Actor *p;
    u8 k;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    k = self->unk_40->unk_13;
    if (FLD(u8, self, 0xf0) != 0 && k != 0x15 && k != 9) {
        self->unk_40->flags |= 4;
    }
    if (k != 1 || self->unk_40->state != 0x63) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x8000;
    self->unk_b6 = 300;
}

void func_ov013_021fc71c(Ov013Actor *self) {
    Ov013Sub40 *s = self->unk_40;
    Ov013Actor *t;
    if (s->unk_0c[0] == 4 && s->unk_0c[1] == 10 && s->unk_0c[2] == 9) {
        func_ov000_02198360(s, 0xf, 0);
        return;
    }
    if (s->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
    }
    self->rot[1] = func_01ffc128(0, self->rot[1], 0xcd, 1, 0x8000);
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
    }
}

extern void *data_0214a420;
extern void *data_02097e4c;
extern const Ov013Vec data_ov013_0220ae64;
extern u8 data_ov013_0220ae88[];
extern const Ov013Vec data_ov013_0220b5a0[];
extern void func_02065804(void *a, s32 b);
extern Ov013V *func_020657b0(void *a, s32 b);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern Ov013Vec func_ov003_021dadc0(const Ov013Vec *a, const Ov013Vec *b);
extern void func_ov000_0219a210(Ov013Vec *v, const Ov013Vec *a, s32 b);
extern void func_ov000_0218d918(Ov013Actor *self, Ov013Vec *v, s32 a);
extern void func_ov000_0218ddd4(Ov013Actor *self, Ov013Vec *v, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const Ov013Vec *a, const Ov013Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

// Enum-typed locals keep their constants out of IRO's propagation (round lfA), so the spawn kind and
// the sound pitch are built where they are assigned (rounds o4B, cmA).
typedef enum { OV013_EF_KIND_FC7E0 = 0x192 } Ov013EfKind;
typedef enum { OV013_SND_PITCH_NONE = 0 } Ov013SndPitch;
void func_ov013_021fc7e0(Ov013Actor *self) {
    Ov013SndPitch pitch;
    Ov013EfKind kind;
    Ov013Actor *pl = func_ov000_0218d240(self);
    if (pl == NULL) {
        return;
    }
    Ov013Vec tgt = {0, 0, 0};
    switch (self->unk_40->state) {
    case 0: {
        Ov013Sub48 *m;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0xcd;
        tgt = self->pos;
        tgt.y += 0x1000;
        self->unk_b8 = tgt;
        m = self->unk_48;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
        self->unk_40->state = 1;
        self->unk_40->timer = 0;
        break;
    }
    case 1: {
        u16 r;
        Ef13 *o;
        tgt = self->unk_b8;
        if (self->pos.y < tgt.y) {
            func_ov000_0218dbe0(self, 0);
            if (self->pos.y > tgt.y) {
                self->pos.y = tgt.y;
            }
            break;
        }
        tgt = pl->pos;
        {
            Ov013Vec dir = func_ov003_021dadc0(&self->pos, &tgt);
            VEC_MultAdd(0x1800, &dir, &tgt, &tgt);
        }
        self->unk_b8 = tgt;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5ca, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0x2b8;
        self->unk_a0 = -0xcd;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        r = self->rot[1];
        func_ov000_0218d918(self, &tgt, 0x1000);
        self->unk_98 = self->rot[1];
        self->rot[1] = r;
        kind = OV013_EF_KIND_FC7E0;
        {
            Ov013Vec v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->unk_98);
            o = (Ef13 *)func_02065f88(kind, &v);
        }
        pitch = OV013_SND_PITCH_NONE;
        FLD(s32, self, 0xf4) = o->id;
        o->SetRotXYZ(0, self->unk_98, 0);
        o->speed = 0xb33;
        o->SetScaleXYZ(0x800, 0x800, 0x800);
        o->loopCount = -1;
        func_02049f44(data_02097e4c, 100, &self->pos, pitch);
        self->unk_40->state = 20;
        self->unk_40->timer = 0;
        break;
    }
    case 20: {
        Ef13 *o;
        tgt = self->unk_b8;
        func_ov000_0218ddd4(self, &tgt, 0);
        func_ov000_0218d918(self, &tgt, 0x400);
        if (self->pos.y < 0x99a) {
            self->pos.y = 0x99a;
        }
        func_ov000_0219aae8(self, self, 0x1e, 0x20, 1 << (pl->id >> 12), data_ov013_0220ae88, NULL, self->unk_64, 0, 100, 0x1000);
        o = (Ef13 *)func_020657b0(data_0214a420, FLD(s32, self, 0xf4));
        if (o != NULL) {
            Ov013Vec v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->unk_98);
            o->SetPos(&v);
            o->SetRotXYZ(0, self->rot[1], 0);
        }
        if (Ov013_DistXZ(&self->pos, &tgt) < 0x19a) {
            self->unk_a0 = 0x29;
            self->unk_b8 = data_ov013_0220b5a0[FLD(u8, self, 0xf8)];
            self->unk_40->state = 21;
            self->unk_40->timer = 0;
        }
        break;
    }
    case 21: {
        Ef13 *o;
        u16 t;
        {
            Ov013Sub40 *s = self->unk_40;
            s->timer++;
            t = s->timer;
        }
        tgt = self->unk_b8;
        if (t > 0x1e) {
            func_ov000_0218d918(self, &tgt, 0x11f);
        }
        if (self->pos.y > data_ov013_0220b5a0[FLD(u8, self, 0xf8)].y) {
            self->pos.y = data_ov013_0220b5a0[FLD(u8, self, 0xf8)].y;
        }
        func_ov000_0219aae8(self, self, 0x1e, 0x20, 1 << (pl->id >> 12), data_ov013_0220ae88, NULL, self->unk_64, 0, 100, 0x1000);
        if (func_01ffc198(&self->pos, &tgt, 0xccd)) {
            func_ov000_0218d918(self, &tgt, 0x1000);
        }
        if (t > 500) {
            func_ov000_0218d918(self, &tgt, 0x1000);
        }
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        o = (Ef13 *)func_020657b0(data_0214a420, FLD(s32, self, 0xf4));
        if (o != NULL) {
            Ov013Vec v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->unk_98);
            o->SetPos(&v);
            o->SetRotXYZ(0, self->rot[1], 0);
        }
        if (VEC_Distance(&tgt, &self->pos) >= 0x19a) {
            break;
        }
        self->pos = tgt;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        func_02065804(data_0214a420, FLD(s32, self, 0xf4));
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
        break;
    }
    case 0x63:
    {
        Ov013Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer > 0x1e) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
}

}
