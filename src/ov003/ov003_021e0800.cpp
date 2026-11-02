#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"

extern "C" {

extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);

void Ov003ActVt_021f8058_Start(ActorEx *self) {
    func_ov000_02194758(self);
    self->model->visible = 0;
    ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x400c, 0x15);
    self->pos.y -= 0x14000;
}

extern char data_ov003_021f852b[];
extern char data_ov003_021f8516[];
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 a);
extern void func_ov000_021915a0(void *model);
extern BOOL func_ov000_02191120(void *model);
extern void *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(void *p);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(u8 *p);
extern u32 Rand_UpTo(u32 max);

#define OV003_FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

void func_ov003_021e0848(ActorEx *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        Model0218fe1c *m = self->model;
        m->scale.x = 0;
        m->scale.y = 0;
        m->scale.z = 0;
        self->model->alpha = 0;
        self->model->visible = 1;
        func_ov000_02190cb0(self->model, data_ov003_021f852b, 0x1000, 0);
        func_ov000_021911c8(self->model, 0xc00);
        self->fsm->st++;
        break;
    }
    case 1:
        w->timer++;
        if (w->timer < 0xf0) {
            u16 t = self->fsm->timer;
            s32 sc = OV003_FX32_CONST(3.0f * t / 240.0f) + 0x800;
            Model0218fe1c *m = self->model;
            m->scale.x = sc;
            m->scale.y = sc;
            m->scale.z = sc;
            self->model->alpha = self->fsm->timer * 26 / 240;
        } else {
            Model0218fe1c *m = self->model;
            m->scale.x = 0x3800;
            m->scale.y = 0x3800;
            m->scale.z = 0x3800;
            self->model->alpha = 26;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov003_021f8516, 0xcd, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0xccd);
        }
        break;
    case 2: {
        void *pl;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        pl = func_ov000_0219bf90();
        if (pl != NULL && !func_ov000_021b4738(pl)) {
            FieldState *g;
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = data_ov000_021ccd54;
            g->stageFlags = 1;
            func_ov000_02182590(&g->stageFlags);
            self->fsm->timer = 0;
            self->fsm->st++;
        } else {
            self->fsm->timer = 0x3c;
        }
        break;
    }
    case 3: {
        u8 n = (u8)Rand_UpTo(0xf) + 10;
        u8 v = self->model->alpha;
        if (n > v) {
            v++;
        } else if (n < v) {
            v--;
        }
        self->model->alpha = v;
        break;
    }
    }
}

} // extern "C"
