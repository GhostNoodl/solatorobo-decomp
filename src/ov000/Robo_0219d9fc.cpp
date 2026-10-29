#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 3;
    u32 b12 : 2;
    u32 b14 : 6;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} B24_0219d9fc;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219d9fc;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 b6 : 1;
    u16 rest : 9;
} B2C_0219d9fc;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bit0_0219d9fc;

typedef struct {
    u8 b0 : 3;
    u8 b3 : 1;
    u8 rest : 4;
} B28_0219d9fc;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} H0_0219d9fc;

typedef struct {
    u16 b0 : 9;
    u16 b9 : 1;
    u16 rest : 6;
} Pad18_0219d9fc;

typedef struct {
    s32 m[9];
} Mtx33_0219d9fc;

#define B24(self) LFLD(B24_0219d9fc, self, 0xb24)
#define B22(self) LFLD(B22_0219d9fc, self, 0xb22)
#define B2C(self) LFLD(B2C_0219d9fc, self, 0xb2c)
#define B93(self) LFLD(Bit0_0219d9fc, self, 0x93)
#define PAD18 LFLD(Pad18_0219d9fc, data_0214a424, 0x18)
#define VEC(p, off) LFLD(VecFx32, p, off)
#define SIN_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern u8 *data_0214a424;
extern u8 *data_02097d48;
extern u8 data_ov000_021ca320[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_02191ec4(void *a, s32 b, u32 c);
int func_02043d9c(void *p);
void func_ov000_02190758(void *model, void *rot, s32 a);
BOOL func_ov000_021903b4(void *model);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
void func_ov003_021ce9ac(void *p);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void func_ov000_021b4130(void *self, BOOL a);
void MI_Copy36B(const void *src, void *dst);
void func_ov000_021bd7a0(void *p);
void func_ov000_02191c24(void *shadow, void *pos);
void MTX_Identity33_(Mtx33_0219d9fc *m);
void MTX_RotX33_(Mtx33_0219d9fc *m, s32 s, s32 c);
void MTX_RotY33_(Mtx33_0219d9fc *m, s32 s, s32 c);
void MTX_RotZ33_(Mtx33_0219d9fc *m, s32 s, s32 c);
void MTX_Concat33(void *a, void *b, void *c);
void func_ov000_02167fac(void *p, s32 a, s32 b);

static inline u8 *FindActor_0219d9fc(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL IsBusy_0219d9fc(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94);
}

static inline BOOL IsIdle_0219d9fc(u8 *g) {
    if (g != NULL) {
        if (IsBusy_0219d9fc(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u8 Begin_0219d9fc(void) {
    u8 a = LFLD(u8, data_02097d48, 0x8b3);
    func_02043d9c(data_02097d48 + 0x8b0);
    return a;
}

static inline BOOL HasD4_0219d9fc(u8 *g) {
    return LFLD(s32, g, 0xd4) != 0;
}

static inline BOOL HasD4B_0219d9fc(u8 *g) {
    return HasD4_0219d9fc(g) ? TRUE : FALSE;
}

static inline BOOL PadB9_0219d9fc(void) {
    return PAD18.b9 ? TRUE : FALSE;
}

static inline BOOL RgbEq_0219d9fc(u8 *g, u8 *self) {
    BOOL e = FALSE;
    if (g[0xca] == self[0x772] && g[0xcb] == self[0x773] && g[0xcc] == self[0x774]) {
        e = TRUE;
    }
    return e;
}

static inline void Flash_0219d9fc(u8 *m, u16 a, u16 b, s32 n) {
    if (n != 0) {
        LFLD(u16, m, 0xb6) = a;
        LFLD(u16, m, 0xb8) = b;
        LFLD(u16, m, 0xba) = n + 1;
        LFLD(u16, m, 0xbc) = n;
    }
}

BOOL func_ov000_0219d9fc(u8 *self) {
    u32 fl;
    u8 *m;
    u8 v;
    s32 n;
    u8 *a;
    u8 lvl;
    u16 ca;
    u16 cb;
    s32 h;

    if (LFLD(B28_0219d9fc, self, 0xb28).b3) {
        return FALSE;
    }
    func_ov000_02191ec4(LFLD(void *, self, 0x3c), 1, LFLD(u32, LFLD(u8 *, self, 0x48), 0x54));
    m = LFLD(u8 *, self, 0x38);
    v = LFLD(u8, m, 0xbf);
    if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x80000) {
        if (B24(self).b20) {
            if (v > 5) {
                LFLD(u8, m, 0xbf) = v - 3;
            }
        } else {
            LFLD(u8, m, 0xbf) = 5;
            B24(self).b20 = 1;
        }
    } else {
        if (B24(self).b20) {
            if (v < 0x1f) {
                LFLD(u8, m, 0xbf) = v + 1;
            }
        } else {
            LFLD(u8, m, 0xbf) = 0x1f;
            B24(self).b20 = 1;
        }
    }

    lvl = 0x1f;
    {
        u16 w = LFLD(u16, LFLD(u8 *, self, 0x50), 0xa);
        n = 0;
        if (w != 0) {
            if (LFLD(u16, LFLD(u8 *, self, 0x38), 0xba) == 0) {
                u16 k;
                n = 1;
                cb = ca = 0x53ff;
                if (w > 0x3c) {
                    k = w & 0xf;
                } else {
                    k = w & 7;
                    if (w <= 0x1e) {
                        k = w & 3;
                    }
                }
                lvl = 0x1e;
                if (k != 0) {
                    lvl = 0x14;
                }
            }
        } else if (B24(self).b0) {
            cb = ca = 0x3def;
            lvl = 0x1e;
            n = 1;
        } else if (B22(self).b3 && IsIdle_0219d9fc(data_ov000_021ccd54)) {
            if (!(LFLD(u16, data_ov000_021ccd68, 0xa) & 0x3f)) {
                ca = 0x63fc;
                cb = 0x5ad4;
                n = 0x40;
            }
        } else if (B2C(self).b6) {
            if (LFLD(u8, LFLD(u8 *, self, 0x40), 0x13) == 0x16) {
                cb = ca = 0x729c;
                n = 1;
            }
        } else if (B2C(self).b3) {
            cb = ca = 0x7e90;
            n = 1;
        }
    }
    if (n != 0) {
        u8 *fm = LFLD(u8 *, self, 0x38);
        LFLD(u16, fm, 0xb6) = ca;
        LFLD(u16, fm, 0xb8) = cb;
        LFLD(u16, fm, 0xba) = n + 1;
        LFLD(u16, fm, 0xbc) = n;
    }
    LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = lvl;
    if (B24(self).b1) {
        if (B22(self).b0 && LFLD(u8 *, self, 0x998) != NULL) {
            Flash_0219d9fc(LFLD(u8 *, self, 0x998), ca, cb, n);
            LFLD(u8, LFLD(u8 *, self, 0x998), 0xbe) = lvl;
        }
    } else if (B24(self).b21) {
        if (n != 0) {
            LFLD(u16, self, 0x82e) = ca;
            LFLD(u16, self, 0x830) = cb;
            LFLD(u16, self, 0x832) = n + 1;
            LFLD(u16, self, 0x834) = n;
        }
        LFLD(u8, self, 0x836) = lvl;
    }

    {
    s32 res = 0;
    s32 off = LFLD(s32, self, 0x64);
    u8 alpha = Begin_0219d9fc();
    if (B24(self).b2) {
        VEC(self, 0x3e0) = VEC(self, 0x75c);
        func_ov000_02190758(self + 0x368, self + 0x76c, 1);
        LFLD(u8, self, 0x426) = 0x1f;
        LFLD(u8, self, 0x429) = alpha;
        if (func_ov000_021903b4(self + 0x368)) {
            res = 1;
        }
        VEC(self, 0x124) = VEC(self, 0x70);
        func_ov000_02190758(self + 0xac, self + 0x7c, 1);
        LFLD(u8, self, 0x16d) = alpha;
        func_ov000_021903b4(self + 0xac);
        h = LFLD(s32, self, 0x338);
    } else {
    if (B24(self).b1) {
        VecFx32 p;
        if ((u32)(B24(self).b5 - 1) <= 1) {
            s32 f = B24(self).b7;
            if (f == 1) {
                LFLD(u8, self, 0xae4) |= 2;
            } else if (f == 0) {
                LFLD(Bit0_0219d9fc, self, 0xae4).b0 = 1;
            } else {
                LFLD(u8, self, 0xae4) |= 2;
                LFLD(Bit0_0219d9fc, self, 0xae4).b0 = 1;
            }
        }
        if (B22(self).b0) {
            LFLD(u8, self, 0xae4) |= 4;
        }
        if (LFLD(u8, self, 0xae4) != 0) {
            LFLD(void *, self, 0x3b8) = self + 0xa50;
            NNS_G3dRenderObjSetInitFunc(self + 0x38c, (void *)func_ov003_021ce9ac);
            LFLD(u16, self, 0x42a) |= 0x20;
        }
        p = VEC(self, 0x75c);
        if (B24(self).b12) {
            a = FindActor_0219d9fc(LFLD(u16, self, 0xb20));
            u8 *s;
            if (a != NULL && (s = LFLD(u8 *, a, 0x4c)) != NULL) {
                s16 *e = (s16 *)(data_ov000_021ca320 + LFLD(u16, s, 6) * 0x18);
                VecFx32 o;
                o.x = e[1];
                o.y = e[2];
                o.z = e[3];
                VEC_Add(&p, &o, &p);
            }
        }
        VEC(self, 0x3e0) = p;
        func_ov000_02190758(self + 0x368, self + 0x76c, 1);
        LFLD(u8, self, 0x429) = alpha;
        if (func_ov000_021903b4(self + 0x368)) {
            res = 1;
        }
        h = LFLD(s32, self, 0x72c);
        if (!B22(self).b3) {
            off = off * 2 - (off >> 2);
        } else {
            off <<= 1;
        }
        if (B24(self).b5) {
            func_ov000_021b4130(self, res != 0 ? TRUE : FALSE);
        }
    } else {
        if (!PadB9_0219d9fc() && RgbEq_0219d9fc(data_ov000_021ccd54, self)) {
            VEC(self, 0x3e0) = VEC(self, 0x75c);
            func_ov000_02190758(self + 0x368, self + 0x76c, 1);
            LFLD(u8, self, 0x426) = 0x1f;
            LFLD(u8, self, 0x429) = alpha;
            if (B22(self).b0) {
                LFLD(u8, self, 0xae4) |= 4;
                LFLD(void *, self, 0x3b8) = self + 0xa50;
                NNS_G3dRenderObjSetInitFunc(self + 0x38c, (void *)func_ov003_021ce9ac);
                LFLD(u16, self, 0x42a) |= 0x20;
            }
            if (func_ov000_021903b4(self + 0x368)) {
                res = 1;
            }
        } else {
            res = -1;
        }
        if (B24(self).b21) {
            LFLD(Bit0_0219d9fc, self, 0xa4c).b0 = 1;
            LFLD(void *, self, 0xfc) = self + 0x9b8;
            NNS_G3dRenderObjSetInitFunc(self + 0xd0, (void *)func_ov003_021ce9ac);
            LFLD(u16, self, 0x16e) |= 0x20;
        }
        if (!B93(self).b0) {
            VEC(self, 0x124) = VEC(self, 0x70);
            func_ov000_02190758(self + 0xac, self + 0x7c, 1);
        }
        LFLD(u8, self, 0x16d) = alpha;
        if (func_ov000_021903b4(self + 0xac) && B24(self).b21) {
            VEC(self, 0x7f0) = VEC(self, 0x9dc);
            MI_Copy36B(self + 0x9b8, self + 0x7fc);
            LFLD(u8, self, 0x839) = alpha;
            func_ov000_021903b4(self + 0x778);
        }
        h = LFLD(s32, self, 0x338);
        if (B24(self).b5) {
            u8 *a = FindActor_0219d9fc(LFLD(u16, self, 0xb1c));
            if (a != NULL) {
                u8 *s = LFLD(u8 *, a, 0x4c);
                s32 q[3];
                LFLD(u16, s, 0x1c) = LFLD(u16, self, 0xc);
                q[0] = LFLD(s32, self, 0x70);
                q[1] = LFLD(s32, self, 0x74);
                q[2] = LFLD(s32, self, 0x78);
                q[1] += LFLD(s32, self, 0x6c);
                VEC(s, 0x44) = *(VecFx32 *)q;
            }
        }
    }
    {
        u8 *g = data_ov000_021ccd54;
        if (IsIdle_0219d9fc(g) && !HasD4B_0219d9fc(g)) {
            func_ov000_021bd7a0(LFLD(void *, self, 0x5c));
            func_ov000_021bd7a0(LFLD(void *, self, 0x9b0));
            func_ov000_021bd7a0(LFLD(void *, self, 0x9b4));
        }
    }
    }
    fl = LFLD(u32, LFLD(u8 *, self, 0x48), 0x54);
    if ((fl & 0xf0f0f0) != 0xe0e000 && (fl & 0x20000) != 0x20000) {
        LFLD(s32, LFLD(u8 *, self, 0x3c), 0x14) = off;
        LFLD(s32, LFLD(u8 *, self, 0x3c), 0x10) = LFLD(s32, self, 0x74) - h;
        LFLD(u8, LFLD(u8 *, self, 0x3c), 0x1a) = alpha;
        if (B93(self).b0 && !B24(self).b1) {
            VecFx32 w;
            w.x = LFLD(s32, self, 0x124);
            w.y = LFLD(s32, self, 0x128);
            w.z = LFLD(s32, self, 0x12c);
            func_ov000_02191c24(LFLD(void *, self, 0x3c), &w);
        } else {
            func_ov000_02191c24(LFLD(void *, self, 0x3c), self + 0x70);
        }
    }
    if (B22(self).b0 && LFLD(u8 *, self, 0x998) != NULL && res >= 0 && LFLD(H0_0219d9fc, self, 0x42a).b0) {
        if (res != 0) {
            BOOL set;
            u16 rz;
            u16 ry;
            u16 rx;
            Mtx33_0219d9fc mm;
            Mtx33_0219d9fc mt;
            VEC(LFLD(u8 *, self, 0x998), 0x78) = VEC(self, 0xad4);
            ry = LFLD(u16, self, 0x9a8);
            rz = LFLD(u16, self, 0x9aa);
            rx = LFLD(u16, self, 0x9a6);
            set = FALSE;
            MTX_Identity33_(&mm);
            if (ry != 0) {
                MTX_RotY33_(&mm, SIN_0219d9fc(ry), COS_0219d9fc(ry));
                set = TRUE;
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&mt, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotX33_(&mm, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    set = TRUE;
                }
            }
            if (rz != 0) {
                if (set) {
                    MTX_RotZ33_(&mt, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotZ33_(&mm, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                }
            }
            MTX_Concat33(&mm, self + 0xab0, &mm);
            MI_Copy36B(&mm, LFLD(u8 *, self, 0x998) + 0x84);
            LFLD(u8, LFLD(u8 *, self, 0x998), 0xc1) = alpha;
            func_ov000_021903b4(LFLD(u8 *, self, 0x998));
        }
        if (LFLD(u16, self, 0x9ac) < LFLD(u16, self, 0x9ae)) {
            if (B24(self).b1) {
                u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
                if (o != NULL && LFLD(void *, o, 0x6c) != NULL) {
                    func_ov000_02167fac(LFLD(void *, o, 0x6c), LFLD(u16, self, 0x9ac), LFLD(u16, self, 0x9ae));
                }
            }
        }
    }
    }
    return TRUE;
}
}
