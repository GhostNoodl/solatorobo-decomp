#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217d7c[];
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern s32 Interp_SinLerp(s32 a, s32 b, s32 c);

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern char data_ov014_02217d3a[];
extern char data_ov014_02217d4c[];
extern u8 data_ov014_02216e08[];
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, VecFx32 *pos, u16 *rot, u16 a);

static inline void Ov014_TimerDec(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void Ov014Act_0221267c_StateAttack3(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0: {
        s32 base;
        u16 ang;
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d3a, 0x19a, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st = 10;
        self->fsm->timer = 0x14;
        base = self->unk_354 != 0 ? -0x1555 : 0x1555;
        ang = FX_Atan2(self->unk_84.x - self->pos.x, self->unk_84.z - self->pos.z);
        self->unk_34c = base + ang;
        self->unk_312 = 3;
        self->unk_350 = (-base * 2) / 3;
        break;
    }
    case 10: {
        EffectObj *e = Effect_SpawnId(0x5e1, &self->unk_314.trans);
        e->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        self->fsm->st++;
        self->fsm->timer = 0x3c;
        break;
    }
    case 11: {
        self->rot_y = func_01ffc128(self->unk_34c, self->rot_y, 0x400, 1, 0x8000);
        s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov014_02217d4c, 0x19a, 0);
            Model0218fe1c_ClearLoop(self->model);
            self->fsm->st++;
        } else {
            Ov014_TimerDec(s);
        }
        break;
    }
    case 12: {
        Ov014SpawnDesc d;
        Ov003Actor *o;
        if (self->model->anim_state != 1) {
            break;
        }
        Ov014Spawn_Init(&d, 0x483b);
        o = Group_SpawnActor(data_ov000_021ccd64, &d, &self->unk_314.trans, &self->rot_x, 0xffff);
        o->unk_60 = data_ov014_02216e08;
        o->target = self->target;
        if (o->targetObj != NULL) {
            o->targetObj->target = self->id;
        }
        o->flags_0 = 1;
        self->target_id = o->id;
        self->unk_312--;
        self->fsm->st++;
        self->fsm->timer = 0x32;
        break;
    }
    case 13:
        if (ActorSub40_Timer(s) == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov014_02217d3a, 0x19a, 0);
            Model0218fe1c_SetLoop(self->model);
            if (self->unk_312 == 0) {
                self->fsm->st = 0x14;
                self->fsm->timer = 0x14;
            } else {
                self->unk_34c = self->unk_34c + self->unk_350;
                self->fsm->st = 0xb;
                self->fsm->timer = 0x14;
            }
        } else {
            Ov014_TimerDec(s);
        }
        break;
    case 0x14:
        if (ActorSub40_Timer(s) == 0) {
            s->st = 0xffff;
        } else {
            Ov014_TimerDec(s);
        }
        break;
    default:
        s->st = 0xffff;
        break;
    }
}

void Ov014Act_0221267c_StateHurt(Ov014Act_0221267c *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d7c, 0x1000, 0);
        Model0218fe1c_SetAnimFrame(self->model, 0);
        Model0218fe1c_ClearLoop(self->model);
        self->fsm->st++;
        SndMgr_PlayAt(data_02097e4c, 0x67, &self->pos, 0);
        break;
    case 1:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->st = 0xffff;
        }
        break;
    default:
        self->fsm->st = 0xffff;
        break;
    }
}

void Ov014Act_0221267c_StateDie(Ov014Act_0221267c *self) {
    switch (self->fsm->st) {
    case 0: {
        u8 c;
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d7c, 0x19a, 0);
        Model0218fe1c_SetAnimFrame(self->model, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        self->fsm->st++;
        self->fsm->timer = 120;
        c = 0x15;
        ActorMgr_SendToKindOthers(0x483a, self->id, 2, 1, 1, &c);
        ActorMgr_SendToKindOthers(0x483b, self->id, 2, 1, 1, &c);
        SndMgr_PlayAt(data_02097e4c, 0x68, &self->pos, 0);
        break;
    }
    case 1: {
        u8 b;
        if (self->fsm->timer % 30 == 0) {
            Effect_SpawnId(0x38a, &self->pos);
        }
        b = Interp_SinLerp(FX_Div(self->fsm->timer << 12, 0x78000), 0, 0x1f000) >> 12;
        self->model->alpha = b;
        self->mdl.alpha = b;
        if (self->fsm->timer == 0) {
            self->fsm->st++;
        }
        if (self->fsm->timer != 0) {
            self->fsm->timer--;
        }
        break;
    }
    case 2:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        self->fsm->st = 0xffff;
        break;
    }
}

}
