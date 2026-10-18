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
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov003_021d969c(void *p, s32 a);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
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
}
