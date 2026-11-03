#include "ov014/ov014.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern u8 Ov014ActEx_0220eca0_vtbl[];
extern char data_ov014_02217c6c[];
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);
extern s16 *AnimEvent_Exec(s16 *a, Model0218fe1c *b);
extern s32 func_ov014_0220ec18(s16 *a, Model0218fe1c *b);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void Model0218fe1c_SetAnim3(Model0218fe1c *a, s32 b, s16 c, u8 d);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *p);
extern void Model0218fe1c_ResumeAnim(Model0218fe1c *p);

#pragma force_active on
Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_Ctor(Ov014ActEx_0220eca0 *self) {
    ActorEx_Ctor(self);
    *(void **)self = Ov014ActEx_0220eca0_vtbl;
    self->unk_ce = 0;
    self->unk_d0 = 0x1000;
    self->unk_d4 = 0x1000;
    self->unk_d8.x = 0;
    self->unk_d8.y = 0;
    self->unk_d8.z = 0;
    self->unk_f0 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = 0;
    self->unk_e4 = 0x1000;
    self->unk_e8 = 0x1000;
    self->unk_ec = 0x1000;
    return self;
}
#pragma force_active reset

Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_Dtor(Ov014ActEx_0220eca0 *self) {
    *(void **)self = Ov014ActEx_0220eca0_vtbl;
    SndMgr_Stop(gSndMgr, 0x38);
    ActorEx_DtorBase(self);
    return self;
}

Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_DtorDelete(Ov014ActEx_0220eca0 *self) {
    *(void **)self = Ov014ActEx_0220eca0_vtbl;
    SndMgr_Stop(gSndMgr, 0x38);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220eca0_Draw(Ov014ActEx_0220eca0 *self) {
    self->model->polyId = Gfx3DState_NextPolyId(gGfxSys->unk_8b0);
    ActorEx_Draw(self);
}

void Ov014ActEx_0220eca0_Start(Ov014ActEx_0220eca0 *self) {
    Model0218fe1c *m;
    ActorEx_Start(self);
    self->unk_ce = self->unk_18;
    self->unk_d0 = self->unk_1a << 4;
    self->unk_d4 = self->unk_1c << 4;
    self->model->unk_c2_6 = 0;
    Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
    Model0218fe1c_GetAnimCtrl(self->model, 3)->paused = 0;
    Model0218fe1c_GetAnimCtrl(self->model, 3)->loop = 1;
    Model0218fe1c_SetAnim(self->model, data_ov014_02217c6c, 0x1000, 1);
    Model0218fe1c_ClearLoop(self->model);
    Model0218fe1c_ResumeAnim(self->model);
    Ov014_VecSet(&self->model->scale, self->unk_d0, self->unk_d4, 0x99a);
    self->model->evFunc = (void *)func_ov014_0220ec18;
    History_SetState(self->fsm, 1, 0);
}

extern BOOL Actor_IsDead(Ov003Actor *p);

extern void func_ov014_0220f20c(Actor *self, void *a, void *b, void *c);

static inline void Ov014_Flash(u8 c) {
    FieldState *g = gSceneCmd;
    g->cam.base.shakeX = 0;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 0;
    g->cam.base.shakeTime = c;
    g->cam.base.shakeLen = 0xf;
    g->cam.base.shakeCur = 0xf;
}

static inline void Ov014_Release(Actor *self) {
    s32 t = 0;
    AnimCtrl *p;
    self->model->anim_state = 0;
    p = Model0218fe1c_GetAnimCtrl(self->model, 0);
    if (p->cur != NULL) {
        t = p->cur->frame;
    }
    Model0218fe1c_SetAnimFrame(self->model, t + 0x2000);
}

void Ov014ActEx_0220eca0_StateIdle(Ov014ActEx_0220eca0 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->timer = 0x1e;
        self->fsm->st++;
        SndMgr_PlayAt(gSndMgr, 0x82, &self->pos, 0);
    case 1: {
        ActorSub40 *w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0 && self->model->anim_state == 1) {
            Ov014_Release(self);
            Ov014_Flash(0x28);
            SndMgr_PlayAt(gSndMgr, 0x1b, &self->pos, 0);
            SndMgr_PlayAt(gSndMgr, 0x38, &self->pos, 0);
            self->fsm->timer = self->unk_ce;
            self->fsm->st++;
        }
        break;
    }
    case 2: {
        Ov003Actor *pl = ActorMgr_FindPlayer();
        s32 t;
        ActorSub40 *w;
        if (pl == NULL || Actor_IsDead(pl)) {
            self->fsm->timer = 0;
            SndMgr_Stop(gSndMgr, 0x38);
        }
        t = self->fsm->timer;
        if (t % 4 == 1) {
            s32 h = FX_Mul(self->height, self->unk_d4);
            self->unk_e4 = FX_Mul(self->radius, self->unk_d0);
            self->unk_e8 = h;
            self->unk_ec = 0x1000;
            self->unk_d8 = self->pos;
            self->unk_d8.y += h / 2;

            self->unk_f0 = self->rot_x;
            self->unk_f2 = self->rot_y;
            self->unk_f4 = self->rot_z;
            func_ov014_0220f20c(self, (u8 *)self + 0xd8, (u8 *)self + 0xf0, (u8 *)self + 0xe4);
        }

        if (t < self->unk_ce - 0xf && t % 15 == 1) {
            Ov014_Flash(0xc);
        }
        w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0 && self->model->anim_state == 2) {
            Ov014_Release(self);
            SndMgr_Stop(gSndMgr, 0x38);
            self->fsm->st++;
        }
        break;
    }
    case 3: {
        BOOL done = FALSE;
        Ov003Actor *pl = ActorMgr_FindPlayer();
        if (pl == NULL || Actor_IsDead(pl)) {
            done = TRUE;
        }
        if (Model0218fe1c_IsAnimDone(self->model) || done) {
            SndMgr_Stop(gSndMgr, 0x38);
            self->model->visible = 0;
            History_SetState(self->fsm, 0x15, 0);
            self->fsm->st++;
        }
        break;
    }
    }
}
}
