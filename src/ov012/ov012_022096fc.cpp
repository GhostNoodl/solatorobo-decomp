#include "ov012/ov012.h"

extern "C" {
extern void *func_ov000_0218e4cc(void *mgr, s32 kind);
extern u32 func_ov000_0218dfb4(void *p, s32 kind);

static inline u16 Ov012_HpPct(Ov012Actor *self) {
    return self->unk_50[0] * 100 / self->unk_50[1];
}

static inline s32 Ov012_Kind(Ov012Actor *o) {
    return o->unk_40 != NULL ? o->unk_40->unk_13 : 0;
}

static inline u16 Ov012_FaceAng(Ov012Actor *self, Ov012Actor *o) {
    if (o == NULL || o == self) {
        return self->rot[1];
    }
    return FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
}

static inline s32 Ov012_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov012_02209268(Ov012Actor *self) {
    Ov012Actor *pl;
    Ov012Actor *o;
    Ov012Vec v;
    s32 dist;
    u8 kind;
    s32 hp;
    s32 lvl;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (func_ov000_021b4738(pl)) {
        return;
    }
    self->unk_90 = pl->id;
    self->unk_93_4 = 1;
    o = (Ov012Actor *)Ov012_FindRes(0x4000, 0x4801);
    v = pl->pos;
    dist = VEC_Distance(&self->pos, &v);
    kind = self->unk_40->unk_13;
    if (!func_ov000_021983b0(self->unk_40, 0x16, 2, 1)) {
        if (func_ov000_021983b0(self->unk_40, 0x13, 5, 1) || func_ov000_021983b0(self->unk_40, 0x12, 5, 1) || Ov012_HpPct(self) < 0x1e) {
            if (o != NULL && Ov012_Kind(o) == 0xb) {
                u16 ang = Ov012_FaceAng(self, o);
                if ((u16)(o->rot[1] - ang - 0x4000) <= 0x8000) {
                    u16 r;
                    v.x = 0;
                    v.y = 0;
                    v.z = 0;
                    if ((u16)(FX_Atan2(v.x - self->pos.x, v.z - self->pos.z) - ang) > 0x8000) {
                        r = ang - 0x3000;
                    } else {
                        r = ang + 0x3000;
                    }
                    {
                        s32 s = FX_SinCosTable_[(r >> 4) * 2];
                        s32 c = FX_SinCosTable_[(r >> 4) * 2 + 1];
                        dist = 0x4800;
                        v.x = self->pos.x + Ov012_FxMul64(s, dist);
                        v.z = self->pos.z + Ov012_FxMul64(c, dist);
                    }
                    self->unk_b8 = v;
                    self->unk_40->flags |= 0x400000;
                    self->unk_b6 = 0x5a;
                }
            }
        }
    }
    if (kind == 2 && VEC_Distance(&self->pos, &self->unk_b8) > 0x1800) {
        self->unk_40->flags |= 4;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    lvl = 0;
    hp = Ov012_HpPct(self);
    if (hp < 0xf) {
        lvl = 3;
    } else if (hp < 0x28) {
        lvl = 2;
    }
    if (lvl != 0 && func_ov000_021983b0(self->unk_40, 0x12, lvl, 1)) {
        self->unk_40->flags |= 0x10000;
    } else if (dist < 0x6000) {
        self->unk_40->flags |= 0x8000;
        if (hp < 0x1e) {
            self->unk_b6 = 100;
        } else {
            self->unk_b6 = 0x78;
        }
    } else if (dist < 0xc000) {
        void *m = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
        if (m == NULL || func_ov000_0218dfb4(m, 0x4009) <= 2) {
            u8 *t = NULL;
            if (o != NULL) {
                t = FLD(u8 *, o, 0x4c);
            }
            if (t != NULL && FLD(u16, t, 0x1c) != self->id) {
                t = NULL;
            }
            if (t == NULL) {
                self->unk_40->flags |= 0x4000;
            }
        }
    }
    if (dist >= 0x7800) {
        self->unk_40->flags |= 4;
        self->unk_b8 = v;
        self->unk_b6 = 0x4b;
    }
}

void func_ov012_022096fc(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
    }
    func_ov003_021d452c(self);
}
extern u8 data_ov012_0220b400[];
extern u8 data_ov012_0220b406[];
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);

struct Ov012Rot16U {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov012_02209740(Ov012Actor *self) {
    Ov012Actor *pl = Ov012_FindActor(self->unk_90);
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b400, 0x19a, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_94_1 = 1;
        self->unk_ea_0 = 3;
        func_02049f44(data_02097e4c, 0x702, &self->pos, 0);
        break;
    case 1:
        func_ov000_0218d988(self, pl, 0x400);
        self->unk_40->timer++;
        if (self->unk_40->timer == 1 || self->unk_40->timer == 0x1e) {
            Ov012V *e = func_02065f88(0x384, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xe66);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov012V *e = func_02065f88(0x192, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0x1333);
            e->v34(0, self->rot[1], 0);
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        self->unk_94_1 = 1;
        break;
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 1 || func_01ffc198(&pl->pos, &self->pos, pl->unk_64 + 0x3000)) {
            func_ov000_02191418(self->unk_38, 0, 1);
            self->unk_a4 = 0xc00;
            self->unk_40->timer = 0;
            self->unk_40->state++;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b406, 0x19a, 0);
            func_ov000_021911c8(self->unk_38, 0x666);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 4:
        s->timer++;
        if (s->timer > 0x14) {
            Ov012V *e;
            Ov012Rot16U r;
            func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot[1] + 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot[1] - 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 5:
        s->timer++;
        if (s->timer > 0x96) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    self->unk_48->unk_9a_5 = 1;
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
    if (self->unk_48->unk_50 & 0x20000000) {
        self->unk_a0 = 0;
    }
}
}
