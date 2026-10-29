#include "ov010/ov010.h"

class Ov010Cls;
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov010Ea {
    u16 lo : 3;
    u16 n : 3;
    u16 rest : 10;
};

struct Ov010B24 {
    u32 lo : 12;
    u32 n : 2;
    u32 rest : 18;
};

struct Ov010Bit0 {
    u8 b0 : 1;
    u8 rest : 7;
};

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);

void func_ov010_021fb5a4(void *self) {
    func_ov003_021da40c(FLD(void *, self, 0x40));
    func_ov000_0218d7e8(self, FLD(u8, FLD(u8 *, self, 0x40), 0x13));
}

extern const Ov010StEnt data_ov010_0220ed50[];
extern const Ov010Vec data_ov010_0220ec50;
extern void func_ov003_021d3008(void *self);
extern int func_ov003_021cf408(void);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov003_021d9a00(Ov010Vec *out, s32 angle, const Ov010Vec *in);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern void func_ov003_021cf4ac(void *p);
extern void func_ov010_021ffa6c(void *p);
extern void func_ov010_02201064(void *p);

static inline Ov010Rot Ov010_MkRotZ(void *q) {
    Ov010Rot r = {0, 0, 0};
    r.z = FLD(u16, q, 8);
    return r;
}

static inline BOOL Ov010_PlFlag(void) {
    u8 *pl = func_ov000_0219bf90();
    BOOL on = FALSE;
    if (pl != NULL) {
        on = FLD(Ov010B24, pl, 0xb24).n != 0;
    }
    return on;
}

static inline void Ov010_SetAlpha(void *self, u8 a) {
    FLD(u8, FLD(void *, self, 0x38), 0xbe) = a;
    if (FLD(Ov010Bit0, self, 0x138).b0 && FLD(s32, self, 0x140) != 0) {
        FLD(u8, self, 0x139) = a;
    }
    if (FLD(void *, self, 0xd0) != NULL && FLD(Ov010Ea, self, 0xea).n) {
        s32 i;
        for (i = 0; i < 2; i++) {
            void *p = FLD(void **, self, 0xd0)[0x68 / 4 + i];
            if (p != NULL) {
                FLD(u8, p, 0xbe) = a;
            }
        }
    }
}

void func_ov010_021fb5c8(Ov010Cls *self) {
    u32 i;
    u8 key;
    void *q;
    key = FLD(u8, FLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 11; i++) {
        if (key == data_ov010_0220ed50[i].key && *(s32 *)&data_ov010_0220ed50[i].fn != 0) {
            (self->*data_ov010_0220ed50[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        FLD(u8, self, 0x15) = func_ov003_021cf408();
    }
    {
        Ov010Vec t;
        Ov010Vec o;
        func_ov003_021d9a00(&t, FLD(u16, self, 0x80), &data_ov010_0220ec50);
        FLD(Ov010Vec, FLD(void *, self, 0x44), 0xc) = t;
        OV010_BLKCPY(&o, FLD(u8 *, self, 0x104) + 0x20);
        VEC_Add(&FLD(Ov010Vec, self, 0x70), &o, &FLD(Ov010Vec, self, 0x70));
    }
    q = FLD(void *, self, 0x108);
    if (!FLD(Ov010Flags8, q, 4).b1) {
        Ov010Rot a = Ov010_MkRotZ(q);
        FLD(u16, self, 0x7c) = a.x;
        Ov010Rot b = Ov010_MkRotZ(q);
        FLD(u16, self, 0x80) = b.z;
    }
    if (FLD(s32, self, 0x70) > 0x1c000) {
        s32 v = 0x1f - ((FLD(s32, self, 0x70) - 0x1c000) >> 12);
        if (v > 0x1f) {
            v = 0x1f;
        } else if (v < 0) {
            v = 0;
        }
        u8 a = v;
        Ov010_SetAlpha(self, a);
    } else {
        Ov010_SetAlpha(self, 0x1f);
    }
    {
        u16 *c = FLD(u16 *, self, 0x50);
        if ((c[0] << 12) / c[1] <= 0x333) {
            u16 *f = FLD(u16 *, self, 0xf8);
            f[0] = 0;
            f[1] = 0;
        } else {
            u16 *f = FLD(u16 *, self, 0xf8);
            if (f[1] >= 0xf) {
                if (f[0] > 0x96) {
                    f[0] = 0;
                    f[1] = 0;
                    if (FLD(Ov010Bit0, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
                        FLD(s32, self, 0x140) = 2;
                        FLD(u16, self, 0x13c) = 0;
                    }
                }
            } else {
                if (f[0] > 0x5a) {
                    f[0] = 0;
                    f[1] = 0;
                    if (FLD(Ov010Bit0, self, 0x138).b0 && FLD(s32, self, 0x140) == 1) {
                        FLD(s32, self, 0x140) = 2;
                        FLD(u16, self, 0x13c) = 0;
                    }
                }
            }
        }
    }
    if (Ov010_PlFlag()) {
        Ov010Cmd cmd;
        func_ov003_021d88ec(&cmd);
        cmd.a = 1;
        cmd.b = 0;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
    } else {
        Ov010Cmd cmd;
        func_ov003_021d88ec(&cmd);
        cmd.a = 1;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
    }
    func_ov003_021cf4ac((u8 *)self + 0x1d0);
    func_ov010_021ffa6c((u8 *)self + 0x138);
    func_ov010_02201064(FLD(void *, self, 0x100));
    FLD(u16 *, self, 0xf8)[0]++;
}

}
