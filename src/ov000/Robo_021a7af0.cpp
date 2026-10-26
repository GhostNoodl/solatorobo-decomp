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
    u32 b24 : 3;
    u32 b27 : 1;
    u32 rest : 4;
} B24_021a7af0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a7af0;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 2;
    u16 rest : 10;
} B2C_021a7af0;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 2;
    u8 rest : 1;
} B93_021a7af0;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 rest : 5;
} B94_021a7af0;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} H22_021a7af0;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 rest : 3;
} I18_021a7af0;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 rest : 7;
} Ba4_021a7af0;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B19_021a7af0;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 rest : 11;
} H9a_021a7af0;

typedef struct {
    u16 st;
    u16 timer;
} State_021a7af0;

#define B24(self) LFLD(B24_021a7af0, self, 0xb24)
#define B22(self) LFLD(B22_021a7af0, self, 0xb22)
#define ST(self) LFLD(State_021a7af0 *, self, 0x40)

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd6c;
extern u8 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern void *data_0214a424;
extern char data_ov000_021cc672[];
extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc666[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc630[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02191120(void *a);
s32 func_ov000_02190cb0(void *model, const char *name, s16 blend, u8 force);
void *func_ov000_02191318(void *model, s32 frame);
void func_ov000_021911c8(void *model, s16 speed);
s32 func_ov000_02198360(void *history, u8 value, BOOL force);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void func_ov000_021987b8(void *body, u8 keep, VecFx32 *pos, const void *rot);
BOOL func_01ffc584(void *a, void *b, s32 c, s32 d);
s32 **func_ov000_02190a30(void *model, u32 i);
VObj *func_02065f88(s32 id, void *pos);
void *func_02049a48(void *mgr, s32 id, s32 volume, s32 targetVolume, s32 frame);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021915a0(void *p);
void func_ov000_0218d988(void *self, void *other, s32 a);
void func_ov000_0218996c(u8 a, u8 b);
s32 func_02049bdc(void *mgr, s32 id, s32 pan);
void func_020627a0(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
void func_ov000_02191418(void *model, u16 delay, BOOL force);
s32 func_02040528(s32 max);
u32 func_02040498(u32 max);
u8 func_0206d37c(void *flags, u32 i);
void func_ov000_0218d46c(void *actor, u16 id, u8 value);
void func_ov000_02199b88(void *a, void *b);
u8 *func_ov000_02199ba0(void *p);
u16 func_ov000_0218d8f4(void *self, void *target);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 pan);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s16 d, s16 e);
void func_ov000_02168490(void *self, s32 a, s32 b, VecFx32 *p, VecFx32 *q);
void func_02062764(u16 clear, u16 set);

static inline u8 *FindActor_021a7af0(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 AngleTo_021a7af0(u8 *self, u8 *other) {
    if (other == NULL || other == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, other, 0x78) - LFLD(s32, self, 0x78));
}

static inline s32 Frame_021a7af0(void *m) {
    s32 f = 0;
    s32 **a = func_ov000_02190a30(m, f);
    if (*a != NULL) {
        f = **a;
    }
    return f;
}

static inline s32 FxMul_021a7af0(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL IsBusy_021a7af0(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94);
}

static inline BOOL IsIdle_021a7af0(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a7af0(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 SubKind_021a7af0(u8 *a) {
    return LFLD(u8 *, a, 0x40) != NULL ? LFLD(u8, LFLD(u8 *, a, 0x40), 0x13) : 0;
}

static inline void Gauge_021a7af0(s32 a, s32 b, VecFx32 *p, VecFx32 *q) {
    u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (o == NULL) {
        return;
    }
    if (LFLD(void *, o, 0x74) == NULL) {
        return;
    }
    func_ov000_02168490(LFLD(void *, o, 0x74), a, b, p, q);
}

static inline BOOL Flag19_021a7af0(u8 *g) {
    u8 *p = LFLD(u8 *, g, 0x14);
    if (p != NULL && LFLD(B19_021a7af0, p, 0x19).b0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Info18b4_021a7af0(u8 *info) {
    return LFLD(I18_021a7af0, info, 0x18).b4 ? TRUE : FALSE;
}

static inline BOOL HasD4_021a7af0(u8 *g) {
    return LFLD(s32, g, 0xd4) != 0;
}

static inline void Bump_021a7af0(u8 *self) {
    if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        B24(self).b17 = 1;
    }
}

static inline void Tail13_021a7af0(u8 *self) {
    State_021a7af0 *st = ST(self);
    if (!(LFLD(u64, st, 4) & 8)) {
        return;
    }
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
        return;
    }
    func_ov000_02198360(st, 3, 0);
}

void func_ov000_021a7af0(u8 *self) {
    u8 *t;
    u8 *info;
    u8 *x50;
    State_021a7af0 *st;
    VecFx32 v;
    BOOL f;
    u16 id;

    id = LFLD(u16, self, 0xb1e);
    if (id == 0xffff) {
        id = LFLD(u16, self, 0xb1c);
        if (id == 0xffff) {
            id = LFLD(u16, self, 0x90);
        }
    }
    t = FindActor_021a7af0(id);
    info = NULL;
    x50 = NULL;
    if (t != NULL) {
        u8 *c = LFLD(u8 *, t, 0x44);
        if (LFLD(u16, self, 0xb1c) != 0xffff ||
            (c != NULL && LFLD(H22_021a7af0, c, 0x22).b0 == 1 && LFLD(H22_021a7af0, c, 0x22).b1 == 1)) {
            info = LFLD(u8 *, t, 0x4c);
            x50 = LFLD(u8 *, t, 0x50);
            if (LFLD(u8, self, 0xb2f) == 0) {
                LFLD(u8, self, 0xb2f)++;
            }
        }
    }
    st = ST(self);
    switch (st->st) {
    case 0x64:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            if (t != NULL) {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc672, 0x111, 0);
                func_ov000_02191318(LFLD(void *, self, 0x38), 0x17000);
                func_ov000_021911c8(LFLD(void *, self, 0x38), 0);
                ST(self)->timer = 0xf;
                ST(self)->st++;
            } else {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0x89, 0);
                func_ov000_02198360(ST(self), 1, 0);
                return;
            }
        }
        if (t == NULL) {
            return;
        }
        LFLD(u16, self, 0x98) = AngleTo_021a7af0(self, t);
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        return;
    case 0x65:
        if (t != NULL) {
            v = LFLD(VecFx32, t, 0x70);
            v.x -= LFLD(s32, self, 0x70);
            v.y -= LFLD(s32, self, 0x74);
            v.z -= LFLD(s32, self, 0x78);
            v.x = FxMul_021a7af0(v.x, 0x1ec);
            v.y = FxMul_021a7af0(v.y, 0x1ec);
            v.z = FxMul_021a7af0(v.z, 0x1ec);
            v.y *= 3;
            VEC_Add((VecFx32 *)(self + 0x70), &v, (VecFx32 *)(self + 0x70));
            v = LFLD(VecFx32, self, 0x70);
            v.y -= 0x1000;
            LFLD(u16, self, 0x98) = AngleTo_021a7af0(self, t);
            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
            f = FALSE;
            func_ov000_021987b8(LFLD(void *, self, 0x48), 0, NULL, NULL);
            if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
                LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
                LFLD(s32, self, 0x9c) = 0x66;
                LFLD(s32, self, 0xa4) = 0;
                if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                    LFLD(s32, self, 0xa0) = 0x200;
                }
                LFLD(s32, self, 0xa8) = 0x52;
                B24(self).b17 = 1;
                f = TRUE;
            }
            if (f) {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
                func_ov000_02198360(ST(self), 4, 0);
                return;
            }
            {
                State_021a7af0 *s = ST(self);
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            if (ST(self)->timer == 0 || func_01ffc584(t + 0x70, &v, LFLD(s32, t, 0x64) * 2 + 0x99a, 0x3800)) {
                ST(self)->st++;
                return;
            }
            if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000) {
                ST(self)->st = 0x1e;
            }
            return;
        } else {
            func_ov000_02198360(st, 1, 0);
        }
        return;
    case 0x66:
        if (t != NULL) {
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer != 0) {
                return;
            }
            LFLD(s32, self, 0xb60) = Frame_021a7af0(LFLD(void *, self, 0x38));
            func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1000);
            LFLD(u16, self, 0xb1e) = LFLD(u16, t, 0xc);
            LFLD(s32, self, 0x9c) = 0;
            LFLD(s32, self, 0xa0) = 0;
            LFLD(s32, self, 0xa4) = 0;
            LFLD(s32, self, 0xa8) = 0x52;
            ST(self)->timer = 0;
            ST(self)->st = 10;
            return;
        } else {
            func_ov000_02198360(st, 1, 0);
        }
        return;
    case 0:
        B24(self).b27 = 0;
        if (LFLD(B2C_021a7af0, self, 0xb2c).b4 == 3) {
            VObj *o;
            LFLD(B2C_021a7af0, self, 0xb2c).b4 = 0;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc666, 0x800, 1);
            o = func_02065f88(0x391, self + 0x70);
            o->vfunc_24(0, (LFLD(s32, self, 0x68) >> 1) + (LFLD(s32, self, 0x68) >> 3), 0);
            o->vfunc_0c(0x1333);
            LFLD(s32, o, 0x3c) = 0x2ccd;
            func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
            ST(self)->st = 0x64;
            return;
        }
        if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            LFLD(s32, self, 0x9c) = 0;
            LFLD(u16, self, 0x98) = AngleTo_021a7af0(self, t);
            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
            func_ov000_021b1fac(self, FALSE, 1);
            Bump_021a7af0(self);
            {
                State_021a7af0 *s = ST(self);
                s->timer++;
                if (s->timer >= 0x1e) {
                    func_ov000_02198360(ST(self), 4, 0);
                }
            }
        } else {
            B24(self).b22 = 0;
            st->timer = 0;
            ST(self)->st++;
        }
        return;
    case 1: {
        s32 r;
        s32 h;
        if (info == NULL) {
            st->st = 0x14;
            return;
        }
        LFLD(u16, self, 0x98) = AngleTo_021a7af0(self, t);
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        v = LFLD(VecFx32, self, 0x70);
        v.y -= 0x1000;
        r = LFLD(s32, self, 0x64) + 0x1000;
        h = 0x3800;
        if (B22(self).b3) {
            r += 0x400;
            h += 0x429;
        }
        {
            State_021a7af0 *s = ST(self);
            s->timer++;
            if (s->timer < 0x14 && !func_01ffc584(t + 0x70, &v, r + LFLD(s32, t, 0x64), h)) {
                u32 fl;
                f = FALSE;
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc61e, 0x400, 0);
                func_ov000_021915a0(LFLD(void *, self, 0x38));
                LFLD(s32, self, 0x9c) = 0x229;
                LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
                func_ov000_021b1fac(self, FALSE, 1);
                fl = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
                if (fl & 0x40000000) {
                    ST(self)->st = 0x1e;
                    return;
                }
                if (!(fl & 0x20000000)) {
                    ST(self)->st = 0x1e;
                    return;
                }
                if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
                    LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
                    LFLD(s32, self, 0x9c) = 0x66;
                    LFLD(s32, self, 0xa4) = 0;
                    if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                        LFLD(s32, self, 0xa0) = 0x200;
                    }
                    LFLD(s32, self, 0xa8) = 0x52;
                    B24(self).b17 = 1;
                    f = TRUE;
                }
                if (!f) {
                    return;
                }
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
                func_ov000_02198360(ST(self), 4, 0);
                return;
            }
        }
        {
            s16 rate = 0x159a;
            char *anim = !B22(self).b3 ? data_ov000_021cc672 : data_ov000_021cc64e;
            if (info != NULL && LFLD(u8, info, 0) == 0x14) {
                rate = 0x1c00;
            }
            func_ov000_02190cb0(LFLD(void *, self, 0x38), anim, 0x800, 1);
            func_ov000_021911c8(LFLD(void *, self, 0x38), rate);
            LFLD(s32, self, 0x9c) = 0;
            LFLD(s32, self, 0xa0) = 0;
            LFLD(s32, self, 0xa4) = 0;
            LFLD(s32, self, 0xa8) = 0x52;
            ST(self)->st = 10;
        }
        return;
    }
    case 10: {
        s32 r;
        s32 h;
        u16 bonus;
        VObj *o;
        if (info == NULL) {
            st->st = 0x1e;
            return;
        }
        v = LFLD(VecFx32, self, 0x70);
        v.y -= 0x1000;
        r = LFLD(s32, self, 0x64) + 0x2800;
        h = 0x3800;
        if (B22(self).b3) {
            r += 0x400;
            h += 0x429;
        }
        if (!func_01ffc584(t + 0x70, &v, r + LFLD(s32, t, 0x64), h)) {
            ST(self)->st = 0x1e;
            return;
        }
        {
            u8 *b = LFLD(u8 *, self, 0x48);
            if (!(LFLD(u32, b, 0x50) & 0x20000000)) {
                if (!(LFLD(u32, b, 0x54) & 0x20000000)) {
                    ST(self)->st = 0x1e;
                    return;
                }
                func_ov000_021b1fac(self, FALSE, 1);
                Bump_021a7af0(self);
            }
        }
        func_ov000_0218d988(self, t, 0x400);
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            ST(self)->st = 0x1e;
            return;
        }
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) != 3) {
            return;
        }
        bonus = 0;
        LFLD(u16, self, 0xb3a) = 0;
        LFLD(u16, self, 0xb3c) = LFLD(u16, info, 4);
        if (x50 != NULL) {
            u16 lim;
            u16 n;
            u16 d;
            LFLD(u8, self, 0xb2a) |= 4;
            n = LFLD(u16, x50, 0xe) + 5;
            lim = LFLD(u16, self, 0xb3c) - (LFLD(u16, self, 0xb3c) >> 2);
            LFLD(u16, self, 0xb3a) = LFLD(u16, x50, 0xe);
            if (n > lim) {
                n = lim;
            }
            LFLD(u16, x50, 0xe) = n;
            d = (u16)(AngleTo_021a7af0(self, t) - LFLD(u16, t, 0x7e)) + 0x38e2;
            if (d <= 0x71c4) {
                if (d < 0x2aaa || d > 0x471a) {
                    bonus = (LFLD(u16, self, 0xb3c) + 3) >> 2;
                } else {
                    bonus = (LFLD(u16, self, 0xb3c) + 1) >> 1;
                }
            } else {
                s32 k = SubKind_021a7af0(t);
                if (k == 0x12 || k == 0x13 || LFLD(B94_021a7af0, t, 0x94).b0) {
                    bonus = (LFLD(u16, self, 0xb3c) + 3) >> 2;
                }
            }
        }
        o = func_02065f88(0x193, self + 0x70);
        o->vfunc_34(0, LFLD(u16, self, 0x7e), 0);
        LFLD(s32, o, 0x3c) = 0xccd;
        LFLD(s32, self, 0xb48) = LFLD(s32, o, 0x24);
        LFLD(s16, self, 0xb5e) = 0;
        LFLD(s32, self, 0xb4c) = 0;
        LFLD(s32, self, 0xb50) = 0;
        LFLD(s32, self, 0xb54) = 0;
        LFLD(u16, self, 0xb58) = 0;
        LFLD(u16, self, 0xb5a) = 0;
        LFLD(u16, self, 0xb5c) = 0;
        if (bonus != 0) {
            VObj *o2;
            u8 *m;
            LFLD(u16, self, 0xb3a) += bonus;
            if (LFLD(u16, self, 0xb3a) >= LFLD(u16, self, 0xb3c)) {
                LFLD(u16, self, 0xb3a) = LFLD(u16, self, 0xb3c) - 1;
            }
            func_ov000_0218996c(9, 0xf);
            v = LFLD(VecFx32, t, 0x70);
            v.y += LFLD(s32, t, 0x68) + 0x400;
            o2 = func_02065f88(0x44c, &v);
            LFLD(s32, o2, 0x3c) = 0x99a;
            o2->vfunc_0c(0x1400);
            m = LFLD(u8 *, self, 0x38);
            LFLD(u16, m, 0xb6) = 0x73ff;
            LFLD(u16, m, 0xb8) = 0x73ff;
            LFLD(u16, m, 0xba) = 5;
            LFLD(u16, m, 0xbc) = 4;
            func_02049bdc(data_02097e4c, 0x4a, -5);
        } else {
            func_ov000_0218996c(6, 10);
        }
        func_02049a48(data_02097e4c, 0x45, -1, -1, -1);
        LFLD(s32, self, 0xb60) = Frame_021a7af0(LFLD(void *, self, 0x38));
        LFLD(u16, self, 0xb1e) = LFLD(u16, t, 0xc);
        ST(self)->timer = 0;
        ST(self)->st++;
        return;
    }
    case 11: {
        s32 r;
        s32 h;
        if (info == NULL) {
            st->st = 0x1e;
            return;
        }
        {
            u8 *b = LFLD(u8 *, self, 0x48);
            if (!(LFLD(u32, b, 0x50) & 0x20000000)) {
                if (!(LFLD(u32, b, 0x54) & 0x20000000)) {
                    st->st = 0x1e;
                    return;
                }
                func_ov000_021b1fac(self, FALSE, 1);
                Bump_021a7af0(self);
            }
        }
        {
            u8 k = LFLD(B94_021a7af0, t, 0x94).b1;
            if (k != 0) {
                BOOL stop = TRUE;
                if ((u8)(k + 0xfe) <= 1) {
                    if ((u16)(LFLD(u16, t, 0x7e) - LFLD(u16, self, 0x7e) + 0x4000) < 0x8000) {
                        stop = FALSE;
                    } else if (k == 3) {
                        u8 *g;
                        func_020627a0(LFLD(u16, t, 0xe), LFLD(u16, t, 0xc));
                        func_020627dc(5);
                        g = data_ov000_021ccd54;
                        LFLD(u8, g, 0xac) = stop;
                        func_ov000_02182590(g + 0xac);
                    }
                }
                if (stop) {
                    ST(self)->st = 0x1e;
                    return;
                }
            }
        }
        v = LFLD(VecFx32, self, 0x70);
        v.y -= 0x1000;
        r = LFLD(s32, self, 0x64) + 0x2800;
        h = 0x3800;
        if (B22(self).b3) {
            r += 0x400;
            h += 0x429;
        }
        if (!func_01ffc584(t + 0x70, &v, r + LFLD(s32, t, 0x64), h)) {
            ST(self)->st = 0x1e;
            return;
        }
        {
            u8 *p = LFLD(u8 *, self, 0xba4);
            if (p != NULL && LFLD(Ba4_021a7af0, p, 6).b8 && LFLD(u16, self, 0xb36) >= 0x10) {
                B24(self).b5 = 0;
                LFLD(u16, self, 0xb1c) = 0xffff;
                LFLD(u16, self, 0xb1e) = 0xffff;
                B24(self).b7 = B24(self).b9;
                LFLD(u16, self, 0xb3a) = 0;
                LFLD(B93_021a7af0, self, 0x93).b5 = 1;
                func_ov000_02198360(ST(self), 0x1c, 0);
                return;
            }
        }
        if (IsIdle_021a7af0()) {
            ST(self)->timer++;
        }
        if ((LFLD(u16, self, 0xb6a) & 2) || (ST(self)->timer >= 0x1e && (LFLD(u16, self, 0xb68) & 0xf0))) {
            ST(self)->st = 0x14;
            return;
        }
        if (ST(self)->timer >= 0x4b) {
            if (LFLD(u16, self, 0xb3a) > 1) {
                LFLD(u16, self, 0xb3a)--;
                ST(self)->timer = 0x46;
            } else {
                LFLD(u16, self, 0xb3a) = 0;
                ST(self)->st = 0x1e;
                return;
            }
        }
        func_ov000_02191418(LFLD(void *, self, 0x38), 1, 0);
        {
            s32 fr = Frame_021a7af0(LFLD(void *, self, 0x38));
            func_ov000_02191318(LFLD(void *, self, 0x38), fr + ((LFLD(s32, self, 0xb60) - fr) >> 3));
        }
        if (LFLD(u16, self, 0xb6a) & 1) {
            s16 n;
            ST(self)->timer = 0;
            func_ov000_02191318(LFLD(void *, self, 0x38), LFLD(s32, self, 0xb60) + 0x3000);
            func_02049a48(data_02097e4c, 0x2a, -1, -1, -1);
            if (!B22(self).b3) {
                VObj *o = func_02065f88(0x44d, self + 0x70);
                s32 a = func_02040528(0x4cd);
                s32 b = func_02040498(0x800);
                s32 c = func_02040528(0x4cd);
                o->vfunc_24(a, b, c);
                o->vfunc_0c((LFLD(u16, data_ov000_021ccd68, 0xa) & 0xff) + 0xf00);
            }
            n = func_0206d37c(data_0214a424, 2);
            if (B22(self).b3) {
                n += 5;
            }
            n += 10;
            LFLD(u16, self, 0xb3a) += (u16)n;
            if (LFLD(u16, self, 0xb3a) >= LFLD(u16, self, 0xb3c)) {
                u8 kind;
                LFLD(u16, self, 0xb3a) = LFLD(u16, self, 0xb3c);
                LFLD(u16, self, 0xb1e) = 0xffff;
                if (x50 != NULL) {
                    LFLD(u16, x50, 0xe) = 0;
                }
                LFLD(H9a_021a7af0, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
                ST(self)->st++;
                kind = LFLD(u8, info, 0);
                if (kind == 0x11) {
                    func_ov000_0218d46c(t, LFLD(u16, self, 0xc), 0x14);
                    if (x50 != NULL) {
                        LFLD(u16, x50, 4) = LFLD(u16, self, 0xc);
                        LFLD(u16, x50, 6) = 0;
                        LFLD(u8, x50, 8) = 0;
                        LFLD(u8, x50, 9) = 0;
                    }
                    func_ov000_021911c8(LFLD(void *, self, 0x38), 0x159a);
                } else if (kind == 0x13) {
                    if (B22(self).b3 && LFLD(u8, info, 1) == 1) {
                        B24(self).b5 = 1;
                    } else {
                        B24(self).b5 = 2;
                    }
                    B24(self).b7 = 2;
                    LFLD(u16, self, 0xb1c) = LFLD(u16, self, 0x90);
                    LFLD(u16, self, 0x90) = 0xffff;
                    func_ov000_0218d46c(t, LFLD(u16, self, 0xc), 9);
                    func_ov000_02199b88(info, self);
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1000);
                } else if (kind == 0x12) {
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_ov000_02198360(ST(self), 6, 0);
                } else if (kind == 0x14) {
                    u8 *p;
                    VObj *o;
                    LFLD(u16, self, 0x90) = 0xffff;
                    func_ov000_0218d46c(t, LFLD(u16, self, 0xc), 0xb);
                    p = func_ov000_02199ba0(info);
                    if (p == NULL) {
                        LFLD(u16, t, 0x7e) = LFLD(u16, self, 0x7e);
                    } else {
                        LFLD(u16, t, 0x7e) = func_ov000_0218d8f4(t, LFLD(void *, p, 0x44));
                        LFLD(u16, t, 0x90) = LFLD(u16, p, 0xc);
                    }
                    func_ov000_02199b88(info, self);
                    func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    func_02049f44(data_02097e4c, 0x2c, self + 0x70, 0);
                    func_ov000_0218996c(8, 0xc);
                    o = func_02065f88(0x69, self + 0x70);
                    if (o != NULL) {
                        o->vfunc_24(0, LFLD(s32, self, 0x6c), 0);
                    }
                    func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1000);
                }
            }
        }
        func_ov000_0218d988(self, t, 0x400);
        {
            u8 *g = data_ov000_021ccd6c;
            VecFx32 w;
            VecFx32 u;
            v = LFLD(VecFx32, t, 0x70);
            v.y += LFLD(s32, t, 0x68) - LFLD(s32, self, 0x6c);
            v.x -= LFLD(s32, self, 0x70);
            v.y -= LFLD(s32, self, 0x74);
            v.z -= LFLD(s32, self, 0x78);
            v.x = FxMul_021a7af0(v.x, 0x733);
            v.y = FxMul_021a7af0(v.y, 0x733);
            v.y += LFLD(s32, self, 0x6c);
            v.z = FxMul_021a7af0(v.z, 0x733);
            if (!Flag19_021a7af0(g) && !Info18b4_021a7af0(info) && !B24(self).b27) {
                if (!IsIdle_021a7af0() || HasD4_021a7af0(data_ov000_021ccd54)) {
                    B24(self).b27 = 1;
                }
                VEC_Add(&v, (VecFx32 *)(self + 0x70), &w);
                func_ov000_021899d8(&w, 0, LFLD(s32, t, 0x64) + 0x8ccd, 1, 0x2000, 0x1000);
            }
            u.x = 0;
            u.y = -0x2000;
            u.z = 0;
            Gauge_021a7af0(LFLD(u16, self, 0xb3a), LFLD(u16, self, 0xb3c), &v, &u);
        }
        return;
    }
    case 12:
        st->timer++;
        if (st->timer >= 4) {
            s32 kind = 0;
            if (info != NULL) {
                kind = LFLD(u8, info, 0);
            }
            if (kind == 0xf) {
                if (t != NULL && SubKind_021a7af0(t) == 0x14) {
                    func_02049f44(data_02097e4c, 0x29, self + 0x70, 0);
                    func_02049a48(data_02097e4c, LFLD(u16, self, 0xb3c) > 0x28 ? 0x303 : 0x302, -1, -1, -1);
                    func_ov000_0218996c(4, 5);
                }
            } else if (kind == 0x13) {
                if (t != NULL && SubKind_021a7af0(t) == 9 && LFLD(I18_021a7af0, info, 0x18).b1) {
                    u8 *g;
                    func_02062764(0x3c0, 0x200);
                    func_020627a0(LFLD(u16, t, 0xe), LFLD(u16, t, 0xc));
                    g = data_ov000_021ccd54;
                    LFLD(u8, g, 0xac) = 1;
                    func_ov000_02182590(g + 0xac);
                }
            }
            ST(self)->timer = 0;
            ST(self)->st++;
        }
        LFLD(H9a_021a7af0, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
        return;
    case 13:
        if (func_ov000_02191120(LFLD(void *, self, 0x38)) || LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) == 2) {
            func_ov000_021911c8(LFLD(void *, self, 0x38), 0x800);
            ST(self)->timer = 0;
            ST(self)->st++;
        }
        Tail13_021a7af0(self);
        return;
    case 14:
        st->timer++;
        if (st->timer >= 0xf) {
            func_ov000_02198360(ST(self), 1, 0);
        }
        Tail13_021a7af0(self);
        return;
    case 0x14:
        LFLD(u16, self, 0xb1c) = 0xffff;
        B24(self).b5 = 0;
        LFLD(u16, self, 0xb1e) = 0xffff;
        B24(self).b7 = B24(self).b9;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(u16, self, 0xb3a) = 0;
        LFLD(s32, self, 0xb48) = 0;
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0x200, 0);
        func_ov000_02198360(ST(self), 1, 0);
        return;
    case 0x1e:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x1000, 1);
        func_02049f44(data_02097e4c, 0x73, self + 0x70, 0);
        LFLD(u16, self, 0xb1c) = 0xffff;
        B24(self).b5 = 0;
        B24(self).b7 = B24(self).b9;
        LFLD(u16, self, 0xb3a) = 0;
        LFLD(s32, self, 0xb48) = 0;
        LFLD(u16, self, 0xb1e) = 0xffff;
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e) + 0x8000;
        LFLD(s32, self, 0x9c) = 0x200;
        LFLD(s32, self, 0xa4) = 0xef6;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(s32, self, 0xa0) = 0x10a;
        LFLD(s32, self, 0xa8) = 0x52;
        ST(self)->st++;
        ST(self)->timer = 0;
        return;
    case 0x1f: {
        State_021a7af0 *s;
        f = FALSE;
        func_ov000_021b1fac(self, f, 1);
        if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
            LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
            LFLD(s32, self, 0x9c) = 0x66;
            LFLD(s32, self, 0xa4) = 0;
            if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                LFLD(s32, self, 0xa0) = 0x200;
            }
            LFLD(s32, self, 0xa8) = 0x52;
            B24(self).b17 = 1;
            f = TRUE;
        }
        if (f) {
            func_ov000_02198360(ST(self), 4, 0);
            return;
        }
        s = ST(self);
        s->timer++;
        if (s->timer >= 0x1e) {
            func_ov000_02198360(ST(self), 4, 0);
            return;
        }
        if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc630, 0x800, 0);
        LFLD(s32, self, 0xa4) = 0xe66;
        func_02049f44(data_02097e4c, 0x81, self + 0x70, 0);
        func_02065f88(0x12f, self + 0x70)->vfunc_0c(0x800);
        ST(self)->timer = 0;
        ST(self)->st++;
        return;
    }
    case 0x20: {
        State_021a7af0 *s;
        f = FALSE;
        func_ov000_021b1fac(self, f, 1);
        if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
            LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
            LFLD(s32, self, 0x9c) = 0x66;
            LFLD(s32, self, 0xa4) = 0;
            if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                LFLD(s32, self, 0xa0) = 0x200;
            }
            LFLD(s32, self, 0xa8) = 0x52;
            B24(self).b17 = 1;
            f = TRUE;
        }
        if (f) {
            func_ov000_02198360(ST(self), 4, 0);
            return;
        }
        s = ST(self);
        s->timer++;
        if (s->timer > 0x1e) {
            func_ov000_02198360(ST(self), 1, 0);
        }
        return;
    }
    }
}
}
