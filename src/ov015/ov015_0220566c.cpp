#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
extern u8 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
extern Ov015Shared *data_ov015_02213368;
extern u8 *data_0214a424;
void *func_02049a48(void *a, int b, int c, int d, int e);
u8 *func_0206ef88(u16 id);
void func_0203cc58(int a, int b, int c);
extern u8 *data_02097dc8;
void *func_ov000_0218084c(void *a, s32 b, s32 c);
BOOL func_ov000_021633ac(void *p);
void *func_0206ec8c(u16 id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov000_02163594(void *p);
extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
void func_0206ecd4(s32 n, void *buf, u16 id);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void *func_ov000_02154b58(void *a, s32 b);
BOOL func_ov015_02206888(u8 *o);

void func_ov015_0220566c(u8 *self, s32 a) {
    if (a == 1 || a == -1) {
        FLD(u16, self, 0x54) = 0xffff;
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) &= ~4;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    } else {
        u32 r;
        u16 price;
        FLD(s32, self, 0x50) = 4;
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x40), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x44), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        data_ov000_021ccd34 = 1;
        ((Ov015ObjFlags *)data_ov000_021ccd44)->b0 = 1;
        FLD(s32, self, 0x2c) = 0;
        FLD(u32, self, 0x4) |= 6;
        FLD(u16, data_ov015_02213368, 0xa) = FLD(u16, self, 0x54);
        price = FLD(u16, func_0206ef88(FLD(u16, data_ov015_02213368, 0x8)), 0x0);
        r = 0;
        if (FLD(u32, data_0214a424, 0x20) > price) {
            r = FLD(u32, data_0214a424, 0x20) - price;
        }
        FLD(u32, data_0214a424, 0x20) = r;
        func_0203cc58(FLD(s32, FLD(u8 *, self, 0x3c), 0x34), 2, -1);
    }
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 4;
}

static inline BOOL Ov015_IsState5c(u8 *o) {
    return FLD(s32, o, 0x4) == 5 ? TRUE : FALSE;
}
void func_ov015_022057dc(u8 *self) {
    if (FLD(s32, self, 0x4c) != 0) {
        return;
    }
    if (!Ov015_IsState5c(FLD(u8 *, self, 0x48))) {
        return;
    }
    if (FLD(u16, data_02097dc8, 0x12) != 2) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x40), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x44), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
    func_ov000_0218084c(data_ov000_021ccd44, 0x20, FLD(s32, self, 0xc));
    FLD(u32, self, 0x4) |= 6;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x50) = 1;
}

static inline u8 *Ov015_ListNthB(u8 *o) {
    u8 *r = NULL;
    u8 *p = FLD(u8 *, o, 0x98);
    if (p != NULL) {
        s32 n = FLD(s8, o, 0xb1);
        while (n-- != 0) {
            p = FLD(u8 *, p, 0x2c);
        }
        r = p;
    }
    return r;
}
void func_ov015_022058d0(u8 *self) {
    u32 saved;
    void *s;
    switch (FLD(s32, self, 0x8)) {
    case 8:
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    VCALL(FLD(void *, self, 0x3c))->v1c();
    VCALL(FLD(void *, self, 0x40))->v1c();
    VCALL(FLD(void *, self, 0x44))->v1c();
    VCALL(FLD(void *, self, 0x48))->v1c();
    if (FLD(void *, self, 0x4c) == NULL) {
        return;
    }
    if (func_ov000_021633ac(FLD(void *, self, 0x4c))) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x4c));
    HEAP_POP(saved);
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) &= ~4;
    FLD(u32, FLD(u8 *, self, 0x40), 0xc) &= ~4;
    FLD(u32, FLD(u8 *, self, 0x44), 0xc) &= ~2;
    FLD(u32, FLD(u8 *, self, 0x40), 0xc) &= ~2;
    FLD(s32, FLD(u8 *, self, 0x40), 0x4) = 0;
    s = func_0206ec8c(FLD(u16, Ov015_ListNthB(FLD(u8 *, self, 0x3c)), 0x6));
    if (FLD(void *, self, 0x40) != NULL && s != NULL) {
        func_ov000_0215bb14(FLD(void *, self, 0x40), s);
        VCALL(FLD(void *, self, 0x40))->v70();
    }
}

void func_ov015_02205a60(void) {
}

void func_ov015_02205a64(u8 *self) {
    if (VCALL(self)->v28() == 0) {
        return;
    }
    VCALL(FLD(void *, self, 0x3c))->v20();
    VCALL(FLD(void *, self, 0x40))->v20();
    VCALL(FLD(void *, self, 0x44))->v20();
    VCALL(FLD(void *, self, 0x48))->v20();
    if (FLD(void *, self, 0x4c) == NULL) {
        return;
    }
    func_ov000_02163594(FLD(void *, self, 0x4c));
}

BOOL func_ov015_02205ad4(u8 *self, u8 *ev) {
    u8 *o = FLD(u8 *, self, 0x8);
    if (ev != NULL) {
        func_0206ecd4(0x100, o + 0x64, FLD(u16, ev, 0x6));
        if (FLD(void *, o, 0x44) != NULL) {
            func_ov000_0215bb14(FLD(void *, o, 0x44), o + 0x64);
            VCALL(FLD(void *, o, 0x44))->v70();
        }
    } else {
        void *m = func_0204c0e8(data_02149ef8, 0x9d);
        if (FLD(void *, o, 0x44) != NULL) {
            func_ov000_0215bb14(FLD(void *, o, 0x44), m);
            VCALL(FLD(void *, o, 0x44))->v70();
        }
    }
    return TRUE;
}

BOOL func_ov015_02205b48(u8 *self, u8 *ev) {
    if (ev != NULL) {
        u8 *o = FLD(u8 *, self, 0x8);
        u8 *t;
        FLD(u32, FLD(u8 *, o, 0x4c), 0xc) &= ~2;
        FLD(u32, FLD(u8 *, o, 0x4c), 0xc) &= ~4;
        t = FLD(u8 *, o, 0x4c);
        VCALL(t)->va8(func_ov000_02154b58(t, 1));
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov015_02205bc8(u8 *self, u8 *item) {
    u8 *o = FLD(u8 *, self, 0x8);
    if (item != NULL) {
        switch (FLD(u16, item, 0x6)) {
        case 0:
            if (func_ov015_02206888(o)) {
                func_02049a48(data_02097e4c, 0x30, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            break;
        default:
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            break;
        }
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    FLD(u32, FLD(u8 *, o, 0x4c), 0xc) |= 2;
    FLD(u32, FLD(u8 *, o, 0x4c), 0xc) |= 4;
    return FALSE;
}

void func_ov015_02205c7c(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x40));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x44));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x48));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x4c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x50));
    HEAP_POP(saved);
}

void func_ov015_02205de4(void) {
}

s32 func_ov015_02205de8(void) {
    return 1;
}

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cafc0[];
extern u8 data_ov000_021cad50[];
extern void *data_0208ccc8;
extern u8 data_ov015_022129ac[];
void func_ov000_02157c90(void *a, void *b);
void func_ov000_02157d2c(void *a, void *b);
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
BOOL func_0206f66c(u16 id);
u8 *func_0206f000(u16 id);
void *func_0206ec48(u16 id);
s32 func_0206f080(u16 id);
void func_ov000_0215d980(void *a, void *b, s32 c);
void func_ov000_02173648(void *self);

static inline void Ov015_SetXYZ16(u8 *o, s16 x, s16 y, s16 z) {
    FLD(s16, o, 0x64) = x;
    FLD(s16, o, 0x66) = y;
    FLD(s16, o, 0x68) = z;
}

static inline void Ov015_SetXYZ32(u8 *o, s32 x, s32 y, s32 z) {
    FLD(s32, o, 0x58) = x;
    FLD(s32, o, 0x5c) = y;
    FLD(s32, o, 0x60) = z;
}

void func_ov015_02205df0(u8 *self) {
    u8 *p;
    s32 i;
    u16 id;
    void *res;
    if (VCALL(self)->v28()) {
        return;
    }
    res = data_02149ef8;
    p = (u8 *)func_0203dd9c(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb2a8);
    }
    FLD(u8 *, self, 0x3c) = p;
    VCALL(FLD(u8 *, self, 0x3c))->v10(func_0204c0e8(res, 0xca));
    VCALL(FLD(u8 *, self, 0x3c))->v14(func_0204c0e8(res, 0xcb));
    func_ov000_02157c90(FLD(u8 *, self, 0x3c), func_0204c0e8(res, 0xa1));
    func_ov000_02157d2c(FLD(u8 *, self, 0x3c), func_0204c0e8(res, 0x3f));
    FLD(s32, FLD(u8 *, self, 0x3c), 0x20) = 5;
    FLD(s32, FLD(u8 *, self, 0x3c), 0x24) = 0xf8;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x3c), 0, 0x2c, -0xccd);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x3c), -0x100, 0, -0xccd);
    FLD(s32, FLD(u8 *, self, 0x3c), 0x2c) = 1;
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 0x400000;
    FLD(u8, FLD(u8 *, self, 0x3c), 0xc0) = 0x78;
    FLD(u8, FLD(u8 *, self, 0x3c), 0xc1) = 5;
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 0x40000;
    func_ov000_021546ec(FLD(u8 *, self, 0x3c), data_0208ccc8, data_ov015_022129ac, 0xffff);
    for (i = 0; i < 13; i++) {
        id = i | 0xc000;
        if (!func_0206f66c(id)) {
            u8 *e = func_0206f000(id);
            switch (e[0]) {
            case 0: {
                u16 k = FLD(u16, e, 2);
                void *a = func_0206ec48(k);
                FLD(s32, VCALL(FLD(u8 *, self, 0x3c))->v74(a, k, (u16)func_0206f080(k), FLD(u16, e, 4)), 0x10) = id;
                break;
            }
            case 1: {
                void *a = func_0206ec48(id);
                FLD(s32, VCALL(FLD(u8 *, self, 0x3c))->v74(a, id, (u16)func_0206f080(id), FLD(u16, e, 4)), 0x10) = id;
                break;
            }
            }
        }
    }
    {
        u8 *o = FLD(u8 *, self, 0x3c);
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    FLD(u8 *, FLD(u8 *, self, 0x3c), 0x8) = self;
    FLD(void *, FLD(u8 *, self, 0x3c), 0x84) = (void *)func_ov015_02205b48;
    FLD(void *, FLD(u8 *, self, 0x3c), 0x88) = (void *)func_ov015_02205ad4;
    VCALL(FLD(u8 *, self, 0x3c))->v08();
    p = (u8 *)func_0203dd9c(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x40) = p;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x40), 0x86, 0x87, -0xccd);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x40), 0x100, 0, -0xccd);
    FLD(s32, FLD(u8 *, self, 0x40), 0x2c) = 1;
    FLD(s32, FLD(u8 *, self, 0x40), 0x84) = 1;
    func_ov000_0215d980(FLD(u8 *, self, 0x40), FLD(void *, data_0214a424, 0x618), 0);
    VCALL(FLD(u8 *, self, 0x40))->v08();
    p = (u8 *)func_0203dd9c(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x44) = p;
    FLD(s32, FLD(u8 *, self, 0x44), 0x24) = 0xf8;
    FLD(s32, FLD(u8 *, self, 0x44), 0x20) = 2;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x44), 4, 0x95, -0x99a);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x44), -0x100, 0, -0x99a);
    FLD(s32, FLD(u8 *, self, 0x44), 0x2c) = 1;
    VCALL(FLD(u8 *, self, 0x44))->v08();
    if (FLD(s16, FLD(u8 *, self, 0x3c), 0x9c) != 0) {
        func_0206ecd4(0x100, self + 0x64, FLD(u16, Ov015_ListNthB(FLD(u8 *, self, 0x3c)), 0x6));
        if (FLD(void *, self, 0x44) != NULL) {
            func_ov000_0215bb14(FLD(void *, self, 0x44), self + 0x64);
            VCALL(FLD(void *, self, 0x44))->v70();
        }
    } else {
        void *s = func_0204c0e8(data_02149ef8, 0x9d);
        if (FLD(void *, self, 0x44) != NULL) {
            func_ov000_0215bb14(FLD(void *, self, 0x44), s);
            VCALL(FLD(void *, self, 0x44))->v70();
        }
    }
    p = (u8 *)func_0203dd9c(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x48) = p;
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 0x4000000;
    FLD(s32, FLD(u8 *, self, 0x48), 0x2c) = 1;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x48), 0x91, 0x12, -0x333);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x48), 0x100, 0, -0x333);
    FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 0x20000000;
    VCALL(FLD(u8 *, self, 0x48))->vf4(1, func_0204c0e8(res, 0x32));
    VCALL(FLD(u8 *, self, 0x48))->vf4(2, func_0204c0e8(res, 0x33));
    VCALL(FLD(u8 *, self, 0x48))->v08();
    p = (u8 *)func_0203dd9c(0x1e4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb1b0);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb0b8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cafc0);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x4c) = p;
    VCALL(FLD(u8 *, self, 0x4c))->v10(func_0204c0e8(res, 0xd6));
    FLD(void *, FLD(u8 *, self, 0x4c), 0x84) = (void *)func_ov015_02205bc8;
    FLD(s16, FLD(u8 *, self, 0x4c), 0x68) = -0x666;
    VCALL(FLD(u8 *, self, 0x4c))->v08();
    FLD(u8 *, FLD(u8 *, self, 0x4c), 0x8) = self;
    FLD(u32, FLD(u8 *, self, 0x4c), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x4c), 0xc) |= 4;
    p = (u8 *)func_0203dd9c(0xe8);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cad50);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x50) = p;
    FLD(s32, FLD(u8 *, self, 0x50), 0x1c) = 4;
    VCALL(FLD(u8 *, self, 0x50))->v08();
    FLD(u32, FLD(u8 *, self, 0x50), 0xc) |= 0x20000;
    FLD(s16, FLD(u8 *, self, 0x50), 0x68) = -0x333;
    FLD(u32, FLD(u8 *, self, 0x50), 0xc) |= 2;
    FLD(s32, self, 0x20) = FLD(s32, FLD(u8 *, self, 0x3c), 0x34);
    func_ov000_02173648(self);
}

}
