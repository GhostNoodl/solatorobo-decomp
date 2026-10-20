#include "ov000/ModelPart.h"
#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s32 x;
    s32 y;
} Ofs9e64;

typedef struct {
    Ofs9e64 e[6];
} Tbl9e64;

struct Obj02169e64;
typedef void (*Draw9e64)(Obj02169e64 *self, s32 x, s32 y, s32 z, s32 w, s32 h, s32 k);

typedef struct Obj02169e64 {
    Draw9e64 *vt;
    u8 pad4[0x44];
    s32 unk_48;
    u8 pad4c[4];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 pad5c[4];
    s32 unk_60;
    u8 pad64[0x38];
    s32 state;
    Model *m1;
    Model *m0;
    u8 unk_a8;
    u8 pada9;
    u16 unk_aa;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
} Obj02169e64;

extern "C" {

extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
extern Tbl9e64 data_ov000_021c9b84;
s32 func_02043d84(void *a);
s32 func_02040498(s32 max);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void func_ov000_02160534(Obj02169e64 *self, s32 a, VecFx32 *pos, s32 c, s32 d);

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void Model_PlayPartEx(Model *model, s32 idx, s32 flag) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, anim, part, flag);
}

void func_ov000_02169e64(Obj02169e64 *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    Tbl9e64 tbl;
    MtxFx22 mtx;
    u8 *g;
    s32 t;
    s32 k;
    s32 ac;
    s32 x;
    s32 y;
    s32 idx;
    s32 r;
    s32 off;
    s32 alpha;
    s32 z;
    Model *m;

    switch (self->state) {
    case 0:
        t = (self->unk_60 >> 12) / 100;
        self->unk_58 = t;
        self->unk_50 = t * 8;
        break;
    case 1:
        self->unk_58 = 1;
        self->unk_50 = 0xd0;
        break;
    }
    if (self->state == 0 && (ac = self->unk_ac) != 0) {
        tbl = data_ov000_021c9b84;
        t = ac << 12;
        if (self->unk_b4 == -1) {
            self->unk_b4 = func_02040498(5);
        }
        k = 0x3000;
        idx = (self->unk_b4 + (FX_Div(t, k) >> 12)) % 6;
        pos->x += LO_FX_MUL(tbl.e[idx].x, k);
        pos->y += LO_FX_MUL(tbl.e[idx].y, k);
    }
    func_ov000_02160534(self, a, pos, c, d);
    g = data_02097d48;
    x = pos->x - 0x81000;
    y = pos->y - 0x61000;
    self->m0->unk_150 = pos->z;
    Model_SetPos(self->m0, x, y);
    MODEL_FLAGS(self->m0)->alpha = 0x1e;
    self->m0->flags |= 0x200000;
    m = self->m0;
    Model_PlayPartEx(m, (u16)self->state, 0);
    if (self->state == 0) {
        alpha = LO_FX_MUL(self->unk_48, 0x10000) >> 12;
        if (alpha != 0) {
            G3_Cmd1(0x2a, 0x20000000);
            G3_Cmd1(0x29, 0x48d0 | (func_02043d84(g + 0x8b0) << 24) | (alpha << 16));
            ((VObj *)self)->vfunc_44( pos->x - 0x30000, pos->y - 0x1000, pos->z, (self->unk_50 + 0x40) << 12, (self->unk_54 << 12) + 0x2000, 4);
        }
    }
    if (self->unk_ac == 0) {
        return;
    }
    a = FX_Div(self->unk_ac << 12, 0x9000);
    if (self->m1 != NULL) {
        r = FX_Div(self->unk_b0, self->unk_60);
        if (r >= 0x1000) {
            r = 0x1000;
        } else if (r < 0) {
            r = 0;
        }
        off = LO_FX_MUL(self->unk_50 << 12, r);
        z = pos->z;
        x = pos->x - 0x80000 + off;
        y = pos->y - 0x5f000;
        self->m1->unk_150 = z + 0x40;
        Model_SetPos(self->m1, x, y);
        r = FX_SinCosTable_[((a << 14) >> 16) * 2];
        MTX_Identity22_((MtxFx22 *)((u8 *)self->m1 + 0x114));
        m = self->m1;
        MTX_Rot22(&mtx, FX_SinCosTable_[(self->unk_aa >> 4) * 2], FX_SinCosTable_[(self->unk_aa >> 4) * 2 + 1]);
        MTX_Concat22(&mtx, (MtxFx22 *)((u8 *)m + 0x114), (MtxFx22 *)((u8 *)m + 0x114));
        MTX_ScaleApply22((MtxFx22 *)((u8 *)self->m1 + 0x114), (MtxFx22 *)((u8 *)self->m1 + 0x114), r, r);
        MODEL_FLAGS(self->m1)->alpha = (u8)(LO_FX_MUL(r, 0x1e000) >> 12);
        MODEL_FLAGS(self->m1)->polygon_id = func_02043d84(g + 0x8b0);
        Model_PlayPartEx(self->m1, self->unk_a8, 1);
    }
    if (self->state != 0) {
        return;
    }
    alpha = (u8)(LO_FX_MUL((s64)FX_SinCosTable_[((a << 15) >> 16) * 2], 0x1e000) >> 12);
    if (alpha != 0) {
        G3_Cmd1(0x2a, 0x20000000);
        G3_Cmd1(0x29, 0x48d0 | (func_02043d84(g + 0x8b0) << 24) | (alpha << 16));
        ((VObj *)self)->vfunc_44( pos->x - 0x30000, pos->y - 0x1000, pos->z, (self->unk_50 + 0x40) << 12, (self->unk_54 << 12) + 0x2000, 5);
    }
}

}
