#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
u8 Gfx3DState_NextPolyId(void *p);

static inline void SetOfs(Model *m, s32 x, s32 y) {
    Model_SetPos(m, x << 12, (y - 0x58) << 12);
}

void func_ov000_021c0b84(Lo021cc938 *self) {
    GfxSys *g;
    s32 x;
    s32 id;
    if (self->unk_68 != 10) {
        return;
    }
    g = data_02097d48;
    x = ((LO_FX_MUL(0x1000 - self->unk_88, 0x40000) + 0xce000) >> 12) - 0x80;
    self->unk_90->unk_150 = self->unk_80;
    SetOfs(self->unk_90, x, 0);
    self->unk_8c->unk_150 = self->unk_80;
    SetOfs(self->unk_8c, x, 0);
    id = Gfx3DState_NextPolyId(g->unk_8b0) & 0x3f;

    MODEL_FLAGS(self->unk_90)->polygon_id = id;
    MODEL_FLAGS(self->unk_90)->alpha = 0x1e;
    Model_PlayPart(self->unk_90, 2);
    MODEL_FLAGS(self->unk_8c)->polygon_id = id;
    MODEL_FLAGS(self->unk_8c)->alpha = 0x1e;
    Model_PlayPart(self->unk_8c, 9);
}

}
