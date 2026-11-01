#include "ov010/ov010.h"

typedef s16 fx16;
typedef Ov010Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// A header's zero rotation and vector, plus copies made at startup, next to this TU's effect
// names and the pointers to them. Other functions read the first pointer, an offset, the zero
// vector and the rotation copy.
// The functions of 0x021fff80..0x0220166c (six files, merged in round dtB, each in its own namespace)
// are part of this TU: they read its name pointers and vectors through the section base plus an
// offset, and now name them (data_ov010_0220ef6c/ef70/ef74, the static sinit copy 0x0220fd90)
// instead of FLD views of data_ov010_0220ef68/fd70.
extern const char *const data_ov010_0220ef68;
extern const VecFx32 data_ov010_0220ef80;
extern const VecFx32 data_ov010_0220ef8c;
extern const VecFx16 data_ov010_0220fd70;
extern char data_ov010_0220fd76[];
extern char data_ov010_0220fd82[];
extern char data_ov010_0220fd9c[];
extern char data_ov010_0220fdab[];
static const char *const data_ov010_0220ef74 = data_ov010_0220fdab;
static const char *const data_ov010_0220ef70 = data_ov010_0220fd82;
static const char *const data_ov010_0220ef6c = data_ov010_0220fd76;
const char *const data_ov010_0220ef68 = data_ov010_0220fd9c;
static const VecFx16 data_ov010_0220ef78 = {0, 0, 0};
const VecFx32 data_ov010_0220ef80 = {0, FX32_ONE, 0};
const VecFx32 data_ov010_0220ef8c = {0, 0, 0};
const VecFx16 data_ov010_0220fd70 = data_ov010_0220ef78;
char data_ov010_0220fd76[] = "ef3di1cas10";
char data_ov010_0220fd82[] = "ef3di1cas11";
static const VecFx32 data_ov010_0220fd90 = data_ov010_0220ef8c;

// ---- merged from ov010_021fff80.cpp
namespace m_021fff80 {
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

extern const Ov010Vec data_ov010_0220ec80;
extern const Ov010Vec data_ov010_0220ec74;
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
    FLD(Ov010Vec, o, 0x24) = data_ov010_0220ef8c;
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

extern void *data_ov000_021ccd68;
extern void *data_0214a420;
extern Ov010V *func_02066774(const char *a, const char *b, s32 c, Ov010Vec *pos);
extern Ov010V *func_02066900(const char *a, const char *b, Ov010Vec *pos);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern Ov010V *func_020657b0(void *mgr, s32 h);
extern void func_02065804(void *mgr, s32 h);
extern void func_02065860(void *mgr, s32 h);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void *func_ov000_021985c0(void *p);
extern s32 func_ov000_0219a5c8(void *self, u16 mask, Ov010Vec *pos, Ov010FxRot *rot, s32 r, s32 a, Ov010Vec **list);
extern BOOL func_ov000_0219a8bc(void *hit, void *a, void *b, s32 c, u8 d, const Ov010Vec *pos, s16 h, s32 i, s32 scale);

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
            const char *m = data_ov010_0220ef68;
            Ov010V *e;
            e = (Ov010V *)func_02066774(m, data_ov010_0220ef70, 0, &o->pos);
            FLD(u8, e, 0x28) = 0;
            FLD(s32, e, 0xc8) = -1;
            o->unk_14 = FLD(s32, e, 0x24);
            e = (Ov010V *)func_02066774(m, data_ov010_0220ef6c, 0, &o->pos);
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
                    const char *m3 = data_ov010_0220ef74;
                    const char *m0 = data_ov010_0220ef68;
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
}  // namespace m_021fff80

// ---- merged from ov010_02200670.cpp
namespace m_02200670 {
extern "C" {

extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov000_02198328(void *p);
extern void func_ov010_02200ee0(void *p);
BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d);

void func_ov010_02200670(u8 *o, const Ov010Vec *v, u16 a, u16 b, s16 c, s16 d, u8 e, u16 g) {
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    if (FLD(u8, o, 0x43) != 0) {
        return;
    }
    FLD(Ov010Flags8, o, 0).b1 = e;
    FLD(s16, o, 6) = c;
    FLD(u16, o, 8) = 0;
    FLD(s16, o, 0xa) = d;
    FLD(u16, o, 0xc) = g;
    FLD(u16, o, 0xe) = a;
    FLD(u16, o, 0x10) = b;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0;
    FLD(Ov010Vec, o, 0x24) = *v;
    func_ov003_021da48c(o + 0x30, 1);
}

BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    FLD(u8, o, 0) = 1;
    FLD(u8, o, 1) = 0;
    FLD(u8, o, 2) = c;
    FLD(u16, o, 4) = a;
    FLD(u16, o, 6) = b;
    FLD(u16, o, 8) = d;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(u16, o, 0xe) = 0;
    FLD(u16, o, 0x10) = 0;
    FLD(u16, o, 0x12) = 0;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(Ov010Vec, o, 0x1c) = data_ov010_0220fd90;
    func_ov003_021da48c(o + 0x6c, 0);
    FLD(u16, o, 0x6e) = 0;
    func_ov000_02198360(o + 0x6c, 5, 0);
    return TRUE;
}

extern void *data_0214a420;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern void func_02065804(void *a, s32 b);
extern BOOL func_ov010_02200048(u8 *o, u16 a, u16 b, u8 c, u16 d);
extern BOOL func_ov010_02200c98(u8 *o);
extern void *func_0204a028(void *a, s32 b, void *c, s32 d);
extern void func_ov010_022000d8(u8 *o);

static inline BOOL Ov010Beam_IsDone(u8 *s) {
    BOOL r = TRUE;
    if (FLD(Ov010Flags8, s, 0).b0 && FLD(u8, s, 0x43) != 0) {
        r = FALSE;
    }
    return r;
}

void func_ov010_0220078c(u8 *o) {
    s32 k;
    if (FLD(u8, o, 0) == 0) {
        return;
    }
    FLD(s32, o, 0x18) = 0;
    switch (FLD(u8, o, 0x7f)) {
    case 5:
        FLD(s32, o, 0x14) = 0;
        break;
    case 0:
        if (FLD(Ov010Flags8, o, 0x28).b0) {
            FLD(Ov010Flags8, o, 0x28).b0 = 0;
            func_02065804(data_0214a420, FLD(s32, o, 0x3c));
            func_02065804(data_0214a420, FLD(s32, o, 0x40));
            func_02065804(data_0214a420, FLD(s32, o, 0x44));
            FLD(s32, o, 0x3c) = 0;
            FLD(s32, o, 0x40) = 0;
            FLD(s32, o, 0x44) = 0;
        }
        func_ov010_02200048(o + 0x28, FLD(u16, o, 4), FLD(u16, o, 6), FLD(u8, o, 2), FLD(u16, o, 8));
        func_ov000_02198360(o + 0x6c, 1, 0);
        break;
    case 1:
        if (func_ov010_02200c98(o)) {
            func_ov000_02198360(o + 0x6c, 2, 0);
        }
        break;
    case 2:
        FLD(u16, o, 0x6e)++;
        if (FLD(u16, o, 0x6e) > 10) {
            FLD(u16, o, 0x6e) = 0;
            func_ov000_02198360(o + 0x6c, 3, 0);
        }
        break;
    case 3:
        if (FLD(u16, o, 0x6c) == 0) {
            FLD(s32, o, 0x18) = 1;
            func_ov010_02200670(o + 0x28, (Ov010Vec *)(o + 0x1c), FLD(u16, o, 0x10), FLD(u16, o, 0x12), FLD(s16, o, 0xc), FLD(s16, o, 0xe), 0, FLD(u16, o, 0xa));
            if (FLD(u8, o, 1) != 0) {
                u8 *g = data_ov000_021ccd54;
                FLD(u8, g, 0x190) |= 0x1c;
                FLD(u8, g, 0x18d) = 0xf;
                FLD(u8, g, 0x18e) = 10;
                FLD(u8, g, 0x18f) = 10;
                func_0204a028(data_02097e4c, 0x5c, o + 0x1c, 5);
            }
            FLD(u16, o, 0x6c)++;
        } else if (Ov010Beam_IsDone(o + 0x28)) {
            FLD(s32, o, 0x18) = 2;
            func_ov000_02198360(o + 0x6c, 4, 0);
        }
        break;
    case 4:
        if (FLD(Ov010Flags8, o, 0x28).b0 && FLD(u8, o, 0x6b) == 1) {
            func_ov003_021da48c(o + 0x58, 2);
        }
        func_ov000_02198360(o + 0x6c, 5, 0);
        break;
    }
    k = 0;
    if (FLD(Ov010Flags8, o, 0x28).b0) {
        if (!Ov010Beam_IsDone(o + 0x28)) {
            k = FLD(s32, o, 0x48);
        }
    }
    if (k == 1) {
        FLD(s32, o, 0x18) = 2;
    }
    func_ov010_022000d8(o + 0x28);
}

extern u8 data_020928b4[];
extern u8 NNS_G3dGlb[];
extern u8 *data_02097d48;
extern void MTX_Identity33_(void *m);
extern void MI_Copy36B(void *m, void *b);
extern void NNS_G3dGlbSetBaseTrans(Ov010Vec *v);
extern void NNS_G3dGlbSetBaseScale(Ov010Vec *v);
extern void NNS_G3dGlbFlushVP(void);
extern void NNS_G3dGeBufferOP_N(s32 cmd, const void *data, s32 n);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern u8 func_02043d48(void *p);
extern void NNS_G3dGeFlushBuffer(void);

static inline void Ov010_G3End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
}  // namespace m_02200670

// ---- merged from ov010_02200a00.cpp
namespace m_02200a00 {
#include "nnsys/g3d.h"

struct Ov010Beam {
    u8 on;
    u8 unk_01[0xd];
    s16 len;
    u16 rx;
    u16 ry;
    s32 alpha;
    u8 unk_18[4];
    VecFx32 pos;
};

extern "C" {

extern u8 *data_02097d48;
u8 func_02043d48(void *p);

void func_ov010_02200a00(Ov010Beam *self) {
    MtxFx33 m;
    VecFx32 v;
    MtxFx33 rx;
    MtxFx33 ry;
    VecFx32 s;
    u32 alpha;
    if (self->on == 0) {
        return;
    }
    alpha = (self->alpha >> 12) & 0xff;
    if (alpha == 0) {
        return;
    }
    MTX_Identity33(&m);
    NNS_G3dGlbSetBaseRot(&m);
    VEC_Set(&v, 0, 0, 0);
    NNS_G3dGlbSetBaseTrans(&v);
    VEC_Set(&v, FX32_ONE, FX32_ONE, FX32_ONE);
    NNS_G3dGlbSetBaseScale(&v);
    NNS_G3dGlbFlushVP();
    NNS_G3dGeMtxMode(GX_MTXMODE_POSITION_VECTOR);
    NNS_G3dGePushMtx();
    NNS_G3dGeIdentity();
    NNS_G3dGeTranslateVec(&self->pos);
    MTX_RotX33(&rx, FX_SinIdx(self->rx), FX_CosIdx(self->rx));
    MTX_RotY33(&ry, FX_SinIdx(self->ry), FX_CosIdx(self->ry));
    NNS_G3dGeMultMtx33(&ry);
    NNS_G3dGeMultMtx33(&rx);
    VEC_Set(&s, FX32_ONE, FX32_ONE, FX_Mul(self->len, 0xf000));
    NNS_G3dGeScaleVec(&s);
    NNS_G3dGePolygonAttr(0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, func_02043d48(data_02097d48 + 0x8b0), alpha, 0);
    NNS_G3dGeTexImageParam(GX_TEXFMT_NONE, GX_TEXGEN_NONE, GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_TRNS, 0);
    NNS_G3dGeBegin(GX_BEGIN_TRIANGLES);
    NNS_G3dGeColor(GX_RGB(31, 0, 0));
    NNS_G3dGeVtx(0, 0, 0);
    NNS_G3dGeVtxXY(0, 0);
    NNS_G3dGeVtx(0, 0, FX16_ONE);
    NNS_G3dGeEnd();
    NNS_G3dGePopMtx(1);
    NNS_G3dGeFlushBuffer();
}

}
}  // namespace m_02200a00

// ---- merged from ov010_02200c98.cpp
namespace m_02200c98 {
extern "C" {

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

BOOL func_ov010_02200c98(u8 *o) {
    BOOL r = FALSE;
    s32 v;
    switch (FLD(u16, o, 0x6c)) {
    case 0:
        FLD(s32, o, 0x14) = 0;
        FLD(u16, o, 0x6e) = 0;
        FLD(u16, o, 0x6c) = 1;
    case 1:
        if (FLD(u16, o, 0x6e) < 9) {
            FLD(s32, o, 0x14) += 0x238e;
            v = Ov010_ClampS(FLD(s32, o, 0x14), 0, 0x14000);
            FLD(s32, o, 0x14) = v;
            FLD(u16, o, 0x6e)++;
            break;
        }
        FLD(u16, o, 0x6c) = 2;
    case 2:
        if (FLD(u16, o, 0x6e) < 0xb) {
            v = 0x14000;
            FLD(s32, o, 0x14) = v;
            FLD(u16, o, 0x6e) = FLD(const u16, o, 0x6e) + 1;
            break;
        }
        FLD(u16, o, 0x6c) = 3;
    case 3:
        if (FLD(u16, o, 0x6e) < 0x14) {
            FLD(s32, o, 0x14) -= 0x238e;
            v = Ov010_ClampS(FLD(s32, o, 0x14), 0, 0x14000);
            FLD(s32, o, 0x14) = v;
            FLD(u16, o, 0x6e)++;
            break;
        }
        FLD(u16, o, 0x6e) = 0;
        FLD(u16, o, 0x6c) = 4;
        break;
    case 4:
        FLD(s32, o, 0x14) = 0;
        r = TRUE;
        break;
    }
    return r;
}

}
}  // namespace m_02200c98

// ---- merged from ov010_02200d94.cpp
namespace m_02200d94 {
extern "C" {

extern void func_ov003_021da48c(void *p, s32 a);
extern void *func_ov000_02198328(void *p);
extern void func_ov010_02200ee0(void *p);
extern BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d);

static inline s32 Ov010_ClampS(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return hi;
    }
    if (x < lo) {
        return lo;
    }
    return x;
}

struct Ov010BeamSt {
    u16 state;
    u16 timer;
};

u8 *func_ov010_02200d94(u8 *o) {
    FLD(Ov010Flags8, o, 0).b0 = 0;
    func_ov000_02198328(o + 0x2c);
    return o;
}

u8 *func_ov010_02200db8(u8 *o) {
    func_ov010_02200ee0(o);
    return o;
}

static inline u8 *Ov010Beam_New(void) {
    u8 *n = (u8 *)func_0203dd9c(0x8c);
    if (n != NULL) {
        FLD(u8, n, 0xc) = 0;
        FLD(Ov010Flags8, n, 0x34).b0 = 0;
        func_ov000_02198328(n + 0x64);
        func_ov000_02198328(n + 0x78);
    }
    return n;
}

static inline u8 *Ov010List_Push(u8 *head, u8 *n) {
    if (n != NULL) {
        FLD(u8 *, n, 8) = head;
        return n;
    }
    return head;
}

BOOL func_ov010_02200dcc(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    s32 i;
    FLD(Ov010Flags8, o, 0).b0 = 1;
    FLD(u8, o, 1) = c;
    FLD(u16, o, 2) = a;
    FLD(u16, o, 4) = b;
    FLD(u16, o, 6) = d;
    FLD(u16, o, 8) = 0;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(void *, o, 0x10) = NULL;
    FLD(Ov010Vec, o, 0x14) = data_ov010_0220fd90;
    FLD(Ov010Vec, o, 0x20) = FLD(Ov010Vec, o, 0x14);
    func_ov003_021da48c(o + 0x2c, 0);
    FLD(u16, o, 0x2c) = 0x65;
    for (i = 0; i < 3; i++) {
        u8 *n = Ov010Beam_New();
        func_ov010_022006fc(n + 0xc, a, b, c, d);
        FLD(u8 *, n, 8) = NULL;
        FLD(u8 *, o, 0x10) = Ov010List_Push(FLD(u8 *, o, 0x10), n);
        if (i == 0) {
            FLD(u8, n, 0xd) = 1;
        }
    }
    return TRUE;
}

}
}  // namespace m_02200d94

// ---- merged from ov010_02200ee0.cpp
namespace m_02200ee0 {
struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern void *data_0214a420;
extern Ov010Heap *data_02097dd0;
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov010_02200a00(u8 *o);
extern u8 *func_ov000_0219bf90(void);
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);

static inline void Ov010Fx_Free(u8 *s) {
    if (FLD(Ov010Flags8, s, 0).b0) {
        FLD(Ov010Flags8, s, 0).b0 = 0;
        func_02065804(data_0214a420, FLD(s32, s, 0x14));
        func_02065804(data_0214a420, FLD(s32, s, 0x18));
        func_02065804(data_0214a420, FLD(s32, s, 0x1c));
        FLD(s32, s, 0x14) = 0;
        FLD(s32, s, 0x18) = 0;
        FLD(s32, s, 0x1c) = 0;
    }
}

static inline void Ov010Beam_Reset(u8 *b) {
    if (FLD(u8, b, 0) != 0) {
        Ov010Fx_Free(b + 0x28);
        FLD(u8, b, 0) = 0;
    }
}

void func_ov010_02200ee0(u8 *o) {
    u8 *next;
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = next) {
        u32 saved;
        next = FLD(u8 *, n, 8);
        Ov010Beam_Reset(n + 0xc);
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (n != NULL) {
            if (n != NULL) {
                Ov010Beam_Reset(n + 0xc);
                Ov010Fx_Free(n + 0x34);
                func_0203de1c(n);
            }
        }
        data_02097dd0->cur = saved;
    }
    FLD(u8 *, o, 0x10) = NULL;
    FLD(Ov010Flags8, o, 0).b0 = 0;
}

}

// func_ov010_02201064 (round raD). Ov010Beam_Idle sets its flag from the mode compare (`r = b[0x7f] == 5`)
// rather than clearing it under an && test: the compare's value is a late temporary, numbered below the CSE'd
// state-byte reads, which is the colouring the ROM has in the beam walks. Each beam register update reads the
// old value into `cur` first, which puts GetB's value first in the add.
extern "C" {

extern s32 func_02040498(s32 max);
extern s32 func_02040528(s32 n);
extern s32 func_020404e0(void);
extern void func_ov003_021d9a00(Ov010Vec *out, s32 angle, const Ov010Vec *in);
extern u16 func_ov003_021d9c50(Ov010Vec *a, Ov010Vec *b);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void func_ov010_0220078c(void *p);

static inline s32 Ov010k_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Ov010Beam_Idle(u8 *b) {
    BOOL r = TRUE;
    if (FLD(u8, b, 0) != 0) {
        r = FLD(u8, b, 0x7f) == 5;
    }
    return r;
}

static inline s32 Ov010Beam_Mode(u8 *b) {
    s32 r = 0;
    if (FLD(u8, b, 0) != 0) {
        r = FLD(s32, b, 0x18);
    }
    return r;
}

static inline u16 Ov010Beam_GetA(u8 *b) {
    u16 r = 0;
    if (FLD(u8, b, 0) != 0 && !Ov010Beam_Idle(b)) {
        r = FLD(u16, b, 0x10);
    }
    return r;
}

static inline void Ov010Beam_SetA(u8 *b, u16 v) {
    if (*b != 0 && !Ov010Beam_Idle(b)) {
        FLD(u16, b, 0x10) = v;
        if (FLD(Ov010Flags8, b, 0x28).b0) {
            FLD(u16, b, 0x36) = v;
        }
    }
}

static inline u16 Ov010Beam_GetB(u8 *b) {
    u16 r = 0;
    if (FLD(u8, b, 0) != 0 && !Ov010Beam_Idle(b)) {
        r = FLD(u16, b, 0x12);
    }
    return r;
}

static inline void Ov010Beam_SetB(u8 *b, u16 v) {
    if (*b != 0 && !Ov010Beam_Idle(b)) {
        FLD(u16, b, 0x12) = v;
        if (FLD(Ov010Flags8, b, 0x28).b0) {
            FLD(u16, b, 0x38) = v;
        }
    }
}

void func_ov010_02201064(u8 *self) {
    BOOL all;
    u16 ang;
    u8 *n;
    u8 *n1;
    u8 *n2;
    Ov010Vec tmp;
    Ov010Vec res;
    Ov010Vec d;
    Ov010Vec v;
    if (!FLD(Ov010Flags8, self, 0).b0) {
        return;
    }
    switch (FLD(u16, self, 0x2c)) {
    case 0:
        FLD(u16, self, 0xa) = 0;
        FLD(u16, self, 0xc) = 0;
        FLD(u16, self, 0x2c) = 10;
        break;
    case 10: {
        u8 *last = NULL;
        for (n1 = FLD(u8 *, self, 0x10); n1 != NULL; n1 = FLD(u8 *, n1, 8)) {
            if (Ov010Beam_Idle(n1 + 0xc)) {
                last = n1;
            }
        }
        if (last != NULL) {
            BOOL flag = FLD(u16, self, 0x2e) % 3 == 0;
            s32 len;
            u16 ry;
            u16 rx;
            u16 t;
            if ((s32)FLD(u16, self, 0xa) >= 3) {
                u16 r = func_02040498(2);
                FLD(u16, self, 0xa) = 0;
                FLD(u16, self, 0xc) = r;
                FLD(u16, self, 0xa)++;
            } else {
                FLD(u16, self, 0xc)++;
                if ((s32)FLD(u16, self, 0xc) >= 3) {
                    FLD(u16, self, 0xc) = 0;
                }
                FLD(u16, self, 0xa)++;
            }
            {
                u16 c = FLD(u16, self, 0xc);
                ang = c * 0x5555 + func_02040498(0x5555);
            }
            if (flag) {
                len = Ov010k_Mul(func_020404e0(), 0x2cd);
            } else {
                len = Ov010k_Mul(func_020404e0(), 0xb33) + 0x4cd;
            }
            if (len > 0x1000) {
                len = 0x1000;
            } else if (len < 0) {
                len = 0;
            }
            func_ov003_021d9a00(&v, ang, &data_ov010_0220ef80);
            len = Ov010k_Mul(len, 0xc000);
            v.x = Ov010_FxMul(v.x, len);
            v.y = Ov010_FxMul(v.y, len);
            v.z = Ov010_FxMul(v.z, len);
            v.y = Ov010k_Mul(v.y, 0x980);
            func_ov003_021d9980(&v, func_ov003_021d9c50(&FLD(Ov010Vec, self, 0x14), &FLD(Ov010Vec, self, 0x20)), &v);
            OV010_BLKCPY(&tmp, &v);
            VEC_Add(&FLD(Ov010Vec, self, 0x14), &tmp, &res);
            d.x = res.x - FLD(s32, self, 0x20);
            d.y = res.y - FLD(s32, self, 0x24);
            d.z = res.z - FLD(s32, self, 0x28);
            VEC_Normalize(&d, &d);
            ry = func_ov003_021d9c74(&d);
            rx = func_ov003_021d9c38(&d);
            t = func_02040498(10) + 10;
            {
                s32 s = func_02040528(2);
                s = s > 0 ? s + 0x16 : s - 0x16;
                FLD(u8, last, 0) = 0;
                FLD(u16, last, 2) = 0;
                FLD(u16, last, 4) = 0;
                FLD(u16, last, 6) = s;
            }
            if (FLD(u8, last, 0xc) != 0 && FLD(u8, last, 0x8b) == 5) {
                FLD(u16, last, 0x7a) = 0;
                func_ov000_02198360(last + 0x78, 0, 0);
                FLD(s32, last, 0x28) = FLD(s32, self, 0x20);
                FLD(s32, last, 0x2c) = FLD(s32, self, 0x24);
                FLD(s32, last, 0x30) = FLD(s32, self, 0x28);
                FLD(u16, last, 0x1c) = ry;
                FLD(u16, last, 0x1e) = rx;
                FLD(u16, last, 0x18) = 0xc20;
                FLD(u16, last, 0x1a) = 0x4000;
                FLD(u16, last, 0x16) = t;
            }
        }
        for (n2 = FLD(u8 *, self, 0x10); n2 != NULL; n2 = FLD(u8 *, n2, 8)) {
            u8 *b = n2 + 0xc;
            if (Ov010Beam_Idle(b)) {
                continue;
            }
            if (Ov010Beam_Mode(b) == 1) {
                FLD(u8, n2, 0) = 1;
            } else if (Ov010Beam_Mode(b) == 2) {
                FLD(u8, n2, 0) = 0;
            }
            if (FLD(u8, n2, 0) != 0) {
                FLD(u16, n2, 2) += 4;
                FLD(u16, n2, 2) = FLD(u16, n2, 2) > 0x24 ? 0x24 : FLD(u16, n2, 2);
                FLD(u16, n2, 4) = FLD(u16, n2, 6);
            } else {
                FLD(u16, n2, 2) = Ov010k_Mul(FLD(u16, n2, 2) << 12, 0x1000) >> 12;
                FLD(u16, n2, 4) = 0;
            }
            {
                u16 dd = 0xffff - FLD(u16, n2, 2);
                u16 cur = Ov010Beam_GetA(b);
                Ov010Beam_SetA(b, cur + dd);
            }
            {
                u16 dd = FLD(u16, n2, 4);
                u16 cur = Ov010Beam_GetB(b);
                Ov010Beam_SetB(b, cur + dd);
            }
        }
        if (FLD(u16, self, 8) < CFLD(u16, self, 0x2e)) {
            FLD(u16, self, 0x2e) = 0;
            FLD(u16, self, 0x2c) = 100;
        } else {
            FLD(u16, self, 0x2e)++;
        }
        break;
    }
    case 100: {
        all = TRUE;
        for (n = FLD(u8 *, self, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
            if (!Ov010Beam_Idle(n + 0xc)) {
                all = FALSE;
            }
        }
        if (all) {
            FLD(u16, self, 0x2c) = 101;
        }
        break;
    }
    case 101:
        break;
    }
    for (n = FLD(u8 *, self, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
        func_ov010_0220078c(n + 0xc);
    }
}


}
}  // namespace m_02200ee0
