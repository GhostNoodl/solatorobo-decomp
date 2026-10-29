#include "ov010/ov010.h"

struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
};

extern "C" {
extern Ov010Vec data_ov010_0220fe38;
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void func_ov010_02203bf8(Ov010FxSet *p);

extern Ov010Vec data_ov010_0220efdc;
extern void *data_02097e4c;
extern void func_0203f364(void *p);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);
extern void func_ov010_02203f08(void *fx);

class Ov010Fx2 {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    s32 timer;
    s32 scale;
};
extern Ov010Fx2 *func_02065f88(s32 a, void *b);

static inline Ov010Fx2 *Ov010_SpawnRing(s32 a, void *b) {
    Ov010Fx2 *fx = func_02065f88(a, b);
    if (fx != NULL) {
        fx->timer = 0;
        fx->scale = 0;
    }
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02203f08;
    return fx;
}

void func_ov010_022029a4(void *self) {
    s32 a = 0;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    switch (FLD(u16 *, self, 0x40)[0]) {
    case 0: {
        void *m;
        FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 1;
        FLD(s32, self, 0x9c) = a;
        FLD(s32, self, 0xa0) = a;
        FLD(s32, self, 0xa4) = a;
        FLD(s32, self, 0xa8) = a;
        Ov010_SpawnRing(0x12c, (u8 *)self + 0x70)->v0c(0x2000);
        FLD(u16 *, self, 0x40)[0] = 1;
        FLD(Ov010Flags, FLD(void *, self, 0x44), 0x22).b1 = 0;
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = FLD(void *, self, 0x38);
        FLD(u16, m, 0xb6) = 0x53ff;
        FLD(u16, m, 0xb8) = 0x53ff;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0x14;
        func_02049f44(data_02097e4c, 0x2b, &FLD(Ov010Vec, self, 0x70), 0);
        break;
    }
    case 1: {
        void *m;
        b = 0x10;
        d = 0x400;
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x41) {
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 2;
        }
        FLD(Ov010Flags, FLD(void *, self, 0x44), 0x22).b1 = 0;
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = FLD(void *, self, 0x38);
        FLD(u16, m, 0xb6) = 0x53ff;
        FLD(u16, m, 0xb8) = 0x53ff;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        break;
    }
    case 2:
        b = 2;
        c = 2;
        d = 0x400;
        FLD(s32, self, 0xe0) = Ov010_FxMul(FLD(s32, self, 0xe0), 0xfa0);
        FLD(s32, self, 0xe4) = Ov010_FxMul(FLD(s32, self, 0xe4), 0xfa0);
        FLD(s32, self, 0xe8) = Ov010_FxMul(FLD(s32, self, 0xe8), 0xfa0);
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x3c) {
            Ov010FxSet *s;
            FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0x1f;
            s = FLD(Ov010FxSet *, self, 0xd8);
            if (s->b0) {
                s->b1 = 1;
                s->unk_06 = 0x1000;
            }
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 3;
        }
        break;
    case 3:
        a = 4;
        c = 0x10;
        d = 0x2000;
        break;
    }
    VEC_MultAdd(a, &data_ov010_0220efdc, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
    VEC_MultAdd(b, &FLD(Ov010Vec, self, 0xec), &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
    VEC_MultAdd(c, &data_ov010_0220fe38, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
    func_ov003_021d9aec(&FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0), d);
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0x70));
    if (FLD(Ov010FxSet *, self, 0xd8) != NULL) {
        func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
    }
}

void func_ov010_02202c9c(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        Ov010FxSet *s;
        FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0x1f;
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x1000;
        }
        FLD(u16, FLD(void *, self, 0x40), 0)++;
    }
    {
        FLD(s32, self, 0xe0) = Ov010_FxMul(FLD(s32, self, 0xe0), 0xf80);
        FLD(s32, self, 0xe4) = Ov010_FxMul(FLD(s32, self, 0xe4), 0xf80);
        FLD(s32, self, 0xe8) = Ov010_FxMul(FLD(s32, self, 0xe8), 0xf80);
    }
    VEC_MultAdd(4, &data_ov010_0220fe38, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0x70));
    if (FLD(Ov010FxSet *, self, 0xd8) != NULL) {
        func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
    }
}
}
