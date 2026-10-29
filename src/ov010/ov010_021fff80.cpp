#include "ov010/ov010.h"

struct Ov010Rot {
    u16 v[3];
};

struct Ov010Toggle {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

struct Ov010G54 {
    u8 unk_000[0x1ce];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 4;
    u8 unk_1cf;
    s32 unk_1d0;
    s32 unk_1d4;
    s32 unk_1d8;
    u8 unk_1dc[0xc];
    s32 unk_1e8;
};

extern "C" {

extern u8 data_ov010_0220ebc0[];
extern const Ov010Vec data_ov010_0220ec80;
extern const Ov010Vec data_ov010_0220ec74;
extern u8 data_ov010_0220ef68[];
extern Ov010G54 *data_ov000_021ccd54;
extern void func_ov000_0218a358(void *a, const void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);

static inline void Ov010_SetSky(void) {
    Ov010G54 *g = data_ov000_021ccd54;
    g->unk_1d0 = 0;
    g->unk_1d4 = 0x5580;
    g->unk_1d8 = 0;
    g->b0 = 1;
    g = data_ov000_021ccd54;
    g->unk_1e8 = 0x5c00;
    g->b2 = 2;
}

BOOL func_ov010_021fff80(Ov010Toggle *o) {
    o->b0 = 1;
    o->b1 = 0;
    return TRUE;
}

void func_ov010_021fffa0(void *self) {
    if (FLD(void *, self, 0x44) != NULL) {
        func_ov000_021984f4(FLD(void *, self, 0x44), 0, 0);
    }
}

void func_ov010_021fffc0(void *self) {
    if (FLD(void *, self, 0x48) != NULL) {
        func_ov000_0219864c(FLD(void *, self, 0x48), 0, 0);
    }
}

void func_ov010_021fffe0(void) {
}

void func_ov010_021fffe4(void) {
}

void func_ov010_021fffe8(void) {
}

void func_ov010_021fffec(void) {
}

void func_ov010_021ffff0(void) {
}

void func_ov010_021ffff4(void) {
}

void func_ov010_021ffff8(void) {
}

void func_ov010_021ffffc(Ov010V *self) {
    self->v54();
}

void func_ov010_02200010(Ov010V *self) {
    FLD(Ov010Flags, self, 0xee).b5 = 1;
    self->v70();
}

void func_ov010_02200030(void) {
}

void func_ov010_02200034(void) {
}

void func_ov010_02200038(void) {
}

void func_ov010_0220003c(void) {
}

void func_ov010_02200040(void) {
}

void func_ov010_02200044(void) {
}

BOOL func_ov010_02200048(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    FLD(Ov010Flags8, o, 0).b0 = 1;
    FLD(Ov010Flags8, o, 0).b1 = 0;
    FLD(u8, o, 1) = c;
    FLD(u16, o, 2) = b;
    FLD(u16, o, 4) = d;
    FLD(u16, o, 6) = 0;
    FLD(u16, o, 8) = 0;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(u16, o, 0xe) = 0;
    FLD(u16, o, 0x10) = 0;
    FLD(u16, o, 0x12) = a;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0;
    FLD(s32, o, 0x20) = 0;
    FLD(Ov010Vec, o, 0x24) = FLD(Ov010Vec, data_ov010_0220ef68, 0x24);
    func_ov003_021da48c(o + 0x30, 0);
    return TRUE;
}

}


struct Ov010FxRot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010FxBits {
    u8 lo : 5;
    u8 f : 2;
    u8 hi : 1;
};

struct Ov010FxSw {
    u16 state;
    u8 pad[0x11];
    u8 mode;
};

struct Ov010FxObj {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    u16 unk_12;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    Ov010Vec pos;
    Ov010FxSw sw;
};

extern "C" {

extern u8 data_ov010_0220ef68[];
extern Ov010Vec data_ov010_0220ef8c;
extern void *data_ov000_021ccd68;
extern void *data_0214a420;
extern Ov010V *func_02066774(void *a, void *b, s32 c, Ov010Vec *pos);
extern Ov010V *func_02066900(void *a, void *b, Ov010Vec *pos);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern Ov010V *func_020657b0(void *mgr, s32 h);
extern void func_02065804(void *mgr, s32 h);
extern void func_02065860(void *mgr, s32 h);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void *func_ov000_021985c0(void *p);
extern s32 func_ov000_0219a5c8(void *self, u16 mask, Ov010Vec *pos, Ov010FxRot *rot, s32 r, s32 a, Ov010Vec **list);
extern BOOL func_ov000_0219a8bc(void *hit, void *a, void *b, s32 c, u8 d, Ov010Vec *pos, s16 h, s32 i, s32 scale);

static inline s32 Ov010g_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void *Ov010g_Find(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov010g_Idle(const Ov010FxObj *o) {
    BOOL r = TRUE;
    if (o->b0 && o->sw.mode != 0) {
        r = FALSE;
    }
    return r;
}

void func_ov010_022000d8(Ov010FxObj *o) {
    if (!o->b0) {
        return;
    }
    if (Ov010g_Idle(o)) {
        return;
    }
    o->unk_20 = 0;
    if (o->sw.mode == 1) {
        switch (o->sw.state) {
        case 0: {
            void *m = FLD(void *, data_ov010_0220ef68, 0);
            Ov010V *e;
            e = (Ov010V *)func_02066774(m, FLD(void *, data_ov010_0220ef68, 8), 0, &o->pos);
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0xc8) = -1;
            o->unk_14 = FLD(s32, e, 0x24);
            e = (Ov010V *)func_02066774(m, FLD(void *, data_ov010_0220ef68, 4), 0, &o->pos);
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0xc8) = -1;
            o->unk_18 = FLD(s32, e, 0x24);
            o->unk_08 = 0x80;
            o->sw.state = 0xa;
            break;
        }
        case 0xa: {
            s32 v;
            s32 t;
            void *a;
            o->unk_08 += (s16)Ov010g_FxMul(o->unk_06 - o->unk_08, 0x4cd);
            v = o->unk_08;
            o->unk_08 = (v > o->unk_06) ? o->unk_06 : ((v < 0) ? 0 : v);
            t = o->unk_0c - 1;
            if (t > 0xffff) {
                t = 0xffff;
            } else if (t < 0) {
                t = 0;
            }
            o->unk_0c = t;
            a = Ov010g_Find(o->unk_12);
            if (a != NULL) {
                Ov010Vec *list[32];
                Ov010Vec p;
                Ov010FxRot rot = {0, 0, 0};
                s32 n;
                s32 j;
                rot.x = o->unk_0e + 0x4000;
                rot.y = o->unk_10;
                n = func_ov000_0219a5c8(a, o->unk_04, &o->pos, &rot, Ov010_FxMul(o->unk_08, 0x500), Ov010_FxMul(o->unk_0a, 0xf000), list);
                if (n > 0) {
                    void *b;
                    void *m3 = FLD(void *, data_ov010_0220ef68, 0xc);
                    void *m0 = FLD(void *, data_ov010_0220ef68, 0);
                    j = 0;
                    do {
                        if (list[j] == NULL) {
                            continue;
                        }
                        if (!func_ov000_0219a8bc(list[j], a, a, o->unk_02, o->unk_01, &data_ov010_0220ef8c, -1, o->unk_06, 0x1000)) {
                            continue;
                        }
                        b = func_ov000_021985c0(list[j]);
                        if (b == NULL) {
                            continue;
                        }
                        if (FLD(u8 *, b, 0x4c) != NULL && *FLD(u8 *, b, 0x4c) != 0xb) {
                            continue;
                        }
                        p = *list[j];
                        if (FLD(Ov010FxBits, b, 0x93).f) {
                            Ov010V *e = func_02065f88(0x327, &p);
                            e->v0c(FLD(s32, b, 0x64) << 1);
                        } else {
                            Ov010V *e = func_02066900(m0, m3, &p);
                            e->v14(o->unk_06, o->unk_06, o->unk_06);
                        }
                    } while (++j < n);
                }
            }
            if (!o->b1 && o->unk_0c == 0) {
                o->sw.state = 0x64;
            }
            break;
        }
        case 0x64:
            func_ov000_02198360(&o->sw, 2, 1);
            break;
        }
    } else if (o->sw.mode == 2) {
        switch (o->sw.state) {
        case 0:
        case 1:
            if (o->sw.state == 0) {
                o->unk_20 = 1;
                o->sw.state = 1;
            }
            o->unk_08 = Ov010g_FxMul(o->unk_08, 0xb33);
            if (o->unk_08 < 0x80) {
                o->unk_08 = 0;
                func_02065804(data_0214a420, o->unk_14);
                func_02065804(data_0214a420, o->unk_18);
                o->sw.state = 0x14;
            }
            break;
        case 0xa: {
            Ov010V *e = func_02065f88(0x25d, &o->pos);
            e->v18(&o->pos);
            e->v14(o->unk_06, o->unk_06, o->unk_0a);
            e->v34(0, o->unk_10, 0);
            o->unk_1c = FLD(s32, e, 0x24);
            o->sw.state = 0xb;
            break;
        }
        case 0xb:
            if (func_020657b0(data_0214a420, o->unk_1c) == NULL) {
                o->sw.state = 0x14;
            }
            break;
        case 0x14:
            func_02065860(data_0214a420, o->unk_14);
            func_02065860(data_0214a420, o->unk_18);
            func_02065860(data_0214a420, o->unk_1c);
            o->unk_14 = 0;
            o->unk_18 = 0;
            o->unk_1c = 0;
            func_ov000_02198360(&o->sw, 0, 1);
            break;
        }
    }
    {
    s32 h[2];
    u32 i;
    h[0] = o->unk_14;
    h[1] = o->unk_18;
    for (i = 0; i < 2; i++) {
        Ov010V *e = func_020657b0(data_0214a420, h[i]);
        if (e != NULL) {
            e->v18(&o->pos);
            e->v14(o->unk_08, o->unk_08, o->unk_0a);
            e->v34(o->unk_0e, o->unk_10, 0);
        }
    }
    }
}

}
