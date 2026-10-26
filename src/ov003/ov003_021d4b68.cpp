#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003KbVec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003KbWork;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x10];
    s32 unk_6c;
    u8 unk_70[0x2a];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003KbCtl;

typedef struct {
    u8 unk_00;
    u8 unk_01[0x18];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 unk_1c;
} Ov003KbDef;

typedef struct {
    u16 unk_00;
    u8 unk_02[2];
    u16 unk_04;
    u8 unk_06[2];
    u8 unk_08;
    u8 unk_09;
} Ov003KbTgt;

typedef struct {
    u8 unk_00[2];
    s16 unk_02;
    u8 unk_04[6];
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 1;
    u16 unk_0a_11 : 1;
} Ov003KbB0;

typedef struct {
    u8 unk_00[0x70];
    Ov003KbVec pos;
} Ov003KbObj;

typedef struct {
    u8 unk_00[0x112];
    s16 unk_112;
} Ov003KbAnim;

class Ov003KbFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetSize(s32 size);
    virtual void v10();
    virtual void v14(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetRot(s32 x, s32 y, s32 z);
    u8 unk_04[0x20];
    void *unk_24;
};

typedef struct {
    u8 unk_00[0xc4];
    s16 unk_c4;
    s16 unk_c6;
    s16 unk_c8;
    s16 unk_ca;
} Ov003KbModel;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
} Ov003KbUnit;

typedef struct {
    u16 id;
    s8 unk_02;
} Ov003KbSpawn;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Kb44;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    Ov003KbModel *model;
    u8 unk_3c[4];
    Ov003KbWork *work;
    Ov003Kb44 *unk_44;
    Ov003KbCtl *ctl;
    Ov003KbDef *def;
    Ov003KbTgt *tgt;
    u8 unk_54[0x10];
    s32 unk_64;
    u8 unk_68[4];
    s32 unk_6c;
    Ov003KbVec pos;
    u8 unk_7c[2];
    u16 rotY;
    u8 unk_80[0x10];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93[3];
    u16 unk_96;
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003KbB0 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    u8 unk_b8[0x26];
    u16 unk_de;
    void *unk_e0;
    void *unk_e4;
    u16 unk_e8;
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 8;
    u16 unk_ea_11 : 1;
    u8 unk_ec_0 : 1;
    u8 unk_ec_1 : 1;
    u8 unk_ed;
    u16 unk_ee_0 : 1;
    u16 unk_ee_1 : 4;
    u16 unk_ee_5 : 1;
    u16 unk_ee_6 : 1;
} Ov003Kb;

extern "C" {

extern void *data_ov000_021ccd68;
extern const char *data_ov003_021f7a38[2][2];
extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern Ov003KbUnit *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, Ov003KbUnit *target, s32 a);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(Ov003KbVec *out, Ov003KbVec *in, u16 ang);
extern void VEC_Add(const Ov003KbVec *a, const Ov003KbVec *b, Ov003KbVec *out);
extern Ov003KbUnit *func_ov000_0219be1c(u16 id, Ov003KbVec *pos, void *rot, u16 a, s32 b);
extern void func_ov000_0218d46c(Ov003KbUnit *u, u16 a, s32 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_021987b8(Ov003KbCtl *ctl, s32 a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);

static inline Ov003KbUnit *Ov003Kb_FindUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov003KbCtl_Bit4(Ov003KbCtl *c) {
    return c->unk_9a_4 ? TRUE : FALSE;
}

void func_ov003_021d4b68(Ov003Kb *self) {
    Ov003KbUnit *pl = Ov003Kb_FindUnit(self->unk_90);
    Ov003KbWork *w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f7a38[self->unk_ee_5][self->unk_ee_6], 0x400, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
        break;
    case 1:
        func_ov000_0218d988(self, pl, self->unk_b0->unk_02);
        if (self->model->unk_c4 == 1) {
            self->work->state = 10;
        }
    case 10:
        if (self->model->unk_c4 >= 2) {
            Ov003KbVec v;
            u8 *rec = func_02070558(self->unk_0e);
            Ov003KbSpawn *sp = NULL;
            u16 id;
            Ov003KbUnit *o;
            if (rec != NULL) {
                sp = (Ov003KbSpawn *)(rec + 0x3a);
            }
            id = 0x4801;
            if (sp != NULL && sp->id != 0xffff) {
                id = sp->id;
            }
            v.x = self->model->unk_c6 << 4;
            v.y = self->model->unk_c8 << 4;
            v.z = self->model->unk_ca << 4;
            func_01ffc9fc(&v, &v, self->rotY);
            VEC_Add(&v, &self->pos, &v);
            {
                u16 b = 0xffff;
                if (pl != NULL) {
                    b = pl->unk_0c;
                }
                o = func_ov000_0219be1c(id, &v, self->unk_7c, self->unk_0c, b);
            }
            if (o != NULL) {
                self->unk_de = o->unk_0c;
            }
            if (o != NULL && sp != NULL) {
                o->unk_18 = sp->unk_02;
            }
            self->work->state = 0x14;
        }
    case 20: {
        s16 k = self->model->unk_c4;
        if ((u16)(s16)(k - 3) <= 1) {
            Ov003KbUnit *o = Ov003Kb_FindUnit(self->unk_de);
            if (o != NULL) {
                func_ov000_0218d46c(o, self->unk_0c, 0xb);
                self->unk_de = 0xffff;
            }
            if (k == 4) {
                self->work->state = 10;
            } else {
                self->work->state = 0x32;
            }
        }
        break;
    }
    case 50: {
        Ov003KbCtl *c;
        if (self->model->unk_c4 >= 10) {
            w->timer = self->model->unk_c4;
        }
        c = self->ctl;
        if ((c->flags & 0x40000000) || c->unk_58 != 0) {
            self->unk_9c >>= 1;
            self->unk_a4 = 0xc00;
        }
        if (func_ov000_02191120(self->model)) {
            if (self->ctl->unk_9a_4 && !(self->ctl->flags & 0x20000000)) {
                self->unk_a8 = 0x52;
            }
            self->work->state++;
        }
        break;
    }
    case 51: {
        Ov003KbCtl *c = self->ctl;
        if (Ov003KbCtl_Bit4(c) && !(c->flags & 0x20000000)) {
            break;
        }
        const char *a = data_ov003_021f7a60;
        if (self->unk_ee_0) {
            a = data_ov003_021f7a66;
        }
        func_ov000_02190cb0(self->model, a, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->work->state++;
        if (self->work->timer < 0x14) {
            self->work->timer = 0x14;
        }
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_ec_0 = 1;
        break;
    }
    case 52:
        self->unk_ec_0 = 1;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            func_ov000_02198360(self->work, 1, 0);
        }
        self->ctl->unk_9a_5 = 1;
        break;
    }
    if (self->unk_9c == 0 && self->unk_a0 == 0 && self->unk_a8 == 0) {
        return;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
    if (self->unk_a0 < 0 && (self->ctl->flags & 0x20000000)) {
        self->unk_a0 = 0;
        self->unk_a8 = 0;
        self->unk_a4 = 0xc00;
    }
}

extern char data_ov003_021f7a91[];
extern void func_ov000_02191418(void *model, s32 a, s32 b);
extern Ov003KbObj *func_ov000_02199f60(Ov003KbTgt *t);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_ov000_02199f88(Ov003KbTgt *t, Ov003Kb *self);
extern Ov003KbAnim *func_ov000_02190a30(void *model, s32 n);
extern void func_ov000_021911c8(void *model, s32 v);
extern Ov003KbFx *func_02065f88(s32 id, Ov003KbVec *pos);
extern BOOL func_ov000_02191508(void *model);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

void func_ov003_021d4fd8(Ov003Kb *self) {
    self->ctl->unk_9a_5 = 1;
    switch (self->work->state) {
    case 0: {
        u16 ang;
        func_ov000_02190cb0(self->model, data_ov003_021f7a91, 0x800, 1);
        func_ov000_02191418(self->model, 5, 1);
        if (self->tgt != NULL) {
            Ov003KbObj *o = func_ov000_02199f60(self->tgt);
            if (o == NULL || o == (Ov003KbObj *)self) {
                ang = self->rotY;
            } else {
                ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
            }
        } else {
            ang = self->rotY;
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->def->unk_1c = 0xffff;
        if (self->tgt != NULL) {
            self->tgt->unk_04 = 0xffff;
        }
        self->work->state++;
        break;
    }
    case 1:
        if (!self->unk_b0->unk_0a_10 && self->tgt != NULL) {
            func_ov000_02199f88(self->tgt, self);
        } else {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0x52;
        }
        if (self->tgt != NULL && self->tgt->unk_09 == 0x11) {
            Ov003KbAnim *a = func_ov000_02190a30(self->model, 0);
            func_ov000_021911c8(self->model, (s16)(((s64)a->unk_112 * 0xccd + 0x800) >> 12));
        }
        if (self->tgt != NULL && self->tgt->unk_08 == 0x42) {
            self->work->timer = 0x3c;
        } else {
            self->work->timer = 0x14;
        }
        if (self->unk_ea_11) {
            self->work->timer = 0x78;
        }
        self->work->state++;
        break;
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov003_021f7a60, 0x200, 0);
            self->work->state++;
            if (self->unk_ea_11) {
                Ov003KbFx *e = func_02065f88(0x322, &self->pos);
                self->unk_e0 = e->unk_24;
                e->SetRot(0, self->unk_6c, 0);
                e->SetSize(self->unk_64);
            }
        }
    case 3: {
        Ov003KbWork *w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->unk_ea_11 = 0;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov000_02198360(self->work, 1, 0);
        }
        if (!func_ov000_02191508(self->model) && !self->unk_b0->unk_0a_10) {
            func_ov000_0218dbe0(self, 0);
            func_ov000_021987b8(self->ctl, 0, 0, 0);
            if (self->ctl->flags & 0x20000000) {
                self->unk_a0 = 0;
            }
        }
        break;
    }
    }
    if (!self->unk_b0->unk_0a_11) {
        self->rotY = func_01ffc128(self->unk_96, self->rotY, 0x8cd, 1, 0x8000);
    }
}

extern char data_ov003_021f7a97[];
extern char data_ov003_021f7a9d[];
extern char data_ov003_021f7aa3[];
extern void *data_02097e4c;
extern s32 func_02040528(s32 max);
extern u16 func_ov000_02198da8(Ov003KbCtl *ctl, u16 a);
extern void func_02049f44(void *mgr, s32 id, Ov003KbVec *pos, s32 a);

static inline u16 Ov003Kb_Angle(Ov003Kb *self) {
    u16 ang;
    if (self->tgt != NULL) {
        Ov003KbObj *o = func_ov000_02199f60(self->tgt);
        if (o == NULL || o == (Ov003KbObj *)self) {
            ang = self->rotY;
        } else {
            ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
        }
    } else {
        ang = self->rotY;
    }
    return ang;
}

void func_ov003_021d5348(Ov003Kb *self) {
    switch (self->work->state) {
    case 0:
        if (!func_ov000_02190cb0(self->model, data_ov003_021f7a97, 0x800, 1)) {
            func_ov000_02190cb0(self->model, data_ov003_021f7a91, 0x800, 1);
        }
        func_ov000_02191418(self->model, 5, 1);
        self->unk_96 = Ov003Kb_Angle(self);
        self->unk_98 = self->unk_96 + 0x8000 + func_02040528(0x2000);
        if (self->unk_b0->unk_0a_11) {
            self->rotY = func_01ffc128(self->unk_96, self->rotY, 0x8cd, 1, 0x8000);
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_92 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->def->unk_1c = 0xffff;
        if (self->tgt != NULL) {
            self->tgt->unk_04 = 0xffff;
        }
        self->work->state++;
        break;
    case 1:
        if (self->tgt != NULL) {
            func_ov000_02199f88(self->tgt, self);
        } else {
            self->unk_9c = 0x229;
            self->unk_a0 = 0x28f;
            self->unk_a4 = 0;
            self->unk_a8 = 0x52;
        }
        if (self->unk_b0->unk_0a_10) {
            self->unk_9c = 0;
        }
        if (self->pos.y - self->ctl->unk_6c >= 0x4000) {
            self->unk_a0 = 0;
        }
        self->work->state++;
        break;
    case 2: {
        Ov003KbWork *w;
        if (self->unk_a0 > 0) {
            if (self->ctl->flags & 0x80000000) {
                self->unk_a0 = 0;
            }
        } else {
            Ov003KbCtl *c = self->ctl;
            if ((c->flags & 0x40000000) || c->unk_58 != 0) {
                self->unk_98 = func_ov000_02198da8(c, self->unk_98);
                self->unk_9c = 0x114;
                if (self->unk_a0 < -0xcd) {
                    self->unk_a0 = -0xcd;
                }
                self->work->timer = 0;
            }
            if (self->ctl->flags & 0x20000000) {
                if (self->unk_92 == 0 && self->tgt != NULL) {
                    func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                }
                if (++self->unk_92 <= 2) {
                    func_ov000_02190cb0(self->model, data_ov003_021f7a9d, 0x400, 1);
                    self->unk_a0 = -self->unk_a0 >> 2;
                    self->unk_9c = self->unk_9c - (self->unk_9c >> 2);
                } else {
                    self->unk_9c = 0;
                    self->unk_a0 = 0;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    self->work->state = 10;
                    self->work->timer = 0;
                    return;
                }
                self->work->timer = 0;
            }
        }
        if (!self->unk_b0->unk_0a_11) {
            self->rotY = func_01ffc128(self->unk_96, self->rotY, 0x8cd, 1, 0x8000);
        }
        if (!func_ov000_02191508(self->model) || self->unk_92 != 0) {
            func_ov000_0218dbe0(self, 0);
            s32 a = 1;
            if (self->unk_b0->unk_0a_10) {
                a = 0;
            }
            func_ov000_021987b8(self->ctl, a, 0, 0);
        }
        w = self->work;
        w->timer++;
        if (w->timer > 0x46) {
            self->work->timer = 0x46;
            if (!(self->ctl->unk_54 & 0x20000000)) {
                func_ov000_02198360(self->work, 0x15, 0);
            }
        }
        break;
    }
    case 10:
        if (func_ov000_02191120(self->model)) {
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            if (self->tgt != NULL) {
                if (self->tgt->unk_08 == 0x42) {
                    self->work->timer = 0x2d;
                } else {
                    self->work->timer = 0x14;
                }
            }
            if (self->unk_ea_11) {
                Ov003KbFx *e;
                self->work->timer = 0x78;
                e = func_02065f88(0x322, &self->pos);
                self->unk_e0 = e->unk_24;
                e->SetRot(0, self->unk_6c, 0);
                e->SetSize(self->unk_64);
                self->unk_ea_11 = 0;
            }
            self->work->state++;
        }
        self->ctl->unk_9a_5 = 1;
        break;
    case 11: {
        Ov003KbWork *w = self->work;
        if (self->tgt == NULL) {
            w->state = ((const Ov003KbWork *)w)->state + 1;
            return;
        }
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            func_ov000_02190cb0(self->model, data_ov003_021f7aa3, 0x800, 1);
            self->work->state++;
            self->unk_ec_1 = 1;
        }
        self->ctl->unk_9a_5 = 1;
        break;
    }
    case 12:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->work, 1, 0);
        }
        self->ctl->unk_9a_5 = 1;
        self->unk_ec_1 = 1;
        break;
    }
}


typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
} Ov003KbGame;

typedef struct {
    u8 unk_00[0xb24];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003KbPlayer;

typedef struct {
    u8 unk_00[0x1c];
    s32 unk_1c;
    s32 unk_20;
} Ov003KbFxEnt;

extern char data_ov003_021f7a7f[];
extern Ov003KbGame *data_ov000_021ccd54;
extern void *data_0214a420;
extern u8 func_ov003_021cee68(void);
extern void func_0203f324(Ov003KbCtl *ctl);
extern Ov003KbPlayer *func_ov000_0219bf90(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_02065804(void *mgr, void *e);
extern Ov003KbFxEnt *func_020657b0(void *mgr, void *e);

static inline BOOL Ov003Kb_GameBusy(Ov003KbGame *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Kb_GameIsIdle(Ov003KbGame *g) {
    if (Ov003Kb_GameBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Kb_GameIdle(void) {
    Ov003KbGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Kb_GameIsIdle(g);
    }
    return TRUE;
}

void func_ov003_021d5900(Ov003Kb *self) {
    u8 n;
    BOOL z = self->tgt->unk_00 == 0;
    switch (self->work->state) {
    case 0: {
        u16 ang;
        s32 spd;
        Ov003KbObj *o;
        func_ov000_02190cb0(self->model, data_ov003_021f7a7f, 0x2ab, 0);
        if (self->def->unk_00 == 0) {
            func_ov000_02198360(self->work, 0x15, 0);
            return;
        }
        func_ov000_021915a0(self->model);
        self->def->unk_1c = 0xffff;
        {
            Ov003KbDef *d = self->def;
            d->unk_19 = 0;
            d->unk_1b = 0;
        }
        o = func_ov000_02199f60(self->tgt);
        if (o == NULL || o == (Ov003KbObj *)self) {
            ang = self->rotY;
        } else {
            ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000;
        if (self->tgt->unk_09 == 0 || z) {
            self->def->unk_1a = 0;
        }
        n = self->def->unk_1a;
        if (!self->unk_b0->unk_0a_10 && n != 0) {
            self->unk_9c = 0x52;
            self->unk_9c += n * 0x37;
        } else {
            self->unk_9c = 0;
        }
        self->unk_a8 = 0x29;
        self->unk_a0 = 0x414;
        if (n != 0) {
            self->unk_a0 = self->unk_a0 + n * (self->unk_a8 - 0x48);
        } else if (z) {
            self->unk_a0 >>= 1;
            self->unk_a8 = 0x52;
        }
        {
            Ov003KbCtl *c = self->ctl;
            s32 h = self->pos.y - c->unk_6c;
            if (!(c->flags & 0x20000000)) {
                h += 0x1000;
            }
            if (h >= 0x4000) {
                if (h >= 0x8000) {
                    self->unk_a0 = 0;
                } else if (h >= 0x7000) {
                    self->unk_a0 >>= 3;
                } else if (h >= 0x6000) {
                    self->unk_a0 >>= 2;
                } else {
                    self->unk_a0 >>= 1;
                }
            }
        }
        self->unk_a4 = 0;
        if (self->unk_e8 == 0 && n == 0) {
            self->unk_e8 = 0x5a;
        } else {
            self->unk_e8 = 1;
        }
        if (self->tgt->unk_09 == 0x41 || self->tgt->unk_09 == 0) {
            u8 max;
            n++;
            max = func_ov003_021cee68();
            if (n > max) {
                n = max;
            }
            self->def->unk_1a = n;
        }
        {
            Ov003KbCtl *c = self->ctl;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            func_0203f324(c);
        }
        {
            Ov003Kb44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        {
            Ov003KbPlayer *p = func_ov000_0219bf90();
            if (p != NULL && p->unk_b24_1) {
                func_020627a0(self->unk_0e, self->unk_0c);
                func_020627dc(3);
                data_ov000_021ccd54->unk_ac = 1;
            }
        }
        if (self->def->unk_00 == 0x11) {
            self->def->unk_00 = 0xf;
        }
        self->unk_92 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        if (self->unk_e4 != NULL) {
            func_02065804(data_0214a420, self->unk_e4);
            self->unk_e4 = NULL;
        }
        if (self->unk_e4 == NULL && !z) {
            Ov003KbFx *e = func_02065f88(0x387, &self->pos);
            s32 s;
            self->unk_e4 = e->unk_24;
            s = self->unk_64 + (self->unk_64 >> 2);
            if (s < 0x1000) {
                s = 0x1000;
            }
            e->v14(s, s * 2, s);
        }
        self->work->state++;
        return;
    }
    case 1: {
        Ov003KbWork *w;
        s32 a;
        if (!self->unk_b0->unk_0a_11) {
            self->rotY = func_01ffc128(self->unk_96, self->rotY, 0x8cd, 1, 0x8000);
        }
        if (self->unk_a0 <= 0 && !z) {
            self->unk_a8 = self->def->unk_1a * 0xd;
        }
        func_ov000_0218dbe0(self, 0);
        a = 1;
        if (self->unk_a0 > 0 || self->unk_b0->unk_0a_10) {
            a = 0;
        }
        func_ov000_021987b8(self->ctl, a, 0, 0);
        if (self->unk_a0 > 0) {
            if (self->ctl->flags & 0x80000000) {
                self->unk_a0 = 0;
            }
        } else {
            Ov003KbCtl *c = self->ctl;
            if ((c->flags & 0x40000000) || c->unk_58 != 0) {
                self->unk_98 = func_ov000_02198da8(c, self->unk_98);
                self->unk_9c = 0x8f;
                self->work->timer = 0;
            }
            if (self->ctl->flags & 0x20000000) {
                if (self->unk_92 == 0) {
                    func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                }
                if (++self->unk_92 <= 2 && self->def->unk_1a <= 1) {
                    self->unk_9c = self->unk_9c - (self->unk_9c >> 2);
                    self->unk_a0 = -self->unk_a0 >> 1;
                    self->unk_a8 = 0x52;
                    self->work->timer = 0;
                } else {
                    self->unk_92 = 0;
                    self->unk_9c = 0;
                    self->unk_a0 = 0;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    if (self->tgt->unk_00 == 0) {
                        self->work->state = 10;
                    } else {
                        self->work->state++;
                    }
                }
                if (self->unk_e4 != NULL) {
                    Ov003KbFxEnt *f = func_020657b0(data_0214a420, self->unk_e4);
                    if (f != NULL && (f->unk_20 != 0x388 || self->tgt->unk_00 == 0)) {
                        f->unk_1c = 4;
                        self->unk_e4 = NULL;
                    }
                }
                if (self->unk_e4 == NULL && self->tgt->unk_00 != 0) {
                    Ov003KbFx *e = func_02065f88(0x388, &self->pos);
                    s32 s;
                    self->unk_e4 = e->unk_24;
                    s = self->unk_64 + (self->unk_64 >> 1);
                    if (s < 0x1000) {
                        s = 0x1000;
                    }
                    e->v14(s, s, s);
                }
            }
        }
        w = self->work;
        w->timer++;
        if (w->timer > 0x64) {
            self->work->timer = 0x46;
            if (!(self->ctl->unk_54 & 0x20000000)) {
                func_ov000_02198360(self->work, 0x15, 0);
            }
        }
        return;
    }
    case 2:
        if (!Ov003Kb_GameIdle()) {
            return;
        }
        if (self->unk_e8 != 0) {
            self->unk_e8--;
        }
        if (self->unk_e8 == 0) {
            if (self->unk_e4 != NULL) {
                func_02065804(data_0214a420, self->unk_e4);
                self->unk_e4 = NULL;
            }
            self->def->unk_1a = 0;
            self->def->unk_00 = *func_02070558(self->unk_0e);
            self->unk_9c = 0;
            self->unk_a0 = 0x266;
            self->unk_a4 = 0;
            self->unk_a8 = 0x52;
            func_ov000_02190cb0(self->model, data_ov003_021f7a60, 0x200, 0);
            func_ov000_02198360(self->work, 4, 0);
        }
    case 10:
        self->ctl->unk_9a_5 = 1;
        break;
    }
}

}
