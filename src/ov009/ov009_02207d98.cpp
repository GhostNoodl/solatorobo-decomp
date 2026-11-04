#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *m, ResSet *res, u8 a, BOOL b);
extern void Obj02190758_SetRot(Model0218fe1c *m, u16 *rot, s32 a);
extern BOOL Model021903b4_Draw(Model0218fe1c *m);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL Ov009Multi_Draw(Ov009Multi *self) {
    BOOL r = Ov003Actor_Draw(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        Model021903b4_Draw(&self->models[i]);
    }
    return r;
}

struct Ov009Query {
    u32 unk_00;
    VecFx32 pos;
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

static inline void Ov009Query_Set(Ov009Query *q, const VecFx32 *pos, u16 ang) {
    q->pos = *pos;
    q->unk_10 = ang;
    q->unk_00 = 0;
}

extern s32 Finder_FindActors(Ov009Query *q, VecFx32 *pos, Ov003Actor **out, s32 max);

void Ov009Multi_Update(Ov009Multi *self) {
    Ov009Query q;
    Ov003Actor *res[0x20];
    s32 n;
    s32 i;
    if (!Ov009_GameIdle()) {
        return;
    }
    switch (self->unk_b4) {
    case 0:
        if (self->fsm->current != 1 || self->unk_490 != 4) {
            return;
        }
        self->target = 0xffff;
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
        Ov009Query_Set(&q, &self->unk_494, self->unk_492);
        n = Finder_FindActors(&q, &q.pos, res, 0x20);
        for (i = 0; i < n; i++) {
            Ov003Actor *a = res[i];
            if (a != NULL && a->kind != self->kind) {
                self->target = res[i]->id;
                if (VEC_Distance(&self->pos, &self->unk_494) > 0x3c00) {
                    return;
                }
                if (VEC_Distance(&self->pos, &res[i]->pos) > 0x5800) {
                    return;
                }
                self->fsm->flags |= 0x8000;
                self->unk_b6 = 0;
                self->unk_b4++;
                return;
            }
        }
        break;
    case 1:
        self->unk_b6++;
        if (self->unk_b6 > 200) {
            self->unk_b4 = 0;
            self->unk_b6 = 0;
        }
        break;
    }
}



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

static inline s32 Ov009m_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009m_Sqrt64(sq);
}

static inline void Ov009m_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline void Ov009m_VecScale(VecFx32 *v, s32 k) {
    v->x = Ov009m_Mul(v->x, k);
    v->y = Ov009m_Mul(v->y, k);
    v->z = Ov009m_Mul(v->z, k);
}

void Ov009Multi_RunState(Ov009Multi *self) {
    VecFx32 p;
    VecFx32 d;
    s32 i;
    s32 len;
    s32 s;
    u16 rot[3];
    Ov003Actor_RunState(self);
    Ov009m_VecSub(&self->pos, &self->unk_494, &d);
    Ov009m_VecScale(&d, 0x555);
    p = self->unk_494;
    for (i = 2; i < 4; i++) {
        VEC_Add(&d, &p, &p);
        self->models[i].trans = p;
    }
    len = Ov009m_DistXZ(&self->pos, &self->unk_494);
    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    rot[0] = FX_Atan2(self->unk_494.y - self->pos.y, len);
    rot[1] = FX_Atan2(self->pos.x - self->unk_494.x, self->pos.z - self->unk_494.z);
    Obj02190758_SetRot(&self->models[1], rot, 0);
    self->models[1].scale.x = 0x1000;
    s = Ov009m_Mul(len, 0x666);
    self->models[1].scale.y = 0x1000;
    self->models[1].scale.z = s;
    Obj02190758_SetRot(&self->models[2], rot, 0);
    self->models[2].scale.x = 0x1000;
    self->models[2].scale.y = 0x1000;
    self->models[2].scale.z = s;
    Obj02190758_SetRot(&self->models[3], rot, 0);
    self->models[3].scale.x = 0x1000;
    self->models[3].scale.y = 0x1000;
    self->models[3].scale.z = s;
}

}
