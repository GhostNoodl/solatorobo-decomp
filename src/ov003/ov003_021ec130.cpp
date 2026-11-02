#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"

struct Ov003GmSig {
    u8 idx;
    u8 on;
};

struct Ov003GmTable {
    void *res[4];
};

extern "C" {

extern u8 data_ov003_021f99e8[];
extern char data_ov003_021f99d8[];
extern const Ov003GmTable data_ov003_021f99c8;
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627b4(void);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);
extern EffectObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void *Target_Get(ActorSub4c *p);
extern void Actor_SendMsg(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void *func_ov000_0218e9c4(ActorRes *res);
extern void func_ov000_0218f074(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218f110(ActorRes *p);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern u32 Rand_UpTo(u32 max);
extern void func_ov003_021ec668(Ov003Gimmick *self);
extern void func_ov000_0219bd20(u16 id, u16 a, s32 type, s32 b, s32 c, Ov003GmSig *sig);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov003_021ec9e0(Ov003Gimmick *self);

static inline void Ov003Gimmick_Finish(Ov003Gimmick *self) {
    func_020627a0(self->kind, self->id);
    func_020627dc(4);
    data_ov000_021ccd54->stageFlags = 1;
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov003_021ec130(Ov003Gimmick *self) {
    ActorSub40 *w = self->fsm;
    u16 t;
    w->timer++;
    t = w->timer;
    if (t % 30 == 0) {
        VecFx32 pos;
        VecFx32 v;
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        v.x = 0x1333;
        v.y = 0x2000;
        v.z = 0x7800;
        func_ov000_0219b71c(&pos, &v, 0x666, 0x1000, 0, 0x3c);
        func_ov000_0218996c(8, 8);
        func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
    }
    if (t <= 0xf0) {
        return;
    }
    switch (self->unk_1a) {
    case 0:
        Ov003Gimmick_Finish(self);
        break;
    case 1:
        self->fsm->timer = 0;
        break;
    }
}

void func_ov003_021ec270(Ov003Gimmick *self) {
    void *p;
    if (self->fsm->st != 0) {
        return;
    }
    func_020627b4();
    p = Target_Get(self->targetObj);
    if (p != NULL) {
        Actor_SendMsg(p, self->id, 3, 1, 0, 0);
    }
    self->targetObj->target = 0xffff;
    self->fsm->st++;
    Ov003Gimmick_Finish(self);
}

Ov003Gimmick *Ov003ActVt_021f99e8_Ctor(Ov003Gimmick *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov003_021f99e8;
    func_ov000_0218e9c4(&self->res);
    self->unk_ce_u = 1;
    self->unk_cf_u = 3;
    return self;
}

void Ov003ActVt_021f99e8_Init(Ov003Gimmick *self) {
    Ov003GmTable tbl = data_ov003_021f99c8;
    func_ov000_0219433c(self);
    func_ov000_0218f074(&self->res, tbl.res[self->kind - 0x4063], 1, 0, 0, 0);
    self->res.unk_00 = 0;
}

BOOL Ov003ActVt_021f99e8_IsReady(Ov003Gimmick *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res.unk_00 >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    return r;
}

void Ov003ActVt_021f99e8_Start(Ov003Gimmick *self) {
    s16 k;
    u8 i;
    func_ov000_02194758(self);
    k = self->unk_18;
    self->unk_ce_u = k;
    if (!(k & 0xff)) {
        self->unk_ce_u = 1;
    }
    self->unk_cf_u = 0;
    self->rotOfs.y = 0;
    self->rotOfs.z = 0;
    self->rotOfs.x = 0x4000;
    self->unk_d6 = 0;
    if (self->kind == 0x4064) {
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        if (self->unk_1e == 0) {
            self->unk_1e = 0x78;
        }
        if (self->unk_1c == 1) {
            self->unk_d6 = self->unk_1e;
        }
    }
    for (i = 0; i < 3; i++) {
        self->vals[i] = 0;
    }
    if (self->targetObj != NULL) {
        self->targetObj->unk_18_5 = 1;
    }
}

void func_ov003_021ec4ac(Ov003Gimmick *self, ActorMsg *msg) {
    if (msg->type == 0xe) {
        self->vals[msg->unk_08] = msg->unk_09;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov000_021950e8(self, msg);
}

void Ov003ActVt_021f99e8_Update(Ov003Gimmick *self) {
    if (self->kind != 0x4064) {
        return;
    }
    if (self->unk_cf_u == 1) {
        return;
    }
    switch (self->model->anim_state) {
    case 1:
        self->unk_cf_u = 0;
        break;
    case 2:
        self->unk_cf_u = 3;
        break;
    case 3:
        self->unk_cf_u = 2;
        break;
    }
    switch (self->unk_cf_u) {
    case 2:
        self->rotOfs.y += 0x333;
        break;
    case 3:
        self->rotOfs.y -= 0x333;
        break;
    }
}

void func_ov003_021ec580(Ov003Gimmick *self) {
    if (self->unk_cf_u == 1) {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer >= 0x96) {
            EffectObj *e;
            self->fsm->timer = Rand_UpTo(0xf);
            e = func_02065f88(0x322, &self->pos);
            e->AddPosXYZ(0, self->centerY, 0);
            e->SetScaleXYZ(self->radius, self->radius, self->radius);
            e->speed = 0x4000;
        }
    } else {
        switch (self->kind) {
        case 0x4064:
            func_ov003_021ec668(self);
            break;
        case 0x4065:
            func_ov003_021ec9e0(self);
            break;
        }
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        func_ov000_02198360(self->fsm, 4, 0);
    }
}

static inline BOOL Ov003GmGlobal_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003GmGlobal_IsIdle(FieldState *g) {
    if (Ov003GmGlobal_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Gm_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003GmGlobal_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003GmGlobal_Flag(FieldState *g) {
    return g->event != 0 ? TRUE : FALSE;
}

void func_ov003_021ec668(Ov003Gimmick *self) {
    VecFx32 v;
    Rot16 r;
    Ov003GmSig sig0;
    Ov003GmSig sig1;
    EffectObj *fx;
    if (!Ov003Gm_GameIdle() || Ov003GmGlobal_Flag(data_ov000_021ccd54)) {
        if (self->unk_bc != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_bc);
            self->unk_bc = NULL;
        }
        return;
    }
    if (self->unk_d6 != 0) {
        self->unk_d6--;
        if (self->unk_d6 != 0) {
            return;
        }
    }
    switch (self->fsm->st) {
    case 0: {
        u8 n = 0;
        u8 i;
        func_ov000_02190cb0(self->model, data_ov003_021f99d8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        for (i = 0; i < 3; i++) {
            if (i != self->unk_1c && self->unk_1c < 3 && self->vals[i] != 0) {
                n++;
            }
        }
        if (n >= 2) {
            return;
        }
        self->fxOffset.x = 0;
        self->fxOffset.y = 0x1333;
        self->fxOffset.z = 0;
        VEC_Add(&self->pos, &self->fxOffset, &v);
        fx = (EffectObj *)func_02065f88(0x25e, &v);
        if (fx == NULL) {
            return;
        }
        r.x = self->rotOfs.x + self->rot.x;
        r.y = self->rotOfs.y + self->rot.y;
        r.z = self->rotOfs.z + self->rot.z;
        self->unk_bc = fx->id;
        fx->SetRot(&r);
        self->fsm->st++;
        sig0.idx = self->unk_1c;
        sig0.on = 1;
        func_ov000_0219bd20(0x4064, self->id, 0xe, 1, 2, &sig0);
        func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
        break;
    }
    case 1:
        fx = func_020657b0(data_0214a420, self->unk_bc);
        if (fx != NULL) {
            s16 lim = self->unk_1e;
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer <= lim) {
                goto attack;
            }
        }
        {
            if (fx != NULL) {
                fx->state = 4;
            }
            self->unk_bc = NULL;
            self->fsm->st = 0;
            self->fsm->timer = 0;
            sig1.idx = self->unk_1c;
            sig1.on = 0;
            func_ov000_0219bd20(0x4064, self->id, 0xe, 1, 2, &sig1);
            self->unk_d6 = self->unk_1e;
            return;
        }
    attack:
        r.x = self->rot.x + self->rotOfs.x;
        r.y = self->rot.y + self->rotOfs.y;
        r.z = self->rot.z + self->rotOfs.z;
        func_ov000_0219aae8(self, self, 0x3c, 0x11, 2, &self->fxOffset, &r, 0x800, 0x5400, 100, 0x1000);
        r.x = 0;
        fx->SetRot(&r);
        break;
    }
}
}
