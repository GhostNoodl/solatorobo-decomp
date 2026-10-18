#include "ov015/ov015.h"

extern "C" {

s32 func_ov000_0218f110(void *a);
extern u8 *data_ov002_021f0f9c;
extern u8 data_ov015_02212db0[];
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 func_ov000_021909a8(void *a, const void *b, const void *c);
u8 *func_0206fef8(u16 id);
void NNS_G3dRenderObjSetInitFunc(void *a, void *cb);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov015_022090fc(u8 *self);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191618(void *a);
void func_ov000_02191690(void *a);
void func_ov000_02191318(void *a, s32 b);
void MI_Copy36B(const void *src, void *dst);
void func_ov000_02190a80(void *a, s32 b);
void *func_ov002_021e4ee4(void *self, s32 a, s32 b);
void func_ov002_021e6360(void *p);
void func_ov002_021e61b4(void *p);
void func_ov000_021903b4(void *a);
void NNS_G3dGeFlushBuffer(void);
extern u8 data_ov015_02212eb0[];
extern u8 data_ov015_02212f64[];
void func_ov002_021e4d4c(void *self);

BOOL func_ov015_0220e024(u8 *self) {
    BOOL r = TRUE;
    if (FLD(s16, self, 0x4c) >= 0) {
        if (func_ov000_0218f110(self + 0x4c) == 0) r = FALSE;
    }
    if (FLD(s16, self, 0x26c) >= 0) {
        if (func_ov000_0218f110(self + 0x26c) == 0) r = FALSE;
    }
    return r;
}

BOOL func_ov015_0220e074(u8 *self) {
    Ov015SlotHost *h = (Ov015SlotHost *)self;
    s32 i;
    s32 cur;
    u8 *n;
    func_ov000_0218ffdc(self + 0x184, self + 0x4c, 0, 1);
    FLD(Ov015AnimFlags, self, 0x246).b4 = 0;
    func_ov000_021915a0(self + 0x184);
    FLD(Ov015AnimFlags, self, 0x246).b0 = 1;
    NNS_G3dRenderObjSetInitFunc(self + 0x1a8, (void *)func_ov015_022090fc);
    FLD(Ov015AnimFlags, self, 0x246).b5 = 0;
    FLD(u8 *, self, 0x1d4) = self + 0x49c;
    FLD(Ov015AnimFlags, self, 0x246).b8 = 1;
    FLD(s32, self, 0x4cc) = func_ov000_021909a8(self + 0x184, data_ov015_02212e14, data_ov015_02212e15);
    FLD(s32, self, 0x50c) = FLD(s16, func_0206fef8(FLD(u16, self, 0x498)), 0x10);
    func_ov000_0218ffdc(self + 0x3a8, self + 0x26c, 0, 1);
    if (FLD(u16, self, 0x3a4) != 0) {
        func_ov000_02190cb0(self + 0x3a8, FLD(void *, data_ov015_02212db0, 0), 0x1000, 0);
        func_ov000_02191690(self + 0x3a8);
        func_ov000_02191618(self + 0x3a8);
        func_ov000_02191318(self + 0x3a8, FLD(u16, self, 0x3a4) << 12);
    }
    FLD(Ov015AnimFlags, self, 0x46a).b4 = 0;
    FLD(Ov015AnimFlags, self, 0x46a).b0 = 1;
    cur = FLD(s32, self, 0x494);
    for (i = 0; i < 8; i++) {
        if (h->slots[i].b >= 0) {
            cur = i;
            break;
        }
    }
    FLD(s32, self, 0x494) = cur;
    if (cur >= 0) {
        func_ov000_02190cb0(self + 0x184, (const void *)h->slots[cur].a, 0x1000, 0);
        if (h->slots[FLD(s32, self, 0x494)].c) {
            func_ov000_021915a0(self + 0x184);
        } else {
            func_ov000_02191618(self + 0x184);
        }
        FLD(s16, self, 0x490) = h->slots[FLD(s32, self, 0x494)].d;
    }
    for (n = FLD(u8 *, data_ov002_021f0f9c, 0xdc); n != NULL; n = FLD(u8 *, n, 0x24)) {
        if (FLD(s32, n, 0x4) == 7) {
            if (FLD(s32, n, 0x4c) == 2) {
                FLD(u8 *, self, 0x518) = n;
            } else if (FLD(s32, n, 0x4c) == 3) {
                FLD(u8 *, self, 0x51c) = n;
            }
        }
    }
    return TRUE;
}

struct Ov015Bits8e294 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};
BOOL func_ov015_0220e294(u8 *self) {
    Ov015SlotHost *h = (Ov015SlotHost *)self;
    s32 sel;
    s32 i;
    s32 t;
    s32 cur;

    void *found;
    void *o;
    t = FLD(s32, data_ov002_021f0f9c, 0xd0);
    if (t >= FLD(s32, self, 0x1c)) return FALSE;

    cur = FLD(s32, self, 0x494);
    sel = cur;
    for (i = 0; i < 8; i++) {
        if (h->slots[i].b >= t) {
            sel = i;
            break;
        }
    }
    if (sel >= 0 && sel != cur) {
        func_ov000_02190cb0(self + 0x184, (const void *)h->slots[sel].a, 0x1000, 0);
        if (h->slots[sel].c) {
            func_ov000_021915a0(self + 0x184);
        } else {
            func_ov000_02191618(self + 0x184);
        }
        FLD(s16, self, 0x490) = h->slots[sel].d;
    }
    FLD(s32, self, 0x494) = sel;
    found = NULL;
    o = FLD(void *, self, 0x520);
    if (o == NULL) {
        found = func_ov002_021e4ee4(self, 3, -1);
    } else if (FLD(Ov015Bits8e294, o, 0xe8).b1) {
        found = func_ov002_021e4ee4(self, 3, FLD(s32, o, 0x18));
    }
    if (found != NULL) {
        if (FLD(void *, self, 0x520) != NULL) {
            func_ov002_021e6360(FLD(void *, self, 0x520));
        }
        func_ov002_021e61b4(found);
        FLD(void *, self, 0x520) = found;
    }
    o = FLD(void *, self, 0x520);
    if (o != NULL) {
        FLD(Ov015Vec, self, 0x4d0) = FLD(Ov015Vec, o, 0xdc);
        MI_Copy36B((u8 *)o + 0xb8, self + 0x4dc);
        FLD(Ov015Vec, self, 0x500) = FLD(Ov015Vec, FLD(u8 *, self, 0x520), 0x94);
    }
    func_ov000_02190a80(self + 0x184, FLD(s16, self, 0x490));
    func_ov000_02190a80(self + 0x3a8, FLD(s16, self, 0x490));
    return TRUE;
}

void func_ov015_0220e434(u8 *self) {
    void *o;
    s32 c;
    if (VCALL(self)->v08() == 0) {
        return;
    }
    c = FLD(s32, data_ov002_021f0f9c, 0xc);
    if (c == 1 && FLD(void *, self, 0x518) != NULL) {
        VCALL(FLD(void *, self, 0x518))->v20();
    } else if (c == 2 && FLD(void *, self, 0x51c) != NULL) {
        VCALL(FLD(void *, self, 0x51c))->v20();
    }

    {
        s32 k = FLD(s32, self, 0x50c);
        s32 x = Ov015_FxMul(FLD(s32, self, 0x500), k);
        s32 y = Ov015_FxMul(FLD(s32, self, 0x504), k);
        s32 z = Ov015_FxMul(FLD(s32, self, 0x508), k);
        *(Ov015VecC *)(self + 0x1fc) = *(Ov015VecC *)(self + 0x4d0);
        MI_Copy36B(self + 0x4dc, self + 0x208);
        FLD(s32, self, 0x22c) = x;
        FLD(s32, self, 0x230) = y;
        FLD(s32, self, 0x234) = z;
    }
    func_ov000_021903b4(self + 0x184);
    *(Ov015VecC *)(self + 0x420) = *(Ov015VecC *)(self + 0x4c0);
    MI_Copy36B(self + 0x49c, self + 0x42c);
    func_ov000_021903b4(self + 0x3a8);
    NNS_G3dGeFlushBuffer();
}

BOOL func_ov015_0220e55c(u8 *self) {
    return FLD(s32, self, 0xc) >= 3;
}

void func_ov015_0220e570(u8 *self, s32 a, s32 b, u8 c, s16 d) {
    s32 i;
    for (i = 0; i < 8; i++) {
        Ov015SlotHost *h = (Ov015SlotHost *)self;
        if (h->slots[i].a == 0) {
            h->slots[i].a = a;
            h->slots[i].b = b;
            h->slots[i].c = c;
            h->slots[i].d = d;
            return;
        }

    }
}

void *func_ov015_0220e5b8(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *func_ov015_0220e5c8(void *self) {
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_0220e5f0(void) {
}

BOOL func_ov015_0220e5f4(void) {
    return FALSE;
}

BOOL func_ov015_0220e5fc(void) {
    return TRUE;
}

BOOL func_ov015_0220e604(void) {
    return TRUE;
}

BOOL func_ov015_0220e60c(void) {
    return TRUE;
}

void *func_ov015_0220e614(void *self) {
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    return self;
}

}
