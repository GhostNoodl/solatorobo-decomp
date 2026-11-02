#include "ov014/ov014.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern u8 data_ov014_02217aac[];
extern char data_ov014_02217c6c[];
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);
extern s16 *func_ov000_02191318(Model0218fe1c *a, s32 b);
extern s16 *func_ov000_02191f18(s16 *a, Model0218fe1c *b);
extern s32 func_ov014_0220ec18(s16 *a, Model0218fe1c *b);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void func_ov000_02191920(Model0218fe1c *a, s32 b, s16 c, u8 d);
extern void func_ov000_02191618(Model0218fe1c *p);
extern void func_ov000_02191708(Model0218fe1c *p);

#pragma force_active on
Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_Ctor(Ov014ActEx_0220eca0 *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_02217aac;
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
    *(void **)self = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_DtorDelete(Ov014ActEx_0220eca0 *self) {
    *(void **)self = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220eca0_Draw(Ov014ActEx_0220eca0 *self) {
    self->model->polyId = Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
    func_ov000_02194c08(self);
}

void Ov014ActEx_0220eca0_Start(Ov014ActEx_0220eca0 *self) {
    Model0218fe1c *m;
    func_ov000_02194758(self);
    self->unk_ce = self->unk_18;
    self->unk_d0 = self->unk_1a << 4;
    self->unk_d4 = self->unk_1c << 4;
    self->model->unk_c2_6 = 0;
    func_ov000_02191920(self->model, 0, 0x1000, 0);
    func_ov000_02190a30(self->model, 3)->paused = 0;
    func_ov000_02190a30(self->model, 3)->loop = 1;
    func_ov000_02190cb0(self->model, data_ov014_02217c6c, 0x1000, 1);
    func_ov000_02191618(self->model);
    func_ov000_02191708(self->model);
    Ov014_VecSet(&self->model->scale, self->unk_d0, self->unk_d4, 0x99a);
    self->model->evFunc = (void *)func_ov014_0220ec18;
    func_ov000_02198360(self->fsm, 1, 0);
}

extern BOOL func_ov000_021b4738(Ov003Actor *p);

extern void func_ov014_0220f20c(Actor *self, void *a, void *b, void *c);

static inline void Ov014_Flash(u8 c) {
    FieldState *g = data_ov000_021ccd54;
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
    p = func_ov000_02190a30(self->model, 0);
    if (p->cur != NULL) {
        t = p->cur->frame;
    }
    func_ov000_02191318(self->model, t + 0x2000);
}

void func_ov014_0220ee9c(Ov014ActEx_0220eca0 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->timer = 0x1e;
        self->fsm->st++;
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
    case 1: {
        ActorSub40 *w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0 && self->model->anim_state == 1) {
            Ov014_Release(self);
            Ov014_Flash(0x28);
            func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x38, &self->pos, 0);
            self->fsm->timer = self->unk_ce;
            self->fsm->st++;
        }
        break;
    }
    case 2: {
        Ov003Actor *pl = func_ov000_0219bf90();
        s32 t;
        ActorSub40 *w;
        if (pl == NULL || func_ov000_021b4738(pl)) {
            self->fsm->timer = 0;
            func_02049de8(data_02097e4c, 0x38);
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
            func_02049de8(data_02097e4c, 0x38);
            self->fsm->st++;
        }
        break;
    }
    case 3: {
        BOOL done = FALSE;
        Ov003Actor *pl = func_ov000_0219bf90();
        if (pl == NULL || func_ov000_021b4738(pl)) {
            done = TRUE;
        }
        if (func_ov000_02191120(self->model) || done) {
            func_02049de8(data_02097e4c, 0x38);
            self->model->visible = 0;
            func_ov000_02198360(self->fsm, 0x15, 0);
            self->fsm->st++;
        }
        break;
    }
    }
}
}
