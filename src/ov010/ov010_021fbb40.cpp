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

struct Ov010MoveParam {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s16 speed;
    s16 accel;
    s16 max;
    s16 near;
    s16 decel;
    s16 min;
    void *anim;
    u16 rot[3];
    u8 unk_1a[2];
    Ov010Vec pos;
    Ov010Vec target;
};

struct Ov010MoveEntry {
    u8 key;
    Ov010MoveParam *param;
};

extern "C" {
extern Ov010MoveEntry data_ov010_0220ed28[];
extern void *data_02097e4c;
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern void func_ov003_021d969c(void *p, s32 a);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(void *out, Ov010Vec *dir, void *in, s32 speed, s32 e);
extern BOOL func_ov003_021d98bc(Ov010Vec *a, void *b);
extern void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

static inline void Ov010_Cmd(void *dst, s32 a, s32 b) {
    Ov010Cmd cmd;
    func_ov003_021d88ec(&cmd);
    cmd.a = a;
    cmd.b = b;
    func_ov003_021d8b60(dst, &cmd);
}

static inline s32 Ov010_Clamp(s32 v, s32 max) {
    s32 r;
    if (v > max) {
        r = max;
    } else {
        if (v < 0) {
            v = 0;
        }
        r = v;
    }
    return r;
}

void func_ov010_021fbb40(void *self) {
    Ov010MoveParam *p = NULL;
    u32 i;
    for (i = 0; i < 5; i++) {
        if (FLD(u8, self, 0x1bd) == data_ov010_0220ed28[i].key) {
            p = data_ov010_0220ed28[i].param;
        }
    }
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *cam;
        func_ov000_02190cb0(FLD(void *, self, 0x38), p->anim, 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = p->speed;
        if (p->b0) {
            FLD(s32, self, 0x70) = p->pos.x;
            FLD(s32, self, 0x74) = p->pos.y;
            FLD(s32, self, 0x78) = p->pos.z;
        }
        if (p->b1) {
            FLD(u16, self, 0x7c) = p->rot[0];
            FLD(u16, self, 0x7e) = p->rot[1];
            FLD(u16, self, 0x80) = p->rot[2];
        }
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
        cam = FLD(u8 *, self, 0x104);
        FLD(u8, cam, 4) = 0;
        FLD(u16, cam, 6) = 0xf00;
        Ov010_Cmd((u8 *)self + 0x1c0, 4, p->unk_02);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
        if (FLD(Ov010Flags8, self, 0xf0).b1) {
            FLD(Ov010Flags8, self, 0xf0).b1 = 0;
            func_02049a48(data_02097e4c, 0xb00, -1, -1, -1);
        }
        break;
    }
    case 10: {
        s32 v;
        if (VEC_Distance(&p->target, (Ov010Vec *)((u8 *)self + 0x70)) <= p->near) {
            v = Ov010_FxMul(FLD(s32, self, 0x9c), p->decel);
        } else {
            FLD(s32, self, 0x9c) += p->accel;
            v = Ov010_Clamp(FLD(s32, self, 0x9c), p->max);
        }
        FLD(s32, self, 0x9c) = v;
        func_ov003_021d9dbc((u8 *)self + 0x70, &p->target, (u8 *)self + 0x70, FLD(s32, self, 0x9c), 0);
        if (func_ov003_021d98bc(&p->target, (u8 *)self + 0x70) || FLD(s32, self, 0x9c) < p->min) {
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
