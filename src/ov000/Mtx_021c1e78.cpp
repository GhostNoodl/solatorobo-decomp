#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s8 unk_00;
    u8 unk_01[0x7];
    void *unk_08;
    u8 unk_0c[0x4];
    void *unk_10;
} Data021ccd74;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 rest : 28;
    s32 state;
    u8 unk_08[4];
    u8 *model;
    u8 unk_10[0x14];
    u8 unk_24[0xc];
    u16 rx;
    u16 ry;
    u16 rz;
    u8 unk_36[0x12];
    s32 unk_48;
    u8 unk_4c[4];
    s32 unk_50;
} Obj021c1e78;

typedef struct { u16 b0 : 5; u16 b5 : 1; u16 rest : 10; } Bits16;

extern "C" {

extern Data021ccd74 data_ov000_021ccd74;
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
BOOL func_ov000_021903b4(void *m);
void func_ov000_021c2078(void *self);

void func_ov000_021c1e78(Obj021c1e78 *self) {
    MtxFx33 m;
    MtxFx33 t;
    const fx16 *tbl = FX_SinCosTable_;
    MtxFx33 *pm = &m;
    u8 alpha;
    u8 *model;
    if (self->state != 10) {
        return;
    }
    if (self->model == NULL) {
        return;
    }
    alpha = FX_MUL(FX_MUL(self->unk_48, self->unk_50), 0x1f000) >> 12;
    if (alpha == 0) {
        return;
    }
    if (self->b2) {
        data_ov000_021ccd74.unk_10 = self->unk_24;
    }
    if (self->b3) {
        BOOL any;
        u16 rz;
        u16 ry;
        u16 rx;
        ry = self->ry;
        rz = self->rz;
        rx = self->rx;
        any = FALSE;
        MTX_Identity33_(pm);
        if (ry != 0) {
            MTX_RotY33_(pm, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
            any = TRUE;
        }
        if (rx != 0) {
            if (any) {
                MTX_RotX33_(&t, tbl[(rx >> 4) * 2], tbl[(rx >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotX33_(&m, tbl[(rx >> 4) * 2], tbl[(rx >> 4) * 2 + 1]);
                any = TRUE;
            }
        }
        if (rz != 0) {
            if (any) {
                MTX_RotZ33_(&t, tbl[(rz >> 4) * 2], tbl[(rz >> 4) * 2 + 1]);
                MTX_Concat33(&t, &m, &m);
            } else {
                MTX_RotZ33_(&m, tbl[(rz >> 4) * 2], tbl[(rz >> 4) * 2 + 1]);
            }
        }
        data_ov000_021ccd74.unk_08 = pm;
    }
    model = self->model;
    NNS_G3dRenderObjSetInitFunc(model + 0x24, (void *)func_ov000_021c2078);
    LFLD(Bits16, model, 0xc2).b5 = 0;
    LFLD(u8, self->model, 0xbe) = alpha;
    func_ov000_021903b4(self->model);
}

}
