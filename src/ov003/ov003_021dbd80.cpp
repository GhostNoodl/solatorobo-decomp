#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003HtVec;

typedef struct {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 kind;
} Ov003HtWork;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
} Ov003HtCtl;

typedef struct {
    u8 kind;
    u8 unk_01[7];
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0xc];
    u8 unk_18_0 : 6;
    u8 unk_18_6 : 1;
    u8 unk_19[3];
    u16 team;
} Ov003HtDef;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
} Ov003HtPart;

typedef struct {
    u8 unk_00[0x20];
    s16 unk_20;
    u8 unk_22[2];
    u8 unk_24;
    u8 unk_25;
    s16 unk_26;
    s16 unk_28;
    u16 unk_2a_0 : 7;
    u16 unk_2a_7 : 3;
    u16 mask;
    u8 unk_2e[6];
    u32 flags;
} Ov003HtAtk;

typedef struct {
    u8 unk_00[0x40];
    Ov003HtWork *work;
    u8 unk_44[8];
    Ov003HtDef *def;
    u8 unk_50[0x40];
    u16 unk_90;
    u8 unk_92[0xa8c];
    u16 unk_b1e;
} Ov003HtPlayer;

class Ov003Hitter {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
    u8 unk_04[8];
    u16 unk_0c;
    u8 unk_0e[0x32];
    Ov003HtWork *work;
    u8 unk_44[4];
    Ov003HtCtl *ctl;
    Ov003HtDef *def;
    u8 unk_50[0x14];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003HtVec pos;
    u8 unk_7c[0x40];
    void *unk_bc;
    u8 unk_c0[0x10];
    Ov003HtAtk *atk;
    u8 unk_d4[4];
    s16 unk_d8;
};

extern "C" {

extern void *data_0214a420;
extern Ov003HtPlayer *func_ov000_0219bf90(void);
extern Ov003HtPart *func_ov000_02199ba0(Ov003HtDef *def);
extern BOOL func_ov000_0218d2e0(Ov003Hitter *self);
extern s32 func_ov000_0219a510(Ov003Hitter *self, u16 mask, Ov003HtVec *pos, s32 r, s32 a, void **list);
extern Ov003HtPlayer *func_ov000_021985c0(void *p);
extern BOOL func_ov000_0219a8bc(void *a, Ov003Hitter *b, Ov003HtPart *c, u16 d, u8 e, Ov003HtVec *f, s32 g, s32 h, s32 i);
extern void func_02065804(void *mgr, void *p);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021f0c60(Ov003Hitter *self, u16 mask);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);

static inline u8 Ov003HtPlayer_Kind(Ov003HtPlayer *pl) {
    if (pl->work != NULL) {
        return pl->work->kind;
    }
    return 0;
}

BOOL func_ov003_021dbd80(Ov003Hitter *self) {
    void *list[32];
    Ov003HtPlayer *pl = func_ov000_0219bf90();
    Ov003HtPart *part = func_ov000_02199ba0(self->def);
    s32 hit = 0;
    u16 mask = self->atk->mask;
    u16 team;
    s32 t;
    if (mask == 0) {
        mask = 0xffff;
    }
    team = self->def->team & 0xf000;
    mask &= ~(1 << (team >> 12));
    if (self->atk->unk_20 != 0) {
        self->unk_d8++;
        t = self->atk->unk_20;
        if (t < 0) {
            if (self->unk_d8 >= -t) {
                hit = -1;
            }
        } else if (self->unk_d8 >= t) {
            hit = 1;
        }
    }
    if (hit == 0 && self->ctl != NULL) {
        u32 fl = self->atk->flags;
        if (self->atk->unk_2a_7 & 2) {
            if (!func_ov000_0218d2e0(self)) {
                fl = 0xe0000000;
            }
        }
        if (fl & self->ctl->flags) {
            hit = 2;
        }
    }
    if (hit == 0) {
        s32 r = self->unk_64;
        s32 n;
        s32 i;
        if (self->def->kind != 0x14 || part->unk_0e == 0x1000) {
            r += 0x4cd;
        } else if (pl != NULL) {
            if (pl->unk_b1e == self->unk_0c || (Ov003HtPlayer_Kind(pl) == 0x18 && pl->unk_90 == self->unk_0c)) {
                r >>= 2;
                self->unk_d8--;
            }
        }
        n = func_ov000_0219a510(self, mask, &self->pos, r, 0, list);
        if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003HtPlayer *o;
            if (list[i] == NULL) {
                continue;
            }
            o = func_ov000_021985c0(list[i]);
            if (o == NULL) {
                continue;
            }
            if (o->def != NULL && team == (u16)(o->def->team & 0xf000)) {
                continue;
            }
            if (!(self->atk->unk_2a_7 & 1) || part->unk_0e == 0x1000) {
                hit = 2;
                break;
            }
            {
                s32 a = 100;
                Ov003HtDef *def = self->def;
                if (def->unk_18_6) {
                    a = -1;
                }
                func_ov000_0219a8bc(list[i], self, part, def->unk_08, (u8)def->unk_0a, &self->pos, a, 0x1000, 0x1000);
            }
        }
        }
    }
    if (hit != 0) {
        if (self->unk_bc != NULL) {
            func_02065804(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        if (hit == 2 && self->atk->unk_24 != 0 && self->atk->unk_25 != 0) {
            func_ov000_0218996c(self->atk->unk_24, self->atk->unk_25);
        }
        if (hit > 0) {
            s32 v;
            v = self->atk->unk_26;
            if (v >= 0) {
                self->unk_64 = v << 4;
            } else {
                self->unk_64 = self->unk_64 * 2;
            }
            v = self->atk->unk_28;
            if (v >= 0) {
                v <<= 4;
                self->unk_68 = v;
                self->unk_6c = v >> 1;
            }
            func_ov003_021f0c60(self, mask);
            func_ov000_02198360(self->work, 0x15, 0);
        } else {
            self->Destroy();
        }
    }
    return hit != 0;
}

}
