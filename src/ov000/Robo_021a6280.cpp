#include "ov000/LoCommon.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 b0 : 7;
    u8 b7 : 1;
} A93_021a6280;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
} S18_021a6280;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 rest : 12;
} Ba4_021a6280;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib_021a6280;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 x;
} Msg_021a6280;

typedef struct {
    u16 x, y, z;
} Rot_021a6280;

typedef struct {
    u8 c[3];
} Rgb_021a6280;

typedef struct {
    u8 pad_00[6];
    Rgb_021a6280 rgb;
} Def_021a6280;

#define BA4(self) LFLD(Ba4_021a6280, LFLD(u8 *, self, 0xba4), 6)

#define SQRTCNT_021a6280 (*(volatile u16 *)0x40002b0)
#define SQRT_RESULT_021a6280 (*(volatile u32 *)0x40002b4)
#define SQRT_PARAM_021a6280 (*(volatile u64 *)0x40002b8)

extern "C" {
extern char data_ov000_021cc68a[];
extern char data_ov000_021cc690[];
extern char data_ov000_021cc5e3[];
extern Def_021a6280 data_ov000_021c9fe8;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd68;
u8 *Actor_GetTarget(u8 *self);
Actor *ActorMgr_GetActor(void *mgr, u16 id);
u16 Actor_YawToPos(void *self, void *target);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_02049bdc(void *a, s32 b, s32 c);
VObj *func_02065f88(s32 id, void *pos);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *a);
void func_ov000_021911c8(void *a, s32 b);
void *func_ov000_02191318(void *a, s32 frame);
void func_ov000_02191418(void *a, s32 b, s32 c);
u16 Camera_GetYaw(void *cam);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
s32 Rand_UpTo(s32 max);
void func_ov000_0218996c(s32 a, s32 b);
void func_ov000_021899d8(VecFx32 *a, s32 b, s32 c, s32 d, s16 e, s16 f);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
void func_ov003_021cedf4(u16 add);
u8 func_ov003_021cee68(void);
void *func_02067120(void);

static inline u16 CamYaw_021a6280(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return Camera_GetYaw(cam);
}

static inline u8 *FindActor_021a6280(u16 id) {
    u8 *r;
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    r = (u8 *)ActorMgr_GetActor(data_ov000_021ccd68, id);
    return r;
}

static inline u16 AngleTo_021a6280(Robo021ca458 *self, u8 *other) {
    if (other == NULL || other == (u8 *)self) {
        return self->rot_y;
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - self->pos.x, LFLD(s32, other, 0x78) - self->pos.z);
}

static inline BOOL RgbEq_021a6280(Rgb_021a6280 *a, Rgb_021a6280 b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 FxMul_021a6280(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov000_021a6280(Robo021ca458 *self) {
    BOOL busy;
    u16 ang;
    u8 *a;
    ActorSub4c *sub;
    u8 *t;
    VecFx32 p;
    VecFx32 d;
    VecFx32 o;
    Msg_021a6280 m;
    VecFx32 v;

    a = FindActor_021a6280(self->unk_b1c);
    self->unk_b24_26 = 0;
    sub = NULL;
    busy = FALSE;
    if (a != NULL) {
        sub = (ActorSub4c *)LFLD(u8 *, a, 0x4c);
        if ((u16)(LFLD(u16, a, 0xc) & 0xf000) == 0x5000 && LFLD(u16 *, a, 0x50) != NULL) {
            if (*LFLD(u16 *, a, 0x50) == 0) {
                self->unk_b24_26 = 1;
            } else {
                busy = TRUE;
            }
        }
    }
    switch (self->fsm->st) {
    case 0:
        if (!self->unk_93_4) {
            self->unk_b24_22 = 0;
        }
        if (!busy) {
            self->unk_b24_22 = 0;
        }
        if (self->unk_b24_5 == 1) {
            func_ov000_02190cb0(self->model, data_ov000_021cc68a, 0x555, 0);
            self->unk_b24_7 = 0;
            if (self->unk_b22_3 && self->unk_93_4) {
                func_ov000_02191318(self->model, 0x14000);
                func_ov000_021911c8(self->model, 0x1800);
            } else if (self->unk_b24_22 != 0) {
                func_ov000_021911c8(self->model, 0x1800);
            }
        } else {
            self->unk_b2b = 0;
            self->unk_b2c_0 = 0;
            self->unk_b2c_1 = 0;
            self->unk_b2c_2 = 0;
            self->unk_b2c_3_f = 0;
            self->unk_b2c_7 = 0;
            if (self->unk_ba4 != NULL && self->unk_b24_22 != 0) {
                if (BA4(self).b0 && (self->padCur & 0xf0) && (self->hit->unk_50 & 0x20000000) &&
                    (!BA4(self).b2 || (self->padCur & 0x30))) {
                    self->unk_b2c_0 = true;
                    func_ov000_02198360(self->fsm, 0x11, 0);
                    goto end;
                }
                if (BA4(self).b2 && (self->padCur & 0xf0) && (self->hit->unk_50 & 0x20000000)) {
                    self->unk_b2c_2 = 1;
                    func_ov000_02198360(self->fsm, 0x11, 0);
                    goto end;
                }
                if (BA4(self).b1 && (self->padCur & 0xf0) && !(self->hit->unk_50 & 0x20000000)) {
                    self->unk_b2c_1 = 1;
                    func_ov000_02198360(self->fsm, 0x11, 0);
                    if (self->unk_b24_22 >= 2 && sub->unk_1a >= 3) {
                        self->unk_b2a_0 = true;
                    }
                    goto end;
                }
            }
            func_ov000_02190cb0(self->model, data_ov000_021cc690, 0x400, 0);
            if (self->unk_93_4) {
                if (self->unk_b24_22 != 0) {
                    func_ov000_021911c8(self->model, 0x3000);
                } else {
                    func_ov000_021911c8(self->model, 0x1800);
                }
            }
        }
        if (self->unk_b24_22 != 0) {
            s32 se;
            s32 lvl = 0;
            VObj *e;
            func_ov000_02191418(self->model, 0x14, lvl);
            se = 0x194;
            if (self->unk_b24_22 >= 2 && sub != NULL) {
                if (sub->unk_1a == 2) {
                    se += 1;
                    lvl = 2;
                } else if (sub->unk_1a >= 3) {
                    lvl = sub->unk_1a;
                    se += 2;
                    self->unk_b2a_0 = true;
                }
            }
            func_02049bdc(data_02097e4c, 0x44, lvl);
            e = func_02065f88(se, &self->pos);
            LFLD(s32, e, 0x3c) = 0x1400;
            e->vfunc_24(0, self->centerY, 0);
            {
                u32 sc = 0xe66;
                if (self->unk_b24_22 < 2) {
                    sc >>= 1;
                }
                e->vfunc_0c(sc);
            }
            if (!self->unk_b22_3 && data_0214a424->bits18.mode == 1) {
                u16 n = 0xc;
                if (sub != NULL) {
                    n += (u16)(sub->unk_1a << 1);
                }
                if (self->unk_ba4 != NULL) {
                    n += LFLD(Nib_021a6280, self->unk_ba4, 5).hi;
                }
                func_ov003_021cedf4(n);
            }
        } else if (self->unk_b24_26) {
            func_ov000_02191418(self->model, 0x32, 0);
            func_02049a48(data_02097e4c, 0x30c, -1, -1, -1);
            func_02067120();
        }
        if (self->unk_b24_12 == 0) {
            if (self->speed > 0x229) {
                self->speed = 0x229;
            }
            if (self->velY < 0x5c) {
                self->velY = 0x5c;
            }
            self->velY -= self->velY >> 1;
            self->gravity = 10;
            self->friction = 0xe66;
        }
        self->fsm->st++;
        break;
    case 1:
        t = Actor_GetTarget((u8 *)self);
        if (t != NULL) {
            if (LFLD(void *, t, 0x44) != NULL) {
                ang = Actor_YawToPos(self, LFLD(void *, t, 0x44));
            } else {
                ang = AngleTo_021a6280(self, t);
            }
        } else if (self->unk_b24_12 == 0) {
            ang = self->rot_y;
            if (self->mode == 1 && (self->padCur & 0xf0)) {
                ang = self->padDir + CamYaw_021a6280((u8 *)data_ov000_021ccd54 + 0xf4);
            }
        } else {
            ang = self->rot_y;
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x59a, 1, 0x8000);
        self->unk_b2c_3_f = 0;
        if (self->unk_b24_22 != 0 && self->unk_ba4 != NULL && BA4(self).b3 && (self->padTrig & 1) &&
            self->unk_b2c_7 < 5 && sub != NULL) {
            VObj *e;
            p.x = sub->dest.x;
            p.y = sub->dest.y;
            p.z = sub->dest.z;
            e = func_02065f88(0x69, &p);
            self->unk_b48 = LFLD(s32, e, 0x24);
            self->unk_b5e = 0x7b;
            self->unk_b4c = p.x - self->pos.x;
            self->unk_b50 = p.y - self->pos.y;
            self->unk_b54 = p.z - self->pos.z;
            self->unk_b58 = 0;
            self->unk_b5a = 0;
            self->unk_b5c = 0;
            e->vfunc_0c(0x800);
            LFLD(s32, e, 0x3c) = 0x2800;
            func_ov000_0218996c(5, 6);
            func_02049a48(data_02097e4c, 0x7a, -1, -1, -1);
            self->unk_b2c_3_f = 1;
            self->unk_b2c_7++;
        }
        if (self->model->anim_state == 1) {
            if (self->unk_b24_5 != 0 && a != NULL) {
                u8 *s2;
                func_ov000_0218d46c(a, self->id, 0xb);
                if (a != NULL) {
                    if (LFLD(VecFx32 *, a, 0x48) != NULL) {
                        v = *LFLD(VecFx32 *, a, 0x48);
                    } else {
                        v = LFLD(VecFx32, a, 0x70);
                    }
                    if (func_01ffbd6c((VecFx32 *)((u8 *)self + 0x70), &v, -1, 0, 0, -1) != -0x1000) {
                        v.x -= self->pos.x;
                        v.y -= self->pos.y;
                        v.z -= self->pos.z;
                        VEC_MultAdd(0xc00, &v, (VecFx32 *)((u8 *)self + 0x70), &v);
                        m.pos = v;
                        *(Rot_021a6280 *)m.rot = LFLD(Rot_021a6280, a, 0x7c);
                        m.x = 0;
                        Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &m);
                    }
                }
                LFLD(u16, a, 0x7e) = ang;
                self->rot_y = ang;
                if (LFLD(A93_021a6280, a, 0x93).b7) {
                    LFLD(u16, a, 0x90) = self->target;
                }
                s2 = LFLD(u8 *, a, 0x4c);
                if (s2 != NULL) {
                    s32 x = 0;
                    s32 y = 0;
                    s32 z = 0;
                    s32 se;
                    if (t != NULL) {
                        VecFx32 tp;
                        s64 sq;
                        s32 dx;
                        s32 dz;
                        s32 h;
                        if (LFLD(VecFx32 *, t, 0x44) != NULL) {
                            tp = *LFLD(VecFx32 *, t, 0x44);
                        } else {
                            tp.x = LFLD(s32, t, 0x70);
                            tp.y = LFLD(s32, t, 0x74) + LFLD(s32, t, 0x6c);
                            tp.z = LFLD(s32, t, 0x78);
                        }
                        dx = self->pos.x - tp.x;
                        dz = self->pos.z - tp.z;
                        sq = (s64)dx * dx;
                        sq += (s64)dz * dz;
                        SQRTCNT_021a6280 = 1;
                        SQRT_PARAM_021a6280 = (u64)(sq * 4);
                        while (SQRTCNT_021a6280 & 0x8000) {
                        }
                        x = (s32)(SQRT_RESULT_021a6280 + 1) >> 1;
                        h = self->pos.y + self->height;
                        if (self->unk_b22_3) {
                            h += 0x333;
                        }
                        y = tp.y - h;
                    } else if (!(self->hit->unk_50 & 0x20000000) &&
                               self->pos.y - self->hit->check.y >= 0x159a) {
                        x = 0x2000;
                        y = -0x2000;
                    } else if (self->unk_b24_22 != 0 || self->unk_b24_26) {
                        x = 0x1800;
                        y = -0xc00;
                    }
                    if (self->unk_b24_12 != 0) {
                        z = self->speed;
                        LFLD(S18_021a6280, s2, 0x18).b2 = 1;
                    }
                    LFLD(s32, s2, 0x50) = x;
                    LFLD(s32, s2, 0x54) = y;
                    LFLD(s32, s2, 0x58) = z;
                    LFLD(S18_021a6280, s2, 0x18).b0 = 0;
                    if (self->unk_b24_22 != 0) {
                        u8 lv = 0;
                        u8 n;
                        if (self->unk_ba4 != NULL && BA4(self).b3) {
                            lv = self->unk_b2c_7 << 1;
                        }
                        LFLD(u8, s2, 0x19) = self->unk_b24_22;
                        LFLD(u8, s2, 0x1b) = lv;
                        n = func_ov003_021cee68();
                        if (self->unk_b24_22 < 2) {
                            n--;
                        }
                        se = LFLD(u8, s2, 0x1a) >= n ? 0x307 : 0x306;
                    } else {
                        se = self->unk_b24_26 ? 0x30d : 0x305;
                    }
                    if (se >= 0) {
                        func_02049a48(data_02097e4c, se, -1, -1, -1);
                    }
                    if (self->unk_b24_22 != 0 || self->unk_b24_26) {
                        if (RgbEq_021a6280((Rgb_021a6280 *)((u8 *)data_ov000_021ccd54 + 0xca), data_ov000_021c9fe8.rgb)) {
                            func_02049bdc(data_02097e4c, 0x5e, Rand_UpTo(3));
                        }
                    }
                }
            }
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
            self->target = 0xffff;
            if (self->unk_93_4) {
                func_ov000_021911c8(self->model, 0x1400);
            }
            self->gravity = 0x29;
            self->unk_b2c_3_f = 0;
            self->fsm->st++;
        }
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0x200, 0);
            self->fsm->st++;
            self->fsm->timer = 0;
            self->friction = 0x800;
        }
        break;
    case 3: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 6) {
            self->gravity = 0x52;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
end:
    if (!func_ov000_02191508(self->model)) {
        func_ov000_021b1fac(self, FALSE, 0);
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
        }
    }
    if (self->unk_b24_22 >= 2 || self->unk_b24_26) {
        if (a != NULL) {
            d = LFLD(VecFx32, a, 0x70);
            d.x -= self->pos.x;
            d.y -= self->pos.y;
            d.z -= self->pos.z;
            d.x = FxMul_021a6280(d.x, 0x733);
            d.y = FxMul_021a6280(d.y, 0x733);
            d.z = FxMul_021a6280(d.z, 0x733);
            d.y = self->height;
            VEC_Add(&d, (VecFx32 *)((u8 *)self + 0x70), &o);
            func_ov000_021899d8(&o, 0, 0x8ccd, 1, 0x2333, 0x1000);
        }
    }
}

}
