#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

extern u8 *data_02097d48;
s32 func_02043d84(void *a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline s32 MulL021688c4(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline u8 PolyId021688c4(u8 *p) {
    return p[2];
}

static inline void SetPosV021688c4(Model *m, VecFx32 *v) {
    m->x = v->x;
    m->y = v->y;
}

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

void func_ov000_021688c4(VObj *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    VecFx32 p;
    u8 *g;
    u8 alpha;
    s32 z;
    s32 r;
    p.x = pos->x - 0x80000;
    p.y = pos->y - 0x60000;
    g = data_02097d48;
    p.z = 0;
    VEC_Add(&p, (VecFx32 *)((u8 *)self + 0xac), &p);
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->unk_20 = 0;
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->unk_21 = 0;
    alpha = MulL021688c4(d, 0x1e000) >> 12;
    LFLD(Model *, self, 0x9c)->unk_150 = pos->z;
    SetPosV021688c4(LFLD(Model *, self, 0x9c), &p);
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->alpha = alpha & 0x1f;
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->polygon_id = PolyId021688c4(g + 0x8b0);
    Model_PlayPartChk(LFLD(Model *, self, 0x9c), 0x1a);
    if (LFLD(s32, self, 0xb8) > 0) {
        LFLD(Model *, self, 0x9c)->unk_150 = pos->z;
        SetPosV021688c4(LFLD(Model *, self, 0x9c), &p);
        MODEL_FLAGS(LFLD(Model *, self, 0x9c))->alpha = alpha & 0x1f;
        MODEL_FLAGS(LFLD(Model *, self, 0x9c))->polygon_id = func_02043d84(g + 0x8b0);
        Model_PlayPartChk(LFLD(Model *, self, 0x9c), 0x1c);
    } else {
        func_02043d84(g + 0x8b0);
    }
    z = pos->z + 0x80;
    LFLD(Model *, self, 0x9c)->unk_150 = z;
    SetPosV021688c4(LFLD(Model *, self, 0x9c), &p);
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->alpha = alpha & 0x1f;
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->unk_21 = 1;
    MODEL_FLAGS(LFLD(Model *, self, 0x9c))->polygon_id = func_02043d84(g + 0x8b0);
    Model_PlayPartChk(LFLD(Model *, self, 0x9c), 0x1b);
    if (LFLD(s32, self, 0x5c) <= 0) {
        return;
    }
    r = FX_Div(LFLD(s32, self, 0x5c), LFLD(s32, self, 0x60));
    if (r >= 0x1000) {
        r = 0x1000;
    } else if (r < 0) {
        r = 0;
    }
    G3_Cmd1(0x29, 0x48d0 | (func_02043d84(g + 0x8b0) << 24) | (alpha << 16));
    self->vfunc_48(pos->x + LFLD(s32, self, 0xac), pos->y + LFLD(s32, self, 0xb0) - 0x8000, z, 0x10000, (MulL021688c4(r, 0x13000) + 0x800) & 0x7ffff000, 0);
}

}
