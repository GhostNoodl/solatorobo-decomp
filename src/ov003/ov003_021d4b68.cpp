#include "types.h"
#include "ov003/Actor.h"

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
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
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
} Ov003KbUnit;

typedef struct {
    u16 id;
    s8 unk_02;
} Ov003KbSpawn;

extern "C" {

extern void *data_ov000_021ccd68;
extern const char *data_ov003_021f7a38[2][2];
extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern Ov003KbUnit *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(void *self, Ov003KbUnit *target, s32 a);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(VecFx32 *out, VecFx32 *in, u16 ang);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern Ov003KbUnit *func_ov000_0219be1c(u16 id, VecFx32 *pos, void *rot, u16 a, s32 b);
extern void func_ov000_0218d46c(Ov003KbUnit *u, u16 a, s32 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_ov000_021915a0(void *model);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void Actor_Move(void *self, s32 a);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);

static inline Ov003KbUnit *Ov003Kb_FindUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Ov003KbCtl_Bit4(ActorSub48 *c) {
    return c->unk_9a_4 ? TRUE : FALSE;
}

void func_ov003_021d4b68(Ov003Actor *self) {
    Ov003KbUnit *pl = Ov003Kb_FindUnit(self->target);
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f7a38[self->unk_ee_5][self->unk_ee_6], 0x400, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        Actor_TurnToActor(self, pl, self->unk_b0->unk_02);
        if (self->model->anim_state == 1) {
            self->fsm->st = 10;
        }
    case 10:
        if (self->model->anim_state >= 2) {
            VecFx32 v;
            u8 *rec = func_02070558(self->kind);
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
            func_01ffc9fc(&v, &v, self->rot_y);
            VEC_Add(&v, &self->pos, &v);
            {
                u16 b = 0xffff;
                if (pl != NULL) {
                    b = pl->unk_0c;
                }
                o = func_ov000_0219be1c(id, &v, &self->rot_x, self->id, b);
            }
            if (o != NULL) {
                self->target_id = o->unk_0c;
            }
            if (o != NULL && sp != NULL) {
                o->unk_18 = sp->unk_02;
            }
            self->fsm->st = 0x14;
        }
    case 20: {
        s16 k = self->model->anim_state;
        if ((u16)(s16)(k - 3) <= 1) {
            Ov003KbUnit *o = Ov003Kb_FindUnit(self->target_id);
            if (o != NULL) {
                func_ov000_0218d46c(o, self->id, 0xb);
                self->target_id = 0xffff;
            }
            if (k == 4) {
                self->fsm->st = 10;
            } else {
                self->fsm->st = 0x32;
            }
        }
        break;
    }
    case 50: {
        ActorSub48 *c;
        if (self->model->anim_state >= 10) {
            w->timer = self->model->anim_state;
        }
        c = self->hit;
        if ((c->unk_50 & 0x40000000) || c->unk_58 != 0) {
            self->speed >>= 1;
            self->friction = 0xc00;
        }
        if (func_ov000_02191120(self->model)) {
            if (self->hit->unk_9a_4 && !(self->hit->unk_50 & 0x20000000)) {
                self->gravity = 0x52;
            }
            self->fsm->st++;
        }
        break;
    }
    case 51: {
        ActorSub48 *c = self->hit;
        if (Ov003KbCtl_Bit4(c) && !(c->unk_50 & 0x20000000)) {
            break;
        }
        const char *a = data_ov003_021f7a60;
        if (self->unk_ee_0) {
            a = data_ov003_021f7a66;
        }
        func_ov000_02190cb0(self->model, a, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        if (self->fsm->timer < 0x14) {
            self->fsm->timer = 0x14;
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
            func_ov000_02198360(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
    if (self->speed == 0 && self->velY == 0 && self->gravity == 0) {
        return;
    }
    Actor_Move(self, 0);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    if (self->velY < 0 && (self->hit->unk_50 & 0x20000000)) {
        self->velY = 0;
        self->gravity = 0;
        self->friction = 0xc00;
    }
}

extern char data_ov003_021f7a91[];
extern void func_ov000_02191418(void *model, s32 a, s32 b);
extern Ov003KbObj *func_ov000_02199f60(ActorHp *t);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_ov000_02199f88(ActorHp *t, Ov003Actor *self);
extern Ov003KbAnim *func_ov000_02190a30(void *model, s32 n);
extern void func_ov000_021911c8(void *model, s32 v);
extern Ov003KbFx *func_02065f88(s32 id, VecFx32 *pos);
extern BOOL func_ov000_02191508(void *model);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

void func_ov003_021d4fd8(Ov003Actor *self) {
    self->hit->unk_9a_5 = 1;
    switch (self->fsm->st) {
    case 0: {
        u16 ang;
        func_ov000_02190cb0(self->model, data_ov003_021f7a91, 0x800, 1);
        func_ov000_02191418(self->model, 5, 1);
        if (self->hpObj != NULL) {
            Ov003KbObj *o = func_ov000_02199f60(self->hpObj);
            if (o == NULL || o == (Ov003KbObj *)self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
            }
        } else {
            ang = self->rot_y;
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->targetObj->target = 0xffff;
        if (self->hpObj != NULL) {
            self->hpObj->unk_04 = 0xffff;
        }
        self->fsm->st++;
        break;
    }
    case 1:
        if (!self->unk_b0->unk_0a_10 && self->hpObj != NULL) {
            func_ov000_02199f88(self->hpObj, self);
        } else {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0x52;
        }
        if (self->hpObj != NULL && self->hpObj->kind2 == 0x11) {
            Ov003KbAnim *a = func_ov000_02190a30(self->model, 0);
            func_ov000_021911c8(self->model, (s16)(((s64)a->unk_112 * 0xccd + 0x800) >> 12));
        }
        if (self->hpObj != NULL && self->hpObj->kind == 0x42) {
            self->fsm->timer = 0x3c;
        } else {
            self->fsm->timer = 0x14;
        }
        if (self->unk_ea_11) {
            self->fsm->timer = 0x78;
        }
        self->fsm->st++;
        break;
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov003_021f7a60, 0x200, 0);
            self->fsm->st++;
            if (self->unk_ea_11) {
                Ov003KbFx *e = func_02065f88(0x322, &self->pos);
                self->unk_e0 = e->unk_24;
                e->SetRot(0, self->centerY, 0);
                e->SetSize(self->radius);
            }
        }
    case 3: {
        ActorSub40 *w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->unk_ea_11 = 0;
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        if (!func_ov000_02191508(self->model) && !self->unk_b0->unk_0a_10) {
            Actor_Move(self, 0);
            func_ov000_021987b8(self->hit, 0, 0, 0);
            if (self->hit->unk_50 & 0x20000000) {
                self->velY = 0;
            }
        }
        break;
    }
    }
    if (!self->unk_b0->unk_0a_11) {
        self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
    }
}

extern char data_ov003_021f7a97[];
extern char data_ov003_021f7a9d[];
extern char data_ov003_021f7aa3[];
extern void *data_02097e4c;
extern s32 Rand_PlusMinus(s32 max);
extern u16 func_ov000_02198da8(ActorSub48 *ctl, u16 a);
extern void *func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);

static inline u16 Ov003Kb_Angle(Ov003Actor *self) {
    u16 ang;
    if (self->hpObj != NULL) {
        Ov003KbObj *o = func_ov000_02199f60(self->hpObj);
        if (o == NULL || o == (Ov003KbObj *)self) {
            ang = self->rot_y;
        } else {
            ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
        }
    } else {
        ang = self->rot_y;
    }
    return ang;
}

void func_ov003_021d5348(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        if (!func_ov000_02190cb0(self->model, data_ov003_021f7a97, 0x800, 1)) {
            func_ov000_02190cb0(self->model, data_ov003_021f7a91, 0x800, 1);
        }
        func_ov000_02191418(self->model, 5, 1);
        self->unk_96 = Ov003Kb_Angle(self);
        self->moveYaw = self->unk_96 + 0x8000 + Rand_PlusMinus(0x2000);
        if (self->unk_b0->unk_0a_11) {
            self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_92 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->targetObj->target = 0xffff;
        if (self->hpObj != NULL) {
            self->hpObj->unk_04 = 0xffff;
        }
        self->fsm->st++;
        break;
    case 1:
        if (self->hpObj != NULL) {
            func_ov000_02199f88(self->hpObj, self);
        } else {
            self->speed = 0x229;
            self->velY = 0x28f;
            self->friction = 0;
            self->gravity = 0x52;
        }
        if (self->unk_b0->unk_0a_10) {
            self->speed = 0;
        }
        if (self->pos.y - self->hit->check.y >= 0x4000) {
            self->velY = 0;
        }
        self->fsm->st++;
        break;
    case 2: {
        ActorSub40 *w;
        if (self->velY > 0) {
            if (self->hit->unk_50 & 0x80000000) {
                self->velY = 0;
            }
        } else {
            ActorSub48 *c = self->hit;
            if ((c->unk_50 & 0x40000000) || c->unk_58 != 0) {
                self->moveYaw = func_ov000_02198da8(c, self->moveYaw);
                self->speed = 0x114;
                if (self->velY < -0xcd) {
                    self->velY = -0xcd;
                }
                self->fsm->timer = 0;
            }
            if (self->hit->unk_50 & 0x20000000) {
                if (self->unk_92 == 0 && self->hpObj != NULL) {
                    func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                }
                if (++self->unk_92 <= 2) {
                    func_ov000_02190cb0(self->model, data_ov003_021f7a9d, 0x400, 1);
                    self->velY = -self->velY >> 2;
                    self->speed = self->speed - (self->speed >> 2);
                } else {
                    self->speed = 0;
                    self->velY = 0;
                    self->friction = 0;
                    self->gravity = 0;
                    self->fsm->st = 10;
                    self->fsm->timer = 0;
                    return;
                }
                self->fsm->timer = 0;
            }
        }
        if (!self->unk_b0->unk_0a_11) {
            self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        }
        if (!func_ov000_02191508(self->model) || self->unk_92 != 0) {
            Actor_Move(self, 0);
            s32 a = 1;
            if (self->unk_b0->unk_0a_10) {
                a = 0;
            }
            func_ov000_021987b8(self->hit, a, 0, 0);
        }
        w = self->fsm;
        w->timer++;
        if (w->timer > 0x46) {
            self->fsm->timer = 0x46;
            if (!(self->hit->unk_54 & 0x20000000)) {
                func_ov000_02198360(self->fsm, 0x15, 0);
            }
        }
        break;
    }
    case 10:
        if (func_ov000_02191120(self->model)) {
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            if (self->hpObj != NULL) {
                if (self->hpObj->kind == 0x42) {
                    self->fsm->timer = 0x2d;
                } else {
                    self->fsm->timer = 0x14;
                }
            }
            if (self->unk_ea_11) {
                Ov003KbFx *e;
                self->fsm->timer = 0x78;
                e = func_02065f88(0x322, &self->pos);
                self->unk_e0 = e->unk_24;
                e->SetRot(0, self->centerY, 0);
                e->SetSize(self->radius);
                self->unk_ea_11 = 0;
            }
            self->fsm->st++;
        }
        self->hit->unk_9a_5 = 1;
        break;
    case 11: {
        ActorSub40 *w = self->fsm;
        if (self->hpObj == NULL) {
            w->st = ((const ActorSub40 *)w)->st + 1;
            return;
        }
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            func_ov000_02190cb0(self->model, data_ov003_021f7aa3, 0x800, 1);
            self->fsm->st++;
            self->unk_ec_1 = 1;
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
    case 12:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
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
extern void HitSphere_Link(ActorSub48 *ctl);
extern Ov003KbPlayer *func_ov000_0219bf90(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void EffectMgr_Kill(void *mgr, void *e);
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

void func_ov003_021d5900(Ov003Actor *self) {
    u8 n;
    BOOL z = self->hpObj->cur == 0;
    switch (self->fsm->st) {
    case 0: {
        u16 ang;
        s32 spd;
        Ov003KbObj *o;
        func_ov000_02190cb0(self->model, data_ov003_021f7a7f, 0x2ab, 0);
        if (self->targetObj->type == 0) {
            func_ov000_02198360(self->fsm, 0x15, 0);
            return;
        }
        func_ov000_021915a0(self->model);
        self->targetObj->target = 0xffff;
        {
            ActorSub4c *d = self->targetObj;
            d->unk_19 = 0;
            d->unk_1b = 0;
        }
        o = func_ov000_02199f60(self->hpObj);
        if (o == NULL || o == (Ov003KbObj *)self) {
            ang = self->rot_y;
        } else {
            ang = FX_Atan2(o->pos.x - self->pos.x, o->pos.z - self->pos.z);
        }
        self->unk_96 = ang;
        self->moveYaw = self->unk_96 + 0x8000;
        if (self->hpObj->kind2 == 0 || z) {
            self->targetObj->unk_1a = 0;
        }
        n = self->targetObj->unk_1a;
        if (!self->unk_b0->unk_0a_10 && n != 0) {
            self->speed = 0x52;
            self->speed += n * 0x37;
        } else {
            self->speed = 0;
        }
        self->gravity = 0x29;
        self->velY = 0x414;
        if (n != 0) {
            self->velY = self->velY + n * (self->gravity - 0x48);
        } else if (z) {
            self->velY >>= 1;
            self->gravity = 0x52;
        }
        {
            ActorSub48 *c = self->hit;
            s32 h = self->pos.y - c->check.y;
            if (!(c->unk_50 & 0x20000000)) {
                h += 0x1000;
            }
            if (h >= 0x4000) {
                if (h >= 0x8000) {
                    self->velY = 0;
                } else if (h >= 0x7000) {
                    self->velY >>= 3;
                } else if (h >= 0x6000) {
                    self->velY >>= 2;
                } else {
                    self->velY >>= 1;
                }
            }
        }
        self->friction = 0;
        if (self->unk_e8 == 0 && n == 0) {
            self->unk_e8 = 0x5a;
        } else {
            self->unk_e8 = 1;
        }
        if (self->hpObj->kind2 == 0x41 || self->hpObj->kind2 == 0) {
            u8 max;
            n++;
            max = func_ov003_021cee68();
            if (n > max) {
                n = max;
            }
            self->targetObj->unk_1a = n;
        }
        {
            ActorSub48 *c = self->hit;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            HitSphere_Link(c);
        }
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        {
            Ov003KbPlayer *p = func_ov000_0219bf90();
            if (p != NULL && p->unk_b24_1) {
                func_020627a0(self->kind, self->id);
                func_020627dc(3);
                data_ov000_021ccd54->unk_ac = 1;
            }
        }
        if (self->targetObj->type == 0x11) {
            self->targetObj->type = 0xf;
        }
        self->unk_92 = 0;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        if (self->unk_e4 != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_e4);
            self->unk_e4 = NULL;
        }
        if (self->unk_e4 == NULL && !z) {
            Ov003KbFx *e = func_02065f88(0x387, &self->pos);
            s32 s;
            self->unk_e4 = e->unk_24;
            s = self->radius + (self->radius >> 2);
            if (s < 0x1000) {
                s = 0x1000;
            }
            e->v14(s, s * 2, s);
        }
        self->fsm->st++;
        return;
    }
    case 1: {
        ActorSub40 *w;
        s32 a;
        if (!self->unk_b0->unk_0a_11) {
            self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        }
        if (self->velY <= 0 && !z) {
            self->gravity = self->targetObj->unk_1a * 0xd;
        }
        Actor_Move(self, 0);
        a = 1;
        if (self->velY > 0 || self->unk_b0->unk_0a_10) {
            a = 0;
        }
        func_ov000_021987b8(self->hit, a, 0, 0);
        if (self->velY > 0) {
            if (self->hit->unk_50 & 0x80000000) {
                self->velY = 0;
            }
        } else {
            ActorSub48 *c = self->hit;
            if ((c->unk_50 & 0x40000000) || c->unk_58 != 0) {
                self->moveYaw = func_ov000_02198da8(c, self->moveYaw);
                self->speed = 0x8f;
                self->fsm->timer = 0;
            }
            if (self->hit->unk_50 & 0x20000000) {
                if (self->unk_92 == 0) {
                    func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                }
                if (++self->unk_92 <= 2 && self->targetObj->unk_1a <= 1) {
                    self->speed = self->speed - (self->speed >> 2);
                    self->velY = -self->velY >> 1;
                    self->gravity = 0x52;
                    self->fsm->timer = 0;
                } else {
                    self->unk_92 = 0;
                    self->speed = 0;
                    self->velY = 0;
                    self->friction = 0;
                    self->gravity = 0;
                    if (self->hpObj->cur == 0) {
                        self->fsm->st = 10;
                    } else {
                        self->fsm->st++;
                    }
                }
                if (self->unk_e4 != NULL) {
                    Ov003KbFxEnt *f = func_020657b0(data_0214a420, self->unk_e4);
                    if (f != NULL && (f->unk_20 != 0x388 || self->hpObj->cur == 0)) {
                        f->unk_1c = 4;
                        self->unk_e4 = NULL;
                    }
                }
                if (self->unk_e4 == NULL && self->hpObj->cur != 0) {
                    Ov003KbFx *e = func_02065f88(0x388, &self->pos);
                    s32 s;
                    self->unk_e4 = e->unk_24;
                    s = self->radius + (self->radius >> 1);
                    if (s < 0x1000) {
                        s = 0x1000;
                    }
                    e->v14(s, s, s);
                }
            }
        }
        w = self->fsm;
        w->timer++;
        if (w->timer > 0x64) {
            self->fsm->timer = 0x46;
            if (!(self->hit->unk_54 & 0x20000000)) {
                func_ov000_02198360(self->fsm, 0x15, 0);
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
                EffectMgr_Kill(data_0214a420, self->unk_e4);
                self->unk_e4 = NULL;
            }
            self->targetObj->unk_1a = 0;
            self->targetObj->type = *func_02070558(self->kind);
            self->speed = 0;
            self->velY = 0x266;
            self->friction = 0;
            self->gravity = 0x52;
            func_ov000_02190cb0(self->model, data_ov003_021f7a60, 0x200, 0);
            func_ov000_02198360(self->fsm, 4, 0);
        }
    case 10:
        self->hit->unk_9a_5 = 1;
        break;
    }
}

}
