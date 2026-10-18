#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u16 x, y, z;
} Ov003Rot3;

struct Ov003Pair {
    u16 x;
    u16 y;
    Ov003Pair() {}
};

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    Ov003Pair unk_08;
    s32 unk_0c;
} Ov003PartA;

typedef struct {
    Ov003Pair unk_00;
    Ov003Pair unk_04;
} Ov003PartB;

typedef struct {
    Ov003PartA a;
    Ov003PartB b;
} Ov003PartSrc;

typedef struct {
    Ov003PartA a;
    Ov003PartB b;
    u8 unk_18_0 : 1;
    u8 unk_18_1 : 1;
    u8 unk_19[3];
    u16 unk_1c;
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
    union {
        u32 flags;
        void *unk_50[3];
    };
    u8 unk_5c[0x3e];
    union {
        struct {
            u16 unk_9a_0 : 1;
            u16 unk_9a_1 : 2;
            u16 unk_9a_3 : 1;
            u16 unk_9a_4 : 1;
            u16 unk_9a_5 : 1;
        };
        u16 unk_9a;
    };
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
    u8 unk_04[0xc];
    s32 queue[16];
    u8 unk_50[0x40];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
} Ov003Game54;

typedef struct {
    s32 v[3];
} Ov003Ids;

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
    u16 unk_0e;
    u8 unk_10[7];
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
    u8 unk_60[0x4];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec3 pos;
    Ov003Rot3 rot;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92;
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
extern s32 func_02040498(s32 max);
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

extern void func_0203f324(Ov003Ctl *ctl);
extern void func_ov000_02196860(void *self);
extern void func_ov003_021f0c60(void *self, s32 a);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_0204a20c(void *mgr, s32 id);
extern void *data_02097e4c;
extern const Ov003Ids data_ov003_021f6bcc;
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void func_ov000_02195d88(void *self);
extern Ov003PartSrc *func_020704b4(u16 id);
extern void func_020627b4(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

class Ov003Fx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSpeed(s32 v);
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
};

class Ov003ObjV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

extern Ov003Fx *func_02065f88(s32 id, const Ov003Vec3 *pos);

static inline void Ov003Sub44_Clear(Ov003Sub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

static inline void Ov003Ctl_Enable(Ov003ObjB *self) {
    Ov003Ctl *c = self->ctl;
    if (c != NULL) {
        c->unk_9a_0 = 1;
        c->unk_9a_3 = 1;
        func_0203f324(c);
        self->ctl->unk_9a |= 0x12;
    }
}

static inline void Ov003PartA_Copy(Ov003PartA *d, const Ov003PartA *s) {
    if (s != NULL) {
        d->unk_00 = s->unk_00;
        d->unk_01 = s->unk_01;
        d->unk_02 = s->unk_02;
        d->unk_03 = s->unk_03;
        d->unk_04 = s->unk_04;
        d->unk_06 = s->unk_06;
        d->unk_08 = s->unk_08;
        d->unk_0c = s->unk_0c;
    }
}

static inline void Ov003PartB_Copy(Ov003PartB *d, const Ov003PartB *s) {
    if (s != NULL) {
        d->unk_00 = s->unk_00;
        d->unk_04 = s->unk_04;
    }
}

static inline BOOL Ov003Game_HasEvent(Ov003Game54 *g, const s32 *ids) {
    s32 i = g->unk_90;
    while (i != g->unk_94) {
        const s32 *p = ids;
        while (*p != 0) {
            if (*p++ == g->queue[i]) {
                return TRUE;
            }
        }
        i++;
        if (i >= 16) {
            i = 0;
        }
    }
    return FALSE;
}

void func_ov003_021eba54(Ov003ObjB *self) {
    if (self->unk_310) {
        Ov003Ctl_Enable(self);
        func_ov000_02198360(self->work, 4, 0);
    } else {
        func_ov000_02196860(self);
    }
    Ov003Sub44_Clear(self->unk_44);
}

void func_ov003_021ebae4(Ov003ObjB *self) {
    if (!self->unk_310 && ++self->unk_30c == 30) {
        Ov003Ids ids = data_ov003_021f6bcc;
        if (!Ov003Game_HasEvent(data_ov000_021ccd54, ids.v)) {
            if (self->unk_18 >= 0) {
                func_ov003_021f0c60(self, 0);
            }
            func_ov000_02197dec(self, 0xf, 5);
            func_0204a20c(data_02097e4c, 0x7e);
            func_02065f88(0x12f, &self->pos)->SetSpeed(0x800);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov003ObjV *)self)->Destroy();
        } else {
            self->unk_30c--;
        }
    }
    func_ov000_02195d88(self);
}

}
