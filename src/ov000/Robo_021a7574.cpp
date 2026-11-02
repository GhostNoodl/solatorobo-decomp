#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a783c;

typedef struct {
    u8 pad_00[0x40];
    u16 unk_40;
    u16 pad_42;
    u16 yaw;
} Cam021a783c;

extern "C" {

extern u8 data_ov000_021cc696[];
extern u8 data_ov000_021cc672[];
extern u8 data_ov000_021ca0a4[];
extern u8 data_ov000_021cc5e3[];
VObj *func_02065f88(s32 id, void *pos);
extern u8 data_ov000_021cc618[];
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02198360(State021a783c *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021b03c8(void *self);
u8 *Actor_GetTarget(void *self);
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
u16 Camera_GetYaw(Cam021a783c *cam);
u16 FX_Atan2(s32 y, s32 x);

static inline u16 CamYaw(Cam021a783c *cam) {
    if (cam->unk_40 != 0) {
        return cam->yaw;
    }
    return Camera_GetYaw(cam);
}

static inline Actor *FindActor021a783c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline u16 AngleTo(Robo021ca458 *self, u8 *other) {
    u16 angle;
    if (other == NULL || other == (u8 *)self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(LFLD(s32, other, 0x70) - self->pos.x, LFLD(s32, other, 0x78) - self->pos.z);
    }
    return angle;
}

static inline s32 FxMul64(s64 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

extern u8 data_ov000_021cc64e[];
extern u8 data_ov000_021cc68a[];
extern u8 data_ov000_021cc690[];
extern u8 data_ov000_021ca090[];
extern void *data_02097e4c;
void *func_ov000_02191318(void *a, s32 frame);
void func_ov000_02191780(void *a);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 func_01ffbd6c(void *a, void *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const void *v1, const void *v2, void *out);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

typedef struct {
    s32 x, y, z;
} Vec021a70b0;

typedef struct {
    u16 x, y, z;
} Rot021a70b0;

typedef struct {
    Vec021a70b0 pos;
    Rot021a70b0 rot;
    u8 pad[2];
    s32 unk_14;
} Msg021a70b0;

void func_ov000_021a70b0(Robo021ca458 *self) {
    switch (((State021a783c *)self->unk_40)->state) {
    case 0:
        if (self->unk_b22_3) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc64e, 0x555, 0);
            func_ov000_02191318(self->unk_38, 0xa000);
            func_ov000_02191780(self->unk_38);
        } else if (self->unk_b24_5 == 1) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc68a, 0x555, 0);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc690, 0x333, 0);
            {
                u8 *m = (u8 *)self->unk_38;
                LFLD(void *, m, 0xd8) = data_ov000_021ca090;
                LFLD(void *, m, 0xdc) = data_ov000_021ca090;
            }
        }
        if (self->unk_a0 > 0) {
            self->unk_a0 = 0;
        }
        self->unk_a4 = 0x99a;
        self->unk_a8 = 10;
        ((State021a783c *)self->unk_40)->state++;
        break;
    case 1: {
        u16 ang;
        u8 *t = Actor_GetTarget(self);
        if (t != NULL) {
            ang = AngleTo(self, t);
        } else {
            ang = self->rot_y;
            if (self->unk_15 == 1 && (self->unk_b68 & 0xf0)) {
                ang = CamYaw((Cam021a783c *)(data_ov000_021ccd54 + 0xf4)) + self->unk_b6e;
            }
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x59a, 1, 0x8000);
        if (self->unk_b24_5 != 0 &&
            (LFLD(s16, self->unk_38, 0xc4) == 1 || self->unk_b22_3)) {
            Actor *a;
            func_02049a48(data_02097e4c, 0x301, -1, -1, -1);
            a = FindActor021a783c(self->unk_b1c);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0xb);
                if (a != NULL) {
                    Msg021a70b0 m;
                    Vec021a70b0 v;
                    if (((Vec021a70b0 *)a->unk_48) != NULL) {
                        v = *((Vec021a70b0 *)a->unk_48);
                    } else {
                        v = LFLD(Vec021a70b0, a, 0x70);
                    }
                    if (func_01ffbd6c(&self->pos, &v, -1, 0, 0, -1) != -0x1000) {
                        v.x -= self->pos.x;
                        v.y -= self->pos.y;
                        v.z -= self->pos.z;
                        VEC_MultAdd(0xc00, &v, &self->pos, &v);
                        m.pos = v;
                        m.rot = LFLD(Rot021a70b0, a, 0x7c);
                        m.unk_14 = 0;
                        Actor_SendMsg(a, self->id, 7, TRUE, sizeof(Msg021a70b0), &m);
                    }
                }
            }
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
            ((State021a783c *)self->unk_40)->state++;
        }
    }
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc5e3, 0x200, 0);
            ((State021a783c *)self->unk_40)->state++;
            ((State021a783c *)self->unk_40)->timer = 0;
            self->unk_a4 = 0x800;
        }
        break;
    case 3: {
        State021a783c *st = ((State021a783c *)self->unk_40);
        st->timer++;
        if (st->timer > 15) {
            self->unk_a8 = 0x52;
            func_ov000_02198360(((State021a783c *)self->unk_40), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 0);
    if (!LBIT(self, 0xb24).b1) {
        return;
    }
    if (!(self->unk_48->unk_54 & 0x400)) {
        return;
    }
    self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                     self->unk_af8 - self->pos.z);
    self->unk_9c = 0x66;
    self->unk_a4 = 0;
    if (!LBIT(self, 0xb24).b17 || (self->unk_48->unk_50 & 0x40000000)) {
        self->unk_a0 = 0x200;
    }
    self->unk_a8 = 0x52;
    LBIT(self, 0xb24).b17 = 1;
}

void func_ov000_021a7574(Robo021ca458 *self) {
    switch (LFLD(State021a783c *, self, 0x40)->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc672, 0x800, 0);
        if (self->unk_b24_5 != 2) {
            u8 *m = (u8 *)self->unk_38;
            LFLD(void *, m, 0xd8) = data_ov000_021ca0a4;
            LFLD(void *, m, 0xdc) = data_ov000_021ca0a4;
        }
        if (self->unk_a0 > 0) {
            self->unk_a0 = 0;
        }
        self->unk_a4 = 0xccd;
        self->unk_a8 = 10;
        self->unk_b24_7 = 2;
        ((State021a783c *)self->unk_40)->state++;
        break;
    case 1:
        if (LFLD(s16, self->unk_38, 0xc4) == 1 || func_ov000_02191120(self->unk_38)) {
            if (self->unk_b24_5 != 0) {
                VObj *e;
                u8 *a = (u8 *)FindActor021a783c(self->unk_b1c);
                if (a != NULL) {
                    func_ov000_0218d46c(a, self->id, 0xd);
                }
                self->unk_b24_5 = 0;
                self->unk_b1c = 0xffff;
                self->unk_b1e = 0xffff;
                self->unk_b24_7 = self->unk_b24_9;
                e = func_02065f88(0xc9, &self->pos);
                LFLD(void *, self, 0xb48) = LFLD(void *, e, 0x24);
                self->unk_b5e = 0;
                self->unk_b4c = 0;
                self->unk_b50 = FxMul64(self->unk_68, 0xa66);
                self->unk_b54 = 0;
                self->unk_b58 = 0xe000;
                self->unk_b5a = 0;
                self->unk_b5c = 0;
                e->vfunc_14(0x2800, 0x2000, 0x2800);
            }
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc5e3, 0x155, 0);
            self->unk_a8 = 0x52;
            ((State021a783c *)self->unk_40)->state++;
        }
        break;
    case 2: {
        State021a783c *st = LFLD(State021a783c *, self, 0x40);
        s32 lim = 0x10;
        if (self->unk_93_4) {
            lim = 8;
        }
        st->timer++;
        if (st->timer > lim) {
            func_ov000_02198360(((State021a783c *)self->unk_40), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!LBIT(self, 0xb24).b1) {
        return;
    }
    if (!(self->unk_48->unk_54 & 0x400)) {
        return;
    }
    self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                     self->unk_af8 - self->pos.z);
    self->unk_9c = 0x66;
    self->unk_a4 = 0;
    if (!LBIT(self, 0xb24).b17 || (self->unk_48->unk_50 & 0x40000000)) {
        self->unk_a0 = 0x200;
    }
    self->unk_a8 = 0x52;
    LBIT(self, 0xb24).b17 = 1;
}

void func_ov000_021a783c(Robo021ca458 *self) {
    if (self->unk_b24_12 == 3) {
        func_ov000_021b03c8(self);
        return;
    }
    switch (((State021a783c *)self->unk_40)->state) {
    case 0:
        if (self->unk_a0 > 0) {
            self->unk_a0 = 0;
        }
        self->unk_a4 = 0xe66;
        self->unk_a8 = 10;
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc696, 0x800, 0);
        ((State021a783c *)self->unk_40)->state++;
        break;
    case 1: {
        u16 ang;
        u8 *t = Actor_GetTarget(self);
        if (t != NULL) {
            ang = AngleTo(self, t);
        } else {
            ang = self->rot_y;
            if (self->unk_15 == 1 && (self->unk_b68 & 0xf0)) {
                ang = CamYaw((Cam021a783c *)(data_ov000_021ccd54 + 0xf4)) + self->unk_b6e;
            }
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x8cd, 1, 0x8000);
        if (self->unk_b24_5 != 0 && LFLD(s16, self->unk_38, 0xc4) == 1) {
            u8 *a = (u8 *)FindActor021a783c(self->unk_b1c);
            if (a != NULL) {
                func_ov000_0218d46c(a, self->id, 0xe);
            }
            ((State021a783c *)self->unk_40)->state++;
        }
        break;
    }
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_a8 = 0x52;
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc618, 0x19a, 0);
            ((State021a783c *)self->unk_40)->state++;
            ((State021a783c *)self->unk_40)->timer = 0;
        }
        break;
    case 3: {
        State021a783c *st = ((State021a783c *)self->unk_40);
        st->timer++;
        if (st->timer > 20) {
            func_ov000_02198360(((State021a783c *)self->unk_40), 1, 0);
        }
        break;
    }
    }
    func_ov000_021b1fac(self, FALSE, 1);
    if (!LBIT(self, 0xb24).b1) {
        return;
    }
    if (!(self->unk_48->unk_54 & 0x400)) {
        return;
    }
    self->unk_98 = FX_Atan2(self->unk_af0 - self->pos.x,
                                     self->unk_af8 - self->pos.z);
    self->unk_9c = 0x66;
    self->unk_a4 = 0;
    if (!LBIT(self, 0xb24).b17 || (self->unk_48->unk_50 & 0x40000000)) {
        self->unk_a0 = 0x200;
    }
    self->unk_a8 = 0x52;
    LBIT(self, 0xb24).b17 = 1;
}

}
