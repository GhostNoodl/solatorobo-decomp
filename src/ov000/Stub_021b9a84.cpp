#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x8];
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10[0x4];
    VObj *unk_14;
    class Spr_021b9b14 *sprA;
    class Spr_021b9b14 *sprB;
    struct Model_021b9b14 *model;
    u8 unk_24[0x4];
    s32 t28;
    s32 t2c;
    s32 t30;
    s32 t34;
} Obj021b9a84;

extern "C" {

extern u8 *data_02097d48;
void func_02043d20(void *p, s32 a);
void func_ov000_021b9b14(Obj021b9a84 *self);
void func_ov000_021ba338(Obj021b9a84 *self);

void func_ov000_021b9a84(Obj021b9a84 *self) {
    switch (self->unk_08) {
    case 11:
    case 12:
    case 13:
        func_02043d20(data_02097d48 + 0x8b0, 0);
        func_ov000_021b9b14(self);
        if (self->unk_0c == 1 || self->unk_0c == 3) {
            func_ov000_021ba338(self);
        }
        break;
    case 14:
    case 15:
        break;
    case 16:
        if (self->unk_14 != NULL) {
            self->unk_14->vfunc_20();
        }
        break;
    }
}

}

#ifdef NONMATCHING
// func_ov000_021b9b14: 33 raw / 2 register-masked diffs (was 64 / 24), no fake
// parameters or junk locals. The else-state arms are written as two arms with the
// same product (the compiler cross-jumps them into rsbeq + one multiply, keeping the
// constant's zero high word in a register); a conditional `t = 0x1000 - t` lets the
// front end fold the high word instead. Section 3 sets `q = 0x68` at the end of each
// arm, so the 0x68 is not live across the 0x1e arm's product when the zero group is
// hoisted (block pressure 10, not 11) and the 0x68 group still ends up in front of
// the branch. Section 4's y position is its own local `y` (declared after `w`), so
// it gets r8 as in the ROM. What is left is register colouring in section 4 (x, the
// product temporaries, the -0x81a and (u8)a values) and one load/and order.
typedef struct {
    u32 b0 : 2;
    u32 b2 : 5;
    u32 b7 : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 b22 : 10;
} ModelFlags_021b9b14;

typedef struct {
    u32 b0 : 8;
    u32 b8 : 5;
    u32 b13 : 8;
    u32 b21 : 11;
} SprAttr_021b9b14;

class Spr_021b9b14 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1c();
    virtual void vfunc_20(s32 x, s32 y);
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2c();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3c();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4c();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5c();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6c();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7c();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8c();
    virtual void vfunc_90();
    SprAttr_021b9b14 attr;
    u8 unk_08[0x3c];
    s32 width;
    u8 unk_48[0x28];
    s32 depth;
};

typedef struct {
    u8 unk_00[0x4];
    void *anim;
    u8 unk_08[0x20];
} Part_021b9b14;

typedef struct {
    u8 unk_00[0x4];
    void *cells;
    u8 unk_08[0x4];
    void *seqs;
} Res_021b9b14;

typedef struct Model_021b9b14 {
    u8 unk_00[0x28];
    Res_021b9b14 *res;
    u8 unk_2c[0x40];
    ModelFlags_021b9b14 flags;
    u8 unk_70[0x8];
    Part_021b9b14 *parts;
    u8 unk_7c[0x4];
    s32 numParts;
    u8 unk_84[0x78];
    s32 x;
    s32 y;
    u8 unk_104[0x4c];
    s32 depth;
} Model_021b9b14;


extern "C" {

extern void *data_0208b3d0;
extern u32 data_020828f8;
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
u32 func_02043d48(void *p);
void *NNS_G2dGetAnimSequenceByIdx(void *p, int idx);
void *NNS_G2dGetCellDataByIdx(void *p, u16 idx);
void func_02042628(void *model, void *anim, void *part, int x);
void func_ov000_021ba858(void *self, s32 x, s32 y);

/* generic s64 product: the constant's high word sits in a zero register */
static inline s32 FxMulL021b9b14(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}
#define FXG(a, b) FxMulL021b9b14(a, b)
/* folded product */
#define FXC(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline void G3Vec(int cmd, s32 x, s32 y, s32 z) {
    s32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline Part_021b9b14 *GetPart(Model_021b9b14 *m, int idx) {
    if (idx >= m->numParts) {
        return NULL;
    }
    return &m->parts[idx];
}

typedef struct {
    u8 unk_00[0xc];
    u16 **frames;
} Seq_021b9b14;

static inline void PlayPart(Model_021b9b14 *m, int idx) {
    Res_021b9b14 *res = m->res;
    Part_021b9b14 *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = GetPart(m, idx);
    if (part != NULL && part->anim != NULL) {
        anim = *(void **)((u8 *)part->anim + 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->cells,
                                       **((Seq_021b9b14 *)NNS_G2dGetAnimSequenceByIdx(res->seqs, idx))->frames);
    }
    func_02042628(m, anim, part, 0);
}

void func_ov000_021b9b14(Obj021b9a84 *self) {
    s32 x;
    u8 *g = data_02097d48;
    s32 t;
    s32 h;
    s32 o;
    s32 a;
    s32 p;
    s32 q;
    s32 w;
    s32 y;
    s32 dp;
    Spr_021b9b14 *sa;
    Spr_021b9b14 *sb;

    if (self->unk_0c == 0 || self->unk_0c == 2) {
        t = self->t28;
        if (self->unk_08 != 0xd) {
            h = FXG(t, 0x16000) >> 12;
            o = FXG(0x1000 - t, 0x8000);
        } else {
            h = FXC(0x1000 - t, 0x16000) >> 12;
            o = 0;
        }
    } else {
        t = self->t28;
        if (self->unk_08 != 0xd) {
            h = FXG(t, 0x16000) >> 12;
        } else {
            h = FXG(0x1000 - t, 0x16000) >> 12;
        }
        o = 0;
    }
    if (h != 0) {
        G3Cmd1(0x29, (g[0x8b1] << 24) | 0xd0 | (h << 16));
        func_02043d48(g + 0x8b0);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3Vec(0x1c, 0x80000, 0x60000 - o, -0x91a);
        if (self->unk_0c <= 1) {
            G3Cmd1(0x20, 0x87);
        } else {
            G3Cmd1(0x20, 0x64);
        }
        G3Cmd1(0x2a, 0x20000000);
        G3Vec(0x1b, 0x100000, 0x18000, 0x1000);
        NNS_G3dGeSendDL(data_0208b3d0, data_020828f8);
        G3Cmd1(0x12, 1);
    }

    if (self->unk_0c == 0 || self->unk_0c == 2) {
        t = self->t2c;
        if (self->unk_08 != 0xd) {
            h = FXG(t, 0x16000) >> 12;
            o = FXG(0x1000 - t, 0x10000);
        } else {
            h = FXC(0x1000 - t, 0x16000) >> 12;
            o = 0;
        }
    }
    if (h != 0) {
        G3Cmd1(0x29, (g[0x8b1] << 24) | 0xd0 | (h << 16));
        func_02043d48(g + 0x8b0);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3Vec(0x1c, 0x80000, o + 0x63000, -0x91a);
        if (self->unk_0c <= 1) {
            G3Cmd1(0x20, 0x7b);
        } else {
            G3Cmd1(0x20, 0x61c0);
        }
        G3Cmd1(0x2a, 0x20000000);
        G3Vec(0x1b, 0x100000, 0xe000, 0x1000);
        NNS_G3dGeSendDL(data_0208b3d0, data_020828f8);
        G3Cmd1(0x12, 1);
    }

    if (self->unk_0c == 0 || self->unk_0c == 2) {
        t = self->t30;
        if (self->unk_08 != 0xd) {
            a = 0x1e;
            p = (FXC(t, -0x104000) >> 12) + 0x120;
            q = 0x68;
        } else {
            a = FXG(0x1000 - t, 0x1e000) >> 12;
            p = 0x1c;
            q = 0x68;
        }
    } else {
        t = self->t28;
        if (self->unk_08 == 0xd) {
            t = 0x1000 - t;
        }
        a = FXG(t, 0x1e000) >> 12;
        p = 0x1c;
        q = 0x68;
    }
    self->model->flags.b19 = 1;
    self->model->flags.b2 = (u8)a;
    if (a != 0) {
        Model_021b9b14 *m;
        G3Cmd1(0x29, (g[0x8b1] << 24) | 0xd0 | (a << 16));
        func_02043d48(g + 0x8b0);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3Vec(0x1c, 0x100000, q << 12, -0x91a);
        G3Cmd1(0x20, 0x7fff);
        func_ov000_021ba858(self, 0x100 - p, 1);
        G3Cmd1(0x12, 1);
        self->model->depth = -0x89a;
        self->model->flags.b7 = 1;
        m = self->model;
        m->x = (p - 0x80) << 12;
        m->y = (q - 0x60) << 12;
        PlayPart(self->model, 1);
    }

    sa = self->sprA;
    sb = self->sprB;
    w = sa->width + 8;
    x = 0x100 - (w + sb->width + 8);
    if (self->unk_0c == 0 || self->unk_0c == 2) {
        t = self->t34;
        if (self->unk_08 != 0xd) {
            a = FXG(t, 0x2e000) >> 12;
            x += FXG(0x1000 - t, 0x20000) >> 12;
            y = 0x68;
        } else {
            a = FXG(0x1000 - t, 0x1f000) >> 12;
            x -= FXG(t, 0x20000) >> 12;
            y = 0x68;
        }
    } else {
        t = self->t28;
        if (self->unk_08 != 0xd) {
            a = FXG(t, 0x2e000) >> 12;
        } else {
            t = 0x1000 - t;
            a = FXG(t, 0x1f000) >> 12;
        }
        y = 0x68;
    }
    if (a == 0) {
        return;
    }
    if (a > 0x1e) {
        a = 0x1e;
    }
    dp = -0x81a;
    sa->depth = dp;
    self->sprA->attr.b8 = (u8)a;
    self->sprA->attr.b13 = g[0x8b1];
    self->sprA->vfunc_20(x, y - 9);
    self->sprA->vfunc_90();
    self->sprB->depth = dp;
    self->sprB->attr.b8 = (u8)a;
    self->sprB->attr.b13 = func_02043d48(g + 0x8b0);
    self->sprB->vfunc_20(x + w, y - 0xb);
    self->sprB->vfunc_90();
}
}
#endif
