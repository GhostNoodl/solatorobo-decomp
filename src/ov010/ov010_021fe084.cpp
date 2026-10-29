#include "ov010/ov010.h"

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

struct Ov010Obj108 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
};

extern "C" {
extern u8 data_ov010_0220ebc0[];
extern Ov010Vec data_ov010_0220ec38;
extern void *data_02097e4c;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov003_021d969c(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d9e90(void *out, Ov010Vec *dir, void *in, s32 speed, s32 e);

static inline void Ov010_SetAnim(void *self, void *model, void *anim, s32 n) {
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
    func_ov000_02190cb0(model, anim, n, 0);
}

void func_ov010_021fe084(void *self) {
    Ov010Vec pos;
    Ov010Vec d;
    Ov010Cmd cmd;
    u16 st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    switch (st) {
    case 0: {
        u8 *cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0xf00;
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        Ov010_SetAnim(self, FLD(void *, self, 0x38), FLD(void *, data_ov010_0220ebc0, 0x1c), 0x266);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        break;
    }
    case 10:
    case 11: {
        s32 v;
        if (st == 10) {
            Ov010V *e;
            pos.x = FLD(s32, self, 0x70);
            pos.y = FLD(s32, self, 0x74) + 0x6000;
            pos.z = FLD(s32, self, 0x78);
            e = func_02065f88(0x192, &pos);
            e->v34(0xbfff, 0, 0);
            e->v0c(0x3000);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 11;
            func_02049f44(data_02097e4c, 0x29, (u8 *)self + 0x70, 0);
        }
        v = FLD(s32, self, 0x9c) + 0xa0;
        FLD(s32, self, 0x9c) = v;
        if (v > 0x3000) {
            v = 0x3000;
        } else if (v < 0) {
            v = 0;
        }
        FLD(s32, self, 0x9c) = v;
        func_ov003_021d9900(&d, 0x9fff, &data_ov010_0220ec38);
        func_ov003_021d9980(&d, FLD(u16, self, 0x7e), &d);
        func_ov003_021d9e90((u8 *)self + 0x70, &d, (u8 *)self + 0x70, FLD(s32, self, 0x9c), 0);
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 60) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    }
    case 100:
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 1;
        o->unk_06 = 0;
    }
    FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
}

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern Ov010Vec data_ov010_0220ecb0;
extern Ov010Vec data_ov010_0220fab0;
extern u8 data_ov010_0220fa2c[];
extern u8 data_ov010_0220fc13[];
extern void *func_ov000_0218e4cc(void *a, s32 b);
extern void *func_ov000_0218e6d0(void *a, u16 b, s32 c);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d6868(void *self, s32 a);
extern Ov010V *func_ov010_02203ee0(s32 a, const Ov010Vec *v);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
static inline void Ov010h_AttachWorld(void *obj, Ov010Vec *out) {
    Ov010Vec a;
    Ov010Vec v = data_ov010_0220ec20;
    void *p;
    if (obj != NULL && (p = FLD(void *, obj, 0x44)) != NULL) {
        u16 ry;
        v.x = FLD(s32, p, 0xc);
        v.y = FLD(s32, p, 0x10);
        v.z = FLD(s32, p, 0x14);
        ry = FLD(u16, obj, 0x7e);
        func_ov003_021d9900(&v, FLD(u16, obj, 0x7c), &v);
        func_ov003_021d9980(&v, ry, &v);
    }
    OV010_BLKCPY(&a, &v);
    VEC_Add(&a, &FLD(Ov010Vec, obj, 0x70), &a);
    OV010_BLKCPY(out, &a);
}
extern void *func_0204a028(void *mgr, s32 id, const Ov010Vec *pos, s32 a);
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021da48c(void *p, s32 a);
extern void func_ov003_021d68e0(void *self, s32 a, s32 b, s32 c);
extern void func_ov000_0218d988(void *self, void *target, s32 a);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov000_021915a0(void *a);

struct Ov010G190 {
    u8 lo : 2;
    u8 mid : 3;
    u8 hi : 3;
};

static inline s32 Ov010h_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010h_Cmd(void *self) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = 4;
    cmd.b = 1;
    func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
}

void func_ov010_021fe2a4(void *self) {
    const Ov010Vec *goal = &data_ov010_0220ecb0;
    BOOL flag = FALSE;
    s32 i;
    switch ((s32)FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        void *a;
        {
            u16 id = FLD(u16, func_ov000_0218e4cc(data_ov000_021ccd68, 0x1000), 8);
            a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e6d0(data_ov000_021ccd68, id, 0x1000);
        }
        if (a == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
            break;
        }
        FLD(u16, self, 0x90) = FLD(u16, a, 0xc);
        {
            u8 *cam = FLD(u8 *, self, 0x104);
            FLD(u8, cam, 4) = 0;
            FLD(u16, cam, 6) = 0;
        }
        Ov010h_Cmd(self);
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(void *, data_ov010_0220ebc0, 4), 0x1000, 0);
        FLD(s32, self, 0x78) = 0x1148;
        FLD(u16, self, 0x7e) = 0xbfff;
        FLD(u16, self, 0x7c) = 0;
        FLD(s32, self, 0x70) = 0x4e639;
        FLD(u16, self, 0x80) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x74) = 0x268b;
        FLD(s32, self, 0x9c) = 0x3000;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        func_02049f44(data_02097e4c, 0x32, (u8 *)self + 0x70, 0);
        break;
    }
    case 10: {
        u8 *g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0x1e;
        FLD(u8, g, 0x18e) = 10;
        FLD(u8, g, 0x18f) = 10;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0xb;
        break;
    }
    case 0xb:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x3c) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        }
        break;
    case 0x14: {
        func_ov003_021d6868(self, 0x2bde);
        for (i = 0; i < 3; i++) {
            if (FLD(u16, FLD(u8 *, self, 0x40), 2) == (u16)((i + 1) * 10)) {
                Ov010V *e;
                {
                    Ov010Vec q;
                    Ov010h_AttachWorld(self, &q);
                    e = func_ov010_02203ee0(0x68, &q);
                }
                e->v0c(0x2800);
                e->v34(0x4000, FLD(u16, self, 0x7e), 0);
            }
        }
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), goal, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), 0);
        if (VEC_Distance(goal, &FLD(Ov010Vec, self, 0x70)) < 0x18000) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        break;
    }
    case 0x1e:
    case 0x1f:
        flag = TRUE;
        if (FLD(u16, FLD(u8 *, self, 0x40), 0) == 0x1e) {
            u8 *cam;
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(void *, data_ov010_0220ebc0, 8), 0x100, 0);
            func_0204a028(data_02097e4c, 0xf, &FLD(Ov010Vec, self, 0x70), -5);
            func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
            cam = FLD(u8 *, self, 0x104);
            if (FLD(u8, cam, 4) == 0) {
                FLD(u8, cam, 4) = 1;
                OV010_BLKCPY(cam + 0x4c, &data_ov010_0220fab0);
                FLD(s16, cam, 0x58) = FLD(s16, data_ov010_0220fa2c, 0x90);
                FLD(s16, cam, 0x5a) = FLD(s16, data_ov010_0220fa2c, 0x92);
                FLD(u16, cam, 0x5c) = FLD(u16, data_ov010_0220fa2c, 0x94);
                FLD(s16, cam, 0x5e) = FLD(s16, data_ov010_0220fa2c, 0x96);
                FLD(s16, cam, 0x60) = FLD(s16, data_ov010_0220fa2c, 0x98);
                FLD(s16, cam, 0x62) = FLD(s16, data_ov010_0220fa2c, 0x9a);
                FLD(s16, cam, 0x64) = FLD(s16, data_ov010_0220fa2c, 0x9c);
                FLD(s16, cam, 0x66) = FLD(s16, data_ov010_0220fa2c, 0x9e);
                func_ov003_021da48c(cam + 0x38, 0);
            }
            func_ov003_021d68e0(self, 0x2bde, 0x6739, 0x50);
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
        }
        {
            u16 id = FLD(u16, self, 0x90);
            void *t = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
            func_ov000_0218d988(self, t, 0x180);
        }
        FLD(s32, self, 0x9c) = Ov010h_Mul64(FLD(s32, self, 0x9c), 0xe00);
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), goal, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), 0);
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            Ov010V *e;
            {
                Ov010Vec q;
                Ov010h_AttachWorld(self, &q);
                e = func_ov010_02203ee0(0x12f, &q);
            }
            e->v0c(0x3000);
            e->v34(0xbfff, FLD(u16, self, 0x7e), 0);
            func_02049f44(data_02097e4c, 0x52, (u8 *)self + 0x70, 0);
        }
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x78) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 100;
        }
        break;
    case 100:
        flag = TRUE;
        FLD(u16, self, 0x7e) = func_01ffc128(FLD(u16, self, 0x90), FLD(u16, self, 0x7e), 0x180, 1, 0x8000);
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
        break;
    }
    {
        Ov010Obj108 *o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 1;
        o->unk_06 = 0;
    }
    if (flag && func_ov000_02191120(FLD(void *, self, 0x38))) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc13, 0x800, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
    if (FLD(u16, FLD(u8 *, self, 0x40), 0) < 0x1e) {
        FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
    }
}
}
