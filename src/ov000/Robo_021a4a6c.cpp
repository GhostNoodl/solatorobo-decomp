#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 b20 : 2;
    u32 b22 : 2;
    u32 rest : 8;
} B24_021a4a6c;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 rest : 10;
} B2C_021a4a6c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a4a6c;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} B93_021a4a6c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
} S18_021a4a6c;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} H22_021a4a6c;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 rest : 13;
} G18_021a4a6c;

typedef struct {
    u16 st;
    u16 timer;
    u64 keys;
} State_021a4a6c;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 x;
} Msg_021a4a6c;

#define B24(self) LFLD(B24_021a4a6c, self, 0xb24)
#define B2C(self) LFLD(B2C_021a4a6c, self, 0xb2c)
#define B22(self) LFLD(B22_021a4a6c, self, 0xb22)
#define B93(self) LFLD(B93_021a4a6c, self, 0x93)
#define ST(self) LFLD(State_021a4a6c *, self, 0x40)

extern "C" {
extern char data_ov000_021cc666[];
extern char data_ov000_021cc64e[];
extern char data_ov000_021cc66c[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc672[];
extern char data_ov000_021cc5e3[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd68;
extern u8 *data_0214a424;
void *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, void *pos);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *a);
void func_ov000_021911c8(void *a, s32 b);
void *func_ov000_02191318(void *a, s32 frame);
void func_ov000_02191418(void *a, s32 b, s32 c);
void func_ov000_021915a0(void *a);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_01ffc584(void *hit, VecFx32 *pos, s32 r, s32 h);
BOOL func_01ffc198(void *a, VecFx32 *b, s32 r);
void func_ov000_0218d988(void *self, void *other, s32 step);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void func_ov000_02199b88(void *body, void *p);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_ov000_02182590(void *p);
void func_ov000_021899d8(VecFx32 *a, s32 b, s32 c, s32 d, s16 e, s16 f);

static inline BOOL IsBusy_021a4a6c(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94);
}

static inline BOOL IsIdle_021a4a6c(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_021a4a6c(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u8 *FindActor_021a4a6c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u8 *FindActor2_021a4a6c(u16 id) {
    u8 *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return a;
}

static inline u16 AngleTo_021a4a6c(u8 *self, u8 *other) {
    if (other == NULL || other == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, other, 0x78) - LFLD(s32, self, 0x78));
}

static inline BOOL Both_021a4a6c(u8 *c) {
    return (LFLD(H22_021a4a6c, c, 0x22).b0 == 1 && LFLD(H22_021a4a6c, c, 0x22).b1 == 1) ? TRUE : FALSE;
}

static inline s32 FxMul_021a4a6c(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Falling_021a4a6c(u8 *self) {
    BOOL drop = FALSE;
    if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
        s32 lim = -0xf000;
        if (B22(self).b0 != 0 || B24(self).b12 != 0 || B24(self).b19) {
            lim = -0x2d000;
        }
        if (LFLD(s32, self, 0x74) - LFLD(s32, self, 0xb00) < lim) {
            drop = TRUE;
        }
    }
    return drop;
}

void func_ov000_021a4a6c(u8 *self) {
    u8 *t;
    u8 *sub;
    VecFx32 p1;
    VecFx32 p2;
    VecFx32 o;
    VecFx32 d;
    Msg_021a4a6c m;

    t = NULL;
    sub = NULL;
    if (IsIdle_021a4a6c()) {
        t = FindActor_021a4a6c(LFLD(u16, self, 0x90));
        if (t != NULL && LFLD(u8 *, t, 0x44) != NULL && LFLD(H22_021a4a6c, LFLD(u8 *, t, 0x44), 0x22).b0 == 1 &&
            LFLD(H22_021a4a6c, LFLD(u8 *, t, 0x44), 0x22).b1 == 1) {
            sub = LFLD(u8 *, t, 0x4c);
            if (LFLD(u8, self, 0xb2f) == 0) {
                LFLD(u8, self, 0xb2f)++;
            }
        }
    }
    switch (ST(self)->st) {
    case 0:
        B24(self).b17 = 0;
        if (B2C(self).b4 == 3) {
            VObj *e;
            B24(self).b7 = 2;
            LFLD(u16, self, 0xb36) = 0;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc666, 0x800, 1);
            e = func_02065f88(0x391, self + 0x70);
            e->vfunc_24(0, (LFLD(s32, self, 0x68) >> 1) + (LFLD(s32, self, 0x68) >> 3), 0);
            e->vfunc_0c(0x1333);
            LFLD(s32, e, 0x3c) = 0x2ccd;
            func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
            LFLD(s32, self, 0x9c) = 0;
            LFLD(s32, self, 0xa4) = 0;
        } else if (B22(self).b3) {
            B24(self).b7 = 2;
            LFLD(u16, self, 0xb36) = 0;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc64e, 0x800, 1);
            func_ov000_021911c8(LFLD(void *, self, 0x38), 0x2800);
        } else {
            B24(self).b7 = B24(self).b9;
            if (sub != NULL && LFLD(u8, sub, 0) == 0xf) {
                if ((u16)(LFLD(u16, t, 0xc) & 0xf000) != 0x4000 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
                    B24(self).b7 = 2;
                    LFLD(s32, self, 0x9c) = 0;
                    LFLD(s32, self, 0xa4) = 0;
                }
            }
        }
        switch (B24(self).b7) {
        case 0:
            B24(self).b9 = 1;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc64e, 0x800, 1);
            break;
        case 1:
            B24(self).b9 = 0;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc66c, 0x800, 1);
            break;
        }
        if (B24(self).b12 == 0 && !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            BOOL f;
            if (LFLD(s32, self, 0xa0) < 0 || LFLD(s32, self, 0xa8) == 0) {
                LFLD(s32, self, 0xa8) = 0x29;
            }
            f = FALSE;
            if (!(LFLD(u32, self, 0x30) & 0x80)) {
                s32 dy = LFLD(s32, self, 0x74) - LFLD(s32, LFLD(u8 *, self, 0x48), 0x6c);
                if (dy <= 0 && !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
                    if (LFLD(s32, self, 0xa0) > 0) {
                        LFLD(s32, self, 0xa0) = 0;
                    }
                    f = TRUE;
                } else if (dy > 0x28cd) {
                    f = TRUE;
                }
            }
            if (!f) {
                if (LFLD(s32, self, 0xa0) <= 0) {
                    LFLD(s32, self, 0xa0) = 0x2e;
                } else {
                    LFLD(s32, self, 0xa0) -= LFLD(s32, self, 0xa0) >> 2;
                }
            }
        }
        B2C(self).b0 = 0;
        B2C(self).b1 = 0;
        B2C(self).b2 = 0;
        B2C(self).b3 = 0;
        ST(self)->st++;
        break;
    case 1:
        if (B24(self).b7 == 2) {
            if (!B22(self).b3 && B2C(self).b4 < 3) {
                if (sub != NULL && t != NULL) {
                    LFLD(u16, self, 0x98) = AngleTo_021a4a6c(self, t);
                    if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) && B24(self).b22 == 0) {
                        State_021a4a6c *st;
                        p1 = LFLD(VecFx32, self, 0x70);
                        p1.y -= 0x1000;
                        st = ST(self);
                        st->timer++;
                        if (st->timer < 0x14 && !func_01ffc584(t + 0x70, &p1, (LFLD(s32, t, 0x64) << 1) + 0x1000, 0x4800)) {
                            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc61e, 0x400, 0);
                            func_ov000_021915a0(LFLD(void *, self, 0x38));
                            LFLD(s32, self, 0x9c) = 0x229;
                            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
                            goto end;
                        }
                    }
                }
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc672, 0x800, 1);
                LFLD(s32, self, 0x9c) = 0;
                LFLD(s32, self, 0xa4) = 0;
            }
            if (sub != NULL && B93(self).b4) {
                u8 *q;
                if (!B22(self).b3 && B2C(self).b4 < 3) {
                    func_ov000_02191318(LFLD(void *, self, 0x38), 0x16000);
                }
                q = LFLD(u8 *, t, 0x48);
                if ((u16)(LFLD(u16, t, 0xc) & 0xf000) == 0x5000 && LFLD(u8, sub, 0) == 0xf) {
                    u32 fl = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000;
                    if (fl == 0 || (LFLD(u8, t, 0x92) == 0 && q != NULL && !(LFLD(u32, q, 0x50) & 0x20000000))) {
                        if (B24(self).b22 != 1 && LFLD(u8, t, 0x92) == 0 && fl == 0 && q != NULL && !(LFLD(u32, q, 0x50) & 0x20000000)) {
                            B24(self).b22 = 2;
                        } else {
                            B24(self).b22 = 1;
                        }
                        func_ov000_021911c8(LFLD(void *, self, 0x38), 0x3800);
                        LFLD(s32, self, 0xa8) = 0x29;
                        if (LFLD(s32, self, 0xa0) > 0) {
                            LFLD(s32, self, 0xa0) -= LFLD(s32, self, 0xa0) >> 1;
                        } else {
                            LFLD(s32, self, 0xa0) = 0;
                        }
                        goto next;
                    }
                }
                B24(self).b22 = 0;
                func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1800);
                goto next;
            }
            B24(self).b22 = 0;
        } else {
            B24(self).b22 = 0;
        }
    next:
        ST(self)->timer = 0;
        ST(self)->st++;
    case 2:
        if (B24(self).b7 == 2) {
            func_ov000_0218d988(self, t, 0x400);
        }
        if (B24(self).b5 != 0) {
            break;
        }
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) < 1) {
            break;
        }
        ST(self)->st++;
    case 3:
        if (B24(self).b12 == 0 && LFLD(s32, self, 0xa0) < 0) {
            LFLD(s32, self, 0xa8) = 0x29;
        }
        if (sub != NULL) {
            u8 *h = NULL;
            BOOL ok = FALSE;
            u8 k = LFLD(u8, sub, 0);
            if (B22(self).b3 || B2C(self).b4 == 3) {
                if (k == 0xf || k == 0xe || k == 5) {
                    ok = TRUE;
                }
            } else if ((k == 0xf && B24(self).b7 == 2) || (k == 0xe && B24(self).b7 != 2) || (k == 5 && B24(self).b7 != 2)) {
                ok = TRUE;
            }
            if (ok) {
                h = LFLD(u8 *, t, 0x44);
            }
            if (h != NULL) {
                s32 r;
                BOOL hit;
                p2 = LFLD(VecFx32, self, 0x70);
                p2.y += LFLD(s32, self, 0x6c);
                r = 0x3000;
                if (B22(self).b3) {
                    r += 0x1800;
                }
                if (B2C(self).b4 == 3) {
                    r = 0x7000;
                }
                r += LFLD(s32, self, 0x64);
                if (LFLD(H22_021a4a6c, h, 0x22).b0 == 1 && LFLD(H22_021a4a6c, h, 0x22).b1 == 1) {
                    hit = func_01ffc198(h, &p2, r + LFLD(s32, h, 0x1c));
                } else {
                    hit = FALSE;
                }
                if (hit) {
                    u16 id;
                    func_02049f44(data_02097e4c, 0xc, self + 0x70, 0);
                    if (B24(self).b22 == 0) {
                        func_ov000_02191418(LFLD(void *, self, 0x38), 4, 0);
                    }
                    if (B24(self).b7 == 2) {
                        if (B22(self).b3) {
                            B24(self).b5 = 1;
                        } else if (B2C(self).b4 == 3) {
                            if (k == 0xf) {
                                B24(self).b5 = 2;
                            } else {
                                B24(self).b5 = 1;
                            }
                        } else {
                            B24(self).b5 = 2;
                        }
                    } else {
                        B24(self).b5 = 1;
                    }
                    if (B24(self).b5 == 2 && B24(self).b22 == 0) {
                        func_02049a48(data_02097e4c, 0x302, -1, -1, -1);
                    }
                    id = LFLD(u16, self, 0x90);
                    LFLD(u16, self, 0xb1c) = id;
                    LFLD(u16, self, 0x90) = 0xffff;
                    func_ov000_0218d46c(t, LFLD(u16, self, 0xc), 9);
                    func_ov000_02199b88(sub, self);
                    if (LFLD(S18_021a4a6c, sub, 0x18).b1) {
                        func_02062764(0x3c0, 0x200);
                        func_020627a0(LFLD(u16, t, 0xe), LFLD(u16, t, 0xc));
                        u8 *g = data_ov000_021ccd54;
                        LFLD(u8, g, 0xac) = 1;
                        func_ov000_02182590(g + 0xac);
                    }
                    ST(self)->st = 10;
                    break;
                }
            }
        } else if (B24(self).b22 == 0 && B22(self).b3 && LFLD(G18_021a4a6c, data_0214a424, 0x18).b1 == 1 && LFLD(u16, self, 0xb36) >= 6) {
            func_ov000_02198360(ST(self), 0xf, 0);
            break;
        }
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) == 2 || func_ov000_02191120(LFLD(void *, self, 0x38))) {
            B24(self).b5 = 0;
            LFLD(u16, self, 0xb1c) = 0xffff;
            LFLD(u16, self, 0xb1e) = 0xffff;
            B24(self).b7 = B24(self).b9;
            ST(self)->st = 10;
        }
        break;
    case 10: {
        BOOL done;
        t = FindActor_021a4a6c(LFLD(u16, self, 0xb1c));
        if (t != NULL) {
            sub = LFLD(u8 *, t, 0x4c);
        } else {
            sub = NULL;
        }
        if (!func_ov000_02191120(LFLD(void *, self, 0x38)) && ST(self)->keys == 0) {
            break;
        }
        if (t == NULL) {
            B24(self).b5 = 0;
            LFLD(u16, self, 0xb1c) = 0xffff;
            LFLD(u16, self, 0xb1e) = 0xffff;
            B24(self).b7 = B24(self).b9;
        }
        done = FALSE;
        if (sub != NULL) {
            if (LFLD(u8, sub, 1) == 4) {
                B24(self).b7 = 2;
                func_ov000_02198360(ST(self), 0xd, 0);
                done = TRUE;
            } else {
                if (!B22(self).b3 && B24(self).b5 == 1) {
                    B24(self).b7 = 0;
                }
                if (B24(self).b22 == 0) {
                    LFLD(s32, self, 0xa8) = 0x52;
                } else {
                    func_ov000_02198360(ST(self), 0xb, 0);
                    done = TRUE;
                }
            }
        } else if (B2C(self).b4 < 3) {
            u64 keys = ST(self)->keys;
            if (keys & 0x80) {
                BOOL drop = Falling_021a4a6c(self);
                if (drop) {
                    B24(self).b18 = 1;
                } else {
                    func_ov000_02198360(ST(self), 7, 1);
                    done = TRUE;
                }
                LFLD(u8, self, 0xb2f) = 0;
            } else if (keys & 8) {
                if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
                    func_ov000_02198360(ST(self), 3, 0);
                    done = TRUE;
                }
            }
        }
        if (!done) {
            if (B2C(self).b4 == 3 && sub == NULL) {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0x89, 0);
                ST(self)->timer = 0;
                ST(self)->st++;
            } else {
                func_ov000_02198360(ST(self), 1, 0);
            }
        }
        B2C(self).b4 = 0;
        break;
    }
    case 11: {
        State_021a4a6c *st = ST(self);
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_02198360(ST(self), 1, 0);
        }
        break;
    }
    }
end:
    if (!func_ov000_02191508(LFLD(void *, self, 0x38))) {
        BOOL turned;
        if (B24(self).b7 == 2 && !B22(self).b3) {
            func_ov000_021b1fac(self, FALSE, 1);
        } else {
            s32 spd = LFLD(s32, self, 0xb08) >> 1;
            if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
                spd >>= 2;
            }
            if (spd > 0x252) {
                spd = 0x252;
            }
            func_ov000_021b1dd8(self, spd, 0x200, 0xe00, 0x466, 1);
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
            u8 *a;
            func_ov000_02198360(ST(self), 4, 0);
            a = FindActor2_021a4a6c(LFLD(u16, self, 0xb1c));
            if (a != NULL) {
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
                    LFLD(S18_021a4a6c, LFLD(u8 *, a, 0x4c), 0x18).b0 = 0;
                }
            }
            B24(self).b5 = 0;
            LFLD(u16, self, 0xb1c) = 0xffff;
            LFLD(u16, self, 0xb1e) = 0xffff;
            B24(self).b7 = B24(self).b9;
        }
    }
    if (t == NULL || sub == NULL) {
        return;
    }
    if (LFLD(S18_021a4a6c, sub, 0x18).b4 ? TRUE : FALSE) {
        return;
    }
    if (B22(self).b0 != 0) {
        return;
    }
    {
        s32 c = 0;
        s16 e = 0x1000;
        if (B24(self).b22 == 2 && LFLD(u16, self, 0xb1c) != 0xffff) {
            d = LFLD(VecFx32, t, 0x70);
            d.x -= LFLD(s32, self, 0x70);
            d.y -= LFLD(s32, self, 0x74);
            d.z -= LFLD(s32, self, 0x78);
            d.x = FxMul_021a4a6c(d.x, 0x733);
            d.y = FxMul_021a4a6c(d.y, 0x733);
            d.z = FxMul_021a4a6c(d.z, 0x733);
            d.y = LFLD(s32, self, 0x68);
            VEC_Add(&d, (VecFx32 *)(self + 0x70), &o);
            c = 0x6f33;
            e = 0x2000;
        }
        if (c == 0) {
            return;
        }
        func_ov000_021899d8(&o, 0, c, 1, e, 0x1000);
    }
}

}
