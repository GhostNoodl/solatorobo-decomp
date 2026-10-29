#include "ov000/ModelPart.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_0 : 13;
    u32 id : 8;
    u32 unk_21 : 11;
} Obj021c1180Bits;

extern "C" {
extern u8 *data_02097d48;
int func_02043d48(void *p);
s32 func_02041b10(Model *model, void *tex);
s32 func_02041bb0(Model *model, void *tex);
void func_02041774(Model *model, s32 idx);
void func_02041c34(Model *model, s32 idx, void *cb, void *arg);
void *func_ov000_021c0d50(void);

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

void func_ov000_021c1180(u8 *self) {
    s32 h;
    u8 *g;
    u8 a;
    s32 hw;
    ModelPos p;
    if (LFLD(s32, self, 0x68) != 10) {
        return;
    }
    p.x = LFLD(s32, self, 0x78) >> 12;
    g = data_02097d48;
    p.y = LFLD(s32, self, 0x7c) >> 12;
    a = LO_FX_MUL(LFLD(s32, self, 0x88), 0x1e000) >> 12;
    hw = (Lo_GetWidth(LFLD(Model *, self, 0x8c), LFLD(u16, self, 0x96)) >> 1) - 10;
    h = Lo_GetHeight(LFLD(Model *, self, 0x8c), LFLD(u16, self, 0x96));
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
    if (LFLD(VObj *, self, 0x90) != NULL) {
        s32 w = LFLD(s32, self, 0x98);
        LFLD(s32, LFLD(VObj *, self, 0x90), 0x70) = LFLD(s32, self, 0x80) + 0x20;
        LFLD(VObj *, self, 0x90)->vfunc_20(p.x - (w >> 1), p.y - 0x1c);
        LFLD(Obj021c1180Bits, LFLD(VObj *, self, 0x90), 4).id = func_02043d48(data_02097d48 + 0x8b0);
        LFLD(VObj *, self, 0x90)->vfunc_90();
    }
    Model_SetPos(LFLD(Model *, self, 0x8c), (p.x - 0x80) << 12, (p.y - 0x60) << 12);
    LFLD(Model *, self, 0x8c)->unk_150 = LFLD(s32, self, 0x80);
    func_02041c34(LFLD(Model *, self, 0x8c), LFLD(u16, self, 0x96), (void *)func_ov000_021c0d50, self + 0x68);
    if (a < 0x1e) {
        MODEL_FLAGS(LFLD(Model *, self, 0x8c))->unk_21 = 0;
    } else {
        MODEL_FLAGS(LFLD(Model *, self, 0x8c))->unk_21 = 1;
    }
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->unk_19 = 1;
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->polygon_id = func_02043d48(g + 0x8b0);
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->alpha = a;
    Model_PlayPart(LFLD(Model *, self, 0x8c), LFLD(u16, self, 0x96));
    func_02041774(LFLD(Model *, self, 0x8c), LFLD(u16, self, 0x96));
}

}

