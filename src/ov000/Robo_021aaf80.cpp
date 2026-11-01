#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State021aaf80;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 4;
    u16 lvl : 3;
    u16 rest : 6;
} B2c021aaf80;

typedef struct {
    u32 b0 : 5;
    u32 f5 : 2;
    u32 f7 : 2;
    u32 f9 : 1;
    u32 b10 : 2;
    u32 mode : 2;
    u32 b14 : 5;
    u32 b19 : 1;
    u32 b20 : 2;
    u32 f22 : 2;
    u32 rest : 8;
} B24_021aaf80;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B18_021aaf80;

typedef struct {
    u16 val;
    u8 d;
    u16 id;
} Hit021aaf80;

typedef struct {
    u16 x, y, z;
} Rot021aaf80;

typedef struct {
    VecFx32 pos;
    Rot021aaf80 rot;
    u8 pad[2];
    s32 unk_14;
} Msg021aaf80;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6b4[];
void *func_ov000_0218e640(ActorMgr *mgr, u16 id);
BOOL func_ov000_02191508(void *a);
void *func_ov000_02191318(void *a, s32 b);
void func_ov000_0218999c(u8 a, u8 b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, VecFx32 *pos);
u16 FX_Atan2(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s16 i, s32 j);
void func_ov000_0218d46c(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
BOOL func_ov000_02191120(void *a);
void func_ov000_02191418(void *a, u16 b, s32 c);
void func_ov000_021b1fac(void *self, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, u16 b);
u16 func_0204bfa8(void *cam);

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021aaf80;

static inline Actor *FindActor021aaf80(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (Actor *)func_ov000_0218e640(mgr, id);
}

static inline u16 AngleTo021aaf80(Actor *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

struct Charge021aaf80Self {
    u8 unk_00[0xb2b];
    u8 unk_b2b;
    u8 unk_b2c[0x3e];
    u16 unk_b6a;
};

static inline void Charge021aaf80(Charge021aaf80Self *self) {
    if (self->unk_b6a & 1) {
        self->unk_b2b++;
    }
    if (self->unk_b6a & 0xf0) {
        self->unk_b2b += 2;
    }
    if (self->unk_b2b > 4) {
        self->unk_b2b = 4;
    }
}

static inline u16 CamYaw021aaf80(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

struct Obj021aaf80 {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x7];
    u8 unk_15;
    u8 unk_16[0x22];
    void *unk_38;
    u8 unk_3c[0x4];
    State021aaf80 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 unk_4c[0x20];
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0x2];
    u16 unk_7e;
    u8 unk_80[0x1c];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0xa54];
    s32 unk_b00;
    u8 unk_b04[0x18];
    u16 unk_b1c;
    u16 unk_b1e;
    u8 unk_b20[0x2];
    B22_021aaf80 unk_b22;
    B24_021aaf80 unk_b24;
    u8 unk_b28[0x4];
    B2c021aaf80 unk_b2c;
    u8 unk_b2e[0x12];
    s32 unk_b40;
    u8 unk_b44[0x24];
    u16 unk_b68;
    u8 unk_b6a[0x4];
    u16 unk_b6e;
};

static inline void Release021aaf80(Obj021aaf80 *self, s32 next) {
    Actor *a = FindActor021aaf80(self->unk_b1c);
    if (a != NULL) {
        Msg021aaf80 m;
        m.pos.x = self->unk_70;
        m.pos.y = self->unk_74;
        m.pos.z = self->unk_78;
        m.pos.y += self->unk_6c;
        m.rot = *(Rot021aaf80 *)&a->rot_x;
        m.unk_14 = 0;
        func_ov000_0218d398(a, self->unk_0c, 7, 1, sizeof(Msg021aaf80), &m);
        func_ov000_0218d46c(a, self->unk_0c, 0xa);
        if (a->unk_4c != NULL) {
            LFLD(B18_021aaf80, a->unk_4c, 0x18).b0 = 0;
        }
    }
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24.f5 = 0;
    self->unk_b24.f7 = self->unk_b24.f9;
    self->unk_b2c.b1 = 0;
    func_ov000_02198360(self->unk_40, next, 0);
}


void func_ov000_021aaf80(Obj021aaf80 *self) {
    Actor *a = FindActor021aaf80(self->unk_b1c);
    u8 *sub = NULL;
    if (a != NULL) {
        sub = (u8 *)a->unk_4c;
    }
    switch (self->unk_40->st) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc6b4, 0x555, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->st++;
        break;
    case 1: {
        VObj *o;
        if (LFLD(s16, self->unk_38, 0xc4) != 1) {
            break;
        }
        o = func_02065f88(0x192, (VecFx32 *)((u8 *)self + 0x70));
        self->unk_b40 = LFLD(s32, o, 0x24);
        o->vfunc_34(0x4000, 0, 0);
        self->unk_40->st++;
    }
    case 2:
        if (a == NULL || sub == NULL) {
            self->unk_40->st++;
            break;
        }
        if (LFLD(u32, self->unk_48, 0x50) & 0x20000000) {
            VecFx32 p;
            VObj *o;
            s32 sc;
            u8 v;
            p = a->pos;
            p.y = self->unk_74;
            func_ov000_0218999c(0xe, 0x19);
            func_02049f44(data_02097e4c, 0x1b, (u8 *)self + 0x70, 0);
            func_02049f44(data_02097e4c, 0x53, (u8 *)self + 0x70, 0);
            sc = a->unk_64;
            if (sc < 0xccd) {
                sc = 0xccd;
            }
            o = func_02065f88(0x66, &p);
            o->vfunc_14(sc + 0xccd, 0x1400, sc + 0xccd);
            LFLD(s32, o, 0x3c) = 0xe66;
            func_ov000_0218d46c(a, self->unk_0c, 0xb);
            LFLD(B18_021aaf80, sub, 0x18).b0 = 0;
            LFLD(s32, sub, 0x50) = 0x19a;
            LFLD(s32, sub, 0x54) = -0x1000;
            LFLD(s32, sub, 0x58) = 0;
            v = LFLD(u8, sub, 0x1a) * 5;
            LFLD(u8, sub, 0x19) = self->unk_b24.f22;
            LFLD(u8, sub, 0x1b) = v;
            if (a != NULL) {
                Msg021aaf80 m;
                VecFx32 t;
                VecFx32 *q = LFLD(VecFx32 *, a, 0x48);
                if (q != NULL) {
                    t.x = q->x;
                    t.y = q->y;
                    t.z = q->z;
                } else {
                    t.x = a->pos.x;
                    t.y = a->pos.y;
                    t.z = a->pos.z;
                }
                if (func_01ffbd6c((VecFx32 *)((u8 *)self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                    t.x -= self->unk_70;
                    t.y -= self->unk_74;
                    t.z -= self->unk_78;
                    VEC_MultAdd(0xc00, &t, (VecFx32 *)((u8 *)self + 0x70), &t);
                    m.pos = t;
                    m.rot = *(Rot021aaf80 *)&a->rot_x;
                    m.unk_14 = 0;
                    func_ov000_0218d398(a, self->unk_0c, 7, 1, sizeof(Msg021aaf80), &m);
                }
            }
            func_ov000_0219aae8(a, self, v * 2, 0x30, 0x30, NULL, 0, sc + 0x34cd, 0x1800, -1, 0x1000);
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24.f5 = 0;
            self->unk_b24.f7 = self->unk_b24.f9;
            func_ov000_02191418(self->unk_38, 3, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->st++;
        } else {
            s32 lim;
            BOOL fall = FALSE;
            if (!(LFLD(u32, self->unk_48, 0x54) & 0x20000000)) {
                lim = -0xf000;
                if (self->unk_b22.b0 || self->unk_b24.mode || self->unk_b24.b19) {
                    lim = -0x2d000;
                }
                if (self->unk_74 - self->unk_b00 < lim) {
                    fall = TRUE;
                }
            }
            if (fall) {
                LFLD(u32, self, 0xb24) |= 0x40000;
                Release021aaf80(self, 4);
            }
            func_ov000_02191418(self->unk_38, 1, 0);
        }
        break;
    case 3:
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        Release021aaf80(self, 1);
        break;
    }
    if (!func_ov000_02191508(self->unk_38)) {
        u16 ang = self->unk_7e;
        if (self->unk_15 == 1 && (self->unk_b68 & 0xf0)) {
            ang = CamYaw021aaf80((u8 *)data_ov000_021ccd54 + 0xf4) + self->unk_b6e;
        }
        self->unk_7e = func_01ffc128(ang, self->unk_7e, 0x19a, 1, 0x8000);
    }
    func_ov000_021b1fac(self, 0, 0);
}

}
