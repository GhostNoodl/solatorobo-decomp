#include "ov000/Vec.h"
#include "Main/Sys/SysState.h"
#include "ov000/Model0218fe1c.h"

typedef struct {
    u8 pad_00[0x10];
    s16 scale;
    u16 b0 : 2;
    u16 mode : 3;
    u16 frame : 3;
    u16 f8 : 1;
    u16 f9 : 1;
    u16 f10 : 1;
    u16 f11 : 1;
    u16 rest : 4;
} Cfg0219badc;

typedef struct {
    u8 pad_00[0x48];
    void *anim;
    u8 pad_4c[0x74];
    void **events;
    u8 pad_c4[0x38];
    void **texFile;
} Res0219badc;

extern "C" {

void *NNS_G3dGetTex(void *file);
ResMdlSet *NNS_G3dGetMdlSet(void *file);
BOOL NNS_G3dBindMdlSet(ResMdlSet *set, void *tex);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 a, u32 mask);
void NNSi_G3dModifyMatFlag(void *mdl, s32 a, u32 mask);
BOOL Model0218fe1c_SetRes(Model0218fe1c *self, Res0219badc *res, u8 mode, s32 e);
void Model0218fe1c_SetAnimByIndex(Model0218fe1c *self, s32 index, s16 blend, u8 force);
void Model0218fe1c_SetLoop(Model0218fe1c *self);
AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
void func_ov000_02191920(Model0218fe1c *self, s32 index, s16 blend, u8 force);

void Model0218fe1c_Setup(Model0218fe1c *self, Res0219badc *res, const Cfg0219badc *cfg) {
    void *tex;
    AnimCtrl *ctrl;
    AnimEventTable *tbl;
    if (!Model0218fe1c_SetRes(self, res, cfg->mode, 1)) {
        return;
    }
    if (res->anim != NULL) {
        Model0218fe1c_SetAnimByIndex(self, 0, 0x1000, 0);
        Model0218fe1c_SetLoop(self);
    }
    tex = res->texFile != NULL ? NNS_G3dGetTex(*res->texFile) : NULL;
    if (tex != NULL) {
        NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(self->res->mdl_handle != NULL ? self->res->mdl_handle->unk_00 : NULL), tex);
    }
    {
        s32 sc = cfg->scale;
        if (sc != 0x1000) {
            self->scale.x = sc;
            self->scale.y = sc;
            self->scale.z = sc;
        }
    }
    if (cfg->f8) {
        NNSi_G3dModifyPolygonAttrMask(self->mdl, 1, 0x3f000000);
    }
    if (cfg->f9) {
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x40);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x80);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x200);
        NNSi_G3dModifyMatFlag(self->mdl, 1, 0x400);
        self->restoreMat = 1;
    }
    if (cfg->f10) {
        NNSi_G3dModifyPolygonAttrMask(self->mdl, 1, 0x1f0000);
    }
    if (cfg->f11) {
        *(u16 *)((u8 *)self + 0xc2) |= 4;
    }
    ctrl = Model0218fe1c_GetAnimCtrl(self, 3);
    if (ctrl != NULL) {
        u32 v;
        float f;
        s32 frame;
        self->unk_c2_6 = 1;
        func_ov000_02191920(self, 0, 0x1000, 0);
        v = cfg->frame;
        if (v > 0) {
            f = (float)(s32)(v << 12) + 0.5f;
        } else {
            f = (float)(s32)(v << 12) - 0.5f;
        }
        frame = (s32)f;
        if (ctrl->cur != NULL) {
            if (frame >= 0) {
                ctrl->cur->frame = frame;
            } else {
                ctrl->cur->frame = (*(u16 *)((u8 *)ctrl->cur->res + 4) << 12) - 1;
            }
        }
        *((u8 *)ctrl + 0x111) |= 8;
    }
    tbl = res->events != NULL ? (AnimEventTable *)((u8 *)*res->events + 8) : NULL;
    if (tbl != NULL) {
        self->evTable = tbl;
        if (tbl != NULL) {
            if (!tbl->is_ptr) self->evData = (s16 *)(tbl->entries + tbl->count);
        }
    }
}

}
