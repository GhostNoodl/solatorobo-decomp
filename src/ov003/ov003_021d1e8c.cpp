#include "types.h"
#include "Main/Lang/TblRes.h"
#include "ov003/ActorApi.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u16 start;
    u16 pad;
    u8 *ptr;
} Ov003AgRangeB;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov003AgFlag;

typedef struct {
    u8 unk_00[0x88];
    VecFx32 pos;
} Ov003AgUnit;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x40];
    ActorHp *unk_50;
    u8 unk_54[0x1c];
    VecFx32 pos;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003AgPl;

extern "C" {

extern Ov003AgRangeB data_ov003_021f45e8[];
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern const Ov003AgFlag data_ov003_021f4466[];
extern const s16 FX_SinCosTable_[];
extern Ov003AgPl *ActorMgr_FindPlayer(void);
extern BOOL Actor_IsDead(Ov003AgPl *pl);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003AgUnit *Group_FindNode(void *mgr, u16 id);
extern BOOL History_HasState(ActorSub40 *w, u8 a, s32 b, s32 c);
extern u32 Rand_UpTo(u32 max);
extern u16 FX_Atan2(s32 x, s32 z);
extern u16 func_ov000_0219a36c(VecFx32 *pos, s32 r, u16 ang, s32 a, u8 b, u32 c);

}

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    BOOL r = g->head != g->tail;
    return r;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasEvent(FieldState *g) {
    return g->event != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasEvent(data_ov000_021ccd54);
}

static inline BOOL Ov003AgPl_Bit2(Ov003AgPl *pl) {
    return pl->unk_b28_2 == 1 ? TRUE : FALSE;
}

static inline Ov003Actor *Ov003Ag_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov003Ag_Dist(s64 sq) {
    *(volatile u16 *)0x040002b0 = 1;
    *(volatile u64 *)0x040002b8 = (u64)(sq << 2);
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
    return (s32)(*(volatile u32 *)0x040002b4 + 1) >> 1;
}

static inline Ov003Entry *Ov003Ag_Lookup(u32 id) {
    Ov003Entry *ret = NULL;
    s32 i;
    for (i = 0; i < 11; i++) {
        if (data_ov003_021f45e8[i + 1].start > id) {
            if (data_ov003_021f45e8[i].start <= id) {
                ret = (Ov003Entry *)(data_ov003_021f45e8[i].ptr + (id - data_ov003_021f45e8[i].start) * 16);
            }
            break;
        }
    }
    return ret;
}

#define TICK(self) do { if ((self)->unk_b6 != 0) { (self)->unk_b6--; } } while (0)

static inline u16 Ov003Ag_Dec(Ov003Actor *self) {
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return self->unk_b6;
}

extern "C" void Ov003Actor_Update(Ov003Actor *self) {
    Ov003AgPl *pl;
    Ov003Actor *tgt;
    TblActorAggro *p;
    s32 dist;
    s32 dist2;
    s32 range;
    s32 h;
    s32 dx;
    s32 dz;
    s32 i;
    Ov003Entry *e;
    VecFx32 pos;
    s32 r;
    u16 ang;
    u16 k;

    if (!Ov003_GameIdle()) {
        return;
    }
    if (Ov003_GameHasD4()) {
        return;
    }
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        if (Ov003AgPl_Bit2(pl)) {
            return;
        }
        if (Actor_IsDead(pl)) {
            return;
        }
    }
    if (self->unk_b4 != 0 && !self->unk_b0->unk_0a_12) {
        self->unk_93_4 = 1;
    }
    if (self->hpObj != NULL && self->hpObj->cur == 0) {
        return;
    }
    tgt = NULL;
    if (self->target == 0xffff) {
        if (pl != NULL) {
            tgt = (Ov003Actor *)pl;
            self->target = pl->unk_0c;
        }
    } else {
        tgt = Ov003Ag_FindObj(self->target);
    }
    if (tgt == NULL) {
        self->target = 0xffff;
        return;
    }
    if (tgt->hpObj != NULL && tgt->hpObj->cur == 0) {
        return;
    }
    {
        ActorSub40 *w = self->fsm;
        if (w->current == 0x20 || w->current == 0 || (w->flags & 1) != 0) {
            self->unk_b4 = 0;
            self->unk_b6 = 0;
            return;
        }
    }
    p = &Tbl_GetActorParam(self->kind)->aggro;
    dist = 0x7fffffff;
    dist2 = 0x7fffffff;
    range = 0x7fffffff;
    if (!self->unk_b0->unk_0a_5) {
        range = self->unk_c8;
        if (range == 0) {
            range = 0x14000;
        }
        if (self->unk_93_4) {
            range += 0x2000;
        }
    }
    h = self->unk_cc;
    if (h == 0) {
        h = 0x3000;
    }
    if (self->unk_93_4) {
        h += 0x4800;
    }
    {
        s32 tx = tgt->pos.x;
        s32 tz = tgt->pos.z;
        s32 sz = self->pos.z;
        s32 ty = tgt->pos.y;
        s32 sy = self->pos.y;
        s32 sx = self->pos.x;
        dx = tx - sx;
        dz = tz - sz;
        if ((ty - sy) <= h && (ty - sy) >= -h && dx <= range && dx >= -range && dz <= range && dz >= -range) {
            s32 ez = sz - tz;
            s32 ex = sx - tx;
            s64 sq = (s64)ex * ex;
            sq += (s64)ez * ez;
            dist = Ov003Ag_Dist(sq);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p->ids[i] == 0x1003) {
            Ov003AgUnit *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
            s32 ez;
            s32 ex;
            s64 sq;
            if (u != NULL) {
                dx = u->pos.x;
                dz = u->pos.z;
            }
            ez = self->pos.z - dz;
            ex = self->pos.x - dx;
            sq = (s64)ex * ex;
            sq += (s64)ez * ez;
            dist2 = Ov003Ag_Dist(sq);
            break;
        }
    }
    if (dist > range) {
        self->unk_b4 = 0;
        self->unk_93_4 = 0;
        self->unk_b6 = 0;
        if (self->unk_44 != NULL) {
            self->unk_44->unk_22_1 = 0;
        }
        return;
    }
    self->unk_c4 = NULL;
    if (self->unk_b4 > 10) {
        if (self->unk_ee_9 != 0) {
            self->unk_c4 = Ov003Ag_Lookup(p->unk_0a[self->unk_ee_9 - 1]);
        } else {
            self->unk_c4 = Ov003Ag_Lookup(p->ids[self->unk_ee_7]);
        }
    }
    switch (self->unk_b4) {
    case 0:
        if (!self->unk_93_4) {
            self->unk_b6 = 0x2d;
        }
        if (!self->unk_b0->unk_0a_12) {
            self->unk_93_4 = 1;
        }
        self->unk_b4++;
        return;
    case 1:
        TICK(self);
        if (self->unk_b6 != 0) {
            return;
        }
        self->unk_b4 = 10;
    case 10:
        self->unk_ee_9 = 0;
        for (i = 0; i < 2; i++) {
            if (p->unk_08[i] != 0 && History_HasState(self->fsm, p->unk_08[i], 2, 1)) {
                self->unk_c4 = Ov003Ag_Lookup(p->unk_0a[i]);
                self->unk_ee_9 = (u16)(i + 1);
                break;
            }
        }
        if (self->unk_c4 == NULL) {
            u16 mode;
            k = self->unk_ee_7;
            mode = p->mode;
            if (mode == 2) {
                if (self->unk_ee_11) {
                    self->unk_ee_11 = 0;
                    mode = 1;
                } else {
                    self->unk_ee_11 = 1;
                    mode = 0;
                }
            }
            switch (mode) {
            case 0: {
                s32 j;
                for (j = 0; j < 3; j++) {
                    k = (u16)(k + 1);
                    if (k >= 3) {
                        k = 0;
                    }
                    self->unk_c4 = Ov003Ag_Lookup(p->ids[k]);
                    if (self->unk_c4 != NULL) {
                        break;
                    }
                }
                break;
            }
            case 1: {
                s32 j;
                for (j = 0; j < 3; j++) {
                    e = Ov003Ag_Lookup(p->ids[j]);
                    self->unk_c4 = e;
                    if (e != NULL) {
                        if (e->type == 6) {
                            dist = dist2;
                        }
                        if (dist >= e->unk_0c << 4 && dist <= e->unk_0e << 4) {
                            k = (u16)j;
                            break;
                        }
                    }
                }
                if (e == NULL) {
                    self->unk_c4 = Ov003Ag_Lookup(p->ids[k]);
                }
                break;
            }
            case 3:
                k = (u16)Rand_UpTo(2);
                self->unk_c4 = Ov003Ag_Lookup(p->ids[k]);
                break;
            }
            self->unk_ee_7 = k;
        }
        e = self->unk_c4;
        if (e == NULL) {
            return;
        }
        pos = tgt->pos;
        pos.y += self->centerY;
        r = ((e->unk_06 + e->unk_08) << 4) >> 1;
        ang = FX_Atan2(pos.x - self->pos.x, pos.z - self->pos.z);
        ang = (u16)(ang + (u16)(Rand_UpTo(0x2000) + 0x7000));
        if (self->unk_c4->type == 3) {
            ang = func_ov000_0219a36c(&pos, r, ang, 5, 0, -1);
        }
        pos.x += (s32)(((s64)r * FX_SinCosTable_[(ang >> 4) * 2] + 0x800) >> 12);
        pos.z += (s32)(((s64)r * FX_SinCosTable_[(ang >> 4) * 2 + 1] + 0x800) >> 12);
        if (self->unk_c4->type == 6) {
            Ov003AgUnit *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
            if (u != NULL) {
                pos = u->pos;
            }
            pos.y = self->pos.y;
        }
        self->unk_b8 = pos;
        self->unk_b4++;
        self->unk_b6 = 0;
    case 11:
        if (self->fsm->current != 1) {
            return;
        }
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_b4++;
        self->unk_b6 = self->unk_c4->unk_03 * 10;
    case 12: {
        BOOL hit = FALSE;
        e = self->unk_c4;
        if (dist >= e->unk_06 << 4 && dist <= e->unk_08 << 4) {
            if (e->unk_0a == 0 || e->unk_0a > 0x8000) {
                hit = TRUE;
            } else {
                u16 a;
                if (tgt == NULL || (void *)tgt == (void *)self) {
                    a = self->rot_y;
                } else {
                    a = FX_Atan2(tgt->pos.x - self->pos.x, tgt->pos.z - self->pos.z);
                }
                a -= self->rot_y;
                if ((u16)(self->unk_c4->unk_0a + a) < (u16)(self->unk_c4->unk_0a << 1)) {
                    hit = TRUE;
                }
            }
        }
        if (hit) {
            self->unk_b4 = 20;
            self->unk_b6 = self->unk_c4->unk_04 * 10;
            return;
        }
        {
            s32 lim = self->speed;
            ActorSub48 *ctl;
            s32 d;
            if (lim < 0x4cd) {
                lim = 0x4cd;
            }
            ctl = self->hit;
            if ((ctl->unk_50 & 0x40000000) || ctl->unk_58 != 0) {
                self->unk_b6 = self->unk_b6 < 10 ? 0 : (u16)(self->unk_b6 - 10);
            }
            {
                s32 ez = self->pos.z - self->unk_b8.z;
                s32 ex = self->pos.x - self->unk_b8.x;
                s64 sq = (s64)ex * ex;
                sq += (s64)ez * ez;
                d = Ov003Ag_Dist(sq);
            }
            if (lim > d || Ov003Ag_Dec(self) == 0) {
                self->unk_b4++;
            }
        }
        self->unk_ee_1 = 0;
        if (self->unk_c4->kind == 2) {
            self->fsm->flags |= 0x400000;
            return;
        }
        self->fsm->flags |= 4;
        self->unk_ee_1 = self->unk_c4->kind;
        return;
    }
    case 13:
        if (self->unk_c4->unk_01_3 == 2 || Ov003Ag_Dec(self) == 0) {
            self->unk_b4 = 10;
        }
        if (self->unk_c4->unk_01_3 != 1) {
            return;
        }
        Actor_TurnToActor(self, tgt, self->unk_b0->unk_02);
        return;
    case 20:
        TICK(self);
        if (self->unk_b6 != 0) {
            if (!self->unk_c4->unk_01_2) {
                return;
            }
            Actor_TurnToActor(self, tgt, self->unk_b0->unk_02);
            return;
        } else {
            u32 idx = self->unk_c4->idx;
            const Ov003AgFlag *f;
            if (idx >= 16) {
                idx = 0;
            }
            f = &data_ov003_021f4466[idx];
            switch (f->a) {
            case 0xf:
            case 0x10:
            case 0x11: {
                self->fsm->flags |= 1ULL << f->a;
                self->unk_ee_2 = f->b;
                if (f->c < 2) {
                    self->unk_ee_4 = f->c;
                } else {
                    self->unk_ee_4 = (u16)(self->unk_ee_4 ? 0 : 1);
                }
                break;
            }
            case 0xe: {
                self->fsm->flags |= 1ULL << f->a;
                self->unk_ee_5 = f->b;
                if (f->c < 2) {
                    self->unk_ee_6 = f->c;
                } else {
                    self->unk_ee_6 = (u16)(self->unk_ee_6 ? 0 : 1);
                }
                break;
            }
            }
            if (self->unk_c4->unk_01_5 != 0) {
                self->unk_ea_0 = self->unk_c4->unk_01_5;
            }
            self->unk_b4++;
            return;
        }
    case 21:
        if (self->fsm->current != 1) {
            return;
        }
        self->unk_b6 = self->unk_c4->unk_05 * 10 + Rand_UpTo(8);
        self->unk_b4++;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        return;
    case 22:
        TICK(self);
        if (self->unk_b6 == 0) {
            self->unk_b4 = 10;
        }
        return;
    }
}
