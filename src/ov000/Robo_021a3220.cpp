#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 7;
    u32 b17 : 1;
    u32 b18 : 4;
    u32 b22 : 2;
    u32 rest : 8;
} B24_021a3220;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a3220;

typedef struct {
    u16 b0 : 6;
    u16 b6 : 1;
    u16 rest : 9;
} B2C_021a3220;

typedef struct {
    u8 b0 : 3;
    u8 b3 : 1;
    u8 rest : 4;
} B2A_021a3220;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} B93_021a3220;

typedef struct {
    u16 b0 : 5;
    u16 b5 : 1;
    u16 rest : 10;
} Ba4_021a3220;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} B19_021a3220;

typedef struct {
    u16 st;
    u16 timer;
} State_021a3220;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 x;
} Msg_021a3220;

#define B24(self) LFLD(B24_021a3220, self, 0xb24)
#define B2C(self) LFLD(B2C_021a3220, self, 0xb2c)
#define ST(self) LFLD(State_021a3220 *, self, 0x40)

extern "C" {
extern char data_ov000_021cc630[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc636[];
extern char *const data_ov000_021ca030[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd6c;
u8 *func_ov000_0218d240(u8 *self);
void *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_02198360(void *st, s32 state, s32 x);
void func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, void *pos);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
u16 func_0204bfa8(void *cam);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void func_01ffc9fc(VecFx32 *out, const void *a, s32 b);
s32 func_02040498(s32 max);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
u16 func_ov000_02198da8(void *body, u16 angle);
void func_ov000_0218996c(s32 a, s32 b);
void *func_ov000_021b68b8(void *a, void *pos);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

static inline u16 CamYaw_021a3220(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

static inline u8 *FindActor_021a3220(u16 id) {
    u8 *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(mgr, id);
}

static inline u16 AngTo_021a3220(u8 *self, u8 *t) {
    if (t == NULL || t == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, t, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, t, 0x78) - LFLD(s32, self, 0x78));
}

static inline BOOL IsBusy_021a3220(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94);
}

static inline BOOL IsIdle_021a3220(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a3220(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

#define Ba4Bit_021a3220(self) (LFLD(u8 *, self, 0xba4) != NULL && LFLD(Ba4_021a3220, LFLD(u8 *, self, 0xba4), 6).b5)

void func_ov000_021a3220(u8 *self) {
    u8 *tgt;
    BOOL hit;
    BOOL turned;

    tgt = func_ov000_0218d240(self);
    switch (ST(self)->st) {
    case 0: {
        B24(self).b17 = 0;
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021ca030[B24(self).b5], 0x555, 1);
        ST(self)->st++;
        if (B2C(self).b6) {
            ST(self)->timer = 5;
            func_02049f44(data_02097e4c, 0x79, self + 0x70, 0);
        }
        if (LFLD(s32, self, 0xa0) == 0) {
            if (!B2C(self).b6) {
                func_02049f44(data_02097e4c, 7, self + 0x70, 0);
            }
            if (!LFLD(B93_021a3220, self, 0x93).b4) {
                s32 se = 0x300;
                if (LFLD(u16, data_ov000_021ccd68, 0xa) & 1) {
                    se = 0x304;
                }
                func_02049f44(data_02097e4c, se, self + 0x70, 0);
            }
        }
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
        LFLD(s32, self, 0x9c) >>= 3;
        LFLD(s32, self, 0xa0) >>= 3;
        if ((LFLD(u16, self, 0xb1c) >> 12) == 5) {
            u8 *a = FindActor_021a3220(LFLD(u16, self, 0xb1c));
            u8 *s = NULL;
            if (a != NULL) {
                s = LFLD(u8 *, a, 0x4c);
            }
            if (s != NULL && (LFLD(u8, s, 0) == 0xf || LFLD(u8, s, 0) == 0x11)) {
                B24(self).b22 = 1;
            }
        }
        LFLD(B2A_021a3220, self, 0xb2a).b3 = 0;
    }
    case 1: {
        State_021a3220 *st = ST(self);
        st->timer++;
        if (st->timer > 5) {
            VObj *e;
            if (LFLD(u16, self, 0xb1c) == 0xffff && tgt != NULL && (u16)(LFLD(u16, tgt, 0xc) & 0xf000) == 0x5000) {
                LFLD(s32, self, 0xa0) = (LFLD(s32, tgt, 0x74) - LFLD(s32, self, 0x74)) >> 4;
                LFLD(u16, self, 0x98) = AngTo_021a3220(self, tgt);
                LFLD(s32, self, 0xa8) = 0x52;
            } else {
                if (LFLD(s32, self, 0xa0) > 0) {
                    LFLD(s32, self, 0xa0) = 0;
                }
                LFLD(s32, self, 0xa8) = 0x148;
            }
            if (Ba4Bit_021a3220(self)) {
                LFLD(s32, self, 0x9c) = LFLD(s32, self, 0xb08) + 0x5c3;
            } else {
                LFLD(s32, self, 0x9c) = LFLD(s32, self, 0xb08) + 0x51f;
            }
            if (LFLD(s32, self, 0x9c) > 0x933) {
                LFLD(s32, self, 0x9c) = 0x933;
            }
            LFLD(s32, self, 0xa4) = 0xf9a;
            ST(self)->timer = 0;
            ST(self)->st++;
            if (LFLD(u16, self, 0xb68) & 0xf0) {
                u16 yaw = CamYaw_021a3220(data_ov000_021ccd54 + 0xf4);
                LFLD(u16, self, 0x98) = yaw + LFLD(u16, self, 0xb6e);
            }
            e = func_02065f88(0x192, self + 0x70);
            LFLD(s32, self, 0xb40) = LFLD(s32, e, 0x24);
            e->vfunc_34(0, LFLD(u16, self, 0x98), 0);
            LFLD(s32, e, 0x3c) = 0x800;
            if (LFLD(B22_021a3220, self, 0xb22).b3) {
                e->vfunc_14(0x1266, 0x1266, 0x1000);
            }
            if (Ba4Bit_021a3220(self)) {
                VecFx32 v;
                VObj *e2;
                v.y = LFLD(s32, self, 0x68) >> 2;
                v.z = 0x1800;
                v.x = 0;
                func_01ffc9fc(&v, &v, LFLD(u16, self, 0x98));
                VEC_Add(&v, (VecFx32 *)(self + 0x70), &v);
                e2 = func_02065f88(0x66, &v);
                e2->vfunc_34(0xc000, LFLD(u16, self, 0x98), 0);
                e2->vfunc_14(0xb33, 0x3000, 0xb33);
                LFLD(s32, e2, 0x3c) = 0x1ccd;
            }
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        func_ov000_021b1fac(self, FALSE, 1);
        break;
    }
    case 2: {
        BOOL near;
        if (Ba4Bit_021a3220(self)) {
            s32 spd = LFLD(s32, self, 0x9c);
            u8 f = 1;
            if (B2C(self).b6) {
                f = 0;
            }
            func_ov000_021b1dd8(self, spd, 0x1000, 0x1000, 0x466, f);
            LFLD(s32, self, 0x9c) = LO_FX_MUL(spd, 0xfc3);
            if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) && (ST(self)->timer & 3) == 1) {
                VObj *e = func_02065f88(0x67, self + 0x70);
                e->vfunc_34(0, LFLD(u16, self, 0x98), 0);
                e->vfunc_0c(0x800);
                LFLD(s32, e, 0x3c) = 0x2000;
            }
        } else {
            s32 f = 1;
            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
            if (B2C(self).b6) {
                f = 0;
            }
            func_ov000_021b1fac(self, FALSE, f);
        }
        if (B2C(self).b6) {
            u16 t = ST(self)->timer;
            if (!(t & 3) && t < 0x14) {
                VObj *e = func_02065f88(0x322, self + 0x70);
                e->vfunc_24(0, LFLD(s32, self, 0x68) >> 2, 0);
                e->vfunc_34(0, (u16)func_02040498(0xffff), 0);
                e->vfunc_0c(((t & 0xfffe) << 7) + 0x800);
                LFLD(s32, e, 0x3c) = 0x4800;
            }
        }
        {
            VecFx32 o;
            o.y = LFLD(s32, self, 0x6c);
            o.x = 0;
            o.z = 0xc00;
            hit = func_ov000_0219aae8(self, self, 0, 0x42, 0x20, &o, NULL, 0x1400, 0, 0x69, 0x800);
        }
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x58) & 1) {
            hit = TRUE;
        }
        if (B2C(self).b6) {
            hit = FALSE;
        }
        near = FALSE;
        if (!hit && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x30) && !Ba4Bit_021a3220(self)) {
            u16 a = func_ov000_02198da8(LFLD(u8 *, self, 0x48), LFLD(u16, self, 0x98));
            if ((u16)(a - LFLD(u16, self, 0x98) - 0x6400) < 0x3800) {
                near = TRUE;
            }
        }
        if (hit || near) {
            BOOL ok;
            u8 *a;
            u8 *p;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x1000, 1);
            func_02049f44(data_02097e4c, 8, self + 0x70, 0);
            ok = TRUE;
            p = LFLD(u8 *, data_ov000_021ccd6c, 0x14);
            if (p == NULL || !LFLD(B19_021a3220, p, 0x19).b1) {
                ok = FALSE;
            }
            if (!ok) {
                func_ov000_0218996c(5, 10);
            }
            a = FindActor_021a3220(LFLD(u16, self, 0xb1c));
            if (a != NULL) {
                Msg_021a3220 m;
                m.pos.x = LFLD(s32, self, 0x70);
                m.pos.y = LFLD(s32, self, 0x74);
                m.pos.z = LFLD(s32, self, 0x78);
                m.pos.y += LFLD(s32, self, 0x6c);
                m.rot[0] = LFLD(u16, a, 0x7c);
                m.rot[1] = LFLD(u16, a, 0x7e);
                m.rot[2] = LFLD(u16, a, 0x80);
                m.x = 0;
                func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, TRUE, 0x18, &m);
                func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 10);
                if (LFLD(u8 *, a, 0x4c) != NULL) {
                    LFLD(B19_021a3220, LFLD(u8 *, a, 0x4c), 0x18).b0 = 0;
                }
            }
            B24(self).b5 = 0;
            LFLD(u16, self, 0xb1c) = 0xffff;
            B24(self).b7 = B24(self).b9;
            LFLD(u16, self, 0xb1e) = 0xffff;
            LFLD(u16, self, 0x98) += 0x8000;
            LFLD(s32, self, 0x9c) >>= 1;
            if (hit) {
                LFLD(s32, self, 0x9c) >>= 1;
            }
            LFLD(s32, self, 0xa0) = 0xb8;
            LFLD(s32, self, 0xa8) = 0x52;
            B2C(self).b6 = 0;
            ST(self)->st = 10;
            ST(self)->timer = 0;
        } else if (!IsIdle_021a3220() || LFLD(u8, self, 0x15) == 3 || func_ov000_021b68b8(data_ov000_021ccd6c, self + 0x70) != NULL) {
            LFLD(s32, self, 0x9c) >>= 2;
            func_ov000_02198360(ST(self), 4, 0);
        } else {
            State_021a3220 *st = ST(self);
            st->timer++;
            if (st->timer >= 0x14) {
                if (Ba4Bit_021a3220(self) && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
                    if (LFLD(u16, self, 0xb38) != 0) {
                        func_ov000_02198360(ST(self), 4, 0);
                    } else if (ST(self)->timer > 0x28) {
                        func_ov000_02198360(ST(self), 4, 0);
                    }
                } else {
                    func_ov000_02198360(ST(self), 4, 0);
                }
            }
        }
        break;
    }
    case 10: {
        State_021a3220 *st;
        func_ov000_021b1fac(self, FALSE, 1);
        st = ST(self);
        st->timer++;
        if (st->timer >= 0x1e) {
            func_ov000_02198360(ST(self), 4, 0);
        } else if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc630, 0x800, 0);
            LFLD(s32, self, 0xa4) = 0xe66;
            func_02049f44(data_02097e4c, 0x81, self + 0x70, 0);
            func_02065f88(0x12f, self + 0x70)->vfunc_0c(0x800);
            ST(self)->timer = 0;
            ST(self)->st++;
        }
        break;
    }
    case 11: {
        State_021a3220 *st;
        func_ov000_021b1fac(self, FALSE, 1);
        st = ST(self);
        st->timer++;
        if (st->timer > 0x14 || Ba4Bit_021a3220(self)) {
            func_ov000_02198360(ST(self), 1, 0);
        }
        break;
    }
    }
    if (B2C(self).b6 && LFLD(u8, ST(self), 0x13) != 0x16) {
        B2C(self).b6 = 0;
    }
    turned = FALSE;
    if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        B24(self).b17 = 1;
        turned = TRUE;
    }
    if (turned) {
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
        func_ov000_02198360(ST(self), 4, 0);
    }
}

}
