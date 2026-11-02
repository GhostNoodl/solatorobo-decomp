#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "Main/Gfx/GfxMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_0 : 13;
    u32 id : 8;
    u32 unk_21 : 11;
} Obj021c1180Bits;

extern "C" {
u8 Gfx3DState_NextPolyId(void *p);
s32 func_02041b10(Model *model, void *tex);
s32 func_02041bb0(Model *model, void *tex);
void func_02041774(Model *model, s32 idx);
void func_02041c34(Model *model, s32 idx, void *cb, void *arg);
void *func_ov000_021c0d50(u8 *self, u16 *cmd, void *arr, u16 *count);

static inline void *Lo_GetPartTex(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        return part->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
}

static inline s32 Lo_GetWidth(Model *model, s32 idx) {
    return func_02041b10(model, Lo_GetPartTex(model, idx));
}

static inline s32 Lo_GetHeight(Model *model, s32 idx) {
    return func_02041bb0(model, Lo_GetPartTex(model, idx));
}

struct Obj021c1180 {
    u8 unk_00[0x68];
    s32 unk_68;
    u8 unk_6c[0xc];
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    u8 unk_84[0x4];
    s32 unk_88;
    Model *unk_8c;
    VObj *unk_90;
    u8 unk_94[0x2];
    u16 unk_96;
    s32 unk_98;
};

void func_ov000_021c1180(Obj021c1180 *self) {
    s32 h;
    GfxSys *g;
    u8 a;
    s32 hw;
    ModelPos p;
    if (self->unk_68 != 10) {
        return;
    }
    p.x = self->unk_78 >> 12;
    g = data_02097d48;
    p.y = self->unk_7c >> 12;
    a = LO_FX_MUL(self->unk_88, 0x1e000) >> 12;
    hw = (Lo_GetWidth(self->unk_8c, self->unk_96) >> 1) - 10;
    h = Lo_GetHeight(self->unk_8c, self->unk_96);
    if (p.x + hw > 0x100) {
        p.x -= p.x + hw - 0x100;
    } else if (p.x - hw < 0) {
        p.x -= p.x - hw;
    }
    if (p.y - 0x17 + (h >> 1) > 0xc0) {
        p.y -= p.y - 0x17 + (h >> 1) - 0xc0;
    } else if (p.y - 0x17 - (h >> 1) < 0) {
        p.y -= p.y - 0x17 - (h >> 1);
    }
    if (self->unk_90 != NULL) {
        s32 w = self->unk_98;
        LFLD(s32, self->unk_90, 0x70) = self->unk_80 + 0x20;
        self->unk_90->vfunc_20(p.x - (w >> 1), p.y - 0x1c);
        LFLD(Obj021c1180Bits, self->unk_90, 4).id = Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
        self->unk_90->vfunc_90();
    }
    Model_SetPos(self->unk_8c, (p.x - 0x80) << 12, (p.y - 0x60) << 12);
    self->unk_8c->unk_150 = self->unk_80;
    func_02041c34(self->unk_8c, self->unk_96, (void *)func_ov000_021c0d50, (u8 *)self + 0x68);
    if (a < 0x1e) {
        MODEL_FLAGS(self->unk_8c)->unk_21 = 0;
    } else {
        MODEL_FLAGS(self->unk_8c)->unk_21 = 1;
    }
    MODEL_FLAGS(self->unk_8c)->unk_19 = 1;
    MODEL_FLAGS(self->unk_8c)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
    MODEL_FLAGS(self->unk_8c)->alpha = a;
    Model_PlayPart(self->unk_8c, self->unk_96);
    func_02041774(self->unk_8c, self->unk_96);
}

}

