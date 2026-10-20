#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003AgVec;

typedef struct {
    u16 start;
    u16 pad;
    u8 *ptr;
} Ov003AgRangeB;

typedef struct {
    u8 idx : 4;
    u8 type : 3;
    u8 b0_7 : 1;
    u8 kind : 2;
    u8 b1_2 : 1;
    u8 b1_3 : 2;
    u8 ea : 3;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    s16 unk_06;
    s16 unk_08;
    u16 unk_0a;
    s16 unk_0c;
    s16 unk_0e;
} Ov003AgEntry;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov003AgFlag;

typedef struct {
    u16 mode;
    u16 ids[3];
    u8 unk_08[2];
    u16 unk_0a[2];
} Ov003AgParam;

typedef struct {
    u32 unk_00;
    u64 flags;
    u8 pad_0c[0x7];
    u8 kind;
} Ov003AgWork;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Ag44;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    s32 unk_58;
} Ov003AgCtl;

typedef struct {
    u16 unk_00;
} Ov003AgS50;

typedef struct {
    u8 unk_00[2];
    s16 unk_02;
    u8 unk_04[6];
    u16 unk_0a_0 : 5;
    u16 unk_0a_5 : 1;
    u16 unk_0a_6 : 1;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 1;
    u16 unk_0a_11 : 1;
    u16 unk_0a_12 : 1;
} Ov003AgB0;

typedef struct {
    u8 unk_00[0x88];
    Ov003AgVec pos;
} Ov003AgUnit;

typedef struct Ov003Ag {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x1e];
    Ov003AgWork *work;
    Ov003Ag44 *unk_44;
    Ov003AgCtl *ctl;
    u8 unk_4c[4];
    Ov003AgS50 *unk_50;
    u8 unk_54[0x18];
    s32 unk_6c;
    Ov003AgVec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[0x10];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
    u8 unk_94[8];
    s32 unk_9c;
    u8 unk_a0[0x10];
    Ov003AgB0 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov003AgVec unk_b8;
    Ov003AgEntry *unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    u8 unk_d0[0x1a];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 13;
    u8 unk_ec[2];
    u16 unk_ee_0 : 1;
    u16 unk_ee_1 : 1;
    u16 unk_ee_2 : 2;
    u16 unk_ee_4 : 1;
    u16 unk_ee_5 : 1;
    u16 unk_ee_6 : 1;
    u16 unk_ee_7 : 2;
    u16 unk_ee_9 : 2;
    u16 unk_ee_11 : 1;
} Ov003Ag;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x40];
    Ov003AgS50 *unk_50;
    u8 unk_54[0x1c];
    Ov003AgVec pos;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003AgPl;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    void *unk_d4;
} Ov003AgGame;

extern "C" {

extern Ov003AgGame *data_ov000_021ccd54;
extern Ov003AgRangeB data_ov003_021f45e8[];
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern const Ov003AgFlag data_ov003_021f4466[];
extern const s16 FX_SinCosTable_[];
extern Ov003AgPl *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003AgPl *pl);
extern Ov003Ag *func_ov000_0218e640(void *mgr, u16 id);
extern Ov003AgUnit *func_ov000_0218bd5c(void *mgr, u16 id);
extern u8 *func_02070558(u16 id);
extern BOOL func_ov000_021983b0(Ov003AgWork *w, u8 a, s32 b, s32 c);
extern s32 func_02040498(s32 max);
extern u16 FX_Atan2(s32 x, s32 z);
extern u16 func_ov000_0219a36c(Ov003AgVec *pos, s32 r, u16 ang, s32 a, s32 b, s32 c);
extern void func_ov000_0218d988(void *self, void *target, s32 a);

}

static inline BOOL Ov003Game_IsBusy(Ov003AgGame *g) {
    BOOL r = g->unk_90 != g->unk_94;
    return r;
}

static inline BOOL Ov003Game_IsIdle(Ov003AgGame *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003AgGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003AgGame *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54);
}

static inline BOOL Ov003AgPl_Bit2(Ov003AgPl *pl) {
    return pl->unk_b28_2 == 1 ? TRUE : FALSE;
}

static inline Ov003Ag *Ov003Ag_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov003Ag_Dist(s64 sq) {
    *(volatile u16 *)0x040002b0 = 1;
    *(volatile u64 *)0x040002b8 = (u64)(sq << 2);
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
    return (s32)(*(volatile u32 *)0x040002b4 + 1) >> 1;
}

static inline Ov003AgEntry *Ov003Ag_Lookup(u32 id) {
    Ov003AgEntry *ret = NULL;
    s32 i;
    for (i = 0; i < 11; i++) {
        if (data_ov003_021f45e8[i + 1].start > id) {
            if (data_ov003_021f45e8[i].start <= id) {
                ret = (Ov003AgEntry *)(data_ov003_021f45e8[i].ptr + (id - data_ov003_021f45e8[i].start) * 16);
            }
            break;
        }
    }
    return ret;
}

#define TICK(self) do { if ((self)->unk_b6 != 0) { (self)->unk_b6--; } } while (0)

static inline u16 Ov003Ag_Dec(Ov003Ag *self) {
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return self->unk_b6;
}

extern "C" void func_ov003_021d1e8c(Ov003Ag *self) {
    Ov003AgPl *pl;
    Ov003Ag *tgt;
    Ov003AgParam *p;
    s32 dist;
    s32 dist2;
    s32 range;
    s32 h;
    s32 dx;
    s32 dz;
    s32 i;
    Ov003AgEntry *e;
    Ov003AgVec pos;
    s32 r;
    u16 ang;
    u16 k;

    if (!Ov003_GameIdle()) {
        return;
    }
    if (Ov003_GameHasD4()) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        if (Ov003AgPl_Bit2(pl)) {
            return;
        }
        if (func_ov000_021b4738(pl)) {
            return;
        }
    }
    if (self->unk_b4 != 0 && !self->unk_b0->unk_0a_12) {
        self->unk_93_4 = 1;
    }
    if (self->unk_50 != NULL && self->unk_50->unk_00 == 0) {
        return;
    }
    tgt = NULL;
    if (self->unk_90 == 0xffff) {
        if (pl != NULL) {
            tgt = (Ov003Ag *)pl;
            self->unk_90 = pl->unk_0c;
        }
    } else {
        tgt = Ov003Ag_FindObj(self->unk_90);
    }
    if (tgt == NULL) {
        self->unk_90 = 0xffff;
        return;
    }
    if (tgt->unk_50 != NULL && tgt->unk_50->unk_00 == 0) {
        return;
    }
    {
        Ov003AgWork *w = self->work;
        if (w->kind == 0x20 || w->kind == 0 || (w->flags & 1) != 0) {
            self->unk_b4 = 0;
            self->unk_b6 = 0;
            return;
        }
    }
    p = (Ov003AgParam *)(func_02070558(self->unk_0e) + 0x2c);
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
            Ov003AgUnit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
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
            if (p->unk_08[i] != 0 && func_ov000_021983b0(self->work, p->unk_08[i], 2, 1)) {
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
                k = (u16)func_02040498(2);
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
        pos.y += self->unk_6c;
        r = ((e->unk_06 + e->unk_08) << 4) >> 1;
        ang = FX_Atan2(pos.x - self->pos.x, pos.z - self->pos.z);
        ang = (u16)(ang + (u16)(func_02040498(0x2000) + 0x7000));
        if (self->unk_c4->type == 3) {
            ang = func_ov000_0219a36c(&pos, r, ang, 5, 0, -1);
        }
        pos.x += (s32)(((s64)r * FX_SinCosTable_[(ang >> 4) * 2] + 0x800) >> 12);
        pos.z += (s32)(((s64)r * FX_SinCosTable_[(ang >> 4) * 2 + 1] + 0x800) >> 12);
        if (self->unk_c4->type == 6) {
            Ov003AgUnit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
            if (u != NULL) {
                pos = u->pos;
            }
            pos.y = self->pos.y;
        }
        self->unk_b8 = pos;
        self->unk_b4++;
        self->unk_b6 = 0;
    case 11:
        if (self->work->kind != 1) {
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
                    a = self->rotY;
                } else {
                    a = FX_Atan2(tgt->pos.x - self->pos.x, tgt->pos.z - self->pos.z);
                }
                a -= self->rotY;
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
            s32 lim = self->unk_9c;
            Ov003AgCtl *ctl;
            s32 d;
            if (lim < 0x4cd) {
                lim = 0x4cd;
            }
            ctl = self->ctl;
            if ((ctl->flags & 0x40000000) || ctl->unk_58 != 0) {
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
            self->work->flags |= 0x400000;
            return;
        }
        self->work->flags |= 4;
        self->unk_ee_1 = self->unk_c4->kind;
        return;
    }
    case 13:
        if (self->unk_c4->b1_3 == 2 || Ov003Ag_Dec(self) == 0) {
            self->unk_b4 = 10;
        }
        if (self->unk_c4->b1_3 != 1) {
            return;
        }
        func_ov000_0218d988(self, tgt, self->unk_b0->unk_02);
        return;
    case 20:
        TICK(self);
        if (self->unk_b6 != 0) {
            if (!self->unk_c4->b1_2) {
                return;
            }
            func_ov000_0218d988(self, tgt, self->unk_b0->unk_02);
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
                self->work->flags |= 1ULL << f->a;
                self->unk_ee_2 = f->b;
                if (f->c < 2) {
                    self->unk_ee_4 = f->c;
                } else {
                    self->unk_ee_4 = (u16)(self->unk_ee_4 ? 0 : 1);
                }
                break;
            }
            case 0xe: {
                self->work->flags |= 1ULL << f->a;
                self->unk_ee_5 = f->b;
                if (f->c < 2) {
                    self->unk_ee_6 = f->c;
                } else {
                    self->unk_ee_6 = (u16)(self->unk_ee_6 ? 0 : 1);
                }
                break;
            }
            }
            if (self->unk_c4->ea != 0) {
                self->unk_ea_0 = self->unk_c4->ea;
            }
            self->unk_b4++;
            return;
        }
    case 21:
        if (self->work->kind != 1) {
            return;
        }
        self->unk_b6 = self->unk_c4->unk_05 * 10 + func_02040498(8);
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
