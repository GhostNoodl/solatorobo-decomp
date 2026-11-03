#include "ov012/ov012.h"

extern "C" {
void Ov012Names_Fill(Ov012Names *n, u16 kind);
void Ov012ActVt_0220b280_Init(Ov012ActVt_0220b280 *self) {
    self->unk_d8 = (void *)Ov012Names_Fill;
    Ov003Actor_Init(self);
    ResSet_SetFile(&self->unk_f0, Tbl_GetResFile(0x480e), 1, 0, 0, 0);
    self->unk_f0.unk_00 = 0;
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    if (self->kind == 0x5029 || self->kind == 0x5057) {
        self->unk_1a = 1;
        return;
    }
    SndMgr_RequestLoad_02049678(data_02097e4c, 4, 6, -1);
    self->unk_1a = 0;
}
}

extern "C" {
BOOL Ov012ActVt_0220b280_IsReady(Ov012ActVt_0220b280 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->unk_f0.unk_00 >= 0 && !ResSet_UpdateLoad(&self->unk_f0)) {
        r = FALSE;
    }
    if (r && !SndMgr_IsLoadDone(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a870[];
extern const u8 data_ov012_0220a878[];
void Ov012ActVt_0220b280_Start(Ov012ActVt_0220b280 *self) {
    Ov003Actor_Start(self);
    self->unk_ea_3 = 0;
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a870);
        return;
    }
    if (self->kind == 0x5039 || self->kind == 0x5057) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a878);
    }
}
}

extern "C" {

struct Ov012Query {
    VecFx32 pos;
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

extern s32 Finder_CollectActors(Ov012Finder *self, Ov012Query *q, void **out, s32 max);

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

static inline u16 Ov012_HpPct(Ov003Actor *self) {
    return self->hp[0] * 100 / self->hp[1];
}

static inline s32 Ov012_Kind(Ov003Actor *o) {
    return o->fsm != NULL ? o->fsm->current : 0;
}

static inline u16 Ov012_FaceAng(Ov003Actor *self, Ov003Actor *o) {
    if (o == NULL || o == self) {
        return self->rot_y;
    }
    return FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
}

static inline void Ov012_Query_SetPosRot(Ov012Query *q, const VecFx32 *pos, u16 rot) {
    q->pos = *pos;
    q->unk_0c = rot;
}

void Ov012ActVt_0220b280_Update(Ov012ActVt_0220b280 *self) {
    s32 n;
    BOOL found;
    s32 i;
    Ov003Actor *pl;
    VecFx32 v;
    s32 dist;
    u8 kind;
    s32 hp;
    s32 lvl;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    if (Actor_IsDead(pl)) {
        return;
    }
    self->target = pl->id;
    self->unk_93_4 = 1;
    v = pl->pos;
    dist = VEC_Distance(&self->pos, &v);
    kind = self->fsm->current;
    if (kind != 0x10) {
        self->unk_ea_3 = 0;
    }
    if (Ov012_HpPct(self) < 0x50 && !History_HasState(self->fsm, 0x11, 5, 1)) {
        Ov012FinderQuery fq;
        Ov003Actor *hits[0x20];
        found = FALSE;
        Ov012_FinderQuery_Init(&fq);
        Ov012_Query_SetPosRot(&fq.q, &self->pos, self->rot_y);
        fq.q.mask = 0x10;
        fq.q.kind = 0x480e;
        fq.q.unk_18 = 0;
        fq.q.unk_1c = 0x4000;
        fq.q.bits.b1 = 1;
        fq.q.bits.b2 = 0;
        fq.finder.query = NULL;
        n = Finder_CollectActors(&fq.finder, &fq.q, (void **)hits, 0x20);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (hits[i] != NULL && Ov012_Kind(hits[i]) == 0xb) {
                    u16 ang = Ov012_FaceAng(self, hits[i]);
                    if ((u16)(hits[i]->rot_y - ang - 0x4000) <= 0x8000) {
                        found = TRUE;
                        break;
                    }
                }
            }
            if (found) {
                self->fsm->flags |= 0x20000;
                self->unk_b6 = 0x3c;
            }
        }
    }
    if (kind == 2 && VEC_Distance(&self->pos, &self->unk_b8) > 0x1800) {
        self->fsm->flags |= 4;
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
    if (lvl != 0 && (History_HasState(self->fsm, 0x12, lvl, 1) || History_HasState(self->fsm, 0x13, lvl, 1) ||
                     History_HasState(self->fsm, 0x14, lvl, 1))) {
        self->unk_b8 = v;
        self->fsm->flags |= 0x10000;
        self->unk_228 = 0;
    } else if (dist < 0x5800) {
        if (hp < 0x28 && !Rand_UpTo(1)) {
            self->fsm->flags |= 0x10000;
            self->unk_228 = 0;
        } else {
            self->fsm->flags |= 0x8000;
        }
        if (hp < 0x28) {
            self->unk_b6 = 0x5a;
        } else {
            self->unk_b6 = 0x87;
        }
    } else if (dist < 0xa000) {
        if (!History_HasState(self->fsm, 0xe, 2, 1)) {
            self->fsm->flags |= 0x4000;
            self->unk_b6 = 0xe1;
        }
    }
    if (dist >= 0x5000) {
        self->fsm->flags |= 4;
        self->unk_b8 = v;
        self->unk_b6 = 0x23;
    }
}
}
