#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_0204c7d0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
s32 FX_Div(s32 a, s32 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(void *self);

void func_ov000_021752f0(VObj *self) {
    switch (LFLD(s32, self, 8)) {
    case 8:
        LFLD(void *, self, 0x2c) = LoFindTask(1);
        if (LFLD(void *, self, 0x40) != NULL) {
            LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 0;
        }
        if (LFLD(void *, self, 0x44) != NULL) {
            LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 0;
        }
        if (LFLD(void *, self, 0x48) != NULL) {
            LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 0;
        }
        break;
    case 0xa:
        if (self->vfunc_54()) {
            LFLD(s32, self, 0x4c) = 0;
        }
        break;
    }
}

void func_ov000_021753a0(void *self) {
    s32 m = LFLD(s32, self, 0x4c);
    if (m == 1) {
        s32 v;
        LFLD(s32, self, 0x50) += 0x1000;
        v = FX_Div(LFLD(s32, self, 0x50), LFLD(s32, LFLD(void *, self, 0x40), 0x34));
        LFLD(s32, self, 0x54) = v;
        if (v >= 0x1000) {
            LFLD(s32, self, 0x54) = 0x1000;
            LFLD(s32, self, 0x4c) = -1;
        }
    } else if (m == 0) {
        s32 v;
        LFLD(s32, self, 0x50) -= 0x1000;
        v = FX_Div(LFLD(s32, self, 0x50), LFLD(s32, LFLD(void *, self, 0x40), 0x34));
        LFLD(s32, self, 0x54) = v;
        if (v <= 0) {
            LFLD(s32, self, 0x54) = 0;
            LFLD(s32, self, 0x4c) = -1;
            if (LFLD(void *, self, 0x40) != NULL) {
                LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
            }
            if (LFLD(void *, self, 0x44) != NULL) {
                LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
            }
            if (LFLD(void *, self, 0x48) != NULL) {
                LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 1;
            }
        }
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_1c();
        LBIT(LFLD(void *, self, 0x40), 0xc).b2 = 1;
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_1c();
    }
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_1c();
    }
}

void func_ov000_021754bc(void *self) {
    s32 scale[3];
    if (LFLD(s32, self, 0x24) == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    LFLD(s32, self, 0x28) = FX_SinCosTable_[((LFLD(s32, self, 0x24) << 14) >> 16) * 2];
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
    func_ov000_0217558c(self);
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
}

}

#ifdef NONMATCHING
// func_ov000_0217558c: 2 raw / 2 register-masked diffs, real signature (self only), no fake locals.
// The ROM schedules mov r0, #0x18000 before the M5C load in the first SetPos block (see docs/MATCHING.md, round aliasW).
#include "ov000/ModelPart.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern const s16 FX_SinCosTable_[];
extern u8 *data_02097d48;
BOOL func_02054f10(void *p, s32 id);
void *func_ov000_0219bf90(void);
u32 func_02043d48(void *p);
void func_02041c20(Model *m, s32 a, s32 b);
void func_02041c18(Model *m, s32 v);
void func_ov000_021c95fc(void *p);

typedef struct {
    s16 a[5];
    s16 b[5];
} Counts;

static inline s32 Clamp99(s16 v) {
    if (v < 0) {
        v = 0;
    } else if (v > 99) {
        v = 99;
    }
    return v;
}

#define TEXT(off) ((VObj *)((u8 *)self + (off)))
#define M5C LFLD(Model *, self, 0x5c)

static inline void Model_PlayPartChk(Model *model, s32 idx) {
    ModelRes *res;
    ModelPart *part;
    void *anim;
    if (model->res == NULL) {
        return;
    }
    res = model->res;
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, anim, part, 0);
}

void func_ov000_0217558c(void *self) {
    Model *m;
    s32 x;
    u8 *g;
    s32 xi;
    Counts c;
    if (LFLD(void *, self, 0x40) == NULL || LFLD(void *, self, 0x58) == NULL) {
        return;
    }
    if (!func_02054f10(LFLD(void *, self, 0x58), 0xffff)) {
        return;
    }
    if (!func_02054f10(LFLD(void *, self, 0x5c), 0xffff)) {
        return;
    }
    x = (s32)(((s64)(0x1000 - FX_SinCosTable_[((s32)(LFLD(s32, self, 0x54) << 14) >> 16) * 2]) * 0x80000 + 0x800) >> 12);
    g = data_02097d48 + 0x8b0;
    Model_SetPos(LFLD(Model *, self, 0x58), x & ~0xfff, 0);
    m = LFLD(Model *, self, 0x58);
    Model_PlayPart(m, 1);
    func_ov000_0219bf90();
    MODEL_FLAGS(M5C)->polygon_id = func_02043d48(g);
    xi = x >> 12;
    TEXT(0x60)->vfunc_20(xi + 0xc2 - (LFLD(s32, self, 0xa4) >> 1), 0x30);
    TEXT(0x60)->vfunc_90();
    TEXT(0x118)->vfunc_20(0x92 + xi, 0x3e);
    TEXT(0x118)->vfunc_90();
    TEXT(0x1d0)->vfunc_20(xi + 0x92, 0x4c);
    TEXT(0x1d0)->vfunc_90();
    TEXT(0x288)->vfunc_20(xi + 0x92, 0x5a);
    TEXT(0x288)->vfunc_90();
    TEXT(0x340)->vfunc_20(xi + 0x92, 0x68);
    TEXT(0x340)->vfunc_90();
    TEXT(0x3f8)->vfunc_20(xi + 0x92, 0x76);
    TEXT(0x3f8)->vfunc_90();
    func_02041c20(M5C, 6, 2);
    x = xi + 0x5a;
    Model_SetPos(M5C, x << 12, -0x18000);
    Model_PlayPart(M5C, 9);
    Model_SetPos(M5C, x << 12, -0xa000);
    Model_PlayPart(M5C, 9);
    Model_SetPos(M5C, x << 12, 0x4000);
    Model_PlayPart(M5C, 9);
    Model_SetPos(M5C, x << 12, 0x12000);
    Model_PlayPart(M5C, 9);
    Model_SetPos(M5C, x << 12, 0x20000);
    M5C->x += 0x15000;
    Model_PlayPart(M5C, 10);
    func_ov000_021c95fc(&c);
    func_02041c18(M5C, (s8)Clamp99(c.a[0] + c.b[0]));
    Model_SetPos(M5C, (x + 7) << 12, -0x21000);
    Model_PlayPartChk(M5C, 6);
    func_02041c18(M5C, (s8)Clamp99(c.a[1] + c.b[1]));
    Model_SetPos(M5C, (x + 7) << 12, -0x13000);
    Model_PlayPartChk(M5C, 6);
    func_02041c18(M5C, (s8)Clamp99(c.a[2] + c.b[2]));
    Model_SetPos(M5C, (x + 7) << 12, -0x5000);
    Model_PlayPartChk(M5C, 6);
    func_02041c18(M5C, (s8)Clamp99(c.a[3] + c.b[3]));
    Model_SetPos(M5C, (x + 7) << 12, 0x9000);
    Model_PlayPartChk(M5C, 6);
    func_02041c18(M5C, (s8)Clamp99(c.a[4] + c.b[4]));
    Model_SetPos(M5C, (x + 7) << 12, 0x17000);
    Model_PlayPartChk(M5C, 6);
}

}
#endif
