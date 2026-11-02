#include "ov000/ModelPart.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern const s16 FX_SinCosTable_[];
u8 Gfx3DState_NextPolyId(void *p);

struct Obj021bcd08 {
    u8 unk_00[0xc];
    s32 unk_0c;
    VObj *unk_10;
    Model *unk_14;
    u8 unk_18[0x4];
    s32 unk_1c;
    u8 unk_20[0x8];
    s32 unk_28;
};

void func_ov000_021bcd08(Obj021bcd08 *self) {
    Model *m;
    s32 y;
    VObj *obj;
    s32 w;
    s32 h;
    if (self->unk_0c != 2) {
        return;
    }
    y = (self->unk_1c + LO_FX_MUL(0x1000 - FX_SinCosTable_[((self->unk_28 << 14) >> 16) * 2], -0x40000)) >> 12;
    MODEL_FLAGS(self->unk_14)->polygon_id = Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
    self->unk_14->unk_150 = -0x99a;
    Model_SetPos(self->unk_14, 0x54000, (y - 0x4e) << 12);
    m = self->unk_14;
    Model_PlayPart(m, 0x1d);
    obj = self->unk_10;
    w = LFLD(s32, obj, 0x44);
    h = LFLD(s32, obj, 0x48) >> 1;
    LFLD(s32, obj, 0x70) = -0x98a;
    self->unk_10->vfunc_20(0xd4 - (w >> 1), y + (0x12 - h));
    self->unk_10->vfunc_90();
}

}
