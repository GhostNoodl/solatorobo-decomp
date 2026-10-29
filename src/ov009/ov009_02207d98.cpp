#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern BOOL func_ov000_0218ffdc(Ov009Sub38 *m, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov009Sub38 *m, u16 *rot, s32 a);
extern BOOL func_ov000_021903b4(Ov009Sub38 *m);
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL func_ov009_02207d98(Ov009Multi *self) {
    BOOL r = func_ov003_021d16cc(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        func_ov000_021903b4(&self->models[i]);
    }
    return r;
}

struct Ov009Query {
    u32 unk_00;
    Ov009Vec pos;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1a[2];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u16 unk_2c;
    u8 unk_2e_0 : 2;
    u8 unk_2e_2 : 1;
    u8 unk_2e_3 : 1;
    u8 unk_2e_4 : 4;
};

static inline void Ov009Query_Set(Ov009Query *q, const Ov009Vec *pos, u16 ang) {
    q->pos = *pos;
    q->unk_10 = ang;
    q->unk_00 = 0;
}

extern s32 func_ov000_02199180(Ov009Query *q, Ov009Vec *pos, Ov009Actor **out, s32 max);

void func_ov009_02207dd0(Ov009Actor *self) {
    Ov009Query q;
    Ov009Actor *res[0x20];
    s32 n;
    s32 i;
    if (!Ov009_GameIdle()) {
        return;
    }
    switch (FLD(u16, self, 0xb4)) {
    case 0:
        if (self->unk_40->unk_13 != 1 || FLD(u8, self, 0x490) != 4) {
            return;
        }
        self->unk_90 = 0xffff;
        q.unk_2c = 0xffff;
        *(u8 *)((u8 *)&q + 0x2e) = 0;
        q.unk_16 = 0xcc00;
        q.unk_18 = 0x3400;
        q.unk_1c = 0;
        q.unk_20 = 0xa000;
        q.unk_2e_2 = 1;
        q.unk_24 = -0x1000;
        q.unk_14 = 0xffff;
        q.unk_28 = 0x3000;
        q.unk_2e_3 = 1;
        q.unk_12 = 0x22;
        q.unk_2c = self->id;
        Ov009Query_Set(&q, &FLD(Ov009Vec, self, 0x494), FLD(u16, self, 0x492));
        n = func_ov000_02199180(&q, &q.pos, res, 0x20);
        for (i = 0; i < n; i++) {
            Ov009Actor *a = res[i];
            if (a != NULL && a->kind != self->kind) {
                self->unk_90 = res[i]->id;
                if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0x494)) > 0x3c00) {
                    return;
                }
                if (VEC_Distance(&self->pos, &res[i]->pos) > 0x5800) {
                    return;
                }
                self->unk_40->flags |= 0x8000;
                FLD(u16, self, 0xb6) = 0;
                FLD(u16, self, 0xb4)++;
                return;
            }
        }
        break;
    case 1:
        FLD(u16, self, 0xb6)++;
        if (FLD(u16, self, 0xb6) > 200) {
            FLD(u16, self, 0xb4) = 0;
            FLD(u16, self, 0xb6) = 0;
        }
        break;
    }
}


extern void func_ov003_021d3008(Ov009Actor *self);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *o);
extern u16 FX_Atan2(s32 y, s32 x);

static inline s32 Ov009m_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov009m_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009m_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009m_Sqrt64(sq);
}

static inline void Ov009m_VecSub(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline void Ov009m_VecScale(Ov009Vec *v, s32 k) {
    v->x = Ov009m_Mul(v->x, k);
    v->y = Ov009m_Mul(v->y, k);
    v->z = Ov009m_Mul(v->z, k);
}

void func_ov009_02207fd8(Ov009Multi *self) {
    Ov009Vec p;
    Ov009Vec d;
    s32 i;
    s32 len;
    s32 s;
    u16 rot[3];
    func_ov003_021d3008(self);
    Ov009m_VecSub(&self->pos, &self->unk_494, &d);
    Ov009m_VecScale(&d, 0x555);
    p = self->unk_494;
    for (i = 2; i < 4; i++) {
        VEC_Add(&d, &p, &p);
        self->models[i].unk_78 = p;
    }
    len = Ov009m_DistXZ(&self->pos, &self->unk_494);
    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    rot[0] = FX_Atan2(self->unk_494.y - self->pos.y, len);
    rot[1] = FX_Atan2(self->pos.x - self->unk_494.x, self->pos.z - self->unk_494.z);
    func_ov000_02190758(&self->models[1], rot, 0);
    FLD(s32, &self->models[1], 0xa8) = 0x1000;
    s = Ov009m_Mul(len, 0x666);
    FLD(s32, &self->models[1], 0xac) = 0x1000;
    FLD(s32, &self->models[1], 0xb0) = s;
    func_ov000_02190758(&self->models[2], rot, 0);
    FLD(s32, &self->models[2], 0xa8) = 0x1000;
    FLD(s32, &self->models[2], 0xac) = 0x1000;
    FLD(s32, &self->models[2], 0xb0) = s;
    func_ov000_02190758(&self->models[3], rot, 0);
    FLD(s32, &self->models[3], 0xa8) = 0x1000;
    FLD(s32, &self->models[3], 0xac) = 0x1000;
    FLD(s32, &self->models[3], 0xb0) = s;
}

}
