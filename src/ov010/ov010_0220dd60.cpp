#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_022102e0[];
extern void *data_0214a420;
extern const Ov010Vec data_ov010_0220f57c;
extern u8 data_ov010_0220f534[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_0219429c(void *self);
extern void func_ov000_02194758(void *self);
extern void MTX_Identity33_(void *m);
extern void func_02065860(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern s32 func_ov000_021903b4(void *p);
extern void func_ov000_02190cb0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern void func_0203f364(void *p);
extern void func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov010_0220dd60_Reset(void *self) {
    FLD(s32, self, 0xd0) = -1;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    MTX_Identity33_((u8 *)self + 0xdc);
}

void *func_ov010_0220dd60(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_022102e0;
    Ov010_0220dd60_Reset(self);
    return self;
}

static inline void Ov010_0220dd60_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_022102e0;
    func_02065860(data_0214a420, FLD(s32, self, 0xd4));
    Ov010_0220dd60_Reset(self);
    func_ov000_0219429c(self);
}

void *func_ov010_0220dd9c(void *self) {
    Ov010_0220dd60_Dtor(self);
    return self;
}

void *func_ov010_0220ddf0(void *self) {
    Ov010_0220dd60_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_0220de4c(void *self, s32 a) {
    if (FLD(u8, self, 0x14) == 1) {
        FLD(s32, self, 0xd0) = a;
    }
}

s32 func_ov010_0220de5c(void *self) {
    u8 m[0x24];
    s32 r = 0;
    if (FLD(void *, self, 0x38) != NULL && FLD(s32, self, 0xd0) != -1) {
        switch (FLD(s32, self, 0xd0)) {
        case 0:
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            break;
        case 1:
            MTX_RotZ33_(m, OV010_SIN(0x4000), OV010_COS(0x4000));
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            MTX_Concat33(m, (u8 *)self + 0xdc, (u8 *)self + 0xdc);
            break;
        }
        FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0x78) = FLD(Ov010Vec, self, 0x70);
        MI_Copy36B((u8 *)self + 0xdc, FLD(u8 *, self, 0x38) + 0x84);
        r = func_ov000_021903b4(FLD(void *, self, 0x38));
    }
    return r;
}

void func_ov010_0220df64(void *self) {
    func_ov000_02194758(self);
    Ov010Vec v = data_ov010_0220f57c;
    FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0xa8) = v;
}

void func_ov010_0220dfac(void *self) {
    void *m;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(s32, self, 0xd0) == -1) {
        FLD(s32, self, 0xd0) = 0;
    }
    func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(s32, data_ov010_0220f534, 0xc), 0x1000, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    m = FLD(void *, self, 0x48);
    if (m != NULL) {
        FLD(Ov010Flags, m, 0x9a).b0 = 0;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b1 = 0;
        FLD(Ov010Flags, m, 0x9a).b4 = 0;
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b2 = 0;
        FLD(Ov010Flags, m, 0x9a).b5 = 0;
    }
    func_ov000_02198360(FLD(void *, self, 0x40), 4, 0);
}

}
