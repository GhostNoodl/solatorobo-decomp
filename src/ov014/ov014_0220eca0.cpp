#include "ov014/ov014.h"

extern "C" {

extern u8 *data_02097d48;
extern u8 data_ov014_02217aac[];
extern char data_ov014_02217c6c[];
extern void func_ov000_02195d88(void *self);
extern void func_ov000_0219763c(void *self);
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern s32 func_ov000_02191318(void *a, s32 b);
extern s32 func_ov000_02191f18(void *a, void *b);
extern s32 func_ov014_0220ec18(s16 *a, u8 *b);
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_02191618(void *p);
extern void func_ov000_02191708(void *p);

#pragma force_active on
Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_Ctor(Ov014ActEx_0220eca0 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_02217aac;
    FLD(s16, self, 0xce) = 0;
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
    FLD(void *, self, 0) = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_0220eca0 *Ov014ActEx_0220eca0_DtorDelete(Ov014ActEx_0220eca0 *self) {
    FLD(void *, self, 0) = data_ov014_02217aac;
    func_02049de8(data_02097e4c, 0x38);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220eca0_Draw(Ov014ActEx_0220eca0 *self) {
    self->model->polyId = Gfx3DState_NextPolyId(data_02097d48 + 0x8b0);
    func_ov000_02194c08(self);
}

void Ov014ActEx_0220eca0_Start(Ov014ActEx_0220eca0 *self) {
    Model0218fe1c *m;
    func_ov000_02194758(self);
    FLD(s16, self, 0xce) = self->unk_18;
    self->unk_d0 = self->unk_1a << 4;
    self->unk_d4 = self->unk_1c << 4;
    FLD(Ov014Flags, self->model, 0xc2).b6 = 0;
    func_ov000_02191920(self->model, 0, 0x1000, 0);
    FLD(Ov014Flags8, func_ov000_02190a30(self->model, 3), 0x111).b3 = 0;
    FLD(Ov014Flags8, func_ov000_02190a30(self->model, 3), 0x111).b2 = 1;
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
    s32 **p;
    self->model->anim_state = 0;
    p = func_ov000_02190a30(self->model, 0);
    if (*p != NULL) {
        t = **p;
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
            self->fsm->timer = FLD(u16, self, 0xce);
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

        if (t < FLD(u16, self, 0xce) - 0xf && t % 15 == 1) {
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
