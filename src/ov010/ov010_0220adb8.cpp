#include "ov010/ov010.h"

namespace NA { extern "C" u8 data_ov010_0220f534[]; }
extern "C" {
extern void *data_0214a420;
extern void func_02065860(void *a, s32 b);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_021950e8(void *self, u8 *msg);

static inline void Ov010FxB_Stop(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065860(data_0214a420, FLD(s32, p, 8));
        FLD(s32, p, 8) = 0;
        func_ov000_02198360(p + 0x58, 1, 0);
    }
}

static inline void Ov010FxB_Start(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        FLD(u16, p, 2) = 0;
        FLD(u16, p, 4) = 0x50;
        func_ov003_021da48c(p + 0x58, 2);
    }
}

BOOL func_ov010_0220adb8(void *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 4:
            FLD(Ov010Flags8, self, 0xce).b3 = 1;
            if (FLD(s32, self, 0xd8) == 7) {
                break;
            }
        case 1:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
            break;
        case 0:
            Ov010FxB_Stop(FLD(u8 *, self, 0xec));
            Ov010FxB_Start(FLD(u8 *, self, 0xec));
            break;
        case 2:
            func_ov000_02198360(FLD(void *, self, 0x40), 6, 0);
            break;
        case 3:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x12, 0);
            break;
        }
        r = TRUE;
        FLD(u32, self, 0x30) |= 1 << msg[5];
        msg[5] = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

extern void func_ov000_02194758(void *self);
extern void *func_ov000_02198328(void *p);
extern void func_0203f364(void *p);
extern u8 data_ov010_0220f534[];
extern Ov010Vec data_ov010_0220f594;
extern BOOL func_ov010_0220e740(void *self, void *a, void *b, s32 c, const Ov010Vec *v, s32 e);

static inline u8 *Ov010FxA_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x28);
    if (p != NULL) {
        func_ov000_02198328(p + 0x14);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

static inline u8 *Ov010FxB_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x6c);
    if (p != NULL) {
        func_ov000_02198328(p + 0x58);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

void func_ov010_0220aecc(u8 *self) {
    u8 *p;
    func_ov000_02194758(self);
    func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
    func_ov000_02198360(self + 0x158, 1, 0);
    FLD(s32, self, 0xd8) = 1;
    FLD(u8 *, self, 0xe8) = p = Ov010FxA_New();
    FLD(Ov010Flags8, p, 0).b0 = 1;
    FLD(Ov010Flags8, p, 0).b1 = 0;
    FLD(Ov010Flags8, p, 0).b2 = 0;
    FLD(u16, p, 2) = 0;
    FLD(s32, p, 4) = 0;
    FLD(Ov010Vec, p, 8) = FLD(Ov010Vec, data_ov010_0220f534, 0x60);
    func_ov003_021da48c(p + 0x14, 0);
    FLD(u8 *, self, 0xec) = Ov010FxB_New();
    func_ov010_0220e740(FLD(u8 *, self, 0xec), self, NA::data_ov010_0220f534, 1, &data_ov010_0220f594, 0x68);
    if (FLD(Ov010Flags8, FLD(u8 *, self, 0xec), 0).b0) {
        FLD(s32, FLD(u8 *, self, 0xec), 0x14) = 0x4000;
    }
    FLD(Ov010Flags, self, 0xcc).b4 = 0;
    {
        u8 *mm = FLD(u8 *, self, 0x48);
        FLD(Ov010Flags, mm, 0x9a).b0 = 0;
        FLD(Ov010Flags, mm, 0x9a).b3 = 0;
        func_0203f364(mm);
    }
    {
        u8 *q = FLD(u8 *, self, 0x44);
        FLD(Ov010Flags, q, 0x22).b0 = 0;
        FLD(Ov010Flags, q, 0x22).b1 = 0;
    }
    FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
    {
        u8 *m = FLD(u8 *, self, 0x38);
        FLD(s32, m, 0xa8) = 0x1400;
        FLD(s32, m, 0xac) = 0x1400;
        FLD(s32, m, 0xb0) = 0x1400;
    }
    FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = FLD(u16, self, 0xd0);
    FLD(Ov010Flags8, FLD(u8 *, self, 0x4c), 0x18).b4 = 1;
    FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
    FLD(s32, FLD(u8 *, self, 0x48), 0x48) = FLD(s32, self, 0x64) + (FLD(s32, self, 0x64) >> 1);
    FLD(u8, self, 0xcf) = 1;
}


}

class Ov010Ac {
public:
    u8 unk_00[0xce];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 6;
    u8 unk_cf[0x9c];
    u8 key16b;
    u8 unk_16c[0x13];
    u8 key17f;
};

typedef void (Ov010Ac::*Ov010AcFn)();

struct Ov010AcEntry {
    u32 key;
    Ov010AcFn fn;
};

struct Ov010Mtx33 {
    s32 m[9];
};

extern "C" {
extern const Ov010AcEntry data_ov010_0220f5a0[];
extern const Ov010AcEntry data_ov010_0220f5b8[];
extern void *data_ov000_021ccd68;
extern void func_ov000_021953b4(void *self);
extern void func_ov010_0220c5a0(void *self);
extern u8 *func_ov000_0219bf90(void);
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220e38c(void *p);
extern void func_ov010_0220e7c8(void *p);
extern void MTX_Identity33_(Ov010Mtx33 *m);
extern void MTX_RotX33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov010Mtx33 *a, Ov010Mtx33 *b, Ov010Mtx33 *out);
extern void MTX_MultVec33(Ov010Vec *v, Ov010Mtx33 *m, Ov010Vec *out);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);

void func_ov010_0220b0a8(Ov010Ac *self) {
    Ov010Vec t;
    Ov010Mtx33 tmp;
    Ov010Mtx33 m;
    func_ov000_021953b4(self);
    if (self->f0) {
        u32 i;
        u8 key = self->key16b;
        for (i = 0; i < 2; i++) {
            if (key == data_ov010_0220f5a0[i].key && *(s32 *)&data_ov010_0220f5a0[i].fn != 0) {
                (self->*data_ov010_0220f5a0[i].fn)();
                break;
            }
        }
    }
    if (self->f1) {
        u32 i;
        u8 key = self->key17f;
        for (i = 0; i < 3; i++) {
            if (key == data_ov010_0220f5b8[i].key && *(s32 *)&data_ov010_0220f5b8[i].fn != 0) {
                (self->*data_ov010_0220f5b8[i].fn)();
                break;
            }
        }
    }
    func_ov010_0220c5a0(self);
    switch (FLD(s32, self, 0xd8)) {
    case 6: {
        u8 *p = FLD(u8 *, self, 0xec);
        u8 n;
        if (FLD(Ov010Flags8, p, 0).b0) {
            n = FLD(u8, p, 0x6b);
        } else {
            n = 0;
        }
        if (n == 4) {
            FLD(Ov010Flags, FLD(u8 *, self, 0x44), 0x22).b1 = 0;
        }
        {
            u8 *q = FLD(u8 *, self, 0x44);
            FLD(Ov010Flags, q, 0x22).b0 = 1;
            FLD(Ov010Flags, q, 0x22).b1 = 1;
        }
        u16 a = FLD(u16, func_ov000_0219bf90(), 0xb1c);
        if (a == FLD(u16, self, 0xc)) {
            FLD(s32, self, 0xd8) = 8;
        }
        break;
    }
    case 7: {
        void *mgr = data_ov000_021ccd68;
        u16 id = FLD(u16, self, 0x180);
        u8 *o = mgr == NULL ? NULL : func_ov000_0218e640(mgr, id);
        if (o != NULL) {
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set;
            t = FLD(Ov010Vec, o, 0x70);
            set = FALSE;
            rz = FLD(u16, o, 0x80) - FLD(u16, self, 0x194);
            ry = FLD(u16, o, 0x7e) - FLD(u16, self, 0x192);
            rx = FLD(u16, o, 0x7c) - FLD(u16, self, 0x190);
            MTX_Identity33_(&m);
            if (rz != 0) {
                MTX_RotZ33_(&m, OV010_SIN(rz), OV010_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY33_(&tmp, OV010_SIN(ry), OV010_COS(ry));
                    MTX_Concat33(&tmp, &m, &m);
                } else {
                    MTX_RotY33_(&m, OV010_SIN(ry), OV010_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&tmp, OV010_SIN(rx), OV010_COS(rx));
                    MTX_Concat33(&tmp, &m, &m);
                } else {
                    MTX_RotX33_(&m, OV010_SIN(rx), OV010_COS(rx));
                    set = TRUE;
                }
            }
            MTX_MultVec33(&FLD(Ov010Vec, self, 0x184), &m, &FLD(Ov010Vec, self, 0x70));
            VEC_Add(&FLD(Ov010Vec, self, 0x70), &t, &FLD(Ov010Vec, self, 0x70));
        }
        break;
    }
    }
    if (FLD(void *, self, 0xe8) != NULL) {
        func_ov010_0220e38c(FLD(void *, self, 0xe8));
    }
    if (FLD(void *, self, 0xec) != NULL) {
        func_ov010_0220e7c8(FLD(void *, self, 0xec));
    }
    ((Ov010V *)((u8 *)self + 0x120))->v0c();
}

}
