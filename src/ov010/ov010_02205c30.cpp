#include "ov010/ov010.h"

struct Ov010Bits3 {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov010Rank {
    u16 pad : 7;
    u16 rank : 3;
    u16 rest : 6;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov010_0220f024[];
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov000_0218d988(void *self, void *target, s32 a);
extern void func_ov000_0218d46c(void *a, u16 b, s32 c);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021d969c(void *p, s32 a);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(Ov010Vec *src, Ov010Vec *dst, u16 angle);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern u8 *func_ov003_021d69f0(void *self, u16 kind, const Ov010Vec *pos, const void *rot, void *t);
extern void func_ov010_0220de4c(void *p, u8 a);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);

void func_ov010_02205c30(u8 *self) {
    u8 *tgt;
    s32 r = FLD(s16, FLD(u8 *, self, 0xb0), 2) * 2;
    {
        u16 id = FLD(u16, self, 0x90);
        tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[6], 0x800, 0);
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        return;
    case 1:
        func_ov000_0218d988(self, tgt, r);
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 2;
        }
        return;
    case 2: {
        u8 *res;
        u8 *ent;
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) != 3) {
            return;
        }
        res = func_02070558(FLD(u16, self, 0xe));
        ent = res != NULL ? res + 0x3a : NULL;
        if (ent == NULL || FLD(u16, ent, 0) == 0xffff) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        } else {
            Ov010Vec v;
            u8 *m = FLD(u8 *, self, 0x38);
            u8 *o;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            func_01ffc9fc(&v, &v, FLD(u16, self, 0x7e));
            VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
            o = func_ov003_021d69f0(self, 0x4818, &v, self + 0x7c, tgt);
            if (o != NULL) {
                FLD(s16, o, 0x18) = FLD(s8, ent, 2);
                func_ov010_0220de4c(o, FLD(u8, self, 0x171));
            }
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 3;
            func_02065f88(0x12c, &v)->v0c(0x2000);
            func_02049f44(data_02097e4c, 0x65, self + 0x70, 0);
            func_02049f44(data_02097e4c, 0x82, self + 0x70, 0);
        }
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x140), self + 0x70, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = FLD(u16, self, 0xde);
        a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        if (a == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
            return;
        }
        func_ov000_0218d46c(a, FLD(u16, self, 0xc), 0xb);
        FLD(u16, self, 0xde) = 0xffff;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        return;
    }
    case 4:
        if (!func_ov000_02191120(FLD(void *, self, 0x38))) {
            return;
        }
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010Bits3, self, 0xea).lo = FLD(Ov010Rank, FLD(u8 *, self, 0xb0), 0xa).rank;
        FLD(Ov010Flags8, self, 0xec).b0 = 1;
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
}

}
