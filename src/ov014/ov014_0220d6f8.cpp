#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217bdc[];
extern u8 data_ov014_02217b44[];
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern Ov003Actor *Actor_GetTarget(Actor *self);

extern char data_ov014_02217a4e[];
extern char data_ov014_02217a9c[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov014_0220a490(Ov014Act_02209280 *self, VecFx32 *vel, u16 a, u16 b, u16 c);

void func_ov014_0220d274(Ov014Act_02209280 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217a4e, 0x2ab, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_021915a0(self->model);
        self->unk_fc = 1;
        EffectMgr_StopLoop(data_0214a420, self->unk_1dc);
        self->unk_1dc = NULL;
        EffectMgr_StopLoop(data_0214a420, self->unk_1e0);
        self->unk_1e0 = NULL;
        self->fsm->st++;
        self->fsm->timer = 0x3c;
        break;
    case 1:
        if (self->fsm->timer == 0x3c) {
            VecFx32 p;
            p.x = self->unk_160;
            p.y = self->unk_164;
            p.z = self->unk_168;
            func_02065f88(0x648, &p)->SetScaleAll(0x4000);
            p.x = self->unk_194;
            p.y = self->unk_198;
            p.z = self->unk_19c;
            func_02065f88(0x648, &p)->SetScaleAll(0x4000);
        } else if (self->fsm->timer == 0x28) {
            VecFx32 p;
            p.x = self->unk_160;
            p.y = self->unk_164;
            p.z = self->unk_168;
            func_02065f88(0x258, &p)->SetScaleAll(0x5000);
            p.x = self->unk_194;
            p.y = self->unk_198;
            p.z = self->unk_19c;
            func_02065f88(0x258, &p)->SetScaleAll(0x5000);
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->fsm->st = 10;
            }
        }
        break;
    case 10:
        self->unk_f8 = self->step->unk_04;
        func_ov000_02190cb0(self->model, data_ov014_02217a9c, 0x2ab, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 11: {
        u8 *m = (u8 *)self->model;
        if (FLD(s16, m, 0xc4) == 2) {
            FLD(s16, m, 0xc4) = 0;
            func_ov000_021911c8(self->model, 0x1400);
            break;
        }
        if (FLD(s16, m, 0xc4) == 1) {
            FieldState *g = data_ov000_021ccd54;
            g->cam.base.flags |= 0x1c;
            g->cam.base.shakeTime = 0x1e;
            g->cam.base.shakeLen = 10;
            g->cam.base.shakeCur = 10;
            self->fsm->st++;
            self->fsm->timer = 0;
            self->unk_f8 = self->step->unk_04;
        }
        break;
    }
    case 12: {
        u16 t;
        u8 *pl;
        VecFx32 v;
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        t = self->step->time;
        pl = func_ov000_0219bf90();
        if (pl != NULL && !(self->unk_f8 & 3)) {
            v.x = FLD(s32, pl, 0x70);
            v.y = FLD(s32, pl, 0x74);
            v.z = FLD(s32, pl, 0x78);
            v.y = 0;
        } else {
            s32 x = Rand_UpTo(0x4000) + 0x3000;
            if (self->unk_f8 & 1) {
                x = -x;
            }
            s32 z;
            z = Rand_PlusMinus(0x4000) + 0xb000;
            v.x = x;
            v.y = 0;
            v.z = z;
        }
        if (v.z < 0x3000) {
            v.z = 0x3000;
        }
        func_ov014_0220a490(self, &v, 0, 0x23, 0x28);
        self->unk_f8--;
        if (self->unk_f8 != 0) {
            self->fsm->timer = t;
            break;
        }
        self->fsm->st++;
        self->fsm->timer = 0x23;
        break;
    }
    case 13: {
        ActorSub40 *s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            break;
        }
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    }
    case 20: {
        ActorSub40 *s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_fc = 0;
            self->fsm->st = 0xffff;
        }
        break;
    }
    }
}

void func_ov014_0220d6f8(Ov014Act_02209280 *self) {
    self->vfunc_7c();
}

#pragma force_active on
Ov014ActEx_0220d70c *Ov014ActEx_0220d70c_Ctor(Ov014ActEx_0220d70c *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov014_02217bdc;
    self->unk_d0 = NULL;
    self->unk_d4 = NULL;
    self->unk_d8.x = 0;
    self->unk_d8.y = 0;
    self->unk_d8.z = 0;
    return self;
}
#pragma force_active reset

Ov014ActEx_0220d70c *Ov014ActEx_0220d70c_Dtor(Ov014ActEx_0220d70c *self) {
    FLD(void *, self, 0) = data_ov014_02217bdc;
    if (self->unk_d0 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_d0);
    }
    if (self->unk_d4 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_d4);
    }
    func_ov000_0219429c(self);
    return self;
}

Ov014ActEx_0220d70c *Ov014ActEx_0220d70c_DtorDelete(Ov014ActEx_0220d70c *self) {
    FLD(void *, self, 0) = data_ov014_02217bdc;
    if (self->unk_d0 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_d0);
    }
    if (self->unk_d4 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_d4);
    }
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_0220d70c_Draw(Ov014ActEx_0220d70c *self) {
    func_ov000_02194c08(self);
}

void Ov014ActEx_0220d70c_Start(Ov014ActEx_0220d70c *self) {
    func_ov000_02194758(self);
    self->unk_d8 = FLD(Ov014Vec16, self, 0x18);
    if (self->unk_1e == 0) {
        func_ov000_02198360(self->fsm, 1, 0);
    } else {
        func_ov000_02198360(self->fsm, 0xb, 0);
    }
    if (self->target != 0xffff) {
        Ov003Actor *a = Actor_GetTarget(self);
        if (a != NULL) {
            self->unk_84 = a->pos;
        }
    }
}

extern BOOL func_ov000_021b4738(u8 *p);
extern EffectObj *func_ov014_0220f7f0(s32 k, VecFx32 *pos);
extern void *Target_Get(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);

static inline void Ov014_d890Fire(Ov014ActEx_0220d70c *self) {
    VecFx32 v;
    void *a = Target_Get(self->targetObj);
    {
        s32 y = -self->pos.y;
        v.x = 0;
        v.y = y;
        v.z = 0;
    }
    func_ov000_0219aae8(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, 0,
                        self->radius, self->height, 0x64, 0x1000);
}

// The durations in unk_d8 are read unsigned here. (u16)self->unk_d8.x loads them signed
// (ldrsh) and changes the code, so these reads stay FLD.
void func_ov014_0220d890(Ov014ActEx_0220d70c *self) {
    BOOL noPl = FALSE;
    u8 *pl = func_ov000_0219bf90();
    if (pl == NULL || func_ov000_021b4738(pl)) {
        noPl = TRUE;
    }
    switch (self->fsm->st) {
    case 0:
        self->pos = self->unk_84;
        self->fsm->st++;
        self->fsm->timer = FLD(u16, self, 0xd8);
        break;
    case 1: {
        ActorSub40 *s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            break;
        }
        if (!noPl) {
            VecFx32 v;
            EffectObj *o;
            v = self->pos;
            v.z += 0x1800;
            o = func_ov014_0220f7f0(2, &v);
            o->SetScaleXYZ(0x1ccd, 0x1666, 0x1ccd);
            o->loopCount = -2;
            o->unk_50 = -0x64000;
            func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
            self->unk_d0 = o->id;
        }
        self->fsm->st++;
        self->fsm->timer = FLD(u16, self, 0xda);
        break;
    }
    case 2:
        if (self->fsm->timer < 0x1e && self->unk_d0 != NULL) {
            EffectMgr_StopLoop(data_0214a420, self->unk_d0);
            self->unk_d0 = NULL;
        }
        if (self->fsm->timer == 0) {
            if (!noPl) {
                EffectObj *o = func_ov014_0220f7f0(1, &self->pos);
                EffectObj *e;
                self->unk_d4 = o->id;
                o->SetScaleXYZ(0x1400, 0x2400, 0x1400);
                o->unk_50 = -0x64000;
                e = func_02065f88(0x66, &self->pos);
                e->SetScaleAll(0x2400);
                e->unk_50 = -0x64000;
                func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
                {
                    FieldState *g = data_ov000_021ccd54;
                    g->cam.base.flags |= 0x1c;
                    g->cam.base.shakeTime = 0x1e;
                    g->cam.base.shakeCur = g->cam.base.shakeLen = 10;
                }
            }
            self->fsm->st++;
            self->fsm->timer = FLD(u16, self, 0xdc);
            break;
        }
        {
            ActorSub40 *s = self->fsm;
            u16 t = ActorSub40_Timer(s);
            if (t != 0) {
                s->timer = t - 1;
            }
        }
        break;
    case 3: {
        ActorSub40 *s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            if (s->timer % 4 == 0 && !(s->timer & 3)) {
                Ov014_d890Fire(self);
            }
            break;
        }
        self->fsm->timer = 0x78;
        self->fsm->st++;
        break;
    }
    case 4: {
        EffectObj *o = func_020657b0(data_0214a420, self->unk_d4);
        ActorSub40 *s;
        if (o == NULL) {
            func_ov000_02198360(self->fsm, 0x15, 0);
            self->unk_d4 = NULL;
            break;
        }
        s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            o->state = 4;
            self->unk_d4 = NULL;
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (!(s->timer & 3)) {
            Ov014_d890Fire(self);
        }
        break;
    }
    }
}

}
