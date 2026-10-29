#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 b14 : 2;
    u32 b16 : 2;
    u32 b18 : 1;
    u32 b19 : 7;
    u32 b26 : 1;
    u32 rest : 5;
} B24_0219efc0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 3;
    u16 b9 : 2;
    u16 rest : 5;
} B22_0219efc0;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 2;
    u16 b6 : 1;
    u16 rest : 9;
} B2C_0219efc0;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 2;
    u8 rest : 1;
} B93_0219efc0;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
} B28_0219efc0;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 rest : 7;
} Ba4_0219efc0;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 6;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 rest : 5;
} Pad18_0219efc0;

typedef struct {
    u16 st;
    u16 timer;
    u64 keys;
    u8 pad[7];
    u8 kind;
} State_0219efc0;

#define B24(self) LFLD(B24_0219efc0, self, 0xb24)
#define B22(self) LFLD(B22_0219efc0, self, 0xb22)
#define B2C(self) LFLD(B2C_0219efc0, self, 0xb2c)
#define B93(self) LFLD(B93_0219efc0, self, 0x93)
#define ST(self) LFLD(State_0219efc0 *, self, 0x40)
#define KEYS(self) (ST(self)->keys)
#define PAD18 LFLD(Pad18_0219efc0, data_0214a424, 0x18)

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern u8 *data_0214a424;
extern void *data_02097dc8;
extern void *data_02097e4c;
u8 *func_ov000_0218e640(void *mgr, u16 id);
void *func_ov000_0218e4cc(void *mgr, u16 key);
u16 func_0203d434(void *pad, void *p);
void func_ov000_021b3738(void *self, void *t);
void func_ov000_021b2d48(void *self);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);
void func_02062764(s32 a, s32 b);
BOOL func_ov000_0219b3b4(void *p);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov000_021b1814(void *self, s32 a, s32 b);
BOOL func_ov000_021b3e90(void *self);
void func_ov000_021b1a54(void *self, s32 a);

static inline u8 *FindActor_0219efc0(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL IsBusy_0219efc0(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94);
}

static inline BOOL IsIdle_0219efc0(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_0219efc0(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL HasD4_0219efc0(u8 *g) {
    return LFLD(s32, g, 0xd4) != 0;
}

static inline void TogglePad_0219efc0(void) {
    if (PAD18.b10) {
        PAD18.b10 = 0;
    } else {
        PAD18.b10 = 1;
    }
}

static inline void LockKeys_0219efc0(u8 *self) {
    u32 m = B24(self).b12;
    if (m != 3) {
        if (B2C(self).b4 == 0 || m == 1) {
            KEYS(self) |= 0x80;
        }
    } else {
        KEYS(self) |= 0x4000;
    }
}

static inline void Gauge_0219efc0(s32 a, s32 b, VecFx32 *p) {
    u8 *o = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (o == NULL) {
        return;
    }
    if (LFLD(void *, o, 0x70) == NULL) {
        return;
    }
    func_ov000_02168e18(LFLD(void *, o, 0x70), a, b, p);
}

static inline BOOL RgbEq_0219efc0(u8 *g, u8 *self) {
    BOOL e = FALSE;
    if (g[0xca] == self[0x772] && g[0xcb] == self[0x773] && g[0xcc] == self[0x774]) e = TRUE;
    return e;
}

static inline BOOL Ready_0219efc0(u8 *g) {
    if (IsBusy_0219efc0(g)) return FALSE;
    if (LFLD(s32, g, 0) != 3) return FALSE;
    return TRUE;
}
static inline BOOL IsIdleG_0219efc0(u8 *g) {
    if (g != NULL) {
        return Ready_0219efc0(g);
    }
    return TRUE;
}

static inline BOOL NotB1_0219efc0(u8 *self) {
    return !B24(self).b1;
}

static inline BOOL PadB9_0219efc0(void) {
    return PAD18.b9 ? TRUE : FALSE;
}

static inline BOOL CanMove_0219efc0(u8 *self) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = IsIdleG_0219efc0(g);
    if (r) {
        r = !LFLD(B28_0219efc0, self, 0xb29).b1;
    }
    if (r) {
        r = LFLD(u8, self, 0xb28) == 0;
    }
    if (r) {
        r = LFLD(u8, self, 0xb2e) == 0;
    }
    if (r) {
        r = !B24(self).b0;
    }
    if (r) {
        r = !LFLD(B28_0219efc0, self, 0xb29).b3;
    }
    if (r) {
        r = !NotB1_0219efc0(self);
        if (!r) {
            BOOL t = PadB9_0219efc0();
            r = !t;
            if (!t) {
                r = RgbEq_0219efc0(g, self);
            }
            if (r) {
                r = B24(self).b14 == 0;
            }
        }
    }
    return r;
}

void func_ov000_0219efc0(u8 *self) {
    u8 *p;
    u8 *t9;
    BOOL x;

    LFLD(u16, self, 0xb68) = 0;
    LFLD(u16, self, 0xb6a) = 0;
    LFLD(u16, self, 0xb6c) = 0;
    LFLD(u16, self, 0xb6e) = 0;
    if (!IsIdle_0219efc0()) {
        return;
    }
    if (HasD4_0219efc0(data_ov000_021ccd54)) {
        return;
    }
    if (B24(self).b0 || B24(self).b12 == 2) {
        LFLD(u16, self, 0x90) = 0xffff;
        B24(self).b4 = 0;
        func_ov000_021b3738(self, NULL);
        return;
    }
    if (!LFLD(B28_0219efc0, self, 0xb29).b1 && !LFLD(B28_0219efc0, self, 0xb28).b2 && LFLD(u8, self, 0xb2e) == 0 &&
        !LFLD(B28_0219efc0, self, 0xb29).b3) {
        LFLD(u16, self, 0xb68) = LFLD(u16, data_02097dc8, 0x10);
        LFLD(u16, self, 0xb6a) = LFLD(u16, data_02097dc8, 0x12);
        LFLD(u16, self, 0xb6c) = LFLD(u16, data_02097dc8, 0x14);
        LFLD(u16, self, 0xb6e) = func_0203d434(data_02097dc8, self + 0xb70);
    }
    if ((LFLD(u16, self, 0xb68) & 1) && !B24(self).b18) {
        LFLD(u16, self, 0xb36)++;
        if (LFLD(u16, self, 0xb36) > 9999) {
            LFLD(u16, self, 0xb36) = 9999;
        }
    } else {
        LFLD(u16, self, 0xb36) = 0;
    }
    if (B22(self).b6 == 5) {
        if ((LFLD(u16, self, 0xb6a) & 1) || ((LFLD(u16, self, 0xb68) & 1) && LFLD(u16, self, 0xb36) >= 0xc)) {
            KEYS(self) |= 0x4000;
        }
        if (LFLD(u16, self, 0xb68) & 0xf0) {
            KEYS(self) |= 4;
        }
        if (LFLD(u16, self, 0xb6a) & 4) {
            TogglePad_0219efc0();
        }
        return;
    }
    func_ov000_021b2d48(self);
    p = LFLD(u8 *, self, 0xba4);
    if (p != NULL && B24(self).b1 && B24(self).b12 == 0) {
        if (LFLD(Ba4_0219efc0, p, 6).b4) {
            if (LFLD(u16, self, 0xb1c) == 0xffff && (u8)(ST(self)->kind + 0xff) <= 1) {
                u16 n = LFLD(u16, self, 0xb36);
                if (n == 0) {
                    if (B2C(self).b4 != 0) {
                        u8 *a = FindActor_0219efc0(LFLD(u16, self, 0x90));
                        u8 *i = NULL;
                        s32 k;
                        if (a != NULL) {
                            i = LFLD(u8 *, a, 0x4c);
                        }
                        k = 0;
                        if (i != NULL) {
                            k = i[0];
                        }
                        switch (k) {
                        default:
                            KEYS(self) |= 0x80;
                            break;
                        case 0x11:
                        case 0x12:
                        case 0x13:
                        case 0x14:
                            KEYS(self) |= 0x1000000;
                            break;
                        }
                        if (B2C(self).b4 < 2) {
                            B2C(self).b4 = 0;
                        } else {
                            B2C(self).b4 = 3;
                        }
                    }
                } else {
                    if (n >= 0x28) {
                        B2C(self).b4 = 2;
                        n = 0x28;
                    } else if (n >= 10) {
                        B2C(self).b4 = 1;
                    }
                    if (B2C(self).b4 != 0) {
                        VecFx32 z;
                        z.x = 0;
                        z.y = 0;
                        z.z = 0;
                        Gauge_0219efc0(n - 10, 0x1e, &z);
                    }
                }
            } else if (B2C(self).b4 < 3 || (ST(self)->kind != 7 && ST(self)->kind != 0x18)) {
                B2C(self).b4 = 0;
            }
        }
        if (B93(self).b5 != 2) {
            B93(self).b5 = 0;
            p = LFLD(u8 *, self, 0xba4);
            if (LFLD(Ba4_0219efc0, p, 6).b8 && LFLD(u16, self, 0xb36) >= 8 && LFLD(u16, self, 0xb1c) == 0xffff) {
                B93(self).b5 = 1;
                if (!LFLD(Ba4_0219efc0, p, 6).b4) {
                    KEYS(self) |= 0x10000000;
                }
            }
        }
    } else {
        B2C(self).b4 = 0;
        B2C(self).b6 = 0;
        B93(self).b5 = 0;
    }
    if (B22(self).b3 && LFLD(u16, self, 0xb36) != 0 && PAD18.b1 == 1 && LFLD(u16, self, 0xb1c) == 0xffff &&
        LFLD(u16, self, 0x90) == 0xffff && (u8)(ST(self)->kind + 0xff) <= 1) {
        KEYS(self) |= 0x80;
    }
    if (LFLD(u16, self, 0xb6a) & 1) {
        u8 *a;
        u8 *i;
        t9 = FindActor_0219efc0(LFLD(u16, self, 0x90));
        if (t9 != NULL) {
            func_02062764(0x3c0, 0x40);
        }
        a = NULL;
        if (B24(self).b5 && B24(self).b1) {
            u8 *i;
            a = FindActor_0219efc0(LFLD(u16, self, 0xb1c));
            i = NULL;
            if (a != NULL) {
                i = LFLD(u8 *, a, 0x4c);
            }
            if (i == NULL || LFLD(u16, i, 0x1c) != LFLD(u16, self, 0xc)) {
                B24(self).b5 = 0;
                LFLD(u16, self, 0xb1c) = 0xffff;
                LFLD(u16, self, 0xb1e) = 0xffff;
                B24(self).b7 = B24(self).b9;
                a = NULL;
            }
        }
        i = NULL;
        if (a != NULL) {
            u8 *j = LFLD(u8 *, a, 0x4c);
            if (j != NULL) {
                switch (j[1]) {
                case 1:
                    KEYS(self) |= 0x800;
                    break;
                case 2:
                    KEYS(self) |= 0x1000;
                    break;
                case 4:
                    KEYS(self) |= 0x2000;
                    break;
                case 5:
                    if (!B22(self).b3) {
                        KEYS(self) |= 0x4000;
                    } else {
                        KEYS(self) |= 0x800;
                    }
                    break;
                case 6:
                    if (FindActor_0219efc0(LFLD(u16, self, 0x90)) != NULL) {
                        KEYS(self) |= 0x40;
                    } else {
                        KEYS(self) |= 0x1000;
                    }
                    break;
                }
            }
        } else {
            if (t9 != NULL) {
                i = LFLD(u8 *, t9, 0x4c);
            }
            if (i != NULL) {
                BOOL hold = (LFLD(u32, self, 0x30) & 0x80) ? TRUE : FALSE;
                switch (i[0]) {
                case 3:
                    if (!hold) {
                        KEYS(self) |= 0x20;
                    }
                    break;
                case 4:
                case 6:
                case 12:
                case 13:
                    if (!hold) {
                        KEYS(self) |= 0x40;
                    }
                    break;
                case 5:
                    if (B24(self).b1) {
                        LockKeys_0219efc0(self);
                    } else if (!hold) {
                        KEYS(self) |= 0x100;
                    }
                    break;
                case 7:
                    if (!hold) {
                        KEYS(self) |= 0x100;
                    }
                    break;
                case 14:
                case 15:
                    if (!B24(self).b1 && ((LFLD(u16, t9, 0xe) >> 12) == 5 || i[2] == 1 || func_ov000_0219b3b4(i))) {
                        KEYS(self) |= 0x10000;
                    } else if (B24(self).b12 != 3) {
                        if (B2C(self).b4 == 0) {
                            KEYS(self) |= 0x80;
                        }
                    } else {
                        KEYS(self) |= 0x4000;
                    }
                    break;
                case 17:
                case 19:
                    if (!B24(self).b1 && ((LFLD(u16, t9, 0xe) >> 12) == 5 || func_ov000_0219b3b4(i))) {
                        KEYS(self) |= 0x10000;
                        break;
                    }
                case 18:
                case 20:
                    if (B24(self).b12 == 0 && B2C(self).b4 == 0) {
                        KEYS(self) |= 0x1000000;
                    }
                    break;
                case 11:
                    KEYS(self) |= 0x10000;
                    break;
                case 8:
                case 16:
                    KEYS(self) |= 0x20000000;
                    break;
                case 9:
                case 10:
                    KEYS(self) |= 0x40000000;
                    break;
                }
            } else if (B24(self).b1) {
                LockKeys_0219efc0(self);
            } else if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
                if (B93(self).b4 || LFLD(u16, func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 0x16) != 0) {
                    KEYS(self) |= 0x10000;
                }
            }
        }
    }
    if (LFLD(u16, self, 0xb68) & 2) {
        if (B24(self).b12 != 3) {
            LFLD(u16, self, 0xb38)++;
            if (LFLD(u16, self, 0xb38) > 9999) {
                LFLD(u16, self, 0xb38) = 9999;
            }
            if (LFLD(u16, self, 0xb6a) & 2) {
                KEYS(self) |= 8;
            }
            if (B24(self).b1) {
                if (B22(self).b0 != 0 && !B24(self).b18) {
                    KEYS(self) |= 0x2000000;
                }
                p = LFLD(u8 *, self, 0xba4);
                if (p != NULL && B24(self).b12 == 0) {
                    if ((LFLD(Ba4_0219efc0, p, 6).b7 && ST(self)->kind == 4 &&
                         !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) && LFLD(u16, self, 0xb38) >= 10) ||
                        (LFLD(Ba4_0219efc0, p, 6).b6 && ST(self)->kind != 3 && LFLD(u16, self, 0xb38) > 6 &&
                         (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000))) {
                        KEYS(self) |= 8;
                    }
                }
            }
        }
    } else {
        LFLD(u16, self, 0xb38) = 0;
    }
    if (LFLD(u16, self, 0xb6a) & 0x800) {
        if (B24(self).b1) {
            if (B24(self).b5 == 0 && B24(self).b12 == 0 && !B22(self).b3 && B22(self).b9 == 0) {
                KEYS(self) |= 0x8000000;
            }
        } else if (B24(self).b4) {
            KEYS(self) |= 0x4000000;
        }
    }
    if ((LFLD(u16, self, 0xb68) & 0x200) && (LFLD(u16, self, 0xb6a) & 0x100) && PAD18.b1 == 1 && !B22(self).b3 &&
        B22(self).b9 == 0 && B24(self).b1 && B93(self).b4 && !LFLD(B28_0219efc0, self, 0xb29).b3 && B22(self).b0 == 0 &&
        B24(self).b12 == 0 && ST(self)->kind != 0x11 && (ST(self)->kind != 0xb || !B24(self).b26) &&
        LFLD(u16, data_0214a424, 0x26) >= 0x2d0) {
        func_02049a48(data_02097e4c, 0x30b, -1, -1, -1);
        func_ov000_021b1814(self, 1, 0);
    }
    x = FALSE;
    if (B22(self).b0 != 0 && CanMove_0219efc0(self)) {
        if ((LFLD(u16, self, 0xb6a) & 4) && B24(self).b1) {
            TogglePad_0219efc0();
        }
        if (B22(self).b0 != 3 && B22(self).b0 != 4) {
            x = func_ov000_021b3e90(self);
        }
    }
    if (!x && B24(self).b12 == 0 && (LFLD(u16, self, 0xb68) & 0xf0)) {
        KEYS(self) |= 4;
    }
    if (!B22(self).b3) {
        return;
    }
    if (B22(self).b4) {
        return;
    }
    if (LFLD(B28_0219efc0, self, 0xb29).b3) {
        return;
    }
    if (B24(self).b0) {
        return;
    }
    if (ST(self)->kind == 0xb && B24(self).b26) {
        return;
    }
    {
        u16 v = LFLD(u16, data_0214a424, 0x26);
        if (v != 0) {
            v--;
            LFLD(u16, data_0214a424, 0x26) = v;
        }
        if (v != 0 && B93(self).b4) {
            return;
        }
    }
    func_ov000_021b1a54(self, 1);
}
}
