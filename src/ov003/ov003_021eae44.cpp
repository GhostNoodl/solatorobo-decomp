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
    u8 unk_04[0x14];
    u8 unk_18_0 : 1;
    u8 unk_18_1 : 1;
} Ov003Part;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003Kind;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Sub44;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Work;

typedef struct {
    u8 unk_00[0x38];
    s32 unk_38;
    u8 unk_3c[0x14];
    u32 flags;
    u8 unk_54[0x46];
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003Ctl;

typedef struct {
    s32 *unk_00;
    u8 unk_04[0x10d];
    u8 unk_111_0 : 3;
    u8 unk_111_3 : 1;
} Ov003SubAnim;

typedef struct {
    u8 unk_00[0x4c];
    u8 *unk_4c;
} Ov003Snd;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x4d];
    s32 radius;
    u8 unk_68[4];
    s32 unk_6c;
    Ov003Vec3 pos;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
    u8 unk_94[0xa90];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
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
    u8 unk_bf[3];
    u16 unk_c2_0 : 6;
    u16 unk_c2_6 : 1;
} Ov003Mdl;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec3 pos;
    u8 unk_84[0x24];
    s32 scale[3];
    u8 unk_b4[0xa];
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
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[9];
    u8 unk_17;
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[4];
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Mdl *model;
    u8 unk_3c[4];
    union {
        Ov003Kind *unk_40;
        Ov003Work *work;
    };
    Ov003Sub44 *unk_44;
    Ov003Ctl *ctl;
    Ov003Part *unk_4c;
    u8 unk_50[0xc];
    void *unk_5c;
    u8 unk_60[0x8];
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec3 pos;
    Ov003Rot3 rot;
    u8 unk_82[0x11];
    u8 unk_93_0 : 1;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x24];
    s16 res;
    u8 unk_d2[0x136];
    Ov003Anim anim;
    u8 unk_2d0[0x20];
    u16 unk_2f0[6];
    u8 unk_2fc[4];
    Ov003Vec3 unk_300;
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
extern void func_ov000_0218ffdc(Ov003Anim *anim, s16 *res, s32 a, s32 b);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void *func_0203dd9c(u32 size);
extern Ov003Part *func_ov000_02199b00(void *p);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_ov000_02190758(Ov003Anim *anim, Ov003Rot3 *rot, s32 a);
extern BOOL func_ov000_021903b4(Ov003Anim *anim);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov003Snd *data_02fe152c;
extern s32 func_0205976c(Ov003Snd *s, s32 a);
extern BOOL func_02059544(Ov003Snd *s, u8 *p, s32 a, s32 b, u16 c);
extern Ov003SubAnim *func_ov000_02190a30(Ov003Mdl *m, s32 a);
extern void func_ov000_02191920(Ov003Mdl *m, s32 a, s32 b, s32 c);
extern void *func_ov000_0218d240(void *self);
extern void func_ov000_0218d988(void *self, void *other, s32 a);
extern void func_ov000_02197ee0(void *self, void *p, s32 a, s32 b, s32 c);
extern void func_0203f364(Ov003Ctl *ctl);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 a);
extern s32 func_02040528(s32 max);
extern void func_ov000_02195848(void *self);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern char data_ov003_021f9983[];
extern char data_ov003_021f9989[];
extern s32 func_01ffbd6c(Ov003Vec3 *a, Ov003Vec3 *b, s32 c, s32 d, s32 e, s32 f);
extern void func_ov000_0218ddd4(void *self, Ov003Vec3 *v, s32 a);
extern void func_ov000_021987b8(Ov003Ctl *ctl, s32 a, s32 b, s32 c);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

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

void func_ov003_021eae44(Ov003Obj *self) {
    if (!self->unk_cc_7) {
        return;
    }
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(self->unk_24));
    }
    func_ov000_02190a80(&self->anim, (void *)0x1000);
}

BOOL func_ov003_021eae8c(Ov003Obj *self) {
    BOOL r;
    BOOL done = FALSE;
    if (self->unk_cc_7) {
        if (self->unk_4c->unk_03 != 11) {
            done = func_ov000_02194c08(self);
        }
        self->anim.alpha = self->model->alpha;
    }
    self->anim.pos.x = self->unk_2f0.x;
    self->anim.pos.y = self->unk_2f0.y;
    self->anim.pos.z = self->unk_2f0.z;
    func_ov000_02190758(&self->anim, &self->unk_2fc, 0);
    r = func_ov000_021903b4(&self->anim);
    if (r && !done && self->unk_5c != NULL && Ov003_GameIdle2()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    return r;
}

void func_ov003_021eaf78(Ov003ObjB *self) {
    func_ov000_0219433c(self);
    self->unk_310 = 0;
    if (self->unk_1a != 0) {
        char *name;
        self->unk_310 = 1;
        name = data_ov003_021f996d;
        if (self->unk_1a == 3 || (self->unk_1a == 1 && (data_ov000_021ccd68->unk_0a & 1))) {
            name = data_ov003_021f9978;
        }
        func_ov000_0218f074(&self->res, name, 1, 0, 0, 0);
        self->res = 0;
    }
    self->unk_2f0[0] = 0;
    self->unk_2f0[1] = 0;
    self->unk_2f0[2] = 0;
    self->unk_2f0[3] = 0;
    self->unk_2f0[4] = 0;
    self->unk_2f0[5] = 0;
    self->unk_30c = 0;
}

BOOL func_ov003_021eb028(Ov003ObjB *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003Unit *u;
    if (self->unk_310 && self->res >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_6 = 0;
    }
    return r;
}

void func_ov003_021eb090(Ov003ObjB *self) {
    u8 *x;
    BOOL f;
    s32 v;
    func_ov000_02194758(self);
    if (self->unk_310) {
        func_ov000_0218ffdc(&self->anim, &self->res, 0, 1);
        *(u16 *)((u8 *)self + 0x2bc) = self->unk_0c;
        self->anim.scale[0] = 0x2000;
        self->anim.scale[1] = 0x2000;
        self->anim.scale[2] = 0x2000;
        self->unk_4c->unk_00 = 15;
        self->unk_4c->unk_01 = 1;
        self->unk_4c->unk_03 = 0;
        self->unk_4c->unk_02 = 1;
        self->unk_4c->unk_18_1 = 0;
        self->ctl->unk_38 = 0x1000;
    }
    v = self->unk_18;
    f = FALSE;
    if (v < 0) {
        f = TRUE;
    }
    if (v >= 0x40) {
        f = TRUE;
    }
    if (!f) {
        x = data_02fe152c->unk_4c;
        if (func_02059544(data_02fe152c, x + 0x150, func_0205976c(data_02fe152c, 10), 1, v)) {
            f = TRUE;
        }
    }
    if (!f) {
        return;
    }
    {
        Ov003SubAnim *a = func_ov000_02190a30(self->model, 3);
        if (a != NULL) {
            self->model->unk_c2_6 = 1;
            func_ov000_02191920(self->model, 0, 0x1000, 0);
            if (a->unk_00 != NULL) {
                *a->unk_00 = 0x1000;
            }
            a->unk_111_3 = 1;
        }
    }
    self->unk_18 = -1;
}

BOOL func_ov003_021eb1f8(Ov003ObjB *self) {
    BOOL r = FALSE;
    if (self->unk_310) {
        Ov003Rot3 rot;
        rot.x = self->rot.x;
        rot.y = self->rot.y;
        rot.z = self->rot.z;
        if (self->unk_40->kind == 1) {
            rot.x += self->unk_2f0[0];
            rot.y += self->unk_2f0[1];
            rot.z += self->unk_2f0[2];
        }
        func_ov000_02190758(&self->anim, &rot, 0);
        self->anim.pos.x = self->pos.x;
        self->anim.pos.y = self->pos.y;
        self->anim.pos.z = self->pos.z;
        r = func_ov000_021903b4(&self->anim);
        if (r && self->unk_5c != NULL && Ov003_GameIdle2()) {
            func_ov000_021bd7a0(self->unk_5c);
        }
    } else if (Ov003_GameIdle() || self->unk_17 == 0xff) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

void func_ov003_021eb380(Ov003ObjB *self) {
    Ov003Player *pl;
    Ov003Ctl *ctl;
    if (self->unk_310) {
        return;
    }
    if (!Ov003_GameIdle()) {
        void *o = func_ov000_0218d240(self);
        if (o != NULL) {
            func_ov000_0218d988(self, o, 0x400);
        }
    } else {
        func_ov000_02197ee0(self, self->unk_2fc, 0x400, 0x333, 0x6000);
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (!pl->unk_93_4) {
        return;
    }
    if (self->unk_44 != NULL) {
        self->unk_44->unk_22_1 = 0;
    }
    ctl = self->ctl;
    if (ctl == NULL) {
        return;
    }
    ctl->unk_9a_3 = 0;
    func_0203f364(ctl);
}

static inline void Ov003Sub44_Clear(Ov003Sub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

void func_ov003_021eb48c(Ov003ObjB *self) {
    if (self->work->state == 0) {
        func_ov000_02190cb0(self->model, data_ov003_021f9983, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, (s16)(func_02040528(0x59a) + 0x1000));
    }
    func_ov000_02195848(self);
    self->unk_93_0 = 0;
    if (self->unk_310) {
        u16 n = 0x100 - (u8)data_ov000_021ccd68->unk_0a;
        if (n < 0x60) {
            self->unk_2f0[3] = 0;
            self->unk_2f0[5] = 0;
        } else if ((n & 7) == 0) {
            self->unk_2f0[3] = func_02040528(n) << 2;
            self->unk_2f0[5] = func_02040528(n) << 2;
        }
        self->unk_2f0[0] = func_01ffc128(self->unk_2f0[3], self->unk_2f0[0], 0x8cd, 1, 0x8000);
        self->unk_2f0[2] = func_01ffc128(self->unk_2f0[5], self->unk_2f0[2], 0x8cd, 1, 0x8000);
    } else {
        Ov003Sub44_Clear(self->unk_44);
    }
}

static inline BOOL Ov003Player_Flag(Ov003Player *pl) {
    return pl->unk_93_4 ? TRUE : FALSE;
}

void func_ov003_021eb5ec(Ov003ObjB *self) {
    Ov003Vec3 a;
    Ov003Vec3 b;
    Ov003Vec3 v;
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f9989, 0x2ab, 0);
        func_ov000_021911c8(self->model, 0x2800);
        func_ov000_021915a0(self->model);
        Ov003Sub44_Clear(self->unk_44);
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
        break;
    case 1:
        if (self->work->timer >= 10) {
            if (self->unk_44 == NULL) {
                break;
            }
            BOOL on = FALSE;
            Ov003Player *pl = func_ov000_0219bf90();
            Ov003Sub44 *s;
            if (pl != NULL && pl->unk_b24_1 && !Ov003Player_Flag(pl)) {
                a.x = self->pos.x;
                a.y = self->pos.y;
                a.z = self->pos.z;
                b.x = pl->pos.x;
                b.y = pl->pos.y;
                b.z = pl->pos.z;
                a.y += self->unk_68;
                b.y += pl->unk_6c;
                if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) == -0x1000) {
                    on = TRUE;
                }
            }
            s = self->unk_44;
            if (!on) {
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
            } else {
                s->unk_22_0 = 1;
                s->unk_22_1 = 1;
            }
        } else {
            self->work->timer = ((const Ov003Work *)self->work)->timer + 1;
        }
        break;
    }
    self->ctl->unk_9a_5 = 1;
    self->unk_9c = 0x400;
    v.x = self->unk_300.x;
    v.y = self->unk_300.y;
    v.z = self->unk_300.z;
    func_ov000_0218ddd4(self, &v, 0x333);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
    if (self->ctl->flags & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->work, 4, 0);
}


}
