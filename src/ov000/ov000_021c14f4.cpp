#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 rest : 28;
} F_021c14f4;

typedef struct {
    u8 pad[0x428];
    s32 a;
    u8 pad2[0xc];
    s32 b;
    s32 c;
} CamSub_021c14f4;

typedef struct {
    u8 pad[0x400];
    CamSub_021c14f4 sub;
} Cam_021c14f4;

typedef struct {
    u8 pad[0x1ec];
    Cam_021c14f4 cam;
} Gfx_021c14f4;

typedef struct { u16 b0 : 5; u16 b5 : 1; u16 rest : 10; } B16_021c14f4;

extern "C" {
extern Gfx_021c14f4 *data_02097d48;
typedef struct G3dGlb14f4 {
    u32 cmd0;
    u32 mtxmode;
    MtxFx44 projMtx;
    u32 cmd1;
    MtxFx43 cameraMtx;
} G3dGlb14f4;
extern G3dGlb14f4 NNS_G3dGlb;
extern char data_ov000_021cc929[];
void func_ov000_021c14dc(void *self);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218fe1c(void *p);
BOOL func_ov000_0218ffdc(void *m, void *res, u8 mode, s32 e);
BOOL func_ov000_02190cb0(void *m, const char *name, s32 blend, s32 force);
void func_ov000_021915a0(void *m);
void func_ov000_02190a80(void *m, s32 a);
BOOL func_ov000_021bd374(u8 *self, s32 r);
void func_ov000_021bd474(u8 *self, VecFx32 *pos);

static inline s32 Mul_021c14f4(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 CalcSub_021c14f4(CamSub_021c14f4 *s, s32 q) {
    s32 r = q - 0x1000;
    r = LO_FX_MUL(r, s->c);
    return FX_Div(r - s->b, s->a);
}

void func_ov000_021c14f4(Lo021cc938 *self) {
    BOOL ok = FALSE;

    switch (self->unk_68) {
    case 0:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 5: {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if ((void *)self->unk_8c != NULL) {
            void *p = self->unk_8c;
            if (p != NULL) {
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            self->unk_8c = NULL;
        }
        LO_HEAP_POP(saved);
        LO_HEAP_PUSH(saved);
        if ((void *)self->unk_90 != NULL) {
            void *p = self->unk_90;
            if (p != NULL) {
                func_ov000_0218fee4(p);
                func_0203de1c(p);
            }
            self->unk_90 = NULL;
        }
        LO_HEAP_POP(saved);
        break;
    }
    case 1: {
        void *res = self->unk_04;
        void *m;
        u8 *model;
        self->unk_04 = NULL;
        self->unk_8c = (Model *)(res);
        m = func_0203dd9c(0xe8);
        if (m != NULL) {
            m = func_ov000_0218fe1c(m);
        }
        self->unk_90 = (Model *)(m);
        func_ov000_0218ffdc(m, self->unk_8c, 0, 1);
        func_ov000_02190cb0(self->unk_90, data_ov000_021cc929, 0, 1);
        LFLD(u16, self->unk_90, 0xb4) = 0;
        model = (u8 *)self->unk_90;
        NNS_G3dRenderObjSetInitFunc(model + 0x24, (void *)func_ov000_021c14dc);
        LFLD(B16_021c14f4, model, 0xc2).b5 = 0;
        func_ov000_021915a0(self->unk_90);
        self->unk_68 = 4;
    }
    case 4:
        self->unk_84 = 0;
        self->unk_88 = 0;
        if (!(LFLD(F_021c14f4, self, 0).b1 == 1 ? TRUE : ok)) {
            return;
        }
        if (!(LFLD(F_021c14f4, self, 0).b3 == 1 ? TRUE : FALSE)) {
            self->unk_68 = 10;
        }
        break;
    case 10: {
        VecFx32 v;
        VecFx32 out;
        u8 *proj;
        s32 a;
        s32 b;
        s32 q;
        Cam_021c14f4 *g;
        if (func_ov000_021bd374((u8 *)self, 0x6000)) {
            return;
        }
        v.x = self->unk_50;
        v.y = self->unk_54;
        v.z = self->unk_58;
        func_ov000_021bd474((u8 *)self, &v);
        proj = (u8 *)&NNS_G3dGlb.projMtx;
        MTX_MultVec43(&v, &NNS_G3dGlb.cameraMtx, &out);
        out.z += 0x3000;
        a = Mul_021c14f4(out.z, -0x1000);
        b = LO_FX_MUL(LFLD(s32, proj, 0x28), out.z) + LFLD(s32, proj, 0x38);
        q = FX_Div(b + a, a << 1);
        self->unk_80 = CalcSub_021c14f4(&data_02097d48->cam.sub, Mul_021c14f4(q, 0x2000));
        func_ov000_02190a80(self->unk_90, 0x1000);
        break;
    }
    }
}
}
