#include "nitro/fx.h"
#include "ov000/Bss021ccd74.h"
#include "ov000/Obj0216c954.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
BOOL Model021903b4_Draw(void *m);
void func_ov000_021c2078(void *self);

void func_ov000_021c1e78(Obj021c2114 *self) {
    MtxFx33 m;
    MtxFx33 t;
    const fx16 *tbl = FX_SinCosTable_;
    MtxFx33 *pm = &m;
    u8 alpha;
    Model0218fe1c *model;
    if (self->state != 10) {
        return;
    }
    if (self->model == NULL) {
        return;
    }
    alpha = FX_MUL(FX_MUL(self->fade, self->pulse), 0x1f000) >> 12;
    if (alpha == 0) {
        return;
    }
    if (self->useOfs) {
        data_ov000_021ccd74.unk_10 = &self->ofs;
    }
    if (self->rotate) {
        BOOL any;
        u16 rz;
        u16 ry;
        u16 rx;
        ry = self->rot[1];
        rz = self->rot[2];
        rx = self->rot[0];
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
    NNS_G3dRenderObjSetInitFunc(model->renderObj, (void *)func_ov000_021c2078);
    model->clearInit = 0;
    self->model->alpha = alpha;
    Model021903b4_Draw(self->model);
}

}
