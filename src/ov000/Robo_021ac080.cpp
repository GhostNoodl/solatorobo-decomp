#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Actor.h"
#include "Main/Res/StageFlags.h"

extern "C" {
extern char data_ov000_021cc5e9[];
extern char data_ov000_021cc6c0[];
extern char data_ov000_021cc636[];
extern void *data_02097e4c;
void func_02062764(s32 a, s32 b);
u16 func_ov000_0219a36c(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);

static inline void SetRgb021ac080(StageFlags *g, u8 r, u8 gr, u8 b) {
    g->color.r = r;
    g->color.g = gr;
    g->color.b = b;
}

static inline BOOL GBusy021ac080(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle021ac080(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021ac080(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_021ac080(Robo021ca458 *self) {
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0:
        self->unk_b24_2 = 2;
        self->unk_b24_1 = 0;
        self->target = 0xffff;
        self->fieldId = data_ov000_021ccd54->unk_ca;
        data_0214a424->bits18.flag8 = 1;
        data_0214a424->target = self->unk_75c;
        data_0214a424->targetRotY = self->unk_76e;
        SetRgb021ac080(data_0214a424, self->unk_772, self->unk_773, self->unk_774);
        func_02062764(3, 2);
        data_ov000_021ccd54->stageFlags = 1;
        self->pos.y += 0x119a;
        func_ov000_02190cb0(&self->mdl1, data_ov000_021cc5e9, 0x155, 0);
        func_ov000_02190cb0(&self->mdl0, data_ov000_021cc6c0, 0x400, 0);
        self->mdl0.unk_cc = 0x320;
        self->fsm->st++;
        break;
    case 1: {
        VecFx32 v;
        self->speed = 0x133;
        self->velY = 0x2cd;
        self->gravity = 0x52;
        self->friction = 0;
        v = self->pos;
        v.y += self->centerY - 0x119a;
        self->moveYaw = func_ov000_0219a36c(&v, 0x2000, self->rot_y, 4, 0, 0xffffffff);
        func_02049f44(data_02097e4c, 0xf, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 2: {
        s32 d;
        u16 t;
        u16 *s;
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        func_ov000_021b1fac(self, FALSE, 1);
        d = self->pos.y - self->unk_75c.y;
        if (d < 0x1800) {
            self->pos.y += (self->unk_75c.y + 0x1800 - self->pos.y) >> 2;
        } else if (d > 0x1ccd) {
            self->pos.y += (self->unk_75c.y + 0x1ccd - self->pos.y) >> 2;
        }
        s = (u16 *)self->fsm;
        s[1]++;
        t = s[1];
        if (t == 10) {
            func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x2ab, 0);
        }
        if (t < 0x16 && GIdle021ac080() && self->mode != 3) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x2ab, 0);
        self->unk_b24_2 = 0;
        func_ov000_02198360(self->fsm, 4, 0);
        break;
    }
    }
}
}

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 z;
} Msg021ac3ec;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6c6[];
extern char data_ov000_021cc6cc[];
void func_ov000_02191008(void *p);
void SndMgr_StopSeqArc(void *mgr, s32 id);
void func_ov000_0218996c(s32 a, s32 b);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
Actor *func_ov000_02199f60(void *p);
void func_ov000_02199f88(void *t, void *self);
void func_ov000_02191418(void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *m);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u16 FX_Atan2(s32 x, s32 z);

static inline Actor *GetObj021ac3ec(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Reset021ac3ec(Robo021ca458 *self) {
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
}

void func_ov000_021ac3ec(Robo021ca458 *self) {
    BOOL go;
    switch (self->fsm->st) {
    case 0: {
        Actor *o;
        char *anm = data_ov000_021cc6c6;
        if (self->unk_93_5 != 0) {
            anm = data_ov000_021cc6cc;
        }
        func_ov000_02190cb0(self->model, anm, 0x800, 1);
        if (self->unk_b22_0 != 0) {
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
        LFLD(u16, ((u8 *)self->hp), 0xa) = 0x5a;
        func_ov000_0218996c(6, 10);
        o = GetObj021ac3ec(self->unk_b1c);
        if (o != NULL) {
            Msg021ac3ec m;
            m.pos = self->pos;
            m.pos.y += self->centerY;
            m.rot[0] = o->rot_x;
            m.rot[1] = o->rot_y;
            m.rot[2] = o->rot_z;
            m.z = 0;
            Actor_SendMsg(o, self->id, 7, 1, 0x18, &m);
            func_ov000_0218d46c(o, self->id, 10);
            if (o->targetObj != NULL) {
                o->targetObj->unk_18_0 = 0;
            }
        }
        Reset021ac3ec(self);
        self->target = 0xffff;
        self->unk_b24_21 = 0;
        if (self->unk_93_5 == 0) {
            self->unk_b36 = 0;
        } else if (self->unk_93_5 == 1) {
            self->unk_93_5 = 2;
        }
        {
            Actor *t = func_ov000_02199f60(((u8 *)self->hp));
            u16 ang;
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
            }
            self->unk_96 = ang;
        }
        self->speed = 0;
        self->moveYaw = self->unk_96 + 0x8000;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        u8 f = self->unk_93_5;
        if (f != 0) {
            self->speed = 0x371;
            self->velY = 0;
            self->friction = 0xccd;
            self->gravity = 0x52;
            if (f == 2) {
                self->unk_93_5 = 1;
            }
        } else {
            func_ov000_02199f88(((u8 *)self->hp), self);
        }
        func_ov000_02191418(self->model, 5, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        if (func_ov000_02191120(self->model)) {
            if (self->unk_93_5 != 0) {
                func_ov000_02198360(self->fsm, 0x1c, 0);
            } else {
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        if (!func_ov000_02191508(self->model)) {
            func_ov000_021b1fac(self, TRUE, 1);
            if (!self->unk_b24_1 && (self->hit->unk_50 & 0x400)) {
                func_ov000_02198360(self->fsm, 4, 0);
            }
        }
        break;
    }
    go = FALSE;
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
        go = TRUE;
    }
    if (go) {
        func_ov000_02198360(self->fsm, 4, 0);
    }
    self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
}
}
