#include "types.h"
#include "Main/Math/Rot16.h"
#include "nitro/std.h"
#include "ov003/Actor.h"
#include "nitro/mi.h"

extern "C" {


typedef struct {
    s32 m[9];
    VecFx32 t;
} Ov003DwMtx;

typedef struct {
    u8 unk_00[0x7c];
    Rot16 rot;
} Ov003DwTgt;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003DwP40;

typedef struct {
    u8 unk_00[0x40];
    Ov003DwP40 *unk_40;
    u8 unk_44[0xad8];
    u16 unk_b1c;
    u16 unk_b1e;
    u8 unk_b20[4];
    u32 unk_b24_0 : 5;
    u32 unk_b24_5 : 2;
    u32 unk_b24_7 : 2;
    u32 unk_b24_9 : 1;
} Ov003DwPl;

typedef struct {
    u16 a;
    u8 b;
    u16 c;
} Ov003DwArg;

extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a78[];
extern char data_ov003_021f7a7f[];
extern Ov003DwTgt *Target_Get(ActorSub4c *p);
extern u16 Target_LerpToDest(ActorSub4c *p, VecFx32 *pos, s32 a, s32 b);
extern void Model0218fe1c_StopAnim(Model0218fe1c *model);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s16 a, u8 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 v);
extern void HitSphere_Unlink_0203f364(ActorSub48 *ctl);
extern BOOL History_SetState(ActorSub40 *w, u8 a, BOOL b);
extern Ov003DwPl *ActorMgr_FindPlayer(void);
extern void Actor_SendMsg(Ov003DwPl *p, u16 id, s32 a, s32 b, s32 c, Ov003DwArg *arg);
extern void func_ov000_021b4560(Ov003DwPl *p, Ov003Actor *self);

static inline void Ov003DwCtl_Clear(ActorSub48 *c) {
    if (c != NULL) {
        c->unk_9a_4 = 0;
    }
}

void Ov003Actor_StateHeld(Ov003Actor *self) {
    Ov003DwTgt *t;
    ActorSub48 *ctl;
    Ov003DwCtl_Clear(self->hit);
    t = Target_Get(self->targetObj);
    switch (self->fsm->st) {
    case 0: {
        const char *name;
        ActorSub44 *s;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        name = self->targetObj->unk_0c;
        if (name != NULL) {
            if (STD_CompareString(name, data_ov003_021f7a78) == 0) {
                Model0218fe1c_StopAnim(self->model);
            } else {
                Model0218fe1c_SetAnim(self->model, name, 0x1000, 0);
            }
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f7a7f, 0x1000, 0);
        }
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1400);
        ctl = self->hit;
        if (ctl != NULL) {
            ctl->unk_9a_0 = 0;
            ctl->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(ctl);
            ctl = self->hit;
            ctl->unk_50 = 0;
            ctl->unk_54 = 0;
            ctl->unk_58 = 0;
        }
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (t != NULL) {
            u32 r = Target_LerpToDest(self->targetObj, &self->pos, self->fsm->timer, 10);
            self->rot_x = t->rot.x;
        self->rot_y = t->rot.y;
        self->rot_z = t->rot.z;
            if (r < 10) {
                self->fsm->timer = r;
                return;
            }
            self->fsm->st++;
            self->fsm->timer = 0;
        } else {
            History_SetState(self->fsm, 4, 0);
        }
        break;
    case 2:
        if (*self->hp != 0) {
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer > 0xb4) {
                Ov003DwPl *p;
                self->fsm->timer = 0xb4;
                p = ActorMgr_FindPlayer();
                if (p != NULL) {
                    s32 kind = p->unk_40 != NULL ? p->unk_40->kind : 0;
                    if (p->unk_b24_5 != 0 && kind != 0xb && kind != 0x11) {
                        Ov003DwArg arg;
                        p->unk_b1c = 0xffff;
                        p->unk_b1e = 0xffff;
                        p->unk_b24_5 = 0;
                        p->unk_b24_7 = p->unk_b24_9;
                        arg.a = 10;
                        arg.b = 0x50;
                        arg.c = 0xffff;
                        Actor_SendMsg(p, self->id, 9, 0, 6, &arg);
                        func_ov000_021b4560(p, self);
                        Model0218fe1c_SetAnim(self->model, data_ov003_021f7a60, 0x400, 0);
                        History_SetState(self->fsm, 10, 0);
                        return;
                    }
                }
            }
        }
        Target_LerpToDest(self->targetObj, &self->pos, 10, 10);
        self->rot_x = t->rot.x;
        self->rot_y = t->rot.y;
        self->rot_z = t->rot.z;
        if (self->targetObj->unk_18_0) {
            Ov003DwMtx m;
            Model0218fe1c *mdl;
            MI_Copy48B(self->targetObj->unk_20, &m);
            m.t.x = self->pos.x;
            m.t.y = self->pos.y;
            m.t.z = self->pos.z;
            mdl = self->model;
            MI_Copy36B(&m, &mdl->rot);
            mdl->trans.x = m.t.x;
            mdl->trans.y = m.t.y;
            mdl->trans.z = m.t.z;
            self->unk_93_0 = 1;
        }
        break;
    }
}

}
