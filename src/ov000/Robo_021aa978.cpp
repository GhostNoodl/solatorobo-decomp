#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State021aa978;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 4;
    u16 lvl : 3;
    u16 rest : 6;
} B2c021aa978;

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
} B24_021aa978;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B18_021aa978;

typedef struct {
    u16 val;
    u8 d;
    u16 id;
} Hit021aa978;

typedef struct {
    u16 x, y, z;
} Rot021aa978;

typedef struct {
    VecFx32 pos;
    Rot021aa978 rot;
    u8 pad[2];
    s32 unk_14;
} Msg021aa978;

extern "C" {
extern void *data_02097e4c;
extern char data_ov000_021cc6ae[];
void *func_ov000_0218e640(ActorMgr *mgr, u16 id);
BOOL func_ov000_02191508(void *a);
void func_ov000_02191318(void *a, s32 b);
void func_ov000_0218999c(s32 a, s32 b);
void func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, VecFx32 *pos);
u16 FX_Atan2(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_ov000_0218996c(s32 a, s32 b);
void func_ov000_0218d46c(Actor *o, u16 id, s32 m);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
void func_ov000_02198360(void *s, s32 a, s32 b);
BOOL func_ov000_02191120(void *a);
void func_ov000_02191418(void *a, s32 b, s32 c);
void func_ov000_021b1fac(void *self, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
u16 func_0204bfa8(void *cam);

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021aa978;

static inline Actor *FindActor021aa978(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (Actor *)func_ov000_0218e640(mgr, id);
}

static inline u16 AngleTo021aa978(Actor *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline void Charge021aa978(u8 *self) {
    if (LFLD(u16, self, 0xb6a) & 1) {
        LFLD(u8, self, 0xb2b)++;
    }
    if (LFLD(u16, self, 0xb6a) & 0xf0) {
        LFLD(u8, self, 0xb2b) += 2;
    }
    if (LFLD(u8, self, 0xb2b) > 4) {
        LFLD(u8, self, 0xb2b) = 4;
    }
}

static inline u16 CamYaw021aa978(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

static inline void Release021aa978(u8 *self, s32 next) {
    Actor *a = FindActor021aa978(LFLD(u16, self, 0xb1c));
    if (a != NULL) {
        Msg021aa978 m;
        m.pos.x = LFLD(s32, self, 0x70);
        m.pos.y = LFLD(s32, self, 0x74);
        m.pos.z = LFLD(s32, self, 0x78);
        m.pos.y += LFLD(s32, self, 0x6c);
        m.rot = *(Rot021aa978 *)&a->rot_x;
        m.unk_14 = 0;
        func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, 1, sizeof(Msg021aa978), &m);
        func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xa);
        if (a->unk_4c != NULL) {
            LFLD(B18_021aa978, a->unk_4c, 0x18).b0 = 0;
        }
    }
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_021aa978, self, 0xb24).f5 = 0;
    LFLD(B24_021aa978, self, 0xb24).f7 = LFLD(B24_021aa978, self, 0xb24).f9;
    LFLD(B2c021aa978, self, 0xb2c).b1 = 0;
    func_ov000_02198360(LFLD(void *, self, 0x40), next, 0);
}


void func_ov000_021aa978(u8 *self) {
    Actor *a = FindActor021aa978(LFLD(u16, self, 0xb1c));
    State021aa978 *st;
    u8 *sub;
    BOOL hit;
    s32 eff;
    sub = NULL;
    if (a != NULL) {
        sub = (u8 *)a->unk_4c;
    }
    eff = 0;
    hit = FALSE;
    st = LFLD(State021aa978 *, self, 0x40);
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc6ae, 0x555, 0);
        LFLD(State021aa978 *, self, 0x40)->st++;
        break;
    case 1:
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) != 1) {
            break;
        }
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
        LFLD(B2c021aa978, self, 0xb2c).lvl = 1;
        eff = 1;
        st->st++;
        LFLD(State021aa978 *, self, 0x40)->timer = 0;
    case 2: {
        State021aa978 *s;
        hit = TRUE;
        Charge021aa978(self);
        func_ov000_02191418(LFLD(void *, self, 0x38), 1, 0);
        s = LFLD(State021aa978 *, self, 0x40);
        s->timer++;
        if (s->timer < 0x20) {
            LFLD(u16, self, 0x7e) += 0x800;
            break;
        }
        LFLD(State021aa978 *, self, 0x40)->timer = 0;
        if (LFLD(B2c021aa978, self, 0xb2c).lvl < 3 && LFLD(u8, self, 0xb2b) >= 4) {
            eff = 1;
            LFLD(u8, self, 0xb2b) = 0;
            LFLD(B2c021aa978, self, 0xb2c).lvl++;
            break;
        }
        {
            Actor *t = FindActor021aa978(LFLD(u16, self, 0x90));
            if (t != NULL) {
                LFLD(u16, self, 0x98) = AngleTo021aa978((Actor *)self, t);
            } else if (LFLD(u16, self, 0xb68) & 0xf0) {
                LFLD(u16, self, 0x98) = CamYaw021aa978((u8 *)data_ov000_021ccd54 + 0xf4) + LFLD(u16, self, 0xb6e);
            }
        }
        LFLD(State021aa978 *, self, 0x40)->st++;
        break;
    }
    case 3: {
        u16 tgt;
        u16 d;
        func_ov000_02191418(LFLD(void *, self, 0x38), 1, 0);
        tgt = LFLD(u16, self, 0x98) + 0x8000;
        d = tgt - LFLD(u16, self, 0x7e);
        if (d > 0x800 && d < 0xf800) {
            LFLD(u16, self, 0x7e) += 0x800;
            break;
        }
        LFLD(u16, self, 0x7e) = tgt;
        hit = TRUE;
        eff = 2;
        LFLD(State021aa978 *, self, 0x40)->st++;
        break;
    }
    case 4:
        if (a == NULL || sub == NULL) {
            st->st++;
            break;
        }
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) != 2) {
            break;
        }
        func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xb);
        a->rot_y = LFLD(u16, self, 0x7e) + 0x8000;
        LFLD(s32, sub, 0x50) = 0x2000;
        LFLD(s32, sub, 0x54) = 0x19a;
        LFLD(s32, sub, 0x58) = 0;
        {
            u8 v = LFLD(B2c021aa978, self, 0xb2c).lvl * 5;
            LFLD(u8, sub, 0x19) = LFLD(B24_021aa978, self, 0xb24).f22;
            LFLD(u8, sub, 0x1b) = v;
        }
        if (a != NULL) {
            Msg021aa978 m;
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
            if (func_01ffbd6c((VecFx32 *)(self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                t.x -= LFLD(s32, self, 0x70);
                t.y -= LFLD(s32, self, 0x74);
                t.z -= LFLD(s32, self, 0x78);
                VEC_MultAdd(0xc00, &t, (VecFx32 *)(self + 0x70), &t);
                m.pos = t;
                m.rot = *(Rot021aa978 *)&a->rot_x;
                m.unk_14 = 0;
                func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, 1, sizeof(Msg021aa978), &m);
            }
        }
        func_02049f44(data_02097e4c, 0x32, self + 0x70, 0);
        LFLD(u16, self, 0xb1c) = 0xffff;
        LFLD(u16, self, 0xb1e) = 0xffff;
        LFLD(B24_021aa978, self, 0xb24).f5 = 0;
        LFLD(B24_021aa978, self, 0xb24).f7 = LFLD(B24_021aa978, self, 0xb24).f9;
        LFLD(State021aa978 *, self, 0x40)->st++;
        break;
    case 5:
        if (!func_ov000_02191120(LFLD(void *, self, 0x38))) {
            break;
        }
        LFLD(B2c021aa978, self, 0xb2c).b0 = 0;
        func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        break;
    }
    if (eff != 0) {
        s32 sc = 0x4400;
        s32 id;
        VObj *o;
        if (a != NULL) {
            sc += a->unk_64 * 2;
        }
        id = 0x3ea;
        if (eff == 2) {
            id = 0x3e9;
        }
        o = func_02065f88(id, (VecFx32 *)(self + 0x70));
        o->vfunc_24(0, LFLD(s32, self, 0x6c), 0);
        o->vfunc_0c(sc);
        o->vfunc_30(self + 0x7c);
        LFLD(s32, o, 0x3c) = 0x99a;
    }
    if (!hit || a == NULL) {
        return;
    }
    if (!func_ov000_0219aae8(a, self, (u8)(LFLD(B2c021aa978, self, 0xb2c).lvl * 5), 0x30, 0x30, NULL, 0, a->unk_64 + 0xccd, 0, 0x64, 0x1000)) {
        return;
    }
    func_ov000_0218996c(8, 0xa);
    func_02049f44(data_02097e4c, 0x7d, self + 0x70, 0);
    func_ov000_02191418(LFLD(void *, self, 0x38), 3, 0);
}

}
