#include "ov000/FieldCam.h"
#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Res/StageFlags.h"
#include "Main/Effect/Effect.h"

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc630[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc6e4[];
extern char data_ov000_021cc6ea[];
extern char data_ov000_021cc6ed[];
extern char data_ov000_021cc6f0[];
extern char data_ov000_021cc6f6[];
extern char data_ov000_021cc6fc[];
extern char data_ov000_021cc702[];
extern char data_ov000_021cc708[];
extern char data_ov000_021cc70b[];
extern char data_ov000_021cc711[];
extern char data_ov000_021cc717[];
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void func_ov000_02191008(void *a);
BOOL func_ov000_02191120(void *a);
void func_ov000_021911c8(void *a, s32 b);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
s32 func_02049afc(void *mgr, s32 id);
void SndMgr_StopSeqArc(void *mgr, s32 id);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);
void func_02062790(u16 a);
void Actor_Move(Actor *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *v, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_ov000_021b1fac(Robo021ca458 *self, s32 a, s32 b);
s32 Ov003_SurfaceSoundId(u32 a);

static inline BOOL GBusy_021ad8ac(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle_021ad8ac(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy_021ad8ac(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void Kill_021ad8ac(Robo021ca458 *self) {
    if (self->unk_998 != NULL) {
        func_ov000_02191008(self->unk_998);
    }
    if (self->seSlot >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->seSlot);
        self->seSlot = -1;
    }
    if (self->unk_b22_0 > 1) {
        self->unk_b22_0 = 1;
        self->rot_x = 0;
        self->rot_z = 0;
        self->unk_9a6 = 0;
        self->unk_9a8 = 0;
        self->unk_9aa = 0;
        self->unk_9a0 = 0;
        self->unk_9a2 = 0;
        self->unk_9a4 = 0;
    }
}

static inline void StopSnd_021ad8ac(Robo021ca458 *self) {
    if (self->seSlot >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->seSlot);
        self->seSlot = -1;
    }
}

static inline void StartSnd_021ad8ac(Robo021ca458 *self) {
    if (self->seSlot < 0) {
        self->seSlot = func_02049afc(data_02097e4c, 0x33);
    }
}

void func_ov000_021ad8ac(Robo021ca458 *self) {
    u16 ang;
    BOOL turn;
    FieldCam *cam = &data_ov000_021ccd54->cam;

    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc6e4, 0x200, 1);
        func_ov000_021915a0(self->model);
        func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
        if ((self->padCur & 2) && self->unk_9ac != 0 && self->seSlot < 0) {
            self->seSlot = func_02049afc(data_02097e4c, 0x33);
        }
        if (self->velY >= 0) {
            self->velY = 0;
        } else {
            self->velY = self->velY >> 1;
        }
        self->friction = 0;
        self->gravity = 0;
        self->rot_x = 0;
        self->rot_z = 0;
        self->fsm->st++;
        self->fsm->timer = 0;
        self->unk_92 = 0;
        self->unk_b22_0 = 2;
        {
            ActorSub48 *m = self->hit;
            if ((m->unk_54 & 0x20000000) && self->pos.y - m->check.y < 0x5000) {
                VecFx32 p;
                p.x = m->check.x;
                p.y = m->check.y;
                p.z = m->check.z;
                func_02065f88(0x12f, &p)->SetScaleAll(0x800);
            }
        }
        func_02062790(1);
        data_ov000_021ccd54->stageFlags = 1;
    case 1: {
        if (!GIdle_021ad8ac()) {
            self->speed = 0;
            self->friction = 0;
            self->velY = 0;
            self->gravity = 0;
            func_ov000_02190cb0(self->model, data_ov000_021cc6e4, 0xe4, 0);
            func_ov000_021915a0(self->model);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
            self->unk_9a8 = func_01ffc128(0xc000, self->unk_9a8, 0x2cd, 1, 0x8000);
            self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x2cd, 1, 0x8000);
            StopSnd_021ad8ac(self);
        } else {
            u16 c = FieldCam_GetYaw(cam);
            u16 f;
            ang = c + self->padDir;
            f = self->padCur;
            turn = FALSE;
            if (!(f & 0x100) && (f & 0xf0)) {
                u16 d;
                turn = TRUE;
                self->rot_y = func_01ffc128(c, self->rot_y, 0x19a, 1, 0x8000);
                d = self->moveYaw - ang;
                if (d < 0x1000 || d > 0xf000) {
                    self->moveYaw = func_01ffc128(ang, self->moveYaw, 0xcd, 1, 0x8000);
                    self->speed += LO_FX_MUL(0x133 - self->speed, 0x133);
                } else {
                    self->speed -= self->speed >> 4;
                    if (self->speed <= 0x29) {
                        self->moveYaw = ang;
                    }
                }
            } else {
                self->speed -= self->speed >> 5;
            }
            if ((self->padCur & 2) && self->unk_9ac != 0) {
                s32 a0;
                u16 rot;
                if (self->unk_9ac > 1) {
                    self->unk_9ac--;
                } else {
                    self->unk_9ac = 0;
                }
                if (turn) {
                    self->velY += LO_FX_MUL(0x52 - self->velY, 0x85);
                    if (self->padCur & 0x40) {
                        ActorSub40 *st = self->fsm;
                        st->timer++;
                        if (st->timer > 0x1e) {
                            self->moveYaw = self->rot_y;
                            self->fsm->st = 10;
                            self->fsm->timer = 0;
                        }
                    }
                } else {
                    self->velY += LO_FX_MUL(0x266 - self->velY, 0x85);
                }
                rot = 0;
                if (turn) {
                    char *anim = NULL;
                    switch ((u32)(u16)((u16)(ang - self->rot_y) + 0x1000) >> 13) {
                    case 0:
                        anim = data_ov000_021cc6f0;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        anim = data_ov000_021cc6f6;
                        rot = 0xc00;
                        break;
                    case 4:
                        anim = data_ov000_021cc6fc;
                        break;
                    case 5:
                    case 6:
                    case 7:
                        anim = data_ov000_021cc702;
                        rot = 0xf400;
                        break;
                    }
                    if (anim != NULL) {
                        func_ov000_02190cb0(self->model, anim, 0xcd, 0);
                    }
                } else {
                    func_ov000_02190cb0(self->model, data_ov000_021cc6e4, 0xe4, 0);
                    func_ov000_021915a0(self->model);
                }
                if ((self->padTrig & 2) || self->seSlot < 0) {
                    func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
                    StartSnd_021ad8ac(self);
                    {
            ActorSub48 *m = self->hit;
            if ((m->unk_54 & 0x20000000) && self->pos.y - m->check.y < 0x5000) {
                VecFx32 p;
                p.x = m->check.x;
                p.y = m->check.y;
                p.z = m->check.z;
                func_02065f88(0x12f, &p)->SetScaleAll(0x800);
            }
        }
                    func_ov000_0219aae8(self, self, 5, 0x11, 0x20, NULL, 0, 0x1000, 0, 0x64, 0x1000);
                } else if (func_ov000_02191120(self->unk_998)) {
                    func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
                    func_ov000_021915a0(self->unk_998);
                }
                self->unk_9a8 = func_01ffc128(0xc000, self->unk_9a8, 0x2cd, 1, 0x8000);
                self->unk_9aa = func_01ffc128(rot, self->unk_9aa, 0x2cd, 1, 0x8000);
                if (self->pos.y > 0x4b000) {
                    self->velY = -0x100;
                }
                self->gravity = 0;
            } else {
                if (self->unk_9ac == 0) {
                    func_02062790(0);
                    data_ov000_021ccd54->stageFlags = 1;
                }
                func_ov000_02190cb0(self->model, data_ov000_021cc636, 0xcd, 0);
                func_ov000_021911c8(self->model, 0x800);
                func_ov000_02190cb0(self->unk_998, data_ov000_021cc708, 0x1000, 0);
                self->gravity += 2;
                if (self->gravity > 0x14) {
                    self->gravity = 0x14;
                }
                self->unk_9a8 = func_01ffc128(0, self->unk_9a8, 0x2cd, 1, 0x8000);
                self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x2cd, 1, 0x8000);
                StopSnd_021ad8ac(self);
                if (self->pos.y - self->unk_afc.y < -0x2d000) {
                    Kill_021ad8ac(self);
                    self->unk_b24_18 = 1;
                    func_ov000_02198360(self->fsm, 4, 0);
                }
            }
        }
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->unk_92 != 0) {
            self->unk_92--;
        }
        {
            u16 f = self->padCur;
            if (!(f & 0x100)) {
                u16 cur = cam->base.pitch;
                u16 t = 0x2800;
                if (f & 0x80) {
                    t += 0x800;
                } else if (f & 0x30) {
                    t += 0x400;
                } else if (f & 0x40) {
                    t -= 0x2000;
                }
                cam->unk_f8 = func_01ffc128(t, cur, 0x266, 1, 0x8000);
                cam->unk_da_4 = 1;
            }
        }
        cam->unk_f4 = cam->base.dist + ((0xb800 - cam->base.dist) >> 1);
        cam->unk_da_2 = 1;
        cam->unk_dc.x = 0;
        cam->unk_dc.y = -0x800;
        cam->unk_dc.z = 0;
        cam->unk_da_0 = 1;
        if (self->hit->unk_50 & 0x20000000) {
            s32 r;
            func_ov000_02190cb0(self->model, data_ov000_021cc630, 0x1000, 0);
            Kill_021ad8ac(self);
            func_02049f44(data_02097e4c, 8, &self->pos, 0);
            r = Ov003_SurfaceSoundId(self->hit->unk_50);
            if (r >= 0) {
                func_0204a028(data_02097e4c, r, &self->pos, -5);
                if ((self->hit->unk_50 & 0xf0f0f0) == 0xe0e000) {
                    VecFx32 p;
                    p.x = self->pos.x;
                    p.y = self->pos.y;
                    p.z = self->pos.z;
                    p.y += 0xccd;
                    func_02065f88(0x2bc, &p);
                    func_02065f88(0x2bd, &p)->SetScaleAll(0x1800);
                } else {
                    func_02065f88(0x12f, &self->pos)->SetScaleAll(0x800);
                }
            }
            self->fsm->st++;
            self->fsm->timer = 0;
            self->velY = 0;
            self->gravity = 0;
            self->friction = 0x800;
            return;
        }
        if (!(self->hit->unk_50 & 0xc0000000)) {
            return;
        }
        if (self->unk_92 != 0) {
            return;
        }
        self->moveYaw = FX_Atan2(self->hit->unk_80, self->hit->unk_88);
        if (self->velY >= 0) {
            s32 a0;
            func_02049f44(data_02097e4c, 0x7c, &self->pos, 0);
            self->unk_92 = 8;
            a0 = self->velY;
            if (a0 < 0) {
                a0 = -a0;
            }
            self->speed += a0;
            self->velY = self->velY >> 1;
        } else {
            self->speed += self->unk_b08 >> 3;
        }
        return;
    }
    case 2: {
        ActorSub40 *st;
        func_ov000_021b1fac(self, 1, 1);
        self->unk_9a8 = func_01ffc128(0, self->unk_9a8, 0x800, 1, 0x8000);
        self->unk_9aa = func_01ffc128(0, self->unk_9aa, 0x59a, 1, 0x8000);
        st = self->fsm;
        st->timer++;
        if (st->timer < 6) {
            return;
        }
        self->fsm->timer = 6;
        if (!func_ov000_02191120(self->model) && ((s64)self->fsm->flags) == 0) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        self->unk_9a6 = 0;
        self->unk_9a8 = 0;
        self->unk_9aa = 0;
        return;
    }
    case 10: {
        EffectObj *e;
        self->unk_b22_0 = 3;
        func_ov000_02190cb0(self->model, data_ov000_021cc70b, 0x200, 1);
        func_ov000_021915a0(self->model);
        func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        StartSnd_021ad8ac(self);
        e = func_02065f88(0x4b0, &self->pos);
        self->unk_b40 = e->id;
        e->SetRot(&self->rot);
        func_02065f88(0x68, &self->pos)->SetRotXYZ(0x4000, self->rot_y, 0);
        self->unk_9a6 = 0;
        self->unk_9a8 = 0;
        self->unk_9aa = 0;
        self->unk_9a0 = 0;
        self->unk_9a2 = 0;
        self->unk_9a4 = 0;
        func_02062790(2);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st++;
    }
    case 11: {
        ActorSub40 *st;
        if (!GIdle_021ad8ac()) {
            self->speed = 0;
            self->friction = 0;
            self->velY = 0;
            self->gravity = 0;
            self->rot_x = func_01ffc128(0, self->rot_x, 0x200, 1, 0x8000);
            self->rot_z = func_01ffc128(0, self->rot_z, 0x266, 1, 0x8000);
            func_ov000_02190cb0(self->model, data_ov000_021cc70b, 0x200, 0);
            func_ov000_021915a0(self->model);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
            StopSnd_021ad8ac(self);
            self->fsm->st++;
            return;
        }
        if (self->unk_9ac > 8) {
            self->unk_9ac -= 8;
        } else {
            self->unk_9ac = 0;
        }
        if (!func_ov000_02191120(self->model)) {
            s32 tgt = data_0214a424->bits18.mode == 1 ? 0x51f : 0x4cd;
            self->speed += LO_FX_MUL(tgt - self->speed, 0x200);
            self->rot_x = func_01ffc128(0, self->rot_x, 0x266, 1, 0x8000);
            self->rot_z = func_01ffc128(0, self->rot_z, 0x266, 1, 0x8000);
        } else if ((self->padTrig & 0x100) && self->unk_9ac != 0) {
            char *anim;
            EffectObj *e;
            self->unk_b22_0 = 4;
            if (self->unk_9ac > 10) {
                self->unk_9ac -= 10;
            } else {
                self->unk_9ac = 0;
            }
            if (!self->unk_b24_9) {
                self->unk_b24_9 = 1;
                anim = data_ov000_021cc711;
            } else {
                self->unk_b24_9 = 0;
                anim = data_ov000_021cc717;
            }
            func_ov000_02190cb0(self->model, anim, 0x800, 1);
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ea, 0x1000, 0);
            self->speed = data_0214a424->bits18.mode == 1 ? 0xd1f : 0xccd;
            self->unk_9a0 = 0;
            self->unk_9a2 = 0;
            self->unk_9a4 = 0;
            e = func_02065f88(0x4b0, &self->pos);
            self->unk_b40 = e->id;
            e->SetRot(&self->rot);
        } else if ((self->padCur & 2) && self->unk_9ac != 0) {
            u16 f;
            s32 tgt;
            u16 cur;
            s32 sp;
            u16 t;
            s32 d;
            tgt = 0;
            self->unk_b22_0 = 3;
            func_ov000_02190cb0(self->model, data_ov000_021cc70b, 0x200, 0);
            func_ov000_021915a0(self->model);
            cur = cam->base.pitch;
            f = self->padCur;
            if (data_0214a424->bits18.flag10) {
                if (f & 0x40) {
                    f = 0x80;
                } else if (f & 0x80) {
                    f = 0x40;
                }
            }
            if (f & 0x40) {
                self->unk_9a0 = func_01ffc128(0x2000, self->unk_9a0, 0x133, 1, 0x8000);
                tgt = -0x414;
                cur = func_01ffc128(0x1200, cur, 0x1ae, 1, 0x8000);
            } else if (f & 0x80) {
                self->unk_9a0 = func_01ffc128(0xe000, self->unk_9a0, 0x133, 1, 0x8000);
                tgt = 0x414;
                cur = func_01ffc128(0xee00, cur, 0x1ae, 1, 0x8000);
            } else {
                self->unk_9a0 = func_01ffc128(0, self->unk_9a0, 0x10a, 1, 0x8000);
                cur = func_01ffc128(0x200, cur, 0x2cd, 1, 0x8000);
            }
            cam->unk_f8 = cur;
            cam->unk_da_4 = 1;
            self->rot_x = func_01ffc128(self->unk_9a0, self->rot_x, 0x59a, 1, 0x8000);
            d = self->pos.y - self->unk_afc.y;
            if (d < -0x2d000) {
                self->velY = 0;
            } else if (d > 0x4b000) {
                self->velY = 0;
            } else {
                self->velY += LO_FX_MUL(tgt - self->velY, 0x8f);
            }
            f = self->padCur;
            t = 0;
            if (f & 0x20) {
                t = 0xe0;
            } else if (f & 0x10) {
                t = 0xff20;
            }
            self->unk_9a2 = func_01ffc128(t, self->unk_9a2, 0x133, 1, 0x8000);
            self->moveYaw = self->moveYaw + self->unk_9a2;
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0xcd, 1, 0x8000);
            self->rot_z = func_01ffc128(-((self->unk_9a2 << 5) + (self->unk_9a2 << 3)), self->rot_z, 0x59a, 1, 0x8000);
            sp = data_0214a424->bits18.mode == 1 ? 0x51f : 0x4cd;
            if (self->padCur & 0xf0) {
                sp -= sp >> 2;
            }
            self->speed += LO_FX_MUL(sp - self->speed, 0x8f);
            self->fsm->timer = 0;
        } else {
            self->unk_b22_0 = 3;
            func_ov000_02190cb0(self->model, data_ov000_021cc70b, 0x200, 0);
            self->speed -= self->speed >> 5;
            self->velY += LO_FX_MUL(0x266 - self->velY, 0x414);
            self->rot_x = func_01ffc128(0xc000, self->rot_x, 0x200, 1, 0x8000);
            self->rot_z = func_01ffc128(0, self->rot_z, 0x266, 1, 0x8000);
            self->fsm->timer++;
        }
        st = self->fsm;
        if (st->timer > 0xc) {
            st->st = 0;
            StopSnd_021ad8ac(self);
            func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
        }
        if (func_ov000_02191120(self->unk_998)) {
            func_ov000_02190cb0(self->unk_998, data_ov000_021cc6ed, 0x1000, 0);
            func_ov000_021915a0(self->unk_998);
        }
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->unk_92 != 0) {
            self->unk_92--;
            return;
        }
        {
            u32 fl = self->hit->unk_50;
            if (fl & 0x20000000) {
                func_02049f44(data_02097e4c, 0x7c, &self->pos, 0);
                self->unk_92 = 8;
                self->velY = 0x519;
                self->speed = self->speed >> 1;
                self->unk_9a0 = 0xee00;
                return;
            }
            if (!(fl & 0xc0000000)) {
                return;
            }
        }
        {
            u16 d;
            u16 h;
            func_02049f44(data_02097e4c, 0x7c, &self->pos, 0);
            self->unk_92 = 8;
            d = FX_Atan2(self->hit->unk_80, self->hit->unk_88) - self->moveYaw;
            if (d <= 0x8000) {
                self->unk_9a2 = 0xc0;
                h = d >> 1;
            } else {
                self->unk_9a2 = 0xff40;
                h = -((u32)(u16)-d >> 1);
            }
            self->moveYaw += h;
            self->speed = self->speed >> 1;
            self->velY = self->velY >> 1;
        }
        return;
    }
    case 12:
        if (!GIdle_021ad8ac()) {
            return;
        }
        StartSnd_021ad8ac(self);
        self->fsm->st--;
        return;
    }
}
}
