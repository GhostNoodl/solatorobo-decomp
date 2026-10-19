#include "ov012/ov012.h"

extern "C" {
void func_ov012_02207b7c(Ov012Names *n, void *res);
void func_ov012_02207c40(Ov012Actor *self) {
    FLD(void *, self, 0xd8) = (void *)func_ov012_02207b7c;
    func_ov003_021d0fc0(self);
    func_ov000_0218f074((u8 *)self + 0xf0, func_0207011c((void *)0x480e), 1, 0, 0, 0);
    FLD(s16, self, 0xf0) = 0;
    func_02049564(data_02097e4c, 1, 1);
    if (self->kind == 0x5029 || self->kind == 0x5057) {
        self->unk_1a = 1;
        return;
    }
    func_02049678(data_02097e4c, 4, 6, -1);
    self->unk_1a = 0;
}
}

extern "C" {
BOOL func_ov012_02207cf0(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110((u8 *)self + 0xf0)) {
        r = FALSE;
    }
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a870[];
extern const u8 data_ov012_0220a878[];
void func_ov012_02207d44(Ov012Actor *self) {
    func_ov003_021d112c(self);
    self->unk_ea_3 = 0;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a870);
        return;
    }
    if (self->kind == 0x5039 || self->kind == 0x5057) {
        func_ov003_021d6bac(self, data_ov012_0220a878);
    }
}
}

extern "C" {

struct Ov012Query {
    Ov012Vec pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    union {
        u8 flags;
        struct {
            u8 b0 : 1;
            u8 b1 : 1;
            u8 b2 : 1;
            u8 b3 : 5;
        } bits;
    };
};

struct Ov012Finder {
    Ov012Query *query;
};

struct Ov012FinderQuery {
    Ov012Finder finder;
    Ov012Query q;
};

extern s32 func_ov000_02199128(Ov012Finder *self, Ov012Query *q, void **out, s32 max);

static inline void Ov012_FinderQuery_Init(Ov012FinderQuery *fq) {
    fq->q.mask = 0;
    fq->q.kind = 0xffff;
    fq->q.unk_12 = 0;
    fq->q.unk_14 = 0;
    fq->q.unk_18 = 0;
    fq->q.unk_1c = 0;
    fq->q.unk_20 = 0;
    fq->q.unk_24 = 0;
    fq->q.exclude = 0xffff;
    fq->q.flags = 0;
}

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

static inline void Ov012_Query_SetPosRot(Ov012Query *q, const Ov012Vec *pos, u16 rot) {
    q->pos = *pos;
    q->unk_0c = rot;
}

void func_ov012_02207dac(Ov012Actor *self) {
    s32 n;
    BOOL found;
    s32 i;
    Ov012Actor *pl;
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
    v = pl->pos;
    dist = VEC_Distance(&self->pos, &v);
    kind = self->unk_40->unk_13;
    if (kind != 0x10) {
        self->unk_ea_3 = 0;
    }
    if (Ov012_HpPct(self) < 0x50 && !func_ov000_021983b0(self->unk_40, 0x11, 5, 1)) {
        Ov012FinderQuery fq;
        Ov012Actor *hits[0x20];
        found = FALSE;
        Ov012_FinderQuery_Init(&fq);
        Ov012_Query_SetPosRot(&fq.q, &self->pos, self->rot[1]);
        fq.q.mask = 0x10;
        fq.q.kind = 0x480e;
        fq.q.unk_18 = 0;
        fq.q.unk_1c = 0x4000;
        fq.q.bits.b1 = 1;
        fq.q.bits.b2 = 0;
        fq.finder.query = NULL;
        n = func_ov000_02199128(&fq.finder, &fq.q, (void **)hits, 0x20);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (hits[i] != NULL && Ov012_Kind(hits[i]) == 0xb) {
                    u16 ang = Ov012_FaceAng(self, hits[i]);
                    if ((u16)(hits[i]->rot[1] - ang - 0x4000) <= 0x8000) {
                        found = TRUE;
                        break;
                    }
                }
            }
            if (found) {
                self->unk_40->flags |= 0x20000;
                self->unk_b6 = 0x3c;
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
    if (hp < 0x3c) {
        lvl = 2;
    }
    if (lvl != 0 && (func_ov000_021983b0(self->unk_40, 0x12, lvl, 1) || func_ov000_021983b0(self->unk_40, 0x13, lvl, 1) ||
                     func_ov000_021983b0(self->unk_40, 0x14, lvl, 1))) {
        self->unk_b8 = v;
        self->unk_40->flags |= 0x10000;
        FLD(u16, self, 0x228) = 0;
    } else if (dist < 0x5800) {
        if (hp < 0x28 && !func_02040498(1)) {
            self->unk_40->flags |= 0x10000;
            FLD(u16, self, 0x228) = 0;
        } else {
            self->unk_40->flags |= 0x8000;
        }
        if (hp < 0x28) {
            self->unk_b6 = 0x5a;
        } else {
            self->unk_b6 = 0x87;
        }
    } else if (dist < 0xa000) {
        if (!func_ov000_021983b0(self->unk_40, 0xe, 2, 1)) {
            self->unk_40->flags |= 0x4000;
            self->unk_b6 = 0xe1;
        }
    }
    if (dist >= 0x5000) {
        self->unk_40->flags |= 4;
        self->unk_b8 = v;
        self->unk_b6 = 0x23;
    }
}
}
