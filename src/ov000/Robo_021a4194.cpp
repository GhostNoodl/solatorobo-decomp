#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 b3 : 1;
    u8 rest : 4;
} B8_021a4194;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} W_021a4194;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a4194;

extern "C" {
extern void *data_ov000_021ccd68;
extern char *data_ov000_021ca050[];
extern char *data_ov000_021ca040[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc654[];
extern char data_ov000_021cc65a[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc61e[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_01ffc584(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_02191780(void *a);
BOOL func_ov000_02191120(void *a);
void Actor_Move(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void Target_Set(void *a, void *b);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
void func_ov000_021bd300(void *p);
void func_ov000_021bd438(void *p, VecFx32 *v, s32 dy);

static inline Actor *FindActor_021a4194(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov000_021a4194(Robo021ca458 *self) {
    u8 *t;
    u8 *info;
    ActorSub40 *sub;
    BOOL hit;
    VecFx32 pos;
    VecFx32 o;
    VecFx32 p;
    Pose_021a4194 pose;

    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    t = (u8 *)FindActor_021a4194(self->target);
    info = NULL;
    if (t != NULL) {
        info = LFLD(u8 *, t, 0x4c);
    }
    if (info == NULL && self->unk_40->st < 0x14) {
        func_ov000_02198360(self->unk_40, 1, 0);
        return;
    }
    sub = self->unk_40;
    switch (sub->st) {
    case 0:
        if (LFLD(u8, info, 0) != 0x12) {
            u16 ang;
            if (t == NULL || t == (u8 *)self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(LFLD(s32, t, 0x70) - self->pos.x, LFLD(s32, t, 0x78) - self->pos.z);
            }
            self->unk_98 = ang;
            self->rot_y = func_01ffc128(self->unk_98, self->rot_y, 0x400, 1, 0x8000);
            {
                ActorSub40 *s;
                pos.x = self->pos.x;
                pos.y = self->pos.y;
                pos.z = self->pos.z;
                pos.y -= 0x1000;
                s = self->unk_40;
                s->timer++;
                if (s->timer < 0x23 &&
                    !func_01ffc584(t + 0x70, &pos, LFLD(s32, t, 0x64) * 2 + 0x1000, 0x3800)) {
                    hit = FALSE;
                    func_ov000_02190cb0(self->unk_38, data_ov000_021ca050[self->unk_b24_5], 0x400, 0);
                    func_ov000_021915a0(self->unk_38);
                    self->unk_9c = 0x15c;
                    Actor_Move(self, 0);
                    func_ov000_021987b8(self->unk_48, 0, 0, 0);
                    if (self->unk_b24_1 && (self->unk_48->unk_54 & 0x400)) {
                        self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x, self->unk_af8 - self->pos.z);
                        self->unk_9c = 0x66;
                        self->unk_a4 = 0;
                        if (!self->unk_b24_17 || (self->unk_48->unk_50 & 0x40000000)) {
                            self->unk_a0 = 0x200;
                        }
                        self->unk_a8 = 0x52;
                        self->unk_b24_17 = 1;
                        hit = TRUE;
                    }
                    if (!hit) {
                        return;
                    }
                    func_ov000_02198360(self->unk_40, 4, 0);
                    {
                        Actor *a = FindActor_021a4194(self->unk_b1c);
                        if (a != NULL) {
                            pose.pos = self->pos;
                            pose.pos.y += self->unk_6c;
                            pose.rx = a->rot_x;
                            pose.ry = a->rot_y;
                            pose.rz = a->rot_z;
                            pose.unk = 0;
                            Actor_SendMsg(a, self->id, 7, 1, 0x18, &pose);
                            func_ov000_0218d46c(a, self->id, 0xa);
                            if (((u8 *)a->unk_4c) != NULL) {
                                LFLD(B8_021a4194, ((u8 *)a->unk_4c), 0x18).b0 = 0;
                            }
                        }
                    }
                    self->unk_b1c = 0xffff;
                    self->unk_b1e = 0xffff;
                    self->unk_b24_5 = 0;
                    self->unk_b24_7 = self->unk_b24_9;
                    return;
                }
            }
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
        }
        self->unk_40->st++;
    case 1: {
        char *anim;
        if (self->unk_b1c != 0xffff) {
            if (self->unk_b22_3) {
                func_ov000_02190cb0(self->unk_38, data_ov000_021cc64e, 0x555, 0);
                func_ov000_02191318(self->unk_38, 0xa000);
                func_ov000_02191780(self->unk_38);
                self->unk_40->st++;
                return;
            }
            if (self->unk_b24_5 == 2) {
                anim = data_ov000_021cc654;
            } else {
                anim = data_ov000_021cc65a;
            }
        } else {
            if (LFLD(u8, info, 0) == 0x12) {
                self->unk_40->st = 10;
                return;
            }
            if (!self->unk_b22_3) {
                if (LFLD(u8, info, 0) == 0xd) {
                    anim = data_ov000_021cc654;
                } else {
                    anim = self->unk_b24_1 ? data_ov000_021cc65a : data_ov000_021cc660;
                }
            } else {
                anim = data_ov000_021cc64e;
            }
        }
        func_ov000_02190cb0(self->unk_38, anim, 0x400, 0);
        self->unk_40->st++;
        return;
    }
    case 2: {
        s16 f = LFLD(s16, self->unk_38, 0xc4);
        Actor *a;
        if (f == 1 || self->unk_b22_3) {
            sub->st = 10;
            return;
        }
        if (f <= 1) {
            return;
        }
        a = FindActor_021a4194(self->unk_b1c);
        if (a != NULL) {
            if (a->unk_4c->unk_02 == 7) {
                if (a->unk_38 != NULL) {
                    func_ov000_02190cb0(a->unk_38, data_ov000_021cc660, 0x1000, 0);
                }
                self->unk_40->timer = LFLD(s16, self->unk_38, 0xc4);
                self->unk_40->st++;
                return;
            }
        } else if (info != NULL && LFLD(u8, info, 2) == 7) {
            self->unk_40->timer = LFLD(s16, self->unk_38, 0xc4);
            self->unk_40->st++;
            return;
        }
        self->unk_40->st = 10;
        return;
    }
    case 3:
        if (sub->timer != 0) {
            sub->timer--;
        }
        if (sub->timer == 0) {
            self->unk_40->st = 10;
        }
        return;
    case 10:
        if (self->unk_b1c != 0xffff) {
            Actor *a = FindActor_021a4194(self->unk_b1c);
            if (a != NULL) {
                a->target = LFLD(u16, t, 0xc);
                func_ov000_0218d46c(a, self->id, 6);
            }
        } else {
            func_ov000_0218d46c(t, self->id, 6);
            LFLD(u16, t, 0x90) = 0xffff;
            Target_Set(info, self);
            if (LFLD(u8, info, 2) == 6) {
                self->unk_b29_0 = 1;
            }
        }
        self->unk_40->st++;
        return;
    case 11:
        if (func_ov000_02191120(self->unk_38)) {
            if (LFLD(u8, info, 2) == 6) {
                if (LFLD(s16, t, 0x18) != 3) {
                    if (!self->unk_b24_1) {
                        self->unk_93_0 = 1;
                    } else {
                        func_ov000_02190cb0(self->unk_38, data_ov000_021cc61e, 0x400, 0);
                        func_ov000_021915a0(self->unk_38);
                    }
                    {
                        p.x = LFLD(s32, t, 0x70);
                        p.y = LFLD(s32, t, 0x74);
                        p.z = LFLD(s32, t, 0x78);
                        o.x = 0;
                        o.y = 0;
                        o.z = -0x800;
                        func_ov000_0219a210(&p, &o, LFLD(u16, t, 0x7e));
                        self->unk_98 = FX_Atan2(p.x - self->pos.x, p.z - self->pos.z);
                    }
                    self->unk_9c = 0x15c;
                    self->unk_a4 = 0;
                    self->unk_a8 = 0;
                    self->unk_40->st = 0x14;
                } else {
                    func_ov000_02198360(self->unk_40, 1, 0);
                }
            } else {
                func_ov000_02190cb0(self->unk_38, data_ov000_021ca040[self->unk_b24_5], 0xcd, 0);
                func_ov000_021915a0(self->unk_38);
                self->unk_40->st = 0x32;
            }
            self->target = 0xffff;
            LFLD(W_021a4194, self->unk_5c, 0).b1 = 0;
            func_ov000_021bd300(self->unk_5c);
            func_ov000_021bd438(self->unk_5c, (VecFx32 *)((u8 *)self + 0x70), 0);
        }
        self->rot_y = func_01ffc128(self->unk_98, self->rot_y, 0x400, 1, 0x8000);
        if (LFLD(u8, info, 2) == 6) {
            self->unk_b29_0 = 1;
            self->unk_b29_3 = 1;
        }
        return;
    case 0x14:
        self->rot_y = func_01ffc128(self->unk_98, self->rot_y, 0x400, 1, 0x8000);
        Actor_Move(self, 0);
        self->unk_b29_0 = 1;
        self->unk_b29_3 = 1;
        return;
    case 0x32:
        if (self->unk_48->unk_50 & 0x20000000) {
            self->unk_a0 = 0;
            return;
        }
        self->unk_a8 = 0x52;
        Actor_Move(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        break;
    }
}
}
