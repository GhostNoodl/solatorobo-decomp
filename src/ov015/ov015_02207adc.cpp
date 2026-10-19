#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212d23[];
extern u8 data_ov015_02212d29[];
void func_ov015_02208474(u8 *self);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void NNS_G3dRenderObjSetInitFunc(void *a, void *cb);
void func_ov000_02190e98(void *a, s32 b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
s32 func_ov000_021909a8(void *a, const void *b, const void *c);

struct Ov015Nib {
    u8 lo : 4;
    u8 hi : 4;
};
struct Ov015Anim8 {
    u8 anim[0xa8];
    s32 a;
    s32 b;
    s32 c;
    u8 pad[0x34];
};
struct Ov015Anim8Host {
    u8 pad[0x358];
    Ov015Anim8 e[8];
};
BOOL func_ov015_02207adc(u8 *self) {
    s32 i;
    func_ov000_0218ffdc(self + 0x138, self, 0, 1);
    func_ov000_02190cb0(self + 0x138, data_ov015_02212d23, 0x1000, 0);
    func_ov000_021915a0(self + 0x138);
    NNS_G3dRenderObjSetInitFunc(self + 0x15c, (void *)func_ov015_02208474);
    FLD(Ov015AnimFlags, self, 0x1fa).b5 = 0;
    FLD(Ov015AnimFlags, self, 0x1fa).b8 = 1;
    FLD(u8, self, 0xd04) = func_ov000_021909a8(self + 0x138, self + 0x6c, data_ov015_02212d29);
    for (i = 0; i < 8; i++) {
        Ov015Anim8Host *h = (Ov015Anim8Host *)self;
        func_ov000_0218ffdc(h->e[i].anim, self + 0x220, 0, 1);
        func_ov000_02190e98(h->e[i].anim, 0, 0x1000, 0);
        func_ov000_021915a0(h->e[i].anim);
        func_ov000_021911c8(h->e[i].anim, 0);
        h->e[i].a = 0x1333;
        h->e[i].b = 0x1333;
        h->e[i].c = 0x1c00;
    }
    func_ov000_0218ffdc(self + 0xbd0, self + 0xa98, 0, 1);
    FLD(Ov015Nib, self, 0xcd0).hi = FLD(Ov015Nib, self, 0xcd0).lo;
    FLD(Ov015Nib, self, 0xcd0).lo = 3;
    FLD(s32, self, 0xccc) = 0x2000;
    FLD(u16, self, 0xd38) = 0x32;
    return TRUE;
}


extern const void *data_ov015_02212634[];
extern u16 data_ov015_0221262c[];
void func_ov000_02191618(void *a);
void func_ov000_02190a80(void *a, s32 b);
void func_ov000_02191780(void *a);
void func_ov000_021917f8(void *a);
u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
s32 func_02040528(s32 max);
s32 func_02040498(s32 max);
Ov015V *func_02065f88(s32 id, void *pos);
s32 func_02065748(void *a, void *b);

void func_ov015_02207c30(u8 *self) {
    u16 ang = 0x8000;
    switch (FLD(u16, self, 0xd3a)) {
    case 0:
        func_ov000_02190cb0(self + 0x138, data_ov015_02212634[FLD(u16, self, 0xd3a)], 0x155, 0);
        func_ov000_021915a0(self + 0x138);
        break;
    case 1:
    case 2:
    case 3:
        func_ov000_02190cb0(self + 0x138, data_ov015_02212634[FLD(u16, self, 0xd3a)], 0x2ab, 0);
        func_ov000_02191618(self + 0x138);
        ang = data_ov015_0221262c[FLD(u16, self, 0xd3a)] + func_02040528(0x800);
        break;
    }
    func_ov000_02190a80(self + 0x138, 0x1000);
    if (FLD(u8, self, 0xd40)) {
        FLD(u16, self, 0xd22) = func_01ffc128(ang, FLD(u16, self, 0xd22), 0x19a, 1, 0x8000);
    }
    if (FLD(u16, self, 0xd3c) == 1) {
        s32 v = FLD(s16, self, 0xd3e);
        BOOL neg = FALSE;
        s32 i;
        if (v < 0) {
            v = (s16)-v;
            neg = TRUE;
        }
        for (i = 0; i < 8; i++) {
            Ov015Anim8Host *h = (Ov015Anim8Host *)self;
            func_ov000_021911c8(h->e[i].anim, v);
            if (neg) {
                func_ov000_02191780(h->e[i].anim);
            } else {
                func_ov000_021917f8(h->e[i].anim);
            }
            func_ov000_02190a80(h->e[i].anim, 0x1000);
        }
    }
    if (FLD(u8, self, 0xd42)) {
        if (FLD(Ov015V *, self, 0xd28) == NULL) {
            Ov015VecC p = FLD(Ov015VecC, self, 0xcf8);
            Ov015V *e = func_02065f88(0x322, &p);
            FLD(Ov015V *, self, 0xd28) = e;
            e->v14(0x1333, 0x1333, 0x1333);
            FLD(Ov015V *, self, 0xd28)->v34(0, 0, (u16)func_02040498(0x3fff));
            FLD(s32, FLD(u8 *, self, 0xd28), 0xc8) = -1;
            FLD(Ov015V *, self, 0xd28)->v08(3);
            FLD(s32, FLD(u8 *, self, 0xd28), 0x3c) = 0x2000;
            FLD(s32, self, 0xd2c) = 0x5a;
        } else {
            if (func_02040498(100) < 5) {
                Ov015VecC p = FLD(Ov015VecC, FLD(u8 *, self, 0xd28), 0x58);
                Ov015V *e = func_02065f88(0x320, &p);
                e->v14(0x800, 0x800, 0x800);
                e->v08(3);
            }
            if (--FLD(s32, self, 0xd2c) < 0) {
                FLD(Ov015V *, self, 0xd28)->v34(0, 0, (u16)func_02040498(0x3fff));
                FLD(s32, self, 0xd2c) = 0x5a;
            }
        }
        if (FLD(Ov015V *, self, 0xd30) == NULL) {
            Ov015V *e = func_02065f88(0x322, self + 0xd4c);
            FLD(Ov015V *, self, 0xd30) = e;
            e->v34(0, 0, 0x3fff);
            FLD(s32, FLD(u8 *, self, 0xd30), 0xc8) = -1;
            FLD(Ov015V *, self, 0xd30)->v08(1);
            FLD(s32, FLD(u8 *, self, 0xd30), 0x50) = -0xaa000;
            FLD(s32, FLD(u8 *, self, 0xd30), 0x54) = -0x37000;
            FLD(s32, self, 0xd34) = 10;
        } else {
            if (--FLD(s32, self, 0xd34) < 0) {
                FLD(s32, self, 0xd34) = 0;
            }
        }
    } else {
        if (func_02065748(data_0214a420, FLD(void *, self, 0xd28))) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0xd28));
            HEAP_POP(saved);
        }
        if (func_02065748(data_0214a420, FLD(void *, self, 0xd30))) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0xd30));
            HEAP_POP(saved);
        }
    }
}

}
