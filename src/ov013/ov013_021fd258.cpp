#include "ov013/ov013.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_ov013_0220b860[];
extern void *data_ov013_0220b7d0[];
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(ActorSub48 *a, VecFx32 *b, u16 *c);
extern Ov003Actor *func_ov000_0219bf90(void);

void Ov013ActVt_0220b5e0_StateDie(Ov013ActVt_0220b5e0 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_Kill(data_0214a420, self->unk_f4);
    }
    if (self->fsm->history[0] == 2) {
        Ov003Actor_Defeat(self, 1, 1, 1);
        return;
    }
    Ov003Actor_StateDie(self);
}

void Ov013ActorBase_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void Ov013Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        func_ov000_0219864c(self->hit, 0, 0);
    }
}

void Ov013ActorBase_UpdateMode1(void) {
}

void Ov013ActorBase_UpdateMode3(void) {
}

void func_ov013_021fd300(void) {
}

void Ov013Actor_State25(void) {
}

void Ov013Actor_State24(void) {
}

void Ov013Actor_State23(void) {
}

void Ov013Actor_State22(void) {
}

void Ov013Actor_State21(void) {
}

void Ov013Actor_State16(Ov003Actor *self) {
    self->vfunc_54();
}

void Ov013Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void Ov013Actor_StateAttack3(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void Ov013Actor_StateAttack2(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

Ov013Boss *Ov013Boss_Dtor(Ov013Boss *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov013Boss *Ov013Boss_DtorDelete(Ov013Boss *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013ActVt_0220b5e0 *Ov013ActVt_0220b5e0_Dtor(Ov013ActVt_0220b5e0 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov013ActVt_0220b5e0 *Ov013ActVt_0220b5e0_DtorDelete(Ov013ActVt_0220b5e0 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

static inline void Ov013_StopHtr(Ov013ActExVt_0220b7d0 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        EffectObj *p = func_020657b0(data_0214a420, self->unk_d0[i]);
        if (p != NULL) {
            p->state = 4;
        }
    }
    if (func_02035b90(data_ov013_0220b860, 7)) {
        func_02036838(data_02097cdc, data_ov013_0220b860, 7, 0);
    }
}

Ov013ActExVt_0220b7d0 *Ov013ActExVt_0220b7d0_Dtor(Ov013ActExVt_0220b7d0 *self) {
    *(void **)self = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    return self;
}

Ov013ActExVt_0220b7d0 *Ov013ActExVt_0220b7d0_DtorDelete(Ov013ActExVt_0220b7d0 *self) {
    *(void **)self = data_ov013_0220b7d0;
    Ov013_StopHtr(self);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov013ActExVt_0220b7d0_Init(Ov013ActExVt_0220b7d0 *self) {
    func_ov000_0219433c(self);
    func_020359d0(data_ov013_0220b860, 7, 0);
}

BOOL Ov013ActExVt_0220b7d0_IsReady(Ov013ActExVt_0220b7d0 *self) {
    BOOL r = func_ov000_021946f8(self);
    return (r & func_02035b90(data_ov013_0220b860, 7)) ? TRUE : FALSE;
}

void Ov013ActExVt_0220b7d0_Start(Ov013ActExVt_0220b7d0 *self) {
    Ov003Actor *p;
    s32 i;
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 0xb, 0);
    self->target = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->target = p->id;
    }
    for (i = 0; i < 2; i++) {
        self->unk_d0[i] = -1;
    }
    self->unk_ce = 0x96;
    self->unk_d8 = 0xccd;
    if (self->speed == 0) {
        self->speed = 0x19a;
    }
    if (self->velY == 0) {
        self->velY = -0xcd;
    }
}


extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern const VecFx32 data_ov013_0220aeb8;
extern char data_ov013_0220b86f[];
extern char data_ov013_0220b87b[];
extern void func_ov000_0219a210(VecFx32 *v, const VecFx32 *off, s32 rot);
extern BOOL func_ov000_021b4738(Ov003Actor *p);
extern void Actor_TurnToPos(Actor *self, VecFx32 *p, s32 a);
extern BOOL func_ov000_0219aae8(Actor *a, Actor *b, u16 c, u8 d, u16 e, VecFx32 *f, void *g, s32 h, s32 i, s16 j, s32 k);
extern void func_ov000_0219b808(u16 id, VecFx32 *pos, void *box, s32 a, s32 b);

struct Ov013HitBox {
    VecFx32 min;
    VecFx32 max;
    u16 rot[3];
    u16 unk_1e;
    u32 unk_20;
    VecFx32 v;
    s32 unk_30;
};

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov013_SetAlpha(EffectObj *o, s32 v) {
    o->alpha = v < 0 ? 0 : v;
    o->alpha = v > 0x1000 ? 0x1000 : v;
}

void Ov013ActExVt_0220b7d0_StateThrown(Ov013ActExVt_0220b7d0 *self) {
    VecFx32 pos;
    VecFx32 pp;
    Ov013HitBox box;
    Ov003Actor *pl = Ov013_FindActor(self->target);
    u8 i;
    if (pl == NULL) {
        return;
    }
    pos.x = self->pos.x;
    pos.y = self->pos.y;
    pos.z = self->pos.z;
    switch (self->fsm->st) {
    case 0: {
        const char *f;
        EffectObj *o;
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        func_ov000_0219a210(&pos, &data_ov013_0220aeb8, self->rot_y);
        f = data_ov013_0220b860;
        o = Effect3D_Create(f, data_ov013_0220b86f, 0, &pos);
        o->loopCount = -1;
        o->SetScaleAll(self->unk_d8);
        EffectObj_AddSndCue(o, 0x3e, 6);
        self->unk_d0[0] = o->id;
        o = EffectGroup_Create(f, data_ov013_0220b87b, &pos);
        o->loopCount = -1;
        o->SetScaleAll(self->unk_d8 >> 1);
        self->unk_d0[1] = o->id;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 1: {
        Ov003Actor *p;
        self->unk_d8 += 0x31;
        p = func_ov000_0219bf90();
        if (p == NULL || func_ov000_021b4738(p)) {
            self->unk_ce = 1;
        }
        self->unk_ce--;
        if (self->unk_ce == 0) {
            self->unk_ce = 0;
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    }
    case 2: {
        EffectObj *o = func_020657b0(data_0214a420, self->unk_d0[0]);
        s32 v = 0;
        if (o != NULL) {
            EffectObj *o2;
            v = o->alpha;
            if (v > 0) {
                v -= 0x52;
            }
            if (v < 0) {
                v = 0;
            }
            Ov013_SetAlpha(o, v);
            o2 = func_020657b0(data_0214a420, self->unk_d0[1]);
            Ov013_SetAlpha(o2, v);
            if (o2->child != NULL) {
                Ov013_SetAlpha(o2->child, v);
            }
        }
        if (v <= 0) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
    }
    if (self->unk_ce > 0x3c) {
        pp.x = pl->pos.x;
        pp.y = pl->pos.y;
        pp.z = pl->pos.z;
        Actor_TurnToPos(self, &pp, 0xcd);
        self->moveYaw = self->rot_y;
    }
    Actor_Move(self, 0);
    for (i = 0; i < 2; i++) {
        EffectObj *o = func_020657b0(data_0214a420, self->unk_d0[i]);
        if (o != NULL) {
            if (i == 0) {
                o->SetScaleXYZ(self->unk_d8, FX_Mul(self->unk_d8, 0x1333), self->unk_d8);
            } else {
                o->SetScaleAll(self->unk_d8 >> 1);
            }
            o->SetPos(&self->pos);
        }
    }
    if (self->pos.y < 0) {
        self->pos.y = 0;
    }
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 1 << (pl->id >> 12), NULL, NULL, FX_Mul(self->unk_d8, 0x800), 0x2000, 100, 0x1000);
    if (pl->hp[0] == 0) {
        return;
    }
    {
        s32 s;
        box.unk_1e = 2;
        box.unk_20 = 0x20000000;
        box.rot[0] = self->rot_x;
        box.rot[1] = self->rot_y;
        box.rot[2] = self->rot_z;
        s = self->unk_d8 + 0x3800;
        box.min.x = -s;
        box.min.y = -0x800;
        box.min.z = -s;
        box.max.x = s;
        box.max.y = 0x800;
        box.max.z = s;
        {
            s32 px = pl->pos.x;
            s32 py = pl->pos.y;
            s32 pz = pl->pos.z;
            box.v.x = self->pos.x - px;
            box.v.y = self->pos.y - py;
            box.v.z = self->pos.z - pz;
        }
        box.v.y = 0;
        VEC_Normalize(&box.v, &box.v);
        box.v.x = FX_Mul(box.v.x, 0xb8);
        box.v.y = FX_Mul(box.v.y, 0xb8);
        box.v.z = FX_Mul(box.v.z, 0xb8);
        box.unk_30 = -1;
        func_ov000_0219b808(self->id, &self->pos, &box, 0, 0);
    }
}
}
