#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_021ac844;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021ac844;

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *data_0214a424;
extern char data_ov000_021cc6cc[];
extern char data_ov000_021cc6d2[];
extern char data_ov000_021cc6d8[];
extern char data_ov000_021cc6de[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_02191008(void *a);
void func_ov000_02191418(void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *a);
void Actor_Move(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void SndMgr_StopSeqArc(void *mgr, s32 id);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218996c(u8 a, u8 b);
u8 *func_ov000_02199f60(void *p);
void func_ov000_02199f88(void *t, void *self);
u16 func_ov000_02198da8(void *body, u16 angle);
u8 func_0206d204(void *p, s32 a);
void func_ov000_021b1fac(void *self, s32 a, s32 b);

static inline Actor *FindActor_021ac844(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL GBusy_021ac844(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle_021ac844(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy_021ac844(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void Bump_021ac844(Robo021ca458 *self) {
    if (self->unk_b24_1 && (self->unk_48->unk_54 & 0x400)) {
        self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x, self->unk_af8 - self->pos.z);
        self->unk_9c = 0x66;
        self->unk_a4 = 0;
        if (!self->unk_b24_17 || (self->unk_48->unk_50 & 0x40000000)) {
            self->unk_a0 = 0x200;
        }
        self->unk_a8 = 0x52;
        self->unk_b24_17 = 1;
    }
}

void func_ov000_021ac844(Robo021ca458 *self) {
    BOOL upd = FALSE;
    Actor *a;
    Pose_021ac844 pose;

    switch (self->unk_40->st) {
    case 0: {
        u8 *o;
        u16 ang;
        char *anim = data_ov000_021cc6d2;
        if (self->unk_93_5) {
            anim = data_ov000_021cc6cc;
        }
        func_ov000_02190cb0(self->model, anim, 0x800, 1);
        if (self->unk_b22_0 != 0) {
            if (self->unk_998 != NULL) {
                func_ov000_02191008(self->unk_998);
            }
            if (self->unk_b64 >= 0) {
                SndMgr_StopSeqArc(data_02097e4c, self->unk_b64);
                self->unk_b64 = -1;
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
        if (!self->unk_b24_0) {
            LFLD(u16, ((u8 *)self->hp), 0xa) = 0x96;
        } else {
            func_02049a48(data_02097e4c, 0x30a, -1, -1, -1);
        }
        func_ov000_0218996c(8, 0xc);
        a = FindActor_021ac844(self->unk_b1c);
        if (a != NULL) {
            pose.pos.x = self->pos.x;
            pose.pos.y = self->pos.y;
            pose.pos.z = self->pos.z;
            pose.pos.y += self->unk_6c;
            pose.rx = a->rot_x;
            pose.ry = a->rot_y;
            pose.rz = a->rot_z;
            pose.unk = 0;
            Actor_SendMsg(a, self->id, 7, 1, 0x18, &pose);
            func_ov000_0218d46c(a, self->id, 0xa);
            if (((u8 *)a->unk_4c) != NULL) {
                LFLD(B8_021ac844, ((u8 *)a->unk_4c), 0x18).b0 = 0;
            }
        }
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->target = 0xffff;
        self->unk_b24_21 = 0;
        if (self->unk_93_5 == 0) {
            self->unk_b36 = 0;
        } else if (self->unk_93_5 == 1) {
            self->unk_93_5 = 2;
        }
        self->unk_b20 = 0xffff;
        self->unk_b24_12 = 0;
        self->rot_x = 0;
        o = func_ov000_02199f60(((u8 *)self->hp));
        if (o == NULL || o == (u8 *)self) {
            ang = self->rot_y;
        } else {
            ang = FX_Atan2(LFLD(s32, o, 0x70) - self->pos.x, LFLD(s32, o, 0x78) - self->pos.z);
        }
        self->unk_96 = ang;
        self->unk_98 = self->unk_96 + 0x8000;
        self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_92 = 0;
        self->unk_40->st++;
        if (self->msg_flags & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 1: {
        u32 m = self->unk_93_5;
        if (m != 0) {
            self->unk_9c = 0x600;
            self->unk_a4 = 0xcb8;
            self->unk_a8 = 0x52;
            self->unk_a0 = 0;
            if (m == 2) {
                self->unk_93_5 = 1;
            }
            self->unk_40->st = 0x14;
        } else {
            func_ov000_02199f88(((u8 *)self->hp), self);
            self->unk_40->st++;
        }
        if (self->pos.y - self->unk_b00 > 0x28cd) {
            self->unk_a0 = -0x60;
        }
        if (self->unk_b24_0) {
            self->unk_9c = 0;
        }
        func_ov000_02191418(self->model, 5, 0);
        if (self->msg_flags & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 2:
        if (self->unk_a0 > 0) {
            if (self->unk_48->unk_50 & 0x80000000) {
                self->unk_a0 = 0;
            }
        } else {
            u32 fl;
            if ((self->unk_48->unk_50 & 0x40000000) || ((s32)self->unk_48->unk_58) != 0) {
                self->unk_98 = func_ov000_02198da8(self->unk_48, self->unk_98);
                self->unk_9c = 0x114;
                if (self->unk_a0 < -0xcd) {
                    self->unk_a0 = -0xcd;
                }
            }
            fl = self->unk_48->unk_50;
            if (fl & 0x20000000) {
                if (fl & 0x400) {
                    self->unk_9c = 0;
                    self->unk_a0 = 0;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    func_ov000_02198360(self->unk_40, 4, 0);
                } else if (++self->unk_92 > 2 || ((self->unk_b68 & 2) && !self->unk_b24_0) ||
                           !GIdle_021ac844() || self->unk_15 == 3) {
                    func_ov000_02190cb0(self->model, data_ov000_021cc6d8, 0x800, 1);
                    self->unk_9c = 0;
                    self->unk_a0 = 0;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    self->unk_40->st = 10;
                    self->unk_40->timer = 0;
                } else {
                    BOOL stop;
                    s32 r;
                    func_ov000_02190cb0(self->model, data_ov000_021cc6de, 0x800, 1);
                    self->unk_a0 = -self->unk_a0 >> 1;
                    self->unk_9c = self->unk_9c - (self->unk_9c >> 2);
                    stop = FALSE;
                    r = func_0206d204(data_0214a424, 0);
                    if (LFLD(u16, ((u8 *)self->hp), 0) == 0 && r == 0) {
                        stop = TRUE;
                    }
                    if (stop) {
                        self->unk_9c = 0;
                    }
                }
            }
        }
        self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        if (!func_ov000_02191508(self->model)) {
            Actor_Move(self, 0);
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        Bump_021ac844(self);
        {
            ActorSub40 *s = self->unk_40;
            s->timer++;
            if (s->timer > 0x3c) {
                func_ov000_02198360(self->unk_40, 4, 0);
            }
        }
        break;
    case 10: {
        ActorSub40 *s = self->unk_40;
        if (self->unk_b24_0) {
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
            func_ov000_02198360(self->unk_40, 0x14, 0);
        } else {
            s->timer++;
            if (s->timer > 0x19 || (self->unk_b68 & 2)) {
                func_ov000_02190cb0(self->model, data_ov000_021cc6d8, 0x800, 0);
                self->unk_40->st++;
            }
        }
        LFLD(u16, self->unk_48, 0x9a) |= 0x20;
        if (self->msg_flags & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 11:
        if (func_ov000_02191120(self->model)) {
            if (self->unk_93_5) {
                func_ov000_02198360(self->unk_40, 0x1c, 0);
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        LFLD(u16, self->unk_48, 0x9a) |= 0x20;
        if (self->msg_flags & 0x80) {
            upd = TRUE;
        }
        break;
    case 0x14:
        if (func_ov000_02191120(self->model)) {
            if (self->unk_93_5) {
                func_ov000_02198360(self->unk_40, 0x1c, 0);
            } else {
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        if (!func_ov000_02191508(self->model)) {
            func_ov000_021b1fac(self, 1, 1);
        }
        Bump_021ac844(self);
        self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
        break;
    }
    if (upd) {
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
    }
}
}
