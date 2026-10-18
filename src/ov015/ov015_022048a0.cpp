#include "ov015/ov015.h"

extern "C" {

extern u8 *data_02097dc8;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd44;
extern Ov015Shared *data_ov015_02213368;
void func_02049a48(void *a, int b, int c, int d, int e);
void func_ov000_0218084c(void *a, s32 b, s32 c);
BOOL func_ov000_021633ac(void *p);
void *func_0206ec8c(u16 id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov000_0217357c(void *self);
void func_ov000_02163594(void *p);
void *func_ov000_02154b58(void *a, s32 b);
void func_ov015_0220566c(void *self, s32 id);
extern u8 data_ov015_02212b88[];

void func_ov015_022048a0(u8 *self) {
    if (FLD(s32, self, 0x50) != 0) {
        return;
    }
    if (FLD(u16, data_02097dc8, 0x12) & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x40), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x44), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
        func_ov000_0218084c(data_ov000_021ccd44, 0x1f, FLD(s32, self, 0xc));
        FLD(s32, self, 0x58) = 0;
        FLD(u32, self, 0x4) |= 6;
        FLD(s32, self, 0x2c) = 0;
    } else if (FLD(u8, self, 0x6a) != 0) {
        FLD(u32, FLD(u8 *, self, 0x3c), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x40), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x44), 0xc) |= 2;
        FLD(u32, FLD(u8 *, self, 0x48), 0xc) |= 2;
        FLD(u16, data_ov015_02213368, 0x8) = FLD(u16, self, 0x68);
        func_ov000_0218084c(data_ov000_021ccd44, 0x21, FLD(s32, self, 0xc));
        FLD(s32, self, 0x58) = 2;
        FLD(u32, self, 0x4) |= 6;
        FLD(s32, self, 0x2c) = 0;
    }
}

static inline u8 *Ov015_ListNth(u8 *o) {
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
void func_ov015_022049f8(u8 *self) {
    u32 saved;
    u8 *item;
    u8 *o2;
    u16 id;
    switch (FLD(s32, self, 0x8)) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    VCALL(FLD(void *, self, 0x3c))->v1c();
    VCALL(FLD(void *, self, 0x40))->v1c();
    VCALL(FLD(void *, self, 0x44))->v1c();
    VCALL(FLD(void *, self, 0x48))->v1c();
    if (FLD(void *, self, 0x50) == NULL) {
        return;
    }
    if (func_ov000_021633ac(FLD(void *, self, 0x50))) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x50));
    HEAP_POP(saved);
    FLD(u32, FLD(u8 *, self, 0x3c), 0xc) &= ~4;
    FLD(u32, FLD(u8 *, self, 0x44), 0xc) &= ~2;
    FLD(u32, FLD(u8 *, self, 0x40), 0xc) &= ~2;
    FLD(s32, FLD(u8 *, self, 0x40), 0x4) = 0;
    item = Ov015_ListNth(FLD(u8 *, self, 0x3c));
    id = FLD(u16, item, 0x6);
    o2 = FLD(u8 *, FLD(u8 *, self, 0x3c), 0x8);
    {
        void *s = func_0206ec8c(id);
        if (FLD(void *, o2, 0x40) != NULL) {
            func_ov000_0215bb14(FLD(void *, o2, 0x40), s);
            VCALL(FLD(void *, o2, 0x40))->v70();
        }
    }
    FLD(u16, o2, 0x68) = id;
}

void func_ov015_02204b88(u8 *self) {
    s32 a = FLD(s32, self, 0x5c);
    s32 r = 0x1000000;
    if (a > 0) {
        r = a - 0x8000;
    }
    FLD(s32, self, 0x5c) = r;
    if (FLD(s32, self, 0x60) >= 0x1000000) {
        FLD(s32, self, 0x60) = 0;
    } else {
        FLD(s32, self, 0x60) += 0x8000;
    }
}

void func_ov015_02204bb4(u8 *self) {
    if (FLD(void *, self, 0x24) == NULL) {
        return;
    }
    func_ov000_0217357c(self);
    VCALL(FLD(void *, self, 0x3c))->v20();
    VCALL(FLD(void *, self, 0x40))->v20();
    VCALL(FLD(void *, self, 0x44))->v20();
    VCALL(FLD(void *, self, 0x48))->v20();
    if (FLD(void *, self, 0x50) == NULL) {
        return;
    }
    func_ov000_02163594(FLD(void *, self, 0x50));
}

static inline BOOL Ov015_IsState5b(u8 *o) {
    return FLD(s32, o, 0x4) == 5 ? TRUE : FALSE;
}
BOOL func_ov015_02204c20(u8 *self, u8 *item) {
    if (item != NULL) {
        if (FLD(s32, item, 0x10) < 0) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            u8 *o;
            u8 *p;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            o = FLD(u8 *, self, 0x8);
            FLD(u16, o, 0x54) = FLD(u16, item, 0x6);
            p = FLD(u8 *, o, 0x48);
            if (p != NULL && Ov015_IsState5b(p)) {
                FLD(u32, p, 0xc) &= ~2;
                FLD(u32, FLD(u8 *, o, 0x48), 0xc) &= ~4;
                p = FLD(u8 *, o, 0x48);
                VCALL(p)->va8(func_ov000_02154b58(p, 1));
                FLD(u32, FLD(u8 *, o, 0x3c), 0xc) |= 4;
            }
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d00(u8 *self, u8 *ev) {
    if (ev != NULL) {
        u8 *o = FLD(u8 *, self, 0x8);
        void *m = func_0206ec8c(FLD(u16, ev, 0x6));
        if (FLD(void *, o, 0x40) != NULL && m != NULL) {
            func_ov000_0215bb14(FLD(void *, o, 0x40), m);
            VCALL(FLD(void *, o, 0x40))->v70();
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d48(u8 *self, u8 *ev) {
    func_ov015_0220566c(FLD(void *, self, 0x8), ev != NULL ? FLD(u16, ev, 0x6) : -1);
    return TRUE;
}

void *func_ov015_02204d68(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212b88);
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
    Ov015TaskBase_Dtor(self);
    return self;
}

void *func_ov015_02204ec4(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212b88);
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
    Ov015TaskBase_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_02205028(void) {
}

s32 func_ov015_0220502c(void) {
    return 1;
}

}
