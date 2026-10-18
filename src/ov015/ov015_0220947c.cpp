#include "ov015/ov015.h"

extern "C" {

s32 func_ov000_0218f110(void *a);
s32 func_ov000_02191b9c(void *a);
extern u8 data_ov015_02212db0[];
extern u8 data_ov015_02212e0d[];
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 func_ov000_021909a8(void *a, const void *b, const void *c);
u8 *func_0206fef8(u16 id);
void func_020267e8(void *a, void *cb);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov015_022090fc(u8 *self);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191618(void *a);
void func_ov000_02191690(void *a);
void func_ov000_02191318(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void func_0203f364(void *a);
void *func_0203dd9c(u32 size);
void *func_ov015_0220a0c8(u8 *self);
void func_ov000_02190a80(void *a, s32 b);
void func_ov015_02209a50(u8 *self);
void func_0203f3d0(void *a);
extern u32 data_02fe0f04;
s32 func_02049130(s32 t, s32 a, s32 b);
void func_ov015_02209c90(u8 *self);
u16 FX_Atan2(s32 x, s32 z);
void func_ov015_0220daf4(void *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
void func_0202a1d4(void);
void func_ov000_021903b4(void *a);
void VEC_Normalize(void *src, void *dst);
void MI_Copy36B(const void *src, void *dst);
s32 func_01ffc584(void *a, void *b, s32 c, s32 d);
void func_020117a4(void *a, void *b, void *c);
void VEC_Add(void *a, void *b, void *c);
extern u8 data_ov015_02212e94[];
extern u8 data_ov015_02212eb0[];

static inline BOOL Ov015_IsIdle567(u8 *self) {
    BOOL r = TRUE;
    if (FLD(u8, self, 0x567) != 3 && FLD(u8, self, 0x567) != 0) r = FALSE;
    return r;
}
BOOL func_ov015_0220947c(u8 *self) {
    BOOL r = TRUE;
    if (FLD(s16, self, 0x10c) >= 0) {
        if (func_ov000_0218f110(self + 0x10c) == 0) r = FALSE;
    }
    if (FLD(s16, self, 0x32c) >= 0) {
        if (func_ov000_0218f110(self + 0x32c) == 0) r = FALSE;
    }
    if (!Ov015_IsIdle567(self)) {
        if (func_ov000_02191b9c(self + 0x54c) == 0) r = FALSE;
    }
    return r;
}

struct Ov015Bits09500 { u16 b0 : 5; u16 b5 : 3; u16 b8 : 8; };
struct Ov015Nib09500 { u8 lo : 4; u8 hi : 4; };
BOOL func_ov015_02209500(u8 *self) {
    u8 *p;
    u32 n;
    Ov015V *m;
    func_ov000_0218ffdc(self + 0x244, self + 0x10c, 0, 1);
    func_ov000_02190cb0(self + 0x244, data_ov015_02212e0d, 0x1000, 0);
    p = NULL;
    if (FLD(u8 *, self, 0x1cc) != NULL) p = FLD(u8 *, FLD(u8 *, self, 0x1cc), 0) + 8;
    FLD(u8 *, self, 0x314) = p;
    if (p != NULL && FLD(u16, p, 2) == 0) {
        FLD(u8 *, self, 0x318) = p + 4 + FLD(u16, p, 0) * 12;
    }
    FLD(Ov015AnimFlags, self, 0x306).b4 = 0;
    func_ov000_021915a0(self + 0x244);
    FLD(Ov015AnimFlags, self, 0x306).b0 = 1;
    func_020267e8(self + 0x268, (void *)func_ov015_022090fc);
    FLD(Ov015AnimFlags, self, 0x306).b5 = 0;
    FLD(Ov015AnimFlags, self, 0x306).b8 = 1;
    FLD(u8 *, self, 0x294) = self + 0xc;
    FLD(s32, self, 0x3c) = func_ov000_021909a8(self + 0x244, data_ov015_02212e14, data_ov015_02212e15);
    func_ov000_0218ffdc(self + 0x464, self + 0x32c, 0, 1);
    n = FLD(Ov015Bits09500, func_0206fef8(FLD(u16, self, 0x4)), 0x12).b5;
    if (n != 0) {
        func_ov000_02190cb0(self + 0x464, FLD(void *, data_ov015_02212db0, 0), 0x1000, 0);
        func_ov000_02191618(self + 0x464);
        func_ov000_02191690(self + 0x464);
        func_ov000_02191318(self + 0x464, n << 12);
    }
    FLD(Ov015AnimFlags, self, 0x526).b4 = 0;
    FLD(Ov015AnimFlags, self, 0x526).b0 = 1;
    FLD(Ov015Nib09500, self, 0x564).hi = FLD(Ov015Nib09500, self, 0x564).lo;
    FLD(Ov015Nib09500, self, 0x564).lo = 3;
    FLD(s32, self, 0x48) = (0x800 - 0x37800) - Ov015_FxMul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    { s32 v = FLD(s16, func_0206fef8(FLD(u16, self, 0xc4)), 0x10); FLD(s32, self, 0x70) = v; FLD(s32, self, 0x74) = v; FLD(s32, self, 0x78) = v; }
    if (FLD(u8, self, 0x58c) != 0) func_0203f364(self + 0x568);
    FLD(s32, self, 0x590) = 0x100;
    FLD(s32, self, 0x594) = 0x100;
    FLD(s32, self, 0x94) = FLD(s16, func_0206fef8(FLD(u16, self, 0xc4)), 0x16) << 4;
    FLD(s32, self, 0x98) = FLD(s16, func_0206fef8(FLD(u16, self, 0xc4)), 0x14) << 4;
    m = (Ov015V *)func_0203dd9c(0x2c);
    if (m != NULL) m = (Ov015V *)func_ov015_0220a0c8((u8 *)m);
    FLD(Ov015V *, self, 0xf8) = m;
    FLD(s32, self, 0xf4) = 2;
    m->v08(self);
    return TRUE;
}

BOOL func_ov015_02209790(u8 *self, BOOL b) {
    func_ov000_02190a80(self + 0x244, FLD(s16, self, 0x104));
    func_ov000_02190a80(self + 0x464, 0);
    if (!b) {
        return TRUE;
    }
    if (FLD(void *, self, 0xf0) != NULL) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0x100));
        HEAP_POP(saved);
        FLD(Ov015V *, self, 0xf8)->v10(self);
        FLD(void *, self, 0x100) = FLD(void *, self, 0xf8);
        FLD(s32, self, 0xfc) = FLD(s32, self, 0xf4);
        FLD(Ov015V *, self, 0xf0)->v08(self);
        FLD(void *, self, 0xf8) = FLD(void *, self, 0xf0);
        FLD(s32, self, 0xf4) = FLD(s32, self, 0xec);
        FLD(void *, self, 0xf0) = NULL;
        FLD(s32, self, 0xec) = 0;
    }
    if (FLD(Ov015V *, self, 0xf8) != NULL && !FLD(Ov015V *, self, 0xf8)->v0c(self)) {
        u32 saved;
        Ov015V *o;
        FLD(Ov015V *, self, 0xf8)->v10(self);
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0xf8));
        HEAP_POP(saved);
        o = FLD(Ov015V *, self, 0x100);
        FLD(Ov015V *, self, 0xf8) = o;
        FLD(s32, self, 0xf4) = FLD(s32, self, 0xfc);
        o->v08(self);
        FLD(void *, self, 0x100) = NULL;
        FLD(s32, self, 0xfc) = 0;
    }
    if (FLD(s32, self, 0xf4) != 5 && FLD(s32, self, 0xf4) != 6) {
        FLD(s32, self, 0x48) = (0x800 - 0x37800) - Ov015_FxMul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    }
    {
        s32 t = Ov015_FxMul(FX_Div(FLD(s32, self, 0x48) + 0x37000, -0x73000), 0x3e8000);
        if (t <= 0x1f4000) {
            FLD(s32, self, 0x7c) = 0x1000;
        } else {
            FLD(s32, self, 0x7c) = Ov015_FxMul(FX_Div(0x3e8000 - t, 0x1f4000), 0x666) + 0x99a;
        }
    }
    func_ov015_02209a50(self);
    FLD(Ov015Vec, self, 0x574) = FLD(Ov015Vec, self, 0x568);
    FLD(Ov015Vec, self, 0x568) = FLD(Ov015Vec, self, 0x40);
    FLD(s32, self, 0x5a0) = FLD(s32, self, 0x80);
    func_0203f3d0(self + 0x568);
    FLD(u32, self, 0x5ac) = data_02fe0f04;
    return TRUE;
}

void func_ov015_02209a50(u8 *self) {
    s32 f;
    if (FLD(s32, self, 0x44) > -0xa000) {
        FLD(s32, self, 0x8c) = 0x1000;
        if (FLD(u8, self, 0x90) > 8) {
            FLD(u8, self, 0x90)--;
        }
    } else if (FLD(s32, self, 0x44) > -0x32000) {
        s32 t = FX_Div(FLD(s32, self, 0x44) + 0x32000, 0x28000);
        s32 k;
        FLD(s32, self, 0x8c) = func_02049130(t, 0x666, 0x1000);
        k = (func_02049130(t, 0xa000, 0x16000) >> 12) & 0xff;
        if (FLD(u8, self, 0x90) > k) {
            FLD(u8, self, 0x90)--;
        } else if (FLD(u8, self, 0x90) < k) {
            FLD(u8, self, 0x90)++;
        }
    } else {
        FLD(s32, self, 0x8c) = 0x666;
        FLD(u8, self, 0x90) = 10;
    }
    f = Ov015_FxMul(FLD(s32, self, 0x8c), FLD(s16, func_0206fef8(FLD(u16, self, 0xc4)), 0x10));
    FLD(s32, self, 0x8c) = f;
    FLD(s32, self, 0x80) = 0x28000;
    FLD(s32, self, 0x84) = 0x1000;
    FLD(s32, self, 0x88) = 0x32000;
    FLD(s32, self, 0x80) = Ov015_FxMul(FLD(s32, self, 0x80), f);
    FLD(s32, self, 0x84) = Ov015_FxMul(FLD(s32, self, 0x84), f);
    FLD(s32, self, 0x88) = Ov015_FxMul(FLD(s32, self, 0x88), f);
}

void func_ov015_02209b80(u8 *self, s32 a, s32 b) {
    FLD(s32, self, 0xf0) = a;
    FLD(s32, self, 0xec) = b;
}

static inline void Ov015_UpdateMove(u8 *self) {
    u16 ang = FX_Atan2(FLD(s32, self, 0x9c), FLD(s32, self, 0xa4));
    Ov015Vec v;
    v = *(Ov015Vec *)(self + 0x40);
    v.y = 0;
    FLD(s32, self, 0x55c) = -0x1666;
    func_ov015_0220daf4(self + 0x54c, &v, FLD(s32, self, 0x80), FLD(s32, self, 0x88), ang, 0);
    FLD(u8, self, 0x565) = FLD(u8, self, 0x90);
}
void func_ov015_02209b8c(u8 *self) {
    switch (FLD(s32, self, 0x108)) {
    case 0:
        func_ov015_02209c90(self);
        break;
    case 1:
        Ov015_UpdateMove(self);
        break;
    case 2:
        func_ov015_02209c90(self);
        Ov015_UpdateMove(self);
        break;
    }
}

struct Ov015Blk09c90 { s32 w[3]; };
extern const Ov015Blk09c90 data_ov015_02212644;
static inline void Ov015_Cross09c90(const Ov015Vec *a, const Ov015Vec *b, Ov015Vec *o) {
    o->x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    o->y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    o->z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
}
void func_ov015_02209c90(u8 *self) {
    Ov015Vec up;
    Ov015Vec x;
    Ov015Vec z;
    s32 k = FLD(s32, self, 0x7c);
    s32 sx = Ov015_FxMul(FLD(s32, self, 0x70), k);
    s32 sy = Ov015_FxMul(FLD(s32, self, 0x74), k);
    s32 sz = Ov015_FxMul(FLD(s32, self, 0x78), k);
    if (FLD(s32, self, 0x9c) != 0 || FLD(s32, self, 0xa0) != 0 || FLD(s32, self, 0xa4) == 0) {
        *(Ov015Blk09c90 *)&up = data_ov015_02212644;
        VEC_Normalize(self + 0x9c, &z);
        Ov015_Cross09c90(&up, &z, &x);
        VEC_Normalize(&x, &x);
        Ov015_Cross09c90(&z, &x, &up);
        VEC_Normalize(&up, &up);
        FLD(Ov015Vec, self, 0x4c) = x;
        FLD(Ov015Vec, self, 0x58) = up;
        FLD(Ov015Vec, self, 0x64) = z;
    }
    if (data_ov015_0221332c.unk_1d != 0 && FLD(s32, self, 0xf4) == 2) {
        FLD(s16, self, 0x2fa) = 0x14bf;
        FLD(s16, self, 0x2fc) = 0x5ad6;
        FLD(s16, self, 0x2fe) = 0xb;
        FLD(s16, self, 0x300) = 0xa;
        FLD(s16, self, 0x51a) = 0x14bf;
        FLD(s16, self, 0x51c) = 0x5ad6;
        FLD(s16, self, 0x51e) = 0xb;
        FLD(s16, self, 0x520) = 0xa;
    }
    FLD(Ov015VecC, self, 0x2bc) = FLD(Ov015VecC, self, 0x40);
    MI_Copy36B(self + 0x4c, self + 0x2c8);
    FLD(s32, self, 0x2ec) = sx;
    FLD(s32, self, 0x2f0) = sy;
    FLD(s32, self, 0x2f4) = sz;
    func_ov000_021903b4(self + 0x244);
    FLD(Ov015VecC, self, 0x4dc) = FLD(Ov015VecC, self, 0x30);
    MI_Copy36B(self + 0xc, self + 0x4e8);
    func_ov000_021903b4(self + 0x464);
    func_0202a1d4();
}

s32 func_ov015_02209fb8(s32 x) {
    s32 t = FX_Div(x + 0x37000, -0x73000);
    return (s32)(((s64)t * 0x3e8000 + 0x800) >> 12);
}

BOOL func_ov015_02209ff0(u8 *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, self + 0x40, FLD(s32, self, 0x98) + 0x4cd, FLD(s32, self, 0x94))) r = TRUE;
    return r;
}

BOOL func_ov015_0220a028(u8 *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, self + 0x40, FLD(s32, self, 0x98), FLD(s32, self, 0x94))) r = TRUE;
    return r;
}

void func_ov015_0220a058(u8 *self, void *out) {
    s32 z = Ov015_FxMul(FLD(s32, self, 0x70), 0xa000);
    Ov015Vec v;
    v.x = 0;
    v.y = 0;
    v.z = z;
    func_020117a4(&v, self + 0xc, &v);
    VEC_Add(&v, self + 0x30, out);
}

void *func_ov015_0220a0c8(u8 *self) {
    SET_VT(self, data_ov015_02212e94);
    FLD(u16, self, 0x4) = 0;
    FLD(u16, self, 0x6) = 0;
    FLD(u16, self, 0x8) = 0;
    FLD(u16, self, 0xa) = 0;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    FLD(u8, self, 0x14) = 0;
    FLD(u16, self, 0x16) = 0;
    FLD(s32, self, 0x18) = 0;
    FLD(u16, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = 0;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    return self;
}

void *func_ov015_0220a110(void *self) {
    SET_VT(self, data_ov015_02212e94);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220a148(void *self) {
    SET_VT(self, data_ov015_02212e94);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_0220a188(u8 *self, u8 *p) {
    FLD(u8 *, self, 0x20) = p;
    FLD(u16, self, 0x6) = 0;
    FLD(u16, self, 0x8) = 2;
    FLD(u16, self, 0xa) = 0;
    FLD(s32, self, 0xc) = FLD(s32, p, 0xdc);
    FLD(s32, p, 0xa8) = 0;
    FLD(s32, p, 0xbc) = 1;
    func_ov000_02190cb0(p + 0x244, data_ov015_02212e0d, 0x19a, 0);
    FLD(u16, p, 0x104) = 0x800;
    func_ov000_021915a0(p + 0x244);
    FLD(u16, self, 0x4) = 0;
    return TRUE;
}

}
