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
    u32 b18 : 4;
    u32 b22 : 2;
    u32 b24 : 2;
    u32 b26 : 1;
    u32 rest : 5;
} B24_021a6280;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 3;
    u16 b7 : 3;
    u16 rest : 6;
} B2C_021a6280;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a6280;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} B93_021a6280;

typedef struct {
    u8 b0 : 7;
    u8 b7 : 1;
} A93_021a6280;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B2A_021a6280;

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
    u16 b0 : 1;
    u16 b1 : 2;
    u16 rest : 13;
} G18_021a6280;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib_021a6280;

typedef struct {
    u16 st;
    u16 timer;
} State_021a6280;

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

#define B24(self) LFLD(B24_021a6280, self, 0xb24)
#define B2C(self) LFLD(B2C_021a6280, self, 0xb2c)
#define B22(self) LFLD(B22_021a6280, self, 0xb22)
#define B93(self) LFLD(B93_021a6280, self, 0x93)
#define BA4(self) LFLD(Ba4_021a6280, LFLD(u8 *, self, 0xba4), 6)
#define ST(self) LFLD(State_021a6280 *, self, 0x40)

#define SQRTCNT_021a6280 (*(volatile u16 *)0x40002b0)
#define SQRT_RESULT_021a6280 (*(volatile u32 *)0x40002b4)
#define SQRT_PARAM_021a6280 (*(volatile u64 *)0x40002b8)

extern "C" {
extern char data_ov000_021cc68a[];
extern char data_ov000_021cc690[];
extern char data_ov000_021cc5e3[];
extern Def_021a6280 data_ov000_021c9fe8;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd68;
extern u8 *data_0214a424;
u8 *func_ov000_0218d240(u8 *self);
void *func_ov000_0218e640(void *mgr, u16 id);
u16 func_ov000_0218d8f4(void *self, void *target);
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
u16 func_0204bfa8(void *cam);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
s32 func_02040498(s32 max);
void func_ov000_0218996c(s32 a, s32 b);
void func_ov000_021899d8(VecFx32 *a, s32 b, s32 c, s32 d, s16 e, s16 f);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
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
    return func_0204bfa8(cam);
}

static inline u8 *FindActor_021a6280(u16 id) {
    u8 *r;
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    r = (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
    return r;
}

static inline u16 AngleTo_021a6280(u8 *self, u8 *other) {
    if (other == NULL || other == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, other, 0x78) - LFLD(s32, self, 0x78));
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

void func_ov000_021a6280(u8 *self) {
    BOOL busy;
    u16 ang;
    u8 *a;
    u8 *sub;
    u8 *t;
    VecFx32 p;
    VecFx32 d;
    VecFx32 o;
    Msg_021a6280 m;
    VecFx32 v;

    a = FindActor_021a6280(LFLD(u16, self, 0xb1c));
    B24(self).b26 = 0;
    sub = NULL;
    busy = FALSE;
    if (a != NULL) {
        sub = LFLD(u8 *, a, 0x4c);
        if ((u16)(LFLD(u16, a, 0xc) & 0xf000) == 0x5000 && LFLD(u16 *, a, 0x50) != NULL) {
            if (*LFLD(u16 *, a, 0x50) == 0) {
                B24(self).b26 = 1;
            } else {
                busy = TRUE;
            }
        }
    }
    switch (ST(self)->st) {
    case 0:
        if (!B93(self).b4) {
            B24(self).b22 = 0;
        }
        if (!busy) {
            B24(self).b22 = 0;
        }
        if (B24(self).b5 == 1) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc68a, 0x555, 0);
            B24(self).b7 = 0;
            if (B22(self).b3 && B93(self).b4) {
                func_ov000_02191318(LFLD(void *, self, 0x38), 0x14000);
                func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1800);
            } else if (B24(self).b22 != 0) {
                func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1800);
            }
        } else {
            LFLD(u8, self, 0xb2b) = 0;
            B2C(self).b0 = 0;
            B2C(self).b1 = 0;
            B2C(self).b2 = 0;
            B2C(self).b3 = 0;
            B2C(self).b7 = 0;
            if (LFLD(u8 *, self, 0xba4) != NULL && B24(self).b22 != 0) {
                if (BA4(self).b0 && (LFLD(u16, self, 0xb68) & 0xf0) && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) &&
                    (!BA4(self).b2 || (LFLD(u16, self, 0xb68) & 0x30))) {
                    B2C(self).b0 = true;
                    func_ov000_02198360(ST(self), 0x11, 0);
                    goto end;
                }
                if (BA4(self).b2 && (LFLD(u16, self, 0xb68) & 0xf0) && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
                    B2C(self).b2 = 1;
                    func_ov000_02198360(ST(self), 0x11, 0);
                    goto end;
                }
                if (BA4(self).b1 && (LFLD(u16, self, 0xb68) & 0xf0) && !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
                    B2C(self).b1 = 1;
                    func_ov000_02198360(ST(self), 0x11, 0);
                    if (B24(self).b22 >= 2 && LFLD(u8, sub, 0x1a) >= 3) {
                        LFLD(B2A_021a6280, self, 0xb2a).b0 = true;
                    }
                    goto end;
                }
            }
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc690, 0x400, 0);
            if (B93(self).b4) {
                if (B24(self).b22 != 0) {
                    func_ov000_021911c8(LFLD(void *, self, 0x38), 0x3000);
                } else {
                    func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1800);
                }
            }
        }
        if (B24(self).b22 != 0) {
            s32 se;
            s32 lvl = 0;
            VObj *e;
            func_ov000_02191418(LFLD(void *, self, 0x38), 0x14, lvl);
            se = 0x194;
            if (B24(self).b22 >= 2 && sub != NULL) {
                if (LFLD(u8, sub, 0x1a) == 2) {
                    se += 1;
                    lvl = 2;
                } else if (LFLD(u8, sub, 0x1a) >= 3) {
                    lvl = LFLD(u8, sub, 0x1a);
                    se += 2;
                    LFLD(B2A_021a6280, self, 0xb2a).b0 = true;
                }
            }
            func_02049bdc(data_02097e4c, 0x44, lvl);
            e = func_02065f88(se, self + 0x70);
            LFLD(s32, e, 0x3c) = 0x1400;
            e->vfunc_24(0, LFLD(s32, self, 0x6c), 0);
            {
                u32 sc = 0xe66;
                if (B24(self).b22 < 2) {
                    sc >>= 1;
                }
                e->vfunc_0c(sc);
            }
            if (!B22(self).b3 && LFLD(G18_021a6280, data_0214a424, 0x18).b1 == 1) {
                u16 n = 0xc;
                if (sub != NULL) {
                    n += (u16)(LFLD(u8, sub, 0x1a) << 1);
                }
                if (LFLD(u8 *, self, 0xba4) != NULL) {
                    n += LFLD(Nib_021a6280, LFLD(u8 *, self, 0xba4), 5).hi;
                }
                func_ov003_021cedf4(n);
            }
        } else if (B24(self).b26) {
            func_ov000_02191418(LFLD(void *, self, 0x38), 0x32, 0);
            func_02049a48(data_02097e4c, 0x30c, -1, -1, -1);
            func_02067120();
        }
        if (B24(self).b12 == 0) {
            if (LFLD(s32, self, 0x9c) > 0x229) {
                LFLD(s32, self, 0x9c) = 0x229;
            }
            if (LFLD(s32, self, 0xa0) < 0x5c) {
                LFLD(s32, self, 0xa0) = 0x5c;
            }
            LFLD(s32, self, 0xa0) -= LFLD(s32, self, 0xa0) >> 1;
            LFLD(s32, self, 0xa8) = 10;
            LFLD(s32, self, 0xa4) = 0xe66;
        }
        ST(self)->st++;
        break;
    case 1:
        t = func_ov000_0218d240(self);
        if (t != NULL) {
            if (LFLD(void *, t, 0x44) != NULL) {
                ang = func_ov000_0218d8f4(self, LFLD(void *, t, 0x44));
            } else {
                ang = AngleTo_021a6280(self, t);
            }
        } else if (B24(self).b12 == 0) {
            ang = LFLD(u16, self, 0x7e);
            if (LFLD(u8, self, 0x15) == 1 && (LFLD(u16, self, 0xb68) & 0xf0)) {
                ang = LFLD(u16, self, 0xb6e) + CamYaw_021a6280(data_ov000_021ccd54 + 0xf4);
            }
        } else {
            ang = LFLD(u16, self, 0x7e);
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x59a, 1, 0x8000);
        B2C(self).b3 = 0;
        if (B24(self).b22 != 0 && LFLD(u8 *, self, 0xba4) != NULL && BA4(self).b3 && (LFLD(u16, self, 0xb6a) & 1) &&
            B2C(self).b7 < 5 && sub != NULL) {
            VObj *e;
            p.x = LFLD(s32, sub, 0x44);
            p.y = LFLD(s32, sub, 0x48);
            p.z = LFLD(s32, sub, 0x4c);
            e = func_02065f88(0x69, &p);
            LFLD(s32, self, 0xb48) = LFLD(s32, e, 0x24);
            LFLD(u16, self, 0xb5e) = 0x7b;
            LFLD(s32, self, 0xb4c) = p.x - LFLD(s32, self, 0x70);
            LFLD(s32, self, 0xb50) = p.y - LFLD(s32, self, 0x74);
            LFLD(s32, self, 0xb54) = p.z - LFLD(s32, self, 0x78);
            LFLD(u16, self, 0xb58) = 0;
            LFLD(u16, self, 0xb5a) = 0;
            LFLD(u16, self, 0xb5c) = 0;
            e->vfunc_0c(0x800);
            LFLD(s32, e, 0x3c) = 0x2800;
            func_ov000_0218996c(5, 6);
            func_02049a48(data_02097e4c, 0x7a, -1, -1, -1);
            B2C(self).b3 = 1;
            B2C(self).b7++;
        }
        if (LFLD(s16, LFLD(u8 *, self, 0x38), 0xc4) == 1) {
            if (B24(self).b5 != 0 && a != NULL) {
                u8 *s2;
                func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xb);
                if (a != NULL) {
                    if (LFLD(VecFx32 *, a, 0x48) != NULL) {
                        v = *LFLD(VecFx32 *, a, 0x48);
                    } else {
                        v = LFLD(VecFx32, a, 0x70);
                    }
                    if (func_01ffbd6c((VecFx32 *)(self + 0x70), &v, -1, 0, 0, -1) != -0x1000) {
                        v.x -= LFLD(s32, self, 0x70);
                        v.y -= LFLD(s32, self, 0x74);
                        v.z -= LFLD(s32, self, 0x78);
                        VEC_MultAdd(0xc00, &v, (VecFx32 *)(self + 0x70), &v);
                        m.pos = v;
                        *(Rot_021a6280 *)m.rot = LFLD(Rot_021a6280, a, 0x7c);
                        m.x = 0;
                        func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, TRUE, 0x18, &m);
                    }
                }
                LFLD(u16, a, 0x7e) = ang;
                LFLD(u16, self, 0x7e) = ang;
                if (LFLD(A93_021a6280, a, 0x93).b7) {
                    LFLD(u16, a, 0x90) = LFLD(u16, self, 0x90);
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
                        dx = LFLD(s32, self, 0x70) - tp.x;
                        dz = LFLD(s32, self, 0x78) - tp.z;
                        sq = (s64)dx * dx;
                        sq += (s64)dz * dz;
                        SQRTCNT_021a6280 = 1;
                        SQRT_PARAM_021a6280 = (u64)(sq * 4);
                        while (SQRTCNT_021a6280 & 0x8000) {
                        }
                        x = (s32)(SQRT_RESULT_021a6280 + 1) >> 1;
                        h = LFLD(s32, self, 0x74) + LFLD(s32, self, 0x68);
                        if (B22(self).b3) {
                            h += 0x333;
                        }
                        y = tp.y - h;
                    } else if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) &&
                               LFLD(s32, self, 0x74) - LFLD(s32, LFLD(u8 *, self, 0x48), 0x6c) >= 0x159a) {
                        x = 0x2000;
                        y = -0x2000;
                    } else if (B24(self).b22 != 0 || B24(self).b26) {
                        x = 0x1800;
                        y = -0xc00;
                    }
                    if (B24(self).b12 != 0) {
                        z = LFLD(s32, self, 0x9c);
                        LFLD(S18_021a6280, s2, 0x18).b2 = 1;
                    }
                    LFLD(s32, s2, 0x50) = x;
                    LFLD(s32, s2, 0x54) = y;
                    LFLD(s32, s2, 0x58) = z;
                    LFLD(S18_021a6280, s2, 0x18).b0 = 0;
                    if (B24(self).b22 != 0) {
                        u8 lv = 0;
                        u8 n;
                        if (LFLD(u8 *, self, 0xba4) != NULL && BA4(self).b3) {
                            lv = B2C(self).b7 << 1;
                        }
                        LFLD(u8, s2, 0x19) = B24(self).b22;
                        LFLD(u8, s2, 0x1b) = lv;
                        n = func_ov003_021cee68();
                        if (B24(self).b22 < 2) {
                            n--;
                        }
                        se = LFLD(u8, s2, 0x1a) >= n ? 0x307 : 0x306;
                    } else {
                        se = B24(self).b26 ? 0x30d : 0x305;
                    }
                    if (se >= 0) {
                        func_02049a48(data_02097e4c, se, -1, -1, -1);
                    }
                    if (B24(self).b22 != 0 || B24(self).b26) {
                        if (RgbEq_021a6280((Rgb_021a6280 *)(data_ov000_021ccd54 + 0xca), data_ov000_021c9fe8.rgb)) {
                            func_02049bdc(data_02097e4c, 0x5e, func_02040498(3));
                        }
                    }
                }
            }
            B24(self).b5 = 0;
            LFLD(u16, self, 0xb1c) = 0xffff;
            LFLD(u16, self, 0xb1e) = 0xffff;
            B24(self).b7 = B24(self).b9;
            LFLD(u16, self, 0x90) = 0xffff;
            if (B93(self).b4) {
                func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1400);
            }
            LFLD(s32, self, 0xa8) = 0x29;
            B2C(self).b3 = 0;
            ST(self)->st++;
        }
    case 2:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0x200, 0);
            ST(self)->st++;
            ST(self)->timer = 0;
            LFLD(s32, self, 0xa4) = 0x800;
        }
        break;
    case 3: {
        State_021a6280 *st = ST(self);
        st->timer++;
        if (st->timer > 6) {
            LFLD(s32, self, 0xa8) = 0x52;
            func_ov000_02198360(ST(self), 1, 0);
        }
        break;
    }
    }
end:
    if (!func_ov000_02191508(LFLD(void *, self, 0x38))) {
        func_ov000_021b1fac(self, FALSE, 0);
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
    if (B24(self).b22 >= 2 || B24(self).b26) {
        if (a != NULL) {
            d = LFLD(VecFx32, a, 0x70);
            d.x -= LFLD(s32, self, 0x70);
            d.y -= LFLD(s32, self, 0x74);
            d.z -= LFLD(s32, self, 0x78);
            d.x = FxMul_021a6280(d.x, 0x733);
            d.y = FxMul_021a6280(d.y, 0x733);
            d.z = FxMul_021a6280(d.z, 0x733);
            d.y = LFLD(s32, self, 0x68);
            VEC_Add(&d, (VecFx32 *)(self + 0x70), &o);
            func_ov000_021899d8(&o, 0, 0x8ccd, 1, 0x2333, 0x1000);
        }
    }
}

}
