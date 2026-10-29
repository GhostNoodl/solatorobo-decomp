#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u16 x, y, z;
} Ov003Rot3;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} Ov003Part;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x4d];
    s32 radius;
    u8 unk_68[8];
    Ov003Vec3 pos;
    u8 unk_7c[0x14];
    u16 unk_90;
} Ov003Player;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0xa];
    u16 unk_0a;
} Ov003Game68;

typedef struct {
    u8 unk_00[0xbe];
    u8 alpha;
} Ov003Mdl;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec3 pos;
    u8 unk_84[0x30];
    u16 unk_b4;
    u8 unk_b6[0x8];
    u8 alpha;
    u8 unk_bf[0x9];
} Ov003Anim;

typedef struct {
    u16 count;
    u16 flag;
    u8 entries[1][0xc];
} Ov003AnimTbl;

typedef struct {
    u8 unk_00[8];
    Ov003AnimTbl tbl;
} Ov003AnimRes;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xc];
    s16 unk_1a;
    u8 unk_1c[0x8];
    u8 unk_24[0x14];
    Ov003Mdl *model;
    u8 unk_3c[0x10];
    Ov003Part *unk_4c;
    u8 unk_50[0xc];
    void *unk_5c;
    u8 unk_60[0x10];
    Ov003Vec3 pos;
    Ov003Rot3 rot;
    u8 unk_82[0x4a];
    u16 unk_cc_0 : 7;
    u16 unk_cc_7 : 1;
    u16 unk_ce;
    s16 res;
    u8 unk_d2[0xbe];
    Ov003AnimRes **unk_190;
    u8 unk_194[0x74];
    Ov003Anim anim;
    u8 unk_2d0[0x8];
    Ov003AnimTbl *unk_2d8;
    void *unk_2dc;
    u8 unk_2e0[0x10];
    Ov003Vec3 unk_2f0;
    Ov003Rot3 unk_2fc;
} Ov003Obj;

typedef struct {
    u8 unk_00[0x1a];
    s16 unk_1a;
    u8 unk_1c[4];
    u16 unk_20;
    u8 unk_22[0xae];
    s16 res;
    u8 unk_d2[0x21e];
    u16 unk_2f0[6];
    u8 unk_2fc[0x10];
    s32 unk_30c;
    u8 unk_310;
} Ov003ObjB;

extern "C" {

extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Game68 *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f995c[];
extern char data_ov003_021f9967[];
extern char data_ov003_021f996d[];
extern char data_ov003_021f9978[];
extern Ov003Player *func_ov000_0219bf90(void);
extern void func_ov000_021bd7a0(void *p);
extern BOOL func_ov000_02194c08(void *self);
extern BOOL func_01ffc198(Ov003Vec3 *a, Ov003Vec3 *b, s32 r);
extern void *func_02065f88(s32 id, const Ov003Vec3 *pos);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_0218ffdc(Ov003Anim *anim, s16 *res, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void *func_0203dd9c(u32 size);
extern Ov003Part *func_ov000_02199b00(void *p);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_ov000_02190758(Ov003Anim *anim, Ov003Rot3 *rot, s32 a);
extern BOOL func_ov000_021903b4(Ov003Anim *anim);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}







static inline BOOL Ov003_GameIdle2(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->unk_90 != g->unk_94) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

BOOL func_ov003_021eab10(Ov003Obj *self) {
    BOOL r = TRUE;
    if (!self->unk_cc_7) {
        if (self->unk_5c != NULL && Ov003_GameIdle()) {
            Ov003Player *pl = func_ov000_0219bf90();
            if (pl->unk_90 == self->unk_0c) {
                func_ov000_021bd7a0(self->unk_5c);
            }
        }
    } else if (self->unk_4c->unk_03 != 10) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

void func_ov003_021eabcc(Ov003Obj *self) {
    if (self->unk_cc_7) {
        return;
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    if ((self->unk_ce & 0x7f) == 0 && self->unk_1a >= 0) {
        Ov003Player *pl = func_ov000_0219bf90();
        if (pl != NULL) {
            s32 r = 0xf000;
            if (self->unk_1a >= 1) {
                r = self->unk_1a << 4;
            }
            if (func_01ffc198(&pl->pos, &self->pos, r + pl->radius)) {
                func_02065f88(0xc8, &self->pos);
            }
        }
    }
    self->unk_ce++;
}

void func_ov003_021eaca4(Ov003Obj *self) {
    func_ov000_0219433c(self);
    func_ov000_0218f074(&self->res, data_ov003_021f995c, 1, 1, 1, 0);
    self->res = 0;
    self->unk_2f0.x = self->pos.x;
    self->unk_2f0.y = self->pos.y;
    self->unk_2f0.z = self->pos.z;
    self->unk_2fc.x = self->rot.x;
    self->unk_2fc.y = self->rot.y;
    self->unk_2fc.z = self->rot.z;
}

BOOL func_ov003_021ead1c(Ov003Obj *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    return r;
}

void func_ov003_021ead50(Ov003Obj *self) {
    Ov003AnimTbl *tbl;
    Ov003Player *pl;
    func_ov000_02194758(self);
    tbl = NULL;
    func_ov000_0218ffdc(&self->anim, &self->res, 0, 1);
    self->anim.unk_b4 = self->unk_0c;
    if (self->unk_190 != NULL) {
        tbl = &(*self->unk_190)->tbl;
    }
    if (tbl != NULL) {
        self->unk_2d8 = tbl;
        if (tbl != NULL && tbl->flag == 0) {
            self->unk_2dc = tbl->entries[tbl->count];
        }
    }
    func_ov000_02190cb0(&self->anim, data_ov003_021f9967, 0x1000, 0);
    pl = func_ov000_0219bf90();
    if (pl == NULL || !pl->unk_16_2) {
        return;
    }
    if (self->unk_4c == NULL) {
        void *mem = func_0203dd9c(0x5c);
        if (mem != NULL) {
            mem = func_ov000_02199b00(mem);
        }
        self->unk_4c = (Ov003Part *)mem;
    }
    self->unk_4c->unk_03 = 0xb;
    self->unk_4c->unk_00 = 7;
    self->unk_4c->unk_01 = 4;
    self->unk_4c->unk_02 = 0;
}

}
