#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
extern u8 *data_02097dc8;
extern u8 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
void func_ov000_0218084c(void *a, s32 b, s32 c);
void *func_ov000_02154b58(void *a, s32 b);
void func_0203cc58(int a, int b, int c);
extern void *data_02149ef8;
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_02203ee0(u8 *self);
void func_ov015_02207c30(u8 *p);
void func_02012d78(void *src, void *dst);
void func_02012fb8(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
BOOL func_ov000_021633ac(void *p);
extern Ov015Vec data_ov015_02212614;
extern Ov015Vec data_ov015_02212620;
void func_ov000_02163594(void *p);
void func_ov000_0217357c(void *self);
void func_ov015_0220daf4(void *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
extern u8 data_02092844[];
extern u8 data_02092800[];
void func_02011ff0(void *a, void *b, void *c, void *d);
void func_02012758(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g);
void func_ov015_02208070(void *p);
void *func_0206ec8c(u16 id);
extern u8 *data_0214a424;

static inline u8 *Ov015_ListNth2(u8 *o) {
    u8 *p = FLD(u8 *, o, 0x98);
    s32 n;
    if (p == NULL) return NULL;
    n = FLD(s8, o, 0xb1);
    while (n-- != 0) {
        p = FLD(u8 *, p, 0x2c);
    }
    return p;

}
struct Ov015Bits32a {
    u32 b0 : 1;
    u32 rest : 31;
};
void func_ov015_022038c8(u8 *self) {
    u16 keys;
    if (FLD(void *, self, 0x8c) != NULL) return;
    keys = FLD(u16, data_02097dc8, 0x12);
    if (FLD(u8, self, 0xa4) != 0) {
        u8 *item = Ov015_ListNth2(FLD(u8 *, self, 0x80));
        switch (FLD(u16, item, 0x6)) {
        case 0:
            FLD(s32, self, 0x94) = 1;
            func_ov000_0218084c(data_ov000_021ccd44, 0x20, FLD(s32, self, 0xc));
            FLD(s32, self, 0x2c) = 0;
            FLD(u32, self, 0x4) |= 6;
            FLD(u32, FLD(u8 *, self, 0x80), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x84), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 2;
            break;
        case 1:
            FLD(s32, self, 0x94) = 3;
            func_ov000_0218084c(data_ov000_021ccd44, 0x22, FLD(s32, self, 0xc));
            FLD(s32, self, 0x2c) = 0;
            FLD(u32, self, 0x4) |= 6;
            FLD(u32, FLD(u8 *, self, 0x80), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x84), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 2;
            break;
        case 2:
            FLD(s32, self, 0x94) = 5;
            data_ov000_021ccd34 = 1;
            FLD(Ov015Bits32a, data_ov000_021ccd44, 0x0).b0 = 1;
            FLD(s32, self, 0x2c) = 0;
            FLD(u32, self, 0x4) |= 6;
            FLD(u32, FLD(u8 *, self, 0x80), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x84), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 2;
            func_0203cc58(FLD(s32, FLD(u8 *, self, 0x80), 0x34), 2, -1);
            break;
        }
    } else if (keys & 2) {
        u8 *o;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        o = FLD(u8 *, self, 0x80);
        VCALL(o)->va8(func_ov000_02154b58(o, 2));
    }
    FLD(u8, self, 0xa4) = 0;
}

static inline u8 *Ov015_ListNth3(u8 *o) {
    u8 *p = FLD(u8 *, o, 0x98);
    s32 n;
    if (p == NULL) return NULL;
    n = FLD(s8, o, 0xb1);
    while (n-- != 0) {
        p = FLD(u8 *, p, 0x2c);
    }
    return p;
}
void func_ov015_02203ab8(u8 *self) {
    Ov015Vec out;
    Ov015Vec v;
    s32 k;
    switch (FLD(s32, self, 0x8)) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 13:
        func_ov015_02203ee0(self);
        break;
    }
    k = Ov015_FxMul(0x1000 - FLD(s32, FLD(u8 *, self, 0x80), 0x38), 0x3000);
    v.x = -0x64a4;
    v.y = 0;
    v.z = 0x3ae1;
    func_02012d78(&v, &v);
    func_02012fb8(k, &v, &data_ov015_02212614, &out);
    FLD(Ov015Vec, self, 0x44) = out;
    func_02012fb8(k, &v, &data_ov015_02212620, &out);
    FLD(Ov015Vec, self, 0x50) = out;
    if (FLD(void *, self, 0x8c) != NULL && !func_ov000_021633ac(FLD(void *, self, 0x8c))) {
        u32 saved;
        u8 *o;
        u8 *t;
        void *s;
        HEAP_PUSH(saved);
        DELETE_V(FLD(void *, self, 0x8c));
        HEAP_POP(saved);
        FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~4;
        FLD(u32, FLD(u8 *, self, 0x84), 0xc) &= ~4;
        FLD(u32, FLD(u8 *, self, 0x88), 0xc) &= ~2;
        FLD(u32, FLD(u8 *, self, 0x84), 0xc) &= ~2;
        FLD(s32, FLD(u8 *, self, 0x84), 0x4) = 0;
        o = FLD(u8 *, self, 0x80);
        {
            u8 *item = Ov015_ListNth3(o);
            u16 n = FLD(u16, item, 0x6);
            void *d = data_02149ef8;
            s32 id;
            t = FLD(u8 *, o, 0x8);
            switch (n) {
            case 0:
                id = 0xc7;
                break;
            case 1:
                id = 0xcb;
                break;
            case 2:
                id = 0xd5;
                break;
            default:
                goto skip;
            }
            s = func_0204c0e8(d, id);
        }
    skip:
        if (FLD(void *, t, 0x84) != NULL) {
            func_ov000_0215bb14(FLD(void *, t, 0x84), s);
            VCALL(FLD(void *, t, 0x84))->v70();
        }
    }
    func_ov015_02207c30(FLD(u8 *, self, 0x3c));
    FLD(Ov015V *, self, 0x80)->v1c();
    FLD(Ov015V *, self, 0x84)->v1c();
    FLD(Ov015V *, self, 0x88)->v1c();
}

void func_ov015_02203d60(void) {
}

static inline void Ov015_02203d64_Cam(u8 *self) {
    data_020927f8.a = FLD(Ov015Vec, self, 0x44);
    data_020927f8.b = FLD(Ov015Vec, self, 0x5c);
    data_020927f8.c = FLD(Ov015Vec, self, 0x50);
    func_02011ff0(self + 0x44, self + 0x5c, self + 0x50, data_02092844);
    data_020927f8.fc &= ~0xe8;
    if (FLD(u8, self, 0x7e) == 1) {
        func_02012758(FLD(s16, self, 0x70), FLD(s16, self, 0x72), FLD(s16, self, 0x74), FLD(s32, self, 0x68),
                      FLD(s32, self, 0x6c), 0x1000, data_02092800);
        data_020927f8.fc &= ~0x50;
        FLD(u8, self, 0x7e) = 0;
    }
}
void func_ov015_02203d64(u8 *self) {
    u8 *o;
    if (FLD(void *, self, 0x24) == NULL) return;
    func_ov000_0217357c(self);
    Ov015_02203d64_Cam(self);
    func_ov015_02208070(FLD(void *, self, 0x3c));
    o = FLD(u8 *, self, 0x3c);
    {
        Ov015Vec v = FLD(Ov015Vec, o, 0xd14);
        func_ov015_0220daf4(FLD(void *, self, 0x40), &v, 0x2000, 0x2000, FLD(u16, o, 0xd22), FLD(u16, o, 0xd20));
    }
    VCALL(FLD(void *, self, 0x80))->v20();
    VCALL(FLD(void *, self, 0x84))->v20();
    VCALL(FLD(void *, self, 0x88))->v20();
    if (FLD(void *, self, 0x8c) != NULL) func_ov000_02163594(FLD(void *, self, 0x8c));
}

void func_ov015_02203ee0(u8 *self) {
    u8 *o = FLD(u8 *, self, 0x3c);
    u16 pad;
    if (o == NULL) {
        return;
    }
    {
    u16 a = (FLD(s32, self, 0xa8) % 1200) * 0xffff / 1200;
    FLD(u16, o, 0xd20) = 0;
    FLD(u16, o, 0xd22) = a;
    FLD(u16, o, 0xd24) = 0;
    }
    pad = FLD(u16, data_02097dc8, 0x10);
    if (pad & 0x20) {
        FLD(u16, FLD(u8 *, self, 0x3c), 0xd3a) = 2;
        FLD(s32, self, 0xac) = 0x3c;
    } else if (pad & 0x10) {
        FLD(u16, FLD(u8 *, self, 0x3c), 0xd3a) = 1;
        FLD(s32, self, 0xac) = 0x3c;
    } else if (pad & 0x800) {
        FLD(u16, FLD(u8 *, self, 0x3c), 0xd3a) = 3;
        FLD(s32, self, 0xac) = 0x3c;
    }
    if (FLD(s32, self, 0xac) == 0) {
        FLD(u16, FLD(u8 *, self, 0x3c), 0xd3a) = 0;
        FLD(s32, self, 0xac) = 0x3c;
    }
    if (++FLD(s32, self, 0xa8) > 60000) {
        FLD(s32, self, 0xa8) = 0;
    }
    if (--FLD(s32, self, 0xac) < 0) {
        FLD(s32, self, 0xac) = 0;
    }
}

BOOL func_ov015_02203fec(u8 *self, u8 *ev) {
    u8 *o;
    u16 id;
    id = FLD(u16, ev, 0x6);
    o = FLD(u8 *, self, 0x8);
    void *m = func_0206ec8c(id);
    if (FLD(void *, o, 0x40) != NULL) {
        func_ov000_0215bb14(FLD(void *, o, 0x40), m);
        VCALL(FLD(void *, o, 0x40))->v70();
    }
    FLD(u16, o, 0x68) = id;
    return TRUE;
}

BOOL func_ov015_02204030(u8 *self, u8 *item) {
    BOOL r = TRUE;
    u8 *o = FLD(u8 *, self, 0x8);
    if (item != NULL) {
        if (FLD(s32, item, 0x10) == -1) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else if (FLD(u32, item, 0xc) > FLD(u32, data_0214a424, 0x20)) {
            void *s = func_0204c0e8(data_02149ef8, 0x9b);
            if (FLD(void *, o, 0x40) != NULL) {
                func_ov000_0215bb14(FLD(void *, o, 0x40), s);
                VCALL(FLD(void *, o, 0x40))->v70();
            }
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            FLD(u8, o, 0x6a) = 1;
            FLD(u16, o, 0x68) = FLD(u16, item, 0x6);
            r = FALSE;
        }
    }
    return r;
}

void func_ov015_02204110(u8 *self) {
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

void func_ov015_02204278(void) {
}

s32 func_ov015_0220427c(void) {
    return 1;
}

}
