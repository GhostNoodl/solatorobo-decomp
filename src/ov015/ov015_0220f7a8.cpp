#include "ov015/ov015.h"

extern "C" {

extern u8 *data_ov002_021f0f9c;
extern u8 *data_02097d48;
void func_ov002_021e8b3c(void *p);
extern Ov015Shared *data_ov015_02213368;
extern char data_ov015_02213111[];
void func_ov002_021e9e40(s32 a);
void *func_ov015_0220dde8(u8 *self);
void *func_0207011c(u16 id);
u8 *func_0206fef8(u16 id);
void func_ov015_0220e570(u8 *self, s32 a, s32 b, u8 c, s16 d);
u8 *func_ov002_021e92b0(s32 a, s32 b, s32 c, s32 d, s32 e);
void func_ov002_021e4dac(void *a, void *b);
u8 *func_02070744(u16 id);
extern char data_ov015_02213123[];
extern char data_ov015_0221312a[];
extern char data_ov015_02213131[];
extern char data_ov015_02213147[];
extern char data_ov015_0221314d[];
extern char data_ov015_02213158[];
extern u8 data_ov015_022131c4[];
void func_02016cd8(u32 val, void *dst, u32 size);
void func_02016d1c(u32 val, void *dst, u32 size);
void func_02041558(void *p);
void func_02041278(void *p);
void *func_02023390(void *a, int b);
void *func_02023410(void *a, u16 b);
void func_02042628(void *model, void *a, void *part, int b);
extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern char data_ov015_02213163[];
extern char data_ov015_02213170[];
void func_0204bfcc(void *p);
void func_0204bfe4(void *p, const void *a, const void *b);

void func_ov015_0220f7a8(u8 *self) {
    u8 *o;
    if (data_ov002_021f0f9c != NULL) {
        func_ov002_021e8b3c(data_ov002_021f0f9c);
    }
    if (FLD(s32, self, 0x4) < 0x14) {
        return;
    }
    o = FLD(u8 *, self, 0x10);
    if (o == NULL) {
        return;
    }
    if (FLD(Ov015D48Bits2, data_02097d48, 0xa30).b4) {
        return;
    }
    if (FLD(void *, o, 0x4) != NULL) VCALL(FLD(void *, o, 0x4))->v20();
    if (FLD(void *, o, 0x8) != NULL) VCALL(FLD(void *, o, 0x8))->v20();
    if (FLD(void *, o, 0xc) != NULL) VCALL(FLD(void *, o, 0xc))->v20();
    if (FLD(void *, o, 0x10) != NULL) VCALL(FLD(void *, o, 0x10))->v20();
    if (FLD(void *, o, 0x14) != NULL) VCALL(FLD(void *, o, 0x14))->v20();
}

struct Ov015ItemBitsF878 {
    u16 lo : 5;
    u16 kind : 3;
    u16 hi : 8;
};
struct Ov015Vec2F878 { s32 w[6]; };
struct Ov015Pair2F878 { s32 w[4]; };
struct Ov015Vec1F878 { s32 w[3]; };
extern const Ov015Vec2F878 data_ov015_022130d0;
extern const Ov015Pair2F878 data_ov015_02213038;
extern const Ov015Pair2F878 data_ov015_02213048;
extern const Ov015Vec2F878 data_ov015_02213088;
extern const Ov015Vec1F878 data_ov015_02212fb8;
extern const Ov015Vec1F878 data_ov015_02212fdc;
extern char data_ov015_0221311c[];
u8 *func_ov002_021e91c8(s32 a, s32 b, s32 c, s32 d, s32 e);
void func_ov002_021e50d8(void *a, s32 b, s32 c);
void func_ov015_0220f878(void) {
    u8 *o;
    u16 id;
    void *name;
    switch (*(u16 *)func_02070744(FLD(u16, data_ov015_02213368, 0xc))) {
    case 0:
        func_ov002_021e9e40(3);
        break;
    case 1:
        func_ov002_021e9e40(4);
        break;
    case 2:
    case 3:
        func_ov002_021e9e40(5);
        break;
    }
    o = (u8 *)func_0203dd9c(0x584);
    if (o != NULL) {
        o = (u8 *)func_ov015_0220dde8(o);
    }
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0x96000;
    FLD(s32, o, 0x8) = 3;
    id = FLD(u16, data_ov015_02213368, 0xc);
    name = func_0207011c(id);
    {
        u8 *info = func_0206fef8(id);
        u16 k = FLD(Ov015ItemBitsF878, info, 0x12).kind;
        FLD(void *, o, 0x510) = name;
        FLD(void *, o, 0x514) = data_ov015_02213111;
        FLD(u16, o, 0x3a4) = k;
    }
    FLD(u16, o, 0x498) = id;
    func_ov015_0220e570(o, (s32)data_ov015_0221311c, 0, 0, 0x1000);
    {
        Ov015Vec a[2];
        s32 b[2][2];
        s32 c[2][2];
        Ov015Vec d[2];
        Ov015Vec e;
        Ov015Vec f;
        s32 n;
        u8 *p5;
        u8 *p4;
        u8 *t;
        *(Ov015Vec2F878 *)a = data_ov015_022130d0;
        *(Ov015Pair2F878 *)b = data_ov015_02213038;
        *(Ov015Pair2F878 *)c = data_ov015_02213048;
        *(Ov015Vec2F878 *)d = data_ov015_02213088;
        *(Ov015Vec1F878 *)&e = data_ov015_02212fb8;
        *(Ov015Vec1F878 *)&f = data_ov015_02212fdc;
        n = FLD(s32, data_ov015_02213368, 0x2c);
        p5 = func_ov002_021e91c8(0, 0x96000, 3, 0, 0);
        p4 = func_ov002_021e91c8(0, 0x96000, 3, 0, 0);
        FLD(s32, p5, 0x50) = a[n].x;
        FLD(s32, p5, 0x54) = a[n].y;
        FLD(s32, p5, 0x58) = a[n].z;
        t = func_ov002_021e92b0(0, 0x50000, 3, 0, 0x1000);
        FLD(Ov015Vec, t, 0x4c) = e;
        FLD(u8 *, t, 0x48) = p5;
        func_ov002_021e4dac(p5, t);
        t = func_ov002_021e92b0(0, 0x96000, 3, 0, 0x1000);
        FLD(s32, t, 0x4) = 3;
        FLD(Ov015Vec, t, 0x4c) = f;
        FLD(u8 *, t, 0x48) = p5;
        func_ov002_021e4dac(p5, t);
        FLD(s32, p4, 0x50) = b[n][0];
        FLD(s32, p4, 0x54) = b[n][1];
        FLD(s32, p4, 0x58) = 0;
        func_ov002_021e50d8(p4, c[n][0], c[n][1]);
        t = func_ov002_021e92b0(0, 0x78000, 3, 0, 0x1000);
        FLD(s32, t, 0x4c) = d[n].x;
        FLD(s32, t, 0x50) = d[n].y;
        FLD(s32, t, 0x54) = d[n].z;
        FLD(u8 *, t, 0x48) = p4;
        func_ov002_021e4dac(p4, t);
    }
}

struct Ov015ItemBits {
    u16 lo : 5;
    u16 kind : 3;
    u16 hi : 8;
};
void func_ov015_0220fb78(u8 *self) {
    u8 *o;
    u8 *t;
    u16 id;
    void *name;
    func_ov002_021e9e40(6);
    o = (u8 *)func_0203dd9c(0x584);
    if (o != NULL) {
        o = (u8 *)func_ov015_0220dde8(o);
    }
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0x168000;
    FLD(s32, o, 0x8) = 3;
    id = FLD(u16, data_ov015_02213368, 0xc);
    name = func_0207011c(id);
    {
        u8 *info = func_0206fef8(id);
        u16 k = FLD(Ov015ItemBits, info, 0x12).kind;
        FLD(void *, o, 0x510) = name;
        FLD(void *, o, 0x514) = data_ov015_02213111;
        FLD(u16, o, 0x3a4) = k;
    }
    FLD(u16, o, 0x498) = id;
    func_ov015_0220e570(o, (s32)data_ov015_02213123, 0x78000, 0, 0x800);
    func_ov015_0220e570(o, (s32)data_ov015_0221312a, 0x168000, 1, 0x1000);
    t = func_ov002_021e92b0(0, 0x78000, 3, 0, 0x800);
    FLD(void *, t, 0x4c) = data_ov015_02213131;
    FLD(void *, t, 0x50) = data_ov015_02213147;
    FLD(void *, t, 0x54) = data_ov015_0221314d;
    FLD(s32, t, 0x4) = 3;
    func_ov002_021e4dac(o, t);
    FLD(u8 *, t, 0x48) = o;
    t = func_ov002_021e92b0(0x79000, 0x168000, 3, 1, 0x1000);
    FLD(void *, t, 0x4c) = data_ov015_02213131;
    FLD(void *, t, 0x50) = data_ov015_02213147;
    FLD(void *, t, 0x54) = data_ov015_02213158;
    FLD(s32, t, 0x4) = 3;
    func_ov002_021e4dac(o, t);
    FLD(u8 *, t, 0x48) = o;
}

void *func_ov015_0220fcec(u8 *self) {
    SET_VT(self, data_ov015_022131c4);
    FLD(u8, self, 0x4) = 0;
    FLD(u16, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 0;
    FLD(s32, self, 0x18) = 0;
    FLD(s32, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = -0x100000;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    func_02016cd8(0, self + 0x30, 0x80);
    FLD(s32, self, 0xb0) = 0;
    FLD(s32, self, 0xb4) = 0;
    func_02016d1c(0, self + 0xb8, 0x80);
    FLD(s32, self, 0x138) = 0;
    FLD(s32, self, 0x13c) = 0;
    FLD(s32, self, 0x140) = 0;
    FLD(s32, self, 0x8) = 0;
    return self;
}

void *func_ov015_0220fd74(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_022131c4);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x10));
    HEAP_POP(saved);
    {
    u32 saved2;
    HEAP_PUSH(saved2);
    {
    u8 *o = FLD(u8 *, self, 0x14);
    if (o != NULL) {
        if (o != NULL) {
            func_02041558(o);
            func_02041278(o + 0x88);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x14) = NULL;
    }
    }
    HEAP_POP(saved2);
    }

    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x18));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x28));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x2c));
    HEAP_POP(saved);

    return self;
}

void *func_ov015_0220fec0(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_022131c4);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x10));
    HEAP_POP(saved);
    {
    u32 saved2;
    HEAP_PUSH(saved2);
    {
    u8 *o = FLD(u8 *, self, 0x14);
    if (o != NULL) {
        if (o != NULL) {
            func_02041558(o);
            func_02041278(o + 0x88);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x14) = NULL;
    }
    }
    HEAP_POP(saved2);
    }

    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x18));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x28));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x2c));
    HEAP_POP(saved);

    func_0203de1c(self);
    return self;
}

static inline void Ov015_SetSeq(u8 *self, s32 n) {
    FLD(s32, self, 0x138) = n;
    FLD(s32, self, 0x13c) = 0;
    FLD(s32, self, 0x140) = 0;
}
BOOL func_ov015_02210014(u8 *self) {
    BOOL r = TRUE;
    switch (FLD(s32, self, 0x138)) {
    case 0:
        VCALL(self)->v14();
        Ov015_SetSeq(self, FLD(s32, self, 0x138) + 1);
    case 1:
        if (VCALL(self)->v18()) {
            Ov015_SetSeq(self, 10);
        }
        break;
    case 10:
        if (VCALL(self)->v1c()) {
            Ov015_SetSeq(self, 20);
        }
        break;
    case 20:
        if (VCALL(self)->v20()) {
            FLD(s32, self, 0x8) = 0;
            Ov015_SetSeq(self, 30);
        }
        break;
    case 30:
        if (!VCALL(self)->v24()) {
            VCALL(self)->v28();
            FLD(s32, self, 0x8) = 0;
            Ov015_SetSeq(self, 40);
        }
        break;
    case 40:
        if (VCALL(self)->v2c()) {
            Ov015_SetSeq(self, 50);
        }
        break;
    case 50:
        r = FALSE;
        break;
    }
    return r;
}

struct Ov015D48Bits {
    u8 lo : 4;
    u8 b4 : 1;
    u8 hi : 3;
};
static inline u8 *Ov015_ModelGetPart(u8 *m, s32 idx) {
    if (idx >= FLD(s32, m, 0x80)) {
        return NULL;
    }
    return FLD(u8 *, m, 0x78) + idx * 0x28;
}
static inline void Ov015_ModelPlayPart(u8 *m, s32 idx) {
    u8 *res = FLD(u8 *, m, 0x28);
    u8 *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015_ModelGetPart(m, idx);
    if (part != NULL && FLD(u8 *, part, 0x4) != NULL) {
        anim = FLD(void *, FLD(u8 *, part, 0x4), 0x30);
    } else {
        anim = func_02023410(FLD(void *, res, 0x4), **FLD(u16 **, func_02023390(FLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(m, anim, part, 0);
}
void func_ov015_0221015c(u8 *self) {
    u8 *p;
    if (!FLD(Ov015D48Bits, data_02097d48, 0xa30).b4) {
        return;
    }
    if (FLD(void *, self, 0x28) != NULL) {
        VCALL(FLD(void *, self, 0x28))->v20();
    }
    if (FLD(void *, self, 0x2c) != NULL) {
        VCALL(FLD(void *, self, 0x2c))->v20();
    }
    if (FLD(u8 *, self, 0x14) != NULL) {
        u8 *m = FLD(u8 *, self, 0x14);
        FLD(s32, m, 0xfc) = FLD(s32, self, 0x1c);
        FLD(s32, m, 0x100) = FLD(s32, self, 0x20);
        Ov015_ModelPlayPart(FLD(u8 *, self, 0x14), 0x1d);
    }
    p = FLD(u8 *, self, 0x18);
    if (p == NULL) {
        return;
    }
    VCALL(p)->v20(((FLD(s32, self, 0x1c) >> 12) + 0x80) - FLD(s32, p, 0x44) / 2, ((FLD(s32, self, 0x20) >> 12) + 0x60) - FLD(s32, p, 0x48) / 2);
    VCALL(FLD(void *, self, 0x18))->v90();
}

void func_ov015_02210298(u8 *self) {
    void *p = func_0203dd9c(0x58);
    if (p != NULL) {
        SET_VT(p, data_0208b318);
        VCALL(p)->v08();
        SET_VT(p, data_0208ba30);
        func_0204bfcc(p);
    }
    FLD(void *, self, 0x10) = p;
    func_0204bfe4(p, data_ov015_02213163, data_ov015_02213170);
}

void func_ov015_022102fc(u8 *self) {
    VCALL(FLD(void *, self, 0x10))->v2c();
}

}
