#include "ov010/ov010.h"

struct Ov010Trail {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_01[5];
    u16 unk_06;
    u16 unk_08;
    u8 unk_0a[6];
    void *unk_10;
};

typedef BOOL (*Ov010HitFn)(u16 id, Ov010Vec *a, Ov010Vec *b);

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Ov010Vec data_ov010_0220efdc;
extern Ov010Vec data_ov010_0220fe44;
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_02065860(void *a, void *b);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *src, Ov010Vec *dst);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9aec(Ov010Vec *out, const Ov010Vec *in, s32 max);
extern void func_ov003_021d9b8c(Ov010Vec *out, const Ov010Vec *in, s32 max, s32 sub);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern BOOL func_01ffc198(const Ov010Vec *a, const Ov010Vec *b, s32 r);
extern void func_ov010_02203bf8(Ov010Trail *p);

static inline s32 Ov010t_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov010_02202d9c(void *self) {
    void *p40 = FLD(void *, self, 0x40);
    BOOL dir;
    BOOL done = FALSE;
    void *tgt;
    u8 chk;
    if ((FLD(u64, p40, 4) & 0x200) != 0) {
        func_ov000_02198360(p40, 9, done);
        return;
    }
    dir = done;
    tgt = NULL;
    chk = done;
    switch (FLD(u16, p40, 0)) {
    case 0: {
        void *m = FLD(void *, self, 0x38);
        Ov010Trail *s;
        FLD(u16, m, 0xb6) = 0x7fff;
        FLD(u16, m, 0xb8) = 0x7fff;
        FLD(u16, m, 0xba) = 0x10;
        FLD(u16, m, 0xbc) = 0xf;
        FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0x1f;
        s = FLD(Ov010Trail *, self, 0xd8);
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        s = FLD(Ov010Trail *, self, 0xd8);
        if (s->b0) {
            if (s->b2) {
                func_02065860(data_0214a420, s->unk_10);
                s->unk_10 = NULL;
            }
            s->b2 = 1;
            s->unk_08 = 0x2000;
            s->b3 = 0;
        }
        FLD(u16 *, self, 0x40)[0] = 1;
        func_02049f44(data_02097e4c, 0x50, &FLD(Ov010Vec, self, 0x70), 0);
        break;
    }
    case 1:
        VEC_MultAdd(6, &data_ov010_0220efdc, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        func_ov003_021d9b8c(&FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0), 0x180, 0x180);
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x46) {
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 10;
            func_0204a028(data_02097e4c, 0x32, &FLD(Ov010Vec, self, 0x70), 8);
        }
        break;
    case 10:
        VEC_MultAdd(0x18, &data_ov010_0220efdc, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        VEC_MultAdd(6, &data_ov010_0220fe44, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0), 0x700);
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x1d) {
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 0x14;
        }
        break;
    case 0x15:
    case 0x14: {
        Ov010Vec d;
        Ov010HitFn fn;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = FLD(u16, self, 0x90);
            tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        {
            u16 *st = FLD(u16 *, self, 0x40);
            if (st[0] == 0x14) {
                FLD(s32, self, 0x9c) = 0;
                FLD(Ov010Vec, self, 0xf8) = FLD(Ov010Vec, tgt, 0x70);
                FLD(s32, self, 0xfc) += FLD(s32, FLD(void *, tgt, 0x44), 0x10);
                st[0] = 0x15;
            }
        }
        d.x = FLD(s32, self, 0xf8) - FLD(s32, self, 0x70);
        d.y = FLD(s32, self, 0xfc) - FLD(s32, self, 0x74);
        d.z = FLD(s32, self, 0x100) - FLD(s32, self, 0x78);
        VEC_Normalize(&d, &d);
        VEC_MultAdd(FLD(s32, self, 0x9c), &d, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        VEC_MultAdd(4, &data_ov010_0220fe44, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        FLD(s32, self, 0x9c) += 4;
        {
            s32 v = FLD(s32, self, 0x9c);
            if (v > 0x400) {
                v = 0x400;
            } else if (v < 0) {
                v = 0;
            }
            FLD(s32, self, 0x9c) = v;
        }
        func_ov003_021d9aec(&FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0), 0x700);
        fn = FLD(Ov010HitFn, self, 0xdc);
        if (fn != NULL) {
            if (fn(FLD(u16, tgt, 0xc), &FLD(Ov010Vec, self, 0xf8), &FLD(Ov010Vec, self, 0x70))) {
                FLD(u16 *, self, 0x40)[0] = 0x1e;
            }
        }
        if (VEC_Distance(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xf8)) < 0x1000) {
            FLD(u16 *, self, 0x40)[0] = 0x28;
        }
        break;
    }
    case 0x1e: {
        Ov010Vec d;
        dir = TRUE;
        chk = TRUE;
        {
            u16 id = FLD(u16, self, 0x90);
            if (data_ov000_021ccd68 != NULL) {
                tgt = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
        }
        FLD(s32, self, 0xe0) = Ov010t_FxMul64(FLD(s32, self, 0xe0), 0xe80);
        FLD(s32, self, 0xe4) = Ov010t_FxMul64(FLD(s32, self, 0xe4), 0xe80);
        FLD(s32, self, 0xe8) = Ov010t_FxMul64(FLD(s32, self, 0xe8), 0xe80);
        d.x = FLD(s32, self, 0xf8) - FLD(s32, self, 0x70);
        d.y = FLD(s32, self, 0xfc) - FLD(s32, self, 0x74);
        d.z = FLD(s32, self, 0x100) - FLD(s32, self, 0x78);
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x40, &d, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
        if (VEC_Distance(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xf8)) < 0x1000) {
            FLD(u16 *, self, 0x40)[0] = 0x28;
        }
        break;
    }
    case 100:
        // Final state: nothing to do, but the empty case sets the switch's compare tree.
        break;
    case 0x28: {
        s32 t;
        u16 col;
        void *m;
        {
            u16 id = FLD(u16, self, 0x90);
            if (data_ov000_021ccd68 != NULL) {
                tgt = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
        }
        t = 0x19 - FLD(u16 *, self, 0x40)[1];
        if (t > 0x19) {
            t = 0x19;
        } else if (t < 1) {
            t = 1;
        }
        col = (t << 5) | 0x1f | (t << 10);
        m = FLD(void *, self, 0x38);
        FLD(u16, m, 0xb6) = col;
        FLD(u16, m, 0xb8) = col;
        FLD(u16, m, 0xba) = 2;
        FLD(u16, m, 0xbc) = 1;
        dir = TRUE;
        chk = TRUE;
        FLD(u16 *, self, 0x40)[1]++;
        if (FLD(u16 *, self, 0x40)[1] > 0x1e) {
            FLD(u16 *, self, 0x40)[1] = 0;
            FLD(u16 *, self, 0x40)[0] = 100;
            done = TRUE;
        }
        break;
    }
    }
    if (dir) {
        Ov010Vec n;
        VEC_Normalize(&FLD(Ov010Vec, self, 0xe0), &n);
        FLD(u16, self, 0x7c) = func_ov003_021d9c74(&n);
        FLD(u16, self, 0x7e) = func_ov003_021d9c38(&n);
    }
    if (chk && tgt != NULL) {
        BOOL hit;
        BOOL r;
        FLD(u16, FLD(void *, self, 0x48), 0x9a) |= 0x10;
        func_ov000_021987b8(FLD(void *, self, 0x48), 0, 0, 0);
        hit = FALSE;
        if (FLD(u32, FLD(void *, self, 0x48), 0x50) & 0x20000000) {
            hit = TRUE;
        }
        r = func_01ffc198(&FLD(Ov010Vec, tgt, 0x70), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x64) + FLD(s32, tgt, 0x64));
        if (hit || r) {
            done = TRUE;
        }
    }
    if (done) {
        FLD(u8, self, 0xce) |= 2;
        func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 1);
    }
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0x70));
    if (FLD(Ov010Trail *, self, 0xd8) != NULL) {
        func_ov010_02203bf8(FLD(Ov010Trail *, self, 0xd8));
    }
}
}
