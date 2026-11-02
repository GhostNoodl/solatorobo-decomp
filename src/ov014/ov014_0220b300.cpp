#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_0220d274(Ov014Act_02209280 *self);

void Ov014Act_02209280_StateAttack3(Ov014Act_02209280 *self) {
    func_ov014_0220d274(self);
}

void Ov014Act_02209280_StateHurt(Ov014Act_02209280 *self) {
    Ov003Actor_StateHurt(self);
}

void Ov014Act_02209280_StateDown(Ov014Act_02209280 *self) {
    if (self->fsm->st == 0) {
        self->targetObj->type = 0xf;
    }
    Ov003Actor_StateDown(self);
}


extern char data_ov014_02217a84[];
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void func_ov000_021911c8(Model0218fe1c *a, s16 b);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *self, u32 i);

void Ov014Act_02209280_StateDie(Ov014Act_02209280 *self) {
    switch (self->fsm->st) {
    case 0:
        self->unk_fc = 0;
        EffectMgr_StopLoop(data_0214a420, self->unk_1dc);
        self->unk_1dc = NULL;
        EffectMgr_StopLoop(data_0214a420, self->unk_1e0);
        self->unk_1e0 = NULL;
        EffectMgr_StopLoop(data_0214a420, self->unk_1e4);
        self->unk_1e4 = 0;
        func_ov000_02190cb0(self->model, data_ov014_02217a84, 0xcd, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x800);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4819, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x481d, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x481e, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x481f, 0x15);
        self->fsm->st++;
        self->fsm->timer = 0xf0;
        break;
    case 1: {
        VecFx32 pos;
        VecFx32 pos2;
        VecFx32 p3;
        VecFx32 p4;
        s32 t;
        s32 v;
        AnimCtrl *a;
        self->rot_y = func_01ffc128(0, self->rot_y, self->unk_b0->unk_02, 1, 0x8000);
        t = self->fsm->timer;
        v = 0;
        a = func_ov000_02190a30(self->model, 0);
        if (a->cur != NULL) {
            v = a->cur->frame;
        }
        if (v > 0x14000) {
            func_ov000_021911c8(self->model, 0);
        }
        if (t % 90 == 0) {
            EffectObj *e;
            pos.x = self->pos.x + Rand_PlusMinus(0x7000);
            pos.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
            pos.z = self->pos.z + 0x3000;
            e = func_02065f88(0x38a, &pos);
            {
                s32 r = Rand_UpTo(0xccd) + 0xccd;
                e->SetScaleAll(r);
            }
        }
        if (t % 55 == 0) {
            EffectObj *e;
            pos2.x = self->pos.x + Rand_PlusMinus(0x7000);
            pos2.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
            pos2.z = self->pos.z + 0x3000;
            e = func_02065f88(4, &pos2);
            e->SetScaleAll(Rand_UpTo(0xccd) + 0xccd);
            EffectObj_AddSndCue(e, 0x56, 2);
        }
        if (t == 0x78) {
            EffectObj *e;
            p3 = self->pos;
            p3.y += 0x3800;
            e = func_02065f88(0x322, &p3);
            e->SetScaleAll(0x2e66);
            e->loopCount = -1;
            self->unk_1f0 = e->id;
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        self->fsm->st++;
        self->fsm->timer = 0x14a;
        p4.x = 0;
        p4.y = 0x3800;
        p4.z = 0;
        func_02065f88(0x38a, &p4)->SetScaleAll(0x3000);
        break;
    }
    case 2:
        Ov003Actor_Defeat(self, 0, 1, 1);
        self->unk_ea_6 = 1;
        self->fsm->st++;
        self->fsm->timer = 0x190;
        break;
    case 3: {
        EffectObj *e = func_020657b0(data_0214a420, self->unk_1f0);
        VecFx32 v;
        if (e == NULL) {
            break;
        }
        v = self->pos;
        v.y += 0x3800;
        e->SetPos(&v);
        break;
    }
    }
}


extern s32 Interp_QuadLerp(s32 t, s32 from, s32 to);

static inline s32 Ov014b_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov014Act_02209280_State21(Ov014Act_02209280 *self) {
    switch (ActorSub40_State(self->fsm)) {
    case 0:
        // The target reloads the state it just switched on (the switch reads it through the const view).
        self->fsm->st++;
        self->fsm->timer = 0x5a;
        break;
    case 1: {
        if (self->fsm->timer == 0x59) {
            VecFx32 p;
            EffectObj *e;
            p = self->pos;
            p.y += 0x3800;
            e = func_02065f88(0x390, &p);
            e->SetScaleXYZ(0x2000, 0x2000, 0x2000);
            e->loopCount = -1;
            e->unk_50 = -0x1e000;
            EffectObj_AddSndCue(e, 0x44, 0);
            EffectObj_AddSndCue(e, 0x44, 0x14);
            EffectObj_AddSndCue(e, 0x44, 0x28);
            e->loopCount = -2;
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        {
            EffectObj *e = func_020658cc(data_0214a420, 0x390);
            if (e != NULL) {
                EffectObj_StopLoop(e);
            }
        }
        self->fsm->st++;
        self->fsm->timer = 0xd2;
        break;
    }
    case 2: {
        s32 t = self->fsm->timer;
        if (t == 0xd2) {
            VecFx32 p;
            EffectObj *e;
            EffectMgr_StopLoop(data_0214a420, self->unk_1f0);
            p = self->pos;
            p.y += 0x3800;
            e = func_02065f88(0x391, &p);
            e->speed = 0x99a;
            e->loopCount = -2;
        } else if (t > 0xb4) {
            EffectObj *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0xd2 - self->fsm->timer) << 12, 0x1e000);
                e->SetScaleAll(Interp_QuadLerp(r, 0x1000, 0x3000));
            }
        } else if (t > 0x6e) {
            EffectObj *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0xb4 - self->fsm->timer) << 12, 0x46000);
                e->SetScaleAll(Interp_QuadLerp(r, 0x3000, 0x1e000));
            }
        } else if (t > 0x5a) {
            EffectObj *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0x6e - self->fsm->timer) << 12, 0x14000);
                u8 a = (Ov014b_Mul64(r, -0x1f000) + 0x1f000) >> 12;
                a = a > 0x1f ? 0x1f : a;
                e->alpha = FX_Div(a << 12, 0x1f000);
            }
        } else {
            if (t == 0x5a) {
                EffectObj *e = func_020658cc(data_0214a420, 0x391);
                if (e != NULL) {
                    void *saved = data_02097dd0->cur;
                    data_02097dd0->cur = data_02097dd0->heapHi;
                    if (e != NULL) {
                        if (e != NULL) {
                            e->Delete();
                        }
                    }
                    data_02097dd0->cur = saved;
                }
            }
            if (t % 30 == 0) {
                VecFx32 p;
                EffectObj *e;
                p.x = self->pos.x + Rand_PlusMinus(0x7000);
                p.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
                p.z = self->pos.z + 0x3000;
                e = func_02065f88(4, &p);
                {
                    s32 r = Rand_UpTo(0xccd) + 0xccd;
                    e->SetScaleAll(r);
                }
            }
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        self->fsm->st++;
        self->fsm->timer = 0x168;
        break;
    }
    case 3: {
        VecFx32 p;
        s32 m = self->fsm->timer % 120;
        if (m == 0) {
            EffectObj *e;
            p.x = self->pos.x + Rand_PlusMinus(0x7000);
            p.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            e = func_02065f88(4, &p);
            {
                s32 r = Rand_UpTo(0xccd) + 0xccd;
                e->SetScaleAll(r);
            }
        }
        if (m == 0x32) {
            EffectObj *e;
            s32 r = Rand_UpTo(0xccd) + 0xccd;
            p.x = self->pos.x + Rand_PlusMinus(0x7000);
            p.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            func_02065f88(4, &p)->SetScaleAll(r);
            e = func_02065f88(0x6d, &p);
            e->SetScaleAll(r);
            EffectObj_AddSndCue(e, 0x56, 0);
        }
        if (m == 0x1e) {
            EffectObj *e;
            s32 r = Rand_UpTo(0xccd) + 0xccd;
            p.x = self->pos.x + Rand_PlusMinus(0x7000);
            p.y = self->pos.y + Rand_UpTo(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            func_02065f88(0x322, &p)->SetScaleAll(r);
            e = func_02065f88(0x320, &p);
            e->SetScaleAll(r);
            e->time = -0x1e000;
            EffectObj_AddSndCue(e, 0x56, 0);
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->fsm->timer = 0x168;
            }
        }
        break;
    }
    }
}

}
